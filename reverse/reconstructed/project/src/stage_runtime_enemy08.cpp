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
constexpr std::size_t kStage08EntityCap = 0x200;

std::uint16_t normalizeStage08Angle(int angle) {
    return static_cast<std::uint16_t>(angle & 0xffff);
}

double stage08AngleRadians(std::uint16_t angle) {
    return static_cast<double>(angle) * kTau / 65536.0;
}

std::uint16_t stage08RadiansAngle(double radians) {
    return normalizeStage08Angle(
        static_cast<int>(radians * 65536.0 / kTau));
}

std::uint16_t approachStage08Angle(std::uint16_t current,
                                   std::uint16_t target, int step) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    delta = std::clamp(delta, -step, step);
    return normalizeStage08Angle(static_cast<int>(current) + delta);
}

std::uint32_t stage08ScriptRand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

int stage08Frame(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

template <std::size_t N>
int stage08AnimationFrame(int timer, int hold,
                          const std::array<int, N>& frames) {
    const int period = hold * static_cast<int>(N);
    int local = timer % period;
    if (local < 0) local += period;
    return frames[static_cast<std::size_t>(local / hold)];
}

bool isStage08CompositeRoot(int spawnType) {
    return spawnType == 0x9b || spawnType == 0x9c ||
           spawnType == 0x9e || spawnType == 0x9f ||
           spawnType == 0xa1 || spawnType == 0xa2;
}

bool isStage08CompositeChild(int spawnType) {
    return spawnType == 0x9d || spawnType == 0xa0 ||
           spawnType == 0xa3;
}

bool isStage08CarrierChild(int spawnType) {
    return spawnType == 0xa5 || spawnType == 0xa6;
}

} // namespace

bool StageRuntime::isStage08EnemyType(int spawnType) const {
    return spawnType >= 0x95 && spawnType <= 0xa6;
}

