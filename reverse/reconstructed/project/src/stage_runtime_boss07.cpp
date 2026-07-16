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
constexpr std::size_t kStage07EntityCap = 0x200;

std::uint16_t normalizeStage07Angle(int angle) {
    return static_cast<std::uint16_t>(angle & 0xffff);
}

double stage07AngleRadians(std::uint16_t angle) {
    return static_cast<double>(angle) * kTau / 65536.0;
}

std::uint16_t stage07RadiansToAngle(double radians) {
    return normalizeStage07Angle(
        static_cast<int>(radians * 65536.0 / kTau));
}

std::uint16_t approachStage07Angle(std::uint16_t current,
                                   std::uint16_t target, int step) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return normalizeStage07Angle(
        static_cast<int>(current) + std::clamp(delta, -step, step));
}

std::uint32_t stage07ScriptRand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

double stage07RandomRange(int seed, double minimum, double maximum) {
    const int low = static_cast<int>(minimum * 100.0);
    const int high = static_cast<int>(maximum * 100.0);
    return static_cast<double>(
               low + static_cast<int>(stage07ScriptRand(seed) %
                                      static_cast<std::uint32_t>(high - low + 1))) /
           100.0;
}

float stage07PolarX(std::uint16_t angle, double radius) {
    return static_cast<float>(std::cos(stage07AngleRadians(angle)) * radius);
}

float stage07PolarY(std::uint16_t angle, double radius) {
    return static_cast<float>(std::sin(stage07AngleRadians(angle)) * radius);
}

double stage07Distance(float x1, float y1, float x2, float y2) {
    return std::hypot(static_cast<double>(x2 - x1),
                      static_cast<double>(y2 - y1));
}

int stage07NodeUpdateCase(int spawnType) {
    if (spawnType == 0x80) return 0x59;
    if (spawnType <= 0x82) return 0x5a;
    if (spawnType <= 0x84) return 0x5b;
    if (spawnType <= 0x86) return 0x5c;
    if (spawnType <= 0x88) return 0x5d;
    if (spawnType <= 0x8a) return 0x5e;
    if (spawnType <= 0x8e) return 0x5f;
    if (spawnType <= 0x92) return 0x60;
    return 0x61;
}

bool isStage07HeadType(int spawnType) {
    return spawnType == 0x83 || spawnType == 0x84;
}

bool isStage07FirstFormPart(int spawnType) {
    return spawnType >= 0x85 && spawnType <= 0x8a;
}

bool isStage07CombatState(int state) {
    return state == 1 || state == 0x0b || state == 0x0c ||
           state == 0x0d || state == 0x15 || state == 0x1f ||
           state == 0x29 || state == 0x33 || state == 0x3d;
}

int frameHandle07(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

} // namespace

bool StageRuntime::isStage07BossNodeType(int spawnType) const {
    return spawnType >= 0x80 && spawnType <= 0x94;
}

bool StageRuntime::spawnStage07BossNode(StageEnemy& parent, int spawnType,
                                        int childIndex, float offsetX,
                                        float offsetY,
                                        std::uint16_t angle16, double speed,
                                        int radius, int hitPoints) {
    if (!isStage07BossNodeType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kStage07EntityCap) {
        return false;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = stage07NodeUpdateCase(spawnType);
    node.sourceHitPoints = hitPoints;
    node.sourceX = static_cast<int>(std::lround(offsetX));
    node.sourceY = static_cast<int>(std::lround(offsetY));
    node.sourceNote = "S07 FUN_14002b680 recovered boss apparatus";
    node.sourceDispatchKind = 1;
    node.sourceDispatchField = radius;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = parent.spawnType;
    node.childIndex = childIndex;
    node.originX = offsetX;
    node.originY = offsetY;
    node.sourceAngle16 = angle16;
    node.secondaryAngle16 = angle16;
    node.targetAngle16 = angle16;
    node.angle = static_cast<float>(stage07AngleRadians(angle16));
    node.sourceSpeed = speed;
    node.speed = static_cast<float>(speed);
    node.hp = hitPoints;
    node.maxHp = hitPoints;
    node.drawHp = hitPoints;
    node.radius = radius;
    node.activationDelay = 0;
    node.rewardWeight = 0;
    node.targetable = false;

    if (spawnType == 0x80) {
        // FUN_140032040 receives screen-space anchors during the intro.
        node.x = offsetX;
        node.y = offsetY;
    }
    else {
        node.x = parent.x + offsetX;
        node.y = parent.y + offsetY;
    }
    node.markerDrawX = node.x;
    node.markerDrawY = node.y;
    pendingEnemies_.push_back(node);
    return true;
}

void StageRuntime::updateStage07Boss(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);

    const auto findHead = [this, &enemy](int index) -> StageEnemy* {
        for (auto& candidate : enemies_) {
            if (candidate.parentEntityId == enemy.entityId &&
                isStage07HeadType(candidate.spawnType) &&
                candidate.childIndex == index) {
                return &candidate;
            }
        }
        return nullptr;
    };

    const auto openPhase = [this, &enemy](int state, int hitPoints,
                                          int countdown, int phaseIndex) {
        enemy.helperState = state;
        enemy.helperTimer = 0;
        enemy.hp = hitPoints;
        enemy.maxHp = hitPoints;
        enemy.drawHp = hitPoints;
        // The 0x13e entity is only the controller. FUN_14002d2f0 clears the
        // collision-disable flag on the apparatus nodes, not on this root.
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        lateStageBossMaxHp_ = hitPoints;
        lateStageBossCountdown_ = countdown;
        lateStageBossCountdownDraw_ = countdown;
        lateStageBossPhaseIndex_ = phaseIndex;
        lateStageBossPhaseMode_ = 1;
    };

    if (lateStageBossPhaseMode_ == 1 &&
        (enemy.hp < 1 || lateStageBossCountdown_ < 1)) {
        StageEnemy* first = findHead(0);
        StageEnemy* second = findHead(1);
        const int firstHp = first != nullptr ? first->hp : 0;
        const int secondHp = second != nullptr ? second->hp : 0;
        const int combatState = enemy.helperState;
        const bool expired = lateStageBossCountdown_ < 1;
        const auto emitBreakFeedback = [this, expired](const StageEnemy& source) {
            if (expired) {
                flushEnemyProjectilesToEffects();
                player_.invulnerableFrames =
                    std::max(player_.invulnerableFrames, 100);
            }
            else {
                spawnPlayerSideObject(0x18, source.x, source.y,
                                      0.0, 0, 0, 0.0f);
            }
            spawnBossPhaseBreakFeedback(source, lateStageBossCountdown_);
        };

        enemy.targetable = false;
        enemy.targetableTimer = 0;
        enemy.helperTimer = 0;

        switch (lateStageBossBreaksRemaining_) {
        case 5:
            emitBreakFeedback(enemy);
            spawnPostDeathCounterEntity(enemy, 140.0);
            enemy.helperState = 10;
            lateStageBossPhaseMode_ = 2;
            break;
        case 4: {
            const bool firstLost = firstHp < secondHp;
            StageEnemy* lost = firstLost ? first : second;
            if (lost != nullptr) {
                spawnStage07BossNode(
                    enemy, firstLost ? 0x81 : 0x82,
                    firstLost ? 0 : 1, lost->x - enemy.x,
                    lost->y - enemy.y, 0x4000, 0.0, 80, 99999999);
                emitBreakFeedback(*lost);
                spawnPostDeathCounterEntity(*lost, 140.0);
                spawnEnemyDeathEffects(*lost, 1);
            }
            else {
                emitBreakFeedback(enemy);
                spawnPostDeathCounterEntity(enemy, 140.0);
            }
            enemy.helperState = firstLost ? 40 : 20;
            lateStageBossPhaseMode_ = 2;
            break;
        }
        case 3:
            if (combatState == 0x15) {
                if (first != nullptr) {
                    emitBreakFeedback(*first);
                    spawnPostDeathCounterEntity(*first, 140.0);
                    spawnEnemyDeathEffects(*first, 1);
                }
                else {
                    emitBreakFeedback(enemy);
                    spawnPostDeathCounterEntity(enemy, 140.0);
                }
                enemy.helperState = 30;
            }
            else {
                if (second != nullptr) {
                    emitBreakFeedback(*second);
                    spawnPostDeathCounterEntity(*second, 140.0);
                    spawnEnemyDeathEffects(*second, 1);
                }
                else {
                    emitBreakFeedback(enemy);
                    spawnPostDeathCounterEntity(enemy, 140.0);
                }
                enemy.helperState = 50;
            }
            lateStageBossPhaseMode_ = 2;
            break;
        case 2: {
            StageEnemy* broken = combatState == 0x1f ? first : second;
            const StageEnemy& source = broken != nullptr ? *broken : enemy;
            emitBreakFeedback(source);
            spawnPostDeathCounterEntity(source, 140.0);
            enemy.helperState = combatState == 0x1f ? 59 : 60;
            lateStageBossPhaseMode_ = 2;
            break;
        }
        case 1:
            if (first != nullptr) {
                emitBreakFeedback(*first);
                spawnPostDeathCounterEntity(*first, 140.0);
            }
            if (second != nullptr) {
                emitBreakFeedback(*second);
                spawnPostDeathCounterEntity(*second, 140.0);
            }
            if (first == nullptr && second == nullptr) {
                emitBreakFeedback(enemy);
                spawnPostDeathCounterEntity(enemy, 140.0);
            }
            if (first != nullptr) spawnEnemyDeathEffects(*first, 1);
            if (second != nullptr) spawnEnemyDeathEffects(*second, 1);
            enemy.helperState = 70;
            lateStageBossPhaseMode_ = -1;
            lateStageClearStarted_ = true;
            lateStageClearTimer_ = 0;
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 360);
            break;
        default:
            break;
        }
        lateStageBossBreaksRemaining_ =
            std::max(0, lateStageBossBreaksRemaining_ - 1);
        lateStageBossPhaseIndex_ =
            std::min(4, lateStageBossPhaseIndex_ + 1);
    }

    if (frame_ % 50 == 0) {
        lateStageBossTargetX_ = 260.0f + static_cast<float>(
            stage07ScriptRand(frame_) % 201u);
        lateStageBossTargetY_ = 230.0f + static_cast<float>(
            stage07ScriptRand(frame_ + difficulty * 0xde) % 51u);
    }

    const int timer = enemy.helperTimer;
    switch (enemy.helperState) {
    case 0:
        if (timer == 0) {
            // Exact FUN_14002b680 constructor order. The coordinates are
            // offsets from the root except for the four 0x80 intro trails.
            spawnStage07BossNode(enemy, 0x83, 0, -80.0f, 0.0f,
                                 0x4000, 0.3, 70, 99999999);
            spawnStage07BossNode(enemy, 0x84, 1, 80.0f, 0.0f,
                                 0x4000, 0.3, 70, 99999999);
            spawnStage07BossNode(enemy, 0x85, 2, -115.0f, -120.0f,
                                 0x4000, 1.0, 50, 99999999);
            spawnStage07BossNode(enemy, 0x86, 3, 115.0f, -120.0f,
                                 0x4000, 1.0, 50, 99999999);
            spawnStage07BossNode(enemy, 0x87, 4, 230.0f, -70.0f,
                                 0x4000, 1.0, 60, 20000);
            spawnStage07BossNode(enemy, 0x87, 5, -230.0f, -70.0f,
                                 0x4000, 1.0, 60, 20000);
            spawnStage07BossNode(enemy, 0x88, 6, 70.0f, 145.0f,
                                 0x4000, 1.0, 24, 10000);
            spawnStage07BossNode(enemy, 0x88, 7, -70.0f, 145.0f,
                                 0x4000, 1.0, 24, 10000);
            spawnStage07BossNode(enemy, 0x88, 8, 185.0f, 115.0f,
                                 0x4000, 1.0, 24, 10000);
            spawnStage07BossNode(enemy, 0x88, 9, -185.0f, 115.0f,
                                 0x4000, 1.0, 24, 10000);
            spawnStage07BossNode(enemy, 0x89, 10, 50.0f, -190.0f,
                                 0x4000, 1.0, 20, 99999999);
            spawnStage07BossNode(enemy, 0x8a, 11, -50.0f, -190.0f,
                                 0x4000, 1.0, 20, 99999999);
            spawnStage07BossNode(enemy, 0x8a, 12, 200.0f, -190.0f,
                                 0x4000, 1.0, 20, 99999999);
            spawnStage07BossNode(enemy, 0x89, 13, -200.0f, -190.0f,
                                 0x4000, 1.0, 20, 99999999);
            spawnStage07BossNode(enemy, 0x80, 14, 460.0f, 800.0f,
                                 0x4000, 1.0, 30, 99999999);
            spawnStage07BossNode(enemy, 0x80, 15, 265.0f, 800.0f,
                                 0x4000, 1.0, 30, 99999999);
            playPlayerSound(bossSe8SoundHandle_, 0x19);
        }
        if (timer == 20) {
            spawnStage07BossNode(enemy, 0x80, 16, 110.0f, 800.0f,
                                 0x4000, 1.0, 30, 99999999);
            spawnStage07BossNode(enemy, 0x80, 17, 610.0f, 800.0f,
                                 0x4000, 1.0, 30, 99999999);
        }
        if (timer == 80) {
            playPlayerSound(bossSe7SoundHandle_, 0x19);
        }
        if (timer < 80) {
            enemy.y = 1000.0f;
        }
        else if (timer < 200) {
            const double t = static_cast<double>(timer - 80) / 120.0;
            enemy.y = 1000.0f + static_cast<float>(
                (250.0 - 1000.0) * (0.5 - std::cos(t * kPi) * 0.5));
        }
        else {
            enemy.y += 0.1f;
        }
        if (timer == 240) {
            lateStageBossBreaksRemaining_ = 5;
            openPhase(1, 148000, 3600, 0);
        }
        break;
    case 1: {
        enemy.targetable = false;
        const auto target = stage07RadiansToAngle(std::atan2(
            static_cast<double>(lateStageBossTargetY_ - enemy.y),
            static_cast<double>(lateStageBossTargetX_ - enemy.x)));
        enemy.sourceAngle16 = approachStage07Angle(
            enemy.sourceAngle16, target, 0x200);
        const double radians = stage07AngleRadians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * 0.2);
        enemy.y += static_cast<float>(std::sin(radians) * 0.2);
        break;
    }
    case 10:
        enemy.targetable = false;
        if (timer < 90) {
            enemy.y += static_cast<float>(timer) * 0.05f;
        }
        if (timer == 1 || timer == 90) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 90) playPlayerSound(blast1SoundHandle_, 0x19);
        if (timer == 390) openPhase(0x0b, 70000, 2100, 1);
        break;
    case 0x0b:
    case 0x0c:
    case 0x0d: {
        enemy.targetable = false;
        StageEnemy* first = findHead(0);
        StageEnemy* second = findHead(1);
        enemy.hp = std::max(0, first != nullptr ? first->hp : 0) +
                   std::max(0, second != nullptr ? second->hp : 0);
        break;
    }
    case 0x14:
    case 0x1e:
    case 0x28:
    case 0x32:
    case 0x3b:
    case 0x3c:
        enemy.targetable = false;
        if (timer == 180) {
            const int hitPoints = enemy.helperState >= 0x3b ? 80000 : 70000;
            openPhase(enemy.helperState >= 0x3b
                          ? 0x3d
                          : enemy.helperState + 1,
                      hitPoints, 2100,
                      std::clamp(5 - lateStageBossBreaksRemaining_, 1, 4));
        }
        break;
    case 0x15:
    case 0x1f:
    case 0x29:
    case 0x33:
    case 0x3d: {
        enemy.targetable = false;
        StageEnemy* first = findHead(0);
        StageEnemy* second = findHead(1);
        const int firstHp = first != nullptr ? first->hp : 0;
        const int secondHp = second != nullptr ? second->hp : 0;
        enemy.hp = std::max(0, std::min(firstHp, secondHp));
        break;
    }
    case 70:
        enemy.targetable = false;
        if (timer < 240 && timer % 3 == 0) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 240) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnEnemyDeathEffects(enemy, 2);
        }
        if (timer >= 480) {
            clearLateStageGate(7);
            enemy.active = false;
        }
        break;
    default:
        break;
    }

    enemy.drawHp = enemy.hp;
    lateStageBossCountdownDraw_ = lateStageBossCountdown_;
    if (lateStageBossPhaseMode_ == 1 &&
        isStage07CombatState(enemy.helperState)) {
        updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
        --lateStageBossCountdown_;
    }
    (void)difficulty;
}

