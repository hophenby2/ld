#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kMidboss07Pi = 3.14159265358979323846;
constexpr double kMidboss07Tau = kMidboss07Pi * 2.0;
constexpr std::size_t kMidboss07EntityCap = 0x200;

std::uint16_t midboss07Angle(int angle) {
    return static_cast<std::uint16_t>(angle & 0xffff);
}

double midboss07Radians(std::uint16_t angle) {
    return static_cast<double>(angle) * kMidboss07Tau / 65536.0;
}

std::uint16_t midboss07AngleTo(float x0, float y0, float x1, float y1) {
    return midboss07Angle(static_cast<int>(
        std::atan2(static_cast<double>(y1 - y0),
                   static_cast<double>(x1 - x0)) *
        65536.0 / kMidboss07Tau));
}

int midboss07AngleDelta(std::uint16_t current, std::uint16_t target) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return delta;
}

std::uint16_t midboss07Approach(std::uint16_t current,
                                std::uint16_t target, int step) {
    const int delta = midboss07AngleDelta(current, target);
    return midboss07Angle(static_cast<int>(current) +
                          std::clamp(delta, -step, step));
}

std::uint32_t midboss07Rand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

double midboss07RandomRange(int seed, double minimum, double maximum) {
    const int minimum100 = static_cast<int>(minimum * 100.0);
    const int maximum100 = static_cast<int>(maximum * 100.0);
    if (minimum100 == maximum100) return minimum;
    return static_cast<double>(
               minimum100 +
               static_cast<int>(midboss07Rand(seed) %
                                static_cast<std::uint32_t>(
                                    maximum100 - minimum100 + 1))) /
           100.0;
}

int midboss07NodeUpdateCase(int spawnType) {
    if (spawnType >= 0x79 && spawnType <= 0x7d) return 0x57;
    if (spawnType == 0x7e || spawnType == 0x7f) return 0x58;
    return -1;
}

int midboss07Frame(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

bool midboss07InsideShotArea(float x, float y, float playerX) {
    const float horizontalOrigin = playerX / 6.0f;
    return x >= horizontalOrigin - 100.0f &&
           x <= horizontalOrigin + 700.0f &&
           y >= -100.0f && y <= 820.0f;
}

} // namespace

bool StageRuntime::isStage07MidbossType(int spawnType) const {
    return spawnType == 0x144 || spawnType == 0x145;
}

bool StageRuntime::isStage07MidbossNodeType(int spawnType) const {
    return spawnType >= 0x79 && spawnType <= 0x7f;
}