bool StageRuntime::spawnStage08EnemyChild(
    StageEnemy& parent, int spawnType, int childIndex, float offsetX,
    float offsetY, std::uint16_t angle16, int kind, int radius,
    bool targetable) {
    if ((!isStage08CompositeChild(spawnType) &&
         !isStage08CarrierChild(spawnType)) ||
        enemies_.size() + pendingEnemies_.size() >= kStage08EntityCap) {
        return false;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.updateCase = isStage08CompositeChild(spawnType) ? 0x1c : 0x68;
    child.sourceHitPoints = 99999999;
    child.sourceDispatchKind = kind;
    child.sourceDispatchField = radius;
    child.rewardWeight = kind;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = childIndex;
    child.sourceNote = isStage08CompositeChild(spawnType)
                           ? "S08 FUN_1400abc50 attached node"
                           : "S08 FUN_1400acd20 shared-HP carrier node";
    child.x = parent.x;
    child.y = parent.y;
    child.originX = offsetX;
    child.originY = offsetY;
    child.sourceX = static_cast<int>(std::lround(offsetX));
    child.sourceY = static_cast<int>(std::lround(offsetY));
    child.sourceAngle16 = angle16;
    child.secondaryAngle16 = angle16;
    child.targetAngle16 = angle16;
    child.angle = static_cast<float>(stage08AngleRadians(angle16));
    child.sourceSpeed = 0.0;
    child.speed = 0.0f;
    child.radius = radius;
    child.activationDelay = 0;
    child.targetable = targetable;
    child.hp = targetable ? std::max(1, parent.hp) : 99999999;
    child.maxHp = targetable ? std::max(1, parent.maxHp) : 99999999;
    child.drawHp = child.hp;
    pendingEnemies_.push_back(child);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage08Enemy(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto aimFrom = [this](float x, float y) {
        return stage08RadiansAngle(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto moveAlong = [](StageEnemy& target, std::uint16_t angle,
                              double speed) {
        const double radians = stage08AngleRadians(angle);
        target.angle = static_cast<float>(radians);
        target.sourceSpeed = speed;
        target.speed = static_cast<float>(speed);
        target.x += static_cast<float>(std::cos(radians) * speed);
        target.y += static_cast<float>(std::sin(radians) * speed);
    };
    const auto immediateDeath = [this](StageEnemy& target, int payout,
                                        int effectMode) {
        spawnEnemyDeathRewardBurst(target, payout, false);
        spawnEnemyDeathEffects(target, effectMode);
        target.targetable = false;
        target.active = false;
    };
    const auto outside = [](const StageEnemy& target, float left,
                            float right, float top, float bottom) {
        return target.x < left || target.x > right ||
               target.y < top || target.y > bottom;
    };
    const auto spawnPortraitEffect = [this]() {
        const int group = std::clamp(config_.setupGroup, 0, 2);
        const int frameIndex = 1 + group * 10;
        const int portrait = stage08Frame(playerFrameFrames_, frameIndex);
        spawnStageEffect(0x16, portrait, 0, 0x6f,
                         0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 0x78,
                         0xff, 0xff, 0xff, 0xff);
    };
    const auto spawnSmallDeathFlourish = [this](const StageEnemy& target,
                                                 float yOffset,
                                                 double minimumScale,
                                                 double maximumScale) {
        const int graph = effectSmallFrames_.size() > 6
                              ? effectSmallFrames_[6]
                              : -1;
        const auto seed = static_cast<std::uint32_t>(target.entityId) +
                          static_cast<std::uint32_t>(frame_);
        const std::uint32_t random = stage08ScriptRand(
            static_cast<int>(seed));
        const int minimum100 = static_cast<int>(minimumScale * 100.0);
        const int maximum100 = static_cast<int>(maximumScale * 100.0);
        const double scale = static_cast<double>(
            minimum100 + random % static_cast<std::uint32_t>(
                maximum100 - minimum100 + 1)) / 100.0;
        const auto angle = static_cast<std::uint16_t>(
            random - random / 0x10001u);
        spawnStageEffect(0x37, graph, 100, 0x15,
                         target.x, target.y + yOffset,
                         angle, 1.0,
                         scale, scale, 0x78,
                         0xff, 0xff, 0xff, 0x80);
    };

    if (enemy.spawnType == 0x95) { // FUN_1400a9080
        const int timer = enemy.helperTimer;
        enemy.y += 1.0f;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        const float horizontalOrigin = player_.x / 6.0f;
        if (!enemy.targetable &&
            enemy.x >= horizontalOrigin + 40.0f &&
            enemy.x <= horizontalOrigin + 560.0f &&
            enemy.y >= 40.0f && enemy.y <= 680.0f) {
            enemy.targetable = true;
        }
        if (timer == 0) enemy.sourceSpeed = 1.0;
        int local = timer % 30;
        if (local < 0) local += 30;
        if (local > 19) {
            moveAlong(enemy, enemy.sourceAngle16, enemy.sourceSpeed);
        }

        static constexpr std::array<int, 5> kCadence{{39, 24, 18, 14, 12}};
        static constexpr std::array<double, 5> kSpeed{{
            5.5, 6.5, 7.0, 7.5, 9.0,
        }};
        const float phase = static_cast<float>(
            std::sin((timer - 6) * kTau / 30.0) * -2.0 - 7.0);
        const float shotX = enemy.x - 25.0f;
        const float shotY = enemy.y + phase - 50.0f;
        if (shotY < 360.0f && timer >= 0 &&
            timer % kCadence[static_cast<std::size_t>(difficulty)] == 0 &&
            shotX >= horizontalOrigin &&
            shotX <= horizontalOrigin + 600.0f &&
            shotY >= 0.0f && shotY <= 720.0f) {
            const float dx = player_.x - shotX;
            const float dy = player_.y - shotY;
            if (dx * dx + dy * dy > 2500.0f) {
                const auto aimed = aimFrom(shotX, shotY);
                const auto snapped = normalizeStage08Angle(
                    ((static_cast<int>(aimed) + 0x800) >> 12) * 0x1000);
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(9, 0, shotX, shotY, snapped,
                                    10.0f, speed, 1, 0);
                spawnProjectileNode(9, 0, shotX, shotY, snapped,
                                    10.0f, speed + 0.2, 1, 0);
            }
        }
        if (enemy.hp < 1) {
            spawnSmallDeathFlourish(enemy, 20.0f, 0.8, 0.9);
            immediateDeath(enemy, 1000, 0);
            return;
        }
        if (enemy.targetable &&
            outside(enemy, horizontalOrigin - 100.0f,
                    horizontalOrigin + 700.0f, -100.0f, 820.0f)) {
            enemy.active = false;
        }
        return;
    }

    if (enemy.spawnType == 0x96) { // FUN_1400a9af0
        const int timer = enemy.helperTimer;
        enemy.y += 1.0f;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.helperState == 0) {
            if (timer == 0) {
                playPlayerSound(bullet2SoundHandle_, 0x19);
            }
            if (timer >= 20) {
                enemy.helperState = 1;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
        }
        if (enemy.helperState == 1) {
            static constexpr std::array<int, 5> kCadence{{18, 11, 8, 9, 7}};
            static constexpr std::array<double, 5> kSpeed{{
                4.5, 5.5, 6.0, 5.5, 6.6,
            }};
            const int activeTimer = enemy.helperTimer;
            if (activeTimer >= 0 &&
                activeTimer % kCadence[static_cast<std::size_t>(difficulty)] == 0) {
                const float bob = static_cast<float>(
                    -std::sin(activeTimer * kTau / 80.0));
                const float shotX = enemy.x - 25.0f;
                const float shotY = enemy.y + bob - 10.0f;
                const float dx = player_.x - shotX;
                const float dy = player_.y - shotY;
                if (shotX >= horizontalOrigin &&
                    shotX <= horizontalOrigin + 600.0f &&
                    shotY >= 0.0f && shotY < 360.0f &&
                    dx * dx + dy * dy > 2500.0f) {
                    const auto random =
                        stage08ScriptRand(frame_ + activeTimer);
                    const auto angle = normalizeStage08Angle(
                        static_cast<int>(aimFrom(shotX, shotY)) +
                        static_cast<int>(random % 1201u) - 600);
                    const double speed =
                        kSpeed[static_cast<std::size_t>(difficulty)];
                    spawnProjectileNode(7, 0, shotX, shotY, angle,
                                        10.0f, speed, 1, 0);
                    if (difficulty > 2) {
                        spawnProjectileNode(7, 0, shotX, shotY, angle,
                                            10.0f, speed + 1.5, 1, 0);
                    }
                }
            }
        }
        if (enemy.hp < 1) {
            immediateDeath(enemy, 1000, 0);
            return;
        }
        if (enemy.targetable &&
            outside(enemy, horizontalOrigin - 100.0f,
                    horizontalOrigin + 700.0f, -100.0f, 820.0f)) {
            enemy.active = false;
        }
        return;
    }

    if (enemy.spawnType >= 0x97 && enemy.spawnType <= 0x99) {
        // FUN_1400aa590
        enemy.y += 1.0f;
        int timer = enemy.helperTimer;
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = timer;
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y;
            if (timer >= 20) {
                if (enemy.spawnType == 0x97) {
                    enemy.sourceSpeed = 0.0;
                }
                else {
                    enemy.sourceAngle16 = enemy.originX > 360.0f
                                                ? 0x8000
                                                : 0;
                    enemy.sourceSpeed = enemy.spawnType == 0x98 ? 1.5 : 6.0;
                }
                enemy.targetAngle16 = aimFrom(enemy.x, enemy.y - 31.0f);
                enemy.secondaryAngle16 = 0;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = false;
                enemy.targetableTimer = 0;
            }
            else {
                return;
            }
        }

        timer = enemy.helperTimer;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        const float horizontalOrigin = player_.x / 6.0f;
        if (!enemy.targetable &&
            enemy.x >= horizontalOrigin &&
            enemy.x <= horizontalOrigin + 600.0f &&
            enemy.y >= 0.0f && enemy.y <= 720.0f) {
            enemy.targetable = true;
        }
        const auto liveAim = aimFrom(enemy.x, enemy.y - 31.0f);
        moveAlong(enemy, enemy.sourceAngle16, enemy.sourceSpeed);
        const int turnSign = enemy.originX > 360.0f ? -1 : 1;
        enemy.secondaryAngle16 = normalizeStage08Angle(
            static_cast<int>(enemy.secondaryAngle16) -
            static_cast<int>(enemy.sourceSpeed * 522.0 * turnSign));
        if (enemy.spawnType == 0x99) {
            if (timer <= 100 && enemy.sourceSpeed > 0.0) {
                enemy.sourceSpeed -= 0.06;
            }
            if (timer >= 100) enemy.sourceSpeed = 0.0;
        }

        static constexpr std::array<int, 5> kPeriod{{90, 60, 44, 60, 44}};
        static constexpr std::array<int, 5> kStep{{30, 18, 12, 12, 10}};
        static constexpr std::array<double, 5> kSpeed{{
            5.5, 6.4, 7.0, 7.0, 8.0,
        }};
        bool lockTurret = false;
        if (timer >= 30) {
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int step = kStep[static_cast<std::size_t>(difficulty)];
            lockTurret = (timer - 30) % period <= step * 2 &&
                         enemy.y < 360.0f;
        }
        if (!lockTurret) {
            int delta = static_cast<int>(liveAim) -
                        static_cast<int>(enemy.targetAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            enemy.targetAngle16 = approachStage08Angle(
                enemy.targetAngle16, liveAim, std::abs(delta) / 10 + 0x30);
        }
        if (timer >= 30) {
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int step = kStep[static_cast<std::size_t>(difficulty)];
            const int local = (timer - 30) % period;
            const double mount = stage08AngleRadians(enemy.secondaryAngle16);
            const float shotX = enemy.x + static_cast<float>(std::cos(mount) * 38.0);
            const float shotY = enemy.y - 30.0f +
                                static_cast<float>(std::sin(mount) * 38.0);
            const float dx = player_.x - shotX;
            const float dy = player_.y - shotY;
            if (local < step * 3 && local % step == 0 &&
                shotX >= horizontalOrigin &&
                shotX <= horizontalOrigin + 600.0f &&
                shotY >= 0.0f && shotY < 360.0f &&
                dx * dx + dy * dy > 2500.0f) {
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)];
                if (difficulty > 2) {
                    for (const int offset : {-2000, 2000}) {
                        spawnProjectileNode(
                            7, 0, shotX, shotY,
                            normalizeStage08Angle(
                                static_cast<int>(enemy.targetAngle16) + offset),
                            10.0f, speed - 0.5, 1, 0);
                    }
                }
                spawnProjectileNode(7, 0, shotX, shotY,
                                    enemy.targetAngle16, 10.0f,
                                    speed, 1, 0);
            }
        }
        if (enemy.hp < 1) {
            spawnSmallDeathFlourish(enemy, 0.0f, 1.1, 1.2);
            immediateDeath(enemy, 1000, 0);
            return;
        }
        if (enemy.targetable && enemy.y >= 820.0f) enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0x9a) { // FUN_1400ab110
        enemy.y += 1.0f;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        int timer = enemy.helperTimer;
        if (enemy.helperState == 0 && enemy.y >= -140.0f) {
            spawnSharedHitboxProxy(enemy, 0x151, 0.0f, 120.0f, 120);
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
            timer = enemy.helperTimer;
        }

        if (enemy.helperState == 1 && timer < 400) {
            static constexpr std::array<int, 5> kOpeningCount{{
                15, 24, 27, 27, 27,
            }};
            static constexpr std::array<double, 5> kOpeningSpeed{{
                5.5, 6.5, 7.5, 6.5, 7.7,
            }};
            static constexpr std::array<double, 5> kDecay{{
                0.12, 0.16, 0.18, 0.18, 0.18,
            }};
            static constexpr std::array<double, 5> kCenterSpeed{{
                6.5, 7.5, 8.5, 8.5, 11.1,
            }};
            const int local = (timer - 40) % 200;
            const std::array<float, 3> shotX{{
                enemy.x - 87.0f, enemy.x + 90.0f, enemy.x,
            }};
            const std::array<float, 3> shotY{{
                enemy.y + 150.0f, enemy.y + 100.0f, enemy.y + 5.0f,
            }};
            bool fired = false;
            for (int mount = 0; mount < 2; ++mount) {
                const int offset = mount * 50;
                const int count =
                    kOpeningCount[static_cast<std::size_t>(difficulty)];
                const int phase = local - offset;
                if (phase == 0) {
                    if (mount == 0) enemy.sourceAngle16 = aimFrom(shotX[0], shotY[0]);
                    else enemy.secondaryAngle16 = aimFrom(shotX[1], shotY[1]);
                }
                const auto savedAim = mount == 0
                                          ? enemy.sourceAngle16
                                          : enemy.secondaryAngle16;
                const double speed =
                    kOpeningSpeed[static_cast<std::size_t>(difficulty)] -
                    static_cast<double>(phase) *
                        kDecay[static_cast<std::size_t>(difficulty)];
                if (phase >= 0 && phase < count && phase % 3 == 0) {
                    const int spread = (30000 / count) * phase;
                    spawnProjectileSpread(3, 0, shotX[mount], shotY[mount],
                                          savedAim, 10.0f, speed, 1,
                                          2, spread, 0);
                    if (difficulty > 2) {
                        spawnProjectileSpread(3, 0, shotX[mount], shotY[mount],
                                              savedAim, 10.0f, speed + 2.4,
                                              1, 2, spread, 0);
                    }
                    fired = true;
                }
                const int secondPhase = phase - 1;
                if (secondPhase >= 0 && secondPhase < count &&
                    secondPhase % 3 == 0) {
                    const int spread = (30000 / count) * phase;
                    spawnProjectileSpread(5, 0, shotX[mount], shotY[mount],
                                          savedAim, 10.0f, speed - 1.2,
                                          1, 2, spread, 0);
                    if (difficulty > 2) {
                        spawnProjectileSpread(5, 0, shotX[mount], shotY[mount],
                                              savedAim, 10.0f, speed + 1.2,
                                              1, 2, spread, 0);
                    }
                    fired = true;
                }
            }
            if (local == 110) {
                enemy.targetAngle16 = aimFrom(shotX[2], shotY[2]);
            }
            if (local >= 110 && local <= 149 && (local - 110) % 5 == 0) {
                const double speed =
                    kCenterSpeed[static_cast<std::size_t>(difficulty)];
                for (const int offset : {-900, 0, 900}) {
                    spawnProjectileNode(
                        10, 0, shotX[2], shotY[2],
                        normalizeStage08Angle(
                            static_cast<int>(enemy.targetAngle16) + offset),
                        10.0f, speed, 1, 0);
                }
                if (difficulty > 2) {
                    for (const int offset : {-1650, 1650}) {
                        spawnProjectileNode(
                            10, 0, shotX[2], shotY[2],
                            normalizeStage08Angle(
                                static_cast<int>(enemy.targetAngle16) + offset),
                            10.0f, speed - 0.8, 1, 0);
                    }
                }
                fired = true;
            }
            if (fired) playPlayerSound(bullet1SoundHandle_, 0x13);
        }

        if (enemy.helperState == 1 && enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x708, false);
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
            spawnPortraitEffect();
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
            enemy.targetableTimer = 0;
            timer = enemy.helperTimer;
        }
        if (enemy.helperState == 2) {
            enemy.targetable = false;
            if (timer <= 60) {
                spawnStage02DeathExplosionChain(enemy);
            }
            if (timer == 60) {
                const int graph = stage08Frame(enemyLargeFrames_, 53);
                spawnStageEffect(0x37, graph, 600, 0x1c,
                                 enemy.x, enemy.y + 50.0f, 0,
                                 1.0, 1.0, 1.0, 0x78,
                                 0xff, 0xff, 0xff, 0xff);
                spawnEnemyDeathEffects(enemy, 2);
                enemy.active = false;
            }
            return;
        }
        if (enemy.y >= 1020.0f) enemy.active = false;
        return;
    }

    if (isStage08CompositeRoot(enemy.spawnType)) { // FUN_1400abc50
        const int timer = enemy.helperTimer;
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = timer;
            if (timer == 0) {
                const float scheduledX = enemy.x;
                enemy.x = scheduledX < 360.0f ? -100.0f : 820.0f;
                enemy.y = -100.0f;
            }
            const float horizontalOrigin = player_.x / 6.0f;
            enemy.markerDrawX = std::clamp(
                enemy.x, horizontalOrigin - 50.0f,
                horizontalOrigin + 650.0f);
            enemy.markerDrawY = std::clamp(enemy.y, -50.0f, 770.0f);
            if (timer >= 20) {
                int childType = 0x9d;
                double initialSpeed = 11.4;
                std::array<float, 4> offsetX{{80.0f, -80.0f, 160.0f, -160.0f}};
                std::array<float, 4> offsetY{{-40.0f, -40.0f, 0.0f, 0.0f}};
                std::array<int, 4> angles{{0, 0, 0, 0}};
                if (enemy.spawnType == 0x9e || enemy.spawnType == 0x9f) {
                    childType = 0xa0;
                    initialSpeed = 12.2;
                    offsetX = {{55.0f, -55.0f, 100.0f, -100.0f}};
                    offsetY = {{-50.0f, -50.0f, 0.0f, 0.0f}};
                    angles = {{200, -200, 500, -500}};
                }
                else if (enemy.spawnType == 0xa1 || enemy.spawnType == 0xa2) {
                    childType = 0xa3;
                    initialSpeed = 11.8;
                    offsetX = {{90.0f, -90.0f, 180.0f, -180.0f}};
                    offsetY = {{-40.0f, -40.0f, 0.0f, 0.0f}};
                    angles = {{-600, 600, -1200, 1200}};
                }
                for (int index = 0; index < 4; ++index) {
                    spawnStage08EnemyChild(
                        enemy, childType, index,
                        offsetX[static_cast<std::size_t>(index)],
                        offsetY[static_cast<std::size_t>(index)],
                        normalizeStage08Angle(
                            angles[static_cast<std::size_t>(index)]),
                        1, 20, false);
                }
                enemy.sourceSpeed = initialSpeed;
                enemy.sourceAngle16 = aimFrom(enemy.x, enemy.y);
                enemy.targetAngle16 = enemy.sourceAngle16;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
                playPlayerSound(bullet2SoundHandle_, 0x19);
            }
            return;
        }

        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (timer < 280) {
            if (timer >= 60 && (timer - 60) % 50 == 0) {
                const int seed = timer * enemy.entityId;
                enemy.markerDrawX = 120.0f + static_cast<float>(
                    stage08ScriptRand(seed * 0x378) % 481u);
                enemy.markerDrawY = static_cast<float>(timer) +
                    static_cast<float>(stage08ScriptRand(seed * 0x22b8) % 101u);
            }
            const double minimum =
                (enemy.spawnType == 0x9b || enemy.spawnType == 0x9c)
                    ? 2.4
                    : ((enemy.spawnType == 0x9e || enemy.spawnType == 0x9f)
                           ? 3.2
                           : 2.8);
            if (timer <= 60 && enemy.sourceSpeed > minimum) {
                enemy.sourceSpeed -= 0.15;
            }
        }
        else {
            enemy.markerDrawY = -500.0f;
            enemy.sourceSpeed += 0.1;
        }
        const auto steeringTarget = stage08RadiansAngle(std::atan2(
            static_cast<double>(enemy.markerDrawY - enemy.y),
            static_cast<double>(enemy.markerDrawX - enemy.x)));
        enemy.sourceAngle16 = approachStage08Angle(
            enemy.sourceAngle16, steeringTarget, 0x280);
        moveAlong(enemy, enemy.sourceAngle16, enemy.sourceSpeed);

        static constexpr std::array<int, 5> kPeriod{{90, 75, 60, 60, 50}};
        static constexpr std::array<int, 5> kWindow{{25, 40, 40, 40, 40}};
        static constexpr std::array<double, 5> kSpeed{{
            7.0, 8.0, 9.0, 8.5, 9.5,
        }};
        if (timer >= 60 && timer < 280) {
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int local = (timer - 60) % period;
            if (local < kWindow[static_cast<std::size_t>(difficulty)] &&
                local % 5 == 0) {
                int visual = 7;
                float shotY = enemy.y + 12.0f;
                if (enemy.spawnType == 0x9e || enemy.spawnType == 0x9f) {
                    visual = 9;
                    shotY = enemy.y;
                }
                else if (enemy.spawnType == 0xa1 || enemy.spawnType == 0xa2) {
                    shotY = enemy.y + 16.0f;
                }
                if (local == 0) {
                    enemy.targetAngle16 = aimFrom(enemy.x, shotY);
                }
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    static_cast<double>(local) * 0.08;
                spawnProjectileNode(visual, 0, enemy.x, shotY,
                                    enemy.targetAngle16, 10.0f,
                                    speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(visual, 0, enemy.x, shotY,
                                        enemy.targetAngle16, 10.0f,
                                        speed + 2.0, 1, 0);
                }
            }
        }
        if (enemy.hp < 1) {
            if ((enemy.spawnType == 0x9c || enemy.spawnType == 0x9f ||
                 enemy.spawnType == 0xa2) &&
                player_.bombLock == 0) {
                const std::uint32_t random = stage08ScriptRand(frame_);
                spawnRewardItem(
                    7, enemy.x, enemy.y,
                    normalizeStage08Angle(
                        static_cast<int>(random % 0x4001u) + 0x2000),
                    4.0f, 30);
            }
            immediateDeath(enemy, 500, 1);
            return;
        }
        if (timer > 240 &&
            outside(enemy, player_.x / 6.0f - 128.0f,
                    player_.x / 6.0f + 728.0f, -128.0f, 848.0f)) {
            enemy.active = false;
        }
        return;
    }

    if (isStage08CompositeChild(enemy.spawnType)) { // FUN_14008bd60
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || !parent->active ||
            parent->spawnType != enemy.parentSpawnType ||
            !isStage08CompositeRoot(parent->spawnType) || parent->hp < 1) {
            enemy.targetable = false;
            enemy.active = false;
            if (parent != nullptr && parent->liveChildCount > 0) {
                --parent->liveChildCount;
            }
            return;
        }
        enemy.drawBodyThisFrame = true;
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
        const auto childAim = aimFrom(enemy.x, enemy.y);
        const auto parentAim = aimFrom(parent->x, parent->y);
        const auto facingTarget = enemy.spawnType == 0x9d
                                      ? childAim
                                      : normalizeStage08Angle(
                                            static_cast<int>(parentAim) +
                                            static_cast<int>(enemy.secondaryAngle16));
        int delta = static_cast<int>(facingTarget) -
                    static_cast<int>(enemy.sourceAngle16);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        enemy.sourceAngle16 = approachStage08Angle(
            enemy.sourceAngle16, facingTarget, std::abs(delta) / 10 + 0x30);

        static constexpr std::array<int, 5> kPeriod{{90, 75, 60, 60, 50}};
        static constexpr std::array<int, 5> kWindow{{25, 40, 40, 40, 40}};
        static constexpr std::array<double, 5> kSpeed{{
            7.0, 8.0, 9.0, 8.0, 9.5,
        }};
        const int timer = enemy.helperTimer;
        if (timer >= 60 && timer < 280) {
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int local = (timer - 60) % period;
            if (local < kWindow[static_cast<std::size_t>(difficulty)] &&
                local % 4 == 0) {
                int visual = enemy.spawnType == 0xa0 ? 9 : 7;
                float shotX = enemy.x;
                float shotY = enemy.y;
                if (enemy.spawnType != 0xa3) {
                    const double radians =
                        stage08AngleRadians(enemy.sourceAngle16);
                    const double distance = enemy.spawnType == 0xa0 ? 8.0 : 15.0;
                    shotX += static_cast<float>(std::cos(radians) * distance);
                    shotY += static_cast<float>(std::sin(radians) * distance);
                }
                if (local == 0) enemy.targetAngle16 = facingTarget;
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    static_cast<double>(local) * 0.08;
                spawnProjectileNode(visual, 0, shotX, shotY,
                                    enemy.targetAngle16, 10.0f,
                                    speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(visual, 0, shotX, shotY,
                                        enemy.targetAngle16, 10.0f,
                                        speed + 2.5, 1, 0);
                }
            }
        }
        return;
    }

    if (enemy.spawnType == 0xa4) { // FUN_1400acd20
        int timer = enemy.helperTimer;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = timer;
            const float horizontalOrigin = player_.x / 6.0f;
            enemy.markerDrawX = std::clamp(
                enemy.x, horizontalOrigin - 50.0f,
                horizontalOrigin + 650.0f);
            enemy.markerDrawY = std::clamp(enemy.y, -50.0f, 770.0f);
            if (timer >= 20) {
                struct ChildSpec {
                    int type;
                    float x;
                    float y;
                    int angle;
                    int kind;
                };
                static constexpr std::array<ChildSpec, 4> kChildren{{
                    {0xa5,  20.0f, -10.0f,  -6000,  0},
                    {0xa5, -20.0f, -10.0f, -26768,  0},
                    {0xa6,  10.0f,   0.0f,  -3000, 30},
                    {0xa6, -10.0f,   0.0f, -29768, 30},
                }};
                for (int index = 0; index < 4; ++index) {
                    const auto& child =
                        kChildren[static_cast<std::size_t>(index)];
                    spawnStage08EnemyChild(
                        enemy, child.type, index, child.x, child.y,
                        normalizeStage08Angle(child.angle), child.kind,
                        60, true);
                }
                enemy.originX = 360.0f;
                enemy.originY = enemy.y;
                enemy.sourceSpeed = 0.0;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
                playPlayerSound(bullet2SoundHandle_, 0x19);
                timer = enemy.helperTimer;
            }
        }

        if (enemy.helperState == 1 || enemy.helperState == 2) {
            const int lifeTimer = enemy.age;
            double amplitude = 100.0;
            if (lifeTimer < 198) {
                amplitude = 650.0 -
                    std::sin(static_cast<double>(lifeTimer) * kPi / 198.0) *
                        550.0;
            }
            if (enemy.sourceX <= 360) amplitude = -amplitude;
            const int retreatStart = selectedStage_ == 9 ? 1200 : 2000;
            if (lifeTimer > retreatStart) {
                enemy.sourceSpeed += 0.1;
                enemy.originY -= static_cast<float>(enemy.sourceSpeed);
            }
            const double phase = static_cast<double>(lifeTimer + 99) *
                                 kTau / 396.0;
            enemy.x = enemy.originX +
                      static_cast<float>(std::sin(phase) * amplitude);
            enemy.y = enemy.originY +
                      static_cast<float>(std::sin(phase * 1.5) * 50.0);
        }

        if (enemy.helperState == 2) {
            static constexpr std::array<int, 5> kPeriod{{
                180, 140, 130, 120, 120,
            }};
            static constexpr std::array<int, 5> kCount{{
                11, 15, 17, 17, 19,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                4.5, 5.5, 6.0, 5.0, 6.0,
            }};
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            if (timer >= 160 && (timer - 160) % period == 0) {
                const float aimY = enemy.y - 40.0f + static_cast<float>(
                    std::sin((timer - 32) * kTau / 88.0) * 2.0);
                const auto aimed = aimFrom(enemy.x, aimY);
                const int count = kCount[static_cast<std::size_t>(difficulty)];
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                const int outerCount = std::max(1, count - 1);
                const int outerSpread =
                    (0x8000 / outerCount) * std::max(0, count - 2);
                spawnProjectileSpread(5, 0, enemy.x, enemy.y, aimed,
                                      0.0f, speed, 1, outerCount,
                                      outerSpread, 0);
                spawnProjectileSpread(3, 0, enemy.x, enemy.y, aimed,
                                      0.0f, speed + 1.2, 1, count,
                                      0x8000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(5, 0, enemy.x, enemy.y, aimed,
                                          0.0f, speed + 2.4, 1,
                                          outerCount, outerSpread, 0);
                    spawnProjectileSpread(3, 0, enemy.x, enemy.y, aimed,
                                          0.0f, speed + 3.6, 1, count,
                                          0x8000, 0);
                }
            }
        }

        if (enemy.helperState == 1 &&
            enemy.hp <= static_cast<int>(enemy.maxHp * 0.4)) {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
            spawnEnemyDeathEffects(enemy, 2);
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            timer = enemy.helperTimer;
        }
        if ((enemy.helperState == 1 || enemy.helperState == 2) &&
            enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x960, false);
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
            spawnPortraitEffect();
            enemy.helperState = 3;
            enemy.helperTimer = 0;
            enemy.targetable = false;
            enemy.targetableTimer = 0;
            timer = enemy.helperTimer;
        }
        if (enemy.helperState == 3) {
            enemy.targetable = false;
            enemy.y += static_cast<float>(timer) * 0.1f;
            if (timer <= 60) {
                spawnStage02DeathExplosionChain(enemy);
            }
            if (timer == 60) {
                spawnEnemyDeathEffects(enemy, 2);
                enemy.active = false;
                clearLateStageGate(selectedStage_);
            }
            return;
        }
        if (enemy.helperState == 3 &&
            outside(enemy, -128.0f, 848.0f, -128.0f, 848.0f)) {
            enemy.active = false;
            clearLateStageGate(selectedStage_);
        }
        return;
    }

    if (isStage08CarrierChild(enemy.spawnType)) { // FUN_1400ad970
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || !parent->active ||
            parent->spawnType != 0xa4) {
            if (parent != nullptr && parent->spawnType == 0xa4 &&
                parent->helperState == 3) {
                spawnEnemyDeathEffects(enemy, 1);
            }
            enemy.targetable = false;
            enemy.active = false;
            if (parent != nullptr && parent->liveChildCount > 0) {
                --parent->liveChildCount;
            }
            return;
        }

        enemy.drawBodyThisFrame = true;
        const int timer = enemy.helperTimer;
        const float centerX = parent->x + enemy.originX;
        const float centerY = parent->y + enemy.originY;
        const double phase = static_cast<double>(timer) * kTau / 144.0;
        int orbitAngle = static_cast<int>(enemy.secondaryAngle16) +
                         static_cast<int>(std::sin(phase) * 1200.0);
        int tipAngle = orbitAngle +
                       static_cast<int>(std::sin(phase - kPi * 0.5) * 1200.0) +
                       7000;
        if (enemy.originX < 0.0f) {
            orbitAngle = static_cast<int>(enemy.secondaryAngle16) -
                         static_cast<int>(std::sin(phase) * 1200.0);
            tipAngle = orbitAngle -
                       static_cast<int>(std::sin(phase - kPi * 0.5) * 1200.0) -
                       7000;
        }
        if (parent->helperState == 3) {
            const int deathTimer = parent->helperTimer;
            const int sign = enemy.originX < 0.0f ? -1 : 1;
            orbitAngle += sign * deathTimer * 100;
            tipAngle += sign * deathTimer * 60;
        }
        enemy.sourceAngle16 = normalizeStage08Angle(orbitAngle);
        enemy.targetAngle16 = normalizeStage08Angle(tipAngle);
        const double radians = stage08AngleRadians(enemy.sourceAngle16);
        const double radius = enemy.spawnType == 0xa5 ? 150.0 : 90.0;
        enemy.x = centerX + static_cast<float>(std::cos(radians) * radius);
        enemy.y = centerY + static_cast<float>(std::sin(radians) * radius);

        const int retreatStart = selectedStage_ == 9 ? 1200 : 2000;
        if (parent->helperState == 1 && parent->age < retreatStart) {
            if (enemy.spawnType == 0xa5) {
                static constexpr std::array<int, 5> kStart{{90, 80, 70, 70, 70}};
                static constexpr std::array<int, 5> kStep{{60, 40, 30, 30, 30}};
                static constexpr std::array<double, 5> kSpeed{{
                    5.4, 6.4, 7.0, 7.0, 8.0,
                }};
                const int local =
                    (timer - kStart[static_cast<std::size_t>(difficulty)]) % 240;
                if (timer >= kStart[static_cast<std::size_t>(difficulty)] &&
                    local >= 0 && local < 120) {
                    const int step = kStep[static_cast<std::size_t>(difficulty)];
                    const int lane = local % (step * 2);
                    const double speed =
                        kSpeed[static_cast<std::size_t>(difficulty)] +
                        static_cast<double>(local % step) * 0.1;
                    if (lane < 30 && lane % 4 == 0) {
                        if (local == 0) {
                            enemy.markerDrawTimer = static_cast<int>(
                                aimFrom(enemy.x, enemy.y));
                        }
                        spawnProjectileSpread(7, 0, enemy.x, enemy.y,
                                              normalizeStage08Angle(
                                                  enemy.markerDrawTimer), 10.0f,
                                              speed, 1, 5, 20000, 0);
                        if (difficulty > 2) {
                            spawnProjectileSpread(7, 0, enemy.x, enemy.y,
                                                  normalizeStage08Angle(
                                                      enemy.markerDrawTimer), 10.0f,
                                                  speed + 1.5, 1, 5, 20000, 0);
                        }
                    }
                    const int alternate = (local - step) % (step * 2);
                    if (local >= step && alternate >= 0 && alternate < 30 &&
                        alternate % 4 == 0) {
                        spawnProjectileSpread(7, 0, enemy.x, enemy.y,
                                              normalizeStage08Angle(
                                                  enemy.markerDrawTimer), 10.0f,
                                              speed, 1, 4, 15000, 0);
                        if (difficulty > 2) {
                            spawnProjectileSpread(7, 0, enemy.x, enemy.y,
                                                  normalizeStage08Angle(
                                                      enemy.markerDrawTimer), 10.0f,
                                                  speed + 1.5, 1, 4, 15000, 0);
                        }
                    }
                }
            }
            else {
                static constexpr std::array<int, 5> kCadence{{18, 13, 11, 11, 11}};
                static constexpr std::array<int, 5> kLayers{{2, 4, 5, 3, 4}};
                static constexpr std::array<int, 5> kCount{{1, 1, 1, 2, 2}};
                static constexpr std::array<double, 5> kSpeed{{
                    4.0, 4.0, 4.0, 5.0, 6.0,
                }};
                if (timer > 120 && timer < retreatStart &&
                    (timer - 120) %
                            kCadence[static_cast<std::size_t>(difficulty)] ==
                        0) {
                    const int layers =
                        kLayers[static_cast<std::size_t>(difficulty)];
                    const int count =
                        kCount[static_cast<std::size_t>(difficulty)];
                    const int sign = enemy.originX < 0.0f ? -1 : 1;
                    for (int layer = 0; layer < layers; ++layer) {
                        const double speed =
                            kSpeed[static_cast<std::size_t>(difficulty)] + layer;
                        const int offset = layer * 800;
                        const auto first = normalizeStage08Angle(
                            static_cast<int>(enemy.targetAngle16) +
                            sign * (offset - 0x4038));
                        const auto second = normalizeStage08Angle(
                            static_cast<int>(enemy.targetAngle16) -
                            sign * (offset - 0x4038));
                        spawnProjectileSpread(0x0c, 0, enemy.x, enemy.y,
                                              first, 10.0f, speed, 1,
                                              count, 9000, 0);
                        spawnProjectileSpread(0x0c, 0, enemy.x, enemy.y,
                                              second, 10.0f, speed, 1,
                                              count, 9000, 0);
                    }
                }
            }
        }

        if (parent->helperState == 2 && enemy.spawnType == 0xa5) {
            static constexpr std::array<int, 5> kPeriod{{
                180, 140, 130, 120, 120,
            }};
            static constexpr std::array<int, 5> kCadence{{16, 12, 10, 9, 8}};
            static constexpr std::array<int, 5> kSpreadStep{{
                1600, 2400, 2700, 3000, 3000,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                7.0, 8.0, 9.0, 10.0, 11.0,
            }};
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int local = (parent->helperTimer - 60) % period;
            double speed = kSpeed[static_cast<std::size_t>(difficulty)] -
                           static_cast<double>(local) * 0.03;
            if (parent->helperTimer > 60 && local == 0) {
                enemy.markerDrawTimer = static_cast<int>(
                    aimFrom(enemy.x, enemy.y));
            }
            if (parent->helperTimer > 60 && local >= 0 && local < 64 &&
                local % 3 == 0) {
                const int spread =
                    (kSpreadStep[static_cast<std::size_t>(difficulty)] / 75) *
                    local;
                for (const int angleOffset : {0, 10000, -10000}) {
                    spawnProjectileSpread(
                        9, 0, enemy.x, enemy.y,
                        normalizeStage08Angle(
                            enemy.markerDrawTimer +
                            angleOffset),
                        10.0f, speed, 1, 2, spread, 0);
                }
            }
            const int cadence =
                kCadence[static_cast<std::size_t>(difficulty)];
            if (parent->helperTimer > 60 && local >= 0 && local < 70 &&
                local % cadence == 0) {
                const int spread = local * 142;
                for (const int angleOffset : {0, 10000, -10000}) {
                    const auto angle = normalizeStage08Angle(
                        enemy.markerDrawTimer + angleOffset);
                    spawnProjectileSpread(8, 0, enemy.x, enemy.y,
                                          angle, 10.0f, speed - 2.0,
                                          1, 2, spread, 0);
                    if (difficulty > 0 && local < 50) {
                        spawnProjectileSpread(8, 0, enemy.x, enemy.y,
                                              angle, 10.0f, speed - 1.0,
                                              1, 2, local * 200, 0);
                    }
                }
            }
        }

        if (enemy.hp < parent->hp) {
            parent->hp -= parent->hp - enemy.hp;
        }
        else if (enemy.hp > parent->hp) {
            enemy.hp = parent->hp;
        }
        enemy.drawHp = parent->drawHp;
        if (enemy.spawnType == 0xa6 &&
            parent->hp <= static_cast<int>(parent->maxHp * 0.4)) {
            spawnEnemyDeathRewardBurst(enemy, 0x960, false);
            spawnEnemyDeathEffects(enemy, 1);
            enemy.targetable = false;
            enemy.active = false;
            if (parent->liveChildCount > 0) --parent->liveChildCount;
            return;
        }
        if (parent->hp < 1 || parent->helperState == 3) {
            enemy.targetable = false;
        }
        else {
            enemy.targetable = true;
        }
        return;
    }
}

