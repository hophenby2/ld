#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kTail09Pi = 3.14159265358979323846;
constexpr double kTail09Tau = kTail09Pi * 2.0;

std::uint16_t tail09Angle(int value) {
    return static_cast<std::uint16_t>(value & 0xffff);
}

double tail09Radians(std::uint16_t angle) {
    return static_cast<double>(angle) * kTail09Tau / 65536.0;
}

std::uint16_t tail09AngleTo(float x0, float y0, float x1, float y1) {
    return tail09Angle(static_cast<int>(
        std::atan2(static_cast<double>(y1 - y0),
                   static_cast<double>(x1 - x0)) *
        65536.0 / kTail09Tau));
}

int tail09AngleDelta(std::uint16_t current, std::uint16_t target) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return delta;
}

std::uint16_t tail09Approach(std::uint16_t current,
                             std::uint16_t target, int step) {
    return tail09Angle(static_cast<int>(current) +
                       std::clamp(tail09AngleDelta(current, target),
                                  -step, step));
}

std::uint32_t tail09Rand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

double tail09SineIn(int timer, int duration) {
    if (timer <= 0) return 0.0;
    if (timer >= duration) return 1.0;
    return std::sin(static_cast<double>(timer) * kTail09Pi /
                    (static_cast<double>(duration) * 2.0));
}

constexpr std::array<float, 6> kTail09ChainX{{
    50.0f, 100.0f, -50.0f, -100.0f, 140.0f, -140.0f,
}};
constexpr std::array<float, 6> kTail09ChainY{{
    150.0f, 140.0f, 150.0f, 140.0f, 120.0f, 120.0f,
}};

} // namespace

void StageRuntime::emitStage09Midboss149Projectiles(StageEnemy& enemy) {
    const int timer = enemy.helperTimer;
    if (timer <= 63 || (timer - 64) < 0) return;

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    static constexpr std::array<int, 5> kInterval{{200, 160, 160, 160, 160}};
    static constexpr std::array<int, 5> kLayerCount{{12, 15, 18, 18, 20}};
    static constexpr std::array<double, 5> kSpeed{{4.5, 5.5, 6.0, 6.5, 7.7}};
    if ((timer - 64) % kInterval[static_cast<std::size_t>(difficulty)] != 0) {
        return;
    }

    const auto aimed = tail09AngleTo(enemy.x, enemy.y, player_.x, player_.y);
    const int layers = kLayerCount[static_cast<std::size_t>(difficulty)];
    const double topSpeed = kSpeed[static_cast<std::size_t>(difficulty)];
    for (int i = 0; i <= layers; ++i) {
        const int spread = i * (0x10000 / layers);
        const double speed = topSpeed -
            static_cast<double>(i) * ((topSpeed - 1.0) / layers);
        spawnProjectileSpread(10, 0, enemy.x, enemy.y, aimed, 10.0f,
                              speed, 1, 2, spread, 0);
        if (difficulty > 2 && i < layers) {
            const double secondSpeed = (topSpeed - 1.0) -
                static_cast<double>(i) * ((topSpeed - 2.4) / layers);
            spawnProjectileSpread(10, 0, enemy.x, enemy.y, aimed, 10.0f,
                                  secondSpeed, 1, 2, spread + 0x5dc, 0);
        }
    }
    playPlayerSound(bullet2SoundHandle_, 0x13);
}