bool StageRuntime::spawnStage07MidbossNode(StageEnemy& parent, int spawnType,
                                           int childIndex, float xOrOffset,
                                           float yOrOffset,
                                           std::uint16_t angle16,
                                           double speed, int hitPoints,
                                           int radius, bool attached,
                                           int kind, bool countsForPhase) {
    if (!isStage07MidbossNodeType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kMidboss07EntityCap) {
        return false;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = midboss07NodeUpdateCase(spawnType);
    node.sourceHitPoints = hitPoints;
    node.sourceX = static_cast<int>(std::lround(xOrOffset));
    node.sourceY = static_cast<int>(std::lround(yOrOffset));
    node.sourceNote = "S07 FUN_1400dcd10/1400de960 internal entity";
    node.sourceDispatchKind = kind;
    node.sourceDispatchField = radius;
    node.rewardWeight = kind;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = parent.spawnType;
    node.childIndex = childIndex;
    node.originX = xOrOffset;
    node.originY = yOrOffset;
    node.x = attached ? parent.x + xOrOffset : xOrOffset;
    node.y = attached ? parent.y + yOrOffset : yOrOffset;
    node.markerDrawX = node.x;
    node.markerDrawY = node.y;
    node.sourceAngle16 = angle16;
    node.secondaryAngle16 = angle16;
    node.targetAngle16 = angle16;
    node.angle = static_cast<float>(midboss07Radians(angle16));
    node.sourceSpeed = speed;
    node.speed = static_cast<float>(speed);
    const double hpScale = config_.difficulty == 0 ? 0.8 : 1.0;
    node.hp = std::max(1, static_cast<int>(hitPoints * hpScale));
    node.maxHp = node.hp;
    node.drawHp = node.hp;
    node.radius = radius;
    node.activationDelay = 0;
    node.targetable = false;
    node.drawBodyThisFrame = spawnType != 0x79;
    pendingEnemies_.push_back(node);
    if (countsForPhase) ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage07Midboss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawMarkerThisFrame = false;
    enemy.drawBodyThisFrame = true;

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int state = enemy.helperState;

    if ((state == 1 || state == 2) &&
        (enemy.hp < 1 || lateStageBossCountdown_ < 1)) {
        const bool expired = lateStageBossCountdown_ < 1;
        if (expired) {
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
        enemy.liveChildCount = 0;
        enemy.helperState = 3;
        enemy.helperTimer = 0;
        lateStageBossBreaksRemaining_ = 0;
        lateStageBossPhaseMode_ = -1;
        lateStageBossCountdown_ = 0;
        lateStageBossCountdownDraw_ = 0;
    }

    const int activeState = enemy.helperState;
    const int activeTimer = enemy.helperTimer;
    const double horizontalWave =
        std::sin(static_cast<double>(frame_) * kMidboss07Tau / 555.0);
    enemy.x = static_cast<float>(enemy.sourceX) +
              static_cast<float>(horizontalWave *
                                 (enemy.spawnType == 0x144 ? 10.0 : -10.0));

    if (activeState == 0) {
        enemy.targetable = false;
        lateStageBossPhaseMode_ = 0;
        if (activeTimer == 0) {
            enemy.liveChildCount = 0;
            spawnStage07MidbossNode(enemy, 0x79, 0, 0.0f, 130.0f,
                                    0x4000, 1.0, 99999999, 70,
                                    true, 0, false);
            if (enemy.spawnType == 0x144) {
                spawnStage07MidbossNode(enemy, 0x7a, 1, 188.0f, 110.0f,
                                        0x4000, 1.0, 20000, 45,
                                        true, 60, true);
                spawnStage07MidbossNode(enemy, 0x7a, 2, -188.0f, 110.0f,
                                        0x4000, 1.0, 20000, 45,
                                        true, 60, true);
                spawnStage07MidbossNode(enemy, 0x7c, 3, 110.0f, -70.0f,
                                        0x4000, 1.0, 10000, 40,
                                        true, 30, true);
                spawnStage07MidbossNode(enemy, 0x7c, 4, -110.0f, -70.0f,
                                        0x4000, 1.0, 10000, 40,
                                        true, 30, true);
            }
            else {
                spawnStage07MidbossNode(enemy, 0x7b, 1, 188.0f, 110.0f,
                                        0x4000, 1.0, 15000, 45,
                                        true, 60, true);
                spawnStage07MidbossNode(enemy, 0x7b, 2, -188.0f, 110.0f,
                                        0x4000, 1.0, 15000, 45,
                                        true, 60, true);
                static constexpr std::array<float, 4> kOffsetsX{{
                    60.0f, -60.0f, 150.0f, -150.0f,
                }};
                static constexpr std::array<float, 4> kOffsetsY{{
                    -70.0f, -70.0f, -70.0f, -70.0f,
                }};
                for (int i = 0; i < 4; ++i) {
                    spawnStage07MidbossNode(
                        enemy, 0x7d, 3 + i,
                        kOffsetsX[static_cast<std::size_t>(i)],
                        kOffsetsY[static_cast<std::size_t>(i)],
                        0x4000, 1.0, 6000, 40, true, 30, true);
                }
            }
            playPlayerSound(bossSe8SoundHandle_, 0x19);
        }

        if (activeTimer < 120) {
            enemy.y = 900.0f - static_cast<float>(static_cast<int>(
                std::sin(static_cast<double>(activeTimer) * kMidboss07Pi /
                         240.0) * 800.0));
        }
        else {
            enemy.y = 100.0f;
        }

        if (activeTimer == 130) {
            const int hitPoints = enemy.spawnType == 0x144 ? 80000 : 60000;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.hp = hitPoints;
            enemy.maxHp = hitPoints;
            enemy.drawHp = hitPoints;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
            lateStageBossBreaksRemaining_ = 1;
            lateStageBossPhaseIndex_ = 0;
            lateStageBossPhaseMode_ = 1;
            lateStageBossMaxHp_ = hitPoints;
            lateStageBossCountdown_ = 0x834;
            lateStageBossCountdownDraw_ = lateStageBossCountdown_;
        }
    }
    else if (activeState == 1 || activeState == 2) {
        enemy.targetable = true;
        enemy.y = 125.0f - static_cast<float>(
            std::sin(static_cast<double>(activeTimer + 222) *
                     kMidboss07Tau / 888.0) * 25.0);
        const int cycle = activeTimer % 0x578;
        const auto aimed = midboss07AngleTo(
            enemy.x, enemy.y + 40.0f, player_.x, player_.y);
        bool fired = false;

        if (enemy.spawnType == 0x144) {
            static constexpr std::array<int, 5> kMinionInterval{{
                18, 12, 10, 8, 8,
            }};
            static constexpr std::array<int, 5> kRingCount{{
                7, 9, 11, 13, 15,
            }};
            static constexpr std::array<double, 5> kFirstRingSpeed{{
                3.2, 3.5, 4.0, 4.5, 5.5,
            }};
            static constexpr std::array<double, 5> kSecondRingSpeed{{
                5.2, 5.5, 6.0, 6.5, 7.5,
            }};

            const int minionPeriod = activeState == 1 ? 0xa4 : 0x54;
            const int local = (cycle - 10) % minionPeriod;
            const bool minionWindow = cycle >= 10 && local >= 0 && local < 60 &&
                (activeState == 2 || cycle < 600);
            if (minionWindow &&
                local % kMinionInterval[static_cast<std::size_t>(difficulty)] == 0) {
                const std::uint32_t random = midboss07Rand(activeTimer);
                spawnStage07MidbossNode(
                    enemy, 0x7e, activeTimer,
                    enemy.x, enemy.y + 40.0f,
                    midboss07Angle(static_cast<int>(random % 0x8001u)),
                    midboss07RandomRange(activeTimer, 5.0, 10.0),
                    500, 20, false,
                    activeState == 1 ? 3 : 0, false);
            }

            if (activeState == 1 && cycle >= 800 && cycle < 0x550 &&
                (cycle - 800) % 0x52 == 0) {
                const int count = kRingCount[static_cast<std::size_t>(difficulty)];
                const double speed =
                    kFirstRingSpeed[static_cast<std::size_t>(difficulty)] +
                    static_cast<double>(cycle - 800) * 0.002;
                spawnProjectileSpread(3, 0, enemy.x, enemy.y + 40.0f,
                                      aimed, 10.0f, speed, 1,
                                      count, 0x8000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(3, 0, enemy.x, enemy.y + 40.0f,
                                          aimed, 10.0f, speed + 1.0, 1,
                                          count, 0x8000, 0);
                }
                fired = true;
            }
            if (activeState == 2 && activeTimer % 0x29 == 0) {
                const int count = kRingCount[static_cast<std::size_t>(difficulty)];
                const double speed =
                    kSecondRingSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(3, 0, enemy.x, enemy.y + 40.0f,
                                      aimed, 10.0f, speed, 1,
                                      count, 0x8000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(3, 0, enemy.x, enemy.y + 40.0f,
                                          aimed, 10.0f, speed + 1.0, 1,
                                          count, 0x8000, 0);
                }
                fired = true;
            }
        }
        else {
            static constexpr std::array<int, 5> kMinionWindow{{
                40, 60, 80, 100, 100,
            }};
            const int minionLocal = (cycle - 10) % 0xb8;
            if ((activeState == 2 || cycle < 0x230) && cycle > 9 &&
                minionLocal >= 0 &&
                minionLocal < kMinionWindow[static_cast<std::size_t>(difficulty)] &&
                minionLocal % 10 == 0) {
                const std::uint32_t random = midboss07Rand(activeTimer + 2);
                spawnStage07MidbossNode(
                    enemy, 0x7f, activeTimer,
                    enemy.x, enemy.y + 40.0f,
                    midboss07Angle(static_cast<int>(random % 0x8001u)),
                    midboss07RandomRange(activeTimer, 5.0, 10.0),
                    500, 20, false, 3, false);
            }

            static constexpr std::array<int, 5> kInterval{{
                0xa4, 0x7b, 0x52, 0x52, 0x29,
            }};
            static constexpr std::array<int, 5> kWindow{{
                0x78, 100, 0x50, 0x50, 0x28,
            }};
            static constexpr std::array<int, 5> kStride{{
                0x0b, 6, 4, 4, 3,
            }};
            static constexpr std::array<double, 5> kFirstSpeed{{
                4.0, 4.5, 5.0, 4.0, 6.0,
            }};
            static constexpr std::array<double, 5> kSecondSpeed{{
                5.5, 6.0, 6.5, 5.5, 6.5,
            }};

            const int start = activeState == 1 ? 600 : 0;
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            const int local = (cycle - start) % interval;
            const bool inPattern = cycle >= start &&
                (activeState == 2 || cycle < 0x550);
            if (inPattern && local == 0) {
                enemy.secondaryAngle16 = aimed;
            }
            if (inPattern && local >= 0 &&
                local < kWindow[static_cast<std::size_t>(difficulty)] &&
                local % kStride[static_cast<std::size_t>(difficulty)] == 0) {
                const int window = kWindow[static_cast<std::size_t>(difficulty)];
                const int sweep = (0x8000 / window) * local - 0x4000;
                const double sweepRadians = midboss07Radians(
                    midboss07Angle(sweep));
                const float firstX = enemy.x +
                    static_cast<float>(std::cos(sweepRadians) * 50.0);
                const float firstY = enemy.y + 40.0f +
                    static_cast<float>(std::sin(sweepRadians) * 50.0);
                const float secondX = enemy.x -
                    static_cast<float>(std::cos(sweepRadians) * 50.0);
                const float secondY = enemy.y + 40.0f -
                    static_cast<float>(std::sin(sweepRadians) * 50.0);
                const double speed =
                    (activeState == 1
                         ? kFirstSpeed[static_cast<std::size_t>(difficulty)] +
                               static_cast<double>(cycle - 600) * 0.004
                         : kSecondSpeed[static_cast<std::size_t>(difficulty)]);
                const int aim = static_cast<int>(enemy.secondaryAngle16);
                spawnProjectileNode(0x0d, 2, firstX, firstY,
                                    midboss07Angle(aim + sweep - 2000),
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(0x0d, 2, secondX, secondY,
                                    midboss07Angle(aim - sweep + 2000),
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(0x0d, 2, firstX, firstY,
                                    midboss07Angle(aim + sweep - 0x8000),
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(0x0d, 2, secondX, secondY,
                                    midboss07Angle(aim - sweep - 0x8000),
                                    0.0f, speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(0x0d, 2, firstX, firstY,
                                        midboss07Angle(aim + sweep - 0x0afa),
                                        0.0f, speed + 1.5, 1, 0);
                    spawnProjectileNode(0x0d, 2, secondX, secondY,
                                        midboss07Angle(aim - sweep + 0x0afa),
                                        0.0f, speed + 1.5, 1, 0);
                }
                fired = true;
            }
        }

        if (fired) playPlayerSound(bullet2SoundHandle_, 0x0c);
        if (activeState == 1 && enemy.liveChildCount < 1) {
            enemy.helperState = 2;
        }
        updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
        --lateStageBossCountdown_;
    }
    else if (activeState == 3) {
        enemy.targetable = false;
        if (activeTimer < 60) {
            if (activeTimer % 3 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
            enemy.y += static_cast<float>(activeTimer) * 0.1f;
        }
        if (activeTimer == 60) {
            spawnEnemyDeathEffects(enemy, 2);
        }
        if (activeTimer >= 120) {
            clearLateStageGate(7);
            enemy.active = false;
        }
        enemy.drawBodyThisFrame = activeTimer <= 69;
    }

    enemy.drawHp = enemy.hp;
    lateStageBossCountdownDraw_ = lateStageBossCountdown_;
}

void StageRuntime::updateStage07MidbossNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawMarkerThisFrame = false;
    enemy.drawBodyThisFrame = enemy.spawnType != 0x79;
    enemy.drawHp = enemy.hp;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || !isStage07MidbossType(parent->spawnType) ||
        !parent->active) {
        enemy.targetable = false;
        enemy.active = false;
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int parentState = parent->helperState;
    const int parentTimer = parent->helperTimer;

    if (enemy.spawnType == 0x79) {
        enemy.x = parent->x + enemy.originX;
        enemy.y = parent->y + enemy.originY;
        enemy.targetable = (parentState == 1 || parentState == 2) &&
                           parent->targetable;
        if (parentState == 1 && parentTimer <= 1) {
            enemy.hp = parent->hp;
            enemy.maxHp = parent->maxHp;
            enemy.sourceHitPoints = parent->hp;
        }
        if (parentState == 1 || parentState == 2) {
            const int sharedHp = std::max(0, std::min(parent->hp, enemy.hp));
            parent->hp = sharedHp;
            enemy.hp = sharedHp;
            parent->drawHp = sharedHp;
            enemy.drawHp = sharedHp;
        }
        if (parentState == 3) {
            enemy.targetable = false;
            enemy.active = false;
        }
        return;
    }

    if (enemy.spawnType >= 0x7a && enemy.spawnType <= 0x7d) {
        const float baseX = parent->x + enemy.originX;
        const float baseY = parent->y + enemy.originY;
        enemy.markerDrawX = baseX;
        enemy.markerDrawY = baseY;
        if (enemy.spawnType == 0x7c || enemy.spawnType == 0x7d) {
            const double currentAngle = midboss07Radians(
                enemy.sourceAngle16);
            enemy.x = baseX +
                      static_cast<float>(std::cos(currentAngle) * 20.0);
            enemy.y = baseY +
                      static_cast<float>(std::sin(currentAngle) * 20.0);
        }
        else {
            enemy.x = baseX;
            enemy.y = baseY;
        }

        enemy.targetable = enemy.helperState == 0 && parentState == 1;
        bool fired = false;
        const auto aimed = midboss07AngleTo(
            enemy.x, enemy.y + 10.0f, player_.x, player_.y);

        if (enemy.helperState == 0 && parentState == 1 &&
            enemy.spawnType == 0x7a) {
            const int cycle = parentTimer % 0x578;
            if (cycle < 0x26c) {
                static constexpr std::array<int, 5> kPeriod{{
                    0xa4, 0x7b, 0x7b, 0x7b, 0x7b,
                }};
                static constexpr std::array<int, 5> kBaseCount{{
                    1, 3, 5, 5, 7,
                }};
                static constexpr std::array<int, 5> kWindow{{
                    25, 30, 40, 50, 50,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    5.5, 6.0, 6.5, 7.0, 9.0,
                }};
                const int period = kPeriod[static_cast<std::size_t>(difficulty)];
                if (cycle >= 90) {
                    const int local = (cycle - 90) % period;
                    const int count =
                        kBaseCount[static_cast<std::size_t>(difficulty)] +
                        ((cycle - 90) / (period * 2)) * 2;
                    if (local == 0) enemy.secondaryAngle16 = aimed;
                    const double speed =
                        kSpeed[static_cast<std::size_t>(difficulty)] +
                        static_cast<double>(local) * 0.1 *
                            static_cast<double>(cycle) * 0.002;
                    if (local < kWindow[static_cast<std::size_t>(difficulty)] &&
                        local % 5 == 0) {
                        spawnProjectileSpread(2, 0, enemy.x, enemy.y + 10.0f,
                                              enemy.secondaryAngle16, 10.0f,
                                              speed, 1, count, 27000, 0);
                        if (difficulty > 2) {
                            spawnProjectileSpread(
                                2, 0, enemy.x, enemy.y + 10.0f,
                                enemy.secondaryAngle16, 10.0f,
                                speed - 2.5, 1, count, 27000, 0);
                        }
                        fired = true;
                    }
                }
                enemy.secondaryAngle16 = midboss07Approach(
                    enemy.secondaryAngle16, aimed, 0x20);
            }
        }
        else if (enemy.helperState == 0 && parentState == 1 &&
                 enemy.spawnType == 0x7b) {
            const int cycle = parentTimer % 0x578;
            if (cycle < 0x262) {
                static constexpr std::array<int, 5> kPeriod{{
                    45, 30, 25, 25, 25,
                }};
                static constexpr std::array<int, 5> kBaseCount{{
                    6, 9, 12, 11, 13,
                }};
                static constexpr std::array<int, 5> kRotation{{
                    70, 100, 110, 120, 140,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    4.0, 5.0, 6.0, 6.0, 7.2,
                }};
                int intactCount = 0;
                for (const auto& candidate : enemies_) {
                    if (candidate.parentEntityId == parent->entityId &&
                        candidate.spawnType == 0x7b &&
                        candidate.helperState == 0 && candidate.hp > 0) {
                        ++intactCount;
                    }
                }
                if (cycle >= 120 && (cycle - 120) % 123 == 0) {
                    enemy.secondaryAngle16 = aimed;
                }
                const int count =
                    kBaseCount[static_cast<std::size_t>(difficulty)] +
                    (cycle >= 120 ? ((cycle - 120) / 123) * 2 : 0);
                int rotation = kRotation[static_cast<std::size_t>(difficulty)];
                if (cycle >= 120 && (cycle - 120) % 246 > 122) {
                    rotation = -rotation;
                }
                const bool left = enemy.originX < 0.0f;
                const int loops = intactCount >= 2 ? 2 : 4;
                int intactThreshold = left ? 120 : 243;
                int reducedThreshold = 120;
                const int period = kPeriod[static_cast<std::size_t>(difficulty)];
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    static_cast<double>(cycle) * 0.004;
                for (int i = 0; i < loops; ++i) {
                    const int threshold = intactCount >= 2
                                              ? intactThreshold
                                              : reducedThreshold;
                    if (cycle >= threshold && cycle < threshold + 100) {
                        const int local = (cycle - threshold) % period;
                        if (local < 16 && local % 4 == 0) {
                            spawnProjectileSpread(
                                0x0b, 0, enemy.x, enemy.y + 10.0f,
                                enemy.secondaryAngle16, 10.0f,
                                speed, 1, count, 0x10000, 0);
                            if (difficulty > 2) {
                                spawnProjectileSpread(
                                    0x0b, 0, enemy.x, enemy.y + 10.0f,
                                    midboss07Angle(
                                        static_cast<int>(enemy.secondaryAngle16) +
                                        800),
                                    10.0f, speed, 1, count, 0x10000, 0);
                            }
                            fired = true;
                        }
                    }
                    intactThreshold += 246;
                    reducedThreshold += 123;
                }
                enemy.secondaryAngle16 = midboss07Angle(
                    static_cast<int>(enemy.secondaryAngle16) + rotation);
            }
        }
        else if (enemy.helperState == 0 && parentState == 1 &&
                 enemy.spawnType == 0x7c) {
            const int cycle = parentTimer % 0x578;
            const auto centerAim = midboss07AngleTo(
                enemy.x, enemy.y, parent->x, parent->y + 170.0f);
            if (cycle < 600) {
                const int step = std::abs(midboss07AngleDelta(
                                     enemy.sourceAngle16, centerAim)) /
                                 10 + 0x30;
                enemy.sourceAngle16 = midboss07Approach(
                    enemy.sourceAngle16, centerAim, step);
            }
            else if (cycle < 700) {
                const auto horizontal = static_cast<std::uint16_t>(
                    enemy.originX < 0.0f ? 0x8000 : 0);
                const int step = std::abs(midboss07AngleDelta(
                                     enemy.sourceAngle16, horizontal)) /
                                 10 + 0x30;
                enemy.sourceAngle16 = midboss07Approach(
                    enemy.sourceAngle16, horizontal, step);
            }
            else {
                static constexpr std::array<int, 5> kInterval{{
                    12, 8, 7, 6, 5,
                }};
                static constexpr std::array<int, 5> kCount{{
                    3, 5, 6, 7, 8,
                }};
                static constexpr std::array<int, 5> kRotation{{
                    240, 300, 350, 350, 350,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    4.5, 5.5, 6.0, 6.5, 7.5,
                }};
                const int direction = enemy.originX < 0.0f ? -1 : 1;
                enemy.sourceAngle16 = midboss07Angle(
                    static_cast<int>(enemy.sourceAngle16) +
                    direction * (cycle - 700 +
                        kRotation[static_cast<std::size_t>(difficulty)]));
                if (cycle < 0x550 &&
                    (cycle - 700) %
                            kInterval[static_cast<std::size_t>(difficulty)] ==
                        0) {
                    int count = kCount[static_cast<std::size_t>(difficulty)];
                    if (parent->liveChildCount == 1) count += 2;
                    const double radians = midboss07Radians(
                        enemy.sourceAngle16);
                    const float sourceX = enemy.markerDrawX +
                        static_cast<float>(std::cos(radians) * 50.0);
                    const float sourceY = enemy.markerDrawY +
                        static_cast<float>(std::sin(radians) * 50.0);
                    const double speed =
                        kSpeed[static_cast<std::size_t>(difficulty)] +
                        static_cast<double>(cycle - 700) * 0.001;
                    spawnProjectileSpread(
                        0x0c, 0, sourceX, sourceY,
                        enemy.sourceAngle16, 10.0f, speed, 1,
                        count, (count - 1) * 0x115c, 0);
                    fired = true;
                }
            }
        }
        else if (enemy.helperState == 0 && parentState == 1 &&
                 enemy.spawnType == 0x7d) {
            const int cycle = parentTimer % 0x578;
            const auto centerAim = midboss07AngleTo(
                enemy.x, enemy.y, parent->x, parent->y + 170.0f);
            const auto playerAim = midboss07AngleTo(
                enemy.x, enemy.y, player_.x, player_.y);
            if (cycle < 620) {
                enemy.secondaryAngle16 = centerAim;
                const int step = std::abs(midboss07AngleDelta(
                                     enemy.sourceAngle16, centerAim)) /
                                 10 + 0x30;
                enemy.sourceAngle16 = midboss07Approach(
                    enemy.sourceAngle16, centerAim, step);
            }
            else if (cycle < 660) {
                enemy.secondaryAngle16 = playerAim;
                const int step = std::abs(midboss07AngleDelta(
                                     enemy.sourceAngle16, playerAim)) /
                                 10 + 0x30;
                enemy.sourceAngle16 = midboss07Approach(
                    enemy.sourceAngle16, playerAim, step);
            }
            else {
                static constexpr std::array<int, 5> kInterval{{
                    33, 27, 27, 27, 21,
                }};
                static constexpr std::array<int, 5> kWindow{{
                    9, 12, 15, 15, 15,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    5.5, 6.5, 8.0, 7.0, 9.0,
                }};
                const int interval =
                    kInterval[static_cast<std::size_t>(difficulty)];
                const int local = (cycle - 660) % interval;
                const double radians = midboss07Radians(
                    enemy.sourceAngle16);
                const float sourceX = enemy.markerDrawX +
                    static_cast<float>(std::cos(radians) * 50.0);
                const float sourceY = enemy.markerDrawY +
                    static_cast<float>(std::sin(radians) * 50.0);
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    static_cast<double>(cycle - 660) * 0.001;
                if (cycle < 0x550 &&
                    local < kWindow[static_cast<std::size_t>(difficulty)] &&
                    local % 3 == 0) {
                    spawnProjectileNode(6, 0, sourceX, sourceY,
                                        enemy.sourceAngle16, 10.0f,
                                        speed, 1, 0);
                    if (difficulty > 2) {
                        spawnProjectileNode(6, 0, sourceX, sourceY,
                                            enemy.sourceAngle16, 10.0f,
                                            speed + 2.0, 1, 0);
                    }
                    fired = true;
                }
                if (local >= kWindow[static_cast<std::size_t>(difficulty)] - 2) {
                    enemy.sourceAngle16 = midboss07Approach(
                        enemy.sourceAngle16, enemy.secondaryAngle16, 0x8ae);
                }
            }
        }

        if (fired) playPlayerSound(bullet2SoundHandle_, 0x0c);

        if (enemy.helperState == 0 && enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x960, false);
            spawnDelayedOwnerDamageNode(
                enemy.maxHp, parent->entityId, parent->spawnType,
                "S07 midboss child delayed-damage node 0x153");
            if (enemy.spawnType == 0x7a || enemy.spawnType == 0x7b) {
                spawnEnemyDeathEffects(enemy, 2);
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = false;
            }
            else {
                spawnEnemyDeathEffects(enemy, 1);
                enemy.targetable = false;
                enemy.active = false;
            }
            parent->liveChildCount = std::max(0, parent->liveChildCount - 1);
        }

        if (parentState == 3) {
            enemy.targetable = false;
            enemy.active = false;
        }
        return;
    }

    const auto moveAlong = [&enemy]() {
        const double radians = midboss07Radians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
    };

    if (enemy.spawnType == 0x7e || enemy.spawnType == 0x7f) {
        enemy.targetable = true;
        bool fired = false;
        const int timer = enemy.helperTimer;

        if (enemy.helperState == 0) {
            const double initialSpeed = enemy.sourceSpeed;
            enemy.sourceSpeed = initialSpeed -
                (initialSpeed / 40.0) * static_cast<double>(timer);
            moveAlong();
            enemy.sourceSpeed = initialSpeed;
            if (timer == 0) enemy.secondaryAngle16 = 0x4000;
            if (timer == 40) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetableTimer = 0;
                if (enemy.spawnType == 0x7e) {
                    enemy.sourceSpeed = 1.2;
                    const auto aimed = midboss07AngleTo(
                        enemy.x, enemy.y, player_.x, player_.y);
                    const int jitter = static_cast<int>(
                        midboss07Rand(frame_) % 0x115du) - 0x8ae;
                    enemy.sourceAngle16 = midboss07Angle(
                        static_cast<int>(aimed) + jitter);
                    enemy.targetAngle16 = aimed;
                }
                else {
                    enemy.sourceSpeed = 0.0;
                    enemy.sourceAngle16 = 0x4000;
                    enemy.secondaryAngle16 = 0x4000;
                    enemy.targetAngle16 = midboss07AngleTo(
                        enemy.x, enemy.y, player_.x, player_.y);
                }
            }
        }
        else if (enemy.helperState == 1) {
            const double radians = midboss07Radians(enemy.sourceAngle16);
            const float sourceX = enemy.x +
                static_cast<float>(std::cos(radians) * 14.0);
            const float sourceY = enemy.y +
                static_cast<float>(std::sin(radians) * 14.0);

            if (enemy.spawnType == 0x7e) {
                static constexpr std::array<int, 5> kInterval{{
                    120, 80, 60, 60, 50,
                }};
                static constexpr std::array<int, 5> kWindow{{
                    15, 24, 30, 30, 30,
                }};
                static constexpr std::array<double, 5> kSpeed{{
                    6.5, 7.5, 8.0, 9.0, 10.0,
                }};
                if (timer < 180) {
                    if (timer <= 150) {
                        const int interval =
                            kInterval[static_cast<std::size_t>(difficulty)];
                        if (timer % interval == 0) {
                            enemy.targetAngle16 = midboss07AngleTo(
                                sourceX, sourceY, player_.x, player_.y);
                        }
                        const int local = timer % interval;
                        const double dx = static_cast<double>(player_.x - sourceX);
                        const double dy = static_cast<double>(player_.y - sourceY);
                        if (local < kWindow[static_cast<std::size_t>(difficulty)] &&
                            local % 3 == 0 &&
                            midboss07InsideShotArea(sourceX, sourceY, player_.x) &&
                            dx * dx + dy * dy > 2500.0) {
                            spawnProjectileNode(
                                7, 0, sourceX, sourceY,
                                enemy.targetAngle16, 10.0f,
                                kSpeed[static_cast<std::size_t>(difficulty)],
                                1, 0);
                            fired = true;
                        }
                    }
                }
                else {
                    enemy.sourceSpeed += 0.1;
                }
                moveAlong();
            }
            else {
                static constexpr std::array<double, 5> kSpeed{{
                    7.5, 9.0, 11.0, 15.0, 15.0,
                }};
                static constexpr std::array<int, 5> kSpread{{
                    0, 0x4b0, 0x708, 0x960, 3000,
                }};
                const int turnStep =
                    std::abs(midboss07AngleDelta(
                        enemy.sourceAngle16,
                        midboss07AngleTo(enemy.x, enemy.y,
                                         player_.x, player_.y))) /
                        10 +
                    0x30;
                enemy.sourceAngle16 = midboss07Approach(
                    enemy.sourceAngle16, enemy.targetAngle16, turnStep);
                enemy.secondaryAngle16 = enemy.sourceAngle16;
                if (timer > 29) {
                    enemy.sourceSpeed += 0.1;
                    if ((timer - 30) % 3 == 0 &&
                        midboss07InsideShotArea(sourceX, sourceY, player_.x)) {
                        const double speed =
                            kSpeed[static_cast<std::size_t>(difficulty)];
                        spawnProjectileNode(4, 3, sourceX, sourceY,
                                            enemy.sourceAngle16, 0.0f,
                                            speed, 1, 0);
                        if (difficulty > 0) {
                            spawnProjectileSpread(
                                4, 3, sourceX, sourceY,
                                enemy.sourceAngle16, 0.0f,
                                speed - 0.5, 1, 2,
                                kSpread[static_cast<std::size_t>(difficulty)],
                                0);
                        }
                        fired = true;
                    }
                }
                moveAlong();
            }
        }

        if (fired) playPlayerSound(bullet1SoundHandle_, 0x0c);
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 300, false);
            spawnEnemyDeathEffects(enemy, 0);
            spawnDelayedOwnerDamageNode(
                enemy.maxHp, parent->entityId, parent->spawnType,
                "S07 midboss projectile delayed-damage node 0x153");
            enemy.targetable = false;
            enemy.active = false;
        }
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.x < horizontalOrigin - 100.0f ||
            enemy.x > horizontalOrigin + 700.0f ||
            enemy.y < -100.0f || enemy.y > 820.0f ||
            parentState == 3) {
            enemy.targetable = false;
            enemy.active = false;
        }
    }
}

