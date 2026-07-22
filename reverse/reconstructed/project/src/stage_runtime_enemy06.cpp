#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>

namespace reconstructed {
namespace {

constexpr double kPi = 3.14159265358979323846;
constexpr double kTau = kPi * 2.0;

std::uint16_t s06Angle(int value) {
    return static_cast<std::uint16_t>(value & 0xffff);
}

double s06Radians(std::uint16_t angle) {
    return static_cast<double>(angle) * kTau / 65536.0;
}

std::uint16_t s06Aim(float fromX, float fromY, float toX, float toY) {
    const double radians = std::atan2(static_cast<double>(toY - fromY),
                                      static_cast<double>(toX - fromX));
    return s06Angle(static_cast<int>(radians * 65536.0 / kTau));
}

int s06Delta(std::uint16_t from, std::uint16_t to) {
    int delta = static_cast<int>(to) - static_cast<int>(from);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return delta;
}

std::uint16_t s06Approach(std::uint16_t from, std::uint16_t to, int step) {
    const int delta = s06Delta(from, to);
    if (std::abs(delta) <= step) return to;
    return s06Angle(static_cast<int>(from) + (delta < 0 ? -step : step));
}

void s06ClampEntry(float& x, float& y, float horizontalOrigin,
                   float signedMargin) {
    x = std::clamp(x, horizontalOrigin + signedMargin,
                   horizontalOrigin + 600.0f - signedMargin);
    y = std::clamp(y, signedMargin, 720.0f - signedMargin);
}

int s06Frame(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

} // namespace

bool StageRuntime::isStage06EnemyType(int spawnType) const {
    return spawnType >= 0x57 && spawnType <= 0x60;
}

bool StageRuntime::spawnStage06EnemyNode(StageEnemy& parent, int childIndex,
                                         std::uint16_t angle16) {
    if (enemies_.size() + pendingEnemies_.size() >= 0x200) return false;

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = 0x60;
    child.updateCase = 0x48;
    child.sourceDispatchKind = 1;
    child.sourceDispatchField = 25;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = childIndex;
    child.x = parent.x;
    child.y = parent.y + 35.0f;
    child.originX = child.x;
    child.originY = child.y;
    child.sourceX = static_cast<int>(child.x);
    child.sourceY = static_cast<int>(child.y);
    child.sourceAngle16 = angle16;
    child.secondaryAngle16 = angle16;
    child.hp = 99999999;
    child.maxHp = child.hp;
    child.drawHp = child.hp;
    child.radius = 25;
    child.rewardWeight = 1;
    child.activationDelay = 0;
    child.targetable = false;
    child.sourceNote = "S06 FUN_1400a1730 timer 90 child 0x60";
    pendingEnemies_.push_back(child);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage06Enemy(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    const float dispatchDelta =
        static_cast<float>(std::clamp(timeWindowDispatchCount_, 1, 4));

    const auto aimPlayer = [this, &enemy]() {
        return s06Aim(enemy.x, enemy.y, player_.x, player_.y);
    };

    if (enemy.spawnType == 0x60) { // FUN_1400a1df0
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || !parent->active || parent->hp < 1) {
            // FUN_1400a1df0 runs its owner-HP tail even when the owner lookup
            // failed, and calls FUN_140079e20(child, 0) before unlinking.
            spawnEnemyDeathEffects(enemy, 0);
            if (parent != nullptr && parent->liveChildCount > 0) {
                --parent->liveChildCount;
            }
            enemy.active = false;
            return;
        }

        const int timer = enemy.helperTimer;
        enemy.originY += dispatchDelta;
        const int unfoldTimer = std::min(timer, 120);
        const int riseTimer = std::min(timer, 180);
        const float radiusX = static_cast<float>(static_cast<int>(
            std::sin(unfoldTimer * kPi / 240.0) * 90.0));
        const float radiusY = static_cast<float>(static_cast<int>(
            std::sin(unfoldTimer * kPi / 240.0) * 50.0));
        const float rise = static_cast<float>(static_cast<int>(
            std::sin(riseTimer * kPi / 360.0) * -120.0));
        const int turn = static_cast<int>(
            std::sin(static_cast<double>(frame_) * kTau / 470.0) * 130.0);
        enemy.secondaryAngle16 = s06Angle(
            static_cast<int>(enemy.secondaryAngle16) - turn);
        const double radians = s06Radians(enemy.secondaryAngle16);
        enemy.x = enemy.originX +
                  static_cast<float>(std::cos(radians) * radiusX);
        enemy.y = enemy.originY + rise +
                  static_cast<float>(std::sin(radians) * radiusY);
        enemy.drawBodyThisFrame = true;
        if (enemy.y >= 760.0f) enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0x57 || enemy.spawnType == 0x58) { // FUN_14009d610
        if (enemy.helperState == 0) {
            if (enemy.helperTimer == 0) {
                enemy.sourceAngle16 = enemy.spawnType == 0x57 ? 0x58f0 : 0x2710;
            }
            const double projection = -static_cast<double>(enemy.y) * 0.8;
            float markerX = enemy.x + static_cast<float>(
                std::cos(s06Radians(enemy.sourceAngle16)) * projection);
            float markerY = enemy.y + static_cast<float>(
                std::sin(s06Radians(enemy.sourceAngle16)) * projection);
            s06ClampEntry(markerX, markerY, player_.x / 6.0f, -50.0f);
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = markerX;
            enemy.markerDrawY = markerY;
            if (enemy.helperTimer < 20) return;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.sourceSpeed = 9.0;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }

        const int timer = enemy.helperTimer;
        const auto aimed = aimPlayer();
        if (timer < 100) {
            if (timer <= 100 && enemy.sourceSpeed > 0.0) enemy.sourceSpeed -= 0.09;
            enemy.sourceAngle16 = s06Approach(enemy.sourceAngle16, aimed, 0x20);
        }
        else if (timer < 240) {
            if (timer == 100) enemy.sourceAngle16 = aimed;
            if (timer < 130) enemy.sourceSpeed += 0.05;
            enemy.sourceAngle16 = s06Approach(enemy.sourceAngle16, aimed, 0x80);
        }
        else {
            enemy.sourceSpeed -= 0.1;
        }
        const double radians = s06Radians(enemy.sourceAngle16);
        enemy.vx = static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.vy = static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        return;
    }

    if (enemy.spawnType == 0x59) { // FUN_14009e3d0
        if (enemy.helperState == 0) {
            float markerX = enemy.x;
            float markerY = enemy.y;
            s06ClampEntry(markerX, markerY, player_.x / 6.0f, -50.0f);
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = markerX;
            enemy.markerDrawY = markerY;
            if (enemy.helperTimer < 20) return;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.originX = 360.0f;
            enemy.originY = enemy.y;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }

        const int timer = enemy.helperTimer;
        enemy.markerDrawX = enemy.x;
        enemy.markerDrawY = enemy.y;
        enemy.sourceAngle16 = s06Angle(static_cast<int>(
            std::sin(timer * kTau / 67.0) * 1024.0));
        enemy.targetAngle16 = s06Angle(static_cast<int>(
            std::sin(timer * kTau / 23.0) * 2048.0));
        float amplitude = 160.0f;
        if (timer < 118) {
            amplitude = static_cast<float>(
                std::sin(timer * kTau / 472.0) * -300.0 + 460.0);
        }
        if (enemy.sourceX <= 360 && enemy.sourceX != 360) amplitude = -amplitude;
        if (timer > 300) {
            enemy.sourceSpeed += 0.1;
            enemy.originY -= static_cast<float>(enemy.sourceSpeed);
        }
        enemy.x = enemy.originX + static_cast<float>(
            std::sin((timer + 59) * kTau / 236.0) * amplitude);
        enemy.y = enemy.originY + static_cast<float>(
            std::sin(timer * kTau / 172.0) * -70.0);
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        return;
    }

    if (enemy.spawnType == 0x5a) { // FUN_14009eca0
        enemy.originY += dispatchDelta;
        if (enemy.helperState == 0) {
            enemy.x = enemy.originX;
            enemy.y = enemy.originY;
            if (enemy.originY < -80.0f) return;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        const int timer = enemy.helperTimer;
        if (!enemy.targetable && enemy.originY >= 0.0f) enemy.targetable = true;
        enemy.x = enemy.originX + static_cast<float>(
            std::sin((timer - enemy.entityId * 7) * kTau / 53.0) * 2.0);
        enemy.y = enemy.originY + static_cast<float>(
            std::sin((timer - enemy.entityId * 11) * kTau / 73.0) * 2.0);
        const auto aimed = aimPlayer();
        const int turn = std::abs(s06Delta(enemy.sourceAngle16, aimed)) / 10 + 0x30;
        enemy.sourceAngle16 = s06Approach(enemy.sourceAngle16, aimed, turn);
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        return;
    }

    if (enemy.spawnType == 0x5b || enemy.spawnType == 0x5c) { // FUN_14009f5d0
        enemy.y += dispatchDelta;
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y;
            if (enemy.helperTimer < 20) return;
            const bool left = enemy.originX <= 360.0f;
            enemy.sourceAngle16 = enemy.spawnType == 0x5b
                                      ? (left ? 0x0000 : 0x8000)
                                      : (left ? 0xe0c0 : 0x9f40);
            enemy.sourceSpeed = 1.5;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        if (!enemy.targetable) {
            const float horizontalOrigin = player_.x / 6.0f;
            if (enemy.x >= horizontalOrigin - 20.0f &&
                enemy.x <= horizontalOrigin + 620.0f &&
                enemy.y >= -20.0f && enemy.y <= 740.0f) {
                enemy.targetable = true;
            }
        }
        if (enemy.spawnType == 0x5c) {
            enemy.sourceAngle16 = s06Angle(static_cast<int>(enemy.sourceAngle16) +
                                           (enemy.originX <= 360.0f ? 0x13 : -0x12));
        }
        const double radians = s06Radians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        return;
    }

    if (enemy.spawnType == 0x5d) { // FUN_1400a0220
        enemy.y += dispatchDelta;
        if (enemy.helperState == 0) {
            if (enemy.y < -100.0f) return;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        if (enemy.helperTimer == 60) enemy.targetable = true;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        return;
    }

    if (enemy.spawnType == 0x5e) { // FUN_1400a0e90
        enemy.originY += dispatchDelta;
        if (enemy.helperState == 0) {
            enemy.x = enemy.originX;
            enemy.y = enemy.originY;
            if (enemy.originY < -140.0f) return;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        const int timer = enemy.helperTimer;
        if (!enemy.targetable && enemy.originY >= -40.0f) enemy.targetable = true;
        enemy.x = enemy.originX + static_cast<float>(
            std::sin((timer - enemy.entityId * 7) * kTau / 83.0) * 3.0);
        enemy.y = enemy.originY + static_cast<float>(
            std::sin((timer - enemy.entityId * 11) * kTau / 100.0) * 3.0);
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        return;
    }

    if (enemy.spawnType == 0x5f) { // FUN_1400a1730
        enemy.y += dispatchDelta;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 0) {
            if (enemy.y < -100.0f) return;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        if (enemy.helperState == 1) {
            if (enemy.helperTimer == 80) enemy.targetable = true;
            if (enemy.helperTimer == 90) {
                static constexpr std::array<int, 5> kCount{{5, 5, 7, 7, 9}};
                const int count = kCount[static_cast<std::size_t>(
                    std::clamp(config_.difficulty, 0, 4))];
                for (int i = 0; i < count; ++i) {
                    spawnStage06EnemyNode(
                        enemy, i, s06Angle(i * (0x10000 / count) - 0x4000));
                }
                playPlayerSound(bossSe1SoundHandle_, 0x19);
            }
            if (enemy.hp < 1) {
                spawnEnemyDeathRewardBurst(enemy, 0x708, false);
                spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
                enemy.helperState = 2;
                enemy.helperTimer = 0;
                enemy.targetable = false;
            }
        }
        else if (enemy.helperState == 2) {
            // FUN_1400a1730 keeps the body for a 60-frame death state and
            // feeds FUN_14007ac00 through timer 60. The final mode-2 effect is
            // emitted on timer 60, rather than at death entry.
            if (enemy.helperTimer < 61) {
                spawnStage02DeathExplosionChain(enemy);
            }
            if (enemy.helperTimer == 60) {
                spawnEnemyDeathEffects(enemy, 2);
                enemy.active = false;
            }
        }
        if (enemy.y >= 960.0f) enemy.active = false;
    }
}

void StageRuntime::emitStage06EnemyProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const std::size_t d = static_cast<std::size_t>(difficulty);
    const int timer = enemy.helperTimer;
    const auto aim = [this](float x, float y) {
        return s06Aim(x, y, player_.x, player_.y);
    };
    const auto finish = [this, &enemy](int reward, int mode) {
        spawnEnemyDeathRewardBurst(enemy, reward, false);
        spawnEnemyDeathEffects(enemy, mode);
        enemy.targetable = false;
        enemy.active = false;
    };
    const auto outside128 = [this, &enemy]() {
        const float origin = player_.x / 6.0f;
        return enemy.x < origin - 128.0f || enemy.x > origin + 728.0f ||
               enemy.y < -128.0f || enemy.y > 848.0f;
    };

    if (enemy.spawnType == 0x57 || enemy.spawnType == 0x58) {
        if (enemy.helperState != 1) return;
        static constexpr std::array<int, 5> kCadence{{47, 19, 15, 15, 10}};
        static constexpr std::array<int, 5> kCount{{3, 5, 7, 9, 13}};
        static constexpr std::array<double, 5> kFanSpeed{{5.2, 6.0, 6.5, 6.5, 7.5}};
        static constexpr std::array<double, 5> kOrbitSpeed{{3.6, 4.5, 5.0, 5.0, 6.0}};
        const bool onScreen = enemy.x >= player_.x / 6.0f &&
                              enemy.x <= player_.x / 6.0f + 600.0f &&
                              enemy.y >= 0.0f && enemy.y <= 720.0f;
        if (timer < 240 && timer >= 40 && (timer - 40) % 160 == 0 && onScreen) {
            const auto center = aim(enemy.x, enemy.y + 30.0f);
            const int count = kCount[d];
            spawnProjectileSpread(5, 0, enemy.x, enemy.y + 30.0f, center,
                                  0.0f, kFanSpeed[d], 1, count,
                                  (count - 1) * 500, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(5, 0, enemy.x, enemy.y + 30.0f, center,
                                      0.0f, kFanSpeed[d] + 1.1, 1, count,
                                      (count - 1) * 500, 0);
            }
        }
        for (int source = 0; source < 3; ++source) {
            const auto orbit = s06Angle(frame_ * 0x29a + source * 0x5555);
            const double radians = s06Radians(orbit);
            const float x = enemy.x + static_cast<float>(std::cos(radians) * 36.0);
            const float y = enemy.y + 20.0f +
                            static_cast<float>(std::sin(radians) * 20.0);
            const int start = 60 + source * kCadence[d];
            if (!onScreen || timer < start || timer >= 240) continue;
            const int local = (timer - start) % 160;
            if (local >= 120 || local % (kCadence[d] * 4) != 0) continue;
            const auto center = aim(x, y);
            spawnProjectileNode(0, 0, x, y, center, 0.0f, kOrbitSpeed[d], 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(0, 0, x, y,
                                    s06Angle(static_cast<int>(center) - 0x92e),
                                    0.0f, kOrbitSpeed[d] - 0.3, 1, 0);
                spawnProjectileNode(0, 0, x, y,
                                    s06Angle(static_cast<int>(center) + 0x92e),
                                    0.0f, kOrbitSpeed[d] - 0.3, 1, 0);
            }
        }
        if (enemy.hp < 1) finish(500, 1);
        else if (timer > 119 && outside128()) enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0x59) {
        if (enemy.helperState != 1) return;
        static constexpr std::array<int, 5> kPeriod{{180, 140, 100, 90, 70}};
        static constexpr std::array<int, 5> kStep{{50, 33, 27, 24, 18}};
        static constexpr std::array<int, 5> kBaseCount{{3, 3, 5, 5, 7}};
        static constexpr std::array<int, 5> kScale{{1, 3, 3, 3, 1}};
        static constexpr std::array<int, 5> kSpread{{5000, 3000, 2500, 2200, 1900}};
        static constexpr std::array<double, 5> kSpeed{{3.8, 4.5, 5.0, 6.0, 7.2}};
        if (timer >= 50 && timer < 300) {
            const double radians = s06Radians(enemy.sourceAngle16);
            const float x = enemy.x + static_cast<float>(std::cos(radians) * 15.0);
            const float y = enemy.y + static_cast<float>(std::sin(radians) * 15.0);
            const int local = (timer - 50) % kPeriod[d];
            if (local == 0) enemy.secondaryAngle16 = aim(x, y);
            if (local < kStep[d] * 3 && local % kStep[d] == 0) {
                const int count = kBaseCount[d] + (local / kStep[d]) * kScale[d];
                spawnProjectileSpread(5, 0, x, y, enemy.secondaryAngle16,
                                      0.0f, kSpeed[d] + local * 0.007, 1,
                                      count, (count - 1) * kSpread[d], 0);
            }
        }
        if (enemy.hp < 1) finish(500, 1);
        else if (timer > 119 && outside128()) enemy.active = false;
        return;
    }

    if (enemy.helperState != 1 && enemy.spawnType != 0x60) return;

    if (enemy.spawnType == 0x5a) {
        static constexpr std::array<int, 5> kCadence{{77, 48, 36, 36, 32}};
        static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 6.6, 6.6, 7.7}};
        const double heading = s06Radians(enemy.sourceAngle16);
        const float x = enemy.x + static_cast<float>(std::cos(heading) * 8.0);
        const float y = enemy.y + static_cast<float>(std::sin(heading) * 8.0) + 7.0f;
        if (enemy.originY < 400.0f) {
            const auto aimed = aim(x, y);
            if (timer > 69) {
                const int local = (timer - 70) % kCadence[d];
                if (local == 0) enemy.secondaryAngle16 = aimed;
                if (local < 12 && local % 4 == 0) {
                    spawnProjectileNode(4, 0, x, y, enemy.secondaryAngle16,
                                        0.0f, kSpeed[d], 1, 0);
                }
                if (difficulty > 2 && timer > 89 &&
                    (timer - 90) % kCadence[d] == 0) {
                    spawnProjectileNode(5, 0, x, y,
                                        s06Angle(static_cast<int>(enemy.secondaryAngle16) - 800),
                                        0.0f, kSpeed[d] + 0.5, 1, 0);
                    spawnProjectileNode(5, 0, x, y,
                                        s06Angle(static_cast<int>(enemy.secondaryAngle16) + 800),
                                        0.0f, kSpeed[d] + 0.5, 1, 0);
                }
            }
            enemy.secondaryAngle16 = s06Approach(
                enemy.secondaryAngle16, aimed, 0x40);
        }
        if (enemy.hp < 1) finish(1000, 0);
        else if (enemy.y >= 760.0f) enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0x5b || enemy.spawnType == 0x5c) {
        static constexpr std::array<int, 5> kCadence{{44, 21, 15, 9, 7}};
        static constexpr std::array<double, 5> kSpeed{{4.5, 5.0, 5.5, 5.5, 7.0}};
        const float wave = static_cast<float>(
            std::sin((timer % 50) * kPi / 50.0) * -10.0);
        const float x = enemy.x;
        const float y = enemy.y + wave - 5.0f;
        if (y < 360.0f && timer >= 0) {
            const int local = timer % (kCadence[d] * 5);
            const float dx = player_.x - x;
            const float dy = player_.y - y;
            if (local < kCadence[d] * 3 && local % kCadence[d] == 0 &&
                dx * dx + dy * dy > 2500.0f) {
                const auto snapped = s06Angle(
                    ((static_cast<int>(aim(x, y)) + 0x400) >> 11) * 0x800);
                spawnProjectileNode(1, 0, x, y, snapped, 0.0f,
                                    kSpeed[d], 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(1, 0, x, y, snapped, 0.0f,
                                        kSpeed[d] + 1.5, 1, 0);
                }
            }
        }
        if (enemy.hp < 1) finish(1000, 0);
        else if (enemy.targetable) {
            const float origin = player_.x / 6.0f;
            if (enemy.x < origin - 100.0f || enemy.x > origin + 700.0f ||
                enemy.y < -100.0f || enemy.y > 820.0f) enemy.active = false;
        }
        return;
    }

    if (enemy.spawnType == 0x5d) {
        static constexpr std::array<int, 5> kCadence{{180, 100, 80, 70, 50}};
        static constexpr std::array<double, 5> kSpeed{{5.5, 6.5, 7.5, 6.5, 8.0}};
        const float wave = static_cast<float>(std::sin(timer * kTau / 55.0) * 2.0);
        const int spin = static_cast<int>(std::sin((timer - 7) * kTau / 55.0) * 600.0);
        const float baseY = enemy.y + wave + 12.0f;
        const auto source = [&](bool right) {
            const double baseAngle = std::atan2(-25.0, right ? 48.0 : -48.0);
            const auto angle16 = s06Angle(static_cast<int>(baseAngle * 65536.0 / kTau) +
                                          (right ? spin : -spin));
            const double radians = s06Radians(angle16);
            const float radius = static_cast<float>(std::sqrt(48.0 * 48.0 + 25.0 * 25.0));
            return std::array<float, 2>{{
                enemy.x + (right ? 13.0f : -13.0f) +
                    static_cast<float>(std::cos(radians) * radius),
                baseY + static_cast<float>(std::sin(radians) * radius)}};
        };
        const auto right = source(true);
        const auto left = source(false);
        if (enemy.y < 400.0f && timer >= 110) {
            const int local = (timer - 110) % kCadence[d];
            const auto currentAim = aim(enemy.x, right[1]);
            if (local == 0) enemy.secondaryAngle16 = currentAim;
            if (local < 20 && local % 10 == 0) {
                const auto fire = [&](const std::array<float, 2>& point, int offset,
                                      double speed) {
                    spawnProjectileNode(13, 0, point[0], point[1],
                                        s06Angle(static_cast<int>(enemy.secondaryAngle16) + offset),
                                        10.0f, speed, 1, 0);
                };
                fire(right, 0, kSpeed[d]);
                fire(left, 0, kSpeed[d]);
                if (difficulty > 0) {
                    fire(right, -8000, kSpeed[d]);
                    fire(left, 8000, kSpeed[d]);
                }
                if (difficulty > 2) {
                    fire(right, -8000, kSpeed[d] + 2.0);
                    fire(right, 0, kSpeed[d] + 2.0);
                    fire(left, 0, kSpeed[d] + 2.0);
                    fire(left, 8000, kSpeed[d] + 2.0);
                }
            }
            enemy.secondaryAngle16 = s06Approach(
                enemy.secondaryAngle16, currentAim, 0x20);
        }
        if (enemy.hp < 1) finish(1000, 1);
        else if (enemy.y >= 820.0f) enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0x5e) {
        static constexpr std::array<int, 5> kCadence{{120, 60, 50, 45, 45}};
        static constexpr std::array<int, 5> kWindow{{16, 16, 20, 24, 30}};
        static constexpr std::array<int, 5> kCount{{9, 11, 13, 13, 15}};
        static constexpr std::array<double, 5> kSpeed{{6.0, 6.8, 7.5, 8.5, 9.5}};
        const int spin = static_cast<int>(std::sin(timer * kTau / 177.0) * 2000.0);
        const bool left = enemy.originX < 360.0f;
        const double baseAngle = left ? std::atan2(10.0, 40.0)
                                      : std::atan2(10.0, -40.0);
        const float radius = static_cast<float>(std::sqrt(1700.0));
        const auto sourceAngle = s06Angle(
            static_cast<int>(baseAngle * 65536.0 / kTau) + spin);
        const double radians = s06Radians(sourceAngle);
        const float x = enemy.x + static_cast<float>(std::cos(radians) * radius);
        const float y = enemy.y + static_cast<float>(std::sin(radians) * radius);
        if (enemy.y < 360.0f && timer >= 120) {
            const int local = (timer - 120) % kCadence[d];
            const auto aimed = aim(x, y);
            if (local == 0) enemy.secondaryAngle16 = aimed;
            if (local < kWindow[d] && local % 4 == 0) {
                const int count = local / 4 + 1;
                spawnProjectileSpread(9, 0, x, y, enemy.secondaryAngle16,
                                      10.0f, kSpeed[d], 1, count,
                                      (count - 1) * 400, 0);
            }
            const int second = kCadence[d] + 130 + kWindow[d];
            if (timer >= second && (timer - second) % (kCadence[d] * 2) == 0) {
                spawnProjectileSpread(14, 0, x, y, enemy.secondaryAngle16,
                                      0.0f, kSpeed[d] - 2.0, 1,
                                      kCount[d], 27000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(14, 0, x, y, enemy.secondaryAngle16,
                                          0.0f, kSpeed[d] - 1.0, 1,
                                          kCount[d], 27000, 0);
                }
            }
        }
        if (enemy.hp < 1) finish(1000, 1);
        else if (enemy.y >= 820.0f) enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0x60) {
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->hp < 1 || parent->y >= 450.0f) return;
        static constexpr std::array<int, 5> kPeriod{{36, 32, 32, 32, 32}};
        static constexpr std::array<int, 5> kWindow{{16, 16, 20, 20, 20}};
        static constexpr std::array<int, 5> kCount{{1, 2, 2, 2, 2}};
        static constexpr std::array<double, 5> kSpeed{{4.8, 5.5, 6.0, 6.0, 7.5}};
        if (timer > 39) {
            const int local = (timer - 40) % kPeriod[d];
            if (local < kWindow[d] && local % 4 == 0) {
                spawnProjectileSpread(5, 0, enemy.x, enemy.y,
                                      enemy.secondaryAngle16, 0.0f,
                                      kSpeed[d], 1, kCount[d], 4000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(5, 0, enemy.x, enemy.y,
                                          enemy.secondaryAngle16, 0.0f,
                                          kSpeed[d] + 0.5, 1,
                                          kCount[d], 4000, 0);
                }
            }
        }
    }
}

bool StageRuntime::drawStage06Enemy(const StageEnemy& enemy, float x,
                                    float y, int exactLayer) const {
    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = s06Frame(effectMediumFrames_, 4);
        if (marker != -1) {
            const double scale = enemy.spawnType == 0x5b || enemy.spawnType == 0x5c
                                     ? std::max(0.0, 2.0 - enemy.markerDrawTimer * 0.1)
                                     : std::max(0.0, 3.0 - enemy.markerDrawTimer * 0.15);
            DrawRotaGraphF(x + enemy.markerDrawX - enemy.x,
                           y + enemy.markerDrawY - enemy.y,
                           scale, 0.0, marker, TRUE);
        }
    }
    if (!enemy.drawBodyThisFrame) return true;