void StageRuntime::emitStage09Midboss14AProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int cycle = enemy.helperTimer % 0x44c;
    static constexpr std::array<float, 6> kOffsetX{{
        90.0f, 156.0f, -95.0f, -156.0f, 156.0f, -156.0f,
    }};
    static constexpr std::array<float, 6> kOffsetY{{
        -20.0f, -20.0f, 50.0f, 50.0f, -100.0f, -100.0f,
    }};
    bool firedPrimary = false;
    bool firedPrimaryLoud = false;
    bool firedSecondaryLoud = false;

    for (int source = 0; source < 6; ++source) {
        const float x = enemy.x + kOffsetX[static_cast<std::size_t>(source)];
        const float y = enemy.y + kOffsetY[static_cast<std::size_t>(source)];
        const auto aimed = tail09AngleTo(x, y, player_.x, player_.y);

        if (cycle < 600 && source < 2) {
            static constexpr std::array<int, 5> kInterval{{160, 120, 80, 60, 50}};
            static constexpr std::array<int, 5> kCount{{15, 21, 27, 30, 33}};
            static constexpr std::array<double, 5> kSpeed{{2.5, 3.0, 3.5, 4.0, 5.5}};
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            const int start = (1 - source) * interval + 100;
            if (cycle < 400 && cycle >= start &&
                (cycle - start) % (interval * 2) == 0) {
                spawnProjectileSpread(
                    2, 0, x, y, aimed, 0.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)], 1,
                    kCount[static_cast<std::size_t>(difficulty)],
                    0x10000, 0);
                firedPrimaryLoud = true;
            }

            if (cycle >= 560 && cycle < 600 && (cycle - 560) % 4 == 0) {
                std::uint16_t& sweep = source == 0
                                           ? enemy.secondaryAngle16
                                           : enemy.targetAngle16;
                if (cycle == 560) sweep = aimed;
                spawnProjectileSpread(
                    2, 0, x, y, sweep, 0.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)] + 5.0, 1,
                    std::max(1, kCount[static_cast<std::size_t>(difficulty)] - 4),
                    0x10000, 0);
                sweep = tail09Approach(sweep, aimed, 0x80);
                firedPrimaryLoud = true;
            }
        }

        if (cycle < 400 && source >= 2) {
            static constexpr std::array<int, 5> kInterval{{120, 90, 60, 40, 36}};
            static constexpr std::array<double, 5> kSpeed{{6.0, 7.0, 8.0, 9.0, 10.0}};
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            const int end = difficulty == 2 ? 350 : 370;
            const int fireStart = (source - 2) * interval + 50;
            if (cycle >= fireStart && cycle < end &&
                (cycle - fireStart) % (interval * 4) == 0) {
                spawnProjectileNode(0x12, 0x0e, x, y,
                                    tail09Angle(source << 15), 0.0f,
                                    kSpeed[static_cast<std::size_t>(difficulty)],
                                    1, 0);
                firedSecondaryLoud = true;
            }
        }

        if (cycle >= 630 && cycle < 1070) {
            static constexpr std::array<int, 5> kInterval{{12, 7, 6, 6, 5}};
            static constexpr std::array<double, 5> kSpeed{{4.0, 5.0, 5.5, 6.0, 7.0}};
            static constexpr std::array<int, 6> kBaseAngle{{
                0x4000, 0x4000, 0, 0x8000, 0, 0x8000,
            }};
            const int local = cycle - 630;
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)] +
                                 static_cast<double>(local) * 0.01;
            if (source < 2 && local % (interval + 2) == 0) {
                for (int opposite = 0; opposite < 2; ++opposite) {
                    const int base = kBaseAngle[static_cast<std::size_t>(source)] -
                                     opposite * 0x8000;
                    spawnProjectileNode(3, 0, x, y,
                                        tail09Angle(base + local * 200),
                                        0.0f, speed, 1, 0);
                    spawnProjectileNode(3, 0, x, y,
                                        tail09Angle(base - local * 200),
                                        0.0f, speed, 1, 0);
                    if (difficulty > 2) {
                        spawnProjectileNode(3, 0, x, y,
                                            tail09Angle(base + local * 200),
                                            0.0f, speed - 0.5, 1, 0);
                        spawnProjectileNode(3, 0, x, y,
                                            tail09Angle(base - local * 200),
                                            0.0f, speed - 0.5, 1, 0);
                    }
                }
                firedPrimary = true;
            }
            else if (source >= 2 && local % interval == 0) {
                const int base = kBaseAngle[static_cast<std::size_t>(source)];
                spawnProjectileNode(5, 0, x, y,
                                    tail09Angle(base + local * 0xd2),
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(5, 0, x, y,
                                    tail09Angle(base - local * 0xd2),
                                    0.0f, speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(5, 0, x, y,
                                        tail09Angle(base + local * 0xd2),
                                        0.0f, speed - 0.5, 1, 0);
                    spawnProjectileNode(5, 0, x, y,
                                        tail09Angle(base - local * 0xd2),
                                        0.0f, speed - 0.5, 1, 0);
                }
                firedPrimary = true;
            }
        }
    }

    if (firedPrimary) playPlayerSound(bullet1SoundHandle_, 0x0c);
    if (firedPrimaryLoud) playPlayerSound(bullet1SoundHandle_, 0x13);
    if (firedSecondaryLoud) playPlayerSound(bullet2SoundHandle_, 0x13);
}

