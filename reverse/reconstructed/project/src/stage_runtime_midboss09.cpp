#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kMidboss09Pi = 3.14159265358979323846;
constexpr double kMidboss09Tau = kMidboss09Pi * 2.0;

std::uint16_t midboss09Angle(int value) {
    return static_cast<std::uint16_t>(value & 0xffff);
}

double midboss09Radians(std::uint16_t angle) {
    return static_cast<double>(angle) * kMidboss09Tau / 65536.0;
}

std::uint16_t midboss09AngleTo(float x0, float y0, float x1, float y1) {
    return midboss09Angle(static_cast<int>(
        std::atan2(static_cast<double>(y1 - y0),
                   static_cast<double>(x1 - x0)) *
        65536.0 / kMidboss09Tau));
}

int midboss09AngleDelta(std::uint16_t current, std::uint16_t target) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return delta;
}

std::uint16_t midboss09Approach(std::uint16_t current,
                                std::uint16_t target, int step) {
    const int delta = midboss09AngleDelta(current, target);
    return midboss09Angle(static_cast<int>(current) +
                          std::clamp(delta, -step, step));
}

std::uint32_t midboss09Rand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

double midboss09RandomHundredth(int seed, double minimum, double maximum) {
    const int minimum100 = static_cast<int>(minimum * 100.0);
    const int maximum100 = static_cast<int>(maximum * 100.0);
    if (minimum100 == maximum100) return minimum;
    return static_cast<double>(
               minimum100 +
               static_cast<int>(midboss09Rand(seed) %
                                static_cast<std::uint32_t>(
                                    maximum100 - minimum100 + 1))) /
           100.0;
}

int midboss09NodeUpdateCase(int spawnType) {
    if (spawnType == 0xc4 || spawnType == 0xc5) return 0x76;
    if (spawnType == 0xc6) return 0x77;
    if (spawnType == 0xc7) return 0x78;
    if (spawnType == 0xc8) return 0x79;
    if (spawnType == 0xc9 || spawnType == 0xca) return 0x7a;
    if (spawnType == 0xcb || spawnType == 0xcc) return 0x7b;
    return -1;
}

} // namespace

bool StageRuntime::isStage09MidbossType(int spawnType) const {
    return spawnType >= 0x146 && spawnType <= 0x14b;
}

bool StageRuntime::isStage09MidbossNodeType(int spawnType) const {
    return spawnType >= 0xc4 && spawnType <= 0xcc;
}