bool StageRuntime::drawStage07Midboss(const StageEnemy& enemy, float x,
                                      float y) const {
    if (!isStage07MidbossType(enemy.spawnType)) return false;
    if (!enemy.drawBodyThisFrame) return true;

    const auto draw = [this](const std::vector<int>& frames, int frame,
                             float drawX, float drawY,
                             std::uint16_t angle = 0,
                             double scale = 1.0,
                             bool reverse = false) {
        const int handle = midboss07Frame(frames, frame);
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle,
                                  scale, scale, reverse);
        }
    };

    static constexpr std::array<int, 16> kFirstBody{{
        0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x57, 0x56,
        0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x50, 0x51,
    }};
    static constexpr std::array<int, 16> kSecondBody{{
        0x60, 0x5f, 0x5e, 0x5d, 0x5c, 0x5a, 0x5b, 0x5a,
        0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x61, 0x60, 0x61,
    }};

    const bool first = enemy.spawnType == 0x144;
    const auto& bodySequence = first ? kFirstBody : kSecondBody;
    const int bodyFrame = bodySequence[
        static_cast<std::size_t>((std::max(0, frame_ - 1) / 5) % 16)];
    const int armFrame = 0x62 + (std::max(0, frame_ - 1) / 3) % 2;
    const float upperY = y + 300.0f;

    draw(enemyLargeFrames_, 48, x, y + 164.0f);
    draw(enemySmallFrames_, armFrame, x + 160.0f, upperY);
    draw(enemySmallFrames_, armFrame, x + 90.0f, upperY);
    draw(enemySmallFrames_, armFrame, x - 160.0f, upperY);
    draw(enemySmallFrames_, armFrame, x - 90.0f, upperY);
    draw(enemyLargeFrames_, 45, x, y + 140.0f);
    if (midboss07Rand(frame_) % 5u != 0u) {
        draw(enemyLargeFrames_, first ? 46 : 47, x, y + 140.0f);
    }
    draw(enemyLargeFrames_, first ? 42 : 43, x, y + 140.0f);
    draw(bossFrames_, bodyFrame, x, y + 120.0f);

    const double pulse = 1.0 +
        std::sin(static_cast<double>(std::max(0, frame_ - 1)) *
                 kMidboss07Tau / 82.0) *
            0.05;
    draw(enemyMediumFrames_, first ? 126 : 130, x, y, 0, pulse);

    int animation = first ? 127 : 131;
    const int state = enemy.drawHelperState;
    const int timer = enemy.drawHelperTimer;
    if (state == 2) {
        animation = first ? 129 : 133;
    }
    else if (state == 3) {
        animation = (first ? 127 : 131) +
                    std::min(2, std::max(0, timer) / 3);
    }
    else if (state == 1) {
        const int cycle = timer % 0x578;
        if (first) {
            const int local = cycle < 600 ? cycle % 0xa4
                                          : (cycle + -0x30c) % 0x52;
            if (local < 10) animation = 128 + (local / 5);
            else if ((cycle < 600 && local < 60) ||
                     (cycle >= 600 && local < 40)) animation = 129;
            else if ((cycle < 600 && local < 70) ||
                     (cycle >= 600 && local < 50)) animation = 128;
        }
        else {
            static constexpr std::array<int, 5> kWindow{{
                40, 60, 80, 100, 100,
            }};
            const int local = cycle % 0xb8;
            const int window = kWindow[static_cast<std::size_t>(
                std::clamp(config_.difficulty, 0, 4))];
            if (local < 10) animation = 132 + local / 5;
            else if (local < window) animation = 133;
            else if (local < window + 10) animation = 132;
        }
    }
    draw(enemyMediumFrames_, animation, x, y);
    draw(enemyLargeFrames_, 44, x, y + 140.0f);
    return true;
}