void StageRuntime::updateStage09TailMidboss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHp = enemy.hp;

    const int state = enemy.helperState;
    const int timer = enemy.helperTimer;
    const auto openCombat = [this, &enemy](int hitPoints, int countdown,
                                           double speed) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.hp = hitPoints;
        enemy.maxHp = hitPoints;
        enemy.drawHp = hitPoints;
        enemy.sourceHitPoints = hitPoints;
        enemy.sourceSpeed = speed;
        enemy.speed = static_cast<float>(speed);
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        lateStageBossBreaksRemaining_ = 1;
        lateStageBossPhaseIndex_ = 0;
        lateStageBossPhaseMode_ = 1;
        lateStageBossMaxHp_ = hitPoints;
        lateStageBossCountdown_ = countdown;
        lateStageBossCountdownDraw_ = countdown;
    };

    if (frame_ % 50 == 0) {
        if (enemy.spawnType == 0x149) {
            lateStageBossTargetX_ = 260.0f + static_cast<float>(
                tail09Rand(frame_) % 201u);
            lateStageBossTargetY_ = 60.0f + static_cast<float>(
                tail09Rand(frame_ + config_.stage * 0x1bc) % 121u);
        }
        else {
            const int seedStride = enemy.spawnType == 0x14a ? 0x6f : 0xde;
            lateStageBossTargetX_ = 210.0f + static_cast<float>(
                tail09Rand(frame_) % 301u);
            lateStageBossTargetY_ =
                (enemy.spawnType == 0x14b ? 140.0f : 150.0f) +
                static_cast<float>(tail09Rand(
                    frame_ + config_.stage * seedStride) % 101u);
        }
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
        }

        if (enemy.spawnType == 0x149) {
            enemy.x = enemy.markerDrawX;
            enemy.y = enemy.markerDrawY + 500.0f -
                static_cast<float>(500.0 * std::sin(
                    static_cast<double>(std::clamp(timer, 0, 240)) *
                    kTail09Pi / 480.0));
            if (timer == 180) {
                static constexpr std::array<float, 6> kSpawnX{{
                    60.0f, -60.0f, 150.0f, -150.0f, 230.0f, -230.0f,
                }};
                static constexpr std::array<float, 6> kSpawnY{{
                    260.0f, 260.0f, 230.0f, 230.0f, 170.0f, 170.0f,
                }};
                for (int i = 0; i < 6; ++i) {
                    spawnStage09MidbossNode(
                        enemy, 0xc8, i,
                        kSpawnX[static_cast<std::size_t>(i)],
                        kSpawnY[static_cast<std::size_t>(i)],
                        0x4000, 1.0, 7000, 30, true);
                }
            }
            if (timer == 240) openCombat(70000, 0x708, 0.3);
        }
        else if (enemy.spawnType == 0x14a) {
            if (timer < 120) {
                const double t = tail09SineIn(timer, 120);
                enemy.y = 1500.0f +
                    static_cast<float>((enemy.markerDrawY - 1500.0f) * t);
            }
            else {
                enemy.y += 0.1f;
            }
            if (timer == 140) openCombat(64000, 0x5dc, 0.3);
        }
        else {
            if (timer == 0) {
                spawnStage09MidbossNode(enemy, 0xc9, 0, -75.0f, 0.0f,
                                        0x8000, 1.0, 99999999, 40, true);
                spawnStage09MidbossNode(enemy, 0xca, 1, 75.0f, 0.0f,
                                        0, 1.0, 99999999, 40, true);
            }
            const int clamped = std::clamp(timer, 0, 150);
            const double phase = static_cast<double>(clamped) * kTail09Pi;
            enemy.x = enemy.markerDrawX + static_cast<float>(
                std::sin(phase / 75.0) * std::cos(phase / 300.0) * 500.0);
            const double t = tail09SineIn(clamped, 150);
            enemy.y = 1000.0f +
                static_cast<float>((enemy.markerDrawY - 1000.0f) * t);
            enemy.secondaryAngle16 = tail09Approach(
                enemy.secondaryAngle16,
                tail09Angle(((timer % 0x708) / 30) * 0x444), 0xb6);
            const auto facing = tail09Angle(
                static_cast<int>(tail09AngleTo(enemy.x, enemy.y,
                                                player_.x, player_.y)) +
                0xc000);
            enemy.targetAngle16 = tail09Approach(
                enemy.targetAngle16, facing,
                std::abs(tail09AngleDelta(enemy.targetAngle16, facing)) / 20 + 0x30);
            if (timer == 150) openCombat(80000, 0x708, 1.6);
        }
        return;
    }

    if (state == 1) {
        const auto target = tail09AngleTo(enemy.x, enemy.y,
                                          lateStageBossTargetX_,
                                          lateStageBossTargetY_);
        enemy.sourceAngle16 = tail09Approach(enemy.sourceAngle16, target, 0x200);
        const double radians = tail09Radians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);

        if (enemy.spawnType == 0x149) {
            emitStage09Midboss149Projectiles(enemy);
            if (timer == 0x4b0) enemy.helperTimer = 0;
        }
        else if (enemy.spawnType == 0x14a) {
            emitStage09Midboss14AProjectiles(enemy);
        }
        else {
            enemy.secondaryAngle16 = tail09Approach(
                enemy.secondaryAngle16,
                tail09Angle(((timer % 0x708) / 30) * 0x444), 0xb6);
            const auto facing = tail09Angle(
                static_cast<int>(tail09AngleTo(enemy.x, enemy.y,
                                                player_.x, player_.y)) +
                0xc000);
            enemy.targetAngle16 = tail09Approach(
                enemy.targetAngle16, facing,
                std::abs(tail09AngleDelta(enemy.targetAngle16, facing)) / 20 + 0x30);
            if (timer % 30 == 0) {
                playPlayerSound(bossSe15SoundHandle_, 0x10);
            }
        }

        enemy.drawHp = enemy.hp;
        lateStageBossCountdownDraw_ = lateStageBossCountdown_;
        updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
        if (lateStageBossCountdown_ > 0) --lateStageBossCountdown_;
        return;
    }

    enemy.targetable = false;
    enemy.drawBodyThisFrame = timer < 100;
    if (timer < 90) {
        if (enemy.spawnType == 0x14b) {
            enemy.secondaryAngle16 = tail09Angle(
                static_cast<int>(enemy.secondaryAngle16) - 0x682);
            enemy.targetAngle16 = tail09Angle(
                static_cast<int>(enemy.targetAngle16) + 0x682);
        }
        enemy.y += static_cast<float>(timer) * 0.02f;
        if (timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
    }
    if (timer == 90) spawnEnemyDeathEffects(enemy, 2);
    if (timer >= 150) {
        clearLateStageGate(9);
        enemy.active = false;
    }
}