void StageRuntime::updateStage07BossNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawMarkerThisFrame = false;
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    StageEnemy* root = parent;
    if (root != nullptr && root->spawnType != 0x13e) {
        root = findEnemyById(root->parentEntityId);
    }
    if (root == nullptr || root->spawnType != 0x13e || !root->active) {
        enemy.targetable = false;
        enemy.active = false;
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto aimAtPlayer = [this](float x, float y) {
        return stage07RadiansToAngle(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto fireSound = [this]() {
        playPlayerSound(bullet2SoundHandle_, 0x13);
    };

    if (enemy.spawnType == 0x80) {
        const int timer = enemy.helperTimer;
        const int amplitude = ((enemy.entityId - root->entityId) & 1) == 0
                                  ? 4000
                                  : -4000;
        enemy.sourceAngle16 = normalizeStage07Angle(
            0x4000 - static_cast<int>(
                std::sin(static_cast<double>(timer) * kTau / 328.0) *
                amplitude));

        float baseY = -100.0f;
        if (timer >= 0 && timer < 120) {
            baseY = 800.0f - 900.0f * static_cast<float>(
                std::sin(static_cast<double>(timer) * kPi / 240.0));
        }
        if (enemy.helperState == 0 && root->helperState == 70 &&
            root->helperTimer == 1) {
            enemy.helperState = 1;
        }
        if (enemy.helperState == 1) {
            baseY = enemy.markerDrawY + root->helperTimer * 0.15f;
            if (root->helperTimer == 80) {
                spawnEnemyDeathEffects(enemy, 0, false);
                enemy.active = false;
            }
        }
        enemy.markerDrawX = enemy.originX;
        enemy.markerDrawY = baseY;
        enemy.markerDrawTimer = root->helperTimer;
        enemy.x = enemy.originX + stage07PolarX(enemy.sourceAngle16, 20.0);
        enemy.y = baseY + 24.0f + stage07PolarY(enemy.sourceAngle16, 20.0);
        return;
    }

    if (enemy.spawnType == 0x81 || enemy.spawnType == 0x82) {
        enemy.targetable = false;
        if (enemy.helperTimer == 1) {
            spawnEnemyDeathEffects(enemy, 0, false);
        }
        if (enemy.helperTimer < 90) {
            spawnStage02DeathExplosionChain(enemy);
        }
        enemy.y += static_cast<float>(enemy.helperTimer) * 0.1f;
        if (root->helperState == 70) enemy.active = false;
        return;
    }

    if (isStage07HeadType(enemy.spawnType)) {
        const int previousState = enemy.helperState;
        const int state = root->helperState;
        const int timer = root->helperTimer;
        const bool phaseEntry = previousState != state || timer <= 1;
        enemy.helperState = state;
        enemy.helperTimer = timer;

        if (phaseEntry) {
            int hitPoints = root->hp;
            if (state >= 0x0b && state <= 0x0d) {
                hitPoints = std::max(1, root->hp / 2);
            }
            if (isStage07CombatState(state)) {
                enemy.hp = hitPoints;
                enemy.maxHp = hitPoints;
                enemy.sourceHitPoints = hitPoints;
            }
        }

        if (state == 1 && !phaseEntry) {
            const int damage = std::max(0, enemy.sourceHitPoints - enemy.hp);
            if (damage > 0) root->hp = std::max(0, root->hp - damage);
            enemy.hp = std::min(enemy.hp, root->hp);
            enemy.sourceHitPoints = enemy.hp;
        }

        const bool leftHead = enemy.spawnType == 0x83;
        const bool headEnabled = state == 1 || state == 0x0b ||
            (state == 0x0c && leftHead) ||
            (state == 0x0d && !leftHead) || state == 0x3d ||
            ((state == 0x15 || state == 0x1f) && leftHead) ||
            ((state == 0x29 || state == 0x33) && !leftHead);
        enemy.targetable = isStage07CombatState(state) &&
                           headEnabled && enemy.hp > 0;
        enemy.drawBodyThisFrame = headEnabled || !isStage07CombatState(state);
        if (state == 70) {
            enemy.targetable = false;
            if (timer >= 220) enemy.active = false;
        }

        const int side = leftHead ? -1 : 1;
        const bool transitionState = state == 0x14 || state == 0x1e ||
            state == 0x28 || state == 0x32 || state == 0x3b || state == 0x3c;
        const bool attached = state <= 1 || (state == 10 && timer < 100);
        if (attached) {
            enemy.x = root->x + enemy.originX;
            enemy.y = root->y + enemy.originY;
        }
        else if (!transitionState) {
            if (frame_ % 50 == 0) {
                const bool wideRange = state > 0x14 && state < 0x3b;
                const int xBase = leftHead
                                      ? 210
                                      : (wideRange ? 310 : 410);
                const int xRange = wideRange ? 201 : 101;
                enemy.sourceX = xBase + static_cast<int>(
                    stage07ScriptRand(frame_ + enemy.childIndex * 0x6f) %
                    static_cast<std::uint32_t>(xRange));
                enemy.sourceY = 200 + static_cast<int>(
                    stage07ScriptRand(frame_ + enemy.childIndex * 0x14d) % 51u);
            }
            const auto travelTarget = stage07RadiansToAngle(std::atan2(
                static_cast<double>(enemy.sourceY - enemy.y),
                static_cast<double>(enemy.sourceX - enemy.x)));
            enemy.sourceAngle16 = approachStage07Angle(
                enemy.sourceAngle16, travelTarget, 0x200);
            const double travel = stage07AngleRadians(enemy.sourceAngle16);
            enemy.x += static_cast<float>(
                std::cos(travel) * enemy.sourceSpeed);
            enemy.y += static_cast<float>(
                std::sin(travel) * enemy.sourceSpeed);
        }

        if (transitionState) {
            const bool dyingHead =
                ((state == 0x14 || state == 0x1e || state == 0x3b) &&
                 leftHead) ||
                ((state == 0x28 || state == 0x32 || state == 0x3c) &&
                 !leftHead);
            if (dyingHead) {
                enemy.targetable = false;
                if (timer < 90) spawnStage02DeathExplosionChain(enemy);
                enemy.y += 0.1f;
            }
            else if ((state == 0x14 && !leftHead) ||
                     (state == 0x28 && leftHead)) {
                enemy.x = 0.0f;
                enemy.y = 30000.0f;
            }
            else if (state == 0x3b || state == 0x3c) {
                enemy.x = leftHead ? 220.0f : 500.0f;
                enemy.y = 900.0f - 660.0f * static_cast<float>(
                    std::sin(static_cast<double>(timer) * kPi / 360.0));
            }
        }

        if (!enemy.targetable) return;

        const double muzzleOrbit = static_cast<double>(frame_) *
                                   399.609756097561 * kPi / 32768.0;
        const float shotX = enemy.x +
                            static_cast<float>(std::cos(muzzleOrbit) * 24.0);
        const float shotY = enemy.y - 120.0f +
                            static_cast<float>(std::sin(muzzleOrbit) * 24.0);
        const auto shotAim = [&]() { return aimAtPlayer(shotX, shotY); };
        bool firedQuiet = false;
        bool firedLoud = false;
        if (state >= 0x0b && state <= 0x0d) {
            const int cycle = timer % 1200;
            const auto index = static_cast<std::size_t>(difficulty);
            static constexpr std::array<int, 5> kOpeningCount{{
                17, 21, 23, 25, 27,
            }};
            static constexpr std::array<int, 5> kOpeningWindow{{
                15, 25, 35, 45, 45,
            }};
            static constexpr std::array<int, 5> kOpeningTurn{{
                180, 250, 300, 360, 420,
            }};
            static constexpr std::array<double, 5> kOpeningSpeed{{
                5.0, 6.0, 6.5, 7.0, 8.0,
            }};
            if (cycle >= 40 && cycle < 320) {
                const int local = cycle - 40;
                if (local % 80 == 0) enemy.secondaryAngle16 = shotAim();
                const int burstFrame = local % 80;
                const int window = kOpeningWindow[index] +
                                   (state == 0x0b ? 0 : 10);
                if (burstFrame < window && burstFrame % 5 == 0) {
                    const bool alternate = local % 160 < 80;
                    const int subtype = leftHead ? (alternate ? 9 : 0)
                                                 : (alternate ? 0 : 9);
                    spawnProjectileSpread(
                        leftHead ? 2 : 3, subtype, shotX, shotY,
                        enemy.secondaryAngle16, 10.0f,
                        kOpeningSpeed[index] + local * 0.008, 1,
                        kOpeningCount[index], 0x10000, 0);
                    const int turn = kOpeningTurn[index] + local;
                    enemy.secondaryAngle16 = normalizeStage07Angle(
                        static_cast<int>(enemy.secondaryAngle16) +
                        (leftHead ? turn : -turn));
                    firedQuiet = true;
                }
            }

            static constexpr std::array<int, 5> kMiddleCadence{{
                12, 9, 7, 6, 6,
            }};
            static constexpr std::array<int, 5> kMiddleCount{{
                4, 6, 7, 9, 10,
            }};
            static constexpr std::array<int, 5> kMiddleSpreadStep{{
                1500, 1500, 1300, 1000, 900,
            }};
            static constexpr std::array<int, 5> kMiddleTurn{{
                400, 680, 750, 750, 750,
            }};
            static constexpr std::array<double, 5> kMiddleSpeed{{
                5.5, 6.5, 7.0, 7.5, 7.5,
            }};
            static constexpr std::array<double, 5> kLayerDrop{{
                0.9, 0.8, 0.7, 0.6, 0.6,
            }};
            if (cycle >= 360 && cycle < 540) {
                int cadence = kMiddleCadence[index];
                if (state != 0x0b) {
                    static constexpr std::array<int, 5> kSoloCadence{{
                        8, 6, 5, 4, 4,
                    }};
                    cadence = kSoloCadence[index];
                }
                if (cycle == 360) enemy.secondaryAngle16 = 0xc000;
                if ((cycle - 360) % cadence == 0) {
                    const int selector = leftHead
                                             ? (difficulty > 2 ? 4 : 2)
                                             : (difficulty > 2 ? 5 : 3);
                    spawnProjectileNode(
                        selector, 0, shotX, shotY,
                        enemy.secondaryAngle16, 10.0f,
                        kMiddleSpeed[index], 1, 0);
                    int spread = 0;
                    for (int layer = 0; layer < kMiddleCount[index]; ++layer) {
                        spawnProjectileSpread(
                            selector, 0, shotX, shotY,
                            enemy.secondaryAngle16, 10.0f,
                            kMiddleSpeed[index] - layer * kLayerDrop[index],
                            1, 2, spread, 0);
                        spread += kMiddleSpreadStep[index];
                    }
                    firedQuiet = true;
                }
                enemy.secondaryAngle16 = normalizeStage07Angle(
                    static_cast<int>(enemy.secondaryAngle16) +
                    (leftHead ? -kMiddleTurn[index] : kMiddleTurn[index]));
            }

            if (cycle >= 600 && cycle < 1160 && leftHead) {
                static constexpr std::array<int, 5> kCadence{{
                    40, 30, 24, 20, 16,
                }};
                static constexpr std::array<int, 5> kCount{{
                    7, 9, 11, 13, 13,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    5.0, 5.5, 6.0, 6.0, 7.2,
                }};
                const int cadence = kCadence[index];
                const int count = kCount[index];
                const double speed = kSpeed[index] + (cycle - 600) * 0.005;
                const auto aim = shotAim();
                const auto fireLeftFan = [&](int fanCount, int spread) {
                    spawnProjectileSpread(
                        4, 10, shotX, shotY, aim, 10.0f, speed, 1,
                        fanCount, spread, 0);
                    if (state == 0x0c) {
                        spawnProjectileSpread(
                            4, 10, shotX, shotY, aim, 10.0f, speed, 1,
                            fanCount, spread, 0);
                        spawnProjectileSpread(
                            4, 10, shotX, shotY,
                            normalizeStage07Angle(static_cast<int>(aim) - 600),
                            10.0f, speed, 1, fanCount, spread, 0);
                    }
                };
                if ((cycle - 600) % (cadence * 2) == 0) {
                    fireLeftFan(count, 44000);
                    firedQuiet = true;
                }
                if (cycle >= 600 + cadence &&
                    (cycle - (600 + cadence)) % (cadence * 2) == 0) {
                    const int fanCount = count - 1;
                    fireLeftFan(fanCount,
                                (44000 / fanCount) * (fanCount - 1));
                    firedQuiet = true;
                }
            }
            if (cycle >= 600 && cycle < 1160 && !leftHead) {
                static constexpr std::array<int, 5> kCadence{{
                    110, 78, 60, 50, 50,
                }};
                static constexpr std::array<int, 5> kCount{{
                    3, 5, 7, 9, 11,
                }};
                static constexpr std::array<int, 5> kSpreadStep{{
                    4500, 3300, 2700, 2400, 2000,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    6.0, 6.5, 7.0, 7.0, 8.0,
                }};
                const int cadence = kCadence[index];
                if (cycle >= 660 && (cycle - 660) % cadence == 0) {
                    enemy.secondaryAngle16 = shotAim();
                }
                if (cycle >= 660) {
                    const int local = (cycle - 660) % cadence;
                    const double speed = kSpeed[index] + local * 0.08;
                    const auto fireRightFan = [&](int count) {
                        const int spread = (count - 1) * kSpreadStep[index];
                        spawnProjectileSpread(
                            9, 0, shotX, shotY, enemy.secondaryAngle16,
                            10.0f, speed, 1, count, spread, 0);
                        if (state == 0x0d) {
                            spawnProjectileSpread(
                                9, 0, shotX, shotY,
                                enemy.secondaryAngle16, 10.0f, speed - 0.5,
                                1, count, spread, 0);
                            spawnProjectileSpread(
                                9, 0, shotX, shotY,
                                normalizeStage07Angle(
                                    static_cast<int>(enemy.secondaryAngle16) -
                                    400),
                                10.0f, speed - 0.5, 1, count, spread, 0);
                        }
                    };
                    const int first = (cycle - 660) % (cadence * 2);
                    if (first < 50 && first % 5 == 0) {
                        fireRightFan(kCount[index]);
                        firedQuiet = true;
                    }
                    const int secondStart = 660 + cadence;
                    if (cycle >= secondStart) {
                        const int second =
                            (cycle - secondStart) % (cadence * 2);
                        if (second < 50 && second % 5 == 0) {
                            fireRightFan(kCount[index] - 1);
                            firedQuiet = true;
                        }
                    }
                }
                enemy.secondaryAngle16 = approachStage07Angle(
                    enemy.secondaryAngle16, shotAim(), 0x10);
            }
        }
        else if (state == 0x15) {
            const auto index = static_cast<std::size_t>(difficulty);
            if (timer % 0x35c == 10) {
                spawnStage07BossNode(
                    enemy, timer - 100 < 0x385 ? 0x90 : 0x8f,
                    timer / 0x35c, 0.0f, 0.0f,
                    timer - 100 < 0x385 ? 0x8000 : 0,
                    1.0, 100, 99999999);
                firedLoud = true;
            }
            static constexpr std::array<int, 5> kWindow{{
                20, 25, 30, 40, 40,
            }};
            static constexpr std::array<int, 5> kCount{{
                15, 19, 23, 25, 27,
            }};
            static constexpr std::array<int, 5> kTurn{{
                320, 420, 460, 480, 500,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                5.6, 6.4, 7.0, 7.7, 8.5,
            }};
            const int cycle = timer % 0x35c;
            const int start = cycle >= 0x2f8 ? 0x2f8 : 0x294;
            if (cycle == 0x294 || cycle == 0x2f8) {
                enemy.secondaryAngle16 = shotAim();
            }
            if (cycle >= start &&
                cycle < start + kWindow[index] &&
                (cycle - start) % 5 == 0) {
                spawnProjectileSpread(
                    3, start == 0x294 ? 0x21 : 0x22,
                    shotX, shotY, enemy.secondaryAngle16,
                    10.0f, kSpeed[index], 1, kCount[index],
                    0x10000, 0);
                enemy.secondaryAngle16 = normalizeStage07Angle(
                    static_cast<int>(enemy.secondaryAngle16) +
                    (start == 0x294 ? -kTurn[index] : kTurn[index]));
                firedQuiet = true;
            }
        }
        else if (state == 0x1f) {
            if (timer >= 10 && timer < 90 && (timer - 10) % 3 == 0) {
                const std::uint32_t random = stage07ScriptRand(timer);
                const int angle =
                    static_cast<std::int16_t>(random / 0xbb81u) * 0x447f +
                    static_cast<std::int16_t>(random) + 0x6240;
                spawnStage07BossNode(
                    enemy, 0x93, timer, shotX - enemy.x,
                    shotY - enemy.y, normalizeStage07Angle(angle),
                    5.0, 20, 99999999);
                firedQuiet = true;
            }
            if (timer > 100) {
                const auto index = static_cast<std::size_t>(difficulty);
                static constexpr std::array<int, 5> kPeriod{{
                    240, 180, 160, 160, 150,
                }};
                static constexpr std::array<int, 5> kTopCadence{{
                    9, 6, 5, 5, 5,
                }};
                static constexpr std::array<int, 5> kSideCadence{{
                    11, 8, 7, 7, 7,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    3.0, 4.0, 4.0, 4.0, 5.0,
                }};
                const int elapsed = timer - 100;
                const int period = kPeriod[index];
                const int phase = elapsed % (period * 4);
                const int local = elapsed % period;
                if (phase < 60 && phase % kTopCadence[index] == 0) {
                    spawnProjectileNode(
                        0x13, 0x23, local * 12.0f, 0.0f,
                        normalizeStage07Angle(0x4000 - local * 120 + 3200),
                        0.0f, kSpeed[index], 1, 0);
                    firedLoud = true;
                }
                if (phase >= period && phase < period + 60 &&
                    (phase - period) % kTopCadence[index] == 0) {
                    spawnProjectileNode(
                        0x13, 0x23,
                        720.0f - local * 12.0f +
                            kTopCadence[index] * 6.0f,
                        0.0f,
                        normalizeStage07Angle(local * 120 + 0x3380),
                        0.0f, kSpeed[index], 1, 0);
                    firedLoud = true;
                }
                if (phase >= period * 2 && phase < period * 2 + 60 &&
                    (phase - period * 2) % kSideCadence[index] == 0) {
                    spawnProjectileNode(
                        0x13, 0x24, 720.0f, local * 12.0f,
                        normalizeStage07Angle(
                            0x8000 - (local * 60 - 1000)),
                        0.0f, kSpeed[index], 1, 0);
                    firedLoud = true;
                }
                if (phase >= period * 3 && phase < period * 3 + 60 &&
                    (phase - period * 3) % kSideCadence[index] == 0) {
                    spawnProjectileNode(
                        0x13, 0x24, 0.0f, local * 12.0f,
                        normalizeStage07Angle(local * 60 - 1000),
                        0.0f, kSpeed[index], 1, 0);
                    firedLoud = true;
                }
            }
        }
        else if (state == 0x29) {
            const auto index = static_cast<std::size_t>(difficulty);
            if (timer % 0x35c == 10) {
                spawnStage07BossNode(
                    enemy, timer - 100 < 0x385 ? 0x92 : 0x91,
                    timer / 0x35c, 0.0f, 0.0f,
                    timer - 100 < 0x385 ? 0 : 0x8000,
                    1.0, 100, 99999999);
                firedLoud = true;
            }
            static constexpr std::array<int, 5> kInterval{{
                4, 3, 2, 2, 2,
            }};
            static constexpr std::array<int, 5> kCount{{
                5, 6, 6, 7, 8,
            }};
            static constexpr std::array<int, 5> kTurn{{
                3500, 4300, 3200, 3900, 3200,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                5.0, 6.0, 6.5, 7.0, 8.0,
            }};
            const int cycle = timer % 0x35c;
            const int start = cycle >= 0x2f8 ? 0x2f8 : 0x294;
            if (cycle == 0x294 || cycle == 0x2f8) {
                enemy.secondaryAngle16 = shotAim();
            }
            if (cycle >= start && cycle < start + 40 &&
                (cycle - start) % kInterval[index] == 0) {
                spawnProjectileSpread(
                    3, start == 0x294 ? 0x22 : 0x21,
                    shotX, shotY, enemy.secondaryAngle16,
                    10.0f, kSpeed[index], 1, kCount[index],
                    0x10000, 0);
                enemy.secondaryAngle16 = normalizeStage07Angle(
                    static_cast<int>(enemy.secondaryAngle16) +
                    (start == 0x294 ? -kTurn[index] : kTurn[index]));
                firedQuiet = true;
            }
        }
        else if (state == 0x33) {
            const auto index = static_cast<std::size_t>(difficulty);
            static constexpr std::array<int, 5> kSegment{{
                120, 90, 70, 70, 70,
            }};
            static constexpr std::array<int, 5> kRest{{
                800, 800, 660, 660, 580,
            }};
            static constexpr std::array<int, 5> kPathCadence{{
                11, 7, 6, 5, 4,
            }};
            const int segment = kSegment[index];
            const int cycle = (timer - 10) % (kRest[index] + segment * 5);
            static constexpr std::array<std::array<float, 2>, 5> kStart{{
                {{30.0f, 0.0f}},
                {{0.0f, 0.0f}},
                {{690.0f, 0.0f}},
                {{720.0f, 0.0f}},
                {{30.0f, 720.0f}},
            }};
            static constexpr std::array<std::array<float, 2>, 5> kEnd{{
                {{690.0f, 0.0f}},
                {{0.0f, 720.0f}},
                {{30.0f, 0.0f}},
                {{720.0f, 720.0f}},
                {{690.0f, 720.0f}},
            }};
            const auto aimPoint = [&](float x, float y) {
                return stage07RadiansToAngle(std::atan2(
                    static_cast<double>(y - shotY),
                    static_cast<double>(x - shotX)));
            };
            if (cycle >= 0 && cycle < segment * 5) {
                const int path = cycle / segment;
                const int local = cycle % segment;
                if (local == 0) {
                    enemy.secondaryAngle16 =
                        aimPoint(kStart[static_cast<std::size_t>(path)][0],
                                 kStart[static_cast<std::size_t>(path)][1]);
                    enemy.targetAngle16 =
                        aimPoint(kEnd[static_cast<std::size_t>(path)][0],
                                 kEnd[static_cast<std::size_t>(path)][1]);
                }
                if (local < 40 && local % kPathCadence[index] == 0) {
                    int delta = static_cast<int>(enemy.targetAngle16) -
                                static_cast<int>(enemy.secondaryAngle16);
                    if (delta > 0x8000) delta -= 0x10000;
                    if (delta < -0x8000) delta += 0x10000;
                    const auto angle = normalizeStage07Angle(
                        static_cast<int>(enemy.secondaryAngle16) +
                        (delta / 40) * local);
                    spawnStage07BossNode(
                        enemy, 0x94, timer, shotX - enemy.x,
                        shotY - enemy.y, angle, 6.0, 20, 99999999);
                    firedLoud = true;
                }
            }

            static constexpr std::array<int, 5> kCornerPeriod{{
                250, 250, 200, 200, 180,
            }};
            static constexpr std::array<int, 5> kCornerCadence{{
                17, 9, 5, 4, 3,
            }};
            static constexpr std::array<int, 5> kCornerWindow{{
                160, 160, 120, 120, 120,
            }};
            const int cornerStart = segment * 5 + 30;
            const int period = kCornerPeriod[index];
            if (cycle >= cornerStart && cycle < cornerStart + period * 3) {
                const int elapsed = cycle - cornerStart;
                const int pairPhase = elapsed % (period * 2);
                if (pairPhase == 0) {
                    enemy.secondaryAngle16 = aimPoint(0.0f, 0.0f);
                }
                else if (pairPhase == period) {
                    enemy.secondaryAngle16 = aimPoint(720.0f, 0.0f);
                }
                const int local = elapsed % period;
                if (local < kCornerWindow[index] &&
                    local % kCornerCadence[index] == 0) {
                    int sweep = local * (0x10000 / kCornerWindow[index]);
                    if (pairPhase >= period) sweep = -sweep;
                    spawnStage07BossNode(
                        enemy, 0x94, timer, shotX - enemy.x,
                        shotY - enemy.y,
                        normalizeStage07Angle(
                            static_cast<int>(enemy.secondaryAngle16) + sweep),
                        6.0, 20, 99999999);
                    firedLoud = true;
                }
            }
        }
        else if (state == 0x3d) {
            const auto index = static_cast<std::size_t>(difficulty);
            if (timer < 480) {
                static constexpr std::array<int, 5> kBaseCount{{
                    11, 17, 19, 21, 23,
                }};
                static constexpr std::array<int, 5> kTurn{{
                    300, 360, 450, -550, -640,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    6.0, 7.0, 7.0, 7.0, 7.0,
                }};
                const int count = kBaseCount[index] +
                                  ((timer - 80) / 100) * 2;
                const int start = leftHead ? 80 : 180;
                if (timer >= start && (timer - start) % 200 == 0) {
                    enemy.secondaryAngle16 = normalizeStage07Angle(
                        static_cast<int>(shotAim()) +
                        0x10000 / (count * 2));
                }
                if (timer >= start) {
                    const int phase = (timer - start) % 200;
                    if (phase < 80 && phase % 4 == 0) {
                        spawnProjectileSpread(
                            leftHead ? 0x0c : 0x0d, 1,
                            shotX, shotY, enemy.secondaryAngle16,
                            10.0f, kSpeed[index], 1, count, 0x10000, 0);
                        const int local = (timer - start) % 100;
                        const bool firstPair = timer < start + 200;
                        const bool narrowHalf = local < 40;
                        int turn = kTurn[index];
                        if (leftHead) {
                            turn = (firstPair == narrowHalf)
                                       ? turn / 3
                                       : -turn;
                        }
                        else {
                            turn = (firstPair == narrowHalf)
                                       ? -(turn / 3)
                                       : turn;
                        }
                        enemy.secondaryAngle16 = normalizeStage07Angle(
                            static_cast<int>(enemy.secondaryAngle16) + turn);
                        firedLoud = true;
                    }
                }
            }
            else {
                static constexpr std::array<int, 5> kInterval{{
                    70, 50, 40, 30, 24,
                }};
                static constexpr std::array<int, 5> kFirstCount{{
                    13, 13, 13, 11, 13,
                }};
                static constexpr std::array<int, 5> kSecondCount{{
                    13, 15, 15, 15, 17,
                }};
                static constexpr std::array<int, 5> kTurn{{
                    20, 30, 40, 40, 40,
                }};
                static constexpr std::array<double, 5> kFirstSpeed{{
                    2.2, 2.6, 3.0, 3.0, 4.0,
                }};
                static constexpr std::array<double, 5> kSecondSpeed{{
                    2.2, 2.7, 3.2, 3.6, 4.6,
                }};
                const int interval = kInterval[index];
                const int start = 480 + (leftHead ? 0 : interval);
                if (timer >= start &&
                    (timer - start) % (interval * 2) == 0) {
                    spawnProjectileSpread(
                        leftHead ? 0x13 : 0x14, 0x26,
                        shotX, shotY,
                        normalizeStage07Angle(timer * kTurn[index]),
                        0.0f, kFirstSpeed[index], 1,
                        kFirstCount[index], 0x10000, 0);
                    auto aim = shotAim();
                    if (!leftHead) {
                        aim = normalizeStage07Angle(
                            static_cast<int>(aim) +
                            0x10000 / (kSecondCount[index] * 2));
                    }
                    spawnProjectileSpread(
                        leftHead ? 2 : 3, 0, shotX, shotY, aim,
                        10.0f, kSecondSpeed[index], 1,
                        kSecondCount[index], 0x10000, 0);
                    firedLoud = true;
                }
            }
        }
        if (firedQuiet) playPlayerSound(bullet2SoundHandle_, 0x0c);
        if (firedLoud) fireSound();
        return;
    }

    if (isStage07FirstFormPart(enemy.spawnType)) {
        const int timer = root->helperTimer;
        enemy.markerDrawTimer = root->helperState == 1 ? timer : -1;
        const bool delayedDamagePart =
            enemy.spawnType == 0x87 || enemy.spawnType == 0x88;
        const bool immediateDetach =
            (enemy.spawnType == 0x89 || enemy.spawnType == 0x8a) &&
            root->helperState > 9;
        if (immediateDetach || root->helperState > 10 ||
            (root->helperState == 10 && timer >= 100)) {
            enemy.targetable = false;
            if (immediateDetach) spawnEnemyDeathEffects(enemy, 1, false);
            enemy.active = false;
            return;
        }

        if (!delayedDamagePart && root->helperState == 1 && timer <= 1) {
            enemy.hp = root->hp;
            enemy.maxHp = root->maxHp;
            enemy.sourceHitPoints = enemy.hp;
        }
        if (!delayedDamagePart && root->helperState == 1 && timer > 1) {
            const int damage = std::max(0, enemy.sourceHitPoints - enemy.hp);
            if (damage > 0) root->hp = std::max(0, root->hp - damage);
            enemy.hp = std::min(enemy.hp, root->hp);
            enemy.sourceHitPoints = enemy.hp;
        }
        enemy.targetable = root->helperState == 1 && enemy.helperState == 0 &&
                           enemy.hp > 0;

        enemy.x = root->x + enemy.originX;
        enemy.y = root->y + enemy.originY;

        if (delayedDamagePart && enemy.helperState == 0 && enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0xf3c, false);
            spawnEnemyDeathEffects(enemy,
                                   enemy.spawnType == 0x87 ? 2 : 1);
            spawnDelayedOwnerDamageNode(
                enemy.maxHp, root->entityId, root->spawnType,
                enemy.spawnType == 0x87
                    ? "S07 type 0x87 delayed-damage node 0x153"
                    : "S07 type 0x88 delayed-damage node 0x153");
            enemy.targetable = false;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            return;
        }
        if (delayedDamagePart && enemy.helperState != 0) return;

        if (root->helperState != 1 || enemy.hp < 1) return;
        const int cycle = timer % 2600;
        bool fired = false;

        if (enemy.spawnType == 0x85 || enemy.spawnType == 0x86) {
            const bool right = enemy.spawnType == 0x86;
            const int start = right ? 480 : 60;
            static constexpr std::array<int, 5> kLeftInterval{{
                20, 16, 14, 12, 12,
            }};
            static constexpr std::array<int, 5> kRightInterval{{
                18, 14, 12, 9, 9,
            }};
            const int interval = (right ? kRightInterval : kLeftInterval)[
                static_cast<std::size_t>(difficulty)];
            if (cycle >= start && cycle < start + 120 &&
                (cycle - start) % interval == 0) {
                const auto angle = normalizeStage07Angle(
                    static_cast<int>(stage07ScriptRand(timer) % 0x8001u));
                spawnStage07BossNode(
                    enemy, right ? 0x8c : 0x8b, timer,
                    0.0f, 38.0f, angle,
                    stage07RandomRange(timer, 4.0, right ? 12.0 : 7.0),
                    20, 900);
                fired = true;
            }
            const int heavyStart = right ? 2120 : 1970;
            if (cycle >= heavyStart && cycle < 2500 &&
                (cycle - heavyStart) % 300 == 0) {
                spawnStage07BossNode(
                    enemy, right ? 0x8e : 0x8d, timer,
                    0.0f, 38.0f,
                    aimAtPlayer(enemy.x, enemy.y + 38.0f),
                    5.0, 20, 3600);
                fired = true;
            }
        }
        else if (enemy.spawnType == 0x87) {
            const bool positiveSide = enemy.originX >= 0.0f;
            const float shotX = enemy.x + (positiveSide ? -10.0f : 10.0f);
            const float shotY = enemy.y + 45.0f;

            const int opening = timer >= 20 ? (timer - 20) % 82 : -1;
            if (opening >= 0 && opening < 30 && opening % 5 == 0) {
                static constexpr std::array<double, 5> kSpeed{{
                    5.0, 6.0, 7.0, 8.0, 9.5,
                }};
                for (int i = 0; i < 3; ++i) {
                    const int angle = positiveSide
                                          ? i * 14000 - 14000
                                          : i * 14000 + 0x4950;
                    spawnProjectileNode(
                        2, 0, shotX, shotY,
                        normalizeStage07Angle(angle), 10.0f,
                        kSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
                }
                fired = true;
            }

            const int sweepStart = positiveSide ? 750 : 330;
            static constexpr std::array<int, 5> kSweepCadence{{
                6, 5, 4, 4, 4,
            }};
            static constexpr std::array<int, 5> kSweepCount{{
                5, 7, 9, 11, 11,
            }};
            static constexpr std::array<double, 5> kSweepSpeed{{
                3.2, 3.6, 4.0, 4.0, 5.5,
            }};
            if (cycle == sweepStart) {
                enemy.secondaryAngle16 = positiveSide ? 0xa000 : 0xe000;
            }
            if (cycle >= sweepStart && cycle < sweepStart + 150) {
                const int local = cycle - sweepStart;
                if (local % kSweepCadence[static_cast<std::size_t>(difficulty)] == 0) {
                    const int count = kSweepCount[static_cast<std::size_t>(difficulty)];
                    spawnProjectileSpread(
                        positiveSide ? 3 : 3, 0, shotX, shotY,
                        enemy.secondaryAngle16, 10.0f,
                        kSweepSpeed[static_cast<std::size_t>(difficulty)] +
                            local * 0.005,
                        1, count, 0x10000, 0);
                    fired = true;
                }
                enemy.secondaryAngle16 = normalizeStage07Angle(
                    static_cast<int>(enemy.secondaryAngle16) +
                    (positiveSide ? -900 : 900));
            }

            static constexpr std::array<int, 5> kRingCadence{{
                19, 13, 11, 11, 10,
            }};
            static constexpr std::array<int, 5> kRingCount{{
                3, 4, 5, 5, 6,
            }};
            static constexpr std::array<double, 5> kRingSpeed{{
                3.5, 4.0, 4.5, 4.5, 5.5,
            }};
            if (cycle == 1050) enemy.secondaryAngle16 = 0xc000;
            if (cycle >= 990 && cycle < 1560) {
                if (cycle >= 1050 &&
                    (cycle - 1050) %
                        kRingCadence[static_cast<std::size_t>(difficulty)] == 0) {
                    spawnProjectileSpread(
                        5, 0, shotX, shotY, enemy.secondaryAngle16, 0.0f,
                        kRingSpeed[static_cast<std::size_t>(difficulty)], 1,
                        kRingCount[static_cast<std::size_t>(difficulty)],
                        0x10000, 0);
                    fired = true;
                }
                enemy.secondaryAngle16 = normalizeStage07Angle(
                    static_cast<int>(enemy.secondaryAngle16) +
                    (positiveSide ? -0xa0 : 0xa0));
            }

            const int aimedStart = positiveSide ? 1790 : 1650;
            static constexpr std::array<int, 5> kAimedCadence{{
                40, 30, 24, 20, 24,
            }};
            static constexpr std::array<int, 5> kAimedCount{{
                7, 9, 9, 9, 11,
            }};
            static constexpr std::array<double, 5> kAimedSpeed{{
                5.5, 6.5, 7.0, 7.5, 8.5,
            }};
            if (cycle == aimedStart) {
                enemy.secondaryAngle16 = aimAtPlayer(shotX, shotY);
            }
            if (cycle >= aimedStart && cycle < aimedStart + 120) {
                const int cadence =
                    kAimedCadence[static_cast<std::size_t>(difficulty)];
                const int local = cycle - aimedStart;
                if (local % cadence == 0 || local % cadence == cadence / 2) {
                    const int count = kAimedCount[static_cast<std::size_t>(difficulty)];
                    const int angleOffset = local % cadence == 0 ? 0 : 0x157c;
                    spawnProjectileSpread(
                        3, 0, shotX, shotY,
                        normalizeStage07Angle(
                            static_cast<int>(enemy.secondaryAngle16) +
                            (positiveSide ? angleOffset : -angleOffset)),
                        0.0f, kAimedSpeed[static_cast<std::size_t>(difficulty)],
                        1, count, count * 0x294 - 0x294, 0);
                    fired = true;
                }
            }
        }
        else if (enemy.spawnType == 0x88) {
            static constexpr std::array<int, 5> kCadence{{
                164, 123, 81, 81, 81,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                4.5, 5.0, 5.5, 6.0, 7.0,
            }};
            if (timer > 40) {
                const int local = (timer - 41) %
                                  kCadence[static_cast<std::size_t>(difficulty)];
                if (local == 0) {
                    enemy.secondaryAngle16 = normalizeStage07Angle(
                        static_cast<int>(aimAtPlayer(enemy.x, enemy.y)) + 0x400);
                }
                if (local < 9 && local % 3 == 0) {
                    const auto angle = normalizeStage07Angle(
                        static_cast<int>(enemy.secondaryAngle16) & 0xf800);
                    spawnProjectileNode(
                        0x0f, 0, enemy.x, enemy.y, angle, 0.0f,
                        kSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
                    if (difficulty > 2) {
                        spawnProjectileNode(
                            0x0f, 0, enemy.x, enemy.y, angle, 0.0f,
                            kSpeed[static_cast<std::size_t>(difficulty)] + 1.2,
                            1, 0);
                    }
                    fired = true;
                }
            }
        }
        else {
            const float baseX = enemy.x;
            const float baseY = enemy.y;
            const bool leftCannon = enemy.spawnType == 0x89;
            std::uint16_t target = aimAtPlayer(baseX, baseY);
            if (cycle < 960 || cycle >= 1600) {
                target = stage07RadiansToAngle(std::atan2(
                    static_cast<double>(root->y + 60.0f - baseY),
                    static_cast<double>(root->x +
                        (leftCannon ? -80.0f : 80.0f) - baseX)));
            }
            int delta = static_cast<int>(target) -
                        static_cast<int>(enemy.sourceAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            enemy.sourceAngle16 = approachStage07Angle(
                enemy.sourceAngle16, target, 0x30 + std::abs(delta) / 10);
            enemy.x = baseX + stage07PolarX(enemy.sourceAngle16, 20.0);
            enemy.y = baseY + stage07PolarY(enemy.sourceAngle16, 20.0);

            static constexpr std::array<int, 5> kCadence{{
                45, 36, 30, 24, 20,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                5.5, 6.5, 7.0, 8.0, 9.0,
            }};
            if (cycle >= 980 && cycle < 1600) {
                const int local = (cycle - 980) %
                                  kCadence[static_cast<std::size_t>(difficulty)];
                if (local < 9 && local % 3 == 0) {
                    const float muzzleX =
                        baseX + stage07PolarX(enemy.sourceAngle16, 50.0);
                    const float muzzleY =
                        baseY + stage07PolarY(enemy.sourceAngle16, 50.0);
                    spawnProjectileNode(
                        6, 0, muzzleX, muzzleY, enemy.sourceAngle16,
                        10.0f, kSpeed[static_cast<std::size_t>(difficulty)],
                        1, 0);
                    fired = true;
                }
            }
        }
        if (fired) fireSound();
        return;
    }

    if (enemy.spawnType >= 0x8b && enemy.spawnType <= 0x8e) {
        const int timer = enemy.helperTimer;
        if (enemy.helperState == 0) {
            enemy.targetable = false;
            const double entrySpeed = enemy.sourceSpeed *
                (1.0 - static_cast<double>(std::clamp(timer, 0, 40)) / 40.0);
            enemy.x += stage07PolarX(enemy.sourceAngle16, entrySpeed);
            enemy.y += stage07PolarY(enemy.sourceAngle16, entrySpeed);
            if (timer == 0) enemy.secondaryAngle16 = 0x4000;
            if (timer == 40) {
                const auto aimed = aimAtPlayer(enemy.x, enemy.y);
                if (enemy.spawnType == 0x8b) {
                    enemy.sourceSpeed = 1.2;
                    enemy.sourceAngle16 = normalizeStage07Angle(
                        static_cast<int>(aimed) +
                        static_cast<int>(stage07ScriptRand(frame_) % 0x115du) -
                        0x8ae);
                }
                else if (enemy.spawnType == 0x8c) {
                    enemy.sourceSpeed = 0.0;
                    enemy.sourceAngle16 = 0x4000;
                    enemy.secondaryAngle16 = aimAtPlayer(
                        enemy.markerDrawX, enemy.markerDrawY);
                }
                else {
                    enemy.sourceSpeed = 1.0;
                    enemy.sourceAngle16 = aimed;
                    enemy.secondaryAngle16 = aimed;
                }
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = enemy.hp > 0;
            }
            return;
        }

        enemy.targetable = enemy.hp > 0;
        const float muzzleX =
            enemy.x + stage07PolarX(enemy.sourceAngle16, 14.0);
        const float muzzleY =
            enemy.y + stage07PolarY(enemy.sourceAngle16, 14.0);
        bool fired = false;

        if (enemy.spawnType == 0x8b) {
            static constexpr std::array<int, 5> kCadence{{
                120, 60, 45, 45, 40,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                3.8, 4.5, 5.0, 5.0, 6.0,
            }};
            const float horizontalOrigin = player_.x / 6.0f;
            const bool inFireArea =
                muzzleX >= horizontalOrigin + 40.0f &&
                muzzleX <= horizontalOrigin + 560.0f &&
                muzzleY >= 40.0f && muzzleY <= 680.0f;
            if (timer < 150 &&
                timer % kCadence[static_cast<std::size_t>(difficulty)] == 0 &&
                inFireArea &&
                stage07Distance(muzzleX, muzzleY, player_.x, player_.y) > 50.0) {
                const auto aimed = aimAtPlayer(muzzleX, muzzleY);
                const int jitter = static_cast<int>(
                    stage07ScriptRand(root->helperTimer + timer) % 0x5dc1u) -
                    0x319c;
                for (int i = 0; i < 3; ++i) {
                    spawnProjectileNode(
                        4, 0, muzzleX, muzzleY,
                        normalizeStage07Angle(
                            static_cast<int>(aimed) + jitter + i * 700),
                        0.0f, kSpeed[static_cast<std::size_t>(difficulty)],
                        1, 0);
                }
                if (difficulty > 2) {
                    const int extraJitter = static_cast<int>(
                        stage07ScriptRand(root->helperTimer + timer + 1) %
                        0x5dc1u) - 0x3458;
                    for (int i = 0; i < 2; ++i) {
                        spawnProjectileNode(
                            4, 0, muzzleX, muzzleY,
                            normalizeStage07Angle(
                                static_cast<int>(aimed) + extraJitter +
                                i * 0xaf0),
                            0.0f,
                            kSpeed[static_cast<std::size_t>(difficulty)],
                            1, 0);
                    }
                }
                fired = true;
            }
        }
        else if (enemy.spawnType == 0x8c) {
            int delta = static_cast<int>(aimAtPlayer(enemy.x, enemy.y)) -
                        static_cast<int>(enemy.sourceAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            enemy.sourceAngle16 = approachStage07Angle(
                enemy.sourceAngle16, enemy.secondaryAngle16,
                0x30 + std::abs(delta) / 10);
            if (timer > 29) {
                static constexpr std::array<double, 5> kAcceleration{{
                    0.06, 0.08, 0.10, 0.12, 0.15,
                }};
                enemy.sourceSpeed +=
                    kAcceleration[static_cast<std::size_t>(difficulty)];
                const float horizontalOrigin = player_.x / 6.0f;
                if ((timer & 1) == 0 &&
                    enemy.x >= horizontalOrigin &&
                    enemy.x <= horizontalOrigin + 600.0f &&
                    enemy.y >= 0.0f && enemy.y <= 720.0f) {
                    const float shotX =
                        enemy.x + stage07PolarX(enemy.sourceAngle16, 14.0);
                    const float shotY =
                        enemy.y + stage07PolarY(enemy.sourceAngle16, 14.0);
                    spawnProjectileNode(
                        4, 3, shotX, shotY, enemy.sourceAngle16,
                        0.0f, 12.0, 1, 0);
                    fired = true;
                }
            }
        }
        else {
            static constexpr std::array<int, 5> kTurnPeriod{{
                100, 100, 75, 75, 65,
            }};
            static constexpr std::array<int, 5> kTurnAmplitude{{
                4000, 4500, 4500, 5000, 5000,
            }};
            static constexpr std::array<int, 5> kRingCount{{
                6, 8, 9, 11, 13,
            }};
            static constexpr std::array<double, 5> kRingSpeed{{
                4.5, 5.0, 5.5, 6.0, 7.0,
            }};
            static constexpr std::array<int, 5> kSecondaryCadence{{
                80, 60, 50, 40, 32,
            }};
            static constexpr std::array<int, 5> kSecondaryCount{{
                13, 17, 23, 27, 31,
            }};
            static constexpr std::array<double, 5> kSecondarySpeed{{
                3.0, 3.5, 4.0, 4.0, 5.0,
            }};

            const int period = kTurnPeriod[static_cast<std::size_t>(difficulty)];
            const int phase = timer % period;
            const int half = period / 2;
            const int triangle = phase < half ? phase : period - phase;
            const int signedTurn = triangle *
                kTurnAmplitude[static_cast<std::size_t>(difficulty)] /
                std::max(1, half);
            const auto ringAngle = normalizeStage07Angle(
                static_cast<int>(enemy.secondaryAngle16) +
                (enemy.spawnType == 0x8d ? signedTurn : -signedTurn));
            const float horizontalOrigin = player_.x / 6.0f;
            const bool inFireArea =
                muzzleX >= horizontalOrigin + 40.0f &&
                muzzleX <= horizontalOrigin + 560.0f &&
                muzzleY >= 40.0f && muzzleY <= 680.0f &&
                stage07Distance(muzzleX, muzzleY, player_.x, player_.y) > 50.0;
            if (timer < 150 && inFireArea && timer % 3 == 0) {
                spawnProjectileSpread(
                    9, 0, muzzleX, muzzleY, ringAngle, 10.0f,
                    kRingSpeed[static_cast<std::size_t>(difficulty)] +
                        timer * 0.04,
                    1, kRingCount[static_cast<std::size_t>(difficulty)],
                    0x10000, 0);
                fired = true;
            }
            if (timer < 150 && inFireArea &&
                timer % kSecondaryCadence[
                    static_cast<std::size_t>(difficulty)] == 0) {
                spawnProjectileSpread(
                    4, 0, muzzleX, muzzleY,
                    aimAtPlayer(muzzleX, muzzleY), 0.0f,
                    kSecondarySpeed[static_cast<std::size_t>(difficulty)],
                    1, kSecondaryCount[static_cast<std::size_t>(difficulty)],
                    0x10000, 0);
                fired = true;
            }
        }

        if (enemy.spawnType != 0x8c) {
            enemy.x += stage07PolarX(enemy.sourceAngle16, enemy.sourceSpeed);
            enemy.y += stage07PolarY(enemy.sourceAngle16, enemy.sourceSpeed);
            if (timer > 179) enemy.sourceSpeed += 0.1;
        }
        else {
            enemy.x += stage07PolarX(enemy.sourceAngle16, enemy.sourceSpeed);
            enemy.y += stage07PolarY(enemy.sourceAngle16, enemy.sourceSpeed);
        }
        if (fired) fireSound();
        if (enemy.hp < 1) {
            const bool transferDamage = player_.invulnerableFrames == 0;
            spawnEnemyDeathRewardBurst(enemy, 300, false);
            spawnEnemyDeathEffects(enemy, 0);
            if (transferDamage) {
                spawnDelayedOwnerDamageNode(
                    enemy.maxHp, root->entityId, root->spawnType,
                    "S07 type 0x8b..0x8e delayed-damage node 0x153");
            }
            enemy.targetable = false;
            enemy.active = false;
            return;
        }
        if (root->hp < 1 || lateStageBossCountdown_ < 1) {
            spawnEnemyDeathEffects(enemy, 0);
            enemy.targetable = false;
            enemy.active = false;
            return;
        }
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.x < horizontalOrigin - 100.0f ||
            enemy.x > horizontalOrigin + 700.0f ||
            enemy.y < -100.0f || enemy.y > 820.0f) {
            enemy.targetable = false;
            enemy.active = false;
        }
        return;
    }

    if (enemy.spawnType >= 0x8f && enemy.spawnType <= 0x92) {
        if (parent == nullptr || !isStage07HeadType(parent->spawnType)) {
            enemy.active = false;
            return;
        }
        enemy.targetable = false;
        const int timer = enemy.helperTimer;
        const double orbitRadians = static_cast<double>(frame_) *
                                    399.609756097561 * kPi / 32768.0;
        enemy.x = parent->x +
                  static_cast<float>(std::cos(orbitRadians) * 24.0);
        enemy.y = parent->y - 120.0f +
                  static_cast<float>(std::sin(orbitRadians) * 24.0);
        const int spin = (enemy.spawnType == 0x8f ||
                          enemy.spawnType == 0x92)
                             ? -0x1e5
                             : 0x1e5;
        enemy.sourceAngle16 = normalizeStage07Angle(
            static_cast<int>(enemy.sourceAngle16) + spin);

        bool fired = false;
        if (enemy.spawnType <= 0x90) {
            static constexpr std::array<int, 5> kCadence{{
                11, 8, 7, 8, 7,
            }};
            static constexpr std::array<int, 5> kCount{{
                3, 5, 7, 7, 8,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                3.5, 4.5, 5.0, 4.5, 6.0,
            }};
            if (timer > 9 &&
                (timer - 10) %
                        kCadence[static_cast<std::size_t>(difficulty)] ==
                    0) {
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    timer * 0.003;
                const auto angle = normalizeStage07Angle(timer * -0x118);
                spawnProjectileSpread(
                    4, 0, enemy.x, enemy.y, angle, 0.0f, speed, 1,
                    kCount[static_cast<std::size_t>(difficulty)],
                    kCount[static_cast<std::size_t>(difficulty)] * 3000 -
                        3000,
                    0);
                spawnProjectileSpread(
                    4, 0, enemy.x, enemy.y,
                    normalizeStage07Angle(static_cast<int>(angle) - 0x8000),
                    0.0f, speed, 1,
                    kCount[static_cast<std::size_t>(difficulty)],
                    kCount[static_cast<std::size_t>(difficulty)] * 3000 -
                        3000,
                    0);
                if (difficulty > 2) {
                    for (int i = 0; i < 4; ++i) {
                        spawnProjectileNode(
                            5, 0, enemy.x, enemy.y,
                            normalizeStage07Angle(
                                i * 3000 + timer * 300 - 0x1194),
                            0.0f, speed + 1.0, 1, 0);
                        spawnProjectileNode(
                            5, 0, enemy.x, enemy.y,
                            normalizeStage07Angle(
                                i * 3000 + timer * 300 + 0x6e6c),
                            0.0f, speed + 1.0, 1, 0);
                    }
                }
                fired = true;
            }
        }
        else {
            static constexpr std::array<int, 5> kPeriod{{
                50, 39, 39, 50, 50,
            }};
            static constexpr std::array<int, 5> kWindow{{
                12, 21, 27, 36, 36,
            }};
            static constexpr std::array<int, 5> kBaseCount{{
                10, 14, 16, 18, 20,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                4.0, 4.5, 5.2, 6.0, 7.0,
            }};
            static constexpr std::array<int, 5> kRingCadence{{
                90, 60, 48, 36, 26,
            }};
            static constexpr std::array<int, 5> kRingCount{{
                20, 32, 36, 40, 44,
            }};
            const auto index = static_cast<std::size_t>(difficulty);
            const int period = kPeriod[index];
            if (timer >= 10 && (timer - 10) % period == 0) {
                enemy.secondaryAngle16 = aimAtPlayer(enemy.x, enemy.y);
            }
            const int count = kBaseCount[index] +
                              std::max(0, timer - 10) / (period * 2);
            const double speed = kSpeed[index] + timer * 0.004;
            const int firstPhase = timer >= 10
                                       ? (timer - 10) % (period * 2)
                                       : period * 2;
            if (firstPhase < kWindow[index] && firstPhase % 3 == 0) {
                spawnProjectileSpread(
                    0x0b, 0, enemy.x, enemy.y,
                    enemy.secondaryAngle16, 10.0f, speed, 1, count,
                    0x10000, 0);
                fired = true;
            }
            const int secondStart = period + 10;
            const int secondPhase = timer >= secondStart
                                        ? (timer - secondStart) % (period * 2)
                                        : period * 2;
            if (secondPhase < kWindow[index] && secondPhase % 3 == 0) {
                spawnProjectileSpread(
                    0x0b, 0, enemy.x, enemy.y,
                    normalizeStage07Angle(
                        static_cast<int>(enemy.secondaryAngle16) +
                        0x10000 / (count * 2)),
                    10.0f, speed, 1, count, 0x10000, 0);
                fired = true;
            }
            if (timer >= 26 && timer < 450 &&
                (timer - 26) % kRingCadence[index] == 0) {
                spawnProjectileSpread(
                    4, 0, enemy.x, enemy.y,
                    enemy.secondaryAngle16, 0.0f, speed * 0.6, 1,
                    kRingCount[index], 0x10000, 0);
                fired = true;
            }
            enemy.secondaryAngle16 = approachStage07Angle(
                enemy.secondaryAngle16, aimAtPlayer(enemy.x, enemy.y), 0x30);
        }
        if (fired) fireSound();
        if (timer == 540) {
            static constexpr std::array<int, 5> kFinalCount{{
                20, 36, 44, 50, 55,
            }};
            static constexpr std::array<int, 5> kFinalLayers{{
                1, 2, 3, 5, 6,
            }};
            static constexpr std::array<double, 5> kFinalBaseSpeed{{
                4.5, 4.5, 4.0, 4.0, 4.0,
            }};
            const auto index = static_cast<std::size_t>(difficulty);
            const auto aimed = aimAtPlayer(enemy.x, enemy.y);
            const int count = kFinalCount[index];
            for (int layer = 0; layer < kFinalLayers[index]; ++layer) {
                const int selector = parent->spawnType == 0x83 ? 3 : 2;
                spawnProjectileSpread(
                    selector, 0, enemy.x, enemy.y,
                    normalizeStage07Angle(
                        static_cast<int>(aimed) +
                        layer * (0x10000 / (count * 5)) * 2),
                    10.0f, kFinalBaseSpeed[index] + layer * 0.9, 1,
                    count, 0x10000, 0);
            }
            spawnEnemyDeathEffects(enemy, 0, false);
            enemy.active = false;
            return;
        }
        if (parent->hp < 1 || lateStageBossCountdown_ < 1) {
            spawnEnemyDeathEffects(enemy, 0, false);
            enemy.active = false;
        }
        return;
    }

    if (enemy.spawnType == 0x93 || enemy.spawnType == 0x94) {
        enemy.targetable = false;
        const double speed = enemy.sourceSpeed;
        enemy.x += stage07PolarX(enemy.sourceAngle16, speed);
        enemy.y += stage07PolarY(enemy.sourceAngle16, speed);
        enemy.sourceSpeed += 0.1;

        const float horizontalOrigin = player_.x / 6.0f;
        const bool hitShotBoundary =
            enemy.x < horizontalOrigin - 30.0f ||
            enemy.x > horizontalOrigin + 630.0f ||
            enemy.y < -180.0f || enemy.y > 750.0f;
        if (enemy.spawnType == 0x94 && hitShotBoundary) {
            enemy.x += stage07PolarX(enemy.sourceAngle16, -30.0);
            enemy.y += stage07PolarY(enemy.sourceAngle16, -30.0);
            static constexpr std::array<double, 5> kShotSpeed{{
                2.0, 3.0, 4.0, 4.0, 5.0,
            }};
            spawnProjectileNode(
                0x14, 0x25, enemy.x, enemy.y,
                aimAtPlayer(enemy.x, enemy.y), 0.0f,
                kShotSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
            enemy.active = false;
            return;
        }
        if (parent == nullptr || !isStage07HeadType(parent->spawnType) ||
            parent->hp < 1 || lateStageBossCountdown_ < 1) {
            spawnEnemyDeathEffects(enemy, 0, false);
            enemy.active = false;
            return;
        }
        if (enemy.x < horizontalOrigin - 180.0f ||
            enemy.x > horizontalOrigin + 780.0f ||
            enemy.y < -180.0f || enemy.y > 900.0f) {
            enemy.active = false;
        }
    }
}

bool StageRuntime::drawStage07BossNode(const StageEnemy& enemy, float x,
                                       float y) const {
    if (!isStage07BossNodeType(enemy.spawnType)) return false;
    if (!enemy.drawBodyThisFrame) return true;

    const auto drawFrame = [this](const std::vector<int>& frames, int index,
                                  float drawX, float drawY,
                                  std::uint16_t angle = 0,
                                  double scaleX = 1.0,
                                  double scaleY = 1.0,
                                  bool reverseX = false) {
        const int handle = frameHandle07(frames, index);
        if (handle == -1) return false;
        drawOriginalMode7Node(handle, drawX, drawY, angle,
                              scaleX, scaleY, reverseX);
        return true;
    };
    const auto fallback = [&enemy](float drawX, float drawY) {
        DrawCircle(static_cast<int>(drawX), static_cast<int>(drawY),
                   std::max(10, enemy.radius / 3),
                   GetColor(enemy.spawnType == 0x84 ? 96 : 255,
                            128, enemy.spawnType == 0x83 ? 96 : 255),
                   TRUE);
    };

    if (enemy.spawnType == 0x80) {
        const float anchorX = x + enemy.markerDrawX - enemy.x;
        const float anchorY = y + enemy.markerDrawY - enemy.y;
        bool drew = false;
        drew |= drawFrame(enemySmallFrames_, 79, anchorX, anchorY);
        drew |= drawFrame(enemySmallFrames_, 80, x, y,
                          enemy.sourceAngle16);

        const int introTimer = enemy.markerDrawTimer;
        int trailAlpha = enemy.drawHelperState == 0 ? 64 : 0;
        if (enemy.drawHelperState == 1 && introTimer >= 0 &&
            introTimer < 60) {
            trailAlpha = std::clamp(static_cast<int>(
                std::sin((static_cast<double>(introTimer) + 60.0) *
                         kPi / 120.0) * 64.0), 0, 64);
        }
        if (trailAlpha > 0) {
            const int cycle = ((frame_ % 656) + 656) % 656;
            const int phase = cycle < 328 ? cycle : cycle - 328;
            const int delta = static_cast<int>(
                static_cast<double>(phase) * 127.0 / 328.0);
            const int red = cycle < 328 ? 255 - delta : 128 + delta;
            const int green = cycle < 328 ? 128 + delta : 255 - delta;
            const int trail = frameHandle07(stageBack2Frames_, 3);
            if (trail != -1) {
                SetDrawBright(red, green, 0xff);
                SetDrawBlendMode(DX_BLENDMODE_ADD, trailAlpha);
                drawOriginalMode7Node(
                    trail,
                    x + stage07PolarX(enemy.sourceAngle16, 720.0),
                    y + stage07PolarY(enemy.sourceAngle16, 720.0),
                    enemy.sourceAngle16, 2.0, 1.0, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
                SetDrawBright(0xff, 0xff, 0xff);
                drew = true;
            }
        }

        const auto spin = normalizeStage07Angle(
            enemy.drawHelperTimer * 0xf3c);
        drew |= drawFrame(enemySmallFrames_, 78, anchorX, anchorY, spin);
        drew |= drawFrame(enemySmallFrames_, 78, anchorX, anchorY,
                          normalizeStage07Angle(
                              static_cast<int>(spin) + 0x8000));
        if (!drew) fallback(x, y);
        return true;
    }

    if (enemy.spawnType == 0x85 || enemy.spawnType == 0x86) {
        const bool right = enemy.spawnType == 0x86;
        const int base = right ? 130 : 126;
        int overlay = 1;
        if (enemy.markerDrawTimer >= 0) {
            const int cycle = enemy.markerDrawTimer % 2600;
            const int firstStart = right ? 480 : 60;
            if (cycle >= firstStart && cycle < 600) {
                overlay = 3;
            }
            const int secondStart = right ? 2100 : 1950;
            if (cycle >= secondStart && cycle < 2450) {
                const int local = (cycle - secondStart) % 300;
                if (local < 5) overlay = 2;
                else if (local < 60) overlay = 3;
                else if (local < 65) overlay = 2;
                else if (local < 70) overlay = 1;
            }
        }
        const double pulse = 1.0 +
            std::sin(static_cast<double>(frame_) * kTau / 82.0) * 0.05;
        bool drew = drawFrame(enemyMediumFrames_, base, x, y,
                              0, pulse, 1.0, false);
        drew |= drawFrame(enemyMediumFrames_, base + overlay, x, y,
                          0, pulse, 1.0, false);
        if (!drew) fallback(x, y);
        return true;
    }

    if (enemy.spawnType == 0x89 || enemy.spawnType == 0x8a) {
        const float baseX = x - stage07PolarX(enemy.sourceAngle16, 20.0);
        const float baseY = y - stage07PolarY(enemy.sourceAngle16, 20.0);
        const float glowX = baseX +
            stage07PolarX(enemy.sourceAngle16, 120.0);
        const float glowY = baseY +
            stage07PolarY(enemy.sourceAngle16, 120.0);
        bool drew = false;
        const int glow = frameHandle07(enemySmallFrames_, 81);
        if (glow != -1) {
            if (enemy.spawnType == 0x89) SetDrawBright(0xff, 0, 0xff);
            else SetDrawBright(0, 0xff, 0xff);
            SetDrawBlendMode(DX_BLENDMODE_ADD, 0x40);
            drawOriginalMode7Node(glow, glowX, glowY,
                                  enemy.sourceAngle16, 2.0, 0.9, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(0xff, 0xff, 0xff);
            drew = true;
        }
        drew |= drawFrame(enemySmallFrames_, 100, baseX, baseY,
                          enemy.sourceAngle16);
        if (!drew) fallback(x, y);
        return true;
    }

    if (enemy.spawnType >= 0x8b && enemy.spawnType <= 0x8e) {
        static constexpr std::array<int, 4> kAnimation{{0, 1, 2, 1}};
        const int base = (enemy.spawnType == 0x8c ||
                          enemy.spawnType == 0x8e)
                             ? 105
                             : 101;
        const int timer = enemy.drawHelperTimer;
        double scale = 1.0;
        if (enemy.drawHelperState == 0) {
            const int entry = std::clamp(timer, 0, 40);
            scale = 0.2 + std::sin(entry * kPi / 80.0) * 0.8;
        }
        const auto bodyAngle = normalizeStage07Angle(
            static_cast<int>(enemy.secondaryAngle16) - 0x4000);
        bool drew = drawFrame(
            enemySmallFrames_,
            base + kAnimation[static_cast<std::size_t>((frame_ / 3) % 4)],
            x, y, bodyAngle, scale, scale, false);

        const float armX = x + stage07PolarX(
            enemy.secondaryAngle16, -24.0 * scale);
        const float armY = y + stage07PolarY(
            enemy.secondaryAngle16, -24.0 * scale);
        std::uint16_t firstArm = normalizeStage07Angle(timer * 0xc80);
        std::uint16_t secondArm = normalizeStage07Angle(
            static_cast<int>(firstArm) + 0x8000);
        if (enemy.spawnType == 0x8c && enemy.drawHelperState == 1 &&
            timer > 29) {
            int firstBase = 0x8ae;
            int secondBase = -0x8ae;
            if (timer < 60) {
                const int transition = static_cast<int>(
                    std::sin((static_cast<double>(timer) - 30.0) *
                             kPi / 60.0) * 14162.0);
                firstBase = 0x4000 - transition;
                secondBase = -0x4000 + transition;
            }
            const int wobble = static_cast<int>(
                std::sin(static_cast<double>(timer) * kTau / 9.0) * 999.0);
            firstArm = normalizeStage07Angle(
                static_cast<int>(enemy.secondaryAngle16) + firstBase -
                0x8000 + wobble);
            secondArm = normalizeStage07Angle(
                static_cast<int>(enemy.secondaryAngle16) + secondBase -
                0x8000 - wobble);
        }
        drew |= drawFrame(enemySmallFrames_, base + 3, armX, armY,
                          firstArm, scale, scale, false);
        drew |= drawFrame(enemySmallFrames_, base + 3, armX, armY,
                          secondArm, scale, scale, false);
        if (!drew) fallback(x, y);
        return true;
    }

    int graph = -1;
    bool reverse = false;
    double scale = 1.0;
    std::uint16_t drawAngle = enemy.sourceAngle16;
    const int timer = enemy.drawHelperTimer;
    if (enemy.spawnType == 0x81 || enemy.spawnType == 0x82) {
        graph = frameHandle07(bossFrames_,
                              (enemy.spawnType == 0x81 ? 88 : 98) +
                                  (timer / 5) % 2);
    }
    else if (enemy.spawnType == 0x83) {
        static constexpr std::array<int, 16> kFrames{{
            80, 81, 82, 83, 84, 85, 87, 86,
            87, 86, 85, 84, 83, 82, 80, 81,
        }};
        int frame = kFrames[static_cast<std::size_t>((frame_ / 5) % 16)];
        if (enemy.drawHelperState == 10) frame = 88 + (timer / 5) % 2;
        graph = frameHandle07(bossFrames_, frame);
    }
    else if (enemy.spawnType == 0x84) {
        static constexpr std::array<int, 16> kFrames{{
            96, 95, 94, 93, 92, 90, 91, 90,
            91, 92, 93, 94, 95, 97, 96, 97,
        }};
        int frame = kFrames[static_cast<std::size_t>((frame_ / 5) % 16)];
        if (enemy.drawHelperState == 10) frame = 98 + (timer / 5) % 2;
        graph = frameHandle07(bossFrames_, frame);
    }
    else if (enemy.spawnType == 0x87) {
        graph = frameHandle07(enemyMediumFrames_,
                              enemy.drawHelperState == 0 ? 138 : 140);
        reverse = enemy.originX >= 0.0f;
    }
    else if (enemy.spawnType == 0x88) {
        graph = frameHandle07(
            enemySmallFrames_,
            enemy.originX >= -100.0f && enemy.originX < 100.0f ? 109 : 111);
        reverse = enemy.originX >= 100.0f;
    }
    else if (enemy.spawnType <= 0x92) {
        graph = frameHandle07(enemySmallFrames_,
                              enemy.parentSpawnType == 0x84 ? 118 : 117);
        drawAngle = normalizeStage07Angle(timer * -0x457);
        scale = timer < 10 ? std::sin(timer * kPi / 20.0) : 1.0;
    }
    else {
        graph = frameHandle07(enemySmallFrames_,
                              enemy.parentSpawnType == 0x84 ? 118 : 117);
        drawAngle = normalizeStage07Angle(
            timer * (enemy.parentSpawnType == 0x84 ? 0x457 : -0x457));
        reverse = enemy.parentSpawnType == 0x84;
        scale = timer < 10 ? std::sin(timer * kPi / 20.0) : 1.0;
    }

    if (graph != -1) {
        drawOriginalMode7Node(graph, x, y, drawAngle,
                              scale, scale, reverse);
    }
    else {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(10, enemy.radius / 3),
                   GetColor(enemy.spawnType == 0x84 ? 96 : 255,
                            128, enemy.spawnType == 0x83 ? 96 : 255),
                   TRUE);
    }
    return true;
}

} // namespace reconstructed
