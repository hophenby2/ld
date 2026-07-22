#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kBoss08Pi = 3.14159265358979323846;
constexpr double kBoss08Tau = kBoss08Pi * 2.0;

std::uint16_t boss08Angle(int value) {
    return static_cast<std::uint16_t>(value & 0xffff);
}

double boss08Radians(std::uint16_t angle) {
    return static_cast<double>(angle) * kBoss08Tau / 65536.0;
}

std::uint16_t boss08AngleTo(float x0, float y0, float x1, float y1) {
    return boss08Angle(static_cast<int>(
        std::atan2(static_cast<double>(y1 - y0),
                   static_cast<double>(x1 - x0)) *
        65536.0 / kBoss08Tau));
}

std::uint16_t boss08Approach(std::uint16_t current, std::uint16_t target,
                             int step) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return boss08Angle(static_cast<int>(current) +
                       std::clamp(delta, -step, step));
}

std::uint32_t boss08Rand(int frame) {
    const auto seed = static_cast<std::uint32_t>(frame);
    const std::uint32_t u = ((seed >> 30) ^ seed) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

double boss08Smooth(double value) {
    value = std::clamp(value, 0.0, 1.0);
    return value * value * (3.0 - 2.0 * value);
}

int boss08UpdateCase(int spawnType) {
    if (spawnType >= 0xa7 && spawnType <= 0xaa) return 0x69;
    if (spawnType == 0xab) return 0x6a;
    if (spawnType == 0xac) return 0x6b;
    if (spawnType == 0xad) return 0x6c;
    if (spawnType == 0xae || spawnType == 0xaf) return 0x6d;
    if (spawnType >= 0xb0 && spawnType <= 0xb3) return 0x6e;
    if (spawnType == 0xb4 || spawnType == 0xb5) return 0x6f;
    if (spawnType == 0xb6) return 0x70;
    if (spawnType == 0xb7) return 0x71;
    if (spawnType >= 0xb8 && spawnType <= 0xba) return 0x72;
    if (spawnType == 0xbb) return 0x73;
    if (spawnType >= 0xbc && spawnType <= 0xc2) return 0x74;
    if (spawnType == 0xc3) return 0x75;
    return -1;
}

int boss08EntityKind(int spawnType) {
    if (spawnType >= 0xa7 && spawnType <= 0xaa) return 0;
    if (spawnType == 0xab) return 24;
    if (spawnType == 0xac) return 120;
    if (spawnType >= 0xad && spawnType <= 0xb3) return 5;
    if (spawnType == 0xb6) return 7;
    if (spawnType == 0xb7) return 5;
    if (spawnType == 0xbb) return 77;
    if ((spawnType >= 0xb4 && spawnType <= 0xb5) ||
        (spawnType >= 0xb8 && spawnType <= 0xba) ||
        (spawnType >= 0xbc && spawnType <= 0xc3)) {
        return 1;
    }
    return 0;
}

bool boss08CombatState(int state) {
    return state == 1 || state == 2 || state == 11 || state == 21 ||
           state == 31 || state == 41 || state == 51 || state == 52 ||
           (state >= 62 && state <= 67);
}

} // namespace

bool StageRuntime::isStage08BossNodeType(int spawnType) const {
    return spawnType >= 0xa7 && spawnType <= 0xc3;
}