bool StageRuntime::drawStage08Enemy(const StageEnemy& enemy, float x,
                                    float y) const {
    if (!isStage08EnemyType(enemy.spawnType)) return false;

    const auto draw = [this](const std::vector<int>& frames, int frame,
                             float drawX, float drawY,
                             std::uint16_t angle = 0,
                             double scaleX = 1.0,
                             double scaleY = 1.0,
                             bool reverse = false) {
        const int handle = stage08Frame(frames, frame);
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle,
                                  scaleX, scaleY, reverse);
        }
    };
    const auto drawMarker = [this, &enemy, x, y](double initial,
                                                  double decay) {
        if (!enemy.drawMarkerThisFrame) return;
        const int handle = stage08Frame(effectMediumFrames_, 4);
        if (handle == -1) return;
        const double scale = std::max(
            0.0, initial - static_cast<double>(enemy.markerDrawTimer) * decay);
        const float drawX = x + enemy.markerDrawX - enemy.x;
        const float drawY = y + enemy.markerDrawY - enemy.y;
        DrawRotaGraphF(drawX, drawY, scale, 0.0, handle, TRUE);
    };

    const int timer = enemy.drawHelperTimer;
    if (enemy.spawnType == 0x97 || enemy.spawnType == 0x98 ||
        enemy.spawnType == 0x99) {
        drawMarker(2.0, 0.1);
    }
    else if (isStage08CompositeRoot(enemy.spawnType)) {
        drawMarker(3.0, 0.15);
    }
    else if (enemy.spawnType == 0xa4) {
        drawMarker(4.0, 0.2);
    }
    if (!enemy.drawBodyThisFrame) return true;

    if (enemy.spawnType == 0x95) { // Enemy_s[119..124]
        const float top = static_cast<float>(
            5.0 - std::sin(timer * kTau / 60.0) * 10.0);
        const float mirroredTop = static_cast<float>(
            5.0 - std::sin((timer - 30) * kTau / 60.0) * 10.0);
        const float center = static_cast<float>(
            5.0 - std::sin(timer * kTau / 30.0) * 2.0);
        const float lower = static_cast<float>(
            -12.0 - std::sin((timer - 12) * kTau / 30.0) * 2.0);
        const float rear = static_cast<float>(
            -7.0 - std::sin((timer - 6) * kTau / 30.0) * 2.0);
        draw(enemySmallFrames_, 122, x, y + lower);
        draw(enemySmallFrames_, 119, x, y + top);
        draw(enemySmallFrames_, 119, x, y + mirroredTop, 0, 1.0, 1.0, true);
        draw(enemySmallFrames_, 120, x, y + center);
        draw(enemySmallFrames_, 121, x, y + lower);
        draw(enemySmallFrames_, 123, x, y + rear);
        SetDrawBlendMode(DX_BLENDMODE_ADD, 64);
        draw(enemySmallFrames_, 124, x, y + 5.0f);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    else if (enemy.spawnType == 0x96) { // Enemy_s[125..128]
        const float first = static_cast<float>(
            -std::sin(timer * kTau / 80.0));
        const float second = static_cast<float>(
            -std::sin((timer - 9) * kTau / 80.0));
        const double phase = enemy.drawHelperState == 0
                                 ? std::sin(std::min(timer, 20) * kPi / 40.0)
                                 : 0.0;
        const double scaleX = 1.0 + phase;
        const double scaleY = 1.0 - phase;
        draw(enemySmallFrames_, 127, x, y, 0, scaleX, scaleY);
        draw(enemySmallFrames_, 126, x, y + first,
             0, scaleX, scaleY);
        draw(enemySmallFrames_, 125, x, y + second,
             0, scaleX, scaleY);
        if (enemy.drawHelperState == 0) {
            const double fade = std::clamp(1.0 - phase, 0.0, 1.0);
            SetDrawBlendMode(DX_BLENDMODE_ADD,
                             static_cast<int>(fade * 255.0));
            draw(enemySmallFrames_, 127, x, y, 0, scaleX, scaleY);
            draw(enemySmallFrames_, 126, x, y + first,
                 0, scaleX, scaleY);
            draw(enemySmallFrames_, 125, x, y + second,
                 0, scaleX, scaleY);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        SetDrawBlendMode(DX_BLENDMODE_ADD, 64);
        draw(enemySmallFrames_, 128, x, y + 5.0f);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    else if (enemy.spawnType >= 0x97 && enemy.spawnType <= 0x99) {
        // Enemy_s[129..131]
        const double radians = stage08AngleRadians(enemy.secondaryAngle16);
        const float mountX = static_cast<float>(std::cos(radians) * 30.0);
        const float mountY = static_cast<float>(std::sin(radians) * 30.0);
        draw(enemySmallFrames_, 130, x + mountX, y + mountY - 15.0f,
             enemy.secondaryAngle16);
        draw(enemySmallFrames_, 130, x - mountX, y - mountY - 15.0f,
             normalizeStage08Angle(
                 static_cast<int>(enemy.secondaryAngle16) + 0x8000),
             1.0, 1.0, true);
        draw(enemySmallFrames_, 129, x, y + 10.0f);
        draw(enemySmallFrames_, 130, x + mountX, y + mountY + 35.0f,
             enemy.secondaryAngle16);
        draw(enemySmallFrames_, 130, x - mountX, y - mountY + 35.0f,
             normalizeStage08Angle(
                 static_cast<int>(enemy.secondaryAngle16) + 0x8000),
             1.0, 1.0, true);
        draw(enemySmallFrames_, 131, x, y - 30.0f,
             enemy.targetAngle16);
        SetDrawBlendMode(DX_BLENDMODE_ADD, 64);
        draw(enemySmallFrames_, 129, x, y + 18.0f);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    else if (enemy.spawnType == 0x9a) {
        draw(enemyLargeFrames_, 52, x, y + 50.0f);
    }
    else if (isStage08CompositeRoot(enemy.spawnType)) {
        static constexpr std::array<int, 4> kType9b{{150, 151, 152, 151}};
        static constexpr std::array<int, 4> kType9e{{153, 154, 155, 154}};
        static constexpr std::array<int, 4> kTypea1{{156, 157, 158, 157}};
        int frame = 150;
        if (enemy.spawnType == 0x9b || enemy.spawnType == 0x9c) {
            frame = stage08AnimationFrame(timer, 5, kType9b);
        }
        else if (enemy.spawnType == 0x9e || enemy.spawnType == 0x9f) {
            frame = stage08AnimationFrame(timer, 5, kType9e);
        }
        else {
            frame = stage08AnimationFrame(timer, 5, kTypea1);
        }
        draw(enemyMediumFrames_, frame, x, y);
        if (enemy.spawnType == 0x9c || enemy.spawnType == 0x9f ||
            enemy.spawnType == 0xa2) {
            const int alpha = static_cast<int>(
                128.0 + std::sin(timer * kTau / 64.0) * 128.0);
            SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(alpha, 0, 255));
            draw(enemyMediumFrames_, frame, x, y);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
    }
    else if (enemy.spawnType == 0x9d) {
        static constexpr std::array<int, 5> kFrames{{90, 91, 92, 93, 94}};
        draw(playerFrames_, stage08AnimationFrame(frame_, 6, kFrames),
             x, y, enemy.sourceAngle16);
    }
    else if (enemy.spawnType == 0xa0) {
        static constexpr std::array<int, 4> kFrames{{132, 133, 134, 133}};
        draw(enemySmallFrames_, stage08AnimationFrame(frame_, 6, kFrames),
             x, y, enemy.sourceAngle16);
    }
    else if (enemy.spawnType == 0xa3) {
        static constexpr std::array<int, 5> kFrames{{98, 99, 100, 101, 102}};
        draw(playerFrames_, stage08AnimationFrame(frame_, 6, kFrames),
             x, y,
             normalizeStage08Angle(
                 static_cast<int>(enemy.sourceAngle16) - 0x8000));
    }
    else if (enemy.spawnType == 0xa4) { // Enemy_m[145..149]
        const float bob0 = static_cast<float>(
            std::sin(timer * kTau / 88.0) * 2.0);
        const float bob1 = static_cast<float>(
            std::sin((timer - 32) * kTau / 88.0) * 2.0);
        const auto wingAngle = normalizeStage08Angle(
            static_cast<int>(std::sin(timer * kTau / 88.0) * 1536.0));
        draw(enemyMediumFrames_, 145, x, y + bob0);
        draw(enemyMediumFrames_, 146, x + 6.0f, y + bob0 + 10.0f,
             wingAngle);
        draw(enemyMediumFrames_, 146, x - 6.0f, y + bob0 + 10.0f,
             normalizeStage08Angle(-static_cast<int>(wingAngle)),
             1.0, 1.0, true);
        draw(enemyMediumFrames_, 147, x, y + bob0);
        draw(enemyMediumFrames_, 148, x, y + bob1);
        draw(enemyMediumFrames_, 149, x, y + bob1);
    }
    else if (enemy.spawnType == 0xa5 || enemy.spawnType == 0xa6) {
        const int segmentCount = enemy.spawnType == 0xa5 ? 8 : 5;
        const double radians = stage08AngleRadians(enemy.sourceAngle16);
        for (int index = segmentCount - 1; index >= 0; --index) {
            const float distance = 20.0f + static_cast<float>(index) * 30.0f;
            const float segmentX = x -
                static_cast<float>(std::cos(radians) * distance);
            const float segmentY = y -
                static_cast<float>(std::sin(radians) * distance);
            const double alphaScale =
                0.75 + static_cast<double>(index) * 0.02;
            draw(enemyMediumFrames_, 159, segmentX, segmentY,
                 enemy.sourceAngle16, alphaScale, 1.0,
                 enemy.originX < 0.0f);
        }
        if (enemy.spawnType == 0xa5) {
            draw(enemyMediumFrames_, 160, x, y,
                 enemy.sourceAngle16, 1.0, 1.0,
                 enemy.originX < 0.0f);
        }
        else {
            draw(enemyMediumFrames_, 162, x, y,
                 enemy.sourceAngle16, 1.0, 1.0,
                 enemy.originX < 0.0f);
        }
        const double tipRadians = stage08AngleRadians(enemy.targetAngle16);
        draw(enemyMediumFrames_, 161,
             x + static_cast<float>(std::cos(tipRadians) * 28.0),
             y + static_cast<float>(std::sin(tipRadians) * 28.0),
             enemy.targetAngle16, 1.0, 1.0,
             enemy.originX < 0.0f);
    }

    if (enemy.targetable && !isStage08CompositeChild(enemy.spawnType) &&
        !isStage08CarrierChild(enemy.spawnType)) {
        StageEnemy gauge = enemy;
        gauge.hp = enemy.drawHp;
        int mode = 2;
        if (isStage08CompositeRoot(enemy.spawnType)) mode = 1;
        if (enemy.spawnType == 0x9a || enemy.spawnType == 0xa4) mode = 0;
        drawEnemyGaugeExact(gauge, mode, x, y);
    }
    return true;
}

} // namespace reconstructed