bool StageRuntime::drawStage07MidbossNode(const StageEnemy& enemy, float x,
                                          float y) const {
    if (!isStage07MidbossNodeType(enemy.spawnType)) return false;
    if (enemy.spawnType == 0x79 || !enemy.drawBodyThisFrame) return true;

    const auto draw = [this](const std::vector<int>& frames, int frame,
                             float drawX, float drawY,
                             std::uint16_t angle = 0,
                             double scale = 1.0,
                             bool reverse = false) {
        const int handle = midboss07Frame(frames, frame);
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle,
                                  scale, scale, reverse);
        }
    };

    if (enemy.spawnType == 0x7a || enemy.spawnType == 0x7b) {
        const int frame = enemy.spawnType == 0x7a
                              ? (enemy.drawHelperState == 0 ? 134 : 136)
                              : (enemy.drawHelperState == 0 ? 135 : 137);
        draw(enemyMediumFrames_, frame, x, y + 10.0f, 0, 1.0,
             enemy.originX < 0.0f);
        if (enemy.drawHelperState == 0 && enemy.targetable) {
            drawEnemyGaugeExact(enemy, 1, x, y);
        }
        return true;
    }

    if (enemy.spawnType == 0x7c || enemy.spawnType == 0x7d) {
        const float baseX = x + (enemy.markerDrawX - enemy.x);
        const float baseY = y + (enemy.markerDrawY - enemy.y);
        const double radians = midboss07Radians(enemy.sourceAngle16);
        const float weaponX = baseX +
            static_cast<float>(std::cos(radians) * 120.0);
        const float weaponY = baseY +
            static_cast<float>(std::sin(radians) * 120.0);
        SetDrawBright(enemy.spawnType == 0x7c ? 255 : 0,
                      enemy.spawnType == 0x7c ? 0 : 255, 255);
        draw(enemySmallFrames_, 81, weaponX, weaponY,
             enemy.sourceAngle16, 0.9);
        SetDrawBright(255, 255, 255);
        draw(enemySmallFrames_, 100, baseX, baseY,
             enemy.sourceAngle16);
        if (enemy.targetable) drawEnemyGaugeExact(enemy, 2, x, y);
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    double scale = 1.0;
    if (enemy.drawHelperState == 0) {
        scale = 0.2 + 0.8 * std::sin(
            static_cast<double>(std::clamp(timer, 0, 40)) *
            kMidboss07Pi / 80.0);
    }
    const int animation = (std::max(0, frame_ - 1) / 3) % 4;
    const int bodyFrame = enemy.spawnType == 0x7e
                              ? std::array<int, 4>{{101, 102, 103, 102}}[
                                    static_cast<std::size_t>(animation)]
                              : std::array<int, 4>{{105, 106, 107, 106}}[
                                    static_cast<std::size_t>(animation)];
    const std::uint16_t bodyAngle = enemy.spawnType == 0x7e
                                        ? 0
                                        : midboss07Angle(
                                              static_cast<int>(
                                                  enemy.sourceAngle16) -
                                              0x4000);
    draw(enemySmallFrames_, bodyFrame, x, y, bodyAngle, scale);

    const double radians = midboss07Radians(enemy.sourceAngle16);
    const float rearX = x -
        static_cast<float>(std::cos(radians) * 24.0 * scale);
    const float rearY = y -
        static_cast<float>(std::sin(radians) * 24.0 * scale);
    if (enemy.spawnType == 0x7e) {
        draw(enemySmallFrames_, 104, rearX, rearY,
             midboss07Angle(timer * 0xc80), scale);
        draw(enemySmallFrames_, 104, rearX, rearY,
             midboss07Angle(timer * 0xc80 - 0x8000), scale);
    }
    else {
        draw(enemySmallFrames_, 108, rearX, rearY,
             midboss07Angle(static_cast<int>(enemy.sourceAngle16) +
                            timer * 0x180 - 0x4000),
             scale);
        draw(enemySmallFrames_, 108, rearX, rearY,
             midboss07Angle(static_cast<int>(enemy.sourceAngle16) -
                            timer * 0x180 + 0x4000),
             scale);
    }
    if (enemy.targetable) drawEnemyGaugeExact(enemy, 2, x, y);
    return true;
}

} // namespace reconstructed