void StageRuntime::updateStage09TailMidbossNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHp = enemy.hp;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);

    if (enemy.spawnType == 0xc8) {
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || !parent->active || parent->spawnType != 0x149) {
            enemy.active = false;
            return;
        }
        const int index = std::clamp(enemy.childIndex, 0, 5);
        const int timer = enemy.helperTimer;
        const float mountX = parent->x + kTail09ChainX[static_cast<std::size_t>(index)];
        const float mountY = parent->y + kTail09ChainY[static_cast<std::size_t>(index)];
        const auto turnStep = [](std::uint16_t current, std::uint16_t target) {
            return std::abs(tail09AngleDelta(current, target)) / 10 + 0x30;
        };
        const auto followMount = [&]() {
            const auto target = tail09AngleTo(enemy.x, enemy.y, mountX, mountY);
            enemy.secondaryAngle16 = tail09Approach(
                enemy.secondaryAngle16, target, 0x457);
            const double radians = tail09Radians(enemy.secondaryAngle16);
            enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
            enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
            enemy.sourceAngle16 = tail09Approach(
                enemy.sourceAngle16, 0x4000,
                turnStep(enemy.sourceAngle16, 0x4000));
        };

        if (enemy.helperState == 0) {
            if (timer == 40) playPlayerSound(bossSe1SoundHandle_, 0x13);
            if (timer >= 60) {
                enemy.secondaryAngle16 =
                    (index == 0 || index == 3 || index == 4) ? 1000 : 0x7c18;
                enemy.sourceSpeed = 1.0;
                enemy.speed = 1.0f;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
            }
        }

        if (enemy.helperState == 1) {
            followMount();
            const int parentTimer = parent->helperTimer;
            if (parentTimer == index * 15 + 10) {
                enemy.helperState = 2;
                enemy.helperTimer = 0;
            }
            else if (parentTimer == index * 20 + 0x14a) {
                enemy.helperState = 4;
                enemy.helperTimer = 0;
            }
            else if (parentTimer == 0x2a8) {
                enemy.helperState = 6;
                enemy.helperTimer = 0;
            }
            else if (parentTimer == 0x3b6) {
                enemy.helperState = 8;
                enemy.helperTimer = 0;
            }
        }

        if (enemy.helperState == 2 || enemy.helperState == 4 ||
            enemy.helperState == 6 || enemy.helperState == 8) {
            const int dashState = enemy.helperState;
            const int dashTimer = enemy.helperTimer;
            if (dashTimer == 1) {
                playPlayerSound(bossSe2SecondSoundHandle_, 0x19);
            }
            if (dashTimer < 50) {
                std::uint16_t target = tail09AngleTo(
                    enemy.x, enemy.y, player_.x, player_.y);
                if (dashState == 6) {
                    static constexpr std::array<float, 6> kTargetX{{
                        720.0f, 0.0f, 720.0f, 0.0f, 0.0f, 720.0f,
                    }};
                    static constexpr std::array<float, 6> kTargetY{{
                        720.0f, 720.0f, 480.0f, 480.0f, 240.0f, 240.0f,
                    }};
                    target = tail09AngleTo(
                        enemy.x, enemy.y,
                        kTargetX[static_cast<std::size_t>(index)],
                        kTargetY[static_cast<std::size_t>(index)]);
                }
                else if (dashState == 8) {
                    static constexpr std::array<float, 6> kTargetX{{
                        520.0f, 200.0f, 640.0f, 60.0f, 720.0f, 0.0f,
                    }};
                    static constexpr std::array<float, 6> kTargetY{{
                        720.0f, 720.0f, 720.0f, 720.0f, 540.0f, 540.0f,
                    }};
                    target = tail09AngleTo(
                        enemy.x, enemy.y,
                        kTargetX[static_cast<std::size_t>(index)],
                        kTargetY[static_cast<std::size_t>(index)]);
                }
                enemy.sourceAngle16 = tail09Approach(
                    enemy.sourceAngle16, target,
                    turnStep(enemy.sourceAngle16, target));
            }
            if (dashTimer == 90) {
                enemy.sourceSpeed = 10.0;
                enemy.speed = 10.0f;
                playPlayerSound(bossSe5SoundHandle_, 0x19);
            }
            if (dashTimer > 90) {
                const double radians = tail09Radians(enemy.sourceAngle16);
                enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
                enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
                enemy.sourceSpeed += 0.2;
                enemy.speed = static_cast<float>(enemy.sourceSpeed);
                const float horizontalOrigin = player_.x / 6.0f;
                if (enemy.x >= horizontalOrigin &&
                    enemy.x <= horizontalOrigin + 600.0f &&
                    enemy.y >= 0.0f && enemy.y <= 720.0f) {
                    const float muzzleX = enemy.x +
                        static_cast<float>(std::cos(radians) * 60.0);
                    const float muzzleY = enemy.y +
                        static_cast<float>(std::sin(radians) * 60.0);
                    const auto reverse = tail09Angle(
                        static_cast<int>(enemy.sourceAngle16) + 0x8000);
                    spawnProjectileNode(
                        3, 1, muzzleX, muzzleY,
                        tail09Angle(static_cast<int>(reverse) +
                                    static_cast<int>(tail09Rand(frame_ + 444) % 0x961u) -
                                    0x4b0),
                        0.0f, 10.0, 1, 0);
                    spawnProjectileNode(
                        5, 1, muzzleX, muzzleY,
                        tail09Angle(static_cast<int>(reverse) +
                                    static_cast<int>(tail09Rand(frame_) % 0xbb9u) -
                                    0x5dc),
                        0.0f, 9.0, 1, 0);
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                }
            }
            if (dashTimer >= 100 &&
                (enemy.x < 40.0f || enemy.x > 680.0f ||
                 enemy.y < 40.0f || enemy.y > 680.0f)) {
                static constexpr std::array<int, 5> kCount{{12, 24, 32, 20, 24}};
                static constexpr std::array<double, 5> kSpeed{{3.5, 4.5, 5.0, 5.5, 6.6}};
                const int count = kCount[static_cast<std::size_t>(difficulty)];
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(2, 0, enemy.x, enemy.y,
                                      enemy.sourceAngle16, 0.0f, speed, 1,
                                      count, 0x10000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(
                        4, 7, enemy.x, enemy.y,
                        tail09Angle(static_cast<int>(enemy.sourceAngle16) +
                                    0x10000 / (count * 2)),
                        0.0f, speed - 1.0, 1, count * 2, 0x10000, 0);
                }
                playPlayerSound(bossSe6SoundHandle_, 0x14);
                enemy.helperState = dashState + 1;
                enemy.helperTimer = 0;
            }
        }

        if (enemy.helperState == 3 || enemy.helperState == 5 ||
            enemy.helperState == 7 || enemy.helperState == 9) {
            const int returnTimer = enemy.helperTimer;
            if (returnTimer >= 60) {
                enemy.x += (mountX - enemy.x) / 20.0f;
                enemy.y += (mountY - enemy.y) / 20.0f;
                enemy.sourceAngle16 = tail09Approach(
                    enemy.sourceAngle16, 0x4000,
                    turnStep(enemy.sourceAngle16, 0x4000));
            }
            if (returnTimer >= 90) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.sourceSpeed = 1.0;
                enemy.speed = 1.0f;
            }
        }

        if (enemy.helperState == -1) {
            const int deathTimer = enemy.helperTimer;
            if (deathTimer < 60 && deathTimer % 6 == 0) {
                spawnEnemyDeathEffects(enemy, 1);
            }
            if (parent->helperState != 1 && deathTimer >= 80) {
                enemy.active = false;
            }
            else if (parent->helperState == 1 && deathTimer >= 200) {
                enemy.hp = enemy.maxHp;
                enemy.drawHp = enemy.hp;
                enemy.x = parent->x + enemy.originX;
                enemy.y = parent->y + enemy.originY;
                enemy.helperState = 0;
                enemy.helperTimer = 0;
                enemy.targetable = false;
                ++parent->liveChildCount;
            }
        }

        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1 && enemy.helperState >= 1) {
            spawnEnemyDeathRewardBurst(enemy, 2000, false);
            spawnEnemyDeathEffects(enemy, 1);
            spawnDelayedOwnerDamageNode(
                enemy.maxHp, parent->entityId, parent->spawnType,
                "S09 chain node delayed-damage node 0x153");
            parent->liveChildCount = std::max(0, parent->liveChildCount - 1);
            enemy.targetable = false;
            enemy.helperState = -1;
            enemy.helperTimer = 0;
        }
        else if (enemy.helperState >= 1 && parent->helperState != 1) {
            spawnEnemyDeathEffects(enemy, 1);
            parent->liveChildCount = std::max(0, parent->liveChildCount - 1);
            enemy.targetable = false;
            enemy.helperState = -1;
            enemy.helperTimer = 0;
        }
        return;
    }

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || !parent->active) {
        enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0xc9 || enemy.spawnType == 0xca) {
        if (parent->spawnType != 0x14b) {
            enemy.active = false;
            return;
        }
        const auto orbit = tail09Angle(
            static_cast<int>(parent->targetAngle16) +
            static_cast<int>(enemy.sourceAngle16));
        const double radians = tail09Radians(orbit);
        enemy.x = parent->x + static_cast<float>(std::cos(radians) * 75.0);
        enemy.y = parent->y + static_cast<float>(std::sin(radians) * 75.0);
        if (enemy.spawnType == 0xc9) {
            if (enemy.helperTimer % 30 > 19) {
                enemy.targetAngle16 = tail09Angle(
                    static_cast<int>(enemy.targetAngle16) + 0x222);
            }
        }
        else {
            const auto aimed = tail09AngleTo(enemy.x, enemy.y,
                                             player_.x, player_.y);
            const double aimRadians = tail09Radians(aimed);
            enemy.x += static_cast<float>(std::cos(aimRadians) * 24.0);
            enemy.y += static_cast<float>(std::sin(aimRadians) * 24.0);
        }
        if (parent->helperState == 1 && parent->helperTimer == 10) {
            spawnStage09MidbossNode(
                enemy, enemy.spawnType == 0xc9 ? 0xcb : 0xcc,
                enemy.childIndex, 0.0f, 0.0f, 0, 0.0,
                99999999, 50, true);
        }
        if (parent->helperState == 2 && parent->helperTimer >= 100) {
            enemy.active = false;
        }
        return;
    }

    if ((enemy.spawnType != 0xcb && enemy.spawnType != 0xcc) ||
        (parent->spawnType != 0xc9 && parent->spawnType != 0xca)) {
        enemy.active = false;
        return;
    }
    StageEnemy* root = findEnemyById(parent->parentEntityId);
    if (root == nullptr || !root->active || root->spawnType != 0x14b ||
        root->helperState != 1 || lateStageBossCountdown_ < 1) {
        enemy.active = false;
        return;
    }
    enemy.x = parent->x;
    enemy.y = parent->y;
    enemy.targetable = false;

    const int timer = enemy.helperTimer;
    const int cycle = timer % 0x514;
    const auto aimed = tail09AngleTo(enemy.x, enemy.y, player_.x, player_.y);
    bool fired = false;
    if (cycle < 0x21c) {
        static constexpr std::array<int, 5> kPeriod{{40, 34, 30, 30, 30}};
        static constexpr std::array<int, 5> kBurst{{20, 25, 25, 30, 30}};
        static constexpr std::array<int, 5> kCount{{11, 17, 19, 19, 23}};
        static constexpr std::array<double, 5> kSpeed{{7.0, 8.9, 8.5, 9.0, 10.0}};
        const int period = kPeriod[static_cast<std::size_t>(difficulty)];
        if (cycle == 0) enemy.secondaryAngle16 = aimed;
        int local = cycle;
        if (enemy.spawnType == 0xcc) local -= period;
        if (local >= 0 && local % (period * 2) < kBurst[static_cast<std::size_t>(difficulty)] &&
            local % 5 == 0) {
            const int direction = enemy.spawnType == 0xcb ? 1 : -1;
            spawnProjectileSpread(
                enemy.spawnType == 0xcb ? 3 : 2, 7,
                enemy.x, enemy.y,
                tail09Angle(static_cast<int>(enemy.secondaryAngle16) +
                            direction * timer * 0x78),
                0.0f, kSpeed[static_cast<std::size_t>(difficulty)], 1,
                kCount[static_cast<std::size_t>(difficulty)], 0x10000, 0);
            fired = true;
        }
    }
    else if (cycle == 0x280) {
        static constexpr std::array<int, 5> kCount{{9, 11, 13, 15, 17}};
        const int count = kCount[static_cast<std::size_t>(difficulty)];
        for (int i = 0; i < count; ++i) {
            spawnProjectileNode(
                enemy.spawnType == 0xcb ? 3 : 2,
                enemy.spawnType == 0xcb ? 0x29 : 0x2a,
                enemy.x, enemy.y,
                tail09Angle(static_cast<int>(aimed) + i * (0x10000 / count)),
                0.0f, 8.0, 1, 0);
        }
        fired = true;
    }
    else if (cycle >= 0x348) {
        static constexpr std::array<int, 5> kInterval{{60, 30, 30, 30, 30}};
        static constexpr std::array<int, 5> kStep{{60, 70, 80, 80, 90}};
        static constexpr std::array<int, 5> kCount{{9, 13, 15, 17, 19}};
        static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 6.0, 6.0, 7.0}};
        const int local = cycle - 0x348;
        const int count = kCount[static_cast<std::size_t>(difficulty)];
        if (local == 0) {
            enemy.secondaryAngle16 = tail09Angle(
                static_cast<int>(aimed) + 2 * (0x10000 / (count * 3)));
        }
        const double speed = kSpeed[static_cast<std::size_t>(difficulty)] +
                             static_cast<double>(local) * 0.02;
        if (cycle < 0x4ec && local % 4 == 0) {
            spawnProjectileSpread(
                enemy.spawnType == 0xcb ? 3 : 2, 0,
                enemy.x, enemy.y, enemy.secondaryAngle16, 0.0f,
                speed, 1, count, 0x10000, 0);
            fired = true;
        }
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        int step = kStep[static_cast<std::size_t>(difficulty)] +
                   (local / interval) * 10;
        if (local % (interval * 2) < interval) step = -step;
        enemy.secondaryAngle16 = tail09Angle(
            static_cast<int>(enemy.secondaryAngle16) + step);
    }
    if (fired) playPlayerSound(bullet1SoundHandle_, 0x13);
}

