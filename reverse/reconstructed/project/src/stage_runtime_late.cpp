#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <utility>

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
constexpr std::array<LateSpawnSpec, 63> kLateSpawnSpecs{{
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
    // Attached nodes created by FUN_1400a7760 at the 0x77 intro transition.
    {0x78, 0x56,  12,  40, kUseScheduledY},
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
    {0xff, 0x1c,   1,  20, kUseScheduledY},
    {0x100, 0x87, 24,  70, kUseScheduledY},
    {0x101, 0x1c,  1,  20, kUseScheduledY},
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

// FUN_140052fb0 creates these shared-HP apparatus/controllers at timer 30.
// The last four own the long 131/141/151 phase scripts; 0x127 dissolves when
// the root enters 142, while 0x12d hands the last quarter to state 153.
constexpr std::array<Stage10FinalBossNodeSpec, 10> kStage10FinalBossNodeSpecs{{
    {0x111, 0x8d, 250.0f, 150,  20},
    {0x112, 0x8e, 250.0f, 100,  40},
    {0x113, 0x8f, 300.0f,  80,  60},
    {0x115, 0x91, 250.0f, 150,  80},
    {0x11a, 0x93, 250.0f, 170, 100},
    {0x11d, 0x95, 320.0f, 150, 120},
    {0x125, 0x98, 250.0f, 150, 140},
    {0x126, 0x98, 250.0f, 150, 140},
    {0x127, 0x99, 250.0f, 150, 142},
    {0x12d, 0x9c, 230.0f, 230, 152},
}};

// FUN_1400630f0 selects exactly one of the mirrored 0x11f batteries for
// each 0x123 launch.  The values come from the 14-entry table assembled
// from .rdata at 0x14053b470/0x14053b478/0x14053b620/0x14053b628.
// Zero selects the right battery and one selects the left battery.
constexpr std::array<int, 14> kStage10Type11fLaunchSides{{
    0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0,
}};

// Direct FUN_140078a00 call arguments recovered from the per-stage handlers.
// Entity type 0x142 has no direct or internal creation site and no update
// helper, so it is deliberately absent rather than assigned invented behavior.
constexpr std::array<LateBossSpec, 16> kLateBossSpecs{{
    {0x13c, 0xa3, 360.0f,  200.0f, 360.0f, 200.0f, 0.3, 175,  6},
    {0x13d, 0xa4, 480.0f,  150.0f, 480.0f, 150.0f, 0.3, 175,  5},
    {0x13e, 0xa5, 360.0f,  250.0f, 360.0f, 200.0f, 0.2, 210,  5},
    {0x13f, 0xa6, 360.0f,  180.0f, 360.0f, 180.0f, 0.3, 130,  6},
    {0x140, 0xa7, 360.0f,  190.0f, 360.0f, 190.0f, 0.1, 140,  4},
    {0x141, 0xa8, 360.0f,  320.0f, 360.0f, 200.0f, 0.4,  80, 16},
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

int lateEnemyDeathRewardWindow(int spawnType) {
    switch (spawnType) {
    case 0x44: return 200;
    case 0x45: return 0xf0;
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4d:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x4e: return 500;
    case 0x4c: return 300;
    case 0x70: return 0x168;
    case 0x74:
    case 0x75: return 600;
    case 0x76: return 800;
    case 0x4f:
    case 0x77: return 0x708;
    default: return 0;
    }
}

int lateEnemyDeathEffectMode(int spawnType) {
    switch (spawnType) {
    case 0x44:
    case 0x45:
    case 0x4c:
    case 0x4e:
    case 0x49:
    case 0x70:
    case 0x74: return 0;
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x4a:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x75: return 1;
    case 0x4d:
    case 0x4f:
    case 0x76:
    case 0x77: return 2;
    default: return 0;
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
           isStage08EnemyType(spawnType) ||
           isStage10SceneNodeType(spawnType) ||
           isSharedHitboxProxyType(spawnType) ||
           isStage10GuardNodeType(spawnType) ||
           isStage06MidbossNodeType(spawnType) ||
           isStage07MidbossNodeType(spawnType) ||
           isStage06BossNodeType(spawnType) ||
           isStage07BossNodeType(spawnType) ||
           isStage09MidbossNodeType(spawnType) ||
           stage10FinalBossNodeSpec(spawnType) != nullptr ||
           isStage10FinalBossAuxNodeType(spawnType) ||
           isStage10FinalBossEmitterType(spawnType);
}

bool StageRuntime::isLateStageBossType(int spawnType) const {
    return lateBossSpec(spawnType) != nullptr ||
           isStage06MidbossNodeType(spawnType) ||
           isStage07MidbossNodeType(spawnType) ||
           isStage06BossNodeType(spawnType) ||
           isStage07BossNodeType(spawnType) ||
           isStage09MidbossNodeType(spawnType) ||
           stage10FinalBossNodeSpec(spawnType) != nullptr ||
           isStage10FinalBossAuxNodeType(spawnType) ||
           isStage10FinalBossEmitterType(spawnType);
}

bool StageRuntime::isLateStageFinalBossType(int spawnType) const {
    return spawnType >= 0x13c && spawnType <= 0x141;
}

bool StageRuntime::isStage10FinalBossNodeType(int spawnType) const {
    return stage10FinalBossNodeSpec(spawnType) != nullptr ||
           isStage10FinalBossAuxNodeType(spawnType) ||
           isStage10FinalBossEmitterType(spawnType);
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
    case 0x125: note = "S10 FUN_140052fb0 state 131 timer 30 node 0x125"; break;
    case 0x126: note = "S10 FUN_140052fb0 state 131 timer 30 node 0x126"; break;
    case 0x127: note = "S10 FUN_140052fb0 state 141 timer 30 node 0x127"; break;
    case 0x12d: note = "S10 FUN_140052fb0 state 151 timer 30 node 0x12d"; break;
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
    if (isStage10FinalBossEmitterType(enemy.spawnType)) {
        updateStage10FinalBossEmitter(enemy);
        return;
    }

    maybeSpawnStage10GuardNode(enemy);

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

        if (enemy.spawnType == 0x114) {
            // FUN_14005dd50 unlinks the satellite as soon as either its
            // 0x113 owner or the shared boss countdown reaches zero.
            if (owner->hp < 1 || lateStageBossCountdown_ < 1) {
                enemy.targetable = false;
                enemy.active = false;
                return;
            }
            constexpr std::array<float, 4> kNearX{{
                100.0f, -100.0f, 200.0f, -200.0f,
            }};
            constexpr std::array<float, 4> kNearY{{
                -70.0f, -70.0f, -30.0f, -30.0f,
            }};
            constexpr std::array<float, 4> kFarX{{
                -140.0f, 140.0f, -90.0f, 90.0f,
            }};
            constexpr std::array<float, 4> kFarY{{
                0.0f, 0.0f, -80.0f, -80.0f,
            }};
            constexpr std::array<int, 4> kFarBaseAngle{{
                -0x8000, 0, -0x8000, 0,
            }};
            constexpr std::array<int, 4> kFarTurn{{
                -750, 750, 750, -750,
            }};
            const std::size_t index = static_cast<std::size_t>(
                std::clamp(enemy.childIndex, 0, 3));

            if (enemy.helperState == 0 && timer == 0) {
                enemy.x = owner->x;
                enemy.y = owner->y;
            }

            int cycle = -1;
            bool useFarMount = false;
            if (enemy.helperState == 1 && timer >= 0x28) {
                cycle = (timer - 0x28) % 0x4b0;
                useFarMount = cycle >= 0x1a4;
            }
            const float targetX = owner->x +
                (useFarMount ? kFarX[index] : kNearX[index]);
            const float targetY = owner->y +
                (useFarMount ? kFarY[index] : kNearY[index]);
            enemy.x += (targetX - enemy.x) * 0.2f;
            enemy.y += (targetY - enemy.y) * 0.2f;

            if (useFarMount) {
                const int turnFrames = std::max(0, cycle - 0x1c2);
                enemy.targetAngle16 = normalizeAngle16(
                    kFarBaseAngle[index] + kFarTurn[index] * turnFrames);
            }
            else if (enemy.helperState == 1) {
                enemy.targetAngle16 = radiansToAngle16(std::atan2(
                    static_cast<double>(player_.y - enemy.y),
                    static_cast<double>(player_.x - enemy.x)));
            }
            int angleDelta = static_cast<int>(enemy.targetAngle16) -
                             static_cast<int>(enemy.sourceAngle16);
            if (angleDelta > 0x8000) angleDelta -= 0x10000;
            if (angleDelta < -0x8000) angleDelta += 0x10000;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, enemy.targetAngle16,
                0x80 + std::abs(angleDelta) / 10);
            enemy.targetable = false;

            if (enemy.helperState == 0 && timer >= 0x28) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                return;
            }

            if (cycle >= 0) {
                bool fire = false;
                double speed = 0.0;
                if (cycle >= 0x14 && cycle < 0x190) {
                    const int local = (cycle - 0x14) % 0x23;
                    fire = local <= 0x13 && local % 5 == 0;
                    speed = 8.0;
                }
                else if (cycle >= 0x1c2 && cycle < 0x488 &&
                         (cycle - 0x1c2) % 3 == 0) {
                    fire = true;
                    speed = 5.0;
                }
                if (fire) {
                    const double heading = fixedAngleRadians(
                        enemy.sourceAngle16);
                    const float muzzleX = enemy.x + static_cast<float>(
                        std::cos(heading) * 15.0);
                    const float muzzleY = enemy.y + static_cast<float>(
                        std::sin(heading) * 15.0);
                    spawnProjectileNode(10, 1, muzzleX, muzzleY,
                                        enemy.sourceAngle16, 10.0f,
                                        speed, 1, 0);
                    playPlayerSound(bullet2SoundHandle_, 9);
                }
            }
        }
        else if (enemy.spawnType >= 0x116 && enemy.spawnType <= 0x119) {
            if (owner->helperState == 99 && enemy.helperState < 99) {
                spawnPostDeathCounterEntity(
                    enemy, static_cast<double>(enemy.radius) * 0.6);
                enemy.helperState = 99;
                enemy.helperTimer = 0;
                enemy.targetable = false;
                spawnStage02DeathExplosionChain(enemy);
                return;
            }
            if (enemy.helperState == 99) {
                enemy.targetable = false;
                if (timer < 90) {
                    spawnStage02DeathExplosionChain(enemy);
                    enemy.y += static_cast<float>(timer) * 0.02f;
                }
                if (timer == 90) {
                    playPlayerSound(blast2SoundHandle_, 0x19);
                    spawnEnemyDeathEffects(enemy, 1, false);
                }
                if (timer >= 140) {
                    enemy.active = false;
                }
            }
            else {
                if (enemy.helperState == 0 &&
                    (owner->helperState == 1 || timer >= 0xbe)) {
                    enemy.helperState = 1;
                    enemy.helperTimer = 0;
                    enemy.targetable = false;
                    return;
                }
                else if (enemy.helperState == 1 || enemy.helperState == 3) {
                    enemy.targetable = true;
                    if (timer == 1) {
                        enemy.markerDrawX = enemy.x;
                        enemy.markerDrawY = enemy.y;
                    }

                    const bool moveRight =
                        (enemy.originX < 360.0f && enemy.helperState == 1) ||
                        (enemy.originX >= 360.0f && enemy.helperState == 3);
                    const float targetX = enemy.markerDrawX +
                                          (moveRight ? 50.0f : -50.0f);
                    const float verticalStep = enemy.markerDrawY < 0.0f
                                                   ? 180.0f
                                               : enemy.markerDrawY < 600.0f
                                                   ? 120.0f
                                                   : 300.0f;
                    const float targetY = enemy.markerDrawY + verticalStep;
                    const double travelPhase =
                        static_cast<double>(timer) * kPi / 80.0;
                    const double bobPhase =
                        static_cast<double>(timer) * kPi / 40.0;
                    const double travel = std::sin(travelPhase);
                    enemy.x = enemy.markerDrawX + static_cast<float>(
                        travel * static_cast<double>(targetX - enemy.markerDrawX));
                    enemy.y = enemy.markerDrawY + static_cast<float>(
                        travel * static_cast<double>(targetY - enemy.markerDrawY) -
                        80.0 * std::sin(bobPhase));

                    if (timer >= 0x28) {
                        ++enemy.helperState;
                        enemy.helperTimer = 0;
                    }
                }
                else if (enemy.helperState == 2 || enemy.helperState == 4) {
                    enemy.targetable = true;
                    if (enemy.y < 400.0f) {
                        const auto aimFrom = [this](float x, float y) {
                            return radiansToAngle16(std::atan2(
                                static_cast<double>(player_.y - y),
                                static_cast<double>(player_.x - x)));
                        };
                        const int local = timer - 10;

                        if (enemy.spawnType == 0x116 && local >= 0 &&
                            local < 30 && local % 4 == 0) {
                            const float fireY = enemy.y + 95.0f;
                            if (timer == 10) {
                                enemy.targetAngle16 = aimFrom(enemy.x, fireY);
                            }
                            const int narrow = local * 50;
                            // The original uses (timer + 0x6e) * 100 as the
                            // full fan width. local is timer - 10 here.
                            const int wide = (local + 0x78) * 50;
                            for (const int offset :
                                 std::array<int, 4>{{-narrow, narrow,
                                                     -wide, wide}}) {
                                spawnProjectileNode(
                                    0x0b, 1, enemy.x, fireY,
                                    normalizeAngle16(
                                        static_cast<int>(enemy.targetAngle16) +
                                        offset),
                                    10.0f, 5.0, 1, 0);
                            }
                            playPlayerSound(bullet1SoundHandle_, 0x13);
                        }
                        else if (enemy.spawnType == 0x117 && local >= 0 &&
                                 local < 30) {
                            const float fireY = enemy.y + 90.0f;
                            const auto aimed = aimFrom(enemy.x, fireY);
                            const int ownerTimer = owner->helperTimer;
                            const int xJitter = static_cast<int>(
                                lateBossFrameRand(ownerTimer) % 81u) - 40;
                            const int angleJitter = static_cast<int>(
                                lateBossFrameRand(ownerTimer + 0x115c) %
                                36001u) - 18000;
                            const double speed = 3.0 +
                                static_cast<double>(lateBossFrameRand(
                                    ownerTimer + 0x1bc) % 301u) /
                                    100.0;
                            spawnProjectileNode(
                                0x0c, 2,
                                enemy.x + static_cast<float>(xJitter), fireY,
                                normalizeAngle16(static_cast<int>(aimed) +
                                                 angleJitter),
                                10.0f, speed, 1, 0);
                            playPlayerSound(bullet2SoundHandle_, 0x0c);
                        }
                        else if (enemy.spawnType == 0x118 && local >= 0 &&
                                 local < 50 && local % 15 == 0) {
                            const float fireY = enemy.y + 90.0f;
                            const auto aimed = aimFrom(enemy.x, fireY);
                            for (int i = 0; i < 5; ++i) {
                                spawnProjectileNode(
                                    3, 1, enemy.x, fireY,
                                    normalizeAngle16(
                                        static_cast<int>(aimed) - 6000 +
                                        i * 3000),
                                    10.0f, 2.4, 1, 0);
                            }
                            playPlayerSound(bullet1SoundHandle_, 0x13);
                        }
                        else if (enemy.spawnType == 0x119 && local >= 0 &&
                                 local < 50 && local % 5 == 0) {
                            const float fireY = enemy.y + 95.0f;
                            if (timer == 10) {
                                enemy.targetAngle16 = aimFrom(enemy.x, fireY);
                            }
                            const int sweep = local * 0x28a;
                            const double speed = 2.5 +
                                                 local * 0.14;
                            spawnProjectileNode(
                                4, 0, enemy.x - 15.0f, fireY,
                                normalizeAngle16(
                                    static_cast<int>(enemy.targetAngle16) +
                                    sweep - 0x4000),
                                0.0f, speed, 1, 0);
                            spawnProjectileNode(
                                4, 0, enemy.x + 15.0f, fireY,
                                normalizeAngle16(
                                    static_cast<int>(enemy.targetAngle16) -
                                    sweep + 0x4000),
                                0.0f, speed, 1, 0);
                            playPlayerSound(bullet2SoundHandle_, 0x0c);
                        }
                    }

                    if (timer >= 0x50) {
                        enemy.helperState = enemy.helperState == 4
                                                ? 1
                                                : enemy.helperState + 1;
                        enemy.helperTimer = 0;
                    }
                    // FUN_14005e890 evaluates this tail after the complete
                    // state-2/4 attack and movement block, so a lethal hit
                    // does not suppress the launcher's final-frame volley.
                    if (enemy.hp < 1) {
                        const StageEnemy* bossRoot =
                            findEnemyById(owner->parentEntityId);
                        const bool specialActive = player_.bombLock > 0 ||
                                                   player_.bombLock < -100 ||
                                                   player_.specialGauge < -100;
                        if (!specialActive && bossRoot != nullptr &&
                            bossRoot->spawnType == 0x141 && bossRoot->active) {
                            spawnDelayedOwnerDamageNode(
                                enemy.maxHp, bossRoot->entityId,
                                bossRoot->spawnType,
                                "S10 launcher delayed-damage node 0x153");
                        }
                        spawnEnemyDeathRewardBurst(enemy, 0x960, false);
                        spawnEnemyDeathEffects(enemy, 2);
                        enemy.targetable = false;
                        enemy.active = false;
                        return;
                    }
                }
            }
            if (enemy.active && enemy.y >= 860.0f) {
                enemy.targetable = false;
                enemy.active = false;
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
            if (enemy.helperState == 0) {
                enemy.x = targetX;
                enemy.y = targetY;
                if (owner->helperState >= 1) {
                    enemy.helperState = 1;
                    enemy.helperTimer = 0;
                }
            }
            else {
                const float divisor = static_cast<float>(
                    std::max(1.0, enemy.sourceSpeed));
                enemy.x += (targetX - enemy.x) / divisor;
                enemy.y += (targetY - enemy.y) / divisor;
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
            if (enemy.helperState == 0) {
                enemy.x = targetX;
                enemy.y = targetY;
                if (owner->helperState >= 1) {
                    enemy.helperState = 1;
                    enemy.helperTimer = 0;
                }
            }
            else {
                const float divisor = static_cast<float>(
                    std::max(1.0, enemy.sourceSpeed));
                enemy.x += (targetX - enemy.x) / divisor;
                enemy.y += (targetY - enemy.y) / divisor;
            }

            // FUN_1400630f0 keeps the two state-1 battery families as direct
            // emitters.  Their windows are keyed to the 0x11d owner's clock.
            if (owner->helperState == 1 && enemy.helperState == 1) {
                const int ownerTimer = owner->helperTimer;
                const float fireY = enemy.y + 130.0f;
                const auto aimed = radiansToAngle16(std::atan2(
                    static_cast<double>(player_.y - fireY),
                    static_cast<double>(player_.x - enemy.x)));
                if (enemy.spawnType == 0x11e && ownerTimer >= 0x46 &&
                    ownerTimer < 0x186) {
                    const int local = (ownerTimer - 0x46) % 0xd2;
                    if (local < 0x6e && local % 8 == 0) {
                        const int randomOffset = 1500 - static_cast<int>(
                            lateBossFrameRand(enemy.helperTimer) % 3001u);
                        spawnProjectileNode(
                            3, 0, enemy.x, fireY,
                            normalizeAngle16(static_cast<int>(aimed) +
                                             randomOffset),
                            0.0f, 7.5, 1, 0);
                        for (int i = 0; i < 7; ++i) {
                            spawnProjectileNode(
                                7, 0, enemy.x, fireY,
                                normalizeAngle16(static_cast<int>(aimed) -
                                                 18000 + i * 2000),
                                0.0f, 8.5, 1, 0);
                            spawnProjectileNode(
                                7, 0, enemy.x, fireY,
                                normalizeAngle16(static_cast<int>(aimed) +
                                                 6000 + i * 2000),
                                0.0f, 8.5, 1, 0);
                        }
                        playPlayerSound(bullet1SoundHandle_, 0x13);
                    }
                }
                else if (enemy.spawnType == 0x120 && ownerTimer >= 0x1e &&
                         ownerTimer < 0x186) {
                    const int local = (ownerTimer - 0x1e) % 0xd2;
                    if (local < 0x96 && local % 10 == 0) {
                        const bool left = enemy.originX < -1.0f;
                        const int firstOffset = left ? 0 : -10000;
                        const int secondOffset = left ? -2500 : -7500;
                        for (int i = 0; i < 3; ++i) {
                            spawnProjectileNode(
                                4, 0, enemy.x, fireY,
                                normalizeAngle16(static_cast<int>(aimed) +
                                                 firstOffset + i * 5000),
                                0.0f, 5.5, 1, 0);
                            spawnProjectileNode(
                                0, 0, enemy.x, fireY,
                                normalizeAngle16(static_cast<int>(aimed) +
                                                 secondOffset + i * 5000),
                                0.0f, 6.5, 1, 0);
                        }
                        playPlayerSound(bullet2SoundHandle_, 0x0c);
                    }
                }
            }

            // FUN_1400630f0 creates the two real short-lived launchers from
            // the parent's state-2 clock. 0x123 follows the recovered side
            // table; both 0x122 batteries create 0x124 every 30 ticks.
            if (owner->helperState == 2) {
                const int ownerTimer = owner->helperTimer;
                if (enemy.spawnType == 0x11f && ownerTimer >= 0x32 &&
                    ownerTimer < 0x2d0 && (ownerTimer - 0x32) % 0x30 == 0) {
                    const int eventIndex = (ownerTimer - 0x32) / 0x30;
                    const bool rightSide = enemy.originX > 0.0f;
                    const bool selectedRight =
                        kStage10Type11fLaunchSides[
                            static_cast<std::size_t>(eventIndex)] == 0;
                    if (rightSide == selectedRight) {
                        spawnStage10FinalBossEmitter(
                            enemy, 0x123, enemy.x, enemy.y, 0x4000, 0.0,
                            eventIndex);
                    }
                }
                if (enemy.spawnType == 0x122 && ownerTimer >= 10 &&
                    ownerTimer < 0x2d0 && (ownerTimer - 10) % 0x1e == 0) {
                    spawnStage10FinalBossEmitter(
                        enemy, 0x124, enemy.x, enemy.y, 0x4000, 0.0,
                        (ownerTimer - 10) / 0x1e);
                }
            }

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
                }
            }
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
            node.sourceSpeed = (spawnType == 0x11b || spawnType == 0x11c)
                                   ? 10.0
                                   : 1.0;
            node.speed = static_cast<float>(node.sourceSpeed);
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

    if (enemy.helperState < 98 &&
        (parent->helperState == spec->parentBreakState ||
         parent->helperState == 200)) {
        // The first eight apparatus controllers each call FUN_1400031d0 at
        // their parent-owned break. FUN_14005e4e0 (0x115) is the one such
        // helper that does not follow it with a 0x137.
        if (enemy.spawnType != 0x127 && enemy.spawnType != 0x12d) {
            if (lateStageBossCountdown_ < 1) {
                flushEnemyProjectilesToEffects();
                player_.invulnerableFrames =
                    std::max(player_.invulnerableFrames, 100);
            }
            else {
                spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                      0.0, 0, 0, 0.0f);
            }
            spawnBossPhaseBreakFeedback(enemy, lateStageBossCountdown_);
        }

        // 0x127 owns no counter and first runs its recovered state-98 return
        // path. 0x12d has its separate last-quarter handoff below.
        if (enemy.spawnType != 0x115 && enemy.spawnType != 0x127) {
            bool spawnCounter = true;
            if (enemy.spawnType == 0x12d) {
                // FUN_14006ad60 suppresses 0x137 when the last-quarter handoff
                // was forced by the sub-1500 countdown. It grants the matching
                // 100-frame player protection instead.
                spawnCounter = lateStageBossCountdown_ >= 1500;
                if (spawnCounter) {
                    spawnPlayerSideObject(0x19, enemy.x, enemy.y,
                                          0.0, 0, 0, 0.0f);
                }
                else {
                    player_.invulnerableFrames =
                        std::max(player_.invulnerableFrames, 100);
                }
            }
            if (spawnCounter) {
                spawnPostDeathCounterEntity(
                    enemy, static_cast<double>(enemy.radius) * 0.6);
            }
        }
        // FUN_140066370 does not enter its dissolve directly.  The parent
        // switch to state 142 forces controller 0x127 through state 98's
        // 35-frame return-to-anchor first; all other shared-HP controllers
        // use the ordinary state-99 destruction branch.
        enemy.helperState = enemy.spawnType == 0x127 ? 98 : 99;
        enemy.helperTimer = 0;
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        if (enemy.spawnType != 0x127 && enemy.spawnType != 0x12d) {
            spawnStage02DeathExplosionChain(enemy);
        }
    }

    if (enemy.helperState == 99 && enemy.spawnType != 0x127) {
        enemy.targetable = false;
        enemy.drawBodyThisFrame = enemy.helperTimer < 100;
        if (enemy.spawnType == 0x12d) {
            // FUN_14006ad60 owns a distinct final-quarter dissolve: a small
            // graphless burst at timer 1, ambient explosions through timer 89,
            // and the full terminal burst at timer 90.
            if (enemy.helperTimer == 1) {
                spawnStageEffect(0x36, -1, 0, 0x28,
                                 enemy.x, enemy.y, 0,
                                 0.0, 1.0, 1.0, 0,
                                 0xff, 0xff, 0xff, 0xff);
            }
            if (enemy.helperTimer < 90 && enemy.helperTimer % 3 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
            if (enemy.helperTimer == 90) {
                playPlayerSound(blast2SoundHandle_, 0x19);
                spawnStageEffect(0x11, -1, 0, 0x28,
                                 enemy.x, enemy.y, 0,
                                 0.0, 1.0, 1.0, 0,
                                 0xff, 0xff, 0xff, 0xff);
            }
        }
        else if (enemy.helperTimer < 90) {
            enemy.y += static_cast<float>(enemy.helperTimer) * 0.02f;
            if (enemy.helperTimer % 6 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
        }
        if (enemy.spawnType != 0x12d && enemy.helperTimer == 90) {
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

    // Each helper owns a materialization state. At the transition it copies
    // the root's current and queued HP fields and becomes targetable.
    if (enemy.helperState == 0) {
        enemy.targetable = false;
        int materializeLength = 190;
        if (enemy.spawnType == 0x125 || enemy.spawnType == 0x126 ||
            enemy.spawnType == 0x12d) {
            materializeLength = 250;
        }
        else if (enemy.spawnType == 0x127) {
            materializeLength = 270;
        }
        if (enemy.helperTimer >= materializeLength) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            if (enemy.spawnType == 0x115) {
                // FUN_14005e4e0 is only a launcher controller. Unlike the
                // neighbouring apparatus helpers it never copies or mirrors
                // the root HP and never becomes a second hit surface.
                return;
            }
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
            case 0x125:
                enemy.sourceSpeed = 0.3;
                enemy.markerDrawX = 510.0f;
                enemy.markerDrawY = 250.0f;
                break;
            case 0x126:
                enemy.sourceSpeed = 0.3;
                enemy.markerDrawX = 210.0f;
                enemy.markerDrawY = 250.0f;
                break;
            case 0x127:
                enemy.sourceSpeed = 0.3;
                enemy.markerDrawX = 360.0f;
                enemy.markerDrawY = 250.0f;
                break;
            case 0x12d:
                enemy.sourceSpeed = 0.3;
                enemy.markerDrawX = 360.0f;
                enemy.markerDrawY = 290.0f;
                break;
            default: break;
            }
        }
        return;
    }

    // FUN_14005a3f0 and its sibling helpers make the apparatus a second hit
    // surface for the root: damage received by either surface is reflected to
    // the other before this frame's body is queued.
    if (enemy.spawnType == 0x115) {
        enemy.targetable = false;
    }
    else {
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
    }

    const int timer = enemy.helperTimer;
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
                const auto aimed = aimAt(enemy.x, enemy.y);
                constexpr std::array<double, 5> kBaseSpeeds{{
                    5.0, 7.0, 9.0, 11.0, 13.0,
                }};
                for (const double baseSpeed : kBaseSpeeds) {
                    spawnProjectileNode(0x0d, 4, enemy.x, enemy.y,
                                        aimed, 0.0f,
                                        baseSpeed + segment * 0.3, 1, 0);
                }
                fired = true;
            }
            if (local >= 0x5a && local < 0x140 &&
                (local - 0x5a) % 0x46 == 0) {
                const int ringTime = local - 0x5a;
                const auto base = normalizeAngle16(static_cast<int>(
                    lateBossFrameRand(timer)));
                spawnProjectileSpread(10, 0, enemy.x, enemy.y, base,
                                      0.0f, 3.0 + ringTime * 0.012,
                                      1, 25, 0x10000, 0);
                spawnProjectileSpread(10, 0, enemy.x, enemy.y,
                                      aimAt(enemy.x, enemy.y), 0.0f,
                                      4.0 + ringTime * 0.017,
                                      1, 25, 0x10000, 0);
                fired = true;
            }
        }
        if (local >= 0x168 && local < 0x258 && local % 20 == 0) {
            const auto aimed = aimAt(enemy.x, enemy.y);
            const double speed = 5.0 + (local - 0x15e) * 0.007;
            for (int i = 0; i < 7; ++i) {
                const auto angle = normalizeAngle16(
                    static_cast<int>(aimed) - 2000 + i * 0x29a);
                spawnProjectileNode(0x0d, 1, enemy.x, enemy.y,
                                    angle, 0.0f, speed, 1, 0);
                spawnProjectileNode(0x0d, 1, enemy.x, enemy.y,
                                    angle, 0.0f, speed + 1.0, 1, 0);
            }
            fired = true;
        }
        if (local >= 0x280 && local < 0x424) {
            const double speed = 3.6 + (local - 0x280) * 0.007;
            spawnProjectileNode(0x0d, 3, enemy.x, enemy.y,
                                normalizeAngle16(timer * 0x960), 0.0f,
                                speed, 1, 0);
            if ((local & 1) == 0) {
                spawnProjectileNode(0x0c, 3, enemy.x, enemy.y,
                                    normalizeAngle16(-timer * 1000), 0.0f,
                                    speed + 1.15, 1, 0);
            }
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
            if (burst == 0) {
                enemy.secondaryAngle16 = local < 0x1a4
                    ? (enemy.y <= player_.y ? 0x4000 : 0xc000)
                    : aimAt(enemy.x, enemy.y + 20.0f);
            }
            if (burst < 40 && burst % 5 == 0) {
                spawnProjectileNode(7, 1, enemy.x + 20.0f,
                                    enemy.y + 20.0f,
                                    enemy.secondaryAngle16, 10.0f,
                                    8.0, 1, 0);
                spawnProjectileNode(7, 1, enemy.x - 20.0f,
                                    enemy.y + 20.0f,
                                    enemy.secondaryAngle16, 10.0f,
                                    8.0, 1, 0);
                fired = true;
            }
        }
        break;
    }
    case 0x115: { // FUN_14005e4e0 plus its 0x116..0x119 launchers
        int scheduleClock = timer;
        int scheduledTimer = 20;
        for (int i = 0; i < 30; ++i) {
            if (scheduleClock >= 20 && scheduleClock < scheduledTimer) {
                const auto isActive = [](const StageEnemy& node) {
                    return node.active;
                };
                const auto activeCount =
                    std::count_if(enemies_.begin(), enemies_.end(), isActive) +
                    std::count_if(pendingEnemies_.begin(), pendingEnemies_.end(),
                                  isActive);
                if (activeCount < 3) {
                    // FUN_14005e4e0 advances its own clock to the next launch
                    // whenever the complete entity list has fewer than three
                    // entries, preventing a long gap after an early kill.
                    scheduleClock = scheduledTimer;
                    enemy.helperTimer = scheduledTimer;
                }
            }
            if (scheduleClock == scheduledTimer) {
                const int selector = i & 3;
                const int type = selector == 0 ? 0x118
                                 : (selector == 1 ? 0x119
                                    : (selector == 2 ? 0x116 : 0x117));
                float spawnX = 170.0f;
                if (i % 3 == 0) {
                    spawnX = 260.0f + static_cast<float>(
                        lateBossFrameRand(scheduleClock) % 201u);
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
                                      0.0f, 8.8, 6, 5, 0x2bf0, 0);
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
            const auto fireMirrorBurst = [&](bool right) {
                const float sideX = enemy.x + (right ? 120.0f : -120.0f);
                const float fireY = enemy.y - 70.0f;
                for (int i = 0; i < 30; ++i) {
                    const int jitterX = static_cast<int>(
                        lateBossFrameRand(timer + i * 0x37) % 41u) - 20;
                    const auto angle3 = normalizeAngle16(
                        0x3e0c + static_cast<int>(lateBossFrameRand(
                            timer + i * 0x15b3) % 1001u));
                    const auto angle5 = normalizeAngle16(
                        0x3e0c + static_cast<int>(lateBossFrameRand(
                            timer + i * 0xd903) % 1001u));
                    spawnProjectileNode(
                        3, 0, sideX + static_cast<float>(jitterX), fireY,
                        angle3, 0.0f, 8.0 + i, 1, 0);
                    spawnProjectileNode(
                        5, 0, sideX + static_cast<float>(jitterX), fireY,
                        angle5, 0.0f, 8.3 + i, 1, 0);
                }

                const int ringSeed = static_cast<int>(
                    lateBossFrameRand(timer) % 1001u) - 0x76b0;
                for (int i = 0; i < 27; ++i) {
                    spawnProjectileNode(
                        2, 0, sideX, fireY,
                        normalizeAngle16(ringSeed + i * 0x40e),
                        0.0f, 11.1, 1, 0);
                }

                constexpr std::array<double, 3> kSpeeds{{5.0, 6.0, 7.0}};
                constexpr std::array<int, 3> kRightBases{{
                    0x35c8, 0x3d98, 0x4568,
                }};
                constexpr std::array<int, 3> kLeftBases{{
                    -11000, -13000, -15000,
                }};
                for (std::size_t layer = 0; layer < kSpeeds.size(); ++layer) {
                    const int base = right ? kRightBases[layer]
                                           : kLeftBases[layer];
                    for (int i = 0; i < 11; ++i) {
                        spawnProjectileNode(
                            4, 0, enemy.x, enemy.y,
                            normalizeAngle16(base + i * 3000),
                            0.0f, kSpeeds[layer], 1, 0);
                    }
                }
            };
            if (timer >= 60 && timer < 620 &&
                (timer - 60) % 72 == 0) {
                fireMirrorBurst(true);
                fired = true;
            }
            if (timer >= 96 && timer < 620 &&
                (timer - 96) % 72 == 0) {
                fireMirrorBurst(false);
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
            else if (timer >= 210 && timer < 421) {
                const double phase = static_cast<double>(timer - 210) *
                                     kTau / 210.0;
                enemy.markerDrawX = 360.0f -
                    static_cast<float>(std::sin(phase) * 240.0);
                enemy.markerDrawY = 250.0f +
                    static_cast<float>(std::cos(phase) * 80.0);
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
    case 0x125:
    case 0x126: { // FUN_140064630 mirrored phase-131 controllers
        const bool right = enemy.spawnType == 0x125;
        if (timer % 50 == 0) {
            enemy.markerDrawX = (right ? 460.0f : 160.0f) +
                static_cast<float>(lateBossFrameRand(frame_ + enemy.entityId) % 101u);
            enemy.markerDrawY = 200.0f + static_cast<float>(
                lateBossFrameRand(frame_ + enemy.entityId * 0x1e61) % 101u);
        }
        steerAndMove(enemy.markerDrawX, enemy.markerDrawY, 0x200, 0.3);

        if (timer < 10) {
            break;
        }
        const int local = (timer - 10) % 0x708;
        const float muzzleX = enemy.x + (right ? -88.0f : 80.0f);
        const float muzzleY = enemy.y + (right ? -120.0f : -122.0f);
        const auto aimed = aimAt(muzzleX, muzzleY);

        // Three short five-way fans begin at 30/450/900 within the 1800-frame
        // cycle.  +0x42 caches the aim and is pulled toward the player by at
        // most 0x140 after each four-frame burst.
        constexpr std::array<int, 3> kFanBases{{0, 0x1a4, 0x366}};
        for (const int base : kFanBases) {
            if (local == base + 0x1e) {
                enemy.secondaryAngle16 = aimed;
            }
            if (local >= base + 0x1e && local < base + 0x46 &&
                (local - base - 0x1e) % 4 == 0) {
                const int visual = right ? 0x0b : 10;
                const double speed = 6.0 + (local - base - 0x1e) * 0.3;
                for (int i = 0; i < 5; ++i) {
                    spawnProjectileNode(
                        visual, 0, muzzleX, muzzleY,
                        normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) -
                                         3000 + i * 1500),
                        10.0f, speed, 1, 0);
                }
                enemy.secondaryAngle16 = approachAngle16(
                    enemy.secondaryAngle16, aimed, 0x140);
                fired = true;
            }
        }

        const int earlyStart = right ? 0x3c : 0x4a;
        if (local >= earlyStart && local < 0x1a4 &&
            (local - earlyStart) % 0x1c == 0) {
            const int amplitude = right ? 9000 : -14162;
            const int oscillation = static_cast<int>(
                std::sin((timer - 90) * kTau / 180.0) * amplitude);
            const double speed = 4.0 + (local - 0x3c) * 0.016;
            for (int i = 0; i < 13; ++i) {
                spawnProjectileNode(
                    right ? 3 : 2, 0, muzzleX, muzzleY,
                    normalizeAngle16(static_cast<int>(aimed) + oscillation -
                                     12000 + i * 2000),
                    10.0f, speed, 1, 0);
            }
            fired = true;
        }

        if (right && local >= 0x1e0 && local < 0x366 &&
            (local - 0x1e0) % 0x24 == 0) {
            const double speed = 4.6 + (local - 0x1e0) * 0.008;
            for (int i = 0; i < 11; ++i) {
                spawnProjectileNode(5, 0, muzzleX, muzzleY,
                    normalizeAngle16(static_cast<int>(aimed) - 2000 + i * 400),
                    0.0f, speed, 1, 0);
                spawnProjectileNode(5, 0, muzzleX, muzzleY,
                    normalizeAngle16(static_cast<int>(aimed) + 6000 + i * 400),
                    0.0f, speed, 1, 0);
                spawnProjectileNode(5, 0, muzzleX, muzzleY,
                    normalizeAngle16(static_cast<int>(aimed) - 10000 + i * 400),
                    0.0f, speed, 1, 0);
            }
            fired = true;
        }
        if (!right && local >= 0x1e0 && local < 0x366 &&
            (local - 0x1e0) % 6 == 0) {
            const double speed = 5.0 + (local - 0x1e0) * 0.012 +
                                 std::sin((timer - 480) * kTau / 180.0) * 0.8;
            for (int i = 0; i < 7; ++i) {
                spawnProjectileNode(
                    8, 0, muzzleX, muzzleY,
                    normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) +
                                     local * 0xf0 + 0x3e00 + i * 0x2492),
                    0.0f, speed, 1, 0);
            }
            fired = true;
        }

        const int spiralStart = right ? 0x3a2 : 0x3b2;
        if (local == spiralStart) {
            enemy.secondaryAngle16 = aimed;
        }
        if (local >= spiralStart && local < 0x6fe) {
            const int offset = local - spiralStart;
            const int within32 = offset & 0x1f;
            if (within32 < 0x12 && within32 % 3 == 0) {
                const double speed = 5.5 + (local - 0x3a2) * 0.01;
                for (int i = 0; i < 13; ++i) {
                    spawnProjectileNode(
                        right ? 0x0b : 10, 0, muzzleX, muzzleY,
                        normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) +
                                         i * 0x13b1),
                        10.0f, speed, 1, 0);
                }
                fired = true;
            }
            const int curve = 0x3c + (local - 0x3a2) / 0x10;
            enemy.secondaryAngle16 = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) + (right ? -curve : curve));
        }
        break;
    }
    case 0x127: { // FUN_140066370 phase-141 controller
        const auto advance = [&enemy](int endTimer) {
            if (enemy.helperTimer == endTimer) {
                ++enemy.helperState;
                enemy.helperTimer = 0;
            }
        };
        const int state = enemy.helperState;

        // States 1..4, 6/7/9/11/14/16/25 and the forced state 98 are the
        // original 35-frame travel cells.  Their destinations differ, but all
        // use the same sine ease and commit the next state at timer 35.
        const bool travelState =
            (state >= 1 && state <= 4) || state == 6 || state == 7 ||
            state == 9 || state == 11 || state == 14 || state == 16 ||
            state == 25 || state == 98;
        if (travelState) {
            if (timer == 1) {
                enemy.originX = enemy.x;
                enemy.originY = enemy.y;
                const std::uint32_t random = lateBossFrameRand(
                    static_cast<int>(frame_ + enemy.entityId + state * 0x223d));
                enemy.markerDrawX = 160.0f + static_cast<float>(random % 401u);
                enemy.markerDrawY = 200.0f + static_cast<float>((random >> 8) % 301u);
                if (state == 14 || state == 25) {
                    enemy.markerDrawX = 360.0f;
                    enemy.markerDrawY = 250.0f;
                }
                else if (state == 16) {
                    enemy.markerDrawX = 280.0f;
                    enemy.markerDrawY = 360.0f;
                }
                else if (state == 98) {
                    enemy.markerDrawX = parent->x;
                    enemy.markerDrawY = parent->y;
                    enemy.targetable = false;
                }
            }
            const double p = std::clamp(timer / 35.0, 0.0, 1.0);
            const double eased = std::sin(p * kPi * 0.5);
            enemy.x = enemy.originX +
                static_cast<float>((enemy.markerDrawX - enemy.originX) * eased);
            enemy.y = enemy.originY +
                static_cast<float>((enemy.markerDrawY - enemy.originY) * eased);
            enemy.sourceAngle16 = normalizeAngle16(static_cast<int>(
                std::atan2(enemy.markerDrawY - enemy.y,
                           enemy.markerDrawX - enemy.x) * 65536.0 / kTau));
            advance(0x23);
            break;
        }

        if (state == 5 || state == 8 || state == 10 ||
            state == 12 || state == 13) {
            steerAndMove(player_.x, player_.y, 0x200, 0.3);
            if (timer == 0x28) {
                const int emitterType = state == 13 ? 0x12c : 0x12b;
                const auto aimed = aimAt(enemy.x, enemy.y);
                for (int i = 0; i < 4; ++i) {
                    spawnStage10FinalBossEmitter(
                        enemy, emitterType, enemy.x, enemy.y,
                        normalizeAngle16(static_cast<int>(aimed) + i * 0x4000),
                        5.0, i);
                }
                if (state != 13) {
                    spawnProjectileSpread(0x0c, 1, enemy.x, enemy.y, aimed,
                                          0.0f, 5.0, 1, 20, 0x10000, 0);
                }
                fired = true;
            }
            advance(state == 12 ? 0x3c : (state == 13 ? 0x78 : 0x5a));
            break;
        }

        if (state == 15) {
            if (timer < 100) {
                steerAndMove(player_.x, player_.y, 0x200, 0.3);
            }
            if (timer == 0x5a) {
            for (int i = 0; i < 32; ++i) {
                const std::uint32_t random = lateBossFrameRand(
                        enemy.entityId + i * 0x58 + timer);
                const auto heading = normalizeAngle16(
                    static_cast<int>(random & 0xffffu));
                    const double speed = 4.0 +
                        static_cast<double>((random >> 16) % 401u) / 100.0;
                spawnStage10FinalBossEmitter(
                    enemy, 0x129, enemy.x, enemy.y, heading, speed, i);
            }
                fired = true;
            }
            if (timer == 100) {
                enemy.originX = enemy.x;
                enemy.originY = enemy.y;
                enemy.x = -1000.0f;
                enemy.y = -1000.0f;
            }
            if (timer >= 0x96 && timer < 0x2b2) {
                const int cadence = timer < 0xf6 ? 0x18 : 6;
                if ((timer - 0x96) % cadence == 0) {
                    const std::uint32_t random = lateBossFrameRand(
                        enemy.entityId + timer * 0x15b38);
                    const float x = 60.0f + static_cast<float>(random % 601u);
                    const auto angle = normalizeAngle16(
                        static_cast<int>(aimAt(x, -20.0f)) - 0x708 +
                        static_cast<int>((random >> 16) % 0xe11u));
                    spawnProjectileNode(2, 0x3c, x, -20.0f, angle,
                                        0.0f, 7.0, 1, 0);
                    fired = true;
                }
            }
            advance(0x2d0);
            break;
        }

        if (state == 17) {
            enemy.targetable = false;
            advance(0x14);
            break;
        }

        if (state >= 18 && state <= 20) {
            if (timer == 0x32) {
                const auto base = normalizeAngle16(static_cast<int>(
                    lateBossFrameRand(enemy.entityId + state * 0x4d)));
                spawnProjectileSpread(5, 0, enemy.x, enemy.y, base,
                                      0.0f, 5.0 + (state - 18) * 0.5,
                                      1, 17, 0x10000, 0);
                fired = true;
            }
            advance(0x32);
            break;
        }

        if (state >= 21 && state <= 24) {
            if (timer == 0x46 && state != 24) {
                const auto base = normalizeAngle16(static_cast<int>(
                    lateBossFrameRand(enemy.entityId + state * 0x378)));
                for (int i = 0; i < 4; ++i) {
                    spawnProjectileSpread((i & 1) == 0 ? 5 : 3, 0,
                                          enemy.x, enemy.y,
                                          normalizeAngle16(base + i * 0x4000),
                                          0.0f, 3.0 + i * 0.4, 1,
                                          27 + i * 2, 0x10000, 0);
                }
                for (int i = 0; i < 128; ++i) {
                    const std::uint32_t random = lateBossFrameRand(
                        enemy.entityId + state * 9999 + i * 99);
                    spawnProjectileNode(
                        0x0c, 0, enemy.x, enemy.y,
                        normalizeAngle16(static_cast<int>(random & 0xffffu)),
                        0.0f, 5.0 + static_cast<double>((random >> 16) % 301u) / 100.0,
                        1, 0);
                }
                fired = true;
            }
            advance(state == 24 ? 0x23 : 0x78);
            break;
        }

        if (state == 26) {
            if (timer == 0x50) {
                for (int i = 0; i < 155; ++i) {
                    const std::uint32_t random = lateBossFrameRand(
                        enemy.entityId + timer * 0xd05 + i * 999);
                    spawnProjectileNode(
                        0x0c, 0, enemy.x, enemy.y,
                        normalizeAngle16(static_cast<int>(random & 0xffffu)),
                        0.0f, 2.5 + static_cast<double>((random >> 16) % 351u) / 100.0,
                        1, 0);
                }
                fired = true;
            }
            if (timer < 0x78) {
                steerAndMove(player_.x, player_.y, 0x200, 0.3);
            }
            else {
                const double phase = (timer - 0x78) * kTau / 120.0;
                enemy.x = enemy.originX + static_cast<float>(std::cos(phase) * 80.0);
                enemy.y = enemy.originY + static_cast<float>(std::sin(phase) * 90.0);
            }
            advance(0xf0);
            break;
        }

        if (state >= 27 && state <= 31) {
            if (timer == 1) {
                constexpr std::array<float, 5> kX{{870.0f, -150.0f, 870.0f, 120.0f, 400.0f}};
                constexpr std::array<float, 5> kY{{100.0f, 240.0f, 480.0f, 870.0f, -150.0f}};
                constexpr std::array<int, 5> kAngle{{0x7830, 2000, 0x7830, 0xc7d0, 0x3830}};
                const int index = state - 27;
                enemy.x = kX[static_cast<std::size_t>(index)];
                enemy.y = kY[static_cast<std::size_t>(index)];
                enemy.sourceAngle16 = normalizeAngle16(kAngle[static_cast<std::size_t>(index)]);
                enemy.sourceSpeed = 10.0;
            }
            if (timer > 0x31) {
                const double radians = fixedAngleRadians(enemy.sourceAngle16);
                enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
                enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
                enemy.sourceSpeed += 0.05;
                const std::uint32_t random = lateBossFrameRand(
                    enemy.entityId + state * 0x22b + timer * 0x58);
                const float burstX = enemy.x +
                    static_cast<float>(static_cast<int>(random % 111u) - 55);
                const float burstY = enemy.y +
                    static_cast<float>(static_cast<int>((random >> 8) % 111u) - 55);
                if (burstX >= 0.0f && burstX <= 720.0f &&
                    burstY >= 0.0f && burstY <= 900.0f) {
                    spawnProjectileNode(2, 0x12, burstX, burstY,
                                        normalizeAngle16(static_cast<int>(random >> 16)),
                                        0.0f, 2.5, 1, 0);
                    const auto curve = normalizeAngle16(
                        static_cast<int>(enemy.sourceAngle16) + timer * 0x9c4);
                    spawnProjectileNode(0x0d, 3, enemy.x, enemy.y, curve,
                                        0.0f, 4.0, 1, 0);
                    spawnProjectileNode(0x0d, 3, enemy.x, enemy.y,
                                        normalizeAngle16(0x8000 - curve),
                                        0.0f, 4.0, 1, 0);
                    fired = true;
                }
            }
            advance(0x8c);
            break;
        }

        if (state == 99) {
            enemy.targetable = false;
            if (timer < 0xb4) {
                enemy.drawBodyThisFrame = false;
            }
            if (timer < 0x118 && (timer & 1) == 0) {
                const std::uint32_t random = lateBossFrameRand(
                    enemy.entityId + timer * 0x15b38);
                spawnStage10FinalBossEmitter(
                    enemy, 0x12a, enemy.x, enemy.y,
                    normalizeAngle16(static_cast<int>(random & 0xffffu)),
                    12.0, timer / 2);
            }
            if (timer >= 300) {
                enemy.active = false;
                if (parent->liveChildCount > 0) {
                    --parent->liveChildCount;
                }
            }
        }
        break;
    }
    case 0x12d: {
        // FUN_14006ad60 keeps this controller on the root's x and 60 pixels
        // below it while its six internal launchers own the visible pattern.
        enemy.x += (parent->x - enemy.x) * 0.2f;
        enemy.y += (parent->y + 60.0f - enemy.y) * 0.2f;

        if (enemy.helperState == 1 && enemy.hp < enemy.maxHp * 3 / 4) {
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            return;
        }
        if (enemy.helperState == 2 && enemy.hp < enemy.maxHp / 2) {
            enemy.helperState = 3;
            enemy.helperTimer = 0;
            return;
        }
        if (enemy.helperState >= 1 && enemy.helperState <= 3) {
            if (timer >= 10 && (timer - 10) % 0x168 == 0) {
                const int type = 0x12e + (enemy.helperState - 1) * 2;
                spawnStage10FinalBossEmitter(
                    enemy, type, 0.0f, -123.0f,
                    normalizeAngle16(static_cast<int>(
                        lateBossFrameRand(timer + enemy.entityId))),
                    0.0, timer / 0x168);
            }
            if (timer >= 0xbe && (timer - 0xbe) % 0x168 == 0) {
                const int type = 0x12f + (enemy.helperState - 1) * 2;
                spawnStage10FinalBossEmitter(
                    enemy, type, 0.0f, -123.0f,
                    normalizeAngle16(static_cast<int>(
                        lateBossFrameRand(timer + enemy.entityId))),
                    0.0, timer / 0x168);
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

    if (isStage06EnemyType(enemy.spawnType)) {
        updateStage06Enemy(enemy);
        return;
    }

    if (isSharedHitboxProxyType(enemy.spawnType)) {
        updateSharedHitboxProxy(enemy);
        return;
    }

    if (isStage10GuardNodeType(enemy.spawnType)) {
        updateStage10GuardNode(enemy);
        return;
    }

    if (isStage10SceneNodeType(enemy.spawnType)) {
        updateStage10SceneNode(enemy);
        return;
    }

    if (enemy.spawnType >= 0xfa && enemy.spawnType <= 0x104) {
        updateStage10Enemy(enemy);
        return;
    }

    if (isStage08EnemyType(enemy.spawnType)) {
        updateStage08Enemy(enemy);
        return;
    }

    if (enemy.parentSpawnType == 0x13c &&
        enemy.spawnType >= 0x54 && enemy.spawnType <= 0x56) {
        updateStage05BossChild(enemy);
        return;
    }

    if (enemy.spawnType >= 0x70 && enemy.spawnType <= 0x78) {
        updateStage07Enemy(enemy);
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
            enemy, lateEnemyDeathRewardWindow(enemy.spawnType), false);
        spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        enemy.helperState = 2;
        enemy.helperTimer = 0;
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
            target, lateEnemyDeathRewardWindow(target.spawnType), false);
        spawnEnemyDeathEffects(
            target, lateEnemyDeathEffectMode(target.spawnType));
        target.targetable = false;
        if (releaseParent) {
            releaseFromParent(target);
        }
        else {
            target.active = false;
        }
    };
    const auto outsideBounds = [this](const StageEnemy& target, float left,
                                      float right, float top, float bottom) {
        const float horizontalOrigin = player_.x / 6.0f;
        return target.x < horizontalOrigin + left ||
               target.x > horizontalOrigin + right ||
               target.y < top || target.y > bottom;
    };
    const auto clampToPlayfield = [this](float x, float y, float margin) {
        const float horizontalOrigin = player_.x / 6.0f;
        return std::pair<float, float>{
            std::clamp(x, horizontalOrigin + margin,
                       horizontalOrigin + 600.0f - margin),
            std::clamp(y, margin, 720.0f - margin),
        };
    };

    if (enemy.spawnType == 0xad) { // FUN_140042b10
        if (enemy.helperState == 0) {
            const auto marker = clampToPlayfield(enemy.x, enemy.y, -20.0f);
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = marker.first;
            enemy.markerDrawY = marker.second;
            if (enemy.helperTimer >= 20) {
                const std::uint32_t random = lateStageScriptRand(frame_);
                enemy.sourceAngle16 = normalizeAngle16(
                    0x3a24 + static_cast<int>(random % 3001u));
                enemy.x = marker.first;
                enemy.y = marker.second;
                enemy.sourceSpeed = 6.0;
                enemy.speed = 6.0f;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            if (enemy.helperState == 0) {
                return;
            }
        }

        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, false);
            return;
        }
        if (outsideBounds(enemy, -180.0f, 900.0f, -180.0f, 900.0f)) {
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

    if (enemy.spawnType == 0x44) { // FUN_140096890
        if (enemy.helperState == 0) {
            const auto marker = clampToPlayfield(enemy.x, enemy.y, -20.0f);
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = marker.first;
            enemy.markerDrawY = marker.second;
            if (enemy.helperTimer >= 20) {
                const int randomAngle = static_cast<int>(
                    lateStageScriptRand(frame_) % 3001u);
                if (enemy.y <= 0.0f) {
                    enemy.sourceAngle16 = normalizeAngle16(0x3a24 + randomAngle);
                }
                if (enemy.x <= 0.0f) {
                    enemy.sourceAngle16 = normalizeAngle16(-0x5dc + randomAngle);
                }
                if (enemy.x >= 720.0f) {
                    enemy.sourceAngle16 = normalizeAngle16(0x7a24 + randomAngle);
                }
                enemy.x = marker.first;
                enemy.y = marker.second;
                enemy.sourceSpeed = selectedStage_ >= 9 ? 6.0 : 3.0;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            if (enemy.helperState == 0) {
                return;
            }
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
                const auto deathAim = aimAtPlayer16();
                fire(deathAim, speed);
                if (difficulty > 2) {
                    fire(deathAim, speed + 2.0);
                }
                if (difficulty > 3) {
                    for (const int offset : {-0xd05, 0xd05}) {
                        const auto angle = normalizeAngle16(
                            static_cast<int>(deathAim) + offset);
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
            const auto marker = clampToPlayfield(enemy.x, enemy.y, -20.0f);
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = marker.first;
            enemy.markerDrawY = marker.second;
            if (enemy.helperTimer >= 20) {
                enemy.sourceSpeed = 6.0 +
                    static_cast<double>(lateStageScriptRand(frame_) % 201u) /
                        100.0;
                if (enemy.x <= 0.0f) enemy.sourceAngle16 = 0;
                if (enemy.x >= 720.0f) enemy.sourceAngle16 = 0x8000;
                enemy.x = marker.first;
                enemy.y = marker.second;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            if (enemy.helperState == 0) {
                return;
            }
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
            const auto marker = clampToPlayfield(enemy.x, enemy.y, -50.0f);
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = marker.first;
            enemy.markerDrawY = marker.second;
            if (enemy.helperTimer >= 20) {
                enemy.sourceSpeed = 12.0;
                if (enemy.x <= 0.0f) enemy.sourceAngle16 = 2000;
                if (enemy.x >= 720.0f) enemy.sourceAngle16 = 0x7830;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            if (enemy.helperState == 0) {
                return;
            }
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, false);
            return;
        }
        if (enemy.helperTimer >= 120 &&
            outsideBounds(enemy, -128.0f, 728.0f, -128.0f, 848.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer < 100) {
            if (enemy.sourceSpeed > 0.0) enemy.sourceSpeed -= 0.12;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimAtPlayer16(), 0x20);
        }
        else if (enemy.helperTimer < 240) {
            if (enemy.helperTimer == 100) {
                enemy.sourceAngle16 = aimAtPlayer16();
            }
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
                playPlayerSound(bossSe1SoundHandle_, 0x19);
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
            const double entranceWave = std::sin(
                static_cast<double>(timer) * kPi / 180.0);
            const int radius = 90 - static_cast<int>(entranceWave * 90.0);
            int entranceAngle16 = static_cast<int>(entranceWave * 65536.0);
            if (enemy.spawnType == 0x48) {
                entranceAngle16 = -entranceAngle16;
            }
            const double entranceAngle = fixedAngleRadians(
                normalizeAngle16(entranceAngle16));
            enemy.x = enemy.originX +
                      static_cast<float>(std::cos(entranceAngle) *
                                         static_cast<double>(radius));
            enemy.y = enemy.originY +
                      static_cast<float>(std::sin(entranceAngle) *
                                         static_cast<double>(radius));
            if (enemy.helperTimer >= 90) {
                enemy.x = enemy.originX;
                enemy.y = enemy.originY;
                enemy.sourceSpeed = 0.5;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            if (enemy.helperState == 0) {
                return;
            }
        }
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, false);
            return;
        }
        if (outsideBounds(enemy, -128.0f, 728.0f, -128.0f, 848.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer < 121 && enemy.sourceSpeed > 1.2) {
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
        if (parent == nullptr || !parent->active ||
            (parent->spawnType != 0x47 && parent->spawnType != 0x48)) {
            releaseFromParent(enemy);
            return;
        }
        if (parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, true);
            return;
        }
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        // +0x30 is the mutable orbit radius. FUN_140098f40 clears it when
        // materialization ends, so the node then eases back into its owner.
        const float radius = enemy.originX;
        const float targetX = parent->x +
                              static_cast<float>(std::cos(radians) * radius);
        const float targetY = parent->y +
                              static_cast<float>(std::sin(radians) * radius);
        if (enemy.helperTimer == 0 && enemy.helperState == 0) {
            enemy.x = parent->x;
            enemy.y = parent->y;
        }
        enemy.x += (targetX - enemy.x) / 30.0f;
        enemy.y += (targetY - enemy.y) / 30.0f;
        const int turn = parent->spawnType == 0x47 ? 0x1bc : -0x1bc;
        enemy.sourceAngle16 = normalizeAngle16(
            static_cast<int>(enemy.sourceAngle16) + turn);
        if (enemy.helperState == 0) {
            if (enemy.helperTimer < 30) {
                enemy.originX = static_cast<float>(static_cast<int>(
                    std::sin(static_cast<double>(enemy.helperTimer) *
                             kPi / 60.0) *
                    static_cast<double>(enemy.sourceX)));
            }
            else {
                enemy.originX = 0.0f;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
        }
        return;
    }

    if (enemy.spawnType == 0x4a) { // FUN_140099570
        if (enemy.helperState == 0) {
            const auto marker = clampToPlayfield(enemy.x, enemy.y, -50.0f);
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = marker.first;
            enemy.markerDrawY = marker.second;
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
            if (enemy.helperState == 0) {
                return;
            }
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, false);
            return;
        }
        if (outsideBounds(enemy, -128.0f, 728.0f, -128.0f, 848.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer <= 120 && enemy.sourceSpeed > 0.8) {
            enemy.sourceSpeed -= 0.09;
        }
        const auto baseAim = radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - enemy.originY),
            static_cast<double>(player_.x - enemy.originX)));
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, baseAim, 0x80);
        if (enemy.helperTimer > 289) enemy.sourceSpeed -= 0.1;
        const double baseRadians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.originX += static_cast<float>(
            std::cos(baseRadians) * enemy.sourceSpeed);
        enemy.originY += static_cast<float>(
            std::sin(baseRadians) * enemy.sourceSpeed);
        const double swayPhase = fixedAngleRadians(normalizeAngle16(
            static_cast<int>(frame_ * 268.59016393442624)));
        const float targetX = enemy.originX + static_cast<float>(
            std::sin(swayPhase) * 100.0);
        enemy.x += (targetX - enemy.x) / 30.0f;
        enemy.y += (enemy.originY - enemy.y) / 30.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        return;
    }

    if (enemy.spawnType == 0x4b) { // FUN_14008bd60 Stage 5 branch
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->spawnType != 0x4a ||
            !parent->active) {
            releaseFromParent(enemy);
            return;
        }
        if (parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
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
        enemy.x += (targetX - enemy.x) * 0.125f;
        enemy.y += (targetY - enemy.y) * 0.125f;

        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int interval = std::array<int, 5>{{60, 40, 34, 30, 25}}[
            static_cast<std::size_t>(difficulty)];
        const int start = (enemy.entityId - parent->entityId) * interval + 44;
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.helperTimer >= start && parent->helperState == 1 &&
            parent->helperTimer < 290 &&
            (enemy.helperTimer - start) % (interval * 5) == 0 &&
            enemy.x >= horizontalOrigin + 10.0f &&
            enemy.x <= horizontalOrigin + 590.0f &&
            enemy.y >= 10.0f && enemy.y <= 710.0f) {
            const auto angle = radiansToAngle16(std::atan2(
                static_cast<double>(player_.y - (enemy.y + 30.0f)),
                static_cast<double>(player_.x - enemy.x)));
            spawnInternalChild(
                *parent, 0x4c, 400, 4, enemy.x, enemy.y, angle,
                3.6, 80, false,
                "S05 FUN_14008bd60 staggered type 0x4c projectile enemy");
            playPlayerSound(bullet2SoundHandle_, 0x13);
        }
        return;
    }

    if (enemy.spawnType == 0x4c) { // FUN_140099e50
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        // FUN_140099e50 advances along the constructor angle before both its
        // 20-tick materialization branch and its lethal branch.
        setVelocity(enemy.sourceSpeed);
        enemy.x += enemy.vx;
        enemy.y += enemy.vy;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (enemy.helperState == 0 && enemy.helperTimer >= 20) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.radius = config_.difficulty <= 1 ? 64 : 80;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }
        if (enemy.hp < 1) {
            const float distance = std::sqrt(
                (player_.x - enemy.x) * (player_.x - enemy.x) +
                (player_.y - enemy.y) * (player_.y - enemy.y));
            if (distance >= static_cast<float>(enemy.radius + 30) &&
                enemy.y < 520.0f && enemy.y < player_.y) {
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
            spawnEnemyDeathRewardBurst(enemy, 300, false);
            enemy.radius = static_cast<int>(enemy.radius * 0.6f);
            spawnEnemyDeathEffects(enemy, 0);
            spawnDelayedOwnerDamageNode(
                enemy.maxHp, enemy.parentEntityId, enemy.parentSpawnType,
                "S05 type 0x4c delayed-damage node 0x153");
            enemy.targetable = false;
            // FUN_140099e50 unlinks 0x4c immediately. The independent 0x153
            // entity owns the original 30-update damage transfer to 0x4a.
            releaseFromParent(enemy);
            return;
        }
        if (outsideBounds(enemy, -128.0f, 728.0f, -128.0f, 848.0f)) {
            releaseFromParent(enemy);
            return;
        }
        return;
    }

    if (enemy.spawnType == 0x4d) { // FUN_14009a4a0
        if (enemy.helperState == 0) {
            enemy.targetable = false;
            if (enemy.helperTimer == 0) {
                playPlayerSound(bossSe8SoundHandle_, 0x19);
            }
            if (enemy.helperTimer >= 20) {
                if (enemy.x <= 0.0f) enemy.sourceAngle16 = 0;
                if (enemy.x >= 720.0f) enemy.sourceAngle16 = 0x8000;
                const auto clamped = clampToPlayfield(
                    enemy.x, enemy.y, -150.0f);
                enemy.x = clamped.first;
                enemy.y = clamped.second;
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
            if (enemy.helperState == 0) {
                return;
            }
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 2) {
            enemy.targetable = false;
            enemy.vy = static_cast<float>(enemy.helperTimer) * 0.06f;
            if (enemy.helperTimer < 61) {
                spawnStage02DeathExplosionChain(enemy);
            }
            if (enemy.helperTimer == 60) {
                spawnEnemyDeathEffects(enemy, 2);
                if (isLateStageGateOwner(enemy)) {
                    clearLateStageGate(selectedStage_);
                }
                enemy.active = false;
            }
            return;
        }
        if (enemy.hp < 1) {
            beginExactDeath();
            enemy.y += 230.0f;
            enemy.radius = 150;
            spawnStage02DeathExplosionChain(enemy);
            return;
        }
        if (outsideBounds(enemy, -400.0f, 1000.0f, -400.0f, 1120.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer <= 90 && enemy.sourceSpeed > 0.5) {
            enemy.sourceSpeed -= 0.1;
        }
        const int turnStep = enemy.helperTimer < 90
                                 ? enemy.helperTimer * 4
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
            !parent->active) {
            releaseFromParent(enemy);
            return;
        }
        if (parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
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
        enemy.x = mountX + static_cast<float>(std::cos(radians) * 30.0);
        enemy.y = mountY + static_cast<float>(std::sin(radians) * 30.0);
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
                                       ? std::sin(static_cast<double>(
                                             std::clamp(enemy.helperTimer, 0, 100)) *
                                             kPi / 200.0)
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
            enemy.x += (targetX - enemy.x) / 5.0f;
            enemy.y += (targetY - enemy.y) / 5.0f;
        }
        if (enemy.spawnType == 0x50 && parent->helperState == 2 &&
            parent->helperTimer == 60) {
            releaseFromParent(enemy);
        }
        return;
    }

    if (enemy.spawnType == 0x53) { // FUN_14009cd10
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->spawnType != 0x4f ||
            !parent->active) {
            releaseFromParent(enemy);
            return;
        }
        if (parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 1);
            enemy.active = false;
            return;
        }
        enemy.drawBodyThisFrame = true;
        const float targetX = parent->x + enemy.originX;
        const float targetY = parent->y + enemy.originY;
        if (enemy.helperTimer == 0 && enemy.helperState == 0) {
            enemy.x = targetX;
            enemy.y = targetY;
        }
        enemy.x += (targetX - enemy.x) / 30.0f;
        enemy.y += (targetY - enemy.y) / 30.0f;
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
            if (enemy.helperState == 0) {
                return;
            }
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
                playPlayerSound(bossSe8SoundHandle_, 0x19);
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
            if (enemy.helperState == 0) {
                return;
            }
        }
        if (enemy.helperState == 1) {
            if (enemy.hp < 1) {
                beginExactDeath();
                enemy.radius = 240;
                spawnStage02DeathExplosionChain(enemy);
                return;
            }
            switch (enemy.helperTimer) {
            case 220:
                spawnInternalChild(
                    enemy, 0x53, 99999999, 1, 220.0f, -40.0f,
                    0x4000, 1.0, 40, false,
                    "S05 FUN_14009b5f0 timer 220 type 0x53 battery");
                playPlayerSound(bossSe1SoundHandle_, 0x19);
                break;
            case 230:
                spawnInternalChild(
                    enemy, 0x53, 99999999, 1, -220.0f, -40.0f,
                    0x4000, 1.0, 40, false,
                    "S05 FUN_14009b5f0 timer 230 type 0x53 battery");
                playPlayerSound(bossSe1SoundHandle_, 0x19);
                break;
            case 240:
                spawnInternalChild(
                    enemy, 0x53, 99999999, 1, 120.0f, -120.0f,
                    0x4000, 1.0, 40, false,
                    "S05 FUN_14009b5f0 timer 240 type 0x53 battery");
                playPlayerSound(bossSe1SoundHandle_, 0x19);
                break;
            case 250:
                spawnInternalChild(
                    enemy, 0x53, 99999999, 1, -120.0f, -120.0f,
                    0x4000, 1.0, 40, false,
                    "S05 FUN_14009b5f0 timer 250 type 0x53 battery");
                playPlayerSound(bossSe1SoundHandle_, 0x19);
                break;
            default:
                break;
            }
            if (enemy.helperTimer < 1200) {
                if (frame_ % 50 == 0) {
                    const auto randomX = lateStageScriptRand(frame_);
                    const auto randomY = lateStageScriptRand(frame_ + 0x15b3);
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
        enemy.targetable = false;
        enemy.vy = static_cast<float>(enemy.helperTimer) * 0.15f;
        if (enemy.helperTimer < 61) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (enemy.helperTimer == 60) {
            spawnEnemyDeathEffects(enemy, 2);
            if (isLateStageGateOwner(enemy)) {
                clearLateStageGate(selectedStage_);
            }
            enemy.active = false;
        }
        return;
    }
}

void StageRuntime::emitLateStageProjectiles(StageEnemy& enemy, int activeAge) {
    if (isStage06EnemyType(enemy.spawnType)) {
        emitStage06EnemyProjectiles(enemy);
        return;
    }

    if (isStage10SceneNodeType(enemy.spawnType) ||
        isSharedHitboxProxyType(enemy.spawnType) ||
        isStage10GuardNodeType(enemy.spawnType)) {
        return;
    }

    if (enemy.spawnType >= 0xfa && enemy.spawnType <= 0x104) {
        emitStage10EnemyProjectiles(enemy);
        return;
    }

    if (isStage08EnemyType(enemy.spawnType)) {
        return;
    }

    if (enemy.spawnType >= 0x70 && enemy.spawnType <= 0x78) {
        emitStage07EnemyProjectiles(enemy);
        return;
    }

    if (enemy.helperState != 1 || !enemy.targetable) {
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const float sourceX = enemy.x - enemy.vx;
    const float sourceY = enemy.y - enemy.vy;
    const auto aimFrom = [this](float x, float y) {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };

    if (enemy.hp < 1) {
        return;
    }

    if (enemy.spawnType == 0xad) { // FUN_140042b10
        if (activeAge >= 200) return;
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        const float fireX = enemy.x +
            static_cast<float>(std::cos(radians) * 20.0);
        const float fireY = enemy.y +
            static_cast<float>(std::sin(radians) * 20.0);
        if (fireX < 40.0f || fireX > 680.0f ||
            fireY < 40.0f || fireY > 760.0f) {
            return;
        }
        static constexpr std::array<int, 5> kInterval{{18, 10, 6, 8, 6}};
        static constexpr std::array<double, 5> kSpeed{{
            6.5, 7.2, 8.0, 8.5, 9.5,
        }};
        const int intervalValue =
            kInterval[static_cast<std::size_t>(difficulty)];
        if (activeAge <= 4) return;
        const int local = (activeAge - 5) % (intervalValue * 5);
        if (local >= intervalValue * 3 || local % intervalValue != 0) {
            return;
        }
        const float dx = player_.x - fireX;
        const float dy = player_.y - fireY;
        if (dx * dx + dy * dy < 90.0f * 90.0f) return;
        const auto rawAim = aimFrom(fireX, fireY);
        const auto snapped = normalizeAngle16(
            ((static_cast<int>(rawAim) + 0x400) >> 11) * 0x800);
        const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
        spawnProjectileNode(0, 0, fireX, fireY, snapped,
                            0.0f, speed, 1, 0);
        if (difficulty > 2) {
            spawnProjectileNode(
                0, 0, fireX, fireY,
                normalizeAngle16(static_cast<int>(snapped) - 2000),
                0.0f, speed - 1.0, 1, 0);
            spawnProjectileNode(
                0, 0, fireX, fireY,
                normalizeAngle16(static_cast<int>(snapped) + 2000),
                0.0f, speed - 1.0, 1, 0);
        }
        return;
    }

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
        const double visualPhase = fixedAngleRadians(normalizeAngle16(
            static_cast<int>((activeAge - 15) * 1365.3333333333333)));
        const float fireY = sourceY + 20.0f +
                            static_cast<float>(std::sin(visualPhase));
        const float horizontalOrigin = player_.x / 6.0f;
        if (activeAge >= start && activeAge < 150 &&
            (activeAge - start) % cadence == 0 &&
            sourceX >= horizontalOrigin + 40.0f &&
            sourceX <= horizontalOrigin + 560.0f &&
            sourceY >= 40.0f && sourceY <= 680.0f && enemy.x < 520.0f) {
            const auto aimed16 = aimFrom(sourceX, fireY);
            const auto snapped = normalizeAngle16(
                (static_cast<int>(aimed16) + 0x400) & ~0x7ff);
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(8, 0, sourceX, fireY,
                                snapped, 10.0f, speed, 1, 0);
            if (difficulty == 2) {
                spawnProjectileNode(8, 0, sourceX, fireY,
                                    snapped, 10.0f, speed + 0.5, 1, 0);
            }
            if (difficulty > 2) {
                spawnProjectileNode(8, 0, sourceX, fireY,
                                    normalizeAngle16(snapped - 2000),
                                    10.0f, speed - 1.5, 1, 0);
                spawnProjectileNode(8, 0, sourceX, fireY,
                                    normalizeAngle16(snapped + 2000),
                                    10.0f, speed - 1.5, 1, 0);
            }
        }
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
            const float fireX = enemy.x;
            const float fireY = enemy.y + 5.0f;
            const auto liveAim = aimFrom(fireX, fireY);
            if (local == 0) {
                enemy.secondaryAngle16 = liveAim;
            }
            const float horizontalOrigin = player_.x / 6.0f;
            const bool inFireBounds =
                fireX >= horizontalOrigin &&
                fireX <= horizontalOrigin + 600.0f &&
                fireY >= 0.0f && fireY <= 720.0f;
            if (inFireBounds && local < 30 && local % 5 == 0) {
                const double speed = kBase[static_cast<std::size_t>(difficulty)] +
                                     local * 0.06;
                spawnProjectileNode(7, 0, fireX, fireY,
                                    enemy.secondaryAngle16, 10.0f,
                                    speed, 1, 0);
                if (difficulty > 0) {
                    spawnProjectileSpread(
                        7, 0, fireX, fireY,
                        enemy.secondaryAngle16, 10.0f, speed - 1.0,
                        1, 2, kSpread[static_cast<std::size_t>(difficulty)], 0);
                }
                if (difficulty > 2) {
                    spawnProjectileNode(7, 0, fireX, fireY,
                                        enemy.secondaryAngle16, 10.0f,
                                        speed + 1.8, 1, 0);
                    spawnProjectileSpread(
                        7, 0, fireX, fireY,
                        enemy.secondaryAngle16, 10.0f, speed + 0.8,
                        1, 2, kSpread[static_cast<std::size_t>(difficulty)], 0);
                }
            }
            enemy.secondaryAngle16 = approachAngle16(
                enemy.secondaryAngle16, liveAim, 0x20);
        }
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
            const auto aimed16 = aimFrom(enemy.x, enemy.y);
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            const int spread = (count - 1) *
                               kAngleStep[static_cast<std::size_t>(difficulty)];
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(11, 0, enemy.x, enemy.y, aimed16,
                                  0.0f, speed, 1, count, spread, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(11, 0, enemy.x, enemy.y, aimed16,
                                      0.0f, speed - 1.5, 1, count,
                                      static_cast<int>(spread * 1.4), 0);
            }
        }
        return;
    }

    if (enemy.spawnType == 0x49) { // FUN_140098f40
        constexpr std::array<int, 5> kCadence{{150, 120, 90, 90, 70}};
        constexpr std::array<int, 5> kBurstStep{{12, 7, 5, 5, 4}};
        constexpr std::array<double, 5> kSpeed{{3.5, 4.5, 5.0, 5.0, 6.0}};
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
        }
        return;
    }

    if (enemy.spawnType == 0x4a) { // FUN_140099570
        constexpr std::array<int, 5> kCadence{{32, 24, 20, 20, 16}};
        constexpr std::array<int, 5> kCount{{5, 7, 9, 7, 9}};
        constexpr std::array<double, 5> kSpeed{{5.0, 5.5, 6.0, 6.5, 8.0}};
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        const double mountPhase = fixedAngleRadians(normalizeAngle16(
            static_cast<int>(activeAge * 1489.4545454545455)));
        const float fireY = enemy.y - 37.0f +
                            static_cast<float>(std::sin(mountPhase) * 2.0);
        if (activeAge >= 50 && activeAge < 290) {
            const int local = (activeAge - 50) % 120;
            if (local < cadence * 3 && local % cadence == 0) {
                const int count = kCount[static_cast<std::size_t>(difficulty)];
                const auto aimed16 = aimFrom(enemy.x, fireY);
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(4, 0, enemy.x, fireY,
                                      aimed16, 0.0f, speed, 1,
                                      count, 17000, 0);
                if (difficulty > 2 && count > 1) {
                    spawnProjectileSpread(
                        4, 0, enemy.x, fireY, aimed16,
                        0.0f, speed + 1.4, 1, count - 1,
                        (17000 / (count - 1)) * (count - 2), 0);
                }
            }
        }
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
                enemy.secondaryAngle16 = aimFrom(enemy.x, enemy.y);
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
                    3, 7, enemy.x, enemy.y, angle, 10.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)], 1,
                    kCount[static_cast<std::size_t>(difficulty)], 30000, 0);
            };
            fireSweep(rootLocal % (cadence * 2), 1);
            fireSweep((activeAge - (cadence + 90)) % (cadence * 2), -1);
        }
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
            const float fireX = enemy.x +
                static_cast<float>(std::cos(radians) * 30.0);
            const float fireY = enemy.y +
                static_cast<float>(std::sin(radians) * 30.0);
            const float horizontalOrigin = player_.x / 6.0f;
            if (fireX < horizontalOrigin - 30.0f ||
                fireX > horizontalOrigin + 630.0f ||
                fireY < -30.0f || fireY > 750.0f) {
                return;
            }
            const auto snapped = normalizeAngle16(
                (static_cast<int>(enemy.sourceAngle16) + 0x400) & ~0x7ff);
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(0, 0, fireX, fireY, snapped,
                                0.0f, speed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(0, 0, fireX, fireY, snapped,
                                    0.0f, speed - 1.8, 1, 0);
            }
        }
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
        if (activeAge >= start && (activeAge - start) % cadence == 0) {
            spawnStageEffect(
                0x31, frameHandle(effectMediumFrames_, 4), 200, 0x23,
                0.0f, 0.0f, 0, 0.0, 5.0, 5.0, 40,
                0xff, 0xff, 0xff, 0xc0, enemy.entityId);
            playPlayerSound(bossSe2SecondSoundHandle_, 0x13);
        }
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
            playPlayerSound(bullet2SoundHandle_, 0x13);
        }
        return;
    }

    if (enemy.spawnType == 0x4f) {
        const int cadence = std::array<int, 5>{{2, 1, 1, 1, 1}}[
            static_cast<std::size_t>(difficulty)];
        const int count = difficulty < 2 ? 1 : 2;
        const int angleStep = std::array<int, 5>{{0x578, 0x9c4, 0x898, 0x898, 0x898}}[
            static_cast<std::size_t>(difficulty)];
        const double speed = lateEnemyProjectileSpeed(
            difficulty, std::array<double, 5>{{4.5, 5.5, 6.0, 6.0, 8.0}});
        if (activeAge >= 20 && activeAge < 120 &&
            (activeAge - 20) % cadence == 0) {
            const int angle = (activeAge - 20) * angleStep - 0x4000;
            const auto angle16 = normalizeAngle16(angle);
            const float sourceRadius = static_cast<float>(activeAge - 20) * 1.5f;
            const double radians = fixedAngleRadians(angle16);
            const float fireX = enemy.x + static_cast<float>(
                std::cos(radians) * sourceRadius);
            const float fireY = enemy.y + static_cast<float>(
                std::sin(radians) * sourceRadius);
            spawnProjectileSpread(10, 2, fireX, fireY, angle16,
                                  10.0f, speed, 1, count,
                                  count * 7000 - 7000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(10, 2, fireX, fireY, angle16,
                                      10.0f, speed + 1.5, 1, count,
                                      count * 12000 - 12000, 0);
            }
        }
        if (activeAge >= 120 && activeAge < 220 &&
            (activeAge - 120) % cadence == 0) {
            const int angle = (100 - activeAge) * angleStep + 0x4000;
            const auto angle16 = normalizeAngle16(angle);
            const float sourceRadius = static_cast<float>(activeAge - 120) * 1.5f;
            const double radians = fixedAngleRadians(angle16);
            const float fireX = enemy.x + static_cast<float>(
                std::cos(radians) * sourceRadius);
            const float fireY = enemy.y + static_cast<float>(
                std::sin(radians) * sourceRadius);
            spawnProjectileSpread(11, 2, fireX, fireY, angle16,
                                  10.0f, speed, 1, count,
                                  count * 7000 - 7000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(11, 2, fireX, fireY, angle16,
                                      10.0f, speed + 1.0, 1, count,
                                      count * 12000 - 12000, 0);
            }
        }
        const int lateCadence = std::array<int, 5>{{0x5f, 0x36, 0x2d, 0x2d, 0x23}}[
            static_cast<std::size_t>(difficulty)];
        if (activeAge >= 480 && (activeAge - 480) % lateCadence == 0) {
            const float fireX = enemy.x + 65.0f;
            const float fireY = enemy.y + 40.0f;
            const auto aimed16 = aimFrom(enemy.x, -1200.0f);
            spawnProjectileNode(3, 0x1c, fireX, fireY,
                                normalizeAngle16(static_cast<int>(aimed16) - 0x4000),
                                0.0f, 12.0, 1, 0);
            spawnProjectileNode(3, 0x1c, fireX, fireY,
                                normalizeAngle16(static_cast<int>(aimed16) - 0xc000),
                                0.0f, 12.0, 1, 0);
        }
        return;
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
    child.rewardWeight = kind;
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
            if (parent->hp < 1) {
                spawnEnemyDeathEffects(enemy, 1);
            }
            release();
            return;
        }

        const int timer = enemy.helperTimer;
        if (timer == 0) {
            enemy.x = parent->x + 5.0f;
            enemy.y = parent->y + 30.0f;
        }
        const float targetX = parent->x + static_cast<float>(
            std::sin(static_cast<double>(timer) * kTau / 277.0) * 200.0);
        const float targetY = parent->y + static_cast<float>(
            std::sin(static_cast<double>(timer) * kTau / 413.0) * -90.0 -
            std::sin(static_cast<double>(timer) * kTau / 688.0) * 60.0);
        enemy.x += (targetX - enemy.x) / 30.0f;
        enemy.y += (targetY - enemy.y) / 30.0f;

        if (enemy.helperState == 0) {
            enemy.targetable = false;
            if (timer != 0xac) {
                return;
            }
            enemy.helperState = 1;
            enemy.hp = parent->hp;
            enemy.maxHp = parent->maxHp;
            enemy.drawHp = parent->drawHp;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }

        syncSharedHp();
        enemy.targetable = true;
        const int local = (timer - 0xac) % 700;
        static constexpr std::array<int, 5> kAimInterval{{83, 51, 33, 45, 33}};
        static constexpr std::array<int, 5> kFireInterval{{10, 6, 3, 4, 3}};
        static constexpr std::array<double, 5> kSweepSpeed{{3.6, 4.5, 5.0, 4.0, 6.0}};
        const int aimInterval = kAimInterval[static_cast<std::size_t>(difficulty)];
        const int fireInterval = kFireInterval[static_cast<std::size_t>(difficulty)];
        const int sweepLocal = local - 0x78;
        if (local >= 0x78 && local < 0x1e0 &&
            sweepLocal % aimInterval == 0) {
            enemy.secondaryAngle16 = aimAtPlayer16();
        }
        if (local >= 0x78 && local < 0x1e0 &&
            sweepLocal % fireInterval == 0) {
            const int phase = sweepLocal % (aimInterval * 2);
            const int triangle = phase < aimInterval
                                     ? phase
                                     : aimInterval * 2 - phase;
            const int sweep = triangle * (0x8000 / aimInterval) - 0x4190;
            const auto center = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) + sweep);
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

        if (local == 0x1cc || local == 0x230) {
            spawnStageEffect(
                0x31, frameHandle(effectMediumFrames_, 4), 200, 0x23,
                0.0f, 0.0f, 0, 0.0, 5.0, 5.0, 40,
                0xff, 0xff, 0xff, 0xc0, enemy.entityId);
            playPlayerSound(bossSe2SecondSoundHandle_, 0x13);
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
            if (parent->hp < 1) {
                spawnEnemyDeathEffects(enemy, 0);
            }
            release();
            return;
        }
        const int timer = enemy.helperTimer;
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed) +
                   static_cast<float>(timer) * 0.15f;
        enemy.targetable = timer >= 50;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            static constexpr std::array<double, 5> kSpeed{{
                3.6, 4.5, 5.0, 5.0, 6.4,
            }};
            const float dx = player_.x - enemy.x;
            const float dy = player_.y - enemy.y;
            const float minimumDistance = static_cast<float>(enemy.radius + 30);
            if (dx * dx + dy * dy >= minimumDistance * minimumDistance &&
                enemy.y < 520.0f && enemy.y < player_.y) {
                const auto snapped = normalizeAngle16(
                    (static_cast<int>(aimAtPlayer16()) + 0x400) & ~0x7ff);
                spawnProjectileNode(
                    0, 0, enemy.x, enemy.y, snapped, 10.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)],
                    1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(
                        0, 0, enemy.x, enemy.y, snapped, 10.0f,
                        kSpeed[static_cast<std::size_t>(difficulty)] + 1.5,
                        1, 0);
                }
            }
            spawnEnemyDeathRewardBurst(enemy, 200, false);
            spawnEnemyDeathEffects(enemy, 0);
            release();
            return;
        }
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.x < horizontalOrigin - 180.0f ||
            enemy.x > horizontalOrigin + 780.0f ||
            enemy.y < -180.0f || enemy.y > 900.0f) {
            release();
        }
        return;
    }

    if (parent->helperState < 11 || parent->helperState > 13 ||
        lateStageBossPhaseMode_ != 1) {
        if (parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 1);
        }
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
        if (enemy.helperState == 0) {
            return;
        }
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
    if (local == 0 || local == 0x17c) {
        spawnStageEffect(
            0x31, frameHandle(effectMediumFrames_, 4), 200, 0x23,
            0.0f, 0.0f, 0, 0.0, 5.0, 5.0, 40,
            0xff, 0xff, 0xff, 0xc0, enemy.entityId);
        playPlayerSound(bossSe2SecondSoundHandle_, 0x13);
    }
    if (local >= 40 && local < 200 &&
        (local - 40) % aimInterval == 0) {
        enemy.secondaryAngle16 = aimAtPlayer16();
    }
    if (local >= 40 && local < 200 && (local - 40) % sweepStep == 0) {
        const int phase = (local - 40) % (aimInterval * 2);
        const int triangle = phase < aimInterval
                                 ? phase
                                 : aimInterval * 2 - phase;
        int sweep = triangle * (28000 / aimInterval) - 14000;
        if (enemy.originX < 0.0f) sweep = -sweep;
        spawnProjectileNode(
            0x11, 0x0d, enemy.x, enemy.y + 10.0f,
            normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + sweep),
            10.0f, kSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
        playPlayerSound(bossSe7SoundHandle_, 0x10);
    }
    const int randomStep = kRandomStep[static_cast<std::size_t>(difficulty)];
    if (local >= 0xd2 && local < 0x154 &&
        (local - 0xd2) % randomStep == 0) {
        const std::uint32_t random = lateStageScriptRand(
            enemy.helperTimer + enemy.childIndex);
        const int jitter = static_cast<int>(random % 28001u) - 14000;
        spawnProjectileNode(
            0x11, 0x0d, enemy.x, enemy.y + 10.0f,
            normalizeAngle16(static_cast<int>(aimAtPlayer16()) + jitter),
            10.0f, kSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
        playPlayerSound(bossSe7SoundHandle_, 0x10);
    }
    if (local == 0x1b8) {
        enemy.secondaryAngle16 = radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - parent->y),
            static_cast<double>(player_.x - parent->x)));
        if (enemy.secondaryAngle16 > 0x8000) {
            enemy.secondaryAngle16 = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) + 0x8000);
        }
        enemy.targetAngle16 = enemy.secondaryAngle16;
    }
    if (local >= 0x1cc && local <= 0x230) {
        int delta = 0x4000 - static_cast<int>(enemy.secondaryAngle16);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        enemy.secondaryAngle16 = approachAngle16(
            enemy.secondaryAngle16, 0x4000, std::abs(delta) / 120);
    }
    if (local >= 0x230 && local < 0x4a6) {
        static constexpr std::array<int, 5> kTurnInterval{{
            160, 135, 80, 60, 40,
        }};
        static constexpr std::array<int, 5> kTurnWindow{{
            90, 75, 60, 60, 40,
        }};
        static constexpr std::array<int, 5> kTurnBase{{
            40, 60, 100, 120, 180,
        }};
        static constexpr std::array<int, 5> kTurnGrowth{{
            12, 15, 10, 5, 3,
        }};
        const int interval = kTurnInterval[static_cast<std::size_t>(difficulty)];
        const int window = kTurnWindow[static_cast<std::size_t>(difficulty)];
        const int offset = local - 0x230;
        const int phase = offset % (interval * 4);
        int turn = kTurnBase[static_cast<std::size_t>(difficulty)] +
                   (offset / interval) *
                       kTurnGrowth[static_cast<std::size_t>(difficulty)];
        if (enemy.targetAngle16 > 0x4000) {
            turn = -turn;
        }
        if (phase < window ||
            (phase >= interval * 3 && phase < interval * 3 + window)) {
            enemy.secondaryAngle16 = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) + turn);
        }
        else if ((phase >= interval && phase < interval + window) ||
                 (phase >= interval * 2 &&
                  phase < interval * 2 + window)) {
            enemy.secondaryAngle16 = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) - turn);
        }
    }
    if (local >= 0x1b8 && local < 0x4a6 &&
        (local - 0x1b8) % 3 == 0) {
        const int spread = local < 500 ? (0x221 - local) * 600 : 27000;
        std::uint16_t shotAngle = enemy.secondaryAngle16;
        const auto parentAim = radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - parent->y),
            static_cast<double>(player_.x - parent->x)));
        int delta = static_cast<int>(parentAim) -
                    static_cast<int>(shotAngle);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        if (std::abs(delta) > 0x4000) {
            shotAngle = normalizeAngle16(static_cast<int>(shotAngle) -
                                         0x8000);
        }
        spawnProjectileSpread(
            6, 0, enemy.x, enemy.y + 10.0f, shotAngle,
            10.0f, 14.0, 1, 5, std::max(27000, spread), 0);
        playPlayerSound(bullet1SoundHandle_, 0x10);
    }
}