bool StageRuntime::spawnStage09MidbossNode(StageEnemy& parent, int spawnType,
                                           int childIndex, float offsetX,
                                           float offsetY,
                                           std::uint16_t angle16,
                                           double speed, int hitPoints,
                                           int radius, bool attached) {
    if (!isStage09MidbossNodeType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= 0x200) {
        return false;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = midboss09NodeUpdateCase(spawnType);
    node.sourceHitPoints = hitPoints;
    node.hp = std::max(1, hitPoints);
    node.maxHp = node.hp;
    node.drawHp = node.hp;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = parent.spawnType;
    node.childIndex = childIndex;
    node.originX = offsetX;
    node.originY = offsetY;
    node.x = attached ? parent.x + offsetX : offsetX;
    node.y = attached ? parent.y + offsetY : offsetY;
    node.markerDrawX = node.x;
    node.markerDrawY = node.y;
    node.sourceX = static_cast<int>(node.x);
    node.sourceY = static_cast<int>(node.y);
    node.sourceAngle16 = angle16;
    node.secondaryAngle16 = 0;
    node.targetAngle16 = 0;
    node.angle = static_cast<float>(midboss09Radians(angle16));
    node.sourceSpeed = speed;
    node.speed = static_cast<float>(speed);
    node.radius = radius;
    node.rewardWeight = spawnType <= 0xc5 ? 5 : 0;
    node.sourceDispatchKind = spawnType <= 0xc5 ? 5 : 10;
    node.sourceDispatchField = attached ? 1 : 0;
    node.activationDelay = 0;
    node.targetable = spawnType <= 0xc5;
    node.drawBodyThisFrame = true;
    node.sourceNote = "S09 FUN_1400e3070/5260/6f70 internal node";
    pendingEnemies_.push_back(node);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::emitStage09Midboss146Projectiles(StageEnemy& enemy) {
    const int timer = enemy.helperTimer;
    if (timer <= 29) return;

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int cycle = (timer - 30) % 1100;
    const auto aimed = midboss09AngleTo(enemy.x, enemy.y + 70.0f,
                                       player_.x, player_.y);
    bool fired = false;

    if (cycle < 500) {
        static constexpr std::array<int, 5> kInterval{{140, 120, 110, 102, 102}};
        static constexpr std::array<int, 5> kEmitterCount{{7, 9, 11, 11, 13}};
        static constexpr std::array<int, 5> kBulletCount{{15, 19, 23, 25, 30}};
        static constexpr std::array<double, 5> kSpeed{{2.5, 3.0, 3.5, 4.0, 5.0}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        const int count = kEmitterCount[static_cast<std::size_t>(difficulty)];
        int emitterType = 0;
        if (cycle % (interval * 2) == 0) emitterType = 0xc4;
        else if (cycle >= interval &&
                 (cycle - interval) % (interval * 2) == 0) emitterType = 0xc5;
        if (emitterType != 0) {
            const int direction = emitterType == 0xc4 ? 1 : -1;
            for (int i = 0; i < count; ++i) {
                const auto angle = midboss09Angle(
                    i * (0x10000 / count) + direction * timer * 0x457);
                spawnStage09MidbossNode(enemy, emitterType, i,
                                        enemy.x, enemy.y + 70.0f,
                                        angle, 0.0, 600, 30, false);
            }
            spawnProjectileSpread(
                2, 0, enemy.x, enemy.y + 70.0f, aimed, 0.0f,
                kSpeed[static_cast<std::size_t>(difficulty)], 1,
                kBulletCount[static_cast<std::size_t>(difficulty)],
                0x10000, 0);
            fired = true;
        }
    }

    if (cycle >= 580 && cycle < 1060) {
        static constexpr std::array<int, 5> kWaveInterval{{45, 35, 35, 35, 35}};
        static constexpr std::array<int, 5> kWaveCount{{6, 8, 10, 10, 10}};
        static constexpr std::array<double, 5> kWaveSpeed{{3.2, 4.0, 5.0, 5.0, 6.4}};
        static constexpr std::array<int, 5> kNeedleInterval{{14, 9, 9, 8, 7}};
        static constexpr std::array<int, 5> kNeedleCount{{3, 5, 6, 7, 8}};
        static constexpr std::array<double, 5> kNeedleSpeed{{4.5, 5.5, 6.0, 7.0, 8.8}};
        const int local = cycle - 580;
        const int sweep = cycle * 0x78;

        if (local % kWaveInterval[static_cast<std::size_t>(difficulty)] == 0) {
            const int count = kWaveCount[static_cast<std::size_t>(difficulty)];
            const int spread = (count - 1) * 600;
            const double speed = kWaveSpeed[static_cast<std::size_t>(difficulty)];
            const auto rightAngle = midboss09Angle(sweep + 0x2000);
            const auto leftAngle = midboss09Angle(-0x2000 - sweep);
            spawnProjectileSpread(3, 0, enemy.x + 95.0f, enemy.y - 5.0f,
                                  rightAngle, 0.0f, speed, 1,
                                  count, spread, 0);
            spawnProjectileSpread(3, 0, enemy.x - 95.0f, enemy.y - 5.0f,
                                  leftAngle, 0.0f, speed, 1,
                                  count, spread, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(3, 0, enemy.x + 95.0f, enemy.y - 5.0f,
                                      rightAngle, 0.0f, speed + 0.5, 1,
                                      count, spread, 0);
                spawnProjectileSpread(3, 0, enemy.x - 95.0f, enemy.y - 5.0f,
                                      leftAngle, 0.0f, speed + 0.5, 1,
                                      count, spread, 0);
            }
            fired = true;
        }

        if (local % kNeedleInterval[static_cast<std::size_t>(difficulty)] == 0) {
            const int count = kNeedleCount[static_cast<std::size_t>(difficulty)];
            const double speed = kNeedleSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(5, 0, enemy.x + 95.0f, enemy.y - 5.0f,
                                  midboss09Angle(sweep - 0x6000),
                                  0.0f, speed, 1, count, 25000, 0);
            spawnProjectileSpread(5, 0, enemy.x - 95.0f, enemy.y - 5.0f,
                                  midboss09Angle(0x6000 - sweep),
                                  0.0f, speed, 1, count, 25000, 0);
            fired = true;
        }
    }

    if (cycle >= 700 && cycle < 1060) {
        static constexpr std::array<int, 5> kInterval{{80, 60, 50, 40, 32}};
        static constexpr std::array<double, 5> kSpeed{{6.0, 7.0, 7.5, 9.0, 10.0}};
        if ((cycle - 700) % kInterval[static_cast<std::size_t>(difficulty)] == 0) {
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            if (difficulty > 1) {
                for (int i = 0; i < 3; ++i) {
                    spawnProjectileNode(0x0c, 0, enemy.x, enemy.y + 70.0f,
                                        midboss09Angle(static_cast<int>(aimed) +
                                                       i * 0x640 - 0x640),
                                        0.0f, speed - 2.0, 1, 0);
                }
            }
            for (int i = 0; i < 2; ++i) {
                spawnProjectileNode(0x0c, 0, enemy.x, enemy.y + 70.0f,
                                    midboss09Angle(static_cast<int>(aimed) +
                                                   i * 0x640 - 800),
                                    0.0f, speed - 1.0, 1, 0);
            }
            spawnProjectileNode(0x0c, 0, enemy.x, enemy.y + 70.0f,
                                aimed, 0.0f, speed, 1, 0);
            fired = true;
        }
    }

    if (fired) playPlayerSound(bullet2SoundHandle_, 0x13);
}

void StageRuntime::emitStage09Midboss148Projectiles(StageEnemy& enemy) {
    const int timer = enemy.helperTimer;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int cycle = timer % 1200;
    const float sourceY = enemy.y + 140.0f;
    const auto aimed = midboss09AngleTo(enemy.x, sourceY,
                                       player_.x, player_.y);
    bool fired = false;

    if (cycle < 360) {
        static constexpr std::array<int, 5> kInterval{{8, 6, 6, 6, 6}};
        static constexpr std::array<int, 5> kCount{{2, 3, 4, 5, 6}};
        static constexpr std::array<double, 5> kSpeed{{4.4, 5.5, 6.5, 7.0, 8.5}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        if (cycle > 29 && (cycle - 30) % interval == 0) {
            const auto base = cycle < 180
                                  ? midboss09Angle(cycle * 0x16c)
                                  : midboss09Angle(cycle * -0x16c - 0x20);
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)] +
                                 static_cast<double>(cycle - 30) * 0.004;
            spawnProjectileSpread(5, 0, enemy.x, sourceY, base, 0.0f,
                                  speed - 1.2, 1,
                                  count, 0x10000, 0);
            spawnProjectileSpread(3, 0, enemy.x, sourceY,
                                  midboss09Angle(static_cast<int>(base) +
                                                 interval * 0xb6),
                                  0.0f, speed, 1, count, 0x10000, 0);
            fired = true;
        }
    }

    if (cycle >= 420 && cycle < 800) {
        static constexpr std::array<int, 5> kInterval{{100, 90, 80, 80, 80}};
        static constexpr std::array<int, 5> kFanCount{{6, 8, 10, 12, 14}};
        static constexpr std::array<int, 5> kSpeedLayers{{2, 2, 3, 4, 5}};
        static constexpr std::array<int, 5> kRingCount{{8, 12, 14, 16, 16}};
        static constexpr std::array<int, 5> kSpreadStep{{4000, 3200, 2800, 2400, 2100}};
        static constexpr std::array<double, 5> kFanSpeed{{8.0, 10.0, 10.5, 11.0, 12.8}};
        static constexpr std::array<double, 5> kRingSpeed{{6.0, 6.0, 6.5, 7.0, 8.8}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        if (cycle >= 450 && cycle < 770 && (cycle - 450) % interval == 0) {
            const int fanCount = kFanCount[static_cast<std::size_t>(difficulty)];
            const double fanSpeed = kFanSpeed[static_cast<std::size_t>(difficulty)];
            for (int i = 0; i < fanCount; ++i) {
                spawnProjectileSpread(2, 0, enemy.x, sourceY, aimed, 10.0f,
                                      fanSpeed - i * 0.6, 1,
                                      i + 1, i * 800, 0);
            }
            const int layers = kSpeedLayers[static_cast<std::size_t>(difficulty)];
            const int count = kRingCount[static_cast<std::size_t>(difficulty)];
            const int step = kSpreadStep[static_cast<std::size_t>(difficulty)];
            const double ringSpeed =
                kRingSpeed[static_cast<std::size_t>(difficulty)];
            for (int i = 0; i < layers; ++i) {
                spawnProjectileSpread(5, 0, enemy.x, sourceY, aimed, 10.0f,
                                      ringSpeed - i * 1.2, 1,
                                      count + i, (count - 1 + i) * step, 0);
            }
            fired = true;
        }
    }

    if (fired) playPlayerSound(bullet1SoundHandle_, 0x13);
}

void StageRuntime::updateStage09Midboss(StageEnemy& enemy) {
    if (enemy.spawnType >= 0x149) {
        updateStage09TailMidboss(enemy);
        return;
    }
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHp = enemy.hp;

    const int state = enemy.helperState;
    const int timer = enemy.helperTimer;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);

    const auto openCombat = [this, &enemy](int hitPoints, int countdown) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.hp = hitPoints;
        enemy.maxHp = hitPoints;
        enemy.drawHp = hitPoints;
        enemy.sourceHitPoints = hitPoints;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        lateStageBossBreaksRemaining_ = 1;
        lateStageBossPhaseIndex_ = 0;
        lateStageBossPhaseMode_ = 1;
        lateStageBossMaxHp_ = hitPoints;
        lateStageBossCountdown_ = countdown;
        lateStageBossCountdownDraw_ = countdown;
    };

    const int targetRefresh = enemy.spawnType == 0x148 ? 30 : 50;
    if (frame_ % targetRefresh == 0) {
        const int targetSeedStride = enemy.spawnType == 0x146 ? 0x6f :
                                     (enemy.spawnType == 0x147 ? 0xde : 0x14d);
        lateStageBossTargetX_ = 210.0f + static_cast<float>(
            midboss09Rand(frame_) % 301u);
        const int baseY = enemy.spawnType == 0x147 ? 220 :
                          (enemy.spawnType == 0x148 ? 120 : 150);
        lateStageBossTargetY_ = static_cast<float>(baseY) +
            static_cast<float>(midboss09Rand(
                frame_ + config_.stage * targetSeedStride) % 101u);
    }

    if (state == 1 && (enemy.hp < 1 || lateStageBossCountdown_ < 1)) {
        const std::size_t index = static_cast<std::size_t>(enemy.spawnType - 0x146);
        if (stage09BossDefeatFrames_[index] < 0) {
            stage09BossDefeatFrames_[index] = frame_;
        }
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
        spawnPostDeathCounterEntity(enemy, 140.0);
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        enemy.helperState = 2;
        enemy.helperTimer = 0;
        enemy.liveChildCount = 0;
        lateStageBossBreaksRemaining_ = 0;
        lateStageBossPhaseMode_ = -1;
        lateStageBossCountdown_ = 0;
        lateStageBossCountdownDraw_ = 0;
        return;
    }

    if (state == 0) {
        enemy.targetable = false;
        if (timer == 0) {
            playPlayerSound(bossSe9SoundHandle_, 0x19);
            if (enemy.spawnType == 0x148) {
                spawnStage09MidbossNode(enemy, 0xc7, 0, 100.0f, -100.0f,
                                        0x4000, 1.0, 99999999, 50, true);
                spawnStage09MidbossNode(enemy, 0xc7, 1, -100.0f, -100.0f,
                                        0x4000, 1.0, 99999999, 50, true);
            }
        }

        if (enemy.spawnType == 0x146) {
            if (timer < 180) {
                const double entry = std::sin(
                    static_cast<double>(timer) * kMidboss09Pi / 360.0);
                const double horizontalRadius = entry * 600.0 - 600.0;
                enemy.x = enemy.markerDrawX + static_cast<float>(
                    std::sin(static_cast<double>(timer + 60) *
                             kMidboss09Pi / 120.0) * horizontalRadius);
                enemy.y = 600.0f + static_cast<float>(
                    entry * static_cast<double>(enemy.markerDrawY - 600.0f));
            }
            else if (timer < 191) {
                enemy.x = enemy.markerDrawX;
                enemy.y = enemy.markerDrawY;
            }
            else {
                enemy.y += 0.1f;
            }
            if (timer == 240) openCombat(85000, 0x708);
        }
        else if (enemy.spawnType == 0x147) {
            if (timer == 120) {
                spawnStage09MidbossNode(enemy, 0xc6, 0, 70.0f, -50.0f,
                                        0x4000, 1.0, 99999999, 50, true);
                spawnStage09MidbossNode(enemy, 0xc6, 1, -70.0f, -50.0f,
                                        0x4000, 1.0, 99999999, 50, true);
                spawnStage09MidbossNode(enemy, 0xc6, 2, 140.0f, -110.0f,
                                        0x4000, 1.0, 99999999, 50, true);
                spawnStage09MidbossNode(enemy, 0xc6, 3, -140.0f, -110.0f,
                                        0x4000, 1.0, 99999999, 50, true);
                playPlayerSound(bullet2SoundHandle_, 0x19);
            }
            if (timer < 180) {
                const double entry = std::sin(
                    static_cast<double>(timer) * kMidboss09Pi / 360.0);
                enemy.y = 1100.0f + static_cast<float>(
                    entry * static_cast<double>(enemy.markerDrawY - 1100.0f));
            }
            else if (timer < 191) {
                enemy.y = enemy.markerDrawY;
            }
            else {
                enemy.y += 0.1f;
            }
            if (timer == 210) openCombat(66000, 0x5dc);
        }
        else {
            if (timer <= 60) {
                const double entry = std::sin(
                    static_cast<double>(timer) * kMidboss09Pi / 120.0);
                enemy.y = enemy.markerDrawY - 400.0f +
                          static_cast<float>(600.0 * entry);
            }
            else if (timer <= 180) {
                enemy.y = enemy.markerDrawY + static_cast<float>(
                    std::sin(static_cast<double>(timer + 60) *
                             kMidboss09Pi / 240.0) * 200.0);
            }
            if (timer == 180) openCombat(64000, 0x708);
        }
        return;
    }

    if (state == 1) {
        const auto target = midboss09AngleTo(enemy.x, enemy.y,
                                             lateStageBossTargetX_,
                                             lateStageBossTargetY_);
        const int turn = enemy.spawnType == 0x148 ? 0x309 : 0x200;
        enemy.sourceAngle16 = midboss09Approach(enemy.sourceAngle16,
                                               target, turn);
        const double radians = midboss09Radians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);

        if (enemy.spawnType == 0x146) {
            emitStage09Midboss146Projectiles(enemy);
        }
        else if (enemy.spawnType == 0x148) {
            emitStage09Midboss148Projectiles(enemy);
        }

        enemy.drawHp = enemy.hp;
        lateStageBossCountdownDraw_ = lateStageBossCountdown_;
        updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
        if (lateStageBossCountdown_ > 0) --lateStageBossCountdown_;
        (void)difficulty;
        return;
    }

    enemy.targetable = false;
    enemy.drawBodyThisFrame = timer < 100;
    if (timer < 90) {
        enemy.y += static_cast<float>(timer) * 0.02f;
        if (timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
    }
    if (timer == 90) {
        spawnEnemyDeathEffects(enemy, 2);
    }
    if (timer >= 150) {
        clearLateStageGate(9);
        enemy.active = false;
    }
}

void StageRuntime::updateStage09MidbossNode(StageEnemy& enemy) {
    if (enemy.spawnType >= 0xc8) {
        updateStage09TailMidbossNode(enemy);
        return;
    }
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHp = enemy.hp;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || !parent->active ||
        !isStage09MidbossType(parent->spawnType)) {
        enemy.active = false;
        return;
    }

    const int timer = enemy.helperTimer;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);

    if (enemy.spawnType == 0xc4 || enemy.spawnType == 0xc5) {
        if (parent->helperState > 1) {
            enemy.active = false;
            return;
        }
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 300, false);
            if (player_.bombLock == 0) {
                spawnDelayedOwnerDamageNode(
                    enemy.maxHp, parent->entityId, parent->spawnType,
                    "S09 midboss emitter delayed-damage node 0x153");
            }
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
            return;
        }

        const int direction = enemy.spawnType == 0xc4 ? 1 : -1;
        if (timer == 0) enemy.speed = 0.0f;
        enemy.speed += static_cast<float>(enemy.sourceSpeed);
        enemy.sourceSpeed += 0.1;
        enemy.sourceAngle16 = midboss09Angle(
            static_cast<int>(enemy.sourceAngle16) +
            direction * (timer + 0x5a));
        const double radians = midboss09Radians(enemy.sourceAngle16);
        enemy.x = enemy.markerDrawX +
                  static_cast<float>(std::cos(radians) * enemy.speed);
        enemy.y = enemy.markerDrawY +
                  static_cast<float>(std::sin(radians) * enemy.speed);

        if (timer >= 30) {
            static constexpr std::array<int, 5> kInterval{{26, 22, 20, 20, 20}};
            static constexpr std::array<int, 5> kBurstLength{{6, 8, 10, 10, 12}};
            static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 6.4, 7.2, 8.5}};
            const int local = (timer - 30) %
                kInterval[static_cast<std::size_t>(difficulty)];
            if (local < kBurstLength[static_cast<std::size_t>(difficulty)] &&
                (local & 1) == 0) {
                const float horizontalOrigin = player_.x / 6.0f;
                const double playerDistance = std::hypot(
                    static_cast<double>(enemy.x - player_.x),
                    static_cast<double>(enemy.y - player_.y));
                if (playerDistance >= 100.0 &&
                    enemy.x >= horizontalOrigin &&
                    enemy.x <= horizontalOrigin + 600.0f &&
                    enemy.y >= 0.0f && enemy.y <= 720.0f) {
                    const auto aimed = midboss09AngleTo(
                        enemy.x, enemy.y + 12.0f, player_.x, player_.y);
                    const double speed =
                        kSpeed[static_cast<std::size_t>(difficulty)];
                    spawnProjectileNode(0x0d, 4, enemy.x, enemy.y + 12.0f,
                                        aimed, 0.0f, speed, 1, 0);
                    if (difficulty > 2) {
                        spawnProjectileNode(0x0d, 4, enemy.x,
                                            enemy.y + 12.0f, aimed, 0.0f,
                                            speed + 2.0, 1, 0);
                    }
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                }
            }
        }
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.x < horizontalOrigin - 200.0f ||
            enemy.x > horizontalOrigin + 800.0f ||
            enemy.y < -200.0f || enemy.y > 920.0f) {
            enemy.active = false;
        }
        return;
    }

    enemy.x = parent->x + enemy.originX;
    enemy.y = parent->y + enemy.originY;
    enemy.targetable = false;

    if (enemy.spawnType == 0xc6) {
        if (parent->helperState > 1) {
            enemy.active = false;
            return;
        }
        if (enemy.helperState == 0) {
            if (timer >= 50) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
            }
            return;
        }
        if (timer <= 59) return;

        const int cycle = (timer - 60) % 1000;
        const float sourceY = enemy.y - 60.0f;
        const auto aimed = midboss09AngleTo(enemy.x, sourceY,
                                           player_.x, player_.y);
        bool firedBullet1 = false;
        bool firedBullet2 = false;

        if (cycle < 460 && enemy.childIndex < 2) {
            static constexpr std::array<int, 5> kInterval{{120, 80, 70, 60, 60}};
            static constexpr std::array<int, 5> kSpread{{800, 1200, 1600, 1600, 1600}};
            static constexpr std::array<double, 5> kSpeed{{6.4, 8.0, 8.5, 9.5, 11.1}};
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            const int local = cycle % interval;
            if (local == 0) enemy.secondaryAngle16 = aimed;
            if (local < 24 && local % 3 == 0) {
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(0x0c, 0, enemy.x, sourceY,
                                    enemy.secondaryAngle16, 10.0f,
                                    speed, 1, 0);
                spawnProjectileSpread(0x0c, 0, enemy.x, sourceY,
                                      enemy.secondaryAngle16, 10.0f,
                                      std::max(1.0, speed - 0.5), 1, 2,
                                      kSpread[static_cast<std::size_t>(difficulty)], 0);
                firedBullet1 = true;
            }
        }
        else if (cycle < 400 && enemy.childIndex >= 2) {
            static constexpr std::array<int, 5> kInterval{{60, 48, 36, 25, 25}};
            static constexpr std::array<int, 5> kCount{{9, 9, 11, 11, 13}};
            static constexpr std::array<double, 5> kSpeed{{3.2, 4.0, 4.5, 5.0, 6.4}};
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            if (cycle % (interval * 2) == 0 ||
                (cycle >= interval && (cycle - interval) % (interval * 2) == 0)) {
                const bool second = cycle % (interval * 2) != 0;
                const int bulletCount = second ? std::max(2, count - 1) : count;
                const int spread = second
                    ? (30000 / bulletCount) * std::max(1, bulletCount - 1)
                    : 30000;
                for (int i = 0; i < 5; ++i) {
                    spawnProjectileSpread(
                        9, 0, enemy.x, sourceY,
                        midboss09Angle(static_cast<int>(aimed) + i * 250 - 500),
                        10.0f, kSpeed[static_cast<std::size_t>(difficulty)], 1,
                        bulletCount, spread, 0);
                }
                firedBullet1 = true;
            }
        }

        if (cycle >= 500 && cycle < 900) {
            static constexpr std::array<int, 5> kRapid{{8, 5, 4, 3, 2}};
            static constexpr std::array<int, 5> kBurst{{120, 100, 80, 60, 50}};
            static constexpr std::array<double, 5> kMaxSpeed{{5.5, 6.0, 6.5, 7.0, 8.8}};
            const int local = cycle - 500;
            const int rapid = kRapid[static_cast<std::size_t>(difficulty)];
            const int seed = enemy.childIndex * 0xde + timer;
            const auto random = midboss09Rand(seed);
            if (local % rapid == 0) {
                spawnProjectileNode(
                    0x0d, 8, enemy.x, sourceY,
                    midboss09Angle(static_cast<int>(random % 0x4e21u) - 0x6710),
                    0.0f,
                    midboss09RandomHundredth(
                        seed, 4.0,
                        kMaxSpeed[static_cast<std::size_t>(difficulty)]),
                    1, 0);
                firedBullet1 = true;
            }
            const int burst = kBurst[static_cast<std::size_t>(difficulty)];
            if (local % burst < 40 && local % rapid == 0) {
                spawnProjectileNode(
                    0x0c, 9, enemy.x, sourceY,
                    midboss09Angle(static_cast<int>(random % 0x5dc1u) - 0x6ee0),
                    0.0f, midboss09RandomHundredth(seed + 1, 5.0, 10.0),
                    1, 0);
                firedBullet2 = true;
            }
        }
        if (firedBullet1) playPlayerSound(bullet1SoundHandle_, 0x0c);
        if (firedBullet2) playPlayerSound(bullet2SoundHandle_, 0x0c);
        return;
    }

    if (parent->helperState > 1) {
        enemy.active = false;
        return;
    }
    if (enemy.helperState == 0) {
        if (parent->helperState == 1) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        return;
    }

    const int cycle = timer % 1200;
    const auto aimed = midboss09AngleTo(enemy.x, enemy.y,
                                       player_.x, player_.y);
    bool fired = false;
    if (cycle < 360) {
        static constexpr std::array<int, 5> kInterval{{70, 48, 36, 36, 36}};
        static constexpr std::array<int, 5> kCount{{9, 13, 15, 15, 17}};
        static constexpr std::array<double, 5> kSpeed{{4.5, 5.5, 6.0, 6.5, 7.5}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        enemy.sourceAngle16 = midboss09Approach(
            enemy.sourceAngle16, aimed,
            0x30 + std::abs(midboss09AngleDelta(enemy.sourceAngle16, aimed)) / 10);
        const int start = interval * enemy.childIndex + 90;
        if (cycle >= start && (cycle - start) % (interval * 2) == 0) {
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            const double radians = midboss09Radians(enemy.sourceAngle16);
            const float sourceX = enemy.x +
                static_cast<float>(std::cos(radians) * 70.0);
            const float sourceY = enemy.y +
                static_cast<float>(std::sin(radians) * 70.0);
            spawnProjectileSpread(0x0c, 0, sourceX, sourceY,
                                  enemy.sourceAngle16, 10.0f,
                                  speed, 1, count, 27000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(0x0c, 0, sourceX, sourceY,
                                      enemy.sourceAngle16, 10.0f,
                                      speed + 1.0, 1, count, 27000, 0);
            }
            fired = true;
        }
    }
    else if (cycle >= 770 && cycle <= 1119) {
        static constexpr std::array<int, 5> kInterval{{12, 9, 8, 7, 5}};
        static constexpr std::array<double, 5> kSpeed{{7.0, 8.0, 9.0, 10.0, 12.0}};
        enemy.sourceAngle16 = midboss09Approach(
            enemy.sourceAngle16, aimed,
            0x30 + std::abs(midboss09AngleDelta(enemy.sourceAngle16, aimed)) / 10);
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        if ((cycle - 770) % interval == 0) {
            const auto random = midboss09Rand(enemy.childIndex * 9999 + timer);
            const int offset = static_cast<int>(random % 0x3e81u) - 0x222e;
            const double radians = midboss09Radians(enemy.sourceAngle16);
            const float sourceX = enemy.x +
                static_cast<float>(std::cos(radians) * 70.0);
            const float sourceY = enemy.y +
                static_cast<float>(std::sin(radians) * 70.0);
            for (int i = 0; i < 3; ++i) {
                spawnProjectileNode(enemy.childIndex == 0 ? 0x0d : 0x0c,
                                    7, sourceX, sourceY,
                                    midboss09Angle(
                                        static_cast<int>(enemy.sourceAngle16) +
                                        offset + i * 0x2ee),
                                    10.0f,
                                    kSpeed[static_cast<std::size_t>(difficulty)],
                                    1, 0);
            }
            fired = true;
        }
    }
    if (fired) playPlayerSound(bullet1SoundHandle_, 0x13);
}