bool StageRuntime::drawStage09TailMidboss(const StageEnemy& enemy,
                                           float x, float y) const {
    if (enemy.spawnType < 0x149 || enemy.spawnType > 0x14b) return false;
    if (!enemy.drawBodyThisFrame) return true;

    const auto handleAt = [](const std::vector<int>& frames, int index) {
        return index >= 0 && index < static_cast<int>(frames.size())
                   ? frames[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto draw = [this](int handle, float drawX, float drawY,
                             std::uint16_t angle = 0,
                             double scaleX = 1.0, double scaleY = 1.0,
                             bool reverse = false) {
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle,
                                  scaleX, scaleY, reverse);
        }
    };
    const int state = enemy.drawHelperState;
    const int timer = enemy.drawHelperTimer;
    int deathAlpha = 255;
    if (state == 2 && timer >= 90) {
        deathAlpha = std::clamp((100 - timer) * 25, 0, 255);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, deathAlpha);
    }

    if (enemy.spawnType == 0x149) {
        double scale = 1.0;
        int brightness = 255;
        int alpha = deathAlpha;
        if (state == 0) {
            scale = timer < 180
                        ? 0.3 + 0.7 * std::sin(
                              static_cast<double>(timer) * kTail09Pi / 360.0)
                        : 0.3;
            brightness = 0;
            if (timer < 60) {
                alpha = static_cast<int>(255.0 * std::sin(
                    static_cast<double>(timer) * kTail09Pi / 120.0));
            }
            else if (timer < 180) {
                brightness = static_cast<int>(255.0 * std::sin(
                    static_cast<double>(timer - 60) * kTail09Pi / 240.0));
            }
        }
        SetDrawBright(brightness, brightness, brightness);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(alpha, 0, 255));
        draw(handleAt(enemyLargeFrames_, 19), x, y, 0, scale, scale);
        double secondScale = scale;
        const int pulse = frame_ % 40;
        if (pulse < 11) {
            secondScale -= scale * 0.1 * std::sin(
                static_cast<double>(pulse) * kTail09Pi / 10.0);
        }
        draw(handleAt(enemyLargeFrames_, 20), x, y, 0,
             secondScale, secondScale);
        SetDrawBright(255, 255, 255);
    }
    else if (enemy.spawnType == 0x14a) {
        draw(handleAt(enemyLargeFrames_, 29), x, y - 110.0f);
        draw(handleAt(enemyLargeFrames_, 33), x, y - 110.0f);
        int bossFrame = 110;
        if (state == 2) {
            bossFrame = 113 + (timer / 5) % 2;
        }
        else {
            static constexpr std::array<int, 4> kFrames{{110, 111, 112, 111}};
            bossFrame = kFrames[static_cast<std::size_t>((timer / 6) % 4)];
        }
        draw(handleAt(bossFrames_, bossFrame), x, y);
        draw(handleAt(enemyLargeFrames_, 34), x, y - 495.0f);

        static constexpr std::array<float, 6> kOffsetX{{
            90.0f, 156.0f, -95.0f, -156.0f, 156.0f, -156.0f,
        }};
        static constexpr std::array<float, 6> kOffsetY{{
            -20.0f, -20.0f, 50.0f, 50.0f, -100.0f, -100.0f,
        }};
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::min(192, deathAlpha));
        const double introScale = timer < 30
                                      ? 0.1 + 0.6 * std::sin(
                                            static_cast<double>(timer) *
                                            kTail09Pi / 60.0)
                                      : 0.7;
        const double emitterScale = introScale + 0.2 * std::sin(
            static_cast<double>(timer) * kTail09Tau / 9.0);
        for (int i = 0; i < 6; ++i) {
            draw(handleAt(enemySmallFrames_, 56),
                 x + kOffsetX[static_cast<std::size_t>(i)],
                 y + kOffsetY[static_cast<std::size_t>(i)],
                 0, emitterScale, emitterScale);
        }
    }
    else {
        const int spin = std::max(0, frame_ - 1) * 0xb6;
        draw(handleAt(enemyLargeFrames_, 36), x, y, tail09Angle(-spin));
        draw(handleAt(enemyLargeFrames_, 36), x, y, tail09Angle(spin));
        draw(handleAt(enemyLargeFrames_, 37), x, y, enemy.secondaryAngle16);
        draw(handleAt(enemyLargeFrames_, 39), x, y, enemy.targetAngle16);
        draw(handleAt(enemyLargeFrames_, 38), x, y, enemy.targetAngle16);
        const double facing = tail09Radians(enemy.targetAngle16);
        draw(handleAt(enemyMediumFrames_, 103),
             x + static_cast<float>(std::cos(facing) * 90.0),
             y + static_cast<float>(std::sin(facing) * 90.0),
             enemy.targetAngle16);
    }

    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    return true;
}