bool StageRuntime::spawnStage08BossNode(StageEnemy& parent, int spawnType,
                                        int childIndex, float offsetX,
                                        float offsetY,
                                        std::uint16_t angle16, double speed,
                                        int hitPoints, int radius,
                                        bool attached) {
    if (!isStage08BossNodeType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= 0x200) {
        return false;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = boss08UpdateCase(spawnType);
    node.sourceHitPoints = hitPoints;
    node.hp = std::max(1, hitPoints);
    node.maxHp = node.hp;
    node.drawHp = node.hp;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = 0x13f;
    node.childIndex = childIndex;
    node.originX = offsetX;
    node.originY = offsetY;
    node.x = attached ? parent.x + offsetX : offsetX;
    node.y = attached ? parent.y + offsetY : offsetY;
    node.sourceX = static_cast<int>(node.x);
    node.sourceY = static_cast<int>(node.y);
    node.sourceAngle16 = angle16;
    node.secondaryAngle16 = angle16;
    node.targetAngle16 = angle16;
    node.angle = static_cast<float>(boss08Radians(angle16));
    node.sourceSpeed = speed;
    node.speed = static_cast<float>(speed);
    node.radius = radius;
    const int kind = boss08EntityKind(spawnType);
    node.sourceDispatchKind = kind;
    node.sourceDispatchField = radius;
    node.rewardWeight = kind;
    node.activationDelay = 0;
    node.targetable = false;
    node.drawBodyThisFrame = true;
    node.sourceNote = "S08 FUN_140038190 internal boss node";
    pendingEnemies_.push_back(node);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage08BossNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || parent->spawnType != 0x13f || !parent->active) {
        enemy.active = false;
        return;
    }

    int timer = enemy.helperTimer;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto aimed = [&]() {
        return boss08AngleTo(enemy.x, enemy.y, player_.x, player_.y);
    };
    const auto move = [&](double speed) {
        const double radians = boss08Radians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * speed);
        enemy.y += static_cast<float>(std::sin(radians) * speed);
    };
    const auto smallFrame = [this](int index) {
        return index >= 0 && index < static_cast<int>(enemySmallFrames_.size())
                   ? enemySmallFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto mediumEffectFrame = [this](int index) {
        return index >= 0 && index < static_cast<int>(effectMediumFrames_.size())
                   ? effectMediumFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto mediumFrame = [this](int index) {
        return index >= 0 && index < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto spawnTrail = [this](int type, int handle, int layer,
                                   float x, float y, std::uint16_t angle,
                                   double scale, int lifetime) {
        spawnStageEffect(type, handle, 0, layer, x, y, angle,
                         0.0, scale, scale, lifetime,
                         0xff, 0xff, 0xff, 0x60);
    };
    const auto spawnTwinTrail = [&](double scale, double radius,
                                    std::uint16_t bladeAngle) {
        const double radians = boss08Radians(enemy.sourceAngle16);
        const float dx = static_cast<float>(std::cos(radians) * radius);
        const float dy = static_cast<float>(std::sin(radians) * radius);
        spawnTrail(5, smallFrame(136), 0x23,
                   enemy.x + dx, enemy.y + dy, bladeAngle, scale, 0x10);
        spawnTrail(7, smallFrame(136), 0x23,
                   enemy.x - dx, enemy.y - dy,
                   boss08Angle(static_cast<int>(bladeAngle) + 0x8000),
                   scale, 0x18);
        spawnTrail(5, smallFrame(135), 0x23,
                   enemy.x, enemy.y, 0, scale, 0x18);
    };

    switch (enemy.spawnType) {
    case 0xa7:
    case 0xa8: {
        const float side = (enemy.childIndex & 1) == 0 ? 1.0f : -1.0f;
        const float sway = static_cast<float>(
            std::sin((frame_ + enemy.childIndex * 17) * kBoss08Tau / 180.0) * 12.0);
        enemy.x = parent->x + enemy.originX + side * sway;
        enemy.y = parent->y + enemy.originY;
        if (parent->helperState == 11 && parent->helperTimer <= 3 &&
            enemy.helperState == 0 && enemy.spawnType == 0xa7) {
            spawnStage08BossNode(*parent, 0xa9, enemy.childIndex,
                                 enemy.originX, enemy.originY,
                                 0, 0.0, 99999999, 50, true);
            enemy.helperState = 1;
        }
        if (parent->helperState == 11 && parent->helperTimer <= 3 &&
            enemy.helperState == 0 && enemy.spawnType == 0xa8) {
            spawnStage08BossNode(*parent, 0xaa, enemy.childIndex,
                                 enemy.originX, enemy.originY,
                                 0, 0.0, 99999999, 50, true);
            enemy.helperState = 1;
        }
        if (parent->helperState >= 20) enemy.active = false;
        break;
    }
    case 0xa9:
    case 0xaa: {
        if (parent->helperState != 11) {
            enemy.active = false;
            break;
        }
        if (enemy.hp < parent->hp) {
            parent->hp = std::max(0, parent->hp - (parent->hp - enemy.hp));
        }
        enemy.hp = parent->hp;
        enemy.maxHp = parent->maxHp;
        enemy.drawHp = parent->drawHp;
        enemy.targetable = true;
        enemy.x = parent->x + enemy.originX;
        enemy.y = parent->y + enemy.originY;
        break;
    }
    case 0xab: {
        enemy.x = parent->x + enemy.originX;
        enemy.y = parent->y + enemy.originY;
        if (enemy.helperState == 0) {
            enemy.targetable = false;
            if (enemy.y < -50.0f) break;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            timer = enemy.helperTimer;
        }
        if (enemy.helperState == 2) {
            enemy.targetable = false;
            if (parent->helperState > 19 || enemy.y >= 900.0f) {
                enemy.active = false;
            }
            break;
        }
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x708, false);
            spawnEnemyDeathEffects(enemy, 1);
            enemy.targetable = false;
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            break;
        }
        if (parent->helperState >= 10) {
            spawnEnemyDeathEffects(enemy, 1);
            enemy.targetable = false;
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            if (parent->helperState > 19 || enemy.y >= 900.0f) {
                enemy.active = false;
            }
            break;
        }
        if (enemy.helperState != 1) {
            enemy.active = false;
            break;
        }
        enemy.targetable = true;
        static constexpr std::array<int, 5> kInterval{{90, 70, 55, 55, 55}};
        static constexpr std::array<double, 5> kSpeed{{
            8.0, 9.0, 9.5, 10.0, 11.1,
        }};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        const int local = (timer - 30) % interval;
        const auto target = aimed();
        const bool firingWindow = timer >= 30 && enemy.y < 350.0f &&
                                  local >= 0 && local <= 24;
        if (!firingWindow) {
            int delta = static_cast<int>(target) -
                        static_cast<int>(enemy.sourceAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            enemy.sourceAngle16 = boss08Approach(
                enemy.sourceAngle16, target, std::abs(delta) / 10 + 0x30);
        }
        if (firingWindow && local < 24 && local % 4 == 0) {
            const double radians = boss08Radians(enemy.sourceAngle16);
            const float fireX = enemy.x +
                static_cast<float>(std::cos(radians) * 25.0);
            const float fireY = enemy.y +
                static_cast<float>(std::sin(radians) * 25.0);
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(7, 0, fireX, fireY,
                                enemy.sourceAngle16, 40.0f,
                                speed, 1, 0);
            for (const int offset : {-600, 600}) {
                spawnProjectileNode(
                    7, 0, fireX, fireY,
                    boss08Angle(static_cast<int>(enemy.sourceAngle16) + offset),
                    40.0f, speed - 0.8, 1, 0);
            }
            if (difficulty > 0) {
                for (const int offset : {-1200, 1200}) {
                    spawnProjectileNode(
                        7, 0, fireX, fireY,
                        boss08Angle(
                            static_cast<int>(enemy.sourceAngle16) + offset),
                        40.0f, speed - 1.6, 1, 0);
                }
            }
            if (difficulty > 2) {
                for (const int offset : {-1800, 1800}) {
                    spawnProjectileNode(
                        7, 0, fireX, fireY,
                        boss08Angle(
                            static_cast<int>(enemy.sourceAngle16) + offset),
                        40.0f, speed - 0.8, 1, 0);
                }
            }
        }
        break;
    }
    case 0xac: {
        // FUN_140041e90 attaches these two destructible mounts at
        // (+/-205,-90), independently of the constructor's approximate data.
        const float mountX = enemy.childIndex == 0 ? 205.0f : -205.0f;
        const float baseY = parent->y - 90.0f;
        enemy.originX = mountX;
        enemy.originY = -90.0f;
        enemy.x = parent->x + mountX;
        enemy.y = baseY - 108.0f +
                  static_cast<float>(std::sin(timer * kBoss08Pi / 50.0) * 3.0);
        enemy.sourceAngle16 = 0;

        if (enemy.helperState == 0) {
            enemy.targetable = false;
            if (baseY < -120.0f) break;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }

        if (enemy.helperState == 1) {
            enemy.radius = 120;
            enemy.targetable = parent->helperState == 1 &&
                               parent->hp > 50000 && enemy.hp > 0;
            if (parent->helperState == 1) {
                int liveMounts = 0;
                for (const StageEnemy& candidate : enemies_) {
                    if (candidate.active && candidate.spawnType == 0xac &&
                        candidate.parentEntityId == parent->entityId &&
                        candidate.helperState < 2) {
                        ++liveMounts;
                    }
                }
                for (const StageEnemy& candidate : pendingEnemies_) {
                    if (candidate.active && candidate.spawnType == 0xac &&
                        candidate.parentEntityId == parent->entityId &&
                        candidate.helperState < 2) {
                        ++liveMounts;
                    }
                }

                const int cycle = (parent->helperTimer - 30) % 1800;
                const auto aim = aimed();
                if (cycle >= 0 && cycle < 640) {
                    static constexpr std::array<int, 5> kCount{{4, 6, 8, 8, 10}};
                    static constexpr std::array<int, 5> kAngleStep{{200, 240, 240, 300, 300}};
                    static constexpr std::array<double, 5> kSpeed{{4.8, 5.5, 6.0, 6.0, 7.0}};
                    int start = 0;
                    int growth = 0;
                    for (int burst = 0; growth < 36; ++burst, growth += 4) {
                        const int length = 20 + growth;
                        const bool assignedToThisMount = liveMounts < 2 ||
                            (mountX < 0.0f ? (burst & 1) != 0 : burst == 0);
                        if (cycle == start) enemy.secondaryAngle16 = aim;
                        if (assignedToThisMount && cycle >= start &&
                            cycle < start + length && (cycle - start) % 4 == 0) {
                            spawnProjectileSpread(
                                0x0d, 0, enemy.x, enemy.y,
                                enemy.secondaryAngle16, 30.0f,
                                kSpeed[static_cast<std::size_t>(difficulty)] +
                                    cycle * 0.007,
                                1, kCount[static_cast<std::size_t>(difficulty)],
                                30000, 0);
                            const int step = kAngleStep[
                                static_cast<std::size_t>(difficulty)];
                            enemy.secondaryAngle16 = boss08Angle(
                                static_cast<int>(enemy.secondaryAngle16) +
                                ((burst & 1) == 0 ? step : -step));
                            playPlayerSound(bullet1SoundHandle_, 0x13);
                        }
                        start += 56 + growth;
                    }
                }
                else if (cycle >= 680 && cycle < 960) {
                    static constexpr std::array<int, 5> kInterval{{150, 150, 100, 100, 100}};
                    static constexpr std::array<int, 5> kCount{{7, 11, 11, 13, 15}};
                    static constexpr std::array<double, 5> kSpeed{{4.2, 4.8, 5.5, 5.5, 6.0}};
                    const int interval = kInterval[static_cast<std::size_t>(difficulty)];
                    const int local = cycle - 680;
                    const int phase = local % interval;
                    if (phase < 48 && phase % 16 == 0) {
                        int count = kCount[static_cast<std::size_t>(difficulty)];
                        if (liveMounts < 2) count += 2;
                        const int minimumSpread = count * 400 - 400;
                        const int spread = phase < 40
                            ? static_cast<int>(
                                  std::sin(phase * kBoss08Pi / 80.0) *
                                      (0x8000 - minimumSpread)) + minimumSpread
                            : 0x8000;
                        const double speed =
                            kSpeed[static_cast<std::size_t>(difficulty)] +
                            local * 0.009 - phase * 0.04;
                        spawnProjectileSpread(2, 0, enemy.x, enemy.y, aim,
                                              0.0f, speed, 1, count, spread, 0);
                        if (difficulty > 2 && local % 100 == 0) {
                            const int insetCount = count - 2;
                            const int insetSpread =
                                (spread / insetCount) * (insetCount - 1);
                            spawnProjectileSpread(2, 0, enemy.x, enemy.y, aim,
                                                  0.0f, speed + 1.0, 1,
                                                  insetCount, insetSpread, 0);
                        }
                        playPlayerSound(bullet1SoundHandle_, 0x13);
                    }
                }
                else if (cycle >= 1000 && cycle < 1740) {
                    static constexpr std::array<int, 5> kInterval{{160, 120, 100, 85, 72}};
                    static constexpr std::array<int, 5> kCount{{8, 12, 14, 16, 16}};
                    const int phase = (cycle - 1000) %
                        kInterval[static_cast<std::size_t>(difficulty)];
                    if (phase < 40 && phase % 8 == 0) {
                        const int count = kCount[static_cast<std::size_t>(difficulty)];
                        spawnProjectileSpread(
                            2, 9, enemy.x, enemy.y,
                            boss08Angle(static_cast<int>(aim) - 0x8000),
                            0.0f, 4.0 + phase * 0.3, 1, count,
                            (count - 1) * 0x0d05, 0);
                        playPlayerSound(bullet1SoundHandle_, 0x13);
                    }
                }
            }

            const bool destroyed = enemy.hp < 1;
            if (destroyed || parent->hp < 50001 || parent->helperState > 9) {
                if (destroyed) {
                    spawnEnemyDeathRewardBurst(enemy, 4000, false);
                    spawnDelayedOwnerDamageNode(
                        enemy.maxHp, parent->entityId, parent->spawnType,
                        "S08 mount delayed-damage node 0x153");
                    spawnPlayerSideObject(0x19, enemy.x, enemy.y,
                                          0.0, 0, 0, 0.0f);
                }
                spawnEnemyDeathEffects(enemy, 2);
                enemy.targetable = false;
                enemy.helperState = 2;
                enemy.helperTimer = 0;
            }
        }
        else {
            enemy.targetable = false;
        }
        if (parent->helperState > 19 || enemy.y >= 920.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0xad: {
        // FUN_140042b10 keeps the warning marker for 20 frames, then turns
        // toward the player for 200 frames while accelerating every frame.
        const float horizontalOrigin = player_.x / 6.0f;
        int activeTimer = timer;
        if (enemy.helperState == 0) {
            enemy.drawBodyThisFrame = false;
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = timer;
            enemy.markerDrawX = std::clamp(
                enemy.x, horizontalOrigin - 20.0f,
                horizontalOrigin + 620.0f);
            enemy.markerDrawY = std::clamp(enemy.y, -20.0f, 740.0f);
            if (timer < 20) break;
            enemy.x = enemy.markerDrawX;
            enemy.y = enemy.markerDrawY;
            enemy.sourceAngle16 = boss08Angle(
                0x3a24 + static_cast<int>(boss08Rand(frame_) % 3001u));
            enemy.sourceSpeed = 6.0;
            enemy.speed = 6.0f;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            activeTimer = 0;
            enemy.targetable = true;
            enemy.drawBodyThisFrame = true;
            enemy.drawMarkerThisFrame = false;
        }

        if (enemy.helperState == 1) {
            if (activeTimer < 200) {
                enemy.sourceAngle16 = boss08Approach(
                    enemy.sourceAngle16, aimed(), 0xff);
            }
            enemy.sourceSpeed += 0.1;
            enemy.speed = static_cast<float>(enemy.sourceSpeed);
            move(enemy.sourceSpeed);

            if (activeTimer < 200) {
                const double radians = boss08Radians(enemy.sourceAngle16);
                const float fireX = enemy.x +
                    static_cast<float>(std::cos(radians) * 20.0);
                const float fireY = enemy.y +
                    static_cast<float>(std::sin(radians) * 20.0);
                if (fireX >= horizontalOrigin + 40.0f &&
                    fireX <= horizontalOrigin + 560.0f &&
                    fireY >= 40.0f && fireY <= 680.0f) {
                    static constexpr std::array<int, 5> kInterval{{18, 10, 6, 8, 6}};
                    static constexpr std::array<double, 5> kSpeed{{6.5, 7.2, 8.0, 8.5, 9.5}};
                    const int interval = kInterval[
                        static_cast<std::size_t>(difficulty)];
                    if (activeTimer > 4) {
                        const int phase = (activeTimer - 5) % (interval * 5);
                        const float dx = player_.x - fireX;
                        const float dy = player_.y - fireY;
                        if (phase < interval * 3 && phase % interval == 0 &&
                            dx * dx + dy * dy >= 90.0f * 90.0f) {
                            const auto snapped = boss08Angle(
                                ((static_cast<int>(boss08AngleTo(
                                      fireX, fireY, player_.x, player_.y)) +
                                  0x400) >> 11) * 0x800);
                            const double speed = kSpeed[
                                static_cast<std::size_t>(difficulty)];
                            spawnProjectileNode(0, 0, fireX, fireY, snapped,
                                                0.0f, speed, 1, 0);
                            if (difficulty > 2) {
                                spawnProjectileNode(
                                    0, 0, fireX, fireY,
                                    boss08Angle(static_cast<int>(snapped) - 2000),
                                    0.0f, speed - 1.0, 1, 0);
                                spawnProjectileNode(
                                    0, 0, fireX, fireY,
                                    boss08Angle(static_cast<int>(snapped) + 2000),
                                    0.0f, speed - 1.0, 1, 0);
                            }
                        }
                    }
                }
            }
            if ((activeTimer & 1) == 0) {
                const double radius =
                    std::sin(activeTimer * kBoss08Pi / 30.0) * 4.0;
                spawnTwinTrail(1.0, radius, enemy.sourceAngle16);
            }
        }
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 200, false);
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
        }
        if (enemy.x < horizontalOrigin - 180.0f ||
            enemy.x > horizontalOrigin + 780.0f ||
            enemy.y < -180.0f || enemy.y > 900.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0xae:
    case 0xaf: {
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.helperState != 0) {
            enemy.active = false;
            break;
        }
        enemy.targetable = true;
        if (timer == 0) {
            enemy.radius = 5;
        }
        if (timer < 30) {
            enemy.speed = static_cast<float>(
                std::sin(timer * kBoss08Pi / 60.0) * 200.0);
        }
        else if (timer > 59) {
            enemy.speed += static_cast<float>((timer - 60) * 0.15);
        }
        enemy.angle += 0.05f;
        const int turn = timer < 60
            ? 400 - static_cast<int>(
                        std::sin(timer * kBoss08Pi / 120.0) * 340.0)
            : 60;
        enemy.sourceAngle16 = boss08Angle(
            static_cast<int>(enemy.sourceAngle16) +
            (enemy.spawnType == 0xae ? turn : -turn));
        const double radians = boss08Radians(enemy.sourceAngle16);
        enemy.x = enemy.originX +
                  static_cast<float>(std::cos(radians) * enemy.speed);
        enemy.y = enemy.originY +
                  static_cast<float>(std::sin(radians) * enemy.speed * 0.5f);

        static constexpr std::array<int, 5> kInterval{{17, 11, 9, 10, 9}};
        static constexpr std::array<double, 5> kSpeed{{4.0, 5.0, 6.0, 5.5, 6.5}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        if (timer > 59 && (timer - 60) % interval == 0) {
            const float dx = player_.x - enemy.x;
            const float dy = player_.y - enemy.y;
            if (enemy.x >= horizontalOrigin &&
                enemy.x <= horizontalOrigin + 600.0f &&
                enemy.y >= 0.0f && enemy.y <= 720.0f &&
                dx * dx + dy * dy >= 60.0f * 60.0f) {
                const int sweep = timer * 0x50 - 0x12c0;
                const auto heading = boss08Angle(
                    static_cast<int>(enemy.sourceAngle16) +
                    (enemy.spawnType == 0xae ? sweep : -sweep));
                const double speed = kSpeed[
                    static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(7, 2, enemy.x, enemy.y, heading,
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(
                    7, 2, enemy.x, enemy.y,
                    boss08Angle(static_cast<int>(heading) - 0x8000),
                    0.0f, speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(7, 2, enemy.x, enemy.y, heading,
                                        0.0f, speed + 1.2, 1, 0);
                    spawnProjectileNode(
                        7, 2, enemy.x, enemy.y,
                        boss08Angle(static_cast<int>(heading) - 0x8000),
                        0.0f, speed + 1.2, 1, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x0c);
            }
        }
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 300, false);
            if (player_.bombLock == 0) {
                spawnDelayedOwnerDamageNode(
                    enemy.maxHp, parent->entityId, parent->spawnType,
                    "S08 spiral node delayed-damage node 0x153");
            }
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
        }
        if (parent->helperState > 9 ||
            enemy.x < horizontalOrigin - 200.0f ||
            enemy.x > horizontalOrigin + 800.0f ||
            enemy.y < -200.0f || enemy.y > 920.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0xb0:
    case 0xb1:
    case 0xb2:
    case 0xb3: {
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.helperState != 0) {
            enemy.active = false;
            break;
        }
        enemy.targetable = true;
        static constexpr std::array<int, 5> kNodeCount{{7, 7, 9, 9, 9}};
        static constexpr std::array<int, 5> kSlowTurn{{150, 180, 222, 222, 222}};
        static constexpr std::array<int, 5> kFastTurn{{330, 300, 300, 280, 280}};
        if (timer == 0) {
            const int count = kNodeCount[static_cast<std::size_t>(difficulty)];
            enemy.sourceAngle16 = boss08Angle(
                enemy.childIndex * (0x10000 / count));
            enemy.speed = 0.0f;
            enemy.radius = 5;
        }
        if (timer < 30) {
            enemy.speed = static_cast<float>(
                std::sin(timer * kBoss08Pi / 60.0) * 200.0);
        }
        const bool reverse = enemy.spawnType == 0xb1 ||
                             enemy.spawnType == 0xb3;
        const int turn = enemy.spawnType < 0xb2
            ? kSlowTurn[static_cast<std::size_t>(difficulty)]
            : kFastTurn[static_cast<std::size_t>(difficulty)];
        enemy.sourceSpeed = reverse ? -turn : turn;
        enemy.sourceAngle16 = boss08Angle(
            static_cast<int>(enemy.sourceAngle16) +
            static_cast<int>(enemy.sourceSpeed));

        const double parentPhase =
            std::sin(parent->helperState * 257.00392156862745 *
                     kBoss08Pi / 32768.0) *
            (reverse ? -2500.0 : 2500.0);
        const double phase = boss08Radians(boss08Angle(
            static_cast<int>(parentPhase)));
        const double orbit = boss08Radians(enemy.sourceAngle16);
        const double radius = enemy.speed;
        enemy.originX = 0.0f;
        enemy.originY = 0.0f;
        enemy.x = parent->x + static_cast<float>(
            std::cos(phase) * std::cos(orbit) * radius -
            std::sin(phase) * std::sin(orbit) * radius * 0.5);
        enemy.y = parent->y + static_cast<float>(
            std::cos(phase) * std::sin(orbit) * radius * 0.5 +
            std::sin(phase) * std::cos(orbit) * radius);

        if (enemy.spawnType < 0xb2) {
            static constexpr std::array<int, 5> kInterval{{20, 11, 9, 7, 6}};
            static constexpr std::array<double, 5> kSpeed{{3.0, 4.0, 4.5, 5.0, 6.0}};
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            if (timer > 49 && (timer - 50) % interval == 0) {
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] + timer * 0.006;
                const auto first = boss08Angle(
                    static_cast<int>(enemy.sourceAngle16) - 0x0ad9);
                spawnProjectileNode(1, 0, enemy.x, enemy.y, first,
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(
                    1, 0, enemy.x, enemy.y,
                    boss08Angle(static_cast<int>(first) + 0x15b3),
                    0.0f, speed, 1, 0);
                playPlayerSound(bullet1SoundHandle_, 0x0c);
            }
        }
        else {
            static constexpr std::array<int, 5> kPeriod{{18, 11, 10, 11, 10}};
            static constexpr std::array<int, 5> kActive{{3, 5, 5, 7, 7}};
            static constexpr std::array<double, 5> kSpeed{{4.2, 5.0, 5.5, 6.0, 7.0}};
            const int phaseIndex = (timer - 50) %
                kPeriod[static_cast<std::size_t>(difficulty)];
            if (timer > 49 && phaseIndex >= 0 &&
                phaseIndex < kActive[static_cast<std::size_t>(difficulty)]) {
                spawnProjectileNode(
                    1, 0, enemy.x, enemy.y, enemy.sourceAngle16, 0.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                        phaseIndex * 0.25,
                    1, 0);
                playPlayerSound(bullet1SoundHandle_, 0x0c);
            }
        }

        if (timer > 29 && (timer - 30) % 72 == 0) {
            static constexpr std::array<double, 5> kRearSpeed{{3.0, 3.5, 4.0, 4.0, 4.5}};
            spawnProjectileNode(
                5, 2, enemy.x, enemy.y,
                boss08Angle(static_cast<int>(enemy.sourceAngle16) - 0x8000),
                0.0f, kRearSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
        }
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 300, false);
            if (player_.bombLock == 0) {
                spawnDelayedOwnerDamageNode(
                    enemy.maxHp, parent->entityId, parent->spawnType,
                    "S08 orbit node delayed-damage node 0x153");
            }
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
        }
        if (timer == 250 || parent->helperState > 29 ||
            enemy.x < horizontalOrigin - 200.0f ||
            enemy.x > horizontalOrigin + 800.0f ||
            enemy.y < -200.0f || enemy.y > 920.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0xb4:
    case 0xb5: {
        if (parent->hp < 1 || lateStageBossCountdown_ < 1) {
            enemy.active = false;
            break;
        }
        const int direction = enemy.spawnType == 0xb4 ? 1 : -1;
        const double radialPhase = std::clamp(timer, 0, 120) *
                                   kBoss08Pi / 240.0;
        const float horizontalRadius = static_cast<float>(
            std::sin(radialPhase) * 150.0);
        const float verticalRadius = horizontalRadius * 0.5f;
        enemy.sourceAngle16 = boss08Angle(
            static_cast<int>(enemy.sourceAngle16) +
            direction * static_cast<int>(enemy.sourceSpeed));
        enemy.secondaryAngle16 = boss08Angle(
            static_cast<int>(enemy.secondaryAngle16) + direction * 0x4d);
        const double tilt = boss08Radians(enemy.secondaryAngle16);
        const double orbit = boss08Radians(enemy.sourceAngle16);
        const double tiltCos = std::cos(tilt);
        const double tiltSin = std::sin(tilt);
        const double orbitCos = std::cos(orbit);
        const double orbitSin = std::sin(orbit);
        enemy.x = parent->x + enemy.originX +
                  static_cast<float>(
                      tiltCos * orbitCos * horizontalRadius -
                      tiltSin * orbitSin * verticalRadius);
        enemy.y = parent->y + enemy.originY +
                  static_cast<float>(
                      tiltCos * orbitSin * verticalRadius +
                      tiltSin * orbitCos * horizontalRadius);
        enemy.targetable = false;
        const int interval = std::array<int, 5>{{3, 2, 1, 1, 1}}[
            static_cast<std::size_t>(difficulty)];
        if (timer >= 50 && (timer - 50) % interval == 0) {
            const int selector = enemy.spawnType == 0xb4 ? 0x0d : 0x0c;
            spawnProjectileNode(selector, 1, enemy.x, enemy.y,
                                enemy.secondaryAngle16, 0.0f, 0.0, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(selector, 1, enemy.x, enemy.y,
                                    enemy.secondaryAngle16,
                                    0.0f, 0.5, 1, 0);
            }
            if (difficulty > 3) {
                spawnProjectileNode(
                    selector, 1, enemy.x, enemy.y,
                    boss08Angle(static_cast<int>(enemy.secondaryAngle16) -
                                0x8000),
                    0.0f, 0.0, 1, 0);
            }
            const int angleStep = std::array<int, 5>{{0xce4, 0x8fc, 0x834,
                                                       0x834, 0x834}}[
                static_cast<std::size_t>(difficulty)];
            enemy.secondaryAngle16 = boss08Angle(
                static_cast<int>(enemy.secondaryAngle16) +
                direction * angleStep);
            playPlayerSound(bullet1SoundHandle_, 0x13);
        }
        if ((timer & 1) == 0) {
            double appendageScale = 0.0;
            if (timer >= 30) {
                appendageScale = 1.0;
            }
            else if (timer >= 10) {
                appendageScale = std::sin(
                    static_cast<double>(timer - 10) * kBoss08Pi / 40.0);
            }
            spawnTrail(5, smallFrame(137), 0x23, enemy.x, enemy.y,
                       boss08Angle(timer * 0x309), appendageScale, 0x10);
        }
        break;
    }
    case 0xb6: {
        if (parent->hp < 1 || lateStageBossCountdown_ < 1) {
            enemy.active = false;
            break;
        }
        enemy.targetable = true;
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 300, false);
            if (player_.bombLock == 0) {
                spawnDelayedOwnerDamageNode(
                    enemy.maxHp, parent->entityId, parent->spawnType,
                    "S08 launched node delayed-damage node 0x153");
            }
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
            break;
        }

        double liveSpeed = 0.0;
        if (timer < 60) {
            liveSpeed = enemy.sourceSpeed *
                (1.0 - std::sin(timer * kBoss08Pi / 120.0));
        }
        move(liveSpeed);

        const int parentCycle = parent->helperTimer % 1600;
        const int local = parentCycle % 350;
        const int start = std::array<int, 5>{{130, 110, 100, 100, 100}}[
            static_cast<std::size_t>(difficulty)];
        const int interval = std::array<int, 5>{{150, 60, 50, 40, 40}}[
            static_cast<std::size_t>(difficulty)];
        const int count = std::array<int, 5>{{3, 5, 7, 7, 9}}[
            static_cast<std::size_t>(difficulty)];
        const double shotSpeed =
            std::array<double, 5>{{5.0, 6.0, 6.5, 7.5, 8.5}}[
                static_cast<std::size_t>(difficulty)];
        if (local >= start && local < 240 &&
            (local - start) % interval == 0) {
            const int spread = (count - 1) * 0x168;
            spawnProjectileSpread(0x0d, 0, enemy.x, enemy.y,
                                  aimed(), 10.0f, shotSpeed, 1,
                                  count, spread, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(0x0d, 0, enemy.x, enemy.y,
                                      aimed(), 10.0f, shotSpeed + 0.6, 1,
                                      count - 1,
                                      std::max(0, spread - 0x168), 0);
            }
            playPlayerSound(bullet1SoundHandle_, 0x13);
        }

        if (timer == 200) {
            const int ringCount =
                std::array<int, 5>{{17, 25, 31, 23, 27}}[
                    static_cast<std::size_t>(difficulty)];
            const double ringSpeed =
                std::array<double, 5>{{4.5, 5.5, 6.0, 6.5, 7.5}}[
                    static_cast<std::size_t>(difficulty)];
            const int selector = difficulty > 2 ? 4 : 2;
            if (difficulty > 2) {
                spawnProjectileSpread(
                    4, 7, enemy.x, enemy.y,
                    boss08Angle(static_cast<int>(enemy.sourceAngle16) +
                                0x10000 / (ringCount * 2)),
                    0.0f, ringSpeed - 1.0, 1,
                    ringCount, 0x10000, 0);
            }
            spawnProjectileSpread(selector, 7, enemy.x, enemy.y,
                                  enemy.sourceAngle16, 0.0f,
                                  ringSpeed, 1, ringCount, 0x10000, 0);
            enemy.active = false;
        }
        if (enemy.x < -150.0f || enemy.x > 870.0f ||
            enemy.y < -150.0f || enemy.y > 870.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0xb7: {
        if (parent->hp < 1 || lateStageBossCountdown_ < 1) {
            enemy.active = false;
            break;
        }
        enemy.targetable = true;
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 200, false);
            if (player_.bombLock == 0) {
                spawnDelayedOwnerDamageNode(
                    enemy.maxHp, parent->entityId, parent->spawnType,
                    "S08 blade node delayed-damage node 0x153");
            }
            spawnEnemyDeathEffects(enemy, 0);
            enemy.active = false;
            break;
        }

        if (enemy.helperState == 0) {
            const double scale = timer < 50
                                     ? 0.2 +
                                           std::sin(timer * kBoss08Pi / 100.0) *
                                               0.8
                                     : 1.0;
            move(enemy.sourceSpeed * scale);
            if (timer == 50) {
                const float horizontalOrigin = player_.x / 6.0f;
                enemy.x = std::clamp(enemy.x,
                                     horizontalOrigin - 20.0f,
                                     horizontalOrigin + 620.0f);
                enemy.y = std::clamp(enemy.y, -20.0f, 740.0f);
                enemy.sourceSpeed = 8.0;
                enemy.sourceAngle16 = boss08Angle(
                    static_cast<int>(boss08Rand(frame_) % 3001u) + 0x3a24);
                enemy.helperState = 1;
                enemy.helperTimer = 0;
            }
        }
        else if (enemy.helperState == 1) {
            enemy.sourceSpeed += 0.1;
            move(enemy.sourceSpeed);
            const int interval =
                std::array<int, 5>{{22, 15, 9, 7, 6}}[
                    static_cast<std::size_t>(difficulty)];
            const double shotSpeed =
                std::array<double, 5>{{5.0, 6.0, 6.5, 7.0, 8.8}}[
                    static_cast<std::size_t>(difficulty)];
            const double dx = static_cast<double>(player_.x - enemy.x);
            const double dy = static_cast<double>(player_.y - enemy.y);
            if (timer < 40 && timer % interval == 0 &&
                dx * dx + dy * dy >= 90.0 * 90.0) {
                const int snapped =
                    ((static_cast<int>(aimed()) + 0x400) >> 11) * 0x800;
                spawnProjectileNode(0x0c, 0, enemy.x, enemy.y,
                                    boss08Angle(snapped), 0.0f,
                                    shotSpeed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(0x0c, 0, enemy.x, enemy.y,
                                        boss08Angle(snapped - 0x15ae),
                                        0.0f, shotSpeed - 1.0, 1, 0);
                    spawnProjectileNode(0x0c, 0, enemy.x, enemy.y,
                                        boss08Angle(snapped + 0x15ae),
                                        0.0f, shotSpeed - 1.0, 1, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }
        if ((timer & 1) == 0) {
            const double scale = enemy.helperState == 0 && timer < 50
                                     ? 0.2 +
                                           std::sin(timer * kBoss08Pi / 100.0) *
                                               0.8
                                     : 1.0;
            const double radius =
                std::sin(timer * kBoss08Pi / 30.0) * 8.0 * scale;
            spawnTwinTrail(scale, radius, enemy.sourceAngle16);
        }
        if (enemy.x < -150.0f || enemy.x > 870.0f ||
            enemy.y < -150.0f || enemy.y > 870.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0xb8: {
        if (parent->helperState >= 60) {
            if (enemy.helperState != 9) {
                enemy.helperState = 9;
                enemy.helperTimer = 0;
                break;
            }
            enemy.targetable = false;
            if (timer >= 120) enemy.active = false;
            break;
        }
        const float enterOffset = timer < 30
                                      ? static_cast<float>(
                                            std::sin((timer + 30) *
                                                     kBoss08Pi / 60.0) *
                                            600.0)
                                      : 0.0f;
        enemy.x = parent->x + enemy.originX;
        enemy.y = parent->y + enemy.originY + enterOffset;
        if (enemy.helperState == 0 && timer == 20) {
            spawnStage08BossNode(*parent, 0xb9, 0, 0.0f, -180.0f,
                                 0, 0.0, 99999999, 80, true);
        }
        if (enemy.helperState == 0 && timer == 50) {
            spawnStage08BossNode(*parent, 0xba, 0, 185.0f, -60.0f,
                                 0x4000, 0.0, 99999999, 110, true);
            spawnStage08BossNode(*parent, 0xba, 1, -185.0f, -60.0f,
                                 0x4000, 0.0, 99999999, 110, true);
        }
        if (parent->helperState == 52 && enemy.helperState == 0) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        break;
    }
    case 0xb9: {
        if (parent->helperState >= 60) {
            if (enemy.helperState != 9) {
                enemy.helperState = 9;
                enemy.helperTimer = 0;
                break;
            }
            enemy.targetable = false;
            if (timer >= 60) enemy.active = false;
            break;
        }
        const float enterOffset = timer < 30
                                      ? static_cast<float>(
                                            std::sin((timer + 30) *
                                                     kBoss08Pi / 60.0) *
                                            600.0)
                                      : 0.0f;
        enemy.x = parent->x + enemy.originX;
        enemy.y = parent->y + enemy.originY - enterOffset;
        if (parent->helperState == 52 && enemy.helperState == 0) {
            spawnSharedHitboxProxy(enemy, 0x152, 145.0f, -50.0f, 90);
            spawnSharedHitboxProxy(enemy, 0x152, -145.0f, -50.0f, 90);
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        if (enemy.helperState == 1) {
            if (enemy.hp > parent->hp) enemy.hp = parent->hp;
            if (enemy.hp < parent->hp) parent->hp = enemy.hp;
            enemy.targetable = true;
            const int phaseTimer = enemy.helperTimer;
            const int cycle = phaseTimer >= 100
                                  ? (phaseTimer - 100) % 1800
                                  : -1;
            const float rightX = enemy.x + 135.0f;
            const float leftX = enemy.x - 135.0f;
            const float fireY = enemy.y - 15.0f;
            if (cycle >= 0 && cycle < 550) {
                const int interval =
                    std::array<int, 5>{{14, 11, 9, 10, 9}}[
                        static_cast<std::size_t>(difficulty)];
                if (cycle % interval == 0) {
                    const int rows = difficulty == 0 ? 3 : 5;
                    const double speed =
                        std::array<double, 5>{{3.5, 4.5, 4.5, 5.0, 6.6}}[
                            static_cast<std::size_t>(difficulty)] +
                        cycle * 0.005;
                    const int rightAim = static_cast<int>(boss08AngleTo(
                        rightX, fireY, player_.x, player_.y));
                    const int leftAim = static_cast<int>(boss08AngleTo(
                        leftX, fireY, player_.x, player_.y));
                    for (int i = 0; i < rows; ++i) {
                        const int offset = rows == 1
                                               ? 0
                                               : -10000 +
                                                     i * (20000 / (rows - 1));
                        spawnProjectileNode(4, 0, rightX, fireY,
                                            boss08Angle(rightAim + offset),
                                            0.0f, speed, 1, 0);
                        spawnProjectileNode(4, 0, leftX, fireY,
                                            boss08Angle(leftAim - offset),
                                            0.0f, speed, 1, 0);
                        if (difficulty > 2) {
                            spawnProjectileNode(4, 0, rightX, fireY,
                                                boss08Angle(rightAim + offset),
                                                0.0f, speed + 0.6, 1, 0);
                            spawnProjectileNode(4, 0, leftX, fireY,
                                                boss08Angle(leftAim - offset),
                                                0.0f, speed + 0.6, 1, 0);
                        }
                    }
                    playPlayerSound(bullet1SoundHandle_, 0x13);
                }
            }
            else if (cycle >= 720 && cycle < 1250) {
                const int interval =
                    std::array<int, 5>{{90, 60, 48, 32, 27}}[
                        static_cast<std::size_t>(difficulty)];
                if ((cycle - 720) % interval == 0) {
                    const double speed =
                        std::array<double, 5>{{5.0, 6.0, 7.0, 8.0, 9.0}}[
                            static_cast<std::size_t>(difficulty)];
                    for (const float fireX : {leftX, rightX}) {
                        const int center = static_cast<int>(boss08AngleTo(
                            fireX, fireY, player_.x, player_.y));
                        for (const int offset : {-0x457, 0, 0x457}) {
                            spawnProjectileNode(0x0d, 0, fireX, fireY,
                                                boss08Angle(center + offset),
                                                0.0f,
                                                speed - (offset == 0 ? 0.0 : 0.6),
                                                1, 0);
                        }
                    }
                    playPlayerSound(bullet1SoundHandle_, 0x13);
                }
            }
            else if (cycle >= 1300 && cycle < 1740) {
                const int count =
                    std::array<int, 5>{{4, 5, 6, 8, 9}}[
                        static_cast<std::size_t>(difficulty)];
                const int interval =
                    std::array<int, 5>{{5, 4, 4, 4, 3}}[
                        static_cast<std::size_t>(difficulty)];
                if ((cycle - 1300) % (interval * 2) == 0) {
                    const double speed =
                        std::array<double, 5>{{4.5, 5.0, 5.0, 5.0, 6.5}}[
                            static_cast<std::size_t>(difficulty)];
                    spawnProjectileSpread(4, 0, rightX, fireY,
                                          enemy.secondaryAngle16, 0.0f,
                                          speed, 1, count, 0x10000, 0);
                    spawnProjectileSpread(4, 0, leftX, fireY,
                                          enemy.targetAngle16, 0.0f,
                                          speed, 1, count, 0x10000, 0);
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                }
                const int step =
                    std::array<int, 5>{{0xf0, 0xf0, 0xdc, 200, 0xdc}}[
                        static_cast<std::size_t>(difficulty)];
                enemy.secondaryAngle16 = boss08Angle(
                    static_cast<int>(enemy.secondaryAngle16) - step);
                enemy.targetAngle16 = boss08Angle(
                    static_cast<int>(enemy.targetAngle16) + step);
            }
        }
        break;
    }
    case 0xba: {
        const bool left = enemy.originX < 0.0f;
        if (parent->helperState >= 60) {
            if (enemy.helperState != 9) {
                enemy.helperState = 9;
                enemy.helperTimer = 0;
                break;
            }
            enemy.targetable = false;
            const int end = left ? 100 : 80;
            if (timer >= end) enemy.active = false;
            break;
        }
        const float enterOffset = timer < 30
                                      ? static_cast<float>(
                                            std::sin((timer + 30) *
                                                     kBoss08Pi / 60.0) *
                                            (left ? -600.0 : 600.0))
                                      : 0.0f;
        enemy.x = parent->x + enemy.originX + enterOffset;
        enemy.y = parent->y + enemy.originY;
        if (parent->helperState == 51 && timer < 30) {
            const auto trailAngle = boss08Angle(
                static_cast<int>(enemy.sourceAngle16) +
                (left ? 0x8000 : 0));
            spawnTrail(left ? 7 : 5, smallFrame(136), 0x1d,
                       enemy.x, enemy.y, trailAngle, 1.0, 0x10);
        }
        if (parent->helperState == 52 && enemy.helperState == 0) {
            spawnStage08BossNode(*parent, 0xbb, enemy.childIndex,
                                 enemy.originX, enemy.originY,
                                 left ? 0xf63c : 0x09c4,
                                 0.0, 40000, 50, true);
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        if (enemy.helperState == 1) {
            if (enemy.hp > parent->hp) enemy.hp = parent->hp;
            if (enemy.hp < parent->hp) parent->hp = enemy.hp;
            enemy.targetable = true;
            const int phaseTimer = enemy.helperTimer;
            const int cycle = phaseTimer >= 100
                                  ? (phaseTimer - 100) % 1800
                                  : -1;
            if (cycle >= 600 && cycle < 1250) {
                const int fanCount =
                    std::array<int, 5>{{7, 7, 9, 11, 11}}[
                        static_cast<std::size_t>(difficulty)];
                const int groups = difficulty == 0 ? 9 : 11;
                const int interval =
                    std::array<int, 5>{{44, 33, 33, 33, 27}}[
                        static_cast<std::size_t>(difficulty)];
                const int phase = cycle - 600;
                const int slot = phase % (interval * 10);
                if (slot < interval * 4 && slot % interval == 0) {
                    const double speed =
                        std::array<double, 5>{{3.5, 4.5, 5.0, 5.0, 6.0}}[
                            static_cast<std::size_t>(difficulty)] +
                        (cycle - 600) * 0.004;
                    for (int i = 0; i < groups; ++i) {
                        const auto center = boss08Angle(
                            static_cast<int>(enemy.secondaryAngle16) +
                            i * (0x10000 / groups));
                        spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                              center, 0.0f, speed, 1,
                                              fanCount,
                                              (fanCount - 1) * 0x168, 0);
                        if (difficulty > 2) {
                            spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                                  center, 0.0f, speed + 0.5,
                                                  1, fanCount,
                                                  std::max(0,
                                                      (fanCount - 2) * 0x168),
                                                  0);
                        }
                    }
                    const int turn = 0x10000 / (fanCount * 3);
                    enemy.secondaryAngle16 = boss08Angle(
                        static_cast<int>(enemy.secondaryAngle16) +
                        (left ? -turn : turn));
                    playPlayerSound(bullet1SoundHandle_, 0x13);
                }
            }
            else if (cycle >= 1300 && cycle < 1740) {
                const int count =
                    std::array<int, 5>{{3, 4, 5, 7, 8}}[
                        static_cast<std::size_t>(difficulty)];
                const int interval =
                    std::array<int, 5>{{6, 5, 5, 5, 4}}[
                        static_cast<std::size_t>(difficulty)];
                if ((cycle - 1300 - (left ? interval : 0)) >= 0 &&
                    (cycle - 1300 - (left ? interval : 0)) %
                            (interval * 2) == 0) {
                    const double speed =
                        std::array<double, 5>{{4.0, 5.0, 5.5, 6.0, 7.0}}[
                            static_cast<std::size_t>(difficulty)];
                    spawnProjectileSpread(2, 0, enemy.x, enemy.y,
                                          enemy.secondaryAngle16, 0.0f,
                                          speed, 1, count, 0x10000, 0);
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                }
                const int step =
                    std::array<int, 5>{{0xdc, 0xdc, 200, 0xb4, 0xd2}}[
                        static_cast<std::size_t>(difficulty)];
                enemy.secondaryAngle16 = boss08Angle(
                    static_cast<int>(enemy.secondaryAngle16) +
                    (left ? step : -step));
            }
        }
        break;
    }
    case 0xbb:
        if (parent->helperState != 52) {
            enemy.active = false;
            break;
        }
        {
        const StageEnemy* wing = nullptr;
        for (const StageEnemy& candidate : enemies_) {
            if (candidate.active && candidate.spawnType == 0xba &&
                candidate.parentEntityId == parent->entityId &&
                candidate.childIndex == enemy.childIndex) {
                wing = &candidate;
                break;
            }
        }
        if (wing == nullptr) {
            enemy.active = false;
            break;
        }
        enemy.targetable = true;
        const auto orbitAngle = boss08Angle(
            static_cast<int>(wing->sourceAngle16) +
            static_cast<int>(enemy.secondaryAngle16));
        enemy.x = wing->x + static_cast<float>(
            std::cos(boss08Radians(orbitAngle)) * 170.0);
        enemy.y = wing->y + static_cast<float>(
            std::sin(boss08Radians(orbitAngle)) * 170.0);
        const int cycle = wing->helperTimer % 300;
        if (cycle == 1) {
            const int pulse = mediumEffectFrame(20);
            spawnStageEffect(0x41, pulse, 0, 0x50,
                             enemy.x, enemy.y, enemy.sourceAngle16,
                             0.0, 0.6, 0.6, 100,
                             0xff, 0xff, 0xff, 0x80,
                             enemy.entityId);
            playPlayerSound(bossSe2SecondSoundHandle_, 0x19);
            enemy.sourceAngle16 = wing->sourceAngle16;
        }
        if (cycle <= 50) {
            enemy.sourceAngle16 = boss08Approach(enemy.sourceAngle16,
                                                 aimed(), 0x30);
        }
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 4000, false);
            spawnDelayedOwnerDamageNode(
                enemy.maxHp, parent->entityId, parent->spawnType,
                "S08 wing controller delayed-damage node 0x153");
            spawnPlayerSideObject(0x19, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
            spawnEnemyDeathEffects(enemy, 2);
            enemy.active = false;
            break;
        }
        if (cycle >= 100 && cycle < 300 && (cycle - 100) % 3 == 0) {
            const int spread = cycle < 160
                                   ? 0
                                   : (cycle - 160) *
                                         std::array<int, 5>{{0, 30, 50, 80, 100}}[
                                             static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(3, 0, enemy.x, enemy.y,
                                  enemy.sourceAngle16, 10.0f,
                                  12.0, 1, 4,
                                  spread, 0);
            playPlayerSound(bullet1SoundHandle_, 0x13);
        }
        }
        break;
    case 0xbc:
    case 0xbd:
    case 0xbe:
    case 0xbf:
    case 0xc0:
    case 0xc1:
    case 0xc2: {
        // FUN_1400488b0 gives all seven colors the same 60-frame
        // decelerating entrance, then dispatches a distinct firing pattern.
        // The firing origin is sampled before the node's 0.5 px/frame drift.
        int nodeTimer = timer;
        const float fireBaseX = enemy.x;
        const float fireBaseY = enemy.y;
        const auto fireAngle = enemy.sourceAngle16;
        const float fireX = fireBaseX + static_cast<float>(
            std::cos(boss08Radians(fireAngle)) * 20.0);
        const float fireY = fireBaseY + static_cast<float>(
            std::sin(boss08Radians(fireAngle)) * 20.0);
        const auto homeTowardPlayer = [&]() {
            const auto target = aimed();
            int delta = static_cast<int>(target) -
                        static_cast<int>(enemy.sourceAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            const int step = std::abs(delta) / 10 + 0x30;
            enemy.sourceAngle16 =
                boss08Approach(enemy.sourceAngle16, target, step);
        };
        const int family = std::clamp(
            (parent->helperState >= 65 ? parent->helperState - 65
                                       : parent->helperState - 62),
            0, 2);
        const double familySpeed = family * 0.5;

        if (enemy.helperState == 0) {
            homeTowardPlayer();
            const double entranceSpeed =
                enemy.sourceSpeed - enemy.sourceSpeed * nodeTimer / 60.0 + 0.5;
            move(entranceSpeed);
            if (nodeTimer == 60) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.sourceSpeed = 0.5;
                nodeTimer = 0;
            }
            else if ((nodeTimer & 1) == 0) {
                const double wave = std::sin(
                    static_cast<double>(nodeTimer) * kBoss08Pi / 120.0);
                const double scale = 0.2 + wave * 0.8;
                const int entranceTurn =
                    -static_cast<int>(wave * 131072.0);
                const auto bladeAngle = boss08Angle(
                    static_cast<int>(enemy.secondaryAngle16) + entranceTurn);
                spawnTwinTrail(scale, -4.0 * scale, bladeAngle);
            }
        }

        if (enemy.helperState == 1) {
            move(enemy.sourceSpeed);
            int duration = 40;
            bool fired = false;

            switch (enemy.spawnType) {
            case 0xbc: {
                duration = 50;
                homeTowardPlayer();
                const int local = nodeTimer - 5;
                if (local >= 0 && local < 45 && local % 18 == 0) {
                    const int baseCount =
                        std::array<int, 5>{{2, 3, 4, 5, 7}}[
                            static_cast<std::size_t>(difficulty)];
                    const int count = baseCount + local / 18;
                    const int step =
                        std::array<int, 5>{{0x1068, 0x0ce4, 3000, 0x0a8c, 0x0960}}[
                            static_cast<std::size_t>(difficulty)];
                    const double speed =
                        std::array<double, 5>{{4.5, 5.5, 6.0, 6.5, 7.5}}[
                            static_cast<std::size_t>(difficulty)] +
                        familySpeed;
                    spawnProjectileSpread(0x0c, 0, fireX, fireY,
                                          enemy.sourceAngle16, 0.0f, speed, 1,
                                          count, (count - 1) * step, 0);
                    fired = true;
                }
                break;
            }
            case 0xbd: {
                duration = 20;
                homeTowardPlayer();
                if (nodeTimer == 5) {
                    const int count =
                        std::array<int, 5>{{17, 25, 29, 25, 29}}[
                            static_cast<std::size_t>(difficulty)];
                    const double speed =
                        std::array<double, 5>{{5.0, 6.0, 6.5, 7.0, 8.0}}[
                            static_cast<std::size_t>(difficulty)] +
                        familySpeed;
                    spawnProjectileSpread(3, 0, fireX, fireY,
                                          enemy.sourceAngle16, 0.0f, speed, 1,
                                          count, 0x10000, 0);
                    if (difficulty > 2) {
                        spawnProjectileSpread(
                            3, 0, fireX, fireY,
                            boss08Angle(static_cast<int>(enemy.sourceAngle16) +
                                        0x10000 / (count * 2)),
                            0.0f, speed - 1.2, 1, count, 0x10000, 0);
                    }
                    fired = true;
                }
                break;
            }
            case 0xbe: {
                duration = 30;
                if (nodeTimer < 5) homeTowardPlayer();
                if (nodeTimer >= 5 && nodeTimer < 30 &&
                    (nodeTimer - 5) % 4 == 0) {
                    const double speed =
                        std::array<double, 5>{{7.4, 8.2, 9.0, 9.0, 10.0}}[
                            static_cast<std::size_t>(difficulty)] +
                        familySpeed;
                    spawnProjectileNode(7, 0, fireX, fireY,
                                        enemy.sourceAngle16, 0.0f, speed, 1, 0);
                    if (difficulty > 0) {
                        for (const int offset : {-350, 350}) {
                            spawnProjectileNode(
                                7, 0, fireX, fireY,
                                boss08Angle(static_cast<int>(enemy.sourceAngle16) +
                                            offset),
                                0.0f, speed - 0.4, 1, 0);
                        }
                    }
                    if (difficulty > 2) {
                        for (const int offset : {-700, 700}) {
                            spawnProjectileNode(
                                7, 0, fireX, fireY,
                                boss08Angle(static_cast<int>(enemy.sourceAngle16) +
                                            offset),
                                0.0f, speed - 0.8, 1, 0);
                        }
                    }
                    fired = true;
                }
                break;
            }
            case 0xbf: {
                duration = 20;
                homeTowardPlayer();
                if (nodeTimer == 5) {
                    const int count =
                        std::array<int, 5>{{5, 7, 9, 9, 11}}[
                            static_cast<std::size_t>(difficulty)];
                    const double speed =
                        std::array<double, 5>{{4.0, 5.0, 5.5, 6.0, 7.0}}[
                            static_cast<std::size_t>(difficulty)] +
                        familySpeed;
                    for (const int offset : {0, 8000, -8000}) {
                        spawnProjectileSpread(
                            5, 0, fireX, fireY,
                            boss08Angle(static_cast<int>(enemy.sourceAngle16) +
                                        offset),
                            0.0f, speed, 1, count, (count - 1) * 400, 0);
                    }
                    if (difficulty > 2) {
                        for (const int offset : {0, 8000, -8000}) {
                            spawnProjectileSpread(
                                5, 0, fireX, fireY,
                                boss08Angle(static_cast<int>(enemy.sourceAngle16) +
                                            offset),
                                0.0f, speed + 0.5, 1, count - 1,
                                (count - 2) * 400, 0);
                        }
                    }
                    fired = true;
                }
                break;
            }
            case 0xc0: {
                duration = 60;
                if (nodeTimer < 5) homeTowardPlayer();
                const int interval =
                    std::array<int, 5>{{8, 5, 4, 4, 4}}[
                        static_cast<std::size_t>(difficulty)];
                if (nodeTimer >= 5 && nodeTimer < 60 &&
                    (nodeTimer - 5) % interval == 0) {
                    const int spread = (nodeTimer - 5) * 700 +
                        std::array<int, 5>{{0x1068, 0x0e10, 0x0ce4, 3000, 3000}}[
                            static_cast<std::size_t>(difficulty)];
                    const double speed =
                        std::array<double, 5>{{5.5, 6.2, 6.6, 6.6, 7.5}}[
                            static_cast<std::size_t>(difficulty)] -
                        (nodeTimer - 5) * 0.05 + familySpeed;
                    spawnProjectileSpread(0x0b, 0, fireX, fireY,
                                          enemy.sourceAngle16, 0.0f, speed, 1,
                                          2, spread, 0);
                    if (difficulty > 2) {
                        spawnProjectileSpread(0x0b, 0, fireX, fireY,
                                              enemy.sourceAngle16, 0.0f,
                                              speed + 1.0, 1, 2,
                                              spread + interval * 400, 0);
                    }
                    fired = true;
                }
                break;
            }
            case 0xc1: {
                duration = 80;
                homeTowardPlayer();
                const int interval =
                    std::array<int, 5>{{20, 16, 14, 12, 10}}[
                        static_cast<std::size_t>(difficulty)];
                const int local = nodeTimer - 5;
                if (local >= 0 && local < 75 && local % interval == 0) {
                    const int volley = local / interval;
                    const int spreadStep =
                        std::array<int, 5>{{0x0ce4, 0x0a28, 0x08fc, 2000, 0x0708}}[
                            static_cast<std::size_t>(difficulty)];
                    const double speed =
                        std::array<double, 5>{{5.5, 6.5, 7.0, 7.5, 8.5}}[
                            static_cast<std::size_t>(difficulty)];
                    const auto quantized = boss08Angle(
                        ((static_cast<int>(enemy.sourceAngle16) + 0x400) >> 11) *
                        0x800);
                    spawnProjectileSpread(8, 0, fireX, fireY, quantized,
                                          0.0f, speed, 1, volley + 1,
                                          volley * spreadStep, 0);
                    fired = true;
                }
                break;
            }
            case 0xc2: {
                duration = 20;
                homeTowardPlayer();
                if (nodeTimer == 5) {
                    const int count =
                        std::array<int, 5>{{9, 13, 15, 17, 19}}[
                            static_cast<std::size_t>(difficulty)];
                    const double speed =
                        std::array<double, 5>{{7.0, 8.5, 10.0, 8.0, 9.0}}[
                            static_cast<std::size_t>(difficulty)];
                    const int spread = (count - 1) * 0x09f6;
                    spawnProjectileSpread(2, 9, fireX, fireY,
                                          enemy.sourceAngle16, 0.0f, speed, 1,
                                          count, spread, 0);
                    if (difficulty > 2) {
                        spawnProjectileSpread(
                            2, 9, fireX, fireY,
                            boss08Angle(static_cast<int>(enemy.sourceAngle16) +
                                        0x10000 / (count * 2)),
                            0.0f, speed + 4.0, 1, count, spread, 0);
                    }
                    fired = true;
                }
                break;
            }
            default:
                break;
            }

            if (fired) playPlayerSound(bullet1SoundHandle_, 0x13);
            if (nodeTimer == duration) {
                enemy.helperState = 2;
                enemy.helperTimer = 0;
            }
        }
        else if (enemy.helperState == 2 && nodeTimer >= 40) {
            enemy.active = false;
        }

        if (parent->helperState < 62 || parent->helperState > 67 ||
            parent->hp < 1 || lateStageBossCountdown_ < 1) {
            enemy.active = false;
        }
        break;
    }
    case 0xc3: {
        enemy.x = parent->x;
        enemy.y = parent->y;
        enemy.sourceAngle16 = boss08Angle(frame_ * 0x180);
        if (enemy.helperState == 0 && timer == 0) {
            const auto randomHundredth = [](int seed, double minimum,
                                            int steps) {
                return minimum +
                       static_cast<double>(boss08Rand(seed) %
                                           static_cast<std::uint32_t>(steps)) /
                           100.0;
            };
            const int particle = playerFrames_.size() > 14
                                     ? playerFrames_[14]
                                     : -1;
            for (int index = 0; index < 32; ++index) {
                const auto angle = boss08Angle(static_cast<int>(
                    boss08Rand(frame_ + index * 0x58) % 0x10001u));
                const double scale = randomHundredth(
                    frame_ + index * 0x22b8, 1.1, 111);
                const double speed = randomHundredth(
                    frame_ + index * 0x378, 16.0, 901);
                spawnStageEffect(0x2c, particle, 0, 0x48,
                                 enemy.x, enemy.y, angle,
                                 speed, scale, scale, 0,
                                 0xff, 0xff, 0xff, 0xc0);
            }
        }
        if (enemy.helperState == 0 &&
            (parent->helperState < 65 || parent->helperState > 67)) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        else if (enemy.helperState == 1 && timer >= 16) {
            enemy.active = false;
        }
        break;
    }
    default:
        enemy.active = false;
        break;
    }
    enemy.drawHp = enemy.hp;
}

void StageRuntime::emitStage08BossProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;

    if (enemy.helperState == 1) {
        const int cycle = (timer - 30) % 1800;
        const int interval = difficulty == 0 ? 120 : 80;
        const int fanCount = std::array<int, 5>{{5, 7, 9, 7, 9}}[
            static_cast<std::size_t>(difficulty)];
        const double fanBaseSpeed =
            std::array<double, 5>{{4.0, 4.5, 5.0, 4.5, 5.5}}[
                static_cast<std::size_t>(difficulty)];
        const float rightX = enemy.x + 110.0f;
        const float leftX = enemy.x - 110.0f;
        const float muzzleY = enemy.y - 76.0f;
        const auto rightAim = boss08AngleTo(rightX, muzzleY,
                                            player_.x, player_.y);
        const auto leftAim = boss08AngleTo(leftX, muzzleY,
                                           player_.x, player_.y);
        const auto fireFanPair = [&](int count, int spread, double speed) {
            spawnProjectileSpread(0x0c, 0, rightX, muzzleY, rightAim,
                                  0.0f, speed, 1, count, spread, 0);
            spawnProjectileSpread(0x0c, 0, leftX, muzzleY, leftAim,
                                  0.0f, speed, 1, count, spread, 0);
        };
        const auto fireOpeningWindow = [&](int start, int count,
                                           int spread) {
            if (cycle < start || cycle >= 640 ||
                (cycle - start) % interval != 0) {
                return;
            }
            const double speed = fanBaseSpeed + cycle * 0.005;
            fireFanPair(count, spread, speed);
            if (difficulty >= 3) {
                fireFanPair(count, spread, speed + 1.2);
            }
            playPlayerSound(bullet1SoundHandle_, 0x13);
        };

        fireOpeningWindow(30, fanCount, 16000);
        const int insetCount = fanCount - 1;
        const int insetSpread =
            (16000 / (fanCount - 1)) * (fanCount - 2);
        fireOpeningWindow(50, insetCount, insetSpread);

        const int aimedStart = difficulty < 2 ? 760 : 740;
        const int aimedInterval = difficulty < 2 ? 150 : 100;
        if (cycle >= aimedStart && cycle < 960) {
            const int phase = (cycle - aimedStart) % aimedInterval;
            if (phase == 0) {
                enemy.secondaryAngle16 = rightAim;
                enemy.targetAngle16 = leftAim;
            }
            if (phase < 30 && phase % 4 == 0) {
                const double speed =
                    std::array<double, 5>{{7.0, 8.0, 8.0, 9.0, 10.0}}[
                        static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(9, 0, rightX, muzzleY,
                                    enemy.secondaryAngle16, 10.0f,
                                    speed, 1, 0);
                spawnProjectileNode(9, 0, leftX, muzzleY,
                                    enemy.targetAngle16, 10.0f,
                                    speed, 1, 0);
                if (difficulty >= 1) {
                    const int spread =
                        std::array<int, 5>{{0, 1000, 1500, 2000, 2400}}[
                            static_cast<std::size_t>(difficulty)];
                    spawnProjectileSpread(9, 0, rightX, muzzleY,
                                          enemy.secondaryAngle16, 10.0f,
                                          speed - 0.7, 1, 2, spread, 0);
                    spawnProjectileSpread(9, 0, leftX, muzzleY,
                                          enemy.targetAngle16, 10.0f,
                                          speed - 0.7, 1, 2, spread, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }

        if (cycle >= 1000 && cycle < 1760) {
            const int phase = (cycle - 1000) % 32;
            const int activeFrames =
                std::array<int, 5>{{20, 25, 30, 30, 30}}[
                    static_cast<std::size_t>(difficulty)];
            if (phase < activeFrames && phase % 5 == 0) {
                const int count = std::array<int, 5>{{3, 4, 5, 5, 7}}[
                    static_cast<std::size_t>(difficulty)];
                const double baseSpeed =
                    std::array<double, 5>{{4.4, 5.0, 5.5, 6.0, 7.2}}[
                        static_cast<std::size_t>(difficulty)];
                const double speed = baseSpeed +
                                     (cycle - 1000) * 0.004 +
                                     phase * 0.08;
                const int angleCycle = (cycle - 810) % 760;
                const int angleProduct = angleCycle * 21;
                const int angleOffset = angleCycle < 380
                                            ? angleProduct - 4000
                                            : 11960 - angleProduct;
                const auto angleA = boss08Angle(0x4000 + angleOffset);
                const auto angleB = boss08Angle(0x4000 - angleOffset);
                const auto fireBurstPair = [&](double burstSpeed) {
                    spawnProjectileSpread(9, 0, enemy.x, 10.0f,
                                          angleA, 10.0f, burstSpeed, 1,
                                          count, 16000, 0);
                    spawnProjectileSpread(9, 0, enemy.x, 10.0f,
                                          angleB, 10.0f, burstSpeed, 1,
                                          count, 16000, 0);
                };
                fireBurstPair(speed);
                if (difficulty >= 3) {
                    fireBurstPair(speed + 0.8);
                }
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }
        return;
    }

    if (enemy.helperState == 2) {
        const auto index = static_cast<std::size_t>(difficulty);
        static constexpr std::array<int, 5> kIntervals{{160, 120, 120, 120, 120}};
        static constexpr std::array<int, 5> kNodeCounts{{13, 17, 19, 19, 21}};
        static constexpr std::array<int, 5> kRingCounts{{21, 33, 37, 33, 37}};
        static constexpr std::array<double, 5> kRingSpeeds{{2.5, 3.2, 4.0,
                                                            3.0, 4.0}};
        const int interval = kIntervals[index];
        const int doubleInterval = interval * 2;
        const int nodeCount = kNodeCounts[index];
        const float muzzleY = enemy.y - 76.0f;
        const float leftX = enemy.x - 110.0f;
        const float rightX = enemy.x + 110.0f;
        const auto centerAim = boss08AngleTo(
            enemy.x, enemy.y - 143.0f, player_.x, player_.y);

        const auto spawnNodeRing = [&](int type) {
            for (int i = 0; i < nodeCount; ++i) {
                const auto angle = boss08Angle(
                    static_cast<int>(centerAim) + i * (0x10000 / nodeCount));
                spawnStage08BossNode(enemy, type, i,
                                     enemy.x, enemy.y - 143.0f,
                                     angle, 0.0, 600, 45, false);
            }
            playPlayerSound(bullet2SoundHandle_, 0x19);
        };
        if (timer >= 0 && timer % doubleInterval == 0) {
            spawnNodeRing(0xae);
        }
        if (timer >= interval && (timer - interval) % doubleInterval == 0) {
            spawnNodeRing(0xaf);
        }

        const auto fireRing = [&](float x, std::uint16_t angle) {
            const int ringCount = kRingCounts[index];
            const double speed = kRingSpeeds[index];
            spawnProjectileSpread(2, 0, x, muzzleY, angle, 0.0f,
                                  speed, 1, ringCount, 0x10000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(
                    2, 0, x, muzzleY,
                    boss08Angle(static_cast<int>(angle) +
                                0x10000 / ringCount),
                    0.0f, speed + 2.0, 1, ringCount, 0x10000, 0);
            }
        };
        const bool fireLeft =
            (timer >= 70 && (timer - 70) % doubleInterval == 0) ||
            (timer >= interval + 90 &&
             (timer - (interval + 90)) % doubleInterval == 0);
        if (fireLeft) {
            fireRing(leftX, boss08AngleTo(leftX, muzzleY,
                                          player_.x, player_.y));
        }
        const bool fireRight =
            (timer >= 90 && (timer - 90) % doubleInterval == 0) ||
            (timer >= interval + 70 &&
             (timer - (interval + 70)) % doubleInterval == 0);
        if (fireRight) {
            fireRing(rightX, boss08AngleTo(rightX, muzzleY,
                                           player_.x, player_.y));
        }
        return;
    }

    if (enemy.helperState == 11) {
        if (timer < 60) return;

        const auto index = static_cast<std::size_t>(difficulty);
        const int cycle = (timer - 60) % 1600;
        const float centerY = enemy.y - 143.0f;
        const float sideY = enemy.y - 76.0f;
        const float rightX = enemy.x + 110.0f;
        const float leftX = enemy.x - 110.0f;
        const auto centerAim = boss08AngleTo(
            enemy.x, centerY, player_.x, player_.y);
        const auto rightAim = boss08AngleTo(
            rightX, sideY, player_.x, player_.y);
        const auto leftAim = boss08AngleTo(
            leftX, sideY, player_.x, player_.y);

        static constexpr std::array<int, 4> kFanStarts{{0, 60, 140, 240}};
        static constexpr std::array<int, 4> kFanLengths{{32, 52, 72, 80}};
        static constexpr std::array<int, 5> kFanCounts{{3, 3, 3, 5, 7}};
        static constexpr std::array<int, 5> kFanSpreads{{800, 1000, 1200,
                                                         2400, 2400}};
        static constexpr std::array<double, 5> kFanSpeeds{{6.0, 7.0, 7.5,
                                                           7.5, 8.8}};
        for (std::size_t wave = 0; wave < kFanStarts.size(); ++wave) {
            const int local = cycle - kFanStarts[wave];
            if (local < 0 || local >= kFanLengths[wave] || local % 4 != 0) {
                continue;
            }
            if (local == 0) enemy.secondaryAngle16 = centerAim;
            spawnProjectileSpread(
                0x0b, 0, enemy.x, centerY, enemy.secondaryAngle16, 10.0f,
                kFanSpeeds[index] + local * 0.15, 1,
                kFanCounts[index], kFanSpreads[index], 0);
            playPlayerSound(bullet1SoundHandle_, 0x13);
            enemy.secondaryAngle16 = boss08Approach(
                enemy.secondaryAngle16, centerAim, 200);
            break;
        }

        static constexpr std::array<int, 5> kRingPeriods{{14, 14, 12, 14, 14}};
        static constexpr std::array<int, 5> kRingActive{{4, 5, 5, 7, 7}};
        static constexpr std::array<int, 5> kRingCounts{{3, 5, 7, 7, 7}};
        static constexpr std::array<double, 5> kRingSpeeds{{3.5, 4.5, 5.0,
                                                            5.0, 6.4}};
        if (cycle >= 20 && cycle < 300 &&
            (cycle - 20) % kRingPeriods[index] < kRingActive[index]) {
            const int turn = static_cast<int>(
                std::sin(cycle * kBoss08Pi / 320.0) * 31000.0);
            const double speed = kRingSpeeds[index] + cycle * 0.008;
            const auto fireRingPair = [&](double pairSpeed) {
                spawnProjectileSpread(
                    8, 0, rightX, sideY, boss08Angle(0x4000 - turn),
                    10.0f, pairSpeed, 1, kRingCounts[index], 0x10000, 0);
                spawnProjectileSpread(
                    8, 0, leftX, sideY, boss08Angle(0x4000 + turn),
                    10.0f, pairSpeed, 1, kRingCounts[index], 0x10000, 0);
            };
            fireRingPair(speed);
            if (difficulty >= 3) fireRingPair(speed + 0.4);
            playPlayerSound(bullet1SoundHandle_, 0x13);
        }

        static constexpr std::array<int, 5> kLayerIntervals{{90, 60, 50,
                                                              60, 50}};
        static constexpr std::array<int, 5> kLayerCounts{{7, 9, 11, 11, 13}};
        static constexpr std::array<double, 5> kLayerSpeeds{{4.0, 5.0, 5.5,
                                                             5.5, 6.5}};
        if (cycle >= 380 && cycle < 640 &&
            (cycle - 380) % kLayerIntervals[index] == 0) {
            const int count = kLayerCounts[index];
            const double speed = kLayerSpeeds[index] +
                                 (cycle - 380) * 0.005;
            const auto fireLayer = [&](double layerSpeed, int layerCount,
                                       int spread) {
                spawnProjectileSpread(3, 0, enemy.x, centerY, centerAim,
                                      10.0f, layerSpeed, 1,
                                      layerCount, spread, 0);
            };
            fireLayer(speed, count, 0x8000);
            fireLayer(speed + 0.7, count, 0x8000);
            fireLayer(speed + 1.4, count, 0x8000);
            if (difficulty >= 3) {
                const int insetCount = count - 1;
                const int insetSpread =
                    (0x8000 / insetCount) * (count - 2);
                fireLayer(speed - 1.0, insetCount, insetSpread);
                fireLayer(speed - 0.6, insetCount, insetSpread);
            }
            playPlayerSound(bullet2SoundHandle_, 0x13);
        }

        static constexpr std::array<int, 5> kCrossUnits{{12, 8, 6, 5, 4}};
        static constexpr std::array<int, 5> kCrossSpreads{{6400, 5800, 5400,
                                                           5000, 4500}};
        static constexpr std::array<double, 5> kCrossSpeeds{{4.5, 5.5, 6.0,
                                                             6.0, 6.0}};
        if (cycle >= 700 && cycle < 960) {
            const int local = cycle - 700;
            const int unit = kCrossUnits[index];
            const int ring = local / (unit * 2);
            const int count = ring + 1;
            const int spreadStep = kCrossSpreads[index] - local * 10;
            const int spread = ring * spreadStep;
            const double speed = kCrossSpeeds[index] + local * 0.03;
            if (local % (unit * 2) == 0) {
                spawnProjectileSpread(0x0d, 0, rightX, sideY, rightAim,
                                      10.0f, speed, 1, count, spread, 0);
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
            if (local >= unit && (local - unit) % (unit * 2) == 0) {
                spawnProjectileSpread(0x0c, 0, leftX, sideY, leftAim,
                                      10.0f, speed, 1, count, spread, 0);
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }

        if (cycle == 960) {
            static constexpr std::array<int, 5> kOuterCounts{{5, 5, 7, 7, 7}};
            static constexpr std::array<int, 5> kInnerCounts{{2, 3, 4, 4, 5}};
            static constexpr std::array<double, 5> kBurstSpeeds{{5.0, 6.6, 7.2,
                                                                 7.7, 8.8}};
            const int outerCount = kOuterCounts[index];
            const int baseCount = difficulty == 0 ? 5 : 7;
            for (int outer = 0; outer < outerCount; ++outer) {
                const int angleOffset =
                    (outer * 2 - outerCount + 1) * 180;
                const auto rightAngle = boss08Angle(rightAim + angleOffset);
                const auto leftAngle = boss08Angle(leftAim + angleOffset);
                for (int inner = 0; inner < kInnerCounts[index]; ++inner) {
                    const int count = baseCount - inner;
                    const int spread =
                        (0x8000 / (count - 1)) * (count - 2);
                    const double innerValue = static_cast<double>(inner);
                    const double speed = kBurstSpeeds[index] -
                        innerValue * (1.8 - innerValue * 0.2);
                    const auto fireBurstPair = [&](double pairSpeed) {
                        spawnProjectileSpread(4, 0, rightX, sideY,
                                              rightAngle, 10.0f, pairSpeed,
                                              1, count, spread, 0);
                        spawnProjectileSpread(4, 0, leftX, sideY,
                                              leftAngle, 10.0f, pairSpeed,
                                              1, count, spread, 0);
                    };
                    fireBurstPair(speed);
                    if (difficulty >= 3) fireBurstPair(speed + 0.3);
                }
            }
            playPlayerSound(bullet2SoundHandle_, 0x13);
        }

        static constexpr std::array<int, 5> kFinalHalfPeriods{{6, 4, 4, 4, 3}};
        static constexpr std::array<int, 5> kFinalCounts{{5, 7, 9, 11, 12}};
        static constexpr std::array<double, 5> kFinalSpeeds{{4.0, 5.5, 6.0,
                                                             7.0, 7.8}};
        if (cycle >= 1060 && cycle < 1550 &&
            (cycle - 1060) % (kFinalHalfPeriods[index] * 2) == 0) {
            const int spread = 17000 + static_cast<int>(
                std::sin((cycle - 1050) * kBoss08Pi / 100.0) * 5000.0);
            const double speed = kFinalSpeeds[index] +
                                 (cycle - 1060) * 0.007;
            const auto angle = boss08Angle(cycle * 360);
            spawnProjectileSpread(4, 0, enemy.x, centerY, angle,
                                  10.0f, speed, 1,
                                  kFinalCounts[index], spread, 0);
            spawnProjectileSpread(4, 0, enemy.x, centerY,
                                  boss08Angle(angle + 0x8000),
                                  10.0f, speed, 1,
                                  kFinalCounts[index], spread, 0);
            playPlayerSound(bullet2SoundHandle_, 0x13);
        }
        return;
    }

    if (enemy.helperState == 21) {
        const auto index = static_cast<std::size_t>(difficulty);
        const int cycle = timer >= 60 ? (timer - 60) % 1400 : -1;
        const int muzzleWave = static_cast<int>(
            std::sin(frame_ * kBoss08Pi / 60.0) * 2000.0);
        const double angleARadians = boss08Radians(
            boss08Angle(muzzleWave - 7600));
        const double angleBRadians = boss08Radians(
            boss08Angle(0x9db0 - muzzleWave));
        const float muzzleAX = enemy.x + 10.0f +
            static_cast<float>(std::cos(angleARadians) * 70.0);
        const float muzzleAY = enemy.y - 15.0f +
            static_cast<float>(std::sin(angleARadians) * 70.0);
        const float muzzleBX = enemy.x - 10.0f +
            static_cast<float>(std::cos(angleBRadians) * 70.0);
        const float muzzleBY = enemy.y - 15.0f +
            static_cast<float>(std::sin(angleBRadians) * 70.0);
        const auto aimA = boss08AngleTo(
            muzzleAX, muzzleAY, player_.x, player_.y);
        const auto aimB = boss08AngleTo(
            muzzleBX, muzzleBY, player_.x, player_.y);

        if (cycle == 0 || cycle == 180 || cycle == 360 || cycle == 540) {
            static constexpr std::array<int, 4> kTypes{{0xb2, 0xb1, 0xb0, 0xb3}};
            static constexpr std::array<int, 5> kNodeCounts{{7, 7, 9, 9, 9}};
            static constexpr std::array<int, 5> kSlowTurns{{150, 180, 222,
                                                            222, 222}};
            static constexpr std::array<int, 5> kFastTurns{{330, 300, 300,
                                                            280, 280}};
            const int type = kTypes[static_cast<std::size_t>(cycle / 180)];
            const int count = kNodeCounts[index];
            const int turn = type < 0xb2 ? kSlowTurns[index]
                                         : kFastTurns[index];
            for (int i = 0; i < count; ++i) {
                spawnStage08BossNode(
                    enemy, type, i, 0.0f, 0.0f,
                    boss08Angle(i * (0x10000 / count)),
                    static_cast<double>(turn), 1600, 45, false);
            }
            playPlayerSound(bossSe1SoundHandle_, 0x19);
        }

        static constexpr std::array<int, 5> kAimActive{{80, 100, 100,
                                                        120, 120}};
        static constexpr std::array<int, 5> kAimCounts{{3, 5, 7, 7, 9}};
        static constexpr std::array<double, 5> kAimSpeeds{{5.0, 6.5, 7.0,
                                                           7.0, 8.0}};
        if (cycle >= 100 && cycle < 800) {
            const int local = (cycle - 100) % 180;
            const int segment = (cycle - 100) / 180;
            if (local == 0) {
                enemy.secondaryAngle16 = aimA;
                enemy.targetAngle16 = aimB;
            }
            if (local < kAimActive[index] && local % 4 == 0) {
                const int count = kAimCounts[index];
                const int spread = cycle < 640
                    ? (6 - segment) * 5000
                    : (count - 1) * 640;
                const double speed = kAimSpeeds[index] + local * 0.15;
                spawnProjectileSpread(
                    2, 0, muzzleAX, muzzleAY, enemy.secondaryAngle16,
                    0.0f, speed, 1, count, spread, 0);
                spawnProjectileSpread(
                    2, 0, muzzleBX, muzzleBY, enemy.targetAngle16,
                    0.0f, speed, 1, count, spread, 0);
                enemy.secondaryAngle16 = boss08Approach(
                    enemy.secondaryAngle16, aimA, 0x78);
                enemy.targetAngle16 = boss08Approach(
                    enemy.targetAngle16, aimB, 0x78);
                playPlayerSound(bullet2SoundHandle_, 0x13);
            }
        }

        static constexpr std::array<int, 5> kNeedleIntervals{{5, 4, 4, 4, 3}};
        static constexpr std::array<int, 5> kNeedleCounts{{3, 4, 5, 7, 7}};
        static constexpr std::array<double, 5> kNeedleSpeeds{{5.0, 5.0, 4.5,
                                                              4.0, 4.0}};
        if (cycle >= 820 && cycle < 860) {
            const int local = cycle - 820;
            if (local == 0) enemy.secondaryAngle16 = aimA;
            if (local % kNeedleIntervals[index] == 0) {
                for (int i = 0; i < kNeedleCounts[index]; ++i) {
                    const auto angle = boss08Angle(
                        enemy.secondaryAngle16 + cycle * 704 + 11724 -
                        i * 333);
                    spawnProjectileNode(5, 0x28, muzzleAX, muzzleAY,
                                        angle, 0.0f,
                                        kNeedleSpeeds[index] + i, 1, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }
        if (cycle >= 970 && cycle < 1010) {
            const int local = cycle - 970;
            if (local == 0) enemy.secondaryAngle16 = aimB;
            if (local % kNeedleIntervals[index] == 0) {
                for (int i = 0; i < kNeedleCounts[index]; ++i) {
                    const auto angle = boss08Angle(
                        enemy.secondaryAngle16 - cycle * 705 + 38490 +
                        i * 333);
                    spawnProjectileNode(5, 0x28, muzzleBX, muzzleBY,
                                        angle, 0.0f,
                                        kNeedleSpeeds[index] + i, 1, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }

        if (cycle >= 1100) {
            const int local = cycle - 1100;
            if (local == 0) {
                enemy.secondaryAngle16 = aimA;
                enemy.targetAngle16 = aimB;
            }

            static constexpr std::array<int, 5> kConvergeSpreads{{3200, 2500,
                                                                  2000, 1500,
                                                                  1500}};
            if (local % 3 == 0) {
                const double converge = std::sin(local * kBoss08Pi / 600.0);
                const int spreadStep = 20000 + static_cast<int>(
                    converge * (kConvergeSpreads[index] - 20000));
                const double speed = cycle < 1200
                    ? 8.0 + std::sin(local * kBoss08Pi / 200.0) * 7.0
                    : 15.0;
                for (int layer = 1; layer <= 3; ++layer) {
                    const int spread = layer * spreadStep;
                    spawnProjectileSpread(
                        7, 0, muzzleAX, muzzleAY, enemy.secondaryAngle16,
                        10.0f, speed, 1, 2, spread, 0);
                    spawnProjectileSpread(
                        7, 0, muzzleBX, muzzleBY, enemy.targetAngle16,
                        10.0f, speed, 1, 2, spread, 0);
                }
                const int step = cycle < 1200
                    ? 200 - static_cast<int>(
                        std::sin(local * kBoss08Pi / 200.0) * 190.0)
                    : 10;
                enemy.secondaryAngle16 = boss08Approach(
                    enemy.secondaryAngle16, aimA, step);
                enemy.targetAngle16 = boss08Approach(
                    enemy.targetAngle16, aimB, step);
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }

            static constexpr std::array<int, 5> kClosingCounts{{3, 5, 7,
                                                                9, 11}};
            static constexpr std::array<double, 5> kClosingSpeeds{{5.0, 6.0,
                                                                   7.0, 8.0,
                                                                   9.0}};
            const int groupCount = difficulty == 0 ? 2 : 3;
            const int groupGap = difficulty == 0 ? 70 : 50;
            int start = 1160;
            int accumulatedGap = 0;
            for (int group = 0; group < groupCount; ++group) {
                const int count = kClosingCounts[index];
                const double speed = kClosingSpeeds[index];
                const int end = start + 12 + accumulatedGap;
                if (cycle >= start && cycle < end &&
                    (cycle - start) % 12 == 0) {
                    spawnProjectileSpread(
                        0x0c, 0, muzzleAX, muzzleAY, aimA,
                        10.0f, speed, 1,
                        count, 24000, 0);
                    spawnProjectileSpread(
                        0x0c, 0, muzzleBX, muzzleBY, aimB,
                        10.0f, speed, 1,
                        count, 24000, 0);
                    playPlayerSound(bullet2SoundHandle_, 0x13);
                }
                if (cycle >= start + 6 && cycle < end &&
                    (cycle - (start + 6)) % 12 == 0) {
                    const int insetCount = count - 1;
                    const int insetSpread =
                        (24000 / insetCount) * (count - 2);
                    spawnProjectileSpread(
                        0x0c, 0, muzzleAX, muzzleAY, aimA,
                        10.0f, speed, 1,
                        insetCount, insetSpread, 0);
                    spawnProjectileSpread(
                        0x0c, 0, muzzleBX, muzzleBY, aimB,
                        10.0f, speed, 1,
                        insetCount, insetSpread, 0);
                    playPlayerSound(bullet2SoundHandle_, 0x13);
                }
                start += accumulatedGap + groupGap;
                accumulatedGap += 12;
            }
        }
        return;
    }

    if (enemy.helperState == 31) {
        if (timer == 10) {
            spawnStage08BossNode(enemy, 0xb4, 0, 0.0f, 0.0f,
                                 0xe000, 444.0, 99999999, 45, true);
            playPlayerSound(bullet2SoundHandle_, 0x19);
        }
        if (timer == 100) {
            spawnStage08BossNode(enemy, 0xb5, 1, 0.0f, 0.0f,
                                 0xa000, 555.0, 99999999, 45, true);
            playPlayerSound(bullet2SoundHandle_, 0x19);
        }
        return;
    }

    if (enemy.helperState == 41) {
        const int cycle = timer % 1600;
        if (cycle < 1050) {
            const int local = cycle % 350;
            const auto spawnPair = [&](int hitPoints, double speed) {
                spawnStage08BossNode(
                    enemy, 0xb6, cycle * 2, enemy.x, enemy.y,
                    boss08Angle(local * 0x226 - 0xc90), speed,
                    hitPoints, 45, false);
                spawnStage08BossNode(
                    enemy, 0xb6, cycle * 2 + 1, enemy.x, enemy.y,
                    boss08Angle(0x8c90 - local * 0x226), speed,
                    hitPoints, 45, false);
            };
            if (local >= 40 && local < 80 &&
                (local - 40) % 8 == 0) {
                spawnPair(2000, 8.0);
                playPlayerSound(bullet2SoundHandle_, 0x19);
            }
            if (cycle >= 390 && cycle < 430 &&
                (cycle - 390) % 6 == 0) {
                spawnPair(1500, 12.0);
                playPlayerSound(bullet2SoundHandle_, 0x19);
            }
            if (cycle > 699) {
                const int ringStep = local - 40;
                if (ringStep >= 0 && ringStep < 60 && ringStep % 40 == 0) {
                    const int ringIndex = ringStep / 40;
                    const int count = 11 - ringIndex * 4;
                    const double speed = 12.0 - ringIndex * 5.0;
                    const std::uint32_t random = boss08Rand(timer);
                    const auto base = boss08Angle(static_cast<int>(
                        random - random / 0x10001u));
                    for (int i = 0; i < count; ++i) {
                        spawnStage08BossNode(
                            enemy, 0xb6, cycle * 16 + i,
                            enemy.x, enemy.y,
                            boss08Angle(static_cast<int>(base) +
                                        i * (0x10000 / count)),
                            speed, 1000, 45, false);
                    }
                    playPlayerSound(bullet2SoundHandle_, 0x19);
                }
            }
        }
        else {
            const int interval =
                std::array<int, 5>{{9, 6, 5, 5, 5}}[
                    static_cast<std::size_t>(difficulty)];
            if (cycle >= 1140 && cycle < 1500 &&
                (cycle - 1140) % interval == 0) {
                const auto angle = boss08Angle(
                    static_cast<int>(boss08Rand(timer) % 0x3201u) - 0x5900);
                spawnStage08BossNode(enemy, 0xb7, cycle,
                                     enemy.x, enemy.y, angle,
                                     9.0, 500, 40, false);
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
        }
        return;
    }

    if (enemy.helperState == 51 || enemy.helperState == 52) {
        if (enemy.helperState == 51 && timer == 60) {
            spawnStage08BossNode(enemy, 0xb8, 0, 0.0f, 0.0f,
                                 0, 0.0, 99999999, 110, true);
        }
        if (enemy.helperState == 51 && timer >= 90 && timer <= 100) {
            enemy.y -= static_cast<float>(12.0 - (timer - 90) * 1.2);
        }
        if (enemy.helperState == 51 && timer >= 110 && timer <= 120) {
            enemy.y += static_cast<float>(12.0 - (timer - 110) * 1.2);
        }
        if (enemy.helperState == 51 && timer == 140) {
            playPlayerSound(bullet2SoundHandle_, 0x19);
        }
        return;
    }

    if (enemy.helperState >= 62 && enemy.helperState <= 67) {
        const int family = (enemy.helperState - 62) % 3;
        const int interval = family == 0
                                 ? std::array<int, 5>{{50, 36, 32, 32, 28}}[
                                       static_cast<std::size_t>(difficulty)]
                                 : (family == 1
                                        ? std::array<int, 5>{{40, 28, 25, 25, 21}}[
                                              static_cast<std::size_t>(difficulty)]
                                        : std::array<int, 5>{{30, 20, 18, 18, 16}}[
                                              static_cast<std::size_t>(difficulty)]);
        if (timer > 100 && (timer - 100) % interval == 0) {
            const int variants = 2 + family * 2;
            const std::uint32_t random = boss08Rand(timer);
            const int variant = static_cast<int>(
                random % static_cast<std::uint32_t>(variants + 1));
            const int type = 0xbc + std::min(6, variant);
            const auto angle = boss08Angle(
                static_cast<int>(random % 30001u) - 31384);
            const double speed = 3.0 +
                                 static_cast<double>(random % 401u) / 100.0;
            spawnStage08BossNode(enemy, type, timer / interval,
                                 enemy.x, enemy.y, angle,
                                 speed, 99999999, 40, false);
            playPlayerSound(bullet2SoundHandle_, 0x19);
        }
    }
}

void StageRuntime::updateStage08Boss(StageEnemy& enemy) {
    const int timer = enemy.helperTimer;
    int state = enemy.helperState;

    const auto openPhase = [this, &enemy](int nextState, int hp,
                                          int countdown, int phaseIndex) {
        enemy.helperState = nextState;
        enemy.helperTimer = 0;
        enemy.hp = hp;
        enemy.maxHp = hp;
        enemy.drawHp = hp;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        lateStageBossMaxHp_ = hp;
        lateStageBossCountdown_ = countdown;
        lateStageBossCountdownDraw_ = countdown;
        lateStageBossPhaseIndex_ = phaseIndex;
        lateStageBossPhaseMode_ = 1;
    };

    const auto beginBreak = [this, &enemy](int nextState) {
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
        enemy.helperState = nextState;
        enemy.helperTimer = 0;
        enemy.liveChildCount = 0;
        lateStageBossPhaseMode_ = 2;
        ++lateStageBossPhaseIndex_;
    };
    const auto startBoss3 = [this]() {
        if (activeBossBgmIndex_ == 2) return;
        if (bossBgmHandles_[1] != -1) StopSoundMem(bossBgmHandles_[1]);
        activeBossBgmIndex_ = 2;
        if (bossBgmHandles_[2] != -1) {
            ChangeVolumeSoundMem(static_cast<int>(config_.bgmVolume * 25.5),
                                 bossBgmHandles_[2]);
            PlaySoundMem(bossBgmHandles_[2], DX_PLAYTYPE_LOOP, TRUE);
        }
    };

    // DAT_140e44600 is the active bomb/fever timer and DAT_140e44654 is the
    // accompanying screen-clear/invulnerability countdown.  States 65..67 are
    // the original invulnerable counterparts of 62..64.
    if (state >= 62 && state <= 64) {
        const bool specialActive = player_.bombLock > 0 ||
                                   player_.bombLock < -100;
        if (specialActive) {
            spawnStage08BossNode(enemy, 0xc3, 0, 0.0f, 0.0f,
                                 0, 0.0, 99999999, 20, true);
            enemy.helperState += 3;
            state = enemy.helperState;
            enemy.targetable = false;
        }
    }
    else if (state >= 65 && state <= 67) {
        if (player_.invulnerableFrames < 61) {
            enemy.helperState -= 3;
            state = enemy.helperState;
            enemy.targetable = true;
        }
        else {
            enemy.targetable = false;
        }
    }

    if (boss08CombatState(state) && lateStageBossPhaseMode_ == 1 &&
        (enemy.hp < 1 || lateStageBossCountdown_ < 1)) {
        int nextState = 70;
        if (state >= 62) {
            lateStageBossBreaksRemaining_ = 0;
            lateStageBossPhaseMode_ = -1;
            lateStageClearStarted_ = true;
            lateStageClearTimer_ = 0;
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 360);
        }
        else {
            switch (lateStageBossBreaksRemaining_) {
            case 6: nextState = 10; break;
            case 5: nextState = 20; break;
            case 4: nextState = 30; break;
            case 3: nextState = 40; break;
            case 2: nextState = 50; break;
            case 1: nextState = 60; break;
            default: nextState = 70; break;
            }
            lateStageBossBreaksRemaining_ =
                std::max(0, lateStageBossBreaksRemaining_ - 1);
        }
        beginBreak(nextState);
        if (nextState == 60 || nextState == 70) {
            lateStageBossPhaseMode_ = -1;
        }
        return;
    }

    if (boss08CombatState(state)) {
        if (frame_ % 50 == 0) {
            lateStageBossTargetX_ = 210.0f + static_cast<float>(
                boss08Rand(frame_) % 301u);
            float targetYBase = 150.0f;
            if (state == 11) targetYBase = 180.0f;
            else if (state >= 51 && state <= 59) targetYBase = 130.0f;
            else if (state >= 61 && state <= 69) targetYBase = 200.0f;
            lateStageBossTargetY_ = targetYBase + static_cast<float>(
                boss08Rand(frame_ + selectedStage_ * 0xde) % 101u);
        }
        const auto target = boss08AngleTo(enemy.x, enemy.y,
                                          lateStageBossTargetX_,
                                          lateStageBossTargetY_);
        enemy.sourceAngle16 = boss08Approach(enemy.sourceAngle16, target, 0x200);
        const double radians = boss08Radians(enemy.sourceAngle16);
        const double speed = state >= 62 ? 0.35 : 0.3;
        enemy.x += static_cast<float>(std::cos(radians) * speed);
        enemy.y += static_cast<float>(std::sin(radians) * speed);

        emitStage08BossProjectiles(enemy);

        if (state == 1 && enemy.hp <= 50000) {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
            spawnEnemyDeathEffects(enemy, 2);
            enemy.helperState = 2;
        }
        else if (state == 51 && timer >= 210) {
            enemy.helperState = 52;
            enemy.helperTimer = 0;
        }
        else if (state >= 62 && state <= 64) {
            int phaseState = state;
            if (phaseState == 62 &&
                enemy.hp < lateStageBossMaxHp_ * 2 / 3) {
                enemy.helperState = 63;
                phaseState = 63;
                spawnEnemyDeathEffects(enemy, 2);
                spawnPlayerSideObject(0x19, enemy.x, enemy.y,
                                      0.0, 0, 0, 0.0f);
            }
            if (phaseState == 63 &&
                enemy.hp < lateStageBossMaxHp_ / 3) {
                enemy.helperState = 64;
                phaseState = 64;
                spawnEnemyDeathEffects(enemy, 2);
                spawnPlayerSideObject(0x19, enemy.x, enemy.y,
                                      0.0, 0, 0, 0.0f);
            }
            if ((phaseState == 62 || phaseState == 63) &&
                lateStageBossCountdown_ < 1500) {
                enemy.helperState = 64;
                spawnEnemyDeathEffects(enemy, 2);
                flushEnemyProjectilesToEffects();
                player_.invulnerableFrames =
                    std::max(player_.invulnerableFrames, 100);
            }
        }

        enemy.drawHp = enemy.hp;
        lateStageBossCountdownDraw_ = lateStageBossCountdown_;
        updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
        if (lateStageBossCountdown_ > 0) --lateStageBossCountdown_;
        return;
    }

    enemy.targetable = false;
    switch (state) {
    case 0: {
        if (timer == 0) {
            playPlayerSound(bossSe9SoundHandle_, 0x19);
            spawnStage08BossNode(enemy, 0xa8, 0, 70.0f, -60.0f,
                                 0xc000, 0.0, 99999999, 40, true);
            spawnStage08BossNode(enemy, 0xa8, 1, -70.0f, -60.0f,
                                 0xc000, 0.0, 99999999, 40, true);
            spawnStage08BossNode(enemy, 0xa7, 0, 90.0f, -50.0f,
                                 0xc000, 0.0, 99999999, 40, true);
            spawnStage08BossNode(enemy, 0xa7, 1, -90.0f, -50.0f,
                                 0xc000, 0.0, 99999999, 40, true);
            static constexpr std::array<float, 4> kNodeX{{
                210.0f, -210.0f, 88.0f, -88.0f}};
            static constexpr std::array<float, 4> kNodeY{{
                146.0f, 146.0f, 72.0f, 72.0f}};
            for (int i = 0; i < 4; ++i) {
                spawnStage08BossNode(
                    enemy, 0xab, i,
                    kNodeX[static_cast<std::size_t>(i)],
                    kNodeY[static_cast<std::size_t>(i)],
                    0xc000, 0.0, 4000, 50, true);
            }
            spawnStage08BossNode(enemy, 0xac, 0, 205.0f, -90.0f,
                                 0xc000, 0.0, 25000, 40, true);
            spawnStage08BossNode(enemy, 0xac, 1, -205.0f, -90.0f,
                                 0xc000, 0.0, 25000, 40, true);
        }
        const double t = boss08Smooth(static_cast<double>(timer) / 1200.0);
        enemy.x = enemy.originX;
        enemy.y = enemy.originY - static_cast<float>((1.0 - t) * 1000.0);
        const bool firstRain = timer >= 30 && timer < 360 &&
                               (timer - 30) % 12 == 0;
        const bool secondRain = timer >= 460 && timer < 660 &&
                                (timer - 460) % 24 == 0;
        const bool finalRain = timer >= 720 && timer < 900 &&
                               (timer - 720) % 8 == 0;
        if (firstRain || secondRain || finalRain) {
            const float x = 60.0f + static_cast<float>(
                boss08Rand(timer) % 601u);
            spawnStage08BossNode(enemy, 0xad, timer, x, -10.0f,
                                 0x4000, 1.0, 300, 40, false);
        }
        if (timer >= 1200) {
            enemy.x = enemy.originX;
            enemy.y = enemy.originY;
            lateStageBossBreaksRemaining_ = 6;
            openPhase(1, 145000, 3300, 0);
        }
        break;
    }
    case 10:
        if (timer < 120 && timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
        if (timer >= 200) {
            // FUN_140038190 starts DAT_140e45144 at the 10 -> 11 handoff.
            startBoss3();
            openPhase(11, 105000, 2700, 1);
        }
        break;
    case 20:
        if (timer < 130 && timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
        enemy.x += static_cast<float>(timer) * 0.0015f;
        if (timer >= 380) openPhase(21, 80000, 2400, 2);
        break;
    case 30:
        if (timer < 120 && timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
        if (timer >= 200) openPhase(31, 40000, 1500, 3);
        break;
    case 40:
        if (timer == 1) playPlayerSound(blast1SoundHandle_, 0x19);
        if (timer < 90 && timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
        enemy.y += 0.08f;
        if (timer >= 180) openPhase(41, 80000, 2400, 4);
        break;
    case 50:
        if (timer == 1) playPlayerSound(blast1SoundHandle_, 0x19);
        if (timer < 90 && timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
        enemy.y += 0.08f;
        if (timer >= 180) openPhase(51, 148000, 3300, 5);
        break;
    case 60:
        if (timer < 180 && timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
        if (timer == 180) playPlayerSound(bossSe9SoundHandle_, 0x19);
        if (timer >= 300) {
            enemy.x = 360.0f;
            enemy.y = 200.0f;
            enemy.helperState = 61;
            enemy.helperTimer = 0;
            enemy.hp = 150000;
            enemy.maxHp = 150000;
            enemy.drawHp = 150000;
            lateStageBossMaxHp_ = 150000;
            lateStageBossCountdown_ = 4800;
            lateStageBossCountdownDraw_ = 4800;
            lateStageBossBreaksRemaining_ = 1;
            lateStageBossPhaseMode_ = 0;
        }
        break;
    case 61:
        if (timer == 90) playPlayerSound(bullet2SoundHandle_, 0x19);
        if (timer >= 120) {
            enemy.helperState = 62;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
            lateStageBossPhaseMode_ = 1;
            lateStageBossPhaseIndex_ = 6;
        }
        break;
    case 70:
    case 99:
        if (timer < 240 && timer % 3 == 0) spawnStage02DeathExplosionChain(enemy);
        enemy.y += 0.15f;
        if (timer == 240) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnEnemyDeathEffects(enemy, 2);
        }
        if (timer >= 480) {
            clearLateStageGate(8);
            enemy.active = false;
        }
        break;
    default:
        break;
    }

    enemy.drawHp = enemy.hp;
    lateStageBossCountdownDraw_ = lateStageBossCountdown_;
}

bool StageRuntime::drawStage08Boss(const StageEnemy& enemy, float x,
                                   float y, int exactLayer) const {
    if (enemy.spawnType != 0x13f) return false;
    if (!enemy.drawBodyThisFrame) return true;

    const auto handleAt = [](const std::vector<int>& frames, int index) {
        return index >= 0 && index < static_cast<int>(frames.size())
                   ? frames[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto draw = [this, &handleAt](const std::vector<int>& frames,
                                        int index, float drawX, float drawY,
                                        std::uint16_t angle = 0,
                                        double scaleX = 1.0,
                                        double scaleY = 1.0,
                                        bool reverse = false) {
        const int handle = handleAt(frames, index);
        if (handle == -1) return false;
        drawOriginalMode7Node(handle, drawX, drawY, angle,
                              scaleX, scaleY, reverse);
        return true;
    };

    const int state = enemy.drawHelperState;
    const int timer = enemy.drawHelperTimer;
    const int sourceFrame = std::max(0, frame_ - 1);
    bool drew = false;

    // FUN_140038190 keeps the opening machine on screen through state 19 and
    // hands it to the core at tick 130 of state 20.
    if (state < 20 || (state == 20 && timer < 130)) {
        const float fixedX = x + (360.0f - enemy.x);
        const bool settled = state > 10 ||
                             (state == 10 && timer > 120);
        const float shellY = y + (settled ? 12.0f : 8.0f) +
            (settled ? 0.0f : static_cast<float>(
                std::sin((sourceFrame - 60) * kBoss08Tau / 180.0) * 3.0));

        if (exactLayer == 0x14) {
            drew |= draw(stageBack2Frames_, 6, fixedX, y + 240.0f);
        }
        if (exactLayer == 0x1e) {
            drew |= draw(enemyLargeFrames_, 56, fixedX, shellY);
            drew |= draw(enemyLargeFrames_, 54, x, y);
            if (state == 1 && timer >= 0 && timer < 24) {
                SetDrawBlendMode(DX_BLENDMODE_ADD,
                                 std::clamp(32 + timer * 7, 0, 160));
                drew |= draw(enemyLargeFrames_, 54, x, y);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
            drew |= draw(enemyLargeFrames_, 55, fixedX, shellY);
        }
    }

    const bool coreVisible = (state >= 21 && state <= 29) ||
                             (state == 20 && timer >= 130) ||
                             (state == 30 && timer < 130);
    if (coreVisible && exactLayer == 0x1d) {
        const int swing = static_cast<int>(
            std::sin(sourceFrame * kBoss08Tau / 120.0) * 2000.0);
        const double pulse = 1.0 +
            std::sin(sourceFrame * kBoss08Tau / 5.0) * 0.1;
        const int flare = handleAt(effectSmallFrames_, 14);
        if (flare != -1) {
            SetDrawBlendMode(DX_BLENDMODE_ADD, 225);
            drawOriginalMode7Node(flare, x + 20.0f, y + 35.0f,
                                  0, 1.0, pulse, false);
            drawOriginalMode7Node(flare, x - 20.0f, y + 35.0f,
                                  0, 1.0, pulse, true);
            drawOriginalMode7Node(flare, x + 24.0f, y + 48.0f,
                                  0, 1.0, pulse, false);
            drawOriginalMode7Node(flare, x - 24.0f, y + 48.0f,
                                  0, 1.0, pulse, true);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            drew = true;
        }
        drew |= draw(bossFrames_, 59, x + 10.0f, y - 15.0f,
                     boss08Angle(swing));
        drew |= draw(bossFrames_, 59, x - 10.0f, y - 15.0f,
                     boss08Angle(-swing), 1.0, 1.0, true);
        drew |= draw(bossFrames_, 58, x, y);
    }

    // State 99 explicitly selects Boss[108..109] and queues an opaque and an
    // additive copy until tick 299.
    if (state == 99 && timer < 300 && exactLayer == 0x1e) {
        const int frame = 108 + (timer / 5) % 2;
        drew |= draw(bossFrames_, frame, x, y);
        SetDrawBlendMode(DX_BLENDMODE_ADD, 96);
        drew |= draw(bossFrames_, frame, x, y);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    if (exactLayer == 0x1e && !drew && !coreVisible &&
        !((state >= 30 && state < 99) ||
          (state == 99 && timer >= 300))) {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(24, enemy.radius / 2),
                   GetColor(255, 96, 160), TRUE);
    }
    return true;
}

bool StageRuntime::drawStage08BossNode(const StageEnemy& enemy, float x,
                                       float y, int exactLayer) const {
    if (!isStage08BossNodeType(enemy.spawnType) ||
        enemy.parentSpawnType != 0x13f) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) return true;

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4
                               ? effectMediumFrames_[4]
                               : -1;
        if (marker != -1) {
            const double scale = std::max(
                0.0, 3.0 - enemy.markerDrawTimer * 0.15);
            DrawRotaGraphF(x + enemy.markerDrawX - enemy.x,
                           y + enemy.markerDrawY - enemy.y,
                           scale, 0.0, marker, TRUE);
        }
    }

    const auto mediumFrame = [this](int index) {
        return index >= 0 && index < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto smallFrame = [this](int index) {
        return index >= 0 && index < static_cast<int>(enemySmallFrames_.size())
                   ? enemySmallFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto largeFrame = [this](int index) {
        return index >= 0 && index < static_cast<int>(enemyLargeFrames_.size())
                   ? enemyLargeFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawNode = [this](int handle, float drawX, float drawY,
                                 std::uint16_t angle, double scaleX,
                                 double scaleY, bool reverse, int blendMode,
                                 int alpha, int red = 0xff, int green = 0xff,
                                 int blue = 0xff) {
        if (handle == -1 || alpha <= 0) return false;
        SetDrawBright(std::clamp(red, 0, 0xff),
                      std::clamp(green, 0, 0xff),
                      std::clamp(blue, 0, 0xff));
        SetDrawBlendMode(blendMode, std::clamp(alpha, 0, 0xff));
        drawOriginalMode7Node(handle, drawX, drawY, angle,
                              scaleX, scaleY, reverse);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        SetDrawBright(0xff, 0xff, 0xff);
        return true;
    };
    const auto drawNormal = [&drawNode](int handle, float drawX, float drawY,
                                        std::uint16_t angle, double scale,
                                        bool reverse = false,
                                        int red = 0xff, int green = 0xff,
                                        int blue = 0xff) {
        return drawNode(handle, drawX, drawY, angle, scale, scale, reverse,
                        DX_BLENDMODE_ALPHA, 0xff, red, green, blue);
    };
    const auto drawAdd = [&drawNode](int handle, float drawX, float drawY,
                                     std::uint16_t angle, double scale,
                                     int alpha, bool reverse = false,
                                     int red = 0xff, int green = 0xff,
                                     int blue = 0xff) {
        return drawNode(handle, drawX, drawY, angle, scale, scale, reverse,
                        DX_BLENDMODE_ADD, alpha, red, green, blue);
    };
    const auto pulseAlpha = [](int timer) {
        const double wave = std::sin(static_cast<double>(timer) *
                                     kBoss08Pi / 20.0);
        return std::clamp(0x80 - static_cast<int>(wave * -128.0),
                          0, 0xff);
    };
    const auto coreEntryScale = [](int timer) {
        if (timer < 0) return 0.1;
        if (timer < 20) {
            return 0.1 + std::sin(static_cast<double>(timer) *
                                  kBoss08Pi / 40.0) * 0.9;
        }
        return 1.0;
    };
    const auto delayedEntryScale = [](int timer) {
        if (timer < 10) return 0.0;
        if (timer < 30) {
            return std::sin(static_cast<double>(timer - 10) *
                            kBoss08Pi / 40.0);
        }
        return 1.0;
    };
    const auto fallback = [&enemy](float drawX, float drawY) {
        DrawCircle(static_cast<int>(drawX), static_cast<int>(drawY),
                   std::max(6, enemy.radius / 3),
                   GetColor(255, 100, 180), TRUE);
    };

    // FUN_140040750 manually queues Enemy_m[168] appendages around an
    // Enemy_m[167] body for all four 0xa7..0xaa variants.
    if (enemy.spawnType >= 0xa7 && enemy.spawnType <= 0xaa) {
        if (exactLayer != 0x1d) return true;
        const bool reverse = (enemy.childIndex & 1) != 0;
        const int appendage = mediumFrame(168);
        const int body = mediumFrame(167);
        if (appendage != -1) {
            drawOriginalMode7Node(appendage, x, y, enemy.sourceAngle16,
                                  1.0, 1.0, reverse);
        }
        if (body != -1) {
            drawOriginalMode7Node(body, x, y, enemy.sourceAngle16,
                                  1.0, 1.0, reverse);
        }
        if (appendage == -1 && body == -1) {
            DrawCircle(static_cast<int>(x), static_cast<int>(y),
                       std::max(6, enemy.radius / 3),
                       GetColor(255, 100, 180), TRUE);
        }
        return true;
    }

    // FUN_140041710 queues a translucent offset copy followed by the opaque
    // Enemy_m[166] body; the old path incorrectly used Enemy_l[53].
    if (enemy.spawnType == 0xab) {
        const int body = mediumFrame(166);
        if (body != -1 && exactLayer == 0x18) {
            SetDrawBright(0, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
            drawOriginalMode7Node(body, x + 16.0f, y + 9.0f,
                                  enemy.sourceAngle16, 1.0, 1.0, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(255, 255, 255);
        }
        if (body != -1 && exactLayer == 0x20) {
            drawOriginalMode7Node(body, x, y, enemy.sourceAngle16,
                                  1.0, 1.0, false);
        }
        else if (body == -1 && exactLayer == 0x20) {
            DrawCircle(static_cast<int>(x), static_cast<int>(y),
                       std::max(6, enemy.radius / 3),
                       GetColor(255, 100, 180), TRUE);
        }
        if (enemy.drawHelperState == 2 && exactLayer == 0x15) {
            const int overlay = effectMediumFrames_.size() > 18
                                    ? effectMediumFrames_[18]
                                    : -1;
            drawNode(overlay, x, y, enemy.sourceAngle16,
                     0.8, 0.5, false, DX_BLENDMODE_ALPHA, 0xc0);
        }
        if (enemy.targetable) {
            drawEnemyGaugeExact(enemy, enemy.radius >= 50 ? 2 : 1,
                                x, y, exactLayer);
        }
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    const int state = enemy.drawHelperState;

    if (enemy.spawnType == 0xac) {
        if (enemy.targetable) {
            drawEnemyGaugeExact(enemy, 1, x, y, exactLayer);
        }
        if (exactLayer != 0x1f) return true;
        const double wave = std::sin(static_cast<double>(timer) *
                                     kBoss08Pi / 50.0);
        const float baseY = y + 108.0f - static_cast<float>(wave * 3.0);
        bool drew = false;
        if (state == 2) {
            drew = drawNormal(mediumFrame(169), x, baseY, 0, 1.0);
        }
        else {
            drew |= drawNormal(mediumFrame(163), x, baseY, 0, 1.0);
            drew |= drawNormal(mediumFrame(164), x, y, 0, 1.0);
            if (timer >= 0 && timer < 24) {
                const int alpha = static_cast<int>(
                    std::sin(static_cast<double>(timer + 24) *
                             kBoss08Pi / 48.0) * 192.0);
                drew |= drawAdd(mediumFrame(164), x, y, 0, 1.0, alpha);
            }
            const float capY = baseY - 225.0f +
                               static_cast<float>(wave * 6.0);
            drew |= drawNormal(mediumFrame(165), x, capY, 0, 1.0);
        }
        if (!drew) fallback(x, y);
        return true;
    }

    const auto drawTwinBladeBody = [&](double scale, double radius,
                                       int red = 0xff, int green = 0xff,
                                       int blue = 0xff) {
        const double radians = boss08Radians(enemy.sourceAngle16);
        const float dx = static_cast<float>(std::cos(radians) * radius);
        const float dy = static_cast<float>(std::sin(radians) * radius);
        bool drew = false;
        drew |= drawNormal(smallFrame(136), x + dx, y + dy,
                           enemy.sourceAngle16, scale, false,
                           red, green, blue);
        drew |= drawNormal(
            smallFrame(136), x - dx, y - dy,
            boss08Angle(static_cast<int>(enemy.sourceAngle16) + 0x8000),
            scale, true, red, green, blue);
        drew |= drawNormal(smallFrame(135), x, y, 0, scale);
        drew |= drawAdd(smallFrame(135), x, y, 0, scale,
                        pulseAlpha(timer));
        return drew;
    };

    if (enemy.spawnType == 0xad) {
        if (enemy.targetable) {
            drawEnemyGaugeExact(enemy, 2, x, y, exactLayer);
        }
        if (exactLayer != 0x24) return true;
        const double radius = std::sin(static_cast<double>(timer) *
                                       kBoss08Pi / 30.0) * 4.0;
        if (!drawTwinBladeBody(1.0, radius)) fallback(x, y);
        return true;
    }

    if ((enemy.spawnType >= 0xae && enemy.spawnType <= 0xb6)) {
        if (enemy.targetable && enemy.spawnType != 0xb4 &&
            enemy.spawnType != 0xb5) {
            drawEnemyGaugeExact(enemy, 2, x, y, exactLayer);
        }
        if (exactLayer != 0x24) return true;
        double appendageScale = delayedEntryScale(timer);
        int appendageBlend = DX_BLENDMODE_ALPHA;
        int appendageAlpha = 0xff;
        int red = 0xff;
        int green = 0xff;
        int blue = 0xff;

        if (enemy.spawnType == 0xb4 || enemy.spawnType == 0xb5) {
            appendageBlend = DX_BLENDMODE_ADD;
            appendageAlpha = 0xc0;
        }
        else if (enemy.spawnType == 0xb6 && timer >= 60) {
            const double envelope = timer < 200
                ? std::sin(static_cast<double>(timer - 60) *
                           kBoss08Pi / 280.0)
                : 1.0;
            appendageScale += 0.2 *
                std::sin(static_cast<double>(timer) * kBoss08Pi / 3.5) *
                envelope;
            const int tint = timer < 200
                ? 0xff - static_cast<int>(envelope * 191.0)
                : 0x40;
            green = tint;
            blue = tint;
        }

        const auto appendageAngle = boss08Angle(timer * 0x309);
        bool drew = drawNode(smallFrame(137), x, y, appendageAngle,
                             appendageScale, appendageScale, false,
                             appendageBlend, appendageAlpha,
                             red, green, blue);
        const double coreScale = coreEntryScale(timer);
        drew |= drawNormal(smallFrame(135), x, y, 0, coreScale);
        drew |= drawAdd(smallFrame(135), x, y, 0, coreScale,
                        pulseAlpha(timer));
        if (!drew) fallback(x, y);
        return true;
    }

    if (enemy.spawnType == 0xb7) {
        if (enemy.targetable) {
            drawEnemyGaugeExact(enemy, 2, x, y, exactLayer);
        }
        if (exactLayer != 0x24) return true;
        double scale = 1.0;
        if (state == 0 && timer < 50) {
            scale = 0.2 + std::sin(static_cast<double>(timer) *
                                   kBoss08Pi / 100.0) * 0.8;
        }
        const double radius = std::sin(static_cast<double>(timer) *
                                       kBoss08Pi / 30.0) * 8.0 * scale;
        if (!drawTwinBladeBody(scale, radius)) fallback(x, y);
        return true;
    }

    if (enemy.spawnType >= 0xb8 && enemy.spawnType <= 0xba) {
        const int bodyLayer = enemy.spawnType == 0xb8 ? 0x20
                            : enemy.spawnType == 0xb9 ? 0x1e
                                                       : 0x1f;
        if (exactLayer != bodyLayer) return true;
        int frame = 57;
        if (enemy.spawnType == 0xb9) frame = 58;
        if (enemy.spawnType == 0xba) frame = state == 0 ? 60 : 59;

        double scale = 1.0;
        if (state == 1) {
            if (enemy.spawnType == 0xba) {
                static constexpr std::array<double, 5> kWingScale{{
                    3.5, 4.5, 5.0, 5.0, 6.0,
                }};
                scale = kWingScale[static_cast<std::size_t>(
                    std::clamp(config_.difficulty, 0, 4))];
            }
            else {
                scale = 3.5;
            }
        }

        const bool reverse = enemy.spawnType == 0xba && enemy.originX < 0.0f;
        auto angle = enemy.sourceAngle16;
        if (reverse) {
            angle = boss08Angle(static_cast<int>(angle) + 0x8000);
        }

        int red = 0xff;
        int green = 0xff;
        int blue = 0xff;
        const bool breaking = state == 9 && timer < 150;
        if (breaking) {
            static constexpr std::array<std::array<int, 3>, 7> kPalette{{
                {{0xff, 0x78, 0x78}}, {{0xff, 0xc8, 0x6e}},
                {{0xff, 0xff, 0x78}}, {{0x78, 0xff, 0x78}},
                {{0x78, 0xff, 0xff}}, {{0x78, 0x78, 0xff}},
                {{0xdc, 0x78, 0xff}},
            }};
            const int segment = (timer / 20) % 7;
            const int next = (segment + 1) % 7;
            const double mix = static_cast<double>(frame_ % 20) / 20.0;
            red = static_cast<int>(kPalette[static_cast<std::size_t>(segment)][0] +
                (kPalette[static_cast<std::size_t>(next)][0] -
                 kPalette[static_cast<std::size_t>(segment)][0]) * mix);
            green = static_cast<int>(kPalette[static_cast<std::size_t>(segment)][1] +
                (kPalette[static_cast<std::size_t>(next)][1] -
                 kPalette[static_cast<std::size_t>(segment)][1]) * mix);
            blue = static_cast<int>(kPalette[static_cast<std::size_t>(segment)][2] +
                (kPalette[static_cast<std::size_t>(next)][2] -
                 kPalette[static_cast<std::size_t>(segment)][2]) * mix);
        }

        const int handle = largeFrame(frame);
        bool drew = drawNormal(handle, x, y, angle, scale, reverse,
                               red, green, blue);
        if (breaking) {
            drew |= drawAdd(handle, x, y, angle, scale, 0xff, reverse,
                            red, green, blue);
        }
        if (!drew) fallback(x, y);
        return true;
    }

    if (enemy.spawnType == 0xbb) {
        // FUN_1400483e0 is an invisible controller. Its only visual is a
        // separately allocated Effect_m[20] node; it has no body sprite.
        if (enemy.targetable) {
            drawEnemyGaugeExact(enemy, 1, x, y, exactLayer);
        }
        return true;
    }

    if (enemy.spawnType >= 0xbc && enemy.spawnType <= 0xc2) {
        if (exactLayer != 0x24) return true;
        static constexpr std::array<std::array<int, 3>, 7> kPalette{{
            {{0xff, 0x78, 0x78}}, {{0xff, 0xc8, 0x6e}},
            {{0xff, 0xff, 0x78}}, {{0x78, 0xff, 0x78}},
            {{0x78, 0xff, 0xff}}, {{0x78, 0x78, 0xff}},
            {{0xdc, 0x78, 0xff}},
        }};
        double scale = 1.0;
        int entranceTurn = 0;
        if (state == 0 && timer < 60) {
            const double wave = std::sin(static_cast<double>(timer) *
                                         kBoss08Pi / 120.0);
            scale = 0.2 + wave * 0.8;
            entranceTurn = -static_cast<int>(wave * 131072.0);
        }
        const auto& color = kPalette[static_cast<std::size_t>(
            enemy.spawnType - 0xbc)];
        const auto bladeAngle = boss08Angle(
            static_cast<int>(enemy.secondaryAngle16) + entranceTurn);
        const double radians = boss08Radians(enemy.sourceAngle16);
        const double radius = -4.0 * scale;
        const float dx = static_cast<float>(std::cos(radians) * radius);
        const float dy = static_cast<float>(std::sin(radians) * radius);
        bool drew = drawNormal(smallFrame(136), x + dx, y + dy,
                               bladeAngle, scale, false,
                               color[0], color[1], color[2]);
        drew |= drawNormal(
            smallFrame(136), x - dx, y - dy,
            boss08Angle(static_cast<int>(bladeAngle) + 0x8000),
            scale, true, color[0], color[1], color[2]);
        drew |= drawNormal(smallFrame(135), x, y, 0, scale);
        drew |= drawAdd(smallFrame(135), x, y, 0, scale,
                        pulseAlpha(timer));
        if (!drew) fallback(x, y);
        return true;
    }

    if (enemy.spawnType == 0xc3) {
        if (exactLayer != 0x3c) return true;
        const int ring = effectLargeFrames_.size() > 6
                             ? effectLargeFrames_[6]
                             : -1;
        double scale = 1.2;
        int alpha = 0xff;
        if (state == 0 && timer < 32) {
            scale = 0.1 + std::sin(static_cast<double>(timer) *
                                   kBoss08Pi / 64.0) * 1.1;
        }
        else if (state == 1) {
            alpha = timer < 16
                ? static_cast<int>(
                      std::sin(static_cast<double>(timer + 16) *
                               kBoss08Pi / 32.0) * 255.0)
                : 0;
        }
        const auto turn = boss08Angle(frame_ * 0x400);
        bool drew = drawAdd(ring, x, y, turn, scale, alpha);
        drew |= drawAdd(ring, x, y,
                        boss08Angle(-static_cast<int>(turn)),
                        scale, alpha);
        if (!drew && alpha > 0) fallback(x, y);
        return true;
    }

    return true;
}

} // namespace reconstructed