bool StageRuntime::drawStage09Midboss(const StageEnemy& enemy, float x,
                                      float y, int exactLayer) const {
    if (!isStage09MidbossType(enemy.spawnType)) return false;
    if (enemy.spawnType >= 0x149) {
        return drawStage09TailMidboss(enemy, x, y, exactLayer);
    }
    if (!enemy.drawBodyThisFrame) return true;

    const int timer = enemy.drawHelperTimer;
    const int state = enemy.drawHelperState;
    const int alpha = state == 2 && timer >= 90
                          ? std::clamp((100 - timer) * 25, 0, 255)
                          : 255;
    if (alpha < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

    const auto drawLarge = [this](int frame, float drawX, float drawY,
                                   std::uint16_t angle = 0,
                                   bool reverse = false) {
        if (frame >= 0 && frame < static_cast<int>(enemyLargeFrames_.size())) {
            const int graph = enemyLargeFrames_[static_cast<std::size_t>(frame)];
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      1.0, 1.0, reverse);
            }
        }
    };

    if (enemy.spawnType == 0x146) {
        if (exactLayer == 0x1e) {
            drawLarge(0, x, y);
        }
    }
    else if (enemy.spawnType == 0x147) {
        const int sourceFrame = std::max(0, frame_ - 1);
        if (exactLayer == 0x1e) {
            for (int i = 0; i < 4; ++i) {
                drawLarge(8, x, y + 90.0f,
                          midboss09Angle(sourceFrame * 600 + i * 0x4000));
            }
            drawLarge(7, x, y);
        }

        int bossFrame = 100;
        if (state == 2) {
            bossFrame = 108 + (timer / 5) % 2;
        }
        else {
            static constexpr std::array<int, 4> kFrames{{100, 101, 102, 101}};
            bossFrame = kFrames[static_cast<std::size_t>((timer / 6) % 4)];
        }
        if (bossFrame < static_cast<int>(bossFrames_.size()) &&
            bossFrames_[static_cast<std::size_t>(bossFrame)] != -1) {
            if (exactLayer == 0x1f) {
                SetDrawBright(0, 0, 0);
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
                drawOriginalMode7Node(
                    bossFrames_[static_cast<std::size_t>(bossFrame)],
                    x, y - 160.0f, 0, 1.0, 1.0, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
                SetDrawBright(255, 255, 255);
            }
            if (exactLayer == 0x20) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                                 std::min(alpha, 0xc0));
                drawOriginalMode7Node(
                    bossFrames_[static_cast<std::size_t>(bossFrame)],
                    x, y - 160.0f, 0, 1.0, 1.0, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }

        if (48 < static_cast<int>(enemyMediumFrames_.size())) {
            const int orbitGraph = enemyMediumFrames_[48];
            if (orbitGraph != -1) {
                for (int i = 0; i < 13; ++i) {
                    const auto angle = midboss09Angle(sourceFrame * 0xde +
                                                      i * 0x13b1);
                    const double radians = midboss09Radians(angle);
                    const int orbitLayer = angle > 0x8000 ? 0x1f : 0x20;
                    if (exactLayer == orbitLayer) {
                        drawOriginalMode7Node(
                            orbitGraph,
                            x + static_cast<float>(std::cos(radians) * 125.0),
                            y - 160.0f +
                                static_cast<float>(std::sin(radians) * 85.0),
                            0, 1.0, 1.0, angle > 0x8000);
                    }
                }
            }
        }
    }
    else {
        if (exactLayer == 0x20) {
            drawLarge(13, x, y);
        }
        const int sourceFrame = std::max(0, frame_ - 1);
        if (exactLayer == 0x22) {
            for (int i = 0; i < 4; ++i) {
                drawLarge(15, x, y - 255.0f,
                          midboss09Angle(sourceFrame * 0x500 + i * 0x4000));
            }
        }
    }

    if (alpha < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    return true;
}

bool StageRuntime::drawStage09MidbossNode(const StageEnemy& enemy, float x,
                                          float y, int exactLayer) const {
    if (!isStage09MidbossNodeType(enemy.spawnType)) return false;
    if (enemy.spawnType >= 0xc8) {
        return drawStage09TailMidbossNode(enemy, x, y, exactLayer);
    }
    if (!enemy.drawBodyThisFrame) return true;

    const auto drawSmall = [this](int frame, float drawX, float drawY,
                                   std::uint16_t angle = 0,
                                   bool reverse = false) {
        if (frame >= 0 && frame < static_cast<int>(enemySmallFrames_.size())) {
            const int graph = enemySmallFrames_[static_cast<std::size_t>(frame)];
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      1.0, 1.0, reverse);
            }
        }
    };
    const auto drawMedium = [this](int frame, float drawX, float drawY,
                                    std::uint16_t angle = 0,
                                    bool reverse = false) {
        if (frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())) {
            const int graph = enemyMediumFrames_[static_cast<std::size_t>(frame)];
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      1.0, 1.0, reverse);
            }
        }
    };

    if (enemy.spawnType == 0xc4 || enemy.spawnType == 0xc5) {
        const auto orbit = midboss09Angle((enemy.drawHelperTimer - 10) * 0x500);
        const double radians = midboss09Radians(orbit);
        const float dx = static_cast<float>(std::cos(radians) * 40.0);
        const float dy = static_cast<float>(std::sin(radians) * 40.0);
        if (exactLayer == 0x23) {
            drawSmall(14, x + dx, y + dy, orbit);
            drawSmall(14, x - dx, y + dy,
                      midboss09Angle(-static_cast<int>(orbit)), true);
            drawSmall(11, x, y);
        }
        return true;
    }

    if (enemy.spawnType == 0xc6) {
        int alpha = 255;
        if (enemy.drawHelperState == 0) {
            alpha = std::clamp(enemy.drawHelperTimer * 255 / 30, 0, 255);
        }
        if (exactLayer == 0x1e) {
            SetDrawBright(0, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
            drawMedium(170, x, y - 50.0f);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(255, 255, 255);
        }
        if (exactLayer == 0x23) {
            if (alpha < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            drawMedium(170, x, y + 50.0f);
            drawSmall(20 + (enemy.drawHelperTimer / 3) % 3,
                      x, y - 60.0f);
            if (alpha < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        return true;
    }

    if (exactLayer == 0x21) {
        drawMedium(62, x, y, enemy.sourceAngle16);
    }
    return true;
}

} // namespace reconstructed