bool StageRuntime::drawStage09TailMidbossNode(const StageEnemy& enemy,
                                               float x, float y) const {
    if (enemy.spawnType < 0xc8 || enemy.spawnType > 0xcc) return false;
    if (!enemy.drawBodyThisFrame) return true;

    const auto handleAt = [](const std::vector<int>& frames, int index) {
        return index >= 0 && index < static_cast<int>(frames.size())
                   ? frames[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto draw = [this](int handle, float drawX, float drawY,
                             std::uint16_t angle = 0,
                             double scaleX = 1.0, double scaleY = 1.0) {
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle,
                                  scaleX, scaleY, false);
        }
    };

    if (enemy.spawnType == 0xc8) {
        const StageEnemy* parent = nullptr;
        for (const auto& candidate : enemies_) {
            if (candidate.entityId == enemy.parentEntityId) {
                parent = &candidate;
                break;
            }
        }
        if (parent != nullptr) {
            const int index = std::clamp(enemy.childIndex, 0, 5);
            const float anchorModelX =
                parent->x + kTail09ChainX[static_cast<std::size_t>(index)];
            const float anchorModelY =
                parent->y + kTail09ChainY[static_cast<std::size_t>(index)];
            const float anchorX = x + anchorModelX - enemy.x;
            const float anchorY = y + anchorModelY - enemy.y;
            for (int segment = 0; segment < 20; ++segment) {
                if (enemy.drawHelperState == -1 &&
                    enemy.drawHelperTimer > 60 - segment * 3) {
                    continue;
                }
                double scale = 1.0;
                if (enemy.drawHelperState == 0) {
                    const int start = segment * 2;
                    if (enemy.drawHelperTimer < start) scale = 0.0;
                    else if (enemy.drawHelperTimer < start + 8) {
                        scale = std::sin(
                            static_cast<double>(enemy.drawHelperTimer - start) *
                            kTail09Pi / 16.0);
                    }
                }
                const float fraction = static_cast<float>(segment) / 20.0f;
                const float localX = anchorX + (x - anchorX) * fraction +
                    4.0f * std::sin(static_cast<double>(frame_ - segment * 7) *
                                    kTail09Tau / 80.0);
                const float localY = anchorY + (y - anchorY) * fraction;
                draw(handleAt(enemySmallFrames_, 43), localX, localY,
                     enemy.sourceAngle16, scale, scale);
            }
        }
        if (enemy.drawHelperState != -1) {
            double scale = 1.0;
            if (enemy.drawHelperState == 0) {
                if (enemy.drawHelperTimer < 40) scale = 0.0;
                else if (enemy.drawHelperTimer < 48) {
                    scale = std::sin(
                        static_cast<double>(enemy.drawHelperTimer - 40) *
                        kTail09Pi / 16.0);
                }
            }
            draw(handleAt(enemyMediumFrames_, 75), x, y,
                 enemy.sourceAngle16, scale, scale);
        }
        if (enemy.targetable) {
            StageEnemy snapshot = enemy;
            snapshot.hp = enemy.drawHp;
            drawEnemyGaugeExact(snapshot, 1, x, y - 80.0f);
        }
        return true;
    }

    if (enemy.spawnType == 0xcb || enemy.spawnType == 0xcc) return true;
    const StageEnemy* parent = nullptr;
    for (const auto& candidate : enemies_) {
        if (candidate.entityId == enemy.parentEntityId) {
            parent = &candidate;
            break;
        }
    }
    if (parent == nullptr) return true;

    const int timer = enemy.drawHelperTimer;
    if (enemy.spawnType == 0xc9) {
        double scale = 1.0;
        int alpha = 255;
        if (timer < 20) {
            scale = 2.0 - std::sin(
                static_cast<double>(timer) * kTail09Pi / 40.0);
            alpha = static_cast<int>(255.0 * std::sin(
                static_cast<double>(timer) * kTail09Pi / 40.0));
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(alpha, 0, 255));
        draw(handleAt(enemyLargeFrames_, 40), x, y,
             tail09Angle(static_cast<int>(parent->targetAngle16) +
                         static_cast<int>(enemy.targetAngle16)),
             scale, scale);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    else {
        double scale = timer < 20
                           ? std::sin(static_cast<double>(timer) *
                                      kTail09Pi / 40.0)
                           : 1.0;
        draw(handleAt(enemyMediumFrames_, 101), x, y,
             parent->targetAngle16, scale, scale);
    }
    return true;
}

} // namespace reconstructed