    int bodyLayer = 0x23;
    if (enemy.spawnType == 0x57 || enemy.spawnType == 0x58 ||
        enemy.spawnType == 0x59) {
        bodyLayer = 0x20;
    }
    else if (enemy.spawnType == 0x60) {
        bodyLayer = 0x1c;
    }
    else if ((enemy.spawnType >= 0x5a && enemy.spawnType <= 0x5f)) {
        bodyLayer = -1;
    }

    const auto draw = [this, exactLayer, bodyLayer](
                             const std::vector<int>& frames, int frame,
                             float drawX, float drawY, std::uint16_t angle = 0,
                             bool reverse = false, double sx = 1.0,
                             double sy = 1.0) {
        if (bodyLayer >= 0 && exactLayer != bodyLayer) return;
        const int graph = s06Frame(frames, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle, sx, sy, reverse);
        }
    };
    const int timer = enemy.drawHelperTimer;

    switch (enemy.spawnType) {
    case 0x57:
    case 0x58: {
        const int sourceFrame = std::max(0, frame_ - 1);
        for (int i = 0; i < 3; ++i) {
            const auto angle = s06Angle(sourceFrame * 0x29a + i * 0x5555);
            const double radians = s06Radians(angle);
            draw(enemyMediumFrames_, 85,
                 x + static_cast<float>(std::cos(radians) * 36.0),
                 y + 20.0f + static_cast<float>(std::sin(radians) * 20.0));
        }
        draw(enemyMediumFrames_, 84, x, y);
        break;
    }
    case 0x59: {
        const double radians = s06Radians(enemy.sourceAngle16);
        draw(enemyMediumFrames_, 87,
             x + enemy.markerDrawX - enemy.x +
                 static_cast<float>(std::cos(radians) * 30.0),
             y + enemy.markerDrawY - enemy.y +
                 static_cast<float>(std::sin(radians) * 30.0),
             enemy.targetAngle16);
        draw(enemyMediumFrames_, 87,
             x + enemy.markerDrawX - enemy.x -
                 static_cast<float>(std::cos(radians) * 30.0),
             y + enemy.markerDrawY - enemy.y -
                 static_cast<float>(std::sin(radians) * 30.0),
             s06Angle(-static_cast<int>(enemy.targetAngle16)), true);
        draw(enemyMediumFrames_, 86, x, y, enemy.sourceAngle16);
        break;
    }
    case 0x5a: {
        const double heading = s06Radians(enemy.sourceAngle16);
        const float fireX = x + static_cast<float>(std::cos(heading) * 8.0);
        const float fireY = y + static_cast<float>(std::sin(heading) * 8.0) + 7.0f;
        if (exactLayer == 0x1a) {
            draw(enemySmallFrames_, 58, x, y, s06Angle(timer * 0x1bc));
            draw(enemySmallFrames_, 59, x, y);
            draw(enemySmallFrames_, 60, fireX, fireY);
        }
        const double pulse = 1.0 + std::sin((timer - 20) * kTau / 61.0) * 0.1;
        if (exactLayer == 0x19) {
            draw(enemySmallFrames_, 61, x + enemy.originX - enemy.x,
                 y + enemy.originY - enemy.y + 30.0f,
                 0, false, pulse, pulse);
        }
        if (exactLayer == 0x18) {
            SetDrawBright(0, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
            draw(enemySmallFrames_, 61, x + enemy.originX - enemy.x,
                 y + enemy.originY - enemy.y + 30.0f,
                 0, false, pulse, pulse);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(255, 255, 255);
        }
        break;
    }
    case 0x5b:
    case 0x5c: {
        const float wave0 = static_cast<float>(std::sin((timer % 50) * kPi / 50.0) * -10.0);
        const float wave3 = static_cast<float>(std::sin(((timer + 3) % 50) * kPi / 50.0) * -10.0);
        const int wing = static_cast<int>(std::sin(((timer + 5) % 50) * kPi / 50.0) * -4000.0);
        const int wingR = ((timer + 5) % 100) < 51
                              ? static_cast<int>(std::sin(((timer + 5) % 100) * kPi / 50.0) * 13000.0)
                              : 0;
        const int wingL = ((timer + 55) % 100) < 51
                              ? static_cast<int>(std::sin(((timer + 55) % 100) * kPi / 50.0) * 13000.0)
                              : 0;
        if (exactLayer == 0x1a) {
            draw(enemySmallFrames_, 66, x + 8.0f, y + wave3 + 16.0f, s06Angle(-wingR));
            draw(enemySmallFrames_, 66, x - 8.0f, y + wave3 + 16.0f, s06Angle(wingL), true);
            draw(enemySmallFrames_, 67, x + 10.0f, y + wave3, s06Angle(-wing));
            draw(enemySmallFrames_, 67, x - 10.0f, y + wave3, s06Angle(wing), true);
            draw(enemySmallFrames_, 68, x, y + wave3);
            draw(enemySmallFrames_, 69, x, y + wave0 - 14.0f);
        }
        if (exactLayer == 0x19) {
            draw(enemySmallFrames_, 62 + (timer / 7) % 4, x, y + 60.0f);
        }
        if (exactLayer == 0x18) {
            SetDrawBright(0, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
            draw(enemySmallFrames_, 62 + (timer / 7) % 4, x, y + 60.0f);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(255, 255, 255);
        }
        break;
    }
    case 0x5d: {
        const float wave0 = static_cast<float>(std::sin(timer * kTau / 55.0) * 2.0);
        const float wave14 = static_cast<float>(std::sin((timer - 14) * kTau / 55.0) * 2.0);
        const int wing = static_cast<int>(std::sin((timer - 28) * kTau / 55.0) * 3000.0);
        const int spin = static_cast<int>(std::sin((timer - 7) * kTau / 55.0) * 600.0);
        if (exactLayer == 0x18) {
            SetDrawBright(0, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
            draw(enemyMediumFrames_, 96, x, y);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(255, 255, 255);
        }
        if (exactLayer == 0x19) {
            draw(enemyMediumFrames_, 91, x, y);
        }
        if (exactLayer == 0x1b) {
            draw(enemyMediumFrames_, 95, x + 13.0f,
                 y + wave0 + 12.0f, s06Angle(spin));
            draw(enemyMediumFrames_, 95, x - 13.0f,
                 y + wave0 + 12.0f, s06Angle(-spin), true);
            draw(enemyMediumFrames_, 92, x, y + wave0 - 8.0f);
            draw(enemyMediumFrames_, 93, x, y + wave14 - 5.0f);
            draw(enemyMediumFrames_, 94, x + 20.0f,
                 y + wave14 - 29.0f, s06Angle(wing));
            draw(enemyMediumFrames_, 94, x - 20.0f,
                 y + wave14 - 29.0f, s06Angle(-wing), true);
        }
        break;
    }
    case 0x5e: {
        const int spin = static_cast<int>(std::sin(timer * kTau / 177.0) * 2000.0);
        const int secondary = static_cast<int>(std::sin(timer * kTau / 77.0) * 800.0);
        if (exactLayer == 0x1a) {
            draw(enemyMediumFrames_, 97, x, y, s06Angle(spin));
            draw(enemyMediumFrames_, 98, x, y, s06Angle(spin),
                 enemy.originX < 360.0f);
            draw(enemyMediumFrames_, 99, x, y,
                 s06Angle(spin + secondary));
        }
        if (exactLayer == 0x18) {
            SetDrawBright(0, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
            draw(enemyMediumFrames_, 100, x + enemy.originX - enemy.x,
                 y + enemy.originY - enemy.y + 40.0f);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(255, 255, 255);
        }
        break;
    }
    case 0x5f: {
        const double scale = enemy.drawHelperState == 2
                                 ? 1.0 + std::sin(timer * kPi / 6.0) * 0.1
                                 : 1.0;
        if (exactLayer == 0x18) {
            SetDrawBright(0, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
            draw(enemyLargeFrames_, 35, x, y - 168.0f, 0, false, scale, 1.5);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(255, 255, 255);
        }
        if (exactLayer == 0x1a) {
            draw(enemyLargeFrames_, 35, x, y + 130.0f, 0, false, scale, 1.0);
        }
        break;
    }
    case 0x60:
        draw(enemySmallFrames_, 70, x, y, s06Angle(timer * 0x22b));
        return true;
    default:
        break;
    }

    if (enemy.targetable) {
        StageEnemy gauge = enemy;
        gauge.hp = enemy.drawHp;
        const int mode = enemy.spawnType == 0x5a || enemy.spawnType == 0x5b ||
                                 enemy.spawnType == 0x5c
                             ? 2
                             : (enemy.spawnType == 0x5f ? 0 : 1);
        drawEnemyGaugeExact(gauge, mode, x, y, exactLayer);
    }
    return true;
}

} // namespace reconstructed