void StageRuntime::emitStage05BossProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    const auto aimFrom = [this](float x, float y) {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto modulo = [](int value, int divisor) {
        const int result = value % divisor;
        return result < 0 ? result + divisor : result;
    };

    if (enemy.helperState == 1) {
        static constexpr std::array<std::array<float, 2>, 3> kSources{{
            {{-95.0f, 80.0f}}, {{90.0f, 35.0f}}, {{-2.0f, -110.0f}},
        }};
        static constexpr std::array<int, 5> kRingCount{{7, 11, 17, 15, 17}};
        static constexpr std::array<int, 5> kRingStep{{330, 370, 400, 400, 560}};
        static constexpr std::array<double, 5> kRingSpeed{{5.7, 7.0, 7.5, 8.0, 9.5}};
        static constexpr std::array<int, 5> kFanInterval{{21, 14, 12, 11, 10}};
        static constexpr std::array<int, 5> kFanCount{{3, 5, 7, 5, 7}};
        static constexpr std::array<double, 5> kFanSpeed{{6.0, 7.4, 8.5, 8.5, 10.0}};
        const int cycle = modulo(timer - 30, 690);
        for (int source = 0; source < 3; ++source) {
            const float x = enemy.x + kSources[static_cast<std::size_t>(source)][0];
            const float y = enemy.y + kSources[static_cast<std::size_t>(source)][1];
            const int ringStart = source * 40;
            if (cycle >= ringStart && cycle < ringStart + 36 &&
                (cycle - ringStart) % 4 == 0) {
                int step = kRingStep[static_cast<std::size_t>(difficulty)] +
                           source * 30;
                if (source == 1) step = -step;
                if (source == 0 && cycle == 0) {
                    enemy.secondaryAngle16 = aimFrom(x, y);
                }
                const auto center = enemy.secondaryAngle16;
                const int count = kRingCount[static_cast<std::size_t>(difficulty)];
                const double speed =
                    kRingSpeed[static_cast<std::size_t>(difficulty)] +
                    static_cast<double>(cycle - ringStart) * 0.03 +
                    source * 0.8;
                spawnProjectileSpread(3, 0, x, y, center, 10.0f, speed,
                                      1, count, 0x10000, 0);
                if (difficulty > 2) {
                    const int offset = 0x10000 / (count * 2) - step;
                    spawnProjectileSpread(
                        5, 0, x, y,
                        normalizeAngle16(static_cast<int>(center) + offset),
                        10.0f, speed - 1.5, 1, count, 0x10000, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x13);
                enemy.secondaryAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.secondaryAngle16) + step);
            }

            const int fanStart = (source + 1) * 160;
            const int interval = kFanInterval[static_cast<std::size_t>(difficulty)];
            if (cycle >= fanStart && cycle < fanStart + 180 &&
                (cycle - fanStart) % interval == 0) {
                const int count = kFanCount[static_cast<std::size_t>(difficulty)];
                const int spread = std::max(0, 27000 -
                    (cycle - fanStart) * 0x91);
                const double speed =
                    kFanSpeed[static_cast<std::size_t>(difficulty)] + source;
                std::uint16_t& cachedAim = (source & 1) == 0
                                               ? enemy.secondaryAngle16
                                               : enemy.targetAngle16;
                if (cycle == fanStart) {
                    cachedAim = aimFrom(x, y);
                }
                spawnProjectileSpread(0x0d, 0, x, y, cachedAim, 0.0f,
                                      speed, 1, count,
                                      spread, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(0x0d, 0, x, y, cachedAim, 0.0f,
                                          speed - 2.0, 1, count,
                                          spread + 2000, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }
        return;
    }

    if (enemy.helperState == 3) {
        static constexpr std::array<std::array<float, 2>, 4> kSources{{
            {{60.0f, 90.0f}}, {{-67.0f, -60.0f}},
            {{153.0f, 5.0f}}, {{-153.0f, 0.0f}},
        }};
        static constexpr std::array<int, 5> kFanInterval{{41, 27, 19, 15, 12}};
        static constexpr std::array<int, 5> kSpreadUnit{{6000, 4000, 3300, 3000, 2700}};
        static constexpr std::array<double, 5> kFanSpeed{{4.4, 5.7, 6.2, 7.0, 9.0}};
        static constexpr std::array<double, 5> kPairSpeed{{5.0, 6.0, 7.0, 8.0, 9.0}};

        if (timer >= 240) {
            const int cycle = modulo(timer - 240, 510);
            for (int source = 0; source < 2; ++source) {
                const int start = source * 210;
                const int interval = kFanInterval[static_cast<std::size_t>(difficulty)];
                if (cycle < start || cycle >= start + 210 ||
                    (cycle - start) % interval != 0) {
                    continue;
                }
                const float x = enemy.x + kSources[static_cast<std::size_t>(source)][0];
                const float y = enemy.y + kSources[static_cast<std::size_t>(source)][1];
                const int shot = (cycle - start) / interval;
                std::uint16_t& cachedAim = source == 0
                                               ? enemy.secondaryAngle16
                                               : enemy.targetAngle16;
                if (cycle == start) {
                    cachedAim = aimFrom(x, y);
                }
                spawnProjectileSpread(
                    3, 0, x, y, cachedAim, 10.0f,
                    kFanSpeed[static_cast<std::size_t>(difficulty)],
                    1, shot + 1,
                    shot * kSpreadUnit[static_cast<std::size_t>(difficulty)],
                    0);
                cachedAim = approachAngle16(cachedAim, aimFrom(x, y), 0x1bc);
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }

        if (timer >= 10) {
            const int cycle = modulo(timer - 10, 240);
            for (int source = 2; source < 4; ++source) {
                const int offset = (source - 1) * 60;
                const float x = enemy.x + kSources[static_cast<std::size_t>(source)][0];
                const float y = enemy.y + kSources[static_cast<std::size_t>(source)][1];
                const auto axis = static_cast<std::uint16_t>(source == 2 ? 0 : 0x8000);
                if (cycle == offset - 60) {
                    playPlayerSound(bossSe2SecondSoundHandle_, 0x13);
                }
                if (cycle == offset - 20) {
                    spawnProjectileNode(
                        0x11, 0x0c, x, y, axis, 0.0f,
                        kPairSpeed[static_cast<std::size_t>(difficulty)],
                        1, 0);
                    playPlayerSound(bullet2SoundHandle_, 0x13);
                }
                if (difficulty > 2 && cycle == offset) {
                    spawnProjectileNode(
                        0x11, 0x0c, x, y,
                        normalizeAngle16(static_cast<int>(axis) - 0x0d05),
                        0.0f,
                        kPairSpeed[static_cast<std::size_t>(difficulty)],
                        1, 0);
                    spawnProjectileNode(
                        0x11, 0x0c, x, y,
                        normalizeAngle16(static_cast<int>(axis) + 0x0d05),
                        0.0f,
                        kPairSpeed[static_cast<std::size_t>(difficulty)],
                        1, 0);
                    playPlayerSound(bullet2SoundHandle_, 0x13);
                }
            }
        }
        return;
    }

    if (enemy.helperState == 5) {
        static constexpr std::array<std::array<float, 2>, 4> kSources{{
            {{90.0f, 30.0f}}, {{-95.0f, 30.0f}},
            {{-2.0f, 100.0f}}, {{-2.0f, -55.0f}},
        }};
        static constexpr std::array<int, 5> kRingInterval{{22, 16, 12, 13, 11}};
        static constexpr std::array<int, 5> kRingCount{{5, 7, 8, 8, 9}};
        static constexpr std::array<int, 5> kRotationStep{{40, 40, 50, 50, 50}};
        static constexpr std::array<double, 5> kRingSpeed{{5.2, 6.5, 7.7, 7.0, 8.5}};
        static constexpr std::array<int, 5> kPairInterval{{70, 45, 36, 36, 36}};
        static constexpr std::array<int, 5> kNarrowCount{{3, 5, 7, 7, 9}};
        static constexpr std::array<int, 5> kWideCount{{8, 12, 16, 18, 20}};
        static constexpr std::array<double, 5> kPairSpeed{{4.0, 5.3, 6.0, 6.0, 7.5}};

        for (int source = 0; source < 2; ++source) {
            const int interval = kRingInterval[static_cast<std::size_t>(difficulty)];
            if (timer < 30 || (timer - 30) % interval != 0) continue;
            const float x = enemy.x + kSources[static_cast<std::size_t>(source)][0];
            const float y = enemy.y + kSources[static_cast<std::size_t>(source)][1];
            int rotation = timer * kRotationStep[static_cast<std::size_t>(difficulty)];
            if (source == 1) rotation = -rotation;
            const auto center = normalizeAngle16(0x4000 + rotation);
            const int count = kRingCount[static_cast<std::size_t>(difficulty)];
            const double speed = kRingSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(0x0d, 0, x, y, center, 0.0f,
                                  speed, 1, count, 0x10000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(0x0d, 0, x, y, center, 0.0f,
                                      speed + 2.0, 1, count, 0x10000, 0);
            }
            playPlayerSound(bullet1SoundHandle_, 0x10);
        }

        if (timer >= 120) {
            const int interval = kPairInterval[static_cast<std::size_t>(difficulty)];
            const float x0 = enemy.x + kSources[2][0];
            const float y0 = enemy.y + kSources[2][1];
            if ((timer - 120) % (interval * 3) == 0) {
                const int count = kNarrowCount[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(
                    2, 0, x0, y0, aimFrom(x0, y0), 10.0f,
                    kPairSpeed[static_cast<std::size_t>(difficulty)],
                    1, count, count * 700 - 700, 0);
                playPlayerSound(bullet2SoundHandle_, 0x13);
            }
            const float x1 = enemy.x + kSources[3][0];
            const float y1 = enemy.y + kSources[3][1];
            if (timer >= 120 + interval &&
                (timer - (120 + interval)) % (interval * 3) == 0) {
                spawnProjectileSpread(
                    2, 0, x1, y1, aimFrom(x1, y1), 10.0f,
                    kPairSpeed[static_cast<std::size_t>(difficulty)] + 1.0,
                    1, kWideCount[static_cast<std::size_t>(difficulty)],
                    0x8000, 0);
                playPlayerSound(bullet2SoundHandle_, 0x13);
            }
        }
        return;
    }

    if (enemy.helperState != 7) return;
    static constexpr std::array<std::array<float, 2>, 6> kSources{{
        {{90.0f, -20.0f}}, {{-95.0f, -20.0f}},
        {{156.0f, 50.0f}}, {{-156.0f, 50.0f}},
        {{156.0f, -100.0f}}, {{-156.0f, -100.0f}},
    }};
    static constexpr std::array<int, 5> kRingInterval{{19, 15, 16, 16, 16}};
    static constexpr std::array<int, 5> kRingWindow{{8, 8, 10, 10, 10}};
    static constexpr std::array<int, 5> kRingCount{{2, 3, 4, 6, 8}};
    static constexpr std::array<double, 5> kRingSpeed{{4.5, 5.5, 6.0, 7.2, 8.6}};
    static constexpr std::array<int, 5> kArcInterval{{68, 51, 44, 39, 33}};
    static constexpr std::array<int, 5> kArcWindow{{14, 20, 24, 24, 24}};
    static constexpr std::array<double, 5> kArcSpeed{{7.2, 8.5, 9.5, 10.0, 11.0}};
    const int cycle = modulo(timer - 30, 880);
    for (int source = 0; source < 2; ++source) {
        const float x = enemy.x + kSources[static_cast<std::size_t>(source)][0];
        const float y = enemy.y + kSources[static_cast<std::size_t>(source)][1];
        if (cycle < 421) {
            const int interval = kRingInterval[static_cast<std::size_t>(difficulty)];
            const int local = cycle % interval;
            if (local < kRingWindow[static_cast<std::size_t>(difficulty)] &&
                (local & 1) == 0) {
                const int sweepPhase = (cycle + 50) % 480;
                int sweep = 0;
                if (source == 0) {
                    sweep = sweepPhase <= 0xef
                                ? sweepPhase * 0xf8
                                : -sweepPhase * 0xf8 - 0x2f00;
                }
                else {
                    sweep = sweepPhase <= 0xef
                                ? -sweepPhase * 0xf8 - 0x8000
                                : sweepPhase * 0xf8 - 0x5100;
                }
                spawnProjectileSpread(
                    3, 0, x, y, normalizeAngle16(sweep), 0.0f,
                    kRingSpeed[static_cast<std::size_t>(difficulty)],
                    1, kRingCount[static_cast<std::size_t>(difficulty)],
                    0x10000, 0);
                playPlayerSound(bullet1SoundHandle_, 0x10);
            }
        }
        if (cycle >= 0x244 && cycle < 0x32a) {
            const int interval = kArcInterval[static_cast<std::size_t>(difficulty)];
            const int local = (cycle - 0x244) % interval;
            std::uint16_t& cachedAim = source == 0
                                           ? enemy.secondaryAngle16
                                           : enemy.targetAngle16;
            if (local == 0) {
                cachedAim = aimFrom(x, y);
            }
            if (local < kArcWindow[static_cast<std::size_t>(difficulty)] &&
                local % 3 == 0) {
                spawnProjectileNode(
                    7, 0, x, y, cachedAim, 10.0f,
                    kArcSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(
                        7, 0, x, y,
                        normalizeAngle16(static_cast<int>(cachedAim) - 0x2a3),
                        10.0f,
                        kArcSpeed[static_cast<std::size_t>(difficulty)] - 0.7,
                        1, 0);
                    spawnProjectileNode(
                        7, 0, x, y,
                        normalizeAngle16(static_cast<int>(cachedAim) + 0x2a3),
                        10.0f,
                        kArcSpeed[static_cast<std::size_t>(difficulty)] - 0.7,
                        1, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }
    }

    static constexpr std::array<int, 5> kPairInterval{{71, 43, 31, 27, 24}};
    static constexpr std::array<double, 5> kPairSpeed{{5.0, 6.0, 7.0, 8.0, 9.0}};
    const int pairInterval = kPairInterval[static_cast<std::size_t>(difficulty)];
    for (int source = 2; source < 6; ++source) {
        const int sourceOffset = (source - 2) * pairInterval;
        const float x = enemy.x + kSources[static_cast<std::size_t>(source)][0];
        const float y = enemy.y + kSources[static_cast<std::size_t>(source)][1];
        const int effectStart = 0x1b8 + sourceOffset;
        if (cycle >= effectStart && cycle < 800 &&
            (cycle - effectStart) % (pairInterval * 4) == 0) {
            playPlayerSound(bossSe2SecondSoundHandle_, 0x13);
        }
        const int shotStart = 0x1e0 + sourceOffset;
        if (cycle >= shotStart && cycle < 0x348 &&
            (cycle - shotStart) % (pairInterval * 4) == 0) {
            const auto axis = static_cast<std::uint16_t>(source << 15);
            spawnProjectileNode(
                0x11, 0x0c, x, y, axis, 0.0f,
                kPairSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
            playPlayerSound(bullet2SoundHandle_, 0x13);
        }
    }
}

void StageRuntime::updateStage05Boss(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto oldTarget = radiansToAngle16(std::atan2(
        static_cast<double>(lateStageBossTargetY_ - enemy.y),
        static_cast<double>(lateStageBossTargetX_ - enemy.x)));
    if (frame_ % 50 == 0) {
        lateStageBossTargetX_ = 210.0f + static_cast<float>(
            lateBossFrameRand(frame_) % 301u);
        lateStageBossTargetY_ = 150.0f + static_cast<float>(
            lateBossFrameRand(selectedStage_ * 111 + frame_) % 101u);
    }

    if (lateStageBossPhaseMode_ == 1 &&
        (enemy.hp < 1 || lateStageBossCountdown_ < 1)) {
        const bool countdownExpired = lateStageBossCountdown_ < 1;
        if (countdownExpired) {
            flushEnemyProjectilesToEffects();
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 100);
        }
        else {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
        }
        spawnBossPhaseBreakFeedback(enemy, lateStageBossCountdown_);
        spawnPostDeathCounterEntity(enemy, 140.0);
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        enemy.helperTimer = 0;
        enemy.liveChildCount = 0;
        enemy.radius = 200;
        switch (lateStageBossBreaksRemaining_) {
        case 6: enemy.helperState = 2; lateStageBossPhaseMode_ = 2; break;
        case 5: enemy.helperState = 4; lateStageBossPhaseMode_ = 2; break;
        case 4: enemy.helperState = 6; lateStageBossPhaseMode_ = 2; break;
        case 3: enemy.helperState = 8; lateStageBossPhaseMode_ = 2; break;
        case 2: enemy.helperState = 10; lateStageBossPhaseMode_ = 2; break;
        case 1:
            enemy.helperState = 14;
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
        ++lateStageBossPhaseIndex_;
    }

    const auto steerAndMove = [&enemy, oldTarget](double speed) {
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, oldTarget, 0x200);
        enemy.angle = static_cast<float>(fixedAngleRadians(enemy.sourceAngle16));
        enemy.sourceSpeed = speed;
        enemy.speed = static_cast<float>(speed);
        enemy.x += static_cast<float>(std::cos(enemy.angle) * speed);
        enemy.y += static_cast<float>(std::sin(enemy.angle) * speed);
    };
    const auto openPhase = [this, &enemy](int state, int hitPoints,
                                          int countdown, double speed,
                                          int radius, int phaseIndex) {
        enemy.helperState = state;
        enemy.helperTimer = 0;
        enemy.hp = hitPoints;
        enemy.maxHp = hitPoints;
        enemy.drawHp = hitPoints;
        enemy.sourceSpeed = speed;
        enemy.speed = static_cast<float>(speed);
        enemy.radius = radius;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        lateStageBossMaxHp_ = hitPoints;
        lateStageBossCountdown_ = countdown;
        lateStageBossCountdownDraw_ = countdown;
        lateStageBossPhaseIndex_ = phaseIndex;
        lateStageBossPhaseMode_ = 1;
    };

    const int timer = enemy.helperTimer;
    switch (enemy.helperState) {
    case 0: {
        if (timer == 0) {
            playPlayerSound(bossSe9SoundHandle_, 0x19);
        }
        if (timer <= 200) {
            const double entrance = std::sin(
                static_cast<double>(timer) * kPi / 400.0);
            enemy.y = 2800.0f + static_cast<float>(
                entrance * static_cast<double>(enemy.originY - 2800.0f));
        }
        else {
            enemy.y += 0.1f;
        }
        enemy.targetable = false;
        if (timer == 240) {
            openPhase(1, 60000, 1500, 0.3, 175, 0);
        }
        break;
    }
    case 1:
    case 3:
    case 5:
    case 7:
        steerAndMove(0.3);
        emitStage05BossProjectiles(enemy);
        break;
    case 2:
    case 4:
    case 6:
        enemy.targetable = false;
        if (timer == 1) {
            spawnStageEffect(0x36, -1, 0, 0x28,
                             enemy.x, enemy.y, 0,
                             0.0, 1.0, 1.0, 0,
                             0xff, 0xff, 0xff, 0xff);
        }
        if (timer < 90) {
            spawnStage02DeathExplosionChain(enemy);
            enemy.y += static_cast<float>(timer) * 0.09f;
        }
        else {
            steerAndMove(0.3);
        }
        if (timer == 90) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnStageEffect(0x11, -1, 0, 0x28,
                             enemy.x, enemy.y, 0,
                             0.0, 1.0, 1.0, 0,
                             0xff, 0xff, 0xff, 0xff);
        }
        if (timer == 100) {
            enemy.y -= 444.0f;
        }
        if (timer >= 100 && timer < 180) {
            enemy.y -= static_cast<float>(
                1.0 - std::sin(static_cast<double>(timer - 100) *
                               kPi / 280.0));
        }
        if (timer == 180) {
            if (enemy.helperState == 2) {
                openPhase(3, 55000, 1500, 0.3, 175, 1);
            }
            else if (enemy.helperState == 4) {
                openPhase(5, 55000, 1500, 0.3, 175, 2);
            }
            else {
                openPhase(7, 70000, 1800, 0.3, 175, 3);
            }
        }
        break;
    case 8:
        enemy.targetable = false;
        if (timer < 120) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer < 120) {
            enemy.y += static_cast<float>(timer) * 0.02f;
        }
        else if (timer >= 130) {
            steerAndMove(0.3);
        }
        if (timer == 120) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnStageEffect(0x11, -1, 0, 0x28,
                             enemy.x, enemy.y, 0,
                             0.0, 1.0, 1.0, 0,
                             0xff, 0xff, 0xff, 0xff);
        }
        if (timer == 130) {
            enemy.y -= 40.0f;
        }
        if (timer == 210) {
            spawnStage05BossChild(
                enemy, 0x54, 0.0f, 0.0f, 0x4000, 1.0, 40,
                99999999, 0,
                "S05 FUN_14001c8b0 state 8 timer 210 child 0x54");
        }
        if (timer == 380) {
            openPhase(9, 45000, 1800, 0.3, 80, 4);
        }
        break;
    case 9: {
        steerAndMove(0.3);
        static constexpr std::array<int, 5> kInterval{{60, 40, 36, 36, 30}};
        static constexpr std::array<std::uint16_t, 6> kAngles{{
            0xc4b0, 0xc960, 0xce10, 0xbb50, 0xb6a0, 0xb1f0,
        }};
        if (timer >= 10) {
            const int local = (timer - 10) % 700;
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            if (local < 360 && local % interval == 0) {
                for (std::uint16_t angle : kAngles) {
                    spawnStage05BossChild(
                        enemy, 0x55, 0.0f, -20.0f, angle, 6.0, 25,
                        10, 2,
                        "S05 FUN_14001c8b0 state 9 child 0x55");
                }
                playPlayerSound(bullet2SoundHandle_, 0x13);
            }
        }
        break;
    }
    case 10:
        enemy.targetable = false;
        enemy.y += 0.1f;
        if (timer == 1) {
            playPlayerSound(enemyDown3SoundHandle_, 0x19);
            spawnStageEffect(0x36, -1, 0, 0x28,
                             enemy.x, enemy.y, 0,
                             0.0, 1.0, 1.0, 0,
                             0xff, 0xff, 0xff, 0xff);
        }
        if (timer < 90) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 180) {
            openPhase(11, 80000, 2100, 0.3, 200, 5);
        }
        break;
    case 11:
        steerAndMove(0.3);
        if (timer == 60) {
            spawnStage05BossChild(
                enemy, 0x56, 90.0f, -30.0f, 0x4000, 1.0, 40,
                99999999, 1,
                "S05 FUN_14001c8b0 state 11 timer 60 right 0x56");
            spawnStage05BossChild(
                enemy, 0x56, -90.0f, -30.0f, 0x4000, 1.0, 40,
                99999999, 1,
                "S05 FUN_14001c8b0 state 11 timer 60 left 0x56");
            playPlayerSound(bossSe1SoundHandle_, 0x19);
        }
        if (timer == 450) {
            enemy.originX = enemy.x;
            enemy.originY = enemy.y;
            enemy.helperState = 12;
            enemy.helperTimer = 0;
        }
        break;
    case 12: {
        if (timer == 1) {
            enemy.originX = enemy.x;
            enemy.originY = enemy.y;
            enemy.markerDrawX = std::clamp(player_.x, 210.0f, 510.0f);
            enemy.markerDrawY = std::clamp(player_.y - 320.0f,
                                           200.0f, 350.0f);
        }
        const double t = std::sin(
            static_cast<double>(std::clamp(timer, 0, 60)) * kPi / 120.0);
        enemy.x = enemy.originX + static_cast<float>(
            (enemy.markerDrawX - enemy.originX) * t);
        enemy.y = enemy.originY + static_cast<float>(
            (enemy.markerDrawY - enemy.originY) * t);
        if (timer == 60) {
            enemy.helperState = 13;
            enemy.helperTimer = 0;
            enemy.sourceSpeed = 0.1;
            enemy.speed = 0.1f;
        }
        break;
    }
    case 13:
        steerAndMove(0.1);
        if (timer >= 40 && timer < 120) {
            enemy.y -= static_cast<float>(
                std::sin(static_cast<double>(timer - 40) * kPi / 80.0) *
                2.4);
        }
        if (timer == 780) {
            enemy.helperState = 11;
            enemy.helperTimer = 90;
            enemy.sourceSpeed = 0.3;
            enemy.speed = 0.3f;
        }
        break;
    case 14:
        enemy.targetable = false;
        if (timer < 240) {
            enemy.y += 0.2f;
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 240) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnStageEffect(0x10, -1, 0, 0x28,
                             enemy.x, enemy.y, 0,
                             0.0, 1.0, 1.0, 0,
                             0xff, 0xff, 0xff, 0xff);
        }
        if (timer >= 480) {
            clearLateStageGate(5);
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
            spawnEnemyDeathRewardBurst(enemy, 3000, false);
            spawnEnemyDeathEffects(enemy, 1);
            if (parent != nullptr && enemy.spawnType >= 0x66 &&
                enemy.spawnType <= 0x6a) {
                spawnDelayedOwnerDamageNode(
                    20000, parent->entityId, parent->spawnType,
                    "S06 destructible arm delayed-damage node 0x153");
            }
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

    int timer = enemy.helperTimer;
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

        // FUN_140026b80 keeps both mounts on their own fixed-angle arms.  The
        // 0x64 arm rotates in short windows selected by the root state; 0x65
        // instead offsets its draw point 24 px toward the player.
        if (enemy.spawnType == 0x64) {
            if ((parent->helperState == 1 || parent->helperState == 2) &&
                (timer + 20) % 60 > 39) {
                enemy.sourceAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.sourceAngle16) + 0x111);
            }
            else if (parent->helperState > 2 && timer % 30 > 19) {
                enemy.sourceAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.sourceAngle16) + 0x222);
            }
        }
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x = parent->x + static_cast<float>(
            std::cos(radians) * static_cast<double>(enemy.originX));
        enemy.y = parent->y + static_cast<float>(
            std::sin(radians) * static_cast<double>(enemy.originX));
        if (enemy.spawnType == 0x65) {
            const auto playerAngle = aimAtPlayer();
            const double playerRadians = fixedAngleRadians(playerAngle);
            enemy.x += static_cast<float>(std::cos(playerRadians) * 24.0);
            enemy.y += static_cast<float>(std::sin(playerRadians) * 24.0);
        }
        if (parent->helperState == 3 && parent->helperTimer == 30 &&
            enemy.liveChildCount == 0) {
            if (spawnStage06BossNode(enemy,
                                     enemy.spawnType == 0x64 ? 0x6c : 0x6d,
                                     0, 0.0f, 0.0f, 0, 50)) {
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
            timer = 0;
            enemy.hp = 33000;
            enemy.maxHp = 33000;
            enemy.drawHp = 33000;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }

        if (enemy.helperState == 0) {
            if (timer == 0) {
                enemy.originX = 980.0f;
                if (enemy.spawnType == 0x67) enemy.sourceAngle16 = 0xda0a;
                if (enemy.spawnType == 0x6a) enemy.sourceAngle16 = 0xa5f6;
            }
            if (timer >= 0 && timer < 31) {
                enemy.originX -= 40.0f;
            }
            const double introRadians = fixedAngleRadians(enemy.sourceAngle16);
            enemy.x = parent->x + static_cast<float>(
                std::cos(introRadians) * enemy.originX);
            enemy.y = parent->y + static_cast<float>(
                std::sin(introRadians) * enemy.originX);
            return;
        }

        const int brokenArmCount = std::clamp(5 - parent->liveChildCount, 0, 5);
        const int period = std::max(225, (8 - brokenArmCount) * 75);
        const double mountRadians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x = parent->x + static_cast<float>(std::cos(mountRadians) * 180.0);
        enemy.y = parent->y + static_cast<float>(std::sin(mountRadians) * 180.0);
        if (enemy.hp < 1) {
            release(true);
            return;
        }

        if (enemy.spawnType == 0x66 && timer >= 120) {
            static constexpr std::array<int, 5> kShotPeriod{{24, 21, 21, 21, 21}};
            static constexpr std::array<int, 5> kBurstWidth{{9, 15, 18, 21, 24}};
            static constexpr std::array<int, 5> kAngleStep{{200, 160, 140, 130, 130}};
            static constexpr std::array<int, 5> kRingBase{{2, 3, 4, 5, 5}};
            static constexpr std::array<double, 5> kSpeed{{3.2, 4.0, 4.5, 5.0, 6.0}};
            const int local = (timer - 120) % period;
            const int shotPhase = local % kShotPeriod[static_cast<std::size_t>(difficulty)];
            if (local == 0) {
                enemy.secondaryAngle16 = normalizeAngle16(
                    static_cast<int>(aimAtPlayer()) - 0x4000);
            }
            const int turn = kAngleStep[static_cast<std::size_t>(difficulty)];
            enemy.secondaryAngle16 = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) +
                (local > 149 ? -turn : turn));
            int count = kRingBase[static_cast<std::size_t>(difficulty)] +
                        brokenArmCount;
            if (brokenArmCount == 4) --count;
            if (local < 300 &&
                shotPhase < kBurstWidth[static_cast<std::size_t>(difficulty)] &&
                shotPhase % 3 == 0) {
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    shotPhase * 0.15 + brokenArmCount * 0.5;
                spawnProjectileSpread(10, 0, enemy.x, enemy.y,
                                      enemy.secondaryAngle16, 10.0f, speed,
                                      1, count, 0x10000, 0);
                if (brokenArmCount == 4) {
                    spawnProjectileSpread(
                        0x0b, 0, enemy.x, enemy.y,
                        normalizeAngle16(
                            static_cast<int>(enemy.secondaryAngle16) +
                            0x10000 / std::max(1, count * 2)),
                        10.0f, speed, 1, count, 0x10000, 0);
                }
                fired = true;
            }
            enemy.sourceAngle16 = normalizeAngle16(
                static_cast<int>(enemy.sourceAngle16) + 0x42);
        }
        else if (enemy.spawnType == 0x67 && timer >= 240) {
            static constexpr std::array<int, 5> kInterval{{70, 41, 35, 33, 30}};
            static constexpr std::array<int, 5> kCount{{3, 5, 7, 9, 11}};
            static constexpr std::array<int, 5> kSpread{{5000, 3800, 3300, 3000, 2700}};
            static constexpr std::array<double, 5> kSpeed{{3.0, 3.6, 4.0, 4.2, 4.8}};
            const int local = (timer - 240) % period;
            const auto aimed = aimAtPlayer();
            const int wave = static_cast<int>(std::sin(
                timer * 516.0314960629921 * kPi / 32768.0) * 4321.0);
            const auto target = normalizeAngle16(static_cast<int>(aimed) + wave);
            int delta = static_cast<int>(target) -
                        static_cast<int>(enemy.sourceAngle16);
            delta = ((delta + 0x8000) & 0xffff) - 0x8000;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, target, std::abs(delta) / 20 + 0x30);
            const int cadence = std::max(
                1, kInterval[static_cast<std::size_t>(difficulty)] -
                       brokenArmCount * 4);
            if (local < 300 && local % cadence == 0) {
                const double radians = fixedAngleRadians(enemy.sourceAngle16);
                const float fireX = enemy.x +
                    static_cast<float>(std::cos(radians) * 70.0);
                const float fireY = enemy.y +
                    static_cast<float>(std::sin(radians) * 70.0);
                spawnProjectileSpread(
                    3, 0, fireX, fireY, enemy.sourceAngle16, 10.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                        local * 0.006 + brokenArmCount * 0.2,
                    1,
                    kCount[static_cast<std::size_t>(difficulty)] +
                        brokenArmCount * 2,
                    (kCount[static_cast<std::size_t>(difficulty)] +
                         brokenArmCount * 2 - 1) *
                        kSpread[static_cast<std::size_t>(difficulty)],
                    0);
                fired = true;
            }
        }
        else if (enemy.spawnType == 0x68 && timer >= 360) {
            static constexpr std::array<int, 5> kInterval{{16, 10, 8, 8, 7}};
            static constexpr std::array<int, 5> kAngleStep{{130, 170, 190, 200, 240}};
            static constexpr std::array<double, 5> kSpeed{{2.8, 3.5, 3.8, 4.0, 5.0}};
            const int local = (timer - 360) % period;
            const int cadence = std::max(
                1, kInterval[static_cast<std::size_t>(difficulty)] -
                       brokenArmCount);
            if (local < 300 && local % cadence == 0) {
                for (int quadrant = 0; quadrant < 4; ++quadrant) {
                    const auto sourceAngle = normalizeAngle16(
                        static_cast<int>(enemy.sourceAngle16) +
                        quadrant * 0x4000);
                    const double radians = fixedAngleRadians(sourceAngle);
                    const float fireX = enemy.x +
                        static_cast<float>(std::cos(radians) * 55.0);
                    const float fireY = enemy.y +
                        static_cast<float>(std::sin(radians) * 55.0);
                    const auto angle = normalizeAngle16(
                        static_cast<int>(enemy.sourceAngle16) +
                        quadrant * 0x4000 +
                        kAngleStep[static_cast<std::size_t>(difficulty)] * timer);
                    const double speed =
                        kSpeed[static_cast<std::size_t>(difficulty)] +
                        brokenArmCount * 0.4;
                    spawnProjectileNode(7, 0, fireX, fireY, angle,
                                        10.0f, speed, 1, 0);
                    if (difficulty > 2) {
                        spawnProjectileNode(7, 0, fireX, fireY, angle,
                                            10.0f, speed + 1.2, 1, 0);
                    }
                    if (brokenArmCount == 4) {
                        const auto extraAngle = normalizeAngle16(
                            static_cast<int>(angle) + 0x1a04);
                        spawnProjectileNode(7, 0, fireX, fireY, extraAngle,
                                            10.0f, speed, 1, 0);
                        if (difficulty > 2) {
                            spawnProjectileNode(7, 0, fireX, fireY,
                                                extraAngle, 10.0f,
                                                speed + 1.2, 1, 0);
                        }
                    }
                }
                fired = true;
            }
            enemy.sourceAngle16 = normalizeAngle16(
                static_cast<int>(enemy.sourceAngle16) + 99);
        }
        else if (enemy.spawnType == 0x69 && timer >= 480) {
            static constexpr std::array<int, 5> kInterval{{17, 11, 10, 10, 9}};
            static constexpr std::array<int, 5> kPairs{{1, 2, 3, 4, 5}};
            static constexpr std::array<int, 5> kAngleStep{{150, 240, 270, 300, 340}};
            static constexpr std::array<double, 5> kSpeed{{2.8, 3.5, 3.8, 4.0, 5.0}};
            const int local = (timer - 480) % period;
            const int cadence = std::max(
                1, kInterval[static_cast<std::size_t>(difficulty)] -
                       brokenArmCount);
            enemy.sourceAngle16 = normalizeAngle16(static_cast<int>(
                std::sin(timer * 422.81290322580645 * kPi / 32768.0) *
                2444.0));
            if (local < 300 && local % cadence == 0) {
                const int pairCount =
                    kPairs[static_cast<std::size_t>(difficulty)] +
                    (brokenArmCount == 4 ? 2 : 0);
                const double rootRadians = fixedAngleRadians(enemy.sourceAngle16);
                const auto ellipsePoint = [&](std::uint16_t orbitAngle) {
                    const double orbit = fixedAngleRadians(orbitAngle);
                    const float px = enemy.x + static_cast<float>(
                        std::cos(rootRadians) * std::cos(orbit) * 90.0 -
                        std::sin(rootRadians) * std::sin(orbit) * 25.0);
                    const float py = enemy.y + static_cast<float>(
                        std::cos(rootRadians) * std::sin(orbit) * 25.0 +
                        std::sin(rootRadians) * std::cos(orbit) * 90.0);
                    return std::pair<float, float>{px, py};
                };
                const int orbitBase =
                    kAngleStep[static_cast<std::size_t>(difficulty)] * timer;
                const auto first = ellipsePoint(normalizeAngle16(orbitBase));
                const auto second = ellipsePoint(
                    normalizeAngle16(orbitBase + 0x8000));
                for (int i = 0; i < pairCount; ++i) {
                    const double speed =
                        kSpeed[static_cast<std::size_t>(difficulty)] +
                        brokenArmCount * 0.4 + i * 0.4;
                    spawnProjectileNode(
                        4, 0, first.first, first.second,
                        normalizeAngle16(orbitBase + i * 0x0d05 - 0x8000),
                        0.0f, speed, 1, 0);
                    spawnProjectileNode(
                        4, 0, second.first, second.second,
                        normalizeAngle16(orbitBase + i * 0x0d05),
                        0.0f, speed, 1, 0);
                }
                fired = true;
            }
        }
        else if (enemy.spawnType == 0x6a) {
            static constexpr std::array<int, 5> kInterval{{90, 60, 55, 50, 50}};
            static constexpr std::array<int, 5> kBurstWidth{{16, 16, 20, 24, 28}};
            static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 6.5, 7.0, 9.0}};
            const int local = timer % period;
            const double oldRadians = fixedAngleRadians(enemy.sourceAngle16);
            const float fireX = enemy.x +
                static_cast<float>(std::cos(oldRadians) * 80.0);
            const float fireY = enemy.y +
                static_cast<float>(std::sin(oldRadians) * 80.0);
            const auto aimed = radiansToAngle16(std::atan2(
                static_cast<double>(player_.y - fireY),
                static_cast<double>(player_.x - fireX)));
            const int cadence = kInterval[static_cast<std::size_t>(difficulty)];
            if (local % cadence == 0) {
                enemy.secondaryAngle16 = aimed;
            }
            enemy.sourceAngle16 = normalizeAngle16(
                static_cast<int>(std::sin(
                    timer * 422.81290322580645 * kPi / 32768.0) * 2444.0) -
                0x5a0a);
            const int shotPhase = local % cadence;
            if (local < 300 &&
                shotPhase <
                    kBurstWidth[static_cast<std::size_t>(difficulty)] +
                        brokenArmCount * 4 &&
                shotPhase % 4 == 0) {
                const int layer = shotPhase / 4;
                const int count = layer + 1;
                const int spread = layer * (brokenArmCount * 40 + 300);
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    brokenArmCount * 0.7;
                spawnProjectileSpread(9, 0, fireX, fireY,
                                      enemy.secondaryAngle16, 10.0f, speed,
                                      1, count, spread, 0);
                if (brokenArmCount == 4) {
                    spawnProjectileSpread(
                        9, 0, fireX, fireY,
                        normalizeAngle16(
                            static_cast<int>(enemy.secondaryAngle16) + 7000),
                        10.0f, speed, 1, count, spread, 0);
                    spawnProjectileSpread(
                        9, 0, fireX, fireY,
                        normalizeAngle16(
                            static_cast<int>(enemy.secondaryAngle16) - 7000),
                        10.0f, speed, 1, count, spread, 0);
                }
                fired = true;
            }
        }
    }
    else if (enemy.spawnType == 0x6b) {
        if (parent->helperState != 3) {
            release(false);
            return;
        }
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x = parent->x + static_cast<float>(
            std::cos(radians) * static_cast<double>(enemy.originX));
        enemy.y = parent->y + static_cast<float>(
            std::sin(radians) * static_cast<double>(enemy.originX));

        static constexpr std::array<int, 5> kWindow{{40, 55, 65, 75, 65}};
        static constexpr std::array<int, 5> kCount{{5, 7, 7, 7, 9}};
        static constexpr std::array<double, 5> kSpeed{{5.5, 6.4, 7.0, 7.0, 8.0}};
        if (timer < 300) {
            const int local = timer % 100;
            if (local == 0) enemy.secondaryAngle16 = aimAtPlayer();
            if (local < kWindow[static_cast<std::size_t>(difficulty)] &&
                local % 5 == 0) {
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    timer * 0.004;
                spawnProjectileSpread(10, 0, enemy.x, enemy.y,
                                      normalizeAngle16(
                                          static_cast<int>(enemy.secondaryAngle16) + 300),
                                      10.0f, speed,
                                      1, kCount[static_cast<std::size_t>(difficulty)],
                                      30000, 0);
                spawnProjectileSpread(10, 0, enemy.x, enemy.y,
                                      normalizeAngle16(
                                          static_cast<int>(enemy.secondaryAngle16) - 300),
                                      10.0f, speed,
                                      1, kCount[static_cast<std::size_t>(difficulty)],
                                      30000, 0);
                fired = true;
            }
        }
        if (timer >= 600) {
            static constexpr std::array<int, 5> kFinalSpread{{
                0x2008, 7000, 0x19c8, 6000, 0x157c,
            }};
            static constexpr std::array<int, 5> kSweepPeriod{{
                0x140, 0x118, 0xf0, 0xf0, 0xf0,
            }};
            if (timer == 600) enemy.secondaryAngle16 = aimAtPlayer();
            if (timer < 750) {
                int delta = 0x4000 -
                            static_cast<int>(enemy.secondaryAngle16);
                delta = ((delta + 0x8000) & 0xffff) - 0x8000;
                enemy.secondaryAngle16 = approachAngle16(
                    enemy.secondaryAngle16, 0x4000,
                    std::abs(delta) / 120);
            }
            int center = static_cast<int>(enemy.secondaryAngle16);
            if (timer > 749) {
                const int periodValue =
                    kSweepPeriod[static_cast<std::size_t>(difficulty)];
                const int phase =
                    (periodValue / 4 + timer - 750) % periodValue;
                const int slope = 12000 / (periodValue / 2);
                center += (phase < periodValue / 2
                               ? phase * slope
                               : (periodValue - phase) * slope) -
                          6000;
            }
            if (enemy.y > player_.y) center += 0x8000;
            if (timer > 601 && (timer - 602) % 5 == 0) {
                int spread = kFinalSpread[static_cast<std::size_t>(difficulty)] * 3;
                if (timer < 750) {
                    spread +=
                        ((0xfffa -
                          kFinalSpread[static_cast<std::size_t>(difficulty)] * 3) /
                         150) *
                        (750 - timer);
                }
                spawnProjectileSpread(0x0b, 0, enemy.x, enemy.y,
                                      normalizeAngle16(center), 10.0f,
                                      12.0, 1, 4, spread, 0);
                fired = true;
            }
        }
    }
    else if (enemy.spawnType == 0x6c || enemy.spawnType == 0x6d) {
        if (parent->spawnType != 0x64 && parent->spawnType != 0x65) {
            release(false);
            return;
        }
        enemy.x = parent->x;
        enemy.y = parent->y;
        if (enemy.spawnType == 0x6c && timer < 300) {
            static constexpr std::array<int, 5> kCadence{{9, 5, 4, 5, 4}};
            static constexpr std::array<int, 5> kBaseCount{{1, 2, 3, 3, 3}};
            static constexpr std::array<double, 5> kSpeed{{3.4, 4.0, 4.4, 4.0, 5.0}};
            const int half = timer % 150;
            enemy.secondaryAngle16 = normalizeAngle16(
                half < 75
                    ? timer * 0x1b4 + (timer / 150) * 0x88
                    : timer * -0x1b4 + (timer / 150) * -0x88 - 0x88);
            if (timer % kCadence[static_cast<std::size_t>(difficulty)] == 0) {
                const int count =
                    kBaseCount[static_cast<std::size_t>(difficulty)] +
                    timer / 75;
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    (timer % 75) * 0.03 + (timer / 75) * 0.4;
                spawnProjectileSpread(3, 0, enemy.x, enemy.y,
                                      enemy.secondaryAngle16, 10.0f,
                                      speed, 1, count, 0x10000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(
                        3, 0, enemy.x, enemy.y,
                        normalizeAngle16(
                            static_cast<int>(enemy.secondaryAngle16) +
                            (half < 75 ? -0x4b0 : 0x4b0)),
                        10.0f, speed + 1.2, 1, count, 0x10000, 0);
                }
                fired = true;
            }
        }

        static constexpr std::array<int, 5> kMiddleCadence{{35, 27, 24, 22, 18}};
        if (timer >= 320 && timer < 600 &&
            (timer - 320) %
                    kMiddleCadence[static_cast<std::size_t>(difficulty)] ==
                0) {
            static constexpr std::array<int, 5> kRingCount{{7, 9, 9, 8, 9}};
            static constexpr std::array<int, 5> kLayerCount{{3, 4, 5, 6, 6}};
            static constexpr std::array<double, 5> kSpeed{{4.8, 5.4, 6.0, 6.5, 7.7}};
            const std::uint32_t random = lateStageScriptRand(
                timer + (enemy.spawnType == 0x6d ? 1 : 0));
            const int randomAngle = static_cast<int>(
                random - random / 0x10001u);
            for (int layer = 0;
                 layer < kLayerCount[static_cast<std::size_t>(difficulty)];
                 ++layer) {
                const int direction = enemy.spawnType == 0x6c ? 1 : -1;
                spawnProjectileSpread(
                    enemy.spawnType == 0x6c ? 5 : 4, 0,
                    enemy.x, enemy.y,
                    normalizeAngle16(direction * layer * 600 + randomAngle),
                    0.0f, kSpeed[static_cast<std::size_t>(difficulty)],
                    1, kRingCount[static_cast<std::size_t>(difficulty)],
                    0x10000, 0);
            }
            fired = true;
        }

        if (timer >= 770) {
            static constexpr std::array<int, 5> kCadence{{75, 45, 39, 36, 30}};
            static constexpr std::array<int, 5> kCount{{1, 3, 3, 5, 5}};
            static constexpr std::array<double, 5> kSpeed{{5.5, 6.6, 7.2, 7.7, 9.0}};
            const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
            const int start = 770 + (enemy.spawnType == 0x6c ? cadence : 0);
            if (timer >= start) {
                const int local = timer - start;
                const int phase = local % (cadence * 2);
                if (phase == 0) enemy.secondaryAngle16 = aimAtPlayer();
                if (phase < 12 && phase % 4 == 0) {
                    const int count = kCount[static_cast<std::size_t>(difficulty)];
                    spawnProjectileSpread(
                        0x0c, 0, enemy.x, enemy.y,
                        enemy.secondaryAngle16, 10.0f,
                        kSpeed[static_cast<std::size_t>(difficulty)],
                        1, count, count * 0x960 - 0x960, 0);
                    fired = true;
                }
            }
        }
    }
    else if (enemy.spawnType == 0x6e) {
        // FUN_140029880: the four phase-5 emitters unfold from the boss's
        // upper mount, then run a five-part 1200-frame script.  The original
        // child lifetime follows the owner's HP, not merely its state number.
        if (parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 1);
            release(false);
            return;
        }

        static constexpr std::array<float, 4> kRouteX{{
            100.0f, -100.0f, 210.0f, -210.0f,
        }};
        static constexpr std::array<float, 4> kRouteY{{
            -120.0f, -120.0f, -70.0f, -70.0f,
        }};
        static constexpr std::array<int, 4> kAimOffset{{
            -2000, 2000, -4000, 4000,
        }};
        const int route = std::clamp(enemy.childIndex, 0, 3);
        const auto moveToward = [&enemy](float targetX, float targetY) {
            const float dx = targetX - enemy.x;
            const float dy = targetY - enemy.y;
            const double distance = std::sqrt(
                static_cast<double>(dx) * dx +
                static_cast<double>(dy) * dy);
            enemy.sourceSpeed = distance / 10.0;
            enemy.speed = static_cast<float>(enemy.sourceSpeed);
            enemy.x += dx * 0.1f;
            enemy.y += dy * 0.1f;
        };
        const auto angleTo = [](float fromX, float fromY,
                                float toX, float toY) {
            return radiansToAngle16(std::atan2(
                static_cast<double>(toY - fromY),
                static_cast<double>(toX - fromX)));
        };
        const auto aimFrom = [this, &angleTo](float x, float y) {
            return angleTo(x, y, player_.x, player_.y);
        };
        const auto clampTrackedPoint = [this](float x, float y) {
            const float horizontalOrigin = player_.x / 6.0f;
            return std::pair<float, float>{
                std::clamp(x, horizontalOrigin + 180.0f,
                           horizontalOrigin + 420.0f),
                std::clamp(y, 180.0f, 540.0f),
            };
        };

        int angleDelta = static_cast<int>(enemy.secondaryAngle16) -
                         static_cast<int>(enemy.sourceAngle16);
        angleDelta = ((angleDelta + 0x8000) & 0xffff) - 0x8000;
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, enemy.secondaryAngle16,
            std::abs(angleDelta) / 10 + 0x80);
        enemy.angle = static_cast<float>(fixedAngleRadians(enemy.sourceAngle16));

        const float routeX = parent->x +
            kRouteX[static_cast<std::size_t>(route)];
        const float routeY = parent->y +
            kRouteY[static_cast<std::size_t>(route)];
        if (enemy.helperState == 0) {
            if (timer == 0) {
                enemy.x = parent->x - 33.0f;
                enemy.y = parent->y - 83.0f;
            }
            else {
                moveToward(routeX, routeY);
            }
        }
        bool enteredAttackThisFrame = false;
        if (enemy.helperState == 0 && timer == 40) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            timer = 0;
            enteredAttackThisFrame = true;
        }
        if (enemy.helperState == 1) {
            const int cycle = timer % 1200;
            float targetX = routeX;
            float targetY = routeY;

            if (cycle >= 400 && cycle < 660) {
                if (cycle == 400) {
                    const auto tracked = clampTrackedPoint(player_.x, player_.y);
                    enemy.markerDrawX = tracked.first;
                    enemy.markerDrawY = tracked.second;
                }
                const auto trackedAngle = angleTo(
                    enemy.x, enemy.y,
                    enemy.markerDrawX, enemy.markerDrawY);
                const double trackedRadians = fixedAngleRadians(trackedAngle);
                targetX = enemy.markerDrawX + static_cast<float>(
                    std::cos(trackedRadians) * 250.0);
                targetY = enemy.markerDrawY + static_cast<float>(
                    std::sin(trackedRadians) * 250.0);

                const auto playerAngle = aimFrom(
                    enemy.markerDrawX, enemy.markerDrawY);
                const double playerRadians = fixedAngleRadians(playerAngle);
                enemy.markerDrawX += static_cast<float>(
                    std::cos(playerRadians) * 0.5);
                enemy.markerDrawY += static_cast<float>(
                    std::sin(playerRadians) * 0.5);
                const auto tracked = clampTrackedPoint(
                    enemy.markerDrawX, enemy.markerDrawY);
                enemy.markerDrawX = tracked.first;
                enemy.markerDrawY = tracked.second;
            }
            else if (cycle >= 660 && cycle < 1160) {
                static constexpr std::array<int, 5> kOrbitStep{{
                    80, 140, 160, 140, 160,
                }};
                if (cycle == 660) {
                    enemy.targetAngle16 = normalizeAngle16(
                        route * 0x4000 + 0x2000);
                }
                const int orbitDelta = static_cast<int>(std::sin(
                    static_cast<double>(timer - 800) * kPi / 1000.0) *
                    kOrbitStep[static_cast<std::size_t>(difficulty)]);
                enemy.targetAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.targetAngle16) + orbitDelta);
                const auto wobbleAngle = normalizeAngle16(static_cast<int>(
                    std::sin(static_cast<double>(timer) * kPi / 90.0) *
                    2000.0));
                const double orbitRadians =
                    fixedAngleRadians(enemy.targetAngle16);
                const double wobbleRadians = fixedAngleRadians(wobbleAngle);
                targetX = parent->x + static_cast<float>(
                    std::cos(orbitRadians) * 240.0 -
                    std::sin(wobbleRadians) * 110.0);
                targetY = parent->y + static_cast<float>(
                    std::sin(orbitRadians) * 240.0 +
                    std::cos(wobbleRadians) * 110.0);
                enemy.secondaryAngle16 = aimFrom(parent->x, -720.0f);
            }
            if (!enteredAttackThisFrame) {
                moveToward(targetX, targetY);
            }

            const double bodyRadians = fixedAngleRadians(enemy.sourceAngle16);
            const float muzzleX = enemy.x + static_cast<float>(
                std::cos(bodyRadians) * 38.0);
            const float muzzleY = enemy.y + static_cast<float>(
                std::sin(bodyRadians) * 38.0);

            if (cycle < 240 || cycle > 1160) {
                static constexpr std::array<int, 5> kCadence{{
                    120, 90, 60, 50, 50,
                }};
                const int start = route < 2 ? 10 : 30;
                enemy.secondaryAngle16 = normalizeAngle16(
                    static_cast<int>(aimFrom(routeX, routeY)) +
                    kAimOffset[static_cast<std::size_t>(route)]);
                if (cycle >= start && cycle < 240 &&
                    (cycle - start) %
                            kCadence[static_cast<std::size_t>(difficulty)] ==
                        0) {
                    spawnProjectileNode(
                        2, 0x1d + (route & 1), muzzleX, muzzleY,
                        enemy.sourceAngle16, 10.0f, 12.0, 1, 0);
                    fired = true;
                }
            }

            if (cycle >= 250 && cycle < 390) {
                static constexpr std::array<int, 5> kCount{{
                    3, 5, 7, 9, 9,
                }};
                if (cycle < 270) {
                    enemy.secondaryAngle16 = aimFrom(enemy.x, enemy.y);
                }
                if (cycle >= 273 && (cycle - 273) % 3 == 0) {
                    spawnProjectileSpread(
                        6, 0, muzzleX, muzzleY, enemy.sourceAngle16,
                        10.0f, 6.0, 1,
                        kCount[static_cast<std::size_t>(difficulty)],
                        cycle * -320 + 136400, 0);
                    fired = true;
                }
            }

            if (cycle >= 400 && cycle < 660) {
                static constexpr std::array<int, 5> kTurn{{
                    250, 350, 420, 420, 480,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    3.0, 3.6, 4.8, 6.0, 7.5,
                }};
                enemy.secondaryAngle16 = normalizeAngle16(
                    kTurn[static_cast<std::size_t>(difficulty)] * timer +
                    route * 0x4000 - 0x8000);
                if (cycle >= 450 && cycle < 600 &&
                    (cycle - 450) % 3 == 0) {
                    const auto aimed = angleTo(
                        muzzleX, muzzleY,
                        enemy.markerDrawX, enemy.markerDrawY);
                    const double speed =
                        kSpeed[static_cast<std::size_t>(difficulty)];
                    if (difficulty > 2 || (route & 1) != 0) {
                        spawnProjectileNode(7, 3, muzzleX, muzzleY, aimed,
                                            0.0f, speed, 1, 0);
                    }
                    spawnProjectileNode(
                        7, 3, muzzleX, muzzleY,
                        normalizeAngle16(static_cast<int>(aimed) + 0x5556),
                        0.0f, speed, 1, 0);
                    spawnProjectileNode(
                        7, 3, muzzleX, muzzleY,
                        normalizeAngle16(static_cast<int>(aimed) + 0xaaab),
                        0.0f, speed, 1, 0);
                    fired = true;
                }
            }

            if (cycle >= 660 && cycle < 1160) {
                static constexpr std::array<int, 5> kBurstPeriod{{
                    60, 40, 40, 48, 40,
                }};
                static constexpr std::array<int, 5> kBurstWidth{{
                    16, 20, 24, 20, 24,
                }};
                static constexpr std::array<double, 5> kPrimarySpeed{{
                    3.2, 3.6, 4.0, 4.0, 5.0,
                }};
                static constexpr std::array<int, 5> kSecondaryPeriod{{
                    120, 100, 90, 90, 90,
                }};
                static constexpr std::array<int, 5> kSecondaryCount{{
                    6, 8, 9, 8, 9,
                }};
                static constexpr std::array<double, 5> kSecondarySpeed{{
                    3.8, 4.5, 5.0, 5.0, 6.0,
                }};

                if (cycle >= 700 && cycle < 1150) {
                    const int burst = (cycle - 700) %
                        kBurstPeriod[static_cast<std::size_t>(difficulty)];
                    if (burst <
                            kBurstWidth[static_cast<std::size_t>(difficulty)] &&
                        burst % 4 == 0) {
                        const int count = difficulty > 2 ? 2 : 1;
                        const double speed =
                            kPrimarySpeed[static_cast<std::size_t>(difficulty)];
                        spawnProjectileSpread(
                            2, 1, muzzleX, muzzleY, enemy.sourceAngle16,
                            10.0f, speed, 1, count, 3000, 0);
                        spawnProjectileNode(
                            2, 1, muzzleX, muzzleY,
                            normalizeAngle16(
                                static_cast<int>(enemy.sourceAngle16) +
                                0x5556),
                            0.0f, speed, 1, 0);
                        spawnProjectileNode(
                            2, 1, muzzleX, muzzleY,
                            normalizeAngle16(
                                static_cast<int>(enemy.sourceAngle16) +
                                0xaaab),
                            0.0f, speed, 1, 0);
                        fired = true;
                    }
                }
                if (cycle >= 800 &&
                    (cycle - 800) %
                            kSecondaryPeriod[
                                static_cast<std::size_t>(difficulty)] ==
                        0 &&
                    (route & 1) == 0) {
                    const int count =
                        kSecondaryCount[static_cast<std::size_t>(difficulty)];
                    const double speed =
                        kSecondarySpeed[static_cast<std::size_t>(difficulty)];
                    spawnProjectileSpread(
                        5, 0, muzzleX, muzzleY, enemy.sourceAngle16,
                        0.0f, speed, 1, count, 16000, 0);
                    if (difficulty > 2) {
                        const int innerCount = count - 1;
                        spawnProjectileSpread(
                            5, 0, muzzleX, muzzleY, enemy.sourceAngle16,
                            0.0f, speed + 0.8, 1, innerCount,
                            16000 / innerCount * (innerCount - 1), 0);
                    }
                    fired = true;
                }
            }
        }
    }
    else { // 0x6f, FUN_14002aac0
        if (parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 1);
            release(false);
            return;
        }

        if (enemy.helperState == 0) {
            if (timer == 0) {
                enemy.secondaryAngle16 = 0x4000;
            }
            const double unfold = timer < 40
                                      ? std::sin(static_cast<double>(timer) *
                                                 kPi / 80.0)
                                      : 1.0;
            if (timer < 40) {
                const float anchorX = parent->x - 33.0f;
                const float anchorY = parent->y - 83.0f;
                enemy.markerDrawX = anchorX + static_cast<float>(
                    (360.0f - anchorX) * unfold);
                enemy.markerDrawY = anchorY + static_cast<float>(
                    (360.0f - anchorY) * unfold);
            }
            const double radians = fixedAngleRadians(enemy.sourceAngle16);
            const float radial = static_cast<float>(
                (timer < 40 ? static_cast<int>(unfold * 800.0) : 800));
            const float vertical = static_cast<float>(
                (timer < 40 ? static_cast<int>(unfold * 350.0) : 350));
            enemy.x = enemy.markerDrawX + static_cast<float>(
                std::cos(radians) * radial);
            enemy.y = enemy.markerDrawY + static_cast<float>(
                std::sin(radians) * radial) + vertical;
        }
        if (enemy.helperState == 0 && parent->helperTimer >= 160) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            timer = 0;
        }
        if (enemy.helperState == 1) {
            static constexpr std::array<int, 5> kBurstPeriod{{
                90, 60, 60, 60, 60,
            }};
            static constexpr std::array<int, 5> kBurstWidth{{
                16, 20, 24, 24, 32,
            }};
            static constexpr std::array<int, 5> kCount{{
                1, 1, 1, 2, 2,
            }};
            static constexpr std::array<int, 5> kSecondPeriod{{
                40, 30, 20, 20, 15,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                3.6, 4.2, 4.6, 5.0, 6.5,
            }};

            const int cycle = timer % 1200;
            const int turn = static_cast<int>(std::sin(
                static_cast<double>(timer) * kPi / 600.0) * 80.0);
            enemy.sourceAngle16 = normalizeAngle16(
                static_cast<int>(enemy.sourceAngle16) + turn);
            const double orbitRadians = fixedAngleRadians(enemy.sourceAngle16);
            enemy.x = enemy.markerDrawX + static_cast<float>(
                std::cos(orbitRadians) * 800.0);
            enemy.y = enemy.markerDrawY + static_cast<float>(
                std::sin(orbitRadians) * 800.0) + 350.0f;

            const double sourceRadians =
                fixedAngleRadians(enemy.secondaryAngle16);
            const float firstX = enemy.x + static_cast<float>(
                std::cos(sourceRadians) * 38.0);
            const float firstY = enemy.y + static_cast<float>(
                std::sin(sourceRadians) * 38.0);
            const auto oppositeAngle = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) + 0x8000);
            const double oppositeRadians = fixedAngleRadians(oppositeAngle);
            const float secondX = enemy.x + static_cast<float>(
                std::cos(oppositeRadians) * 38.0);
            const float secondY = enemy.y + static_cast<float>(
                std::sin(oppositeRadians) * 38.0);
            const int burstPeriod =
                kBurstPeriod[static_cast<std::size_t>(difficulty)];
            const int burstWidth =
                kBurstWidth[static_cast<std::size_t>(difficulty)];
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            const int secondPeriod =
                kSecondPeriod[static_cast<std::size_t>(difficulty)];
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];

            if (cycle < 580) {
                const int burst = cycle % burstPeriod;
                if (burst < burstWidth && burst % 4 == 0) {
                    spawnProjectileSpread(
                        5, 0, firstX, firstY, enemy.secondaryAngle16,
                        10.0f, speed, 1, count, 4000, 0);
                    fired = true;
                }
                if (cycle % secondPeriod == 0) {
                    spawnProjectileNode(
                        8, 0, secondX, secondY,
                        normalizeAngle16(
                            static_cast<int>(enemy.secondaryAngle16) -
                            0x8000),
                        10.0f, speed - 1.6, 1, 0);
                    fired = true;
                }
            }
            else if (cycle >= 640 && cycle < 1140) {
                const int local = cycle - 640;
                const int burst = local % burstPeriod;
                if (burst < burstWidth && burst % 4 == 0) {
                    spawnProjectileNode(
                        5, 0, secondX, secondY,
                        normalizeAngle16(
                            static_cast<int>(enemy.secondaryAngle16) -
                            0x8000),
                        10.0f, speed - 1.6, 1, 0);
                    fired = true;
                }
                if (local % secondPeriod == 0) {
                    spawnProjectileSpread(
                        8, 0, firstX, firstY, enemy.secondaryAngle16,
                        10.0f, speed, 1, count, 4000, 0);
                    fired = true;
                }
            }

            if (cycle % 4 == 0) {
                const float horizontalOrigin = player_.x / 6.0f;
                const auto insideBoundary = [horizontalOrigin](float px,
                                                                float py) {
                    return px >= horizontalOrigin - 30.0f &&
                           px <= horizontalOrigin + 630.0f && py >= -30.0f &&
                           py <= 750.0f;
                };
                if (enemy.sourceAngle16 > 0x7fff &&
                    insideBoundary(firstX, firstY)) {
                    spawnProjectileNode(0x0e, 0, firstX, firstY,
                                        enemy.sourceAngle16, 0.0f,
                                        2.0, 1, 0);
                    fired = true;
                }
                if (enemy.sourceAngle16 < 0x8000 &&
                    insideBoundary(secondX, secondY)) {
                    spawnProjectileNode(0x0e, 0, secondX, secondY,
                                        enemy.sourceAngle16, 0.0f,
                                        2.0, 1, 0);
                    fired = true;
                }
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
        const bool countdownExpired = lateStageBossCountdown_ < 1;
        if (countdownExpired) {
            flushEnemyProjectilesToEffects();
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 100);
        }
        else {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
        }
        spawnBossPhaseBreakFeedback(enemy, lateStageBossCountdown_);
        spawnPostDeathCounterEntity(enemy, 140.0);
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
                                 0, 40);
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
                // FUN_140023260 alternates the five possible rings between
                // the upper body origin and the (-33,-83) muzzle.
                const float shotX = (layer & 1) == 0
                                        ? enemy.x - 33.0f
                                        : enemy.x;
                const float shotY = (layer & 1) == 0
                                        ? enemy.y - 83.0f
                                        : enemy.y;
                for (int i = 0; i < count; ++i) {
                    spawnProjectileNode(
                        visual, projectileId, shotX, shotY,
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

    if (enemy.spawnType == 0x143) {
        updateStage06Midboss(enemy);
        return;
    }
    if (isStage06MidbossNodeType(enemy.spawnType)) {
        updateStage06MidbossNode(enemy);
        return;
    }
    if (isStage09MidbossType(enemy.spawnType)) {
        updateStage09Midboss(enemy);
        return;
    }
    if (isStage09MidbossNodeType(enemy.spawnType)) {
        updateStage09MidbossNode(enemy);
        return;
    }
    if (isStage07MidbossNodeType(enemy.spawnType)) {
        updateStage07MidbossNode(enemy);
        return;
    }
    if (isStage06BossNodeType(enemy.spawnType)) {
        updateStage06BossNode(enemy);
        return;
    }
    if (isStage07BossNodeType(enemy.spawnType)) {
        updateStage07BossNode(enemy);
        return;
    }
    if (enemy.parentSpawnType == 0x13f &&
        isStage08BossNodeType(enemy.spawnType)) {
        updateStage08BossNode(enemy);
        return;
    }
    if (enemy.parentSpawnType == 0x140 &&
        isStage09BossNodeType(enemy.spawnType)) {
        updateStage09BossNode(enemy);
        return;
    }
    if (isStage10FinalBossNodeType(enemy.spawnType)) {
        updateStage10FinalBossNode(enemy);
        return;
    }
    lateStageBossCountdownDraw_ = lateStageBossCountdown_;

    if (isStage07MidbossType(enemy.spawnType)) {
        updateStage07Midboss(enemy);
        return;
    }

    if (enemy.spawnType == 0x13d) {
        updateStage06Boss(enemy);
        return;
    }
    if (enemy.spawnType == 0x13e) {
        updateStage07Boss(enemy);
        return;
    }
    if (enemy.spawnType == 0x13f) {
        updateStage08Boss(enemy);
        return;
    }
    if (enemy.spawnType == 0x140) {
        updateStage09Boss(enemy);
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

    const auto emitStage10ScenePattern = [this, &enemy]() {
        const int timer = enemy.helperTimer;
        const auto aimFrom = [this](float x, float y) {
            return radiansToAngle16(std::atan2(
                static_cast<double>(player_.y - y),
                static_cast<double>(player_.x - x)));
        };

        if (enemy.helperState == 2 && timer >= 40) {
            const int cycle = (timer - 40) % 0x35c;
            const float rightX = enemy.x + 68.0f;
            const float leftX = enemy.x - 68.0f;
            const float sourceY = enemy.y + 95.0f;
            const auto rightAim = aimFrom(rightX, sourceY);
            const auto leftAim = aimFrom(leftX, sourceY);

            if (cycle < 400) {
                if (cycle % 100 == 0) {
                    enemy.secondaryAngle16 = rightAim;
                    enemy.targetAngle16 = leftAim;
                    for (int layer = 0; layer < 4; ++layer) {
                        const double speed = 4.4 - layer * 1.3;
                        for (int i = 0; i < 8; ++i) {
                            spawnProjectileNode(
                                10, 0x35, rightX, sourceY,
                                normalizeAngle16(
                                    static_cast<int>(rightAim) + i * 5000 -
                                    layer * 0x0af0 - 0x53fc),
                                0.0f, speed, 1, 0);
                            spawnProjectileNode(
                                10, 0x36, leftX, sourceY,
                                normalizeAngle16(
                                    static_cast<int>(leftAim) + i * 0x0df3 +
                                    layer * 0x0af0 - 0x2134),
                                0.0f, speed, 1, 0);
                        }
                    }
                    playPlayerSound(bullet2SoundHandle_, 0x0c);
                }
                if (cycle % 100 < 30 && cycle % 5 == 0) {
                    spawnProjectileNode(0x0b, 0, rightX, sourceY,
                                        enemy.secondaryAngle16, 10.0f,
                                        8.0, 1, 0);
                    spawnProjectileNode(0x0b, 0, leftX, sourceY,
                                        enemy.targetAngle16, 10.0f,
                                        8.0, 1, 0);
                    enemy.secondaryAngle16 = approachAngle16(
                        enemy.secondaryAngle16, rightAim, 500);
                    enemy.targetAngle16 = approachAngle16(
                        enemy.targetAngle16, leftAim, 500);
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                }
            }

            const auto emitAlternating = [&](bool right, int localCycle) {
                const std::uint32_t random = lateBossFrameRand(
                    timer + (right ? 0 : 0x457));
                const int jitter = static_cast<int>(random % 2001u);
                const auto base = aimFrom(enemy.x, enemy.y);
                for (int i = 0; i < 15; ++i) {
                    const int angle = right
                                          ? static_cast<int>(base) + 0x18f0 +
                                                jitter + i * 0x0505
                                          : static_cast<int>(base) - 0x5f40 -
                                                jitter + i * 0x0505;
                    spawnProjectileNode(right ? 3 : 2, 8,
                                        right ? rightX : leftX, sourceY,
                                        normalizeAngle16(angle), 10.0f,
                                        7.2, 1, 0);
                }
                (void)localCycle;
                playPlayerSound(bullet2SoundHandle_, 0x0c);
            };
            if (cycle >= 400 && cycle < 800) {
                const int local = (cycle - 400) % 200;
                if (local < 60 && local % 12 == 0) {
                    emitAlternating(true, local);
                }
            }
            if (cycle >= 500 && cycle < 800) {
                const int local = (cycle - 500) % 200;
                if (local < 60 && local % 12 == 0) {
                    emitAlternating(false, local);
                }
            }
            return;
        }

        if (enemy.helperState == 4 && timer > 30) {
            const float rightX = enemy.x + 68.0f;
            const float leftX = enemy.x - 68.0f;
            const float burstY = enemy.y + 155.0f;
            const float streamY = enemy.y + 95.0f;
            if (timer >= 60) {
                const int burst = (timer - 60) % 150;
                if (burst == 0) {
                    enemy.secondaryAngle16 = aimFrom(enemy.x, burstY);
                }
                if (burst < 40 && burst % 13 == 0) {
                    for (int i = 0; i < 2; ++i) {
                        spawnProjectileNode(
                            0x0d, 0, enemy.x, burstY,
                            normalizeAngle16(
                                static_cast<int>(enemy.secondaryAngle16) +
                                i * 2000 - 1000),
                            10.0f, 9.0, 1, 0);
                    }
                    for (int i = 0; i < 3; ++i) {
                        spawnProjectileNode(
                            0x0d, 0, enemy.x, burstY,
                            normalizeAngle16(
                                static_cast<int>(enemy.secondaryAngle16) +
                                i * 2000 - 2000),
                            10.0f, 8.0, 1, 0);
                    }
                    enemy.secondaryAngle16 = approachAngle16(
                        enemy.secondaryAngle16,
                        aimFrom(enemy.x, burstY), 0x04b0);
                    playPlayerSound(bullet1SoundHandle_, 0x13);
                }
            }
            if (timer >= 130) {
                const int local = (timer - 130) % 0x21c;
                if (local < 250 && local % 6 == 0) {
                    for (int i = 0; i < 2; ++i) {
                        spawnProjectileNode(
                            2, 0x37, leftX, streamY,
                            normalizeAngle16(timer * 0x164 - i * 0x8000),
                            10.0f, 5.0, 1, 0);
                    }
                    playPlayerSound(bullet2SoundHandle_, 0x0c);
                }
            }
            if (timer >= 400) {
                const int local = (timer - 400) % 0x21c;
                if (local < 250 && local % 6 == 0) {
                    for (int i = 0; i < 2; ++i) {
                        spawnProjectileNode(
                            2, 0x37, rightX, streamY,
                            normalizeAngle16(-timer * 0x164 - i * 0x8000),
                            10.0f, 5.0, 1, 0);
                    }
                    playPlayerSound(bullet2SoundHandle_, 0x0c);
                }
            }
            return;
        }

        if (enemy.helperState == 6 && timer > 0 &&
            (timer - 1) % 5 == 0) {
            const auto random = lateBossFrameRand(timer + frame_ * 0x457);
            const auto random2 = lateBossFrameRand(
                timer + frame_ * 0x457 + 1);
            const auto randomAngle = normalizeAngle16(
                static_cast<int>(random & 0xffffu));
            const auto randomAngle2 = normalizeAngle16(
                static_cast<int>(random2 & 0xffffu));
            const float firstX = enemy.x + static_cast<float>(
                std::sin(fixedAngleRadians(randomAngle)) * 36.0);
            const float secondX = enemy.x + static_cast<float>(
                std::sin(fixedAngleRadians(randomAngle2)) * 36.0);
            const float sourceY = enemy.y + 140.0f;
            const auto firstAngle = normalizeAngle16(
                static_cast<int>(std::sin(
                    fixedAngleRadians(normalizeAngle16(random + 0x1357))) *
                                 14000.0) - 0x4000);
            const auto secondAngle = normalizeAngle16(
                static_cast<int>(std::sin(
                    fixedAngleRadians(normalizeAngle16(random2 + 0x2468))) *
                                 14000.0) - 0x4000);
            for (double speed : {7.0, 11.0}) {
                spawnProjectileNode(0x0d, 0x0b, firstX, sourceY,
                                    firstAngle, 10.0f, speed, 1, 0);
                spawnProjectileNode(0x0d, 0x0b, secondX, sourceY,
                                    secondAngle, 10.0f, speed, 1, 0);
            }
            playPlayerSound(bullet2SoundHandle_, 0x0c);
        }
    };

    if (enemy.spawnType == 0x14c) {
        ensureStage10SceneRootNode(enemy);
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
            if (lateStageBossPhaseMode_ != 1 ||
                (enemy.hp > 0 && lateStageBossCountdown_ > 0)) {
                return false;
            }

            enemy.targetable = false;
            enemy.targetableTimer = 0;
            enemy.radius = 250;
            const bool countdownExpired = lateStageBossCountdown_ < 1;
            if (countdownExpired) {
                flushEnemyProjectilesToEffects();
                player_.invulnerableFrames =
                    std::max(player_.invulnerableFrames, 100);
            }
            else {
                spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                      0.0, 0, 0, 0.0f);
            }
            spawnBossPhaseBreakFeedback(enemy, lateStageBossCountdown_);
            spawnPostDeathCounterEntity(enemy, 140.0);
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

        // FUN_1400ef010 steers toward fields 0x30/0x34 before dispatching
        // helperState. markerDrawX/Y preserve those target fields here.
        if (enemy.helperState == 0 && enemy.helperTimer == 0) {
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y;
        }
        if (enemy.helperState != 7) {
            const double xPeriod = enemy.helperState == 6 ? 11.0 : 100.0;
            const double xAmplitude = enemy.helperState == 6 ? 10.0 : 18.0;
            const float desiredX = enemy.markerDrawX + static_cast<float>(
                std::sin(static_cast<double>(frame_) * kTau / xPeriod) *
                xAmplitude);
            const float desiredY = enemy.markerDrawY + static_cast<float>(
                std::sin(static_cast<double>(frame_) * kTau / 177.0) * 10.0);
            const float dx = desiredX - enemy.x;
            const float dy = desiredY - enemy.y;
            const float distance = std::sqrt(dx * dx + dy * dy);
            const auto heading = radiansToAngle16(std::atan2(
                static_cast<double>(dy), static_cast<double>(dx)));
            const double headingRadians = fixedAngleRadians(heading);
            enemy.x += static_cast<float>(
                std::cos(headingRadians) * (static_cast<double>(distance) / 5.0));
            enemy.y += static_cast<float>(
                std::sin(headingRadians) * (static_cast<double>(distance) / 5.0));
        }

        if (enemy.helperState == 0 || enemy.helperState == 1) {
            const bool preAttackState = enemy.helperState == 1;
            if (preAttackState) {
                stage10GateFlag_ = true;
                enemy.targetable = false;
            }

            float targetX = enemy.markerDrawX;
            float targetY = enemy.markerDrawY;
            if (frame_ < 1200) {
                // Fields 0x30/0x34 retain their constructor values.
            }
            else if (frame_ < 3000) {
                const double phase = static_cast<double>(frame_ - 1200) *
                                     kTau / 7200.0;
                targetX = 360.0f;
                targetY = static_cast<float>(std::sin(phase) * 800.0 - 2400.0);
            }
            else if (frame_ < 4700) {
                const double phase = static_cast<double>(frame_ - 3000) *
                                     kTau / 6800.0;
                targetX = 360.0f;
                targetY = static_cast<float>(std::sin(phase) * 850.0 - 1600.0);
            }
            else if (frame_ < 6600) {
                const double phase = static_cast<double>(frame_ - 4700) *
                                     kTau / 7600.0;
                const double wave = std::sin(phase);
                targetX = static_cast<float>(wave * -560.0 + 360.0);
                targetY = static_cast<float>(wave * 100.0 - 750.0);
            }
            else if (frame_ < 8500) {
                const double primaryPhase = static_cast<double>(frame_ - 6600) *
                                            kTau / 7600.0;
                const double secondaryPhase = static_cast<double>(frame_ - 6600) *
                                              kTau / 3800.0;
                const double primaryWave = std::sin(primaryPhase);
                targetX = static_cast<float>(primaryWave * 1120.0 - 200.0);
                targetY = static_cast<float>(
                    primaryWave * (50.0 - std::sin(secondaryPhase) * 150.0) -
                    650.0);
            }
            else if (frame_ < 9100) {
                const double phase = static_cast<double>(frame_ - 8500) *
                                     kTau / 2400.0;
                const double wave = std::sin(phase);
                targetX = static_cast<float>(wave * -560.0 + 920.0);
                targetY = static_cast<float>(wave * -100.0 - 600.0);
            }
            else if (frame_ < 11300) {
                const double phase = static_cast<double>(frame_ - 9100) *
                                     kTau / 8800.0;
                targetX = 360.0f;
                targetY = static_cast<float>(std::sin(phase) * 450.0 - 700.0);
            }
            else if (frame_ < 12000) {
                const double phase = static_cast<double>(frame_ - 11300) *
                                     kTau / 2800.0;
                targetX = 360.0f;
                targetY = static_cast<float>(std::sin(phase) * 400.0 - 250.0);
            }
            else {
                targetX = 360.0f;
                targetY = 150.0f;
            }
            enemy.markerDrawX = targetX;
            enemy.markerDrawY = targetY;
            if (!preAttackState && enemy.helperTimer == 0) {
                // State 0 copies the freshly computed target into x/y at timer 0.
                enemy.x = targetX;
                enemy.y = targetY;
            }
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
                enemy.targetable = false;
                enemy.targetableTimer = 0;
                stage10GateFlag_ = true;
            }
            else if (preAttackState && frame_ == 12000) {
                // The original processes state 1 for frame 12000, then advances;
                // state 2 must not emit until the following entity update.
                enemy.helperState = 2;
                enemy.helperTimer = 0;
                lateStageBossPhaseMode_ = 1;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
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

            emitStage10ScenePattern();
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
                enemy.radius = 200;
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
                spawnStageEffect(0x11, -1, 0, 0x28,
                                 enemy.x, enemy.y, 0,
                                 0.0, 1.0, 1.0, 0,
                                 0xff, 0xff, 0xff, 0xff);
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

        const auto aimFrom = [this](float x, float y) {
            return radiansToAngle16(std::atan2(
                static_cast<double>(player_.y - y),
                static_cast<double>(player_.x - x)));
        };
        const auto moveTowardScriptTarget = [this, &enemy](double speed,
                                                            bool refreshTarget) {
            if (refreshTarget && frame_ % 50 == 0) {
                lateStageBossTargetX_ = 210.0f + static_cast<float>(
                    lateBossFrameRand(frame_) % 301u);
                lateStageBossTargetY_ = 180.0f + static_cast<float>(
                    lateBossFrameRand(selectedStage_ * 0x457 + frame_) % 101u);
            }
            const auto target = radiansToAngle16(std::atan2(
                static_cast<double>(lateStageBossTargetY_ - enemy.y),
                static_cast<double>(lateStageBossTargetX_ - enemy.x)));
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                                  target, 0x200);
            const double radians = fixedAngleRadians(enemy.sourceAngle16);
            enemy.x += static_cast<float>(std::cos(radians) * speed);
            enemy.y += static_cast<float>(std::sin(radians) * speed);
        };
        const auto emitFinalRootPattern = [this, &enemy, &aimFrom]() {
            const int state = enemy.helperState;
            const int timer = enemy.helperTimer;
            bool fired = false;

            const auto ring = [this, &enemy, &fired](
                                  int visual, int projectileId,
                                  std::uint16_t angle, double speed,
                                  int count, int spread = 0x10000) {
                spawnProjectileSpread(visual, projectileId, enemy.x, enemy.y,
                                      angle, 0.0f, speed, 1, count, spread, 0);
                fired = true;
            };
            if (state == 1 && timer >= 30) {
                const bool fastHalf = timer >= 0x17c;
                const int halfPeriod = fastHalf ? 0x5a : 0x78;
                const int start = fastHalf ? 0x136 : 0x1e;
                const int sweep = (timer - start) % halfPeriod;
                const double speed = 4.0 + (timer - 0x1e) * 0.003;
                const int first = (timer - start) % (halfPeriod * 2);
                if (first >= 0 && first < 0x48 && first % 5 == 0) {
                    const float sourceX = 720.0f - sweep * 10.0f;
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x105, sourceX, -10.0f,
                        aimFrom(sourceX, -10.0f), speed, first / 5);
                }
                const int secondStart = start + halfPeriod;
                const int second = timer >= secondStart
                                       ? (timer - secondStart) % (halfPeriod * 2)
                                       : -1;
                if (second >= 0 && second < 0x48 && second % 5 == 0) {
                    const float sourceX = 25.0f + sweep * 10.0f;
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x105, sourceX, -10.0f,
                        aimFrom(sourceX, -10.0f), speed, second / 5);
                }
            }
            else if (state == 0x15 && timer >= 0x1e) {
                const int local = timer - 0x1e;
                const double speed = 6.0 + local * 0.004;
                const int first = local % 300;
                if (first < 0x5a && first % 0x0e == 0) {
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x106, enemy.x, enemy.y,
                        normalizeAngle16(7000), speed, first / 0x0e);
                }
                const int second = timer >= 0xb4 ? (timer - 0xb4) % 300 : -1;
                if (second >= 0 && second < 0x5a && second % 0x0e == 0) {
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x106, enemy.x, enemy.y,
                        normalizeAngle16(0x64a8), speed, second / 0x0e);
                }
                if (timer >= 0xd2 && (timer - 0xd2) % 100 == 0) {
                    const auto aimed = aimFrom(enemy.x, enemy.y);
                    const double burstSpeed = 5.0 + (timer - 0xd2) * 0.002;
                    ring(3, 0, aimed, burstSpeed, 7, 0x3000);
                    ring(3, 0, aimed, burstSpeed - 1.5, 20);
                }
            }
            else if (state == 0x29 && timer >= 0x1e) {
                const int local = timer - 0x1e;
                const int sweep = local % 100;
                const double nodeSpeed = 3.0 + local * 0.001;
                if (local % 300 < 0x3c && local % 300 % 5 == 0) {
                    const float sourceX = 720.0f - sweep * 10.0f;
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x107, sourceX, -10.0f,
                        normalizeAngle16(sweep * 0x96 + 500), nodeSpeed,
                        local / 5);
                }
                const int second = timer >= 0x82 ? (timer - 0x82) % 300 : -1;
                if (second >= 0 && second < 0x3c && second % 5 == 0) {
                    const float sourceX = 85.0f + sweep * 10.0f;
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x107, sourceX, -10.0f,
                        normalizeAngle16(0x7e0c - sweep * 0x96), nodeSpeed,
                        second / 5);
                }
                const int third = timer >= 0xe6 ? (timer - 0xe6) % 300 : -1;
                if (third >= 0 && third < 0x3c && third % 7 == 0) {
                    const auto aimed = aimFrom(enemy.x, enemy.y);
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x107, enemy.x, enemy.y,
                        normalizeAngle16(static_cast<int>(aimed) - 0x1800),
                        nodeSpeed, third / 7 * 2);
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x107, enemy.x, enemy.y,
                        normalizeAngle16(static_cast<int>(aimed) + 0x1800),
                        nodeSpeed, third / 7 * 2 + 1);
                }
                if (timer >= 0x118) {
                    const int burst = (timer - 0x118) % 100;
                    if (burst < 0x20 && (burst & 3) == 0) {
                        ring(3, 0, aimFrom(enemy.x, enemy.y),
                             6.4 + local * 0.003, 3, 0x1800);
                    }
                }
            }
            else if (state == 0x3d && timer >= 0x1e) {
                const bool fastHalf = timer >= 0x1ae;
                const int halfPeriod = fastHalf ? 0x4b : 100;
                const int start = fastHalf ? 0x1ae : 0x1e;
                const int local = timer - start;
                const double speed = 5.0 + (timer - 0x1e) * 0.002;
                if (local >= 0 && local % (halfPeriod * 2) == 0) {
                    const auto random = lateBossFrameRand(timer);
                    const auto base = normalizeAngle16(
                        static_cast<int>(random & 0xffffu));
                    for (int i = 0; i < 15; ++i) {
                        fired |= spawnStage10FinalBossEmitter(
                            enemy, 0x10c, enemy.x, enemy.y,
                            normalizeAngle16(static_cast<int>(base) +
                                             i * 0x1111),
                            speed, i);
                    }
                }
                if (local >= halfPeriod &&
                    (local - halfPeriod) % (halfPeriod * 2) == 0) {
                    const auto random = lateBossFrameRand(timer + 1);
                    const auto base = normalizeAngle16(
                        static_cast<int>(random & 0xffffu));
                    for (int i = 0; i < 15; ++i) {
                        fired |= spawnStage10FinalBossEmitter(
                            enemy, 0x10d, enemy.x, enemy.y,
                            normalizeAngle16(static_cast<int>(base) +
                                             i * 0x1111),
                            speed, i);
                    }
                }
            }
            else if (state == 0x51 && timer >= 0x1e) {
                const int local = timer - 0x1e;
                const auto aimed = aimFrom(enemy.x, enemy.y);
                if (timer == 0x1e) enemy.secondaryAngle16 = aimed;
                if ((local & 3) == 0) {
                    enemy.secondaryAngle16 = approachAngle16(
                        enemy.secondaryAngle16, aimed, 0x78);
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x10e, enemy.x, enemy.y,
                        enemy.secondaryAngle16, 2.0 + local * 0.0015,
                        local / 4);
                }
                if (timer >= 0x96 && (timer - 0x96) % 100 == 0) {
                    const double speed = 6.6 + local * 0.0015;
                    ring(3, 0, aimed, speed, 15);
                    ring(3, 0, aimed, speed - 1.6, 15);
                }
            }
            else if (state == 0x65 && timer >= 0x1e) {
                const int local = timer - 0x1e;
                const int first = local % 0x2e8;
                if (first % 0x174 == 0) {
                    const bool reverse = first > 0x173;
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, reverse ? 0x109 : 0x108,
                        enemy.x, enemy.y,
                        normalizeAngle16((reverse ? -1 : 1) * timer * 0x400),
                        16.0, first / 0x174);
                }
                if (timer >= 0xd8 && (timer - 0xd8) % 0x174 == 0) {
                    const bool reverse = ((timer - 0xd8) / 0x174 & 1) != 0;
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, reverse ? 0x109 : 0x108,
                        enemy.x, enemy.y,
                        normalizeAngle16(timer * -0x400), 16.0,
                        (timer - 0xd8) / 0x174);
                }
                if (timer >= 0x2d && (timer - 0x2d) % 0x5d == 0) {
                    ring(2, 0, aimFrom(enemy.x, enemy.y), 3.2, 21);
                }
            }
            else if (state == 0x79 && timer >= 0x1e) {
                int scheduled = 0x1e;
                int interval = 0x8c;
                for (int index = 0; index < 30; ++index) {
                    if (timer == scheduled) {
                        const double speed = std::min(
                            40.0, 29.0 + (timer - 0x1e) * 0.026);
                        const int type = (index & 1) == 0 ? 0x10f : 0x110;
                        const float targetX = type == 0x10f ? 10.0f : 590.0f;
                        fired |= spawnStage10FinalBossEmitter(
                            enemy, type, targetX, enemy.y,
                            normalizeAngle16(0xc000), speed, index);
                        break;
                    }
                    scheduled += std::max(interval, 0x50);
                    interval -= 10;
                }
            }
            else if (state == 0x83 && timer >= 0x122) {
                const int local = (timer - 0x122) % 0x708;
                const float leftX = 200.0f;
                const float rightX = 520.0f;
                const auto leftAim = aimFrom(leftX, 240.0f);
                const auto rightAim = aimFrom(rightX, 240.0f);
                if (local < 0x168 && local % 0x1c == 0) {
                    spawnProjectileSpread(0x0b, 0, leftX, 240.0f,
                                          leftAim, 0.0f, 6.0, 1,
                                          13, 24000, 0);
                    spawnProjectileSpread(10, 0, rightX, 240.0f,
                                          rightAim, 0.0f, 6.0, 1,
                                          13, 24000, 0);
                    fired = true;
                }
                if (local >= 0x1e0 && local < 0x366 &&
                    (local - 0x1e0) % 0x24 == 0) {
                    spawnProjectileSpread(5, 0, leftX, 240.0f,
                                          leftAim, 0.0f, 5.0, 1,
                                          11, 0x3000, 0);
                    spawnProjectileSpread(8, 0, rightX, 240.0f,
                                          rightAim, 0.0f, 5.0, 1,
                                          7, 0x6000, 0);
                    fired = true;
                }
            }
            else if (state == 0x8d && timer < 0xd2 && (timer & 1) == 0) {
                const auto random = lateBossFrameRand(timer);
                fired |= spawnStage10FinalBossEmitter(
                    enemy, 0x128, enemy.x, enemy.y,
                    normalizeAngle16(static_cast<int>(random & 0xffffu)),
                    0.0, timer / 2);
            }
            else if (state == 0x99 && timer >= 0x1e) {
                if ((timer - 0x1e) % 0x168 == 0) {
                    const auto random = lateBossFrameRand(timer);
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x134, 0.0f, 0.0f,
                        normalizeAngle16(static_cast<int>(random & 0xffffu)),
                        0.0, (timer - 0x1e) / 0x168);
                }
                if (timer >= 0xd2 && (timer - 0xd2) % 0x168 == 0) {
                    const auto random = lateBossFrameRand(timer + 1);
                    fired |= spawnStage10FinalBossEmitter(
                        enemy, 0x135, 0.0f, 0.0f,
                        normalizeAngle16(static_cast<int>(random & 0xffffu)),
                        0.0, (timer - 0xd2) / 0x168);
                }
            }

            if (fired) {
                playPlayerSound(bullet2SoundHandle_, 0x0c);
            }
        };

        if (enemy.helperState == 0) {
            // FUN_140052fb0 uses the same 0x200 steering and 0.4 speed as its
            // combat states; it does not interpolate to a fixed y coordinate.
            moveTowardScriptTarget(0.4, true);
            if (enemy.helperTimer >= 260) {
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

        const bool regularCombatState = enemy.helperState == 1 ||
            (enemy.helperState >= 11 && enemy.helperState <= 151 &&
             enemy.helperState % 10 == 1);
        const bool extendedCombatState = enemy.helperState == 142 ||
                                         enemy.helperState == 153;
        if (regularCombatState || extendedCombatState) {
            const int state = enemy.helperState;
            const bool sharedNodePhase = state >= 11 && state <= 111 &&
                                         state % 20 == 11;
            if (sharedNodePhase && enemy.helperTimer == 220) {
                lateStageBossPhaseMode_ = 1;
            }
            if ((state == 131 || state == 151) && enemy.helperTimer == 280) {
                lateStageBossPhaseMode_ = 1;
            }
            if (state == 141 && enemy.helperTimer == 310) {
                lateStageBossPhaseMode_ = 1;
            }

            if (lateStageBossPhaseMode_ == 1 &&
                (enemy.hp < 1 || lateStageBossCountdown_ < 1)) {
                enemy.targetable = false;
                enemy.targetableTimer = 0;
                const bool countdownExpired = lateStageBossCountdown_ < 1;
                if (countdownExpired) {
                    flushEnemyProjectilesToEffects();
                    player_.invulnerableFrames =
                        std::max(player_.invulnerableFrames, 100);
                }
                else {
                    spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                          0.0, 0, 0, 0.0f);
                }
                spawnBossPhaseBreakFeedback(enemy, lateStageBossCountdown_);
                spawnPostDeathCounterEntity(enemy, 140.0);
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

            if (state == 151 &&
                (enemy.hp < lateStageBossMaxHp_ / 4 ||
                 lateStageBossCountdown_ < 1500)) {
                enemy.helperState = 152;
                enemy.helperTimer = 0;
                enemy.targetable = false;
                enemy.targetableTimer = 0;
                return;
            }

            bool moveThisFrame = true;
            bool refreshTarget = true;
            if (sharedNodePhase && enemy.helperTimer >= 220) {
                moveThisFrame = false;
                refreshTarget = false;
            }
            if (state == 131 && enemy.helperTimer >= 280) {
                moveThisFrame = false;
                refreshTarget = false;
            }
            if (state == 141 && enemy.helperTimer >= 270) {
                moveThisFrame = false;
                refreshTarget = false;
            }
            if (moveThisFrame) {
                moveTowardScriptTarget(enemy.sourceSpeed > 0.0
                                           ? enemy.sourceSpeed
                                           : 0.4,
                                       refreshTarget);
            }
            emitFinalRootPattern();
            if (enemy.helperTimer == 30) {
                int nodeType = 0;
                switch (enemy.helperState) {
                case 11:  nodeType = 0x111; break;
                case 31:  nodeType = 0x112; break;
                case 51:  nodeType = 0x113; break;
                case 71:  nodeType = 0x115; break;
                case 91:  nodeType = 0x11a; break;
                case 111: nodeType = 0x11d; break;
                case 141: nodeType = 0x127; break;
                case 151: nodeType = 0x12d; break;
                default: break;
                }
                if (nodeType != 0) {
                    spawnStage10FinalBossNode(enemy, nodeType);
                }
                if (enemy.helperState == 131) {
                    spawnStage10FinalBossNode(enemy, 0x125);
                    spawnStage10FinalBossNode(enemy, 0x126);
                }
            }
            if (state == 141 && enemy.helperTimer == 0xd20) {
                enemy.helperState = 142;
                enemy.helperTimer = 0;
                enemy.sourceSpeed = 0.1;
                return;
            }
            if (lateStageBossPhaseMode_ == 1 && lateStageBossCountdown_ > 0) {
                updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
                --lateStageBossCountdown_;
            }
            return;
        }

        if (enemy.helperState == 152) {
            moveTowardScriptTarget(enemy.sourceSpeed > 0.0
                                       ? enemy.sourceSpeed
                                       : 0.1,
                                   true);
            enemy.targetable = false;
            if (enemy.helperTimer >= 150) {
                enemy.helperState = 153;
                enemy.helperTimer = 0;
                enemy.sourceSpeed = 0.4;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            if (lateStageBossPhaseMode_ == 1 && lateStageBossCountdown_ > 0) {
                updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
                --lateStageBossCountdown_;
            }
            return;
        }

        if (enemy.helperState >= 10 && enemy.helperState <= 150 &&
            enemy.helperState % 10 == 0) {
            const int transitionIndex = enemy.helperState / 10;
            if ((transitionIndex & 1) != 0) {
                // States 10/30/.../150 run FUN_14007ac00 and add 0.1 to y.
                enemy.y += 0.1f;
            }
            else {
                // States 20/40/.../140 retain the normal 0x200 steering.
                moveTowardScriptTarget(enemy.sourceSpeed > 0.0
                                           ? enemy.sourceSpeed
                                           : 0.4,
                                       true);
            }
            if (enemy.helperTimer < 90 && enemy.helperTimer % 3 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
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
                if (enemy.helperState == 141) {
                    enemy.sourceSpeed = 0.1;
                }
                else if (enemy.helperState == 151) {
                    enemy.sourceSpeed = 0.2;
                }
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }

        if (enemy.helperState == 200) {
            enemy.targetable = false;
            enemy.y += 0.2f;
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

    // Every reachable late-stage boss and child has returned through a
    // dedicated helper above. An unexpected state must not acquire invented
    // movement or projectile behavior.
    enemy.targetable = false;
    enemy.drawBodyThisFrame = false;
}

bool StageRuntime::drawStage10FinalBossNode(const StageEnemy& enemy, float x,
                                            float y, int exactLayer) const {
    if (isStage10FinalBossEmitterType(enemy.spawnType)) {
        return drawStage10FinalBossEmitter(enemy, x, y, exactLayer);
    }

    if (!isStage10FinalBossNodeType(enemy.spawnType)) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    const bool stage10Launcher = enemy.spawnType >= 0x116 &&
                                 enemy.spawnType <= 0x119;
    int defaultBodyLayer = 0x1e;
    switch (enemy.spawnType) {
    case 0x114: defaultBodyLayer = 0x1c; break;
    case 0x11b: defaultBodyLayer = 0x1d; break;
    case 0x11c: defaultBodyLayer = 0x1c; break;
    case 0x11e:
    case 0x120: defaultBodyLayer = 0x20; break;
    case 0x11f:
    case 0x121: defaultBodyLayer = 0x1f; break;
    case 0x122: defaultBodyLayer = 0x1d; break;
    case 0x127: defaultBodyLayer = 0x1e; break;
    default: break;
    }
    int alpha = 255;
    if (!stage10Launcher && enemy.drawHelperState == 0) {
        alpha = std::clamp(timer * 255 / 150, 0, 255);
    }
    else if (!stage10Launcher && enemy.drawHelperState == 99 &&
             enemy.spawnType != 0x127) {
        alpha = std::clamp((100 - timer) * 255 / 100, 0, 255);
    }
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

    bool drew = false;
    const auto drawLarge = [this, &drew, exactLayer, defaultBodyLayer](
                                         int frame, float drawX, float drawY,
                                         std::uint16_t angle = 0,
                                         bool reverseX = false,
                                         double scale = 1.0) {
        if (exactLayer != defaultBodyLayer) return;
        const int graph = frameHandle(enemyLargeFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  scale, scale, reverseX);
            drew = true;
        }
    };
    const auto drawMedium = [this, &drew, exactLayer, defaultBodyLayer](
                                          int frame, float drawX, float drawY,
                                          std::uint16_t angle = 0,
                                          bool reverseX = false) {
        if (exactLayer != defaultBodyLayer) return;
        const int graph = frameHandle(enemyMediumFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  1.0, 1.0, reverseX);
            drew = true;
        }
    };
    const auto drawSmall = [this, &drew, exactLayer, defaultBodyLayer](
                                         int frame, float drawX, float drawY,
                                         std::uint16_t angle = 0,
                                         bool reverseX = false) {
        if (exactLayer != defaultBodyLayer) return;
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
        // FUN_14005e890 uses a dedicated three-layer materialization and
        // keeps the body opaque while it wobbles apart in state 99.
        const int frame = 0x5a + (enemy.spawnType - 0x116);
        const float drawY = y + 120.0f;
        const int bodyLayer = std::clamp(
            0x19 + static_cast<int>(enemy.y / 100.0f), 0, 0x7f);
        const auto drawLauncherLayer =
            [this, &drew, x, drawY, exactLayer, bodyLayer](
                                    int layerFrame, int layerAlpha,
                                    double scaleX, double scaleY,
                                    int forcedLayer = -1) {
                const int nodeLayer = forcedLayer >= 0
                                          ? forcedLayer
                                          : (layerFrame == 0x59 ? 0x14
                                                                : bodyLayer);
                if (exactLayer != nodeLayer) return;
                const int graph = frameHandle(enemyLargeFrames_, layerFrame);
                if (graph == -1 || layerAlpha <= 0) {
                    return;
                }
                SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                                 std::clamp(layerAlpha, 0, 255));
                drawOriginalMode7Node(graph, x, drawY, 0,
                                      scaleX, scaleY, false);
                drew = true;
            };
        const auto sineAlpha = [](double phase) {
            return std::clamp(
                static_cast<int>(std::sin(phase) * 255.0), 0, 255);
        };

        // This family owns the draw branch even on the fully transparent
        // first frame and after visible destruction ends.
        drew = true;
        if (enemy.drawHelperState == 0) {
            if (timer < 150) {
                const int appearAlpha = sineAlpha(
                    static_cast<double>(timer) * kPi / 300.0);
                drawLauncherLayer(frame, appearAlpha, 1.0, 1.0);
            }
            else if (timer < 180) {
                const int bodyAlpha = sineAlpha(
                    static_cast<double>(timer - 150) * kPi / 60.0);
                const int appearAlpha = sineAlpha(
                    static_cast<double>(timer - 120) * kPi / 60.0);
                drawLauncherLayer(frame, bodyAlpha, 1.0, 1.0);
                drawLauncherLayer(0x59, bodyAlpha / 2, 1.0, 1.0);
                drawLauncherLayer(frame, appearAlpha, 1.0, 1.0, 0x1e);
            }
            else {
                drawLauncherLayer(frame, 255, 1.0, 1.0);
                drawLauncherLayer(0x59, 255 / 2, 1.0, 1.0);
            }
        }
        else if (enemy.drawHelperState == 99) {
            if (timer < 100) {
                const double wave = std::sin(
                    static_cast<double>(timer) * kTau / 15.0);
                const double scaleX = 1.0 - wave * 0.2;
                const double scaleY = 1.0 + wave * 0.2;
                drawLauncherLayer(frame, 255, scaleX, scaleY);
                drawLauncherLayer(0x59, 255 / 2, scaleX, 1.0);
            }
        }
        else if (enemy.drawHelperState == 1 ||
                 enemy.drawHelperState == 3) {
            const double wave = std::sin(
                static_cast<double>(timer) * kPi / 40.0);
            const double scaleX = 1.0 - wave * 0.3;
            const double scaleY = 1.0 + wave * 0.3;
            drawLauncherLayer(frame, 255, scaleX, scaleY);
            drawLauncherLayer(0x59, 255 / 2, scaleX, 1.0);
        }
        else if (enemy.drawHelperState == 2 ||
                 enemy.drawHelperState == 4) {
            double wobble = 0.05 * std::sin(
                static_cast<double>(timer) * kPi / 30.0);
            if (timer < 60) {
                wobble += 0.1 * std::sin(
                    static_cast<double>(timer) * kTau / 15.0) *
                    std::sin(static_cast<double>(timer + 60) *
                             kPi / 120.0);
            }
            drawLauncherLayer(frame, 255, 1.0 + wobble,
                              1.0 - wobble);
            drawLauncherLayer(0x59, 255 / 2, 1.0 + wobble, 1.0);
        }
        else {
            drawLauncherLayer(frame, 255, 1.0, 1.0);
            drawLauncherLayer(0x59, 255 / 2, 1.0, 1.0);
        }
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
        if (exactLayer == 0x1e) {
            drew = true;
        }
        break;
    case 0x11a:
        // Enemy_l[0x5e] is the shared-HP root. 0x11b/0x11c own [0x5f]/[0x60].
        drawLarge(0x5e, x, y, enemy.sourceAngle16);
        break;
    case 0x11d:
        // The nine batteries are separate parent-relative entities.
        drawLarge(0x61, x, y - 80.0f, enemy.sourceAngle16);
        break;
    case 0x125: {
        // FUN_140064630 materializes through [0x4e] -> [0x50] -> [0x52];
        // state 1 and the destruction branch both use the final [0x52] body.
        int frame = 0x52;
        if (enemy.helperState == 0) {
            frame = timer < 0x78 ? 0x4e : (timer < 0xb4 ? 0x50 : 0x52);
        }
        drawLarge(frame, x, y, enemy.sourceAngle16);
        break;
    }
    case 0x126: {
        int frame = 0x53;
        if (enemy.helperState == 0) {
            frame = timer < 0x78 ? 0x4f : (timer < 0xb4 ? 0x51 : 0x53);
        }
        drawLarge(frame, x, y, enemy.sourceAngle16, true);
        break;
    }
    case 0x127: {
        // FUN_140066370 never replaces Enemy_l[0x64].  It remains the
        // controller body at 0x1e while Enemy_m[0xdd..0xe0] supplies the
        // animated face/component and the later states add independent
        // Enemy_l[0x65]/[0x66] shells on 0x19/0x1d.
        const int state = enemy.drawHelperState;
        const auto drawLargeLayer =
            [this, &drew, exactLayer, x, y, &enemy](int frame, int layer,
                                                    bool reverse = false,
                                                    double scale = 1.0) {
                if (exactLayer != layer) return;
                const int graph = frameHandle(enemyLargeFrames_, frame);
                if (graph == -1) return;
                drawOriginalMode7Node(graph, x, y, enemy.sourceAngle16,
                                      scale, scale, reverse);
                drew = true;
            };
        const auto drawMediumLayer =
            [this, &drew, exactLayer, x, y, &enemy](int frame, int layer) {
                if (exactLayer != layer) return;
                const int graph = frameHandle(enemyMediumFrames_, frame);
                if (graph == -1) return;
                drawOriginalMode7Node(graph, x, y, enemy.sourceAngle16,
                                      1.0, 1.0, false);
                drew = true;
            };

        int mediumFrame = 0xdd;
        if (state == 0) {
            mediumFrame = timer < 0x28 ? 0xde : 0xdf;
        }
        else if (state == 17) {
            mediumFrame = 0xde;
        }
        else if (state >= 18 && state <= 20) {
            mediumFrame = timer <= 0x18 ? 0xdf : 0xde;
        }
        else if (state >= 21 && state <= 24) {
            mediumFrame = timer < 0x23 ? 0xdf : 0xde;
        }
        else if (state == 26) {
            mediumFrame = timer < 0x5a ? 0xde : 0xe0;
        }
        else if ((state >= 27 && state <= 31) || state == 99) {
            mediumFrame = 0xe0;
        }

        drawLargeLayer(0x64, 0x1e);
        drawMediumLayer(mediumFrame, 0x1e);

        if (state >= 17 && state <= 24) {
            drawLargeLayer(0x65, 0x1e);
        }
        if (state >= 18 && state <= 24) {
            drawLargeLayer(0x59, 0x19);
            if (exactLayer == 0x1d && (timer & 1) == 0) {
                SetDrawBlendMode(DX_BLENDMODE_ADD, 96);
                drawLargeLayer(0x65, 0x1d, false, 1.02);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }

        const bool finalShell = (state == 26 && timer >= 0x50) ||
                                (state >= 27 && state <= 31 && timer >= 0x32);
        if (finalShell && exactLayer == 0x1d) {
            SetDrawBlendMode(DX_BLENDMODE_ADD, 160);
            drawLargeLayer(0x66, 0x1d, false, 1.0);
            SetDrawBlendMode(DX_BLENDMODE_ADD, 96);
            drawLargeLayer(0x66, 0x1d, true, 1.015);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        break;
    }
    case 0x12d:
        // FUN_14006ad60 advances through Enemy_l[0x67..0x6a].
        drawLarge(0x67 + std::min(3, std::max(0, enemy.drawHelperState)),
                  x, y, enemy.sourceAngle16);
        break;
    default:
        break;
    }

    if (!drew && exactLayer == defaultBodyLayer) {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(20, enemy.radius / 3),
                   GetColor(255, 96, 160), TRUE);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    return true;
}

bool StageRuntime::drawLateStageBoss(const StageEnemy& enemy, float x,
                                     float y, int exactLayer) const {
    const bool stage08Node = enemy.parentSpawnType == 0x13f &&
                             isStage08BossNodeType(enemy.spawnType);
    const bool stage09Node = enemy.parentSpawnType == 0x140 &&
                             isStage09BossNodeType(enemy.spawnType);
    if (!isLateStageBossType(enemy.spawnType) && !stage08Node &&
        !stage09Node) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (enemy.spawnType == 0x143) {
        if (exactLayer != 0x1e) return true;
        return drawStage06Midboss(enemy, x, y);
    }
    if (isStage06MidbossNodeType(enemy.spawnType)) {
        if (exactLayer != 0x1e) return true;
        return drawStage06MidbossNode(enemy, x, y);
    }
    if (isStage07MidbossType(enemy.spawnType)) {
        return drawStage07Midboss(enemy, x, y, exactLayer);
    }
    if (isStage07MidbossNodeType(enemy.spawnType)) {
        return drawStage07MidbossNode(enemy, x, y, exactLayer);
    }
    if (isStage09MidbossType(enemy.spawnType)) {
        return drawStage09Midboss(enemy, x, y, exactLayer);
    }
    if (isStage09MidbossNodeType(enemy.spawnType)) {
        return drawStage09MidbossNode(enemy, x, y, exactLayer);
    }
    if (isStage07BossNodeType(enemy.spawnType)) {
        return drawStage07BossNode(enemy, x, y, exactLayer);
    }
    if (stage08Node) {
        return drawStage08BossNode(enemy, x, y, exactLayer);
    }
    if (stage09Node) {
        return drawStage09BossNode(enemy, x, y, exactLayer);
    }
    if (isStage06BossNodeType(enemy.spawnType)) {
        int graph = -1;
        bool large = false;
        int bodyLayer = 0x23;
        double nodeScale = 1.0;
        std::uint16_t drawAngle = enemy.sourceAngle16;
        switch (enemy.spawnType) {
        case 0x64:
            graph = frameHandle(enemyLargeFrames_, 40);
            large = true;
            bodyLayer = 0x21;
            break;
        case 0x65:
            graph = frameHandle(enemyMediumFrames_, 101);
            bodyLayer = 0x1f;
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
            // FUN_1400289b0 updates these controller/emitters but never
            // queues a draw node.
            return true;
        case 0x6e:
        case 0x6f:
            graph = frameHandle(enemySmallFrames_,
                                72 + (frame_ / 4) % 6);
            if (enemy.drawHelperState == 0) {
                nodeScale = std::sin(
                    static_cast<double>(std::clamp(enemy.drawHelperTimer,
                                                   0, 40)) *
                    kPi / 80.0);
            }
            if (enemy.spawnType == 0x6f) {
                drawAngle = enemy.secondaryAngle16;
            }
            break;
        default:
            break;
        }
        if (graph != -1 && exactLayer == bodyLayer) {
            drawOriginalMode7Node(graph, x, y, drawAngle,
                                  large ? 1.0 : nodeScale,
                                  large ? 1.0 : nodeScale, false);
        }
        return true;
    }
    if (isStage10FinalBossNodeType(enemy.spawnType)) {
        return drawStage10FinalBossNode(enemy, x, y, exactLayer);
    }
    if (enemy.spawnType == 0x140) {
        return drawStage09Boss(enemy, x, y, exactLayer);
    }
    if (enemy.spawnType == 0x13f) {
        return drawStage08Boss(enemy, x, y, exactLayer);
    }

    const int timer = enemy.drawHelperTimer;
    int handle = -1;
    double scale = 1.0;
    bool drewBody = false;
    bool bodyIntentionallyHidden = false;
    if (enemy.spawnType == 0x13e) {
        const int state = enemy.drawHelperState;
        if (state < 10 || (state == 10 && timer < 100)) {
            const auto drawLarge = [this, &drewBody](int frame, float drawX,
                                                      float drawY) {
                const int graph = frameHandle(enemyLargeFrames_, frame);
                if (graph != -1) {
                    drawOriginalMode7Node(graph, drawX, drawY, 0,
                                          1.0, 1.0, false);
                    drewBody = true;
                }
            };
            // FUN_14002b680 queues the deck and its lower fixtures before the
            // twins on layer 0x19. Only the foreground truss is on 0x1e.
            if (exactLayer == 0x19) {
                drawLarge(45, x, y + 20.0f);
                if (lateBossFrameRand(std::max(0, frame_ - 1)) % 5u != 0u) {
                    drawLarge(51, x, y);
                }
                drawLarge(49, x, y);
            }
            else if (exactLayer == 0x1e) {
                drawLarge(50, x, y);
            }
        }
        else {
            bodyIntentionallyHidden = true;
        }
    }
    else if (enemy.spawnType == 0x13c) {
        const int state = enemy.drawHelperState;
        int segmentStart = -1;
        if (state == 0 || state == 1 || (state == 2 && timer <= 99)) {
            segmentStart = 0;
        }
        else if (state == 2 || state == 3 ||
                 (state == 4 && timer <= 99)) {
            segmentStart = 1;
        }
        else if (state == 4 || state == 5 ||
                 (state == 6 && timer <= 99)) {
            segmentStart = 2;
        }
        else if (state == 6 || state == 7 ||
                 (state == 8 && timer <= 129)) {
            segmentStart = 3;
        }

        if (segmentStart >= 0) {
            bodyIntentionallyHidden = true;
            const int sourceFrame = std::max(0, frame_ - 1);
            const int effect = frameHandle(effectLargeFrames_, 15);
            if (effect != -1 && exactLayer == 0x17) {
                const double pulse = 1.0 +
                    std::sin(sourceFrame * kTau / 5.0) * 0.1;
                SetDrawBlendMode(DX_BLENDMODE_ADD, 0xe1);
                drawOriginalMode7Node(effect, x, y + 110.0f, 0,
                                      pulse, pulse, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
                drewBody = true;
            }

            for (int segment = segmentStart; segment < 4; ++segment) {
                const float segmentY = y +
                    static_cast<float>((segmentStart - segment) * 444 - 110);
                const int base = frameHandle(enemyLargeFrames_, 0x1d);
                const int baseLayer = 0x18 + segment * 3;
                if (base != -1 && exactLayer == baseLayer) {
                    drawOriginalMode7Node(base, x, segmentY, 0,
                                          1.0, 1.0, false);
                    drewBody = true;
                }

                // The character animation occupies layer 34, between the
                // final segment's base (33) and overlay (35).
                if (segment == 3 && exactLayer == 0x22) {
                    const int character = frameHandle(
                        bossFrames_, 40 + (timer / 7) % 4);
                    if (character != -1) {
                        drawOriginalMode7Node(character, x, segmentY + 70.0f,
                                              0, 1.0, 1.0, false);
                        drewBody = true;
                    }
                }

                const int overlay = frameHandle(
                    enemyLargeFrames_, 0x1e + segment);
                const int overlayLayer = 0x1a + segment * 3;
                if (overlay != -1 && exactLayer == overlayLayer) {
                    drawOriginalMode7Node(overlay, x, segmentY, 0,
                                          1.0, 1.0, false);
                    drewBody = true;
                }
                if (segment == 3 && exactLayer == 0x24) {
                    const int cap = frameHandle(enemyLargeFrames_, 0x22);
                    if (cap != -1) {
                        drawOriginalMode7Node(cap, x, segmentY - 385.0f, 0,
                                              1.0, 1.0, false);
                        drewBody = true;
                    }
                }
            }
        }
        else if (state == 8) {
            int bossFrame = 45 + ((timer - 220) / 5) % 4;
            if (timer < 210) {
                bossFrame = 40 + (timer / 7) % 4;
            }
            else if (timer < 220) {
                bossFrame = 43 + ((timer - 210) / 5) % 2;
            }
            handle = frameHandle(bossFrames_, bossFrame);
        }
        else if (state == 9 || (state >= 11 && state <= 13)) {
            handle = frameHandle(bossFrames_, 45 + (timer / 5) % 4);
        }
        else if (state == 10 || (state == 14 && timer < 240)) {
            handle = frameHandle(bossFrames_, 48 + (timer / 5) % 2);
            if (state == 10) {
                scale = 1.0 - 0.3 * std::sin(
                    static_cast<double>(timer) * kTau / 360.0);
            }
        }
        else if (state == 14) {
            bodyIntentionallyHidden = true;
        }
    }
    else if (enemy.spawnType == 0x13d) {
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
            if (exactLayer == 0x1e) {
                drawLarge(36, x + 75.0f, y,
                          normalizeAngle16(spin));
                drawLarge(36, x - 75.0f, y,
                          normalizeAngle16(-spin), true);
                drawLarge(37, x, y, enemy.secondaryAngle16);
                drawLarge(39, x, y, enemy.targetAngle16);
            }
            if (exactLayer == 0x20) {
                drawLarge(38, x, y, enemy.targetAngle16);
                const int mediumFrame = (state < 3 &&
                                         (state != 2 || timer < 101))
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
        bodyIntentionallyHidden = true;
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
        if (exactLayer == 0x11) {
            drawLarge(70, x + upperX, y + upperY,
                      normalizeAngle16(leftUpperAngle));
            drawLarge(70, x - upperX, y + upperY,
                      normalizeAngle16(-0x2000 - upperSwing), true);
        }

        int bodyFrame = 66;
        if (enemy.drawHelperState <= 2) bodyFrame = 63;
        else if (enemy.drawHelperState == 4) bodyFrame = 64;
        else if (enemy.drawHelperState == 6) bodyFrame = 65;
        if (exactLayer == 0x19) {
            drawLarge(bodyFrame, x, y, 0);
        }

        const int lowerSwing = static_cast<int>(
            std::sin(sourceFrame * kTau / 100.0) * 700.0);
        if (exactLayer == 0x19) {
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

    if (handle != -1 && exactLayer == 0x1e) {
        drawOriginalMode7Node(handle, x, y, 0, scale, scale, false);
        drewBody = true;
    }
    if (exactLayer == 0x1e && !drewBody && !bodyIntentionallyHidden) {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(24, enemy.radius / 2), GetColor(255, 96, 160), TRUE);
    }

    return true;
}

bool StageRuntime::drawLateStageEnemy(const StageEnemy& enemy, float x,
                                      float y, int exactLayer) const {
    if (isStage06EnemyType(enemy.spawnType)) {
        return drawStage06Enemy(enemy, x, y, exactLayer);
    }

    if (enemy.spawnType >= 0x70 && enemy.spawnType <= 0x78) {
        return drawStage07Enemy(enemy, x, y, exactLayer);
    }

    if (isSharedHitboxProxyType(enemy.spawnType)) {
        return true;
    }

    if (isStage10GuardNodeType(enemy.spawnType)) {
        if (exactLayer != 0x3c) return true;
        return drawStage10GuardNode(enemy, x, y);
    }

    if (isStage10SceneNodeType(enemy.spawnType)) {
        return drawStage10SceneNode(enemy, x, y, exactLayer);
    }

    if (enemy.spawnType >= 0xfa && enemy.spawnType <= 0x104) {
        return drawStage10Enemy(enemy, x, y, exactLayer);
    }

    if (isStage08EnemyType(enemy.spawnType)) {
        return drawStage08Enemy(enemy, x, y, exactLayer);
    }

    const LateSpawnSpec* spec = lateSpawnSpec(enemy.spawnType);
    if (spec == nullptr) {
        return false;
    }

    int bodyLayer = 0x23;
    switch (enemy.spawnType) {
    case 0x44:
    case 0x4c:
        bodyLayer = 0x4e;
        break;
    case 0x46:
    case 0x49:
    case 0x4a:
    case 0x4d:
    case 0x4f:
    case 0x57:
    case 0x58:
        bodyLayer = 0x20;
        break;
    case 0x47:
    case 0x48:
        bodyLayer = 0x21;
        break;
    case 0x4b:
        bodyLayer = 0x22;
        break;
    case 0x4e:
    case 0x50:
    case 0x51:
    case 0x52:
        bodyLayer = 0x1e;
        break;
    default:
        break;
    }

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
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

    const auto drawSmallExact = [this, exactLayer, bodyLayer](int frame,
                                        float drawX, float drawY,
                                        std::uint16_t angle, double scale = 1.0,
                                        bool reverseX = false) {
        if (exactLayer != bodyLayer) return;
        const int graph = frameHandle(enemySmallFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  scale, scale, reverseX);
        }
    };
    const auto drawMediumExact = [this, exactLayer, bodyLayer](int frame,
                                         float drawX, float drawY,
                                         std::uint16_t angle, double scaleX = 1.0,
                                         double scaleY = 1.0) {
        if (exactLayer != bodyLayer) return;
        const int graph = frameHandle(enemyMediumFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  scaleX, scaleY, false);
        }
    };
    const auto drawLargeExact = [this, exactLayer, bodyLayer](int frame,
                                        float drawX, float drawY,
                                        std::uint16_t angle, double scale = 1.0) {
        if (exactLayer != bodyLayer) return;
        const int graph = frameHandle(enemyLargeFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  scale, scale, false);
        }
    };
    const auto drawBossExact = [this, exactLayer, bodyLayer](int frame,
                                       float drawX, float drawY,
                                       double scale = 1.0) {
        if (exactLayer != bodyLayer) return;
        const int graph = frameHandle(bossFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, 0,
                                  scale, scale, false);
        }
    };
    const auto drawStage05Gauge = [this, &enemy, x, y, exactLayer](int mode) {
        if (!enemy.targetable || enemy.maxHp < 1000) return;
        StageEnemy gauge = enemy;
        gauge.hp = enemy.drawHp;
        drawEnemyGaugeExact(gauge, mode, x, y, exactLayer);
    };

    // The original helpers queue their draw nodes before the main loop
    // advances DAT_140e418c8. draw() runs after that increment here.
    const int sourceFrame = std::max(0, frame_ - 1);

    if (enemy.spawnType == 0x44) { // FUN_140096890 draw tail
        const int timer = enemy.drawHelperTimer;
        const int spin = timer * 0x29a;
        const double outerScale = 1.1 + 0.1 * std::sin(
            static_cast<double>(timer - 11) * kTau / 44.0);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x80);
        drawSmallExact(47, x, y, normalizeAngle16(spin), outerScale);
        drawSmallExact(47, x, y, normalizeAngle16(-spin), outerScale);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        const int body = frameHandle(enemySmallFrames_, 46);
        if (body != -1 && exactLayer == bodyLayer) {
            const double bodyScaleY = 1.0 + 0.1 * std::sin(
                static_cast<double>(timer) * kTau / 44.0);
            drawOriginalMode7Node(body, x, y, enemy.sourceAngle16,
                                  1.0, bodyScaleY, false);
        }
        drawStage05Gauge(2);
        return true;
    }

    if (enemy.spawnType == 0x45) { // FUN_140097270 draw tail
        const int timer = enemy.drawHelperTimer;
        const double bodyPhase = static_cast<double>(timer) * kTau / 48.0;
        const double mountPhase = static_cast<double>(timer) * kTau / 13.0;
        const float mountY = y + static_cast<float>(
            std::sin(static_cast<double>(timer - 15) * kTau / 48.0));
        const int outerAngle = static_cast<int>(std::sin(mountPhase) * 5000.0);
        const int innerAngle = static_cast<int>(
            std::sin(static_cast<double>(timer - 4) * kTau / 13.0) * 5000.0);
        drawSmallExact(51, x + 5.0f, mountY,
                       normalizeAngle16(innerAngle));
        drawSmallExact(51, x - 5.0f, mountY,
                       normalizeAngle16(-innerAngle), 1.0, true);
        drawSmallExact(50, x + 5.0f, mountY,
                       normalizeAngle16(outerAngle));
        drawSmallExact(50, x - 5.0f, mountY,
                       normalizeAngle16(-outerAngle), 1.0, true);
        drawSmallExact(49, x, mountY, 0);
        drawSmallExact(48, x,
                       y + 2.0f + static_cast<float>(std::sin(bodyPhase)), 0);
        drawStage05Gauge(2);
        return true;
    }

    if (enemy.spawnType == 0x46) { // FUN_140097d30 draw tail
        const int timer = enemy.drawHelperTimer;
        const int frontAngle = static_cast<int>(
            std::sin(static_cast<double>(timer - 3) * kTau / 36.0) * 2400.0);
        const int rearAngle = static_cast<int>(
            std::sin(static_cast<double>(timer) * kTau / 36.0) * 2400.0);
        drawMediumExact(80, x, y, normalizeAngle16(frontAngle));
        const int front = frameHandle(enemyMediumFrames_, 80);
        if (front != -1 && exactLayer == bodyLayer) {
            drawOriginalMode7Node(front, x, y, normalizeAngle16(-frontAngle),
                                  1.0, 1.0, true);
        }
        drawMediumExact(79, x, y, normalizeAngle16(rearAngle));
        const int rear = frameHandle(enemyMediumFrames_, 79);
        if (rear != -1 && exactLayer == bodyLayer) {
            drawOriginalMode7Node(rear, x, y, normalizeAngle16(-rearAngle),
                                  1.0, 1.0, true);
        }
        drawMediumExact(78, x, y, 0);
        drawStage05Gauge(1);
        return true;
    }

    if (enemy.spawnType == 0x47 || enemy.spawnType == 0x48) {
        // FUN_140098700 keys the small rotation to the stage tick and entity
        // id, while the body scale keeps pulsing independently of entry state.
        const int timer = enemy.drawHelperTimer;
        const double scale = 1.0 + 0.05 * std::sin(
            static_cast<double>(timer) * kTau / 66.0);
        const int wobble = static_cast<int>(std::sin(
            static_cast<double>(sourceFrame - enemy.entityId * 13) *
            kTau / 88.0) * 666.0);
        drawMediumExact(81, x, y, normalizeAngle16(wobble), scale, scale);
        drawStage05Gauge(1);
        return true;
    }

    if (enemy.spawnType == 0x49) {
        // FUN_140098f40 uses the same half-sine for the child radius and its
        // visual materialization. Once state 1 begins the scale is fixed.
        const double scale = enemy.drawHelperState == 0
                                 ? std::sin(static_cast<double>(std::clamp(
                                       enemy.drawHelperTimer, 0, 30)) *
                                       kPi / 60.0)
                                 : 1.0;
        drawMediumExact(82, x, y, 0, scale, scale);
        drawStage05Gauge(1);
        return true;
    }
    if (enemy.spawnType == 0x4a) {
        const int timer = enemy.drawHelperTimer;
        const double bodyScale = 1.0 + 0.05 * std::sin(
            static_cast<double>(timer) * kTau / 99.0);
        const double mountPhase = fixedAngleRadians(normalizeAngle16(
            static_cast<int>((timer - 12) * 1489.4545454545455)));
        drawMediumExact(83, x, y, 0, bodyScale, 1.0);
        drawSmallExact(52, x,
                       y - 52.0f + static_cast<float>(
                           std::sin(mountPhase) * 2.0),
                       0);
        drawStage05Gauge(1);
        return true;
    }
    if (enemy.spawnType == 0x4b) { // FUN_14008bd60 type-0x4b branch
        const float wave = static_cast<float>(
            std::sin(static_cast<double>(enemy.drawHelperTimer) *
                     kTau / 8.0) * 2.0);
        drawSmallExact(54, x, y + wave, 0);
        drawSmallExact(53, x, y - wave, 0);
        return true;
    }
    if (enemy.spawnType == 0x4c) {
        const auto angle = normalizeAngle16(
            sourceFrame * -0x8ae + enemy.entityId * -0x4a56);
        const double targetScale = config_.difficulty < 2 ? 0.8 : 1.0;
        const double scale = enemy.drawHelperState == 0
                                 ? std::sin(static_cast<double>(std::clamp(
                                       enemy.drawHelperTimer, 0, 20)) *
                                       kPi / 40.0) * targetScale
                                 : targetScale;
        drawMediumExact(84, x, y, angle, scale, scale);
        if (scale > 0.0) {
            const int graph = frameHandle(enemyMediumFrames_, 84);
            if (graph != -1 && exactLayer == bodyLayer) {
                SetDrawBlendMode(DX_BLENDMODE_ADD, 0x30);
                drawOriginalMode7Node(graph, x, y, angle, scale, scale, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
        return true;
    }
    if (enemy.spawnType == 0x4d) {
        const auto drawBar = [this, exactLayer](float drawX, float drawY) {
            if (exactLayer != 0x1e) return;
            const int graph = frameHandle(enemyLargeFrames_, 21);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, 0,
                                      1.0, 1.0, false);
            }
        };
        if (enemy.drawHelperState != 2) {
            const double ringScale = 1.0 + 0.1 * std::sin(
                static_cast<double>(sourceFrame) * kTau / 94.0);
            const float ringRadius = static_cast<float>(50.0 * ringScale);
            for (int i = 0; i < 5; ++i) {
                const auto angle = normalizeAngle16(
                    enemy.drawHelperTimer * 0x1c8 + i * 0x3333);
                const double radians = fixedAngleRadians(angle);
                drawMediumExact(
                    85,
                    x + static_cast<float>(std::cos(radians) * ringRadius),
                    y + static_cast<float>(std::sin(radians) * ringRadius),
                    angle, ringScale, ringScale);
            }
            drawSmallExact(55, x, y,
                           normalizeAngle16(sourceFrame * -0x7b));
            drawBar(x, y + 115.0f);
        }
        else {
            drawBar(x, y - 115.0f);
        }
        drawStage05Gauge(0);
        return true;
    }
    if (enemy.spawnType >= 0x50 && enemy.spawnType <= 0x52) {
        const double scale = enemy.drawHelperState == 0
                                 ? std::sin(static_cast<double>(std::clamp(
                                       enemy.drawHelperTimer, 0, 100)) *
                                       kPi / 200.0)
                                 : 1.0;
        int frame = 24;
        std::uint16_t angle = 0;
        if (enemy.spawnType == 0x51) {
            const double wave = std::sin(
                static_cast<double>(sourceFrame - 66) * kTau / 99.0);
            const bool left = enemy.originX < 0.0f;
            frame = left ? 26 : 25;
            angle = normalizeAngle16(static_cast<int>(
                wave * (left ? -700.0 : 700.0)));
        }
        else if (enemy.spawnType == 0x52) {
            const double wave = std::sin(
                static_cast<double>(sourceFrame - 33) * kTau / 99.0);
            const bool left = enemy.originX < 0.0f;
            frame = left ? 28 : 27;
            angle = normalizeAngle16(static_cast<int>(
                wave * (left ? -900.0 : 900.0)) +
                (left ? -10000 : 10000));
        }
        int brightness = 0xff;
        int alpha = 0xff;
        if (enemy.drawHelperState == 0) {
            const int timer = std::max(0, enemy.drawHelperTimer);
            brightness = timer < 100
                             ? static_cast<int>(std::sin(
                                   static_cast<double>(timer) * kPi / 200.0) *
                                   255.0)
                             : 0xff;
            alpha = timer < 10
                        ? static_cast<int>(std::sin(
                              static_cast<double>(timer) * kPi / 20.0) *
                              255.0)
                        : 0xff;
        }
        SetDrawBright(std::clamp(brightness, 0, 0xff),
                      std::clamp(brightness, 0, 0xff),
                      std::clamp(brightness, 0, 0xff));
        if (alpha < 0xff) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(alpha, 0, 0xff));
        }
        drawLargeExact(frame, x, y, angle, scale);
        if (exactLayer == 0x1f && enemy.drawHelperState == 0 &&
            enemy.drawHelperTimer < 100) {
            const int graph = frameHandle(enemyLargeFrames_, frame);
            if (graph != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ADD,
                                 std::clamp(255 - brightness, 0, 255));
                drawOriginalMode7Node(graph, x, y, angle,
                                      scale, scale, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
        if (alpha < 0xff) {
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        SetDrawBright(0xff, 0xff, 0xff);
        return true;
    }
    if (enemy.spawnType == 0x53) {
        const int timer = enemy.drawHelperTimer;
        const int sequence = std::clamp(enemy.childIndex, 1, 4);
        const int start = sequence * 20;
        int frame = 50 + (timer / 7) % 3;
        if (enemy.drawHelperState == 1 && timer >= start + 40) {
            frame = 55 + ((timer - (start + 40)) / 5) % 3;
        }
        else if (enemy.drawHelperState == 1 && timer >= start + 30) {
            frame = 53 + ((timer - (start + 30)) / 5) % 2;
        }
        double scaleX = 1.0;
        double scaleY = 1.0;
        int overlayAlpha = 0;
        if (enemy.drawHelperState == 0) {
            const int intro = std::clamp(timer, 0, 30);
            const double fold = std::sin(
                static_cast<double>(intro + 30) * kPi / 60.0);
            scaleX = 1.0 - fold;
            scaleY = 1.0 + fold;
            overlayAlpha = std::clamp(static_cast<int>(
                255.0 - std::sin(static_cast<double>(intro) *
                                 kPi / 60.0) * 255.0), 0, 0xff);
        }
        const int graph = frameHandle(bossFrames_, frame);
        if (graph != -1 && exactLayer == bodyLayer) {
            drawOriginalMode7Node(graph, x, y, 0,
                                  scaleX, scaleY, false);
            if (overlayAlpha > 0) {
                SetDrawBlendMode(DX_BLENDMODE_ADD, overlayAlpha);
                drawOriginalMode7Node(graph, x, y, 0,
                                      scaleX, scaleY, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
        return true;
    }
    if (enemy.spawnType == 0x54) { // FUN_1400210c0 draw state table
        static constexpr std::array<int, 3> kIdle{{50, 51, 52}};
        static constexpr std::array<int, 2> kWindup{{53, 54}};
        static constexpr std::array<int, 3> kAttack{{55, 56, 57}};
        static constexpr std::array<int, 2> kReturn{{54, 53}};

        const int timer = enemy.drawHelperTimer;
        int frame = loopingFrame(timer, 0, 7, kIdle);
        double scale = 1.0;
        if (enemy.drawHelperState == 0 && timer < 60) {
            scale = 0.4 + std::sin(static_cast<double>(timer) *
                                   kPi / 120.0) * 0.6;
        }
        if (enemy.drawHelperState == 1) {
            const int local = (timer - 0xac) % 700;
            if (local >= 0x78 && local < 0x82) {
                frame = loopingFrame(local, 0x78, 5, kWindup);
            }
            else if (local >= 0x82 && local < 0x2b3) {
                frame = loopingFrame(local, 0x82, 5, kAttack);
            }
            else if (local >= 0x2b3) {
                frame = loopingFrame(local, 0x2b3, 5, kReturn);
            }
        }
        drawBossExact(frame, x, y, scale);
        return true;
    }
    if (enemy.spawnType == 0x55) {
        const int timer = enemy.drawHelperTimer;
        const double scale = timer < 50
                                 ? std::sin(static_cast<double>(timer) *
                                            kPi / 100.0)
                                 : 1.0;
        drawSmallExact(57, x, y,
                       normalizeAngle16(timer * 0x29a), scale);
        return true;
    }
    if (enemy.spawnType == 0x56) { // FUN_140022120 draw state table
        static constexpr std::array<int, 3> kIdle{{50, 51, 52}};
        static constexpr std::array<int, 2> kWindup{{53, 54}};
        static constexpr std::array<int, 2> kReturn{{54, 53}};
        static constexpr std::array<int, 3> kAttack{{55, 56, 57}};

        const int timer = enemy.drawHelperTimer;
        int frame = loopingFrame(timer, 0, 7, kIdle);
        double scaleX = 1.0;
        double scaleY = 1.0;
        int overlayAlpha = 0;
        if (enemy.drawHelperState == 0) {
            const int intro = std::clamp(timer, 0, 30);
            const double fold = std::sin(
                static_cast<double>(intro + 30) * kPi / 60.0);
            scaleX = 1.0 - fold;
            scaleY = 1.0 + fold;
            overlayAlpha = std::clamp(static_cast<int>(
                255.0 - std::sin(static_cast<double>(intro) *
                                 kPi / 60.0) * 255.0), 0, 0xff);
        }
        else {
            const int local = timer % 0x4b0;
            if (local >= 0x1e && local < 0x28) {
                frame = loopingFrame(local, 0x1e, 5, kWindup);
            }
            else if ((local >= 0x28 && local < 0x168) ||
                     (local >= 0x1ae && local < 0x4a7)) {
                frame = loopingFrame(local, 0x28, 5, kAttack);
            }
            if (local >= 0x168 && local < 0x172) {
                frame = loopingFrame(local, 0x168, 5, kReturn);
            }
            if (local >= 0x1a4 && local < 0x1ae) {
                frame = loopingFrame(local, 0x1a4, 5, kWindup);
            }
            if (local >= 0x4a7) {
                frame = loopingFrame(local, 0x4a7, 5, kReturn);
            }
        }

        const int graph = frameHandle(bossFrames_, frame);
        if (graph != -1 && exactLayer == bodyLayer) {
            drawOriginalMode7Node(graph, x, y, 0,
                                  scaleX, scaleY, false);
            if (overlayAlpha > 0) {
                SetDrawBlendMode(DX_BLENDMODE_ADD, overlayAlpha);
                drawOriginalMode7Node(graph, x, y, 0,
                                      scaleX, scaleY, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
        return true;
    }

    if (enemy.spawnType == 0x4f) { // FUN_14009b5f0 draw tail
        const int timer = enemy.drawHelperTimer;
        double scale = 1.0;
        int brightness = 0xff;
        int alpha = 0xff;
        if (enemy.drawHelperState == 0) {
            if (timer < 0) {
                scale = 0.0;
            }
            else if (timer < 100) {
                scale = std::sin(static_cast<double>(timer) * kPi / 200.0);
                brightness = std::clamp(
                    static_cast<int>(scale * 255.0), 0, 0xff);
                if (timer < 10) {
                    alpha = std::clamp(static_cast<int>(std::sin(
                        static_cast<double>(timer) * kPi / 20.0) * 255.0),
                        0, 0xff);
                }
            }
        }
        const auto ornamentAngle = normalizeAngle16(static_cast<int>(
            std::sin(static_cast<double>(sourceFrame) * kTau / 99.0) *
            1000.0));
        const int body = frameHandle(enemyLargeFrames_, 22);
        const int ornament = frameHandle(enemyLargeFrames_, 23);
        SetDrawBright(brightness, brightness, brightness);
        if (alpha < 0xff) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        }
        if (ornament != -1 && exactLayer == bodyLayer) {
            drawOriginalMode7Node(
                ornament,
                x + static_cast<float>(scale * 128.0),
                y - static_cast<float>(scale * 95.0),
                ornamentAngle, scale, scale, false);
        }
        if (body != -1 && exactLayer == bodyLayer) {
            drawOriginalMode7Node(body, x, y, 0, scale, scale, false);
        }
        if (alpha < 0xff) {
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        SetDrawBright(0xff, 0xff, 0xff);
        drawStage05Gauge(0);
        return true;
    }

    int handle = -1;
    bool large = false;
    std::uint16_t bodyAngle = enemy.sourceAngle16;
    switch (spec->updateCase) {
    case 0x1c: handle = frameHandle(enemySmallFrames_, 53); break;
    case 0x32: handle = frameHandle(enemySmallFrames_, 46); break;
    case 0x33: handle = frameHandle(enemySmallFrames_, 48); break;
    case 0x34: handle = frameHandle(enemyMediumFrames_, 78); break;
    case 0x35: handle = frameHandle(enemyMediumFrames_, 81); break;
    case 0x36: handle = frameHandle(enemyMediumFrames_, 82); break;
    case 0x37: handle = frameHandle(enemyMediumFrames_, 80); break;
    case 0x38: handle = frameHandle(enemyMediumFrames_, 81); break;
    case 0x39: handle = frameHandle(enemyMediumFrames_, 93); break;
    case 0x3a: handle = frameHandle(enemyMediumFrames_, 86); break;
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
    case 0x3e:
    case 0x40:
        handle = frameHandle(
            bossFrames_, enemy.drawHelperState == 0
                             ? 50 + std::min(2, enemy.drawHelperTimer / 10)
                             : 53 + (enemy.drawHelperTimer / 5) % 3);
        break;
    case 0x3f:
        handle = frameHandle(bossFrames_,
                             50 + (enemy.drawHelperTimer / 5) % 3);
        break;
    case 0x6c: handle = frameHandle(enemySmallFrames_, 142); break;
    default: break;
    }

    if (handle != -1 && exactLayer == bodyLayer) {
        const bool exactUnscaledBody =
            enemy.spawnType >= 0x44 && enemy.spawnType <= 0x53;
        const double pulse = exactUnscaledBody
                                 ? 1.0
                                 : 1.0 + 0.03 *
                                       std::sin(enemy.drawHelperTimer * 0.08);
        const auto drawSmallPart = [this, exactLayer, bodyLayer](int frame,
                                           float drawX, float drawY,
                                           std::uint16_t angle,
                                           bool reverse = false) {
            if (exactLayer != bodyLayer) return;
            const int graph = frameHandle(enemySmallFrames_, frame);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      1.0, 1.0, reverse);
            }
        };
        const auto drawMediumPart = [this, exactLayer, bodyLayer](int frame,
                                            float drawX, float drawY,
                                            std::uint16_t angle,
                                            bool reverse = false) {
            if (exactLayer != bodyLayer) return;
            const int graph = frameHandle(enemyMediumFrames_, frame);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      1.0, 1.0, reverse);
            }
        };
        drawOriginalMode7Node(handle, x, y, bodyAngle,
                              pulse, pulse, false);

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
        if (large && exactLayer == bodyLayer) {
            const int core = frameHandle(effectMediumFrames_, 3);
            if (core != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ADD, 96);
                DrawRotaGraphF(x, y, 0.7, enemy.drawHelperTimer * 0.02,
                               core, TRUE);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
    }
    else if (exactLayer == bodyLayer) {
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
        drawEnemyGaugeExact(gauge, gaugeMode, x, y, exactLayer);
    }
    return true;
}

} // namespace reconstructed
