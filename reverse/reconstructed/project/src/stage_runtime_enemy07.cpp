#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kPi07 = 3.14159265358979323846;
constexpr double kTau07 = kPi07 * 2.0;
constexpr std::size_t kStage07EnemyCap = 0x200;

std::uint16_t angle07(int angle) {
    return static_cast<std::uint16_t>(angle & 0xffff);
}

double radians07(std::uint16_t angle) {
    return static_cast<double>(angle) * kTau07 / 65536.0;
}

std::uint16_t radiansToAngle07(double radians) {
    return angle07(static_cast<int>(radians * 65536.0 / kTau07));
}

int angleDelta07(std::uint16_t current, std::uint16_t target) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return delta;
}

std::uint16_t approachAngle07(std::uint16_t current,
                              std::uint16_t target, int step) {
    return angle07(static_cast<int>(current) +
                   std::clamp(angleDelta07(current, target), -step, step));
}

std::uint32_t enemy07Rand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

double randomHundredth07(int seed, double minimum, double maximum) {
    const int low = static_cast<int>(minimum * 100.0);
    const int high = static_cast<int>(maximum * 100.0);
    return static_cast<double>(
               low + static_cast<int>(enemy07Rand(seed) %
                                      static_cast<std::uint32_t>(high - low + 1))) /
           100.0;
}

void clampEntry07(float& x, float& y, float horizontalOrigin,
                  float signedMargin) {
    x = std::clamp(x, horizontalOrigin + signedMargin,
                   horizontalOrigin + 600.0f - signedMargin);
    y = std::clamp(y, signedMargin, 720.0f - signedMargin);
}

void moveAngle07(float& x, float& y, std::uint16_t angle, double speed) {
    const double radians = radians07(angle);
    x += static_cast<float>(std::cos(radians) * speed);
    y += static_cast<float>(std::sin(radians) * speed);
}

int positiveMod07(int value, int divisor) {
    const int result = value % divisor;
    return result < 0 ? result + divisor : result;
}

int frame07(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

} // namespace

bool StageRuntime::spawnStage07EnemyChild(StageEnemy& parent, float offsetX,
                                           float offsetY, int childIndex) {
    if (parent.spawnType != 0x77 ||
        enemies_.size() + pendingEnemies_.size() >= kStage07EnemyCap) {
        return false;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = 0x78;
    child.updateCase = 0x56;
    child.sourceHitPoints = 6000;
    child.sourceX = static_cast<int>(offsetX);
    child.sourceY = static_cast<int>(offsetY);
    child.sourceNote = "S07 FUN_1400a7760 attached child 0x78";
    child.sourceDispatchKind = 12;
    child.sourceDispatchField = 40;
    child.rewardWeight = 12;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = childIndex;
    child.originX = offsetX;
    child.originY = offsetY;
    child.x = parent.x + offsetX;
    child.y = parent.y + offsetY;
    child.sourceAngle16 = 0x4000;
    child.secondaryAngle16 = 0x4000;
    child.targetAngle16 = 0x4000;
    child.angle = static_cast<float>(radians07(child.sourceAngle16));
    child.sourceSpeed = 0.0;
    child.speed = 0.0f;
    const double hpScale = config_.difficulty == 0 ? 0.8 : 1.0;
    child.hp = std::max(1, static_cast<int>(6000.0 * hpScale));
    child.maxHp = child.hp;
    child.drawHp = child.hp;
    child.radius = 40;
    child.activationDelay = 0;
    child.helperState = 1;
    child.targetable = true;
    pendingEnemies_.push_back(child);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage07Enemy(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHp = enemy.hp;

    const auto aimFrom = [this](float x, float y) {
        return radiansToAngle07(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto adaptiveApproach = [](std::uint16_t current,
                                     std::uint16_t target, int divisor) {
        const int distance = std::abs(angleDelta07(current, target));
        return approachAngle07(current, target, distance / divisor + 0x30);
    };
    const float horizontalOrigin = player_.x / 6.0f;

    if (enemy.spawnType == 0x78) {
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || !parent->active || parent->spawnType != 0x77 ||
            parent->helperState != 1 || parent->hp < 1) {
            if (parent != nullptr && parent->liveChildCount > 0) {
                --parent->liveChildCount;
            }
            enemy.targetable = false;
            enemy.active = false;
            return;
        }

        const double bob = std::sin(static_cast<double>(parent->helperTimer) *
                                    kPi07 / 4.0) * 2.0;
        enemy.x = parent->x + enemy.originX;
        enemy.y = parent->y + enemy.originY + static_cast<float>(bob);
        // FUN_1400a8a80 derives this stagger from the allocated entity ids,
        // not a zero-based child ordinal. Consecutive children therefore use
        // thresholds 0x6f and 0x98 rather than 0x46 and 0x6f.
        const int aimEnd =
            (enemy.entityId - parent->entityId) * 0x29 + 0x46;
        if (enemy.helperTimer < aimEnd) {
            const auto aimed = aimFrom(enemy.x, enemy.y);
            enemy.sourceAngle16 = adaptiveApproach(
                enemy.sourceAngle16, aimed, 10);
        }
        enemy.angle = static_cast<float>(radians07(enemy.sourceAngle16));
        enemy.targetable = true;
        enemy.drawBodyThisFrame = true;
        return;
    }

    if (enemy.spawnType == 0x77 && enemy.helperState == 2) {
        enemy.targetable = false;
        enemy.drawBodyThisFrame = true;
        enemy.y += static_cast<float>(enemy.helperTimer) * 0.1f;
        if (enemy.helperTimer < 61 && enemy.helperTimer % 3 == 0) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (enemy.helperTimer >= 60) {
            // FUN_1400a7760's delayed terminal branch calls
            // FUN_140079e20(parent, 2); 0x1e is the reward weight passed to
            // FUN_14007b010 at death entry, not an effect mode.
            spawnEnemyDeathEffects(enemy, 2);
            clearLateStageGate(7);
            enemy.active = false;
        }
        return;
    }

    if (enemy.helperState == 0) {
        if ((enemy.spawnType == 0x71 || enemy.spawnType == 0x72) &&
            enemy.helperTimer == 0) {
            enemy.x = enemy.originX +
                      (enemy.spawnType == 0x71 ? 640.0f : -640.0f);
            enemy.y = enemy.originY;
            enemy.originY -= 120.0f;
        }

        const float margin = (enemy.spawnType == 0x71 ||
                              enemy.spawnType == 0x72 ||
                              enemy.spawnType == 0x73 ||
                              enemy.spawnType == 0x76 ||
                              enemy.spawnType == 0x77)
                                 ? -50.0f
                                 : -20.0f;
        float markerX = enemy.x;
        float markerY = enemy.y;
        if (enemy.spawnType == 0x71 || enemy.spawnType == 0x72) {
            const double projection = -static_cast<double>(enemy.y) * 0.8;
            markerX += static_cast<float>(
                std::cos(radians07(enemy.sourceAngle16)) * projection);
            markerY += static_cast<float>(
                std::sin(radians07(enemy.sourceAngle16)) * projection);
        }
        else if (enemy.spawnType == 0x74) {
            markerX += static_cast<float>(
                std::sin(static_cast<double>(frame_) * kTau07 / 3300.0) *
                80.0);
        }
        clampEntry07(markerX, markerY, horizontalOrigin, margin);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = markerX;
        enemy.markerDrawY = markerY;
        if (enemy.helperTimer < 20) {
            return;
        }

        switch (enemy.spawnType) {
        case 0x70:
            enemy.sourceSpeed = randomHundredth07(frame_, 6.0, 9.0);
            if (enemy.x <= 0.0f) enemy.sourceAngle16 = 0;
            if (enemy.x >= 720.0f) enemy.sourceAngle16 = 0x8000;
            if (enemy.y >= 720.0f) {
                enemy.sourceSpeed = randomHundredth07(frame_, 11.0, 12.0);
                enemy.sourceAngle16 = 0xc000;
            }
            enemy.secondaryAngle16 = 0x4000;
            clampEntry07(enemy.originX, enemy.originY,
                         horizontalOrigin, -60.0f);
            break;
        case 0x71:
        case 0x72:
            enemy.sourceSpeed = 1.0;
            break;
        case 0x73:
            enemy.sourceSpeed = 7.0;
            enemy.secondaryAngle16 = 0x4000;
            break;
        case 0x74:
        case 0x75:
        case 0x76:
            clampEntry07(enemy.x, enemy.y, horizontalOrigin, -20.0f);
            break;
        case 0x77:
            clampEntry07(enemy.x, enemy.y, horizontalOrigin, -20.0f);
            spawnStage07EnemyChild(enemy, -40.0f, 140.0f, 0);
            spawnStage07EnemyChild(enemy, 40.0f, 70.0f, 1);
            playPlayerSound(bossSe8SoundHandle_, 0x19);
            break;
        default:
            break;
        }
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
    }

    if (enemy.helperState != 1) {
        return;
    }

    enemy.drawBodyThisFrame = true;
    const int timer = enemy.helperTimer;
    switch (enemy.spawnType) {
    case 0x70: {
        auto aimed = aimFrom(enemy.x, enemy.y + 24.0f);
        const auto raw = static_cast<unsigned int>(aimed);
        if (static_cast<std::uint16_t>(raw - 4000u) < 0xb060u) {
            if (aimed > 0x7060) aimed = 0x7060;
        }
        else {
            aimed = 4000;
        }
        if (timer < 200) {
            if (enemy.sourceSpeed > 0.5) enemy.sourceSpeed -= 0.1;
            if (enemy.sourceSpeed < 1.2) {
                enemy.sourceAngle16 = approachAngle07(
                    enemy.sourceAngle16, aimed, 0x40);
            }
        }
        else {
            enemy.sourceAngle16 = approachAngle07(
                enemy.sourceAngle16, 0xc000, 0x200);
            enemy.sourceSpeed += 0.05;
        }
        moveAngle07(enemy.originX, enemy.originY,
                    enemy.sourceAngle16, enemy.sourceSpeed);
        enemy.secondaryAngle16 = adaptiveApproach(
            enemy.secondaryAngle16, aimed, 10);
        const double bodyAngle = radians07(enemy.secondaryAngle16);
        enemy.x = enemy.originX +
                  static_cast<float>(std::cos(bodyAngle) * 20.0);
        enemy.y = enemy.originY + 24.0f +
                  static_cast<float>(std::sin(bodyAngle) * 20.0);
        enemy.angle = static_cast<float>(bodyAngle);
        break;
    }
    case 0x71:
    case 0x72: {
        const auto aimed = aimFrom(enemy.x, enemy.y);
        if (timer < 120) {
            const double phase = static_cast<double>(timer) * kTau07 / 480.0;
            const double side = enemy.spawnType == 0x71 ? 1.0 : -1.0;
            enemy.x = enemy.originX + static_cast<float>(side * 640.0 -
                side * std::sin(phase) * 640.0);
            enemy.y = enemy.originY -
                      static_cast<float>(std::sin(phase) * 60.0);
            enemy.originY += 1.0f;
        }
        else {
            if (timer < 130) enemy.sourceSpeed += 0.05;
            enemy.sourceAngle16 = approachAngle07(
                enemy.sourceAngle16, aimed, 0x80);
            if (timer > 299) enemy.sourceSpeed -= 0.1;
            moveAngle07(enemy.x, enemy.y,
                        enemy.sourceAngle16, enemy.sourceSpeed);
        }
        enemy.angle = static_cast<float>(radians07(enemy.sourceAngle16));
        break;
    }
    case 0x73: {
        const auto aimed = aimFrom(enemy.x, enemy.y);
        if (timer < 121 && enemy.sourceSpeed > 0.6) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.sourceAngle16 = approachAngle07(
            enemy.sourceAngle16, aimed, 0x40);
        if (timer > 359) enemy.sourceSpeed -= 0.1;
        moveAngle07(enemy.x, enemy.y,
                    enemy.sourceAngle16, enemy.sourceSpeed);
        const auto gunAim = aimFrom(enemy.x, enemy.y + 25.0f);
        enemy.secondaryAngle16 = adaptiveApproach(
            enemy.secondaryAngle16, gunAim, 10);
        enemy.angle = static_cast<float>(radians07(enemy.sourceAngle16));
        break;
    }
    case 0x74: {
        const int phaseSeed = frame_ - (frame_ - timer) / 7 - timer;
        const int phaseTick = frame_ - phaseSeed;
        enemy.x = enemy.originX + static_cast<float>(
            std::sin(static_cast<double>(phaseTick) * kTau07 / 320.0) * 32.0);
        const int baseY = static_cast<int>(enemy.originY);
        if (timer < 120) {
            enemy.y = static_cast<float>(baseY - static_cast<int>(
                std::sin(static_cast<double>(timer) * kTau07 / 480.0) * 800.0));
        }
        else if (timer < 300) {
            enemy.y = static_cast<float>(baseY - 800);
        }
        else if (timer < 480) {
            enemy.y = static_cast<float>(baseY - static_cast<int>(
                std::sin(static_cast<double>(timer - 120) *
                         kTau07 / 720.0) * 800.0));
        }
        else {
            enemy.y = static_cast<float>(baseY);
            enemy.originY += 1.0f + static_cast<float>(timer - 480) * 0.05f;
        }
        break;
    }
    case 0x75: {
        enemy.x = enemy.originX;
        const int baseY = static_cast<int>(enemy.originY);
        if (timer < 120) {
            enemy.y = static_cast<float>(baseY - static_cast<int>(
                std::sin(static_cast<double>(timer) * kTau07 / 480.0) * 800.0));
        }
        else if (timer < 300) {
            enemy.y = static_cast<float>(baseY - 800);
        }
        else if (timer < 480) {
            enemy.y = static_cast<float>(baseY - static_cast<int>(
                std::sin(static_cast<double>(timer - 120) *
                         kTau07 / 720.0) * 800.0));
        }
        else {
            enemy.y = static_cast<float>(baseY);
            enemy.originY += 0.5f + static_cast<float>(timer - 480) * 0.05f;
        }
        break;
    }
    case 0x76: {
        enemy.x = enemy.originX;
        const int baseY = static_cast<int>(enemy.originY);
        if (timer < 120) {
            enemy.y = static_cast<float>(baseY - static_cast<int>(
                std::sin(static_cast<double>(timer) * kTau07 / 480.0) * 750.0));
        }
        else if (timer < 420) {
            enemy.y = static_cast<float>(baseY - 750);
        }
        else if (timer < 600) {
            enemy.y = static_cast<float>(baseY - static_cast<int>(
                std::sin(static_cast<double>(timer - 240) *
                         kTau07 / 720.0) * 750.0));
        }
        else {
            enemy.y = static_cast<float>(baseY);
            enemy.originY += 0.25f + static_cast<float>(timer - 600) * 0.05f;
        }
        auto aimed = aimFrom(enemy.x, enemy.y + 24.0f);
        if (aimed < 6000 || aimed > 0xf000) aimed = 6000;
        else if (aimed > 0x6890) aimed = 0x6890;
        const int cycle = positiveMod07(timer - 70, 0xa4);
        if (timer < 70 || cycle > 99) {
            enemy.secondaryAngle16 = adaptiveApproach(
                enemy.secondaryAngle16, aimed, 20);
        }
        enemy.angle = static_cast<float>(radians07(enemy.secondaryAngle16));
        break;
    }
    case 0x77: {
        enemy.x = enemy.originX;
        const int baseY = static_cast<int>(enemy.originY);
        if (timer < 150) {
            enemy.y = static_cast<float>(baseY - static_cast<int>(
                std::sin(static_cast<double>(timer) * kTau07 / 600.0) * 900.0));
        }
        else if (timer < 1020) {
            enemy.y = static_cast<float>(baseY - 900);
        }
        else if (timer < 1200) {
            enemy.y = static_cast<float>(baseY - static_cast<int>(
                std::sin(static_cast<double>(timer - 840) *
                         kTau07 / 720.0) * 900.0));
        }
        else {
            enemy.y = static_cast<float>(baseY);
            enemy.originY += 0.25f + static_cast<float>(timer - 1200) * 0.05f;
        }
        break;
    }
    default:
        break;
    }
}

void StageRuntime::emitStage07EnemyProjectiles(StageEnemy& enemy) {
    if (!enemy.active || enemy.helperState != 1) {
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    const auto aimFrom = [this](float x, float y) {
        return radiansToAngle07(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto farEnough = [this](float x, float y) {
        const double dx = static_cast<double>(x - player_.x);
        const double dy = static_cast<double>(y - player_.y);
        return dx * dx + dy * dy > 80.0 * 80.0;
    };
    const auto inFireArea = [this](float x, float y) {
        const float horizontalOrigin = player_.x / 6.0f;
        return x >= horizontalOrigin + 40.0f &&
               x <= horizontalOrigin + 560.0f &&
               y >= 40.0f && y <= 680.0f;
    };
    bool fired = false;

    switch (enemy.spawnType) {
    case 0x70: {
        static constexpr std::array<int, 5> kCadence{{60, 45, 33, 30, 20}};
        static constexpr std::array<int, 5> kCount{{3, 5, 5, 5, 7}};
        static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 7.0, 9.0, 9.0}};
        const double radians = radians07(enemy.secondaryAngle16);
        const float sourceX = enemy.x + static_cast<float>(std::cos(radians) * 20.0);
        const float sourceY = enemy.y + static_cast<float>(std::sin(radians) * 20.0);
        const int start = enemy.sourceY >= 720 ? 70 : 20;
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        if (timer < 200 && timer >= start &&
            (timer - start) % cadence == 0 && farEnough(sourceX, sourceY)) {
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(0x0c, 0, sourceX, sourceY,
                                  enemy.secondaryAngle16, 0.0f, speed, 1,
                                  count, (count - 1) * 0x1c2, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(0x0c, 0, sourceX, sourceY,
                                      enemy.secondaryAngle16, 0.0f,
                                      speed - 1.5, 1, count, 3000, 0);
            }
            fired = true;
        }
        break;
    }
    case 0x71:
    case 0x72: {
        static constexpr std::array<int, 5> kPeriod{{150, 120, 90, 80, 80}};
        static constexpr std::array<int, 5> kBurstStep{{19, 12, 12, 10, 8}};
        static constexpr std::array<double, 5> kSideSpeed{{6.0, 7.0, 7.5, 8.5, 9.5}};
        static constexpr std::array<int, 5> kFanCount{{3, 5, 5, 5, 7}};
        static constexpr std::array<double, 5> kFanSpeed{{4.2, 5.0, 6.0, 6.0, 7.0}};
        const int period = kPeriod[static_cast<std::size_t>(difficulty)];
        if (timer >= 70 && timer < 300) {
            const int rem = (timer - 70) % period;
            const float rightX = enemy.x + 40.0f;
            const float leftX = enemy.x - 40.0f;
            const float sourceY = enemy.y - 40.0f;
            if (rem == 0) {
                enemy.secondaryAngle16 = aimFrom(rightX, sourceY);
                enemy.targetAngle16 = aimFrom(leftX, sourceY);
            }
            if (rem < 50 && rem % kBurstStep[static_cast<std::size_t>(difficulty)] == 0) {
                const int turn = rem * 0x20;
                const double speed = kSideSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(9, 0, rightX, sourceY,
                                    angle07(static_cast<int>(enemy.secondaryAngle16) - turn),
                                    10.0f, speed, 1, 0);
                spawnProjectileNode(9, 0, leftX, sourceY,
                                    angle07(static_cast<int>(enemy.targetAngle16) + turn),
                                    10.0f, speed, 1, 0);
                if (difficulty > 1) {
                    spawnProjectileNode(9, 0, rightX, sourceY,
                                        angle07(static_cast<int>(enemy.secondaryAngle16) - turn - 4000),
                                        10.0f, speed, 1, 0);
                    spawnProjectileNode(9, 0, leftX, sourceY,
                                        angle07(static_cast<int>(enemy.targetAngle16) + turn + 4000),
                                        10.0f, speed, 1, 0);
                }
                fired = true;
            }
        }
        if (timer >= 125 && timer < 300 &&
            (timer - 125) % period == 0) {
            const int count = kFanCount[static_cast<std::size_t>(difficulty)];
            const auto aimed = aimFrom(enemy.x, enemy.y - 30.0f);
            const double speed = kFanSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(4, 0, enemy.x, enemy.y - 30.0f,
                                  aimed, 0.0f, speed, 1,
                                  count, 12000, 0);
            if (difficulty > 2 && count > 1) {
                spawnProjectileSpread(4, 0, enemy.x, enemy.y - 30.0f,
                                      aimed, 0.0f, speed + 1.2, 1,
                                      count - 1,
                                      12000 * (count - 2) / (count - 1), 0);
            }
            fired = true;
        }
        break;
    }
    case 0x73: {
        static constexpr std::array<int, 5> kSpinCadence{{18, 10, 8, 6, 5}};
        static constexpr std::array<int, 5> kSpinStep{{150, 200, 240, 270, 320}};
        static constexpr std::array<double, 5> kSpinSpeed{{4.8, 5.0, 5.8, 6.5, 7.5}};
        static constexpr std::array<int, 5> kAimPeriod{{160, 120, 90, 90, 70}};
        static constexpr std::array<int, 5> kAimCount{{1, 3, 3, 3, 3}};
        static constexpr std::array<double, 5> kAimSpeed{{6.0, 6.6, 7.0, 7.0, 8.5}};
        if (timer >= 30 && timer < 360 &&
            (timer - 30) % kSpinCadence[static_cast<std::size_t>(difficulty)] == 0) {
            const int spin = timer * kSpinStep[static_cast<std::size_t>(difficulty)];
            const int count = difficulty == 0 ? 1 : 2;
            const double speed = kSpinSpeed[static_cast<std::size_t>(difficulty)];
            const std::array<float, 4> px{{enemy.x + 85.0f, enemy.x - 85.0f,
                                          enemy.x - 83.0f, enemy.x + 83.0f}};
            const std::array<float, 4> py{{enemy.y + 50.0f, enemy.y + 50.0f,
                                          enemy.y - 35.0f, enemy.y - 35.0f}};
            const std::array<int, 4> heading{{-0x6000 - spin, -0x2000 + spin,
                                              -0x4000 - spin, -0x4000 + spin}};
            for (int i = 0; i < 4; ++i) {
                spawnProjectileSpread(7, 0, px[static_cast<std::size_t>(i)],
                                      py[static_cast<std::size_t>(i)],
                                      angle07(heading[static_cast<std::size_t>(i)]),
                                      10.0f, speed, 1, count, 0x10000, 0);
            }
            fired = true;
        }
        const int aimPeriod = kAimPeriod[static_cast<std::size_t>(difficulty)];
        const int aimLocal = timer - 50;
        if (timer >= 50 && timer < 360 &&
            positiveMod07(aimLocal, aimPeriod) < 50 &&
            positiveMod07(aimLocal, aimPeriod) % 18 == 0) {
            const double radians = radians07(enemy.secondaryAngle16);
            const float sourceX = enemy.x + static_cast<float>(std::cos(radians) * 45.0);
            const float sourceY = enemy.y + 25.0f +
                                  static_cast<float>(std::sin(radians) * 45.0);
            const int count = kAimCount[static_cast<std::size_t>(difficulty)];
            const double speed = kAimSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(0x0c, 0, sourceX, sourceY,
                                  enemy.secondaryAngle16, 10.0f, speed, 1,
                                  count, 5000, 0);
            if (difficulty > 2 && count > 1) {
                spawnProjectileSpread(0x0c, 0, sourceX, sourceY,
                                      enemy.secondaryAngle16, 10.0f,
                                      speed + 1.0, 1, count, 5000, 0);
            }
            fired = true;
        }
        break;
    }
    case 0x74: {
        static constexpr std::array<int, 5> kPeriod{{72, 48, 40, 40, 32}};
        static constexpr std::array<double, 5> kSpeed{{4.2, 5.4, 6.0, 5.5, 7.0}};
        if (timer >= 70 && timer < 480 && inFireArea(enemy.x, enemy.y)) {
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int rem = (timer - 70) % period;
            if (rem == 0) enemy.secondaryAngle16 = aimFrom(enemy.x, enemy.y);
            if (rem < 18 && rem % 6 == 0 && farEnough(enemy.x, enemy.y) && enemy.y < 360.0f) {
                // FUN_1400a4440 seeds both layers with globalFrame plus the
                // helper's seven-frame phase seed, not the entity id.
                const int phaseSeed =
                    frame_ - (frame_ - timer) / 7 - timer;
                const int jitter = static_cast<int>(
                    enemy07Rand(frame_ + phaseSeed) % 1601u) - 800;
                const auto heading = angle07(static_cast<int>(enemy.secondaryAngle16) + jitter);
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(1, 0, enemy.x, enemy.y,
                                    heading, 0.0f, speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(1, 0, enemy.x, enemy.y,
                                        heading, 0.0f, speed + 2.4, 1, 0);
                }
                fired = true;
            }
        }
        break;
    }
    case 0x75: {
        static constexpr std::array<double, 5> kSpeed{{4.0, 5.5, 6.5, 6.5, 7.7}};
        const int divisor = difficulty == 0 ? 82 : 41;
        const float sourceY = enemy.y + 20.0f;
        if (timer >= 60 && timer < 480 && frame_ % divisor == 0 &&
            inFireArea(enemy.x, sourceY) && sourceY < 360.0f &&
            farEnough(enemy.x, sourceY)) {
            const auto aimed = aimFrom(enemy.x, sourceY);
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            const auto shot = [this, &enemy, sourceY](std::uint16_t heading,
                                                       double shotSpeed) {
                spawnProjectileNode(5, 0, enemy.x, sourceY,
                                    heading, 0.0f, shotSpeed, 1, 0);
            };
            if (difficulty == 0) {
                shot(angle07(static_cast<int>(aimed) - 1000), speed + 1.0);
                shot(angle07(static_cast<int>(aimed) + 1000), speed + 1.0);
            }
            else {
                for (int offset : {-2000, 0, 2000}) {
                    shot(angle07(static_cast<int>(aimed) + offset), speed);
                }
                if (difficulty != 1) {
                    shot(angle07(static_cast<int>(aimed) - 1000), speed + 1.0);
                    shot(angle07(static_cast<int>(aimed) + 1000), speed + 1.0);
                }
                if (difficulty > 2) {
                    shot(angle07(static_cast<int>(aimed) - 4000), speed);
                    shot(angle07(static_cast<int>(aimed) + 4000), speed);
                    shot(angle07(static_cast<int>(aimed) - 3000), speed + 1.0);
                    shot(angle07(static_cast<int>(aimed) + 3000), speed + 1.0);
                }
            }
            fired = true;
        }
        break;
    }
    case 0x76: {
        const double bob = std::sin(static_cast<double>(timer - 2) * kPi07 / 4.0) * 2.0;
        const double headingRadians = radians07(enemy.secondaryAngle16);
        const float muzzleX = enemy.x +
                              static_cast<float>(std::cos(headingRadians) * 88.0);
        const float muzzleY = enemy.y + static_cast<float>(bob) +
                              static_cast<float>(std::sin(headingRadians) * 88.0);
        const float centerX = enemy.x + static_cast<float>(std::cos(headingRadians) * -60.0);
        const float centerY = enemy.y + static_cast<float>(bob) +
                              static_cast<float>(std::sin(headingRadians) * -60.0);
        const double leftRadians = radians07(angle07(
            static_cast<int>(enemy.secondaryAngle16) - 0x32c8));
        const double rightRadians = radians07(angle07(
            static_cast<int>(enemy.secondaryAngle16) + 0x32c8));
        const float leftX = centerX +
                            static_cast<float>(std::cos(leftRadians) * 87.0);
        const float leftY = centerY +
                            static_cast<float>(std::sin(leftRadians) * 87.0);
        const float rightX = centerX +
                             static_cast<float>(std::cos(rightRadians) * 87.0);
        const float rightY = centerY +
                             static_cast<float>(std::sin(rightRadians) * 87.0);
        if (timer >= 70 && timer < 600 && enemy.y < 360.0f) {
            const int local = (timer - 70) % 0xa4;
            if (local < 32 && local % 4 == 0) {
                static constexpr std::array<double, 5> kSpeed{{6.0, 7.0, 8.0, 9.0, 11.0}};
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                if (difficulty > 1) {
                    spawnProjectileNode(10, 0, muzzleX, muzzleY,
                                        angle07(static_cast<int>(enemy.secondaryAngle16) - 1500),
                                        10.0f, speed - 1.6, 1, 0);
                    spawnProjectileNode(10, 0, muzzleX, muzzleY,
                                        angle07(static_cast<int>(enemy.secondaryAngle16) + 1500),
                                        10.0f, speed - 1.6, 1, 0);
                }
                spawnProjectileNode(10, 0, muzzleX, muzzleY,
                                    angle07(static_cast<int>(enemy.secondaryAngle16) - 750),
                                    10.0f, speed - 0.8, 1, 0);
                spawnProjectileNode(10, 0, muzzleX, muzzleY,
                                    angle07(static_cast<int>(enemy.secondaryAngle16) + 750),
                                    10.0f, speed - 0.8, 1, 0);
                spawnProjectileNode(10, 0, muzzleX, muzzleY,
                                    enemy.secondaryAngle16, 10.0f, speed, 1, 0);
                fired = true;
            }

            static constexpr std::array<int, 5> kPairCadence{{30, 20, 20, 20, 20}};
            static constexpr std::array<int, 5> kPairCount{{1, 2, 3, 5, 7}};
            static constexpr std::array<int, 5> kPairStep{{8000, 4800, 4000, 3200, 2700}};
            static constexpr std::array<double, 5> kPairSpeed{{10.0, 7.0, 8.0, 9.0, 10.0}};
            const int pairCadence = kPairCadence[static_cast<std::size_t>(difficulty)];
            const int pairLocal = local - 20;
            if (local == 20) {
                const int count = kPairCount[static_cast<std::size_t>(difficulty)];
                enemy.targetAngle16 = angle07((count - 1) *
                    kPairStep[static_cast<std::size_t>(difficulty)] / 2);
            }
            if (local >= 20 && local < 80) {
                const int sub = positiveMod07(pairLocal, pairCadence);
                const int count = kPairCount[static_cast<std::size_t>(difficulty)];
                const int spread = (count - 1) *
                                   kPairStep[static_cast<std::size_t>(difficulty)];
                const double speed = kPairSpeed[static_cast<std::size_t>(difficulty)];
                const auto leftHeading = angle07(static_cast<int>(enemy.secondaryAngle16) -
                                                 static_cast<int>(enemy.targetAngle16));
                const auto rightHeading = angle07(static_cast<int>(enemy.secondaryAngle16) +
                                                  static_cast<int>(enemy.targetAngle16));
                if (sub < 12 && sub % 3 == 0) {
                    spawnProjectileSpread(7, 0, leftX, leftY, leftHeading,
                                          10.0f, speed, 1, count, spread, 0);
                    spawnProjectileSpread(7, 0, rightX, rightY, rightHeading,
                                          10.0f, speed, 1, count, spread, 0);
                    fired = true;
                }
                if (sub == 0) {
                    spawnProjectileSpread(0x0f, 0, leftX, leftY, leftHeading,
                                          20.0f, speed, 1, count, spread, 0);
                    spawnProjectileSpread(0x0f, 0, rightX, rightY, rightHeading,
                                          20.0f, speed, 1, count, spread, 0);
                    fired = true;
                }
            }
            if (local >= 35 && local < 70 &&
                (local - 35) % pairCadence == 0) {
                static constexpr std::array<int, 5> kTurn{{5000, 3000, 2700, 2400, 2000}};
                enemy.targetAngle16 = angle07(
                    static_cast<int>(enemy.targetAngle16) +
                    kTurn[static_cast<std::size_t>(difficulty)]);
            }

            static constexpr std::array<int, 5> kAimCadence{{36, 20, 18, 18, 16}};
            static constexpr std::array<int, 5> kAimCount{{5, 9, 11, 9, 11}};
            static constexpr std::array<double, 5> kAimSpeed{{6.0, 8.0, 10.0, 10.0, 12.0}};
            if (local >= 50 && local < 100 &&
                (local - 50) % kAimCadence[static_cast<std::size_t>(difficulty)] == 0) {
                const auto aimed = aimFrom(centerX, centerY);
                const int count = kAimCount[static_cast<std::size_t>(difficulty)];
                const double speed = kAimSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(2, 7, centerX, centerY, aimed,
                                      10.0f, speed, 1, count, 27000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(2, 7, centerX, centerY, aimed,
                                          10.0f, speed + 1.5, 1,
                                          count, 27000, 0);
                }
                fired = true;
            }
        }
        if (timer % 14 == 1) {
            playPlayerSound(bossSe14SoundHandle_, 0x13);
        }
        break;
    }
    case 0x77: {
        if (timer >= 120 && timer < 1200 && enemy.y < 360.0f) {
            const int local = (timer - 120) % 0x148;
            static constexpr std::array<int, 5> kRingCadence{{19, 13, 11, 10, 8}};
            static constexpr std::array<int, 5> kRingCount{{6, 8, 9, 10, 10}};
            static constexpr std::array<int, 5> kSpin{{80, 100, 100, 120, 150}};
            static constexpr std::array<double, 5> kRingSpeed{{5.4, 6.0, 6.5, 7.0, 8.0}};
            const int cadence = kRingCadence[static_cast<std::size_t>(difficulty)];
            const int count = kRingCount[static_cast<std::size_t>(difficulty)];
            const int direction = enemy.originX >= 360.0f ? -1 : 1;
            const auto center = angle07(direction * timer *
                                        kSpin[static_cast<std::size_t>(difficulty)]);
            if (local < 120 && local % cadence == 0) {
                const double speed = kRingSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(4, 0, enemy.x, enemy.y + 10.0f,
                                      center, 0.0f, speed, 1,
                                      count, 0x10000, 0);
                const int offset = direction * (0x10000 / (count * 3));
                spawnProjectileSpread(4, 0, enemy.x, enemy.y + 10.0f,
                                      angle07(static_cast<int>(center) + offset),
                                      0.0f, speed - 0.5, 1,
                                      count, 0x10000, 0);
                fired = true;
            }

            static constexpr std::array<int, 5> kSourceCadence{{32, 15, 15, 15, 12}};
            static constexpr std::array<int, 5> kSourceCount{{3, 3, 5, 5, 7}};
            static constexpr std::array<double, 5> kSourceSpeed{{4.4, 5.0, 5.5, 6.0, 7.0}};
            const int sourceCadence = kSourceCadence[static_cast<std::size_t>(difficulty)];
            const int sourceCount = kSourceCount[static_cast<std::size_t>(difficulty)];
            const double bob = std::sin(static_cast<double>(timer) * kPi07 / 4.0) * 2.0;
            const auto baseAim = aimFrom(enemy.x, enemy.y + static_cast<float>(bob));
            const std::array<float, 4> px{{enemy.x - 125.0f, enemy.x + 125.0f,
                                          enemy.x + 125.0f, enemy.x - 125.0f}};
            const std::array<float, 4> py{{enemy.y + 125.0f, enemy.y + 125.0f,
                                          enemy.y + 40.0f, enemy.y + 40.0f}};
            for (int source = 0; source < 4; ++source) {
                const int start = 160 + source * sourceCadence;
                if (local >= start && local < 300 &&
                    (local - start) % (sourceCadence * 5) == 0) {
                    // FUN_1400a7760 reinitializes the inline MT sequence from
                    // the same helper timer for all four sources. Odd sources
                    // only change the post-random angle bias below.
                    const auto random = enemy07Rand(timer);
                    const int jitter = static_cast<int>(random % 10001u) -
                                       ((source & 1) == 0 ? 8000 : 2000);
                    const auto heading = angle07(static_cast<int>(baseAim) + jitter);
                    const double speed = kSourceSpeed[static_cast<std::size_t>(difficulty)];
                    const int spread = (sourceCount - 1) * 0x960;
                    spawnProjectileSpread(0x0c, 0,
                                          px[static_cast<std::size_t>(source)],
                                          py[static_cast<std::size_t>(source)],
                                          heading, static_cast<float>(bob),
                                          speed, 1, sourceCount, spread, 0);
                    if (difficulty > 2) {
                        spawnProjectileSpread(0x0c, 0,
                                              px[static_cast<std::size_t>(source)],
                                              py[static_cast<std::size_t>(source)],
                                              heading, static_cast<float>(bob),
                                              speed + 1.0, 1,
                                              sourceCount, spread, 0);
                    }
                    fired = true;
                }
            }
        }
        if (timer % 18 == 1) {
            playPlayerSound(bossSe15SoundHandle_, 0x13);
        }
        break;
    }
    case 0x78: {
        const int start =
            (enemy.entityId - enemy.parentEntityId) * 0x29 + 0x46;
        static constexpr std::array<int, 5> kCadence{{164, 123, 82, 82, 82}};
        static constexpr std::array<double, 5> kSpeed{{5.5, 6.6, 7.2, 7.7, 8.8}};
        if (timer >= start && enemy.y < 360.0f) {
            const int local = (timer - start) %
                              kCadence[static_cast<std::size_t>(difficulty)];
            if (local < 16 && local % 4 == 0) {
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                const double radians = radians07(enemy.sourceAngle16);
                const float sourceX = enemy.x +
                                      static_cast<float>(std::cos(radians) * 40.0);
                const float sourceY = enemy.y +
                                      static_cast<float>(std::sin(radians) * 40.0);
                for (int offset : {-600, 0, 600}) {
                    spawnProjectileNode(0x0d, 0, sourceX, sourceY,
                                        angle07(static_cast<int>(enemy.sourceAngle16) + offset),
                                        10.0f, speed, 1, 0);
                }
                if (difficulty > 2) {
                    for (int offset : {-4000, 4000}) {
                        spawnProjectileNode(0x0d, 0, sourceX, sourceY,
                                            angle07(static_cast<int>(enemy.sourceAngle16) + offset),
                                            10.0f, speed - 1.0, 1, 0);
                    }
                }
                fired = true;
            }
        }
        break;
    }
    default:
        break;
    }

    (void)fired;

    if (enemy.hp < 1) {
        const int rewardWindow = enemy.spawnType == 0x70 ? 0x168
                               : enemy.spawnType == 0x77 || enemy.spawnType == 0x78
                                     ? 0x708
                               : enemy.spawnType == 0x74 || enemy.spawnType == 0x75
                                     ? 600
                               : enemy.spawnType == 0x76 ? 800 : 500;
        // This is FUN_140079e20's mode, independent of FUN_14007b010's
        // per-type reward-weight argument stored on the entity.
        const int effectMode = enemy.spawnType == 0x70 || enemy.spawnType == 0x74
                                   ? 0
                             : enemy.spawnType == 0x76 ? 2
                                                       : 1;
        spawnEnemyDeathRewardBurst(enemy, rewardWindow, false);
        if (enemy.spawnType == 0x77) {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
            enemy.targetable = false;
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            return;
        }
        spawnEnemyDeathEffects(enemy, effectMode);
        enemy.targetable = false;
        enemy.active = false;
        if (enemy.spawnType == 0x78) {
            StageEnemy* parent = findEnemyById(enemy.parentEntityId);
            if (parent != nullptr && parent->liveChildCount > 0) {
                --parent->liveChildCount;
            }
        }
        return;
    }

    if (enemy.spawnType == 0x78) {
        return;
    }

    const float horizontalOrigin = player_.x / 6.0f;
    float left = horizontalOrigin - 180.0f;
    float right = horizontalOrigin + 780.0f;
    float top = -180.0f;
    float bottom = 900.0f;
    if (enemy.spawnType == 0x71 || enemy.spawnType == 0x72 ||
        enemy.spawnType == 0x73) {
        left = horizontalOrigin - 128.0f;
        right = horizontalOrigin + 728.0f;
        top = -128.0f;
        bottom = 848.0f;
        if (timer <= 150) return;
    }
    else if (enemy.spawnType == 0x75) {
        left = horizontalOrigin - 300.0f;
        right = horizontalOrigin + 900.0f;
        top = -500.0f;
        bottom = 1016.0f;
    }
    else if (enemy.spawnType == 0x77) {
        left = horizontalOrigin - 240.0f;
        right = horizontalOrigin + 840.0f;
        top = -220.0f;
        bottom = 960.0f;
    }
    if (enemy.x < left || enemy.x > right ||
        enemy.y < top || enemy.y > bottom) {
        enemy.targetable = false;
        enemy.active = false;
        if (enemy.spawnType == 0x77) {
            clearLateStageGate(7);
        }
    }
}

bool StageRuntime::drawStage07Enemy(const StageEnemy& enemy,
                                    float x, float y) const {
    if (enemy.spawnType < 0x70 || enemy.spawnType > 0x78) {
        return false;
    }

    if (enemy.drawMarkerThisFrame) {
        const int marker = frame07(effectMediumFrames_, 4);
        if (marker != -1) {
            double scale = 2.0 - enemy.markerDrawTimer * 0.1;
            if (enemy.spawnType == 0x71 || enemy.spawnType == 0x72 ||
                enemy.spawnType == 0x73) {
                scale = 3.0 - enemy.markerDrawTimer * 0.15;
            }
            else if (enemy.spawnType == 0x76 || enemy.spawnType == 0x77) {
                scale = 4.0 - enemy.markerDrawTimer * 0.2;
            }
            DrawRotaGraphF(x + enemy.markerDrawX - enemy.x,
                           y + enemy.markerDrawY - enemy.y,
                           std::max(0.0, scale), 0.0, marker, TRUE);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const auto drawSmall = [this](int index, float px, float py,
                                   std::uint16_t angle = 0,
                                   bool reverse = false) {
        const int handle = frame07(enemySmallFrames_, index);
        if (handle != -1) {
            drawOriginalMode7Node(handle, px, py, angle, 1.0, 1.0, reverse);
        }
    };
    const auto drawMedium = [this](int index, float px, float py,
                                    std::uint16_t angle = 0,
                                    bool reverse = false) {
        const int handle = frame07(enemyMediumFrames_, index);
        if (handle != -1) {
            drawOriginalMode7Node(handle, px, py, angle, 1.0, 1.0, reverse);
        }
    };
    const auto drawLarge = [this](int index, float px, float py,
                                   std::uint16_t angle = 0,
                                   bool reverse = false) {
        const int handle = frame07(enemyLargeFrames_, index);
        if (handle != -1) {
            drawOriginalMode7Node(handle, px, py, angle, 1.0, 1.0, reverse);
        }
    };

    const int timer = enemy.drawHelperTimer;
    switch (enemy.spawnType) {
    case 0x70: {
        const float anchorX = x + enemy.originX - enemy.x;
        const float anchorY = y + enemy.originY - enemy.y;
        const auto spin = angle07(timer * 0xf3c);
        drawSmall(78, anchorX, anchorY, spin);
        drawSmall(78, anchorX, anchorY, angle07(static_cast<int>(spin) + 0x8000));
        drawSmall(79, anchorX, anchorY);
        drawSmall(80, x, y, enemy.secondaryAngle16);
        const double radians = radians07(enemy.secondaryAngle16);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
        drawSmall(81,
                  x + static_cast<float>(std::cos(radians) * 55.0),
                  y + static_cast<float>(std::sin(radians) * 55.0),
                  enemy.secondaryAngle16);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        break;
    }
    case 0x71:
    case 0x72: {
        const int sway = static_cast<int>(
            std::sin(static_cast<double>(timer) * kTau07 / 240.0) * 1800.0);
        drawMedium(114, x, y - 18.0f, angle07(sway));
        drawMedium(114, x, y - 18.0f, angle07(-sway), true);
        drawMedium(113, x, y - 18.0f, angle07(sway / 2));
        drawMedium(113, x, y - 18.0f, angle07(-sway / 2), true);
        drawMedium(110 + (timer / 5) % 2, x, y);
        break;
    }
    case 0x73: {
        drawMedium(116, x, y + 25.0f, enemy.secondaryAngle16);
        drawMedium(115, x, y);
        const std::array<float, 4> px{{x + 85.0f, x - 85.0f,
                                      x - 83.0f, x + 83.0f}};
        const std::array<float, 4> py{{y + 50.0f, y + 50.0f,
                                      y - 35.0f, y - 35.0f}};
        for (int i = 0; i < 4; ++i) {
            const int sign = (i & 1) == 0 ? 1 : -1;
            drawMedium(117, px[static_cast<std::size_t>(i)],
                       py[static_cast<std::size_t>(i)],
                       angle07(sign * timer * 0xe10), (i & 1) != 0);
        }
        break;
    }
    case 0x74: {
        int frame = 82 + (timer / 5) % 2;
        const int cycle = positiveMod07(timer + 0x2670, 0x140);
        if ((cycle >= 30 && cycle < 35) || (cycle >= 125 && cycle < 130)) {
            frame = 87;
        }
        else if (cycle >= 35 && cycle < 125) {
            frame = 88 + ((cycle - 35) / 5) % 2;
        }
        else if ((cycle >= 190 && cycle < 195) ||
                 (cycle >= 285 && cycle < 290)) {
            frame = 84;
        }
        else if (cycle >= 195 && cycle < 285) {
            frame = 85 + ((cycle - 195) / 5) % 2;
        }
        drawSmall(frame, x, y);
        break;
    }
    case 0x75: {
        const float wave = static_cast<float>(
            std::sin(static_cast<double>(timer) * kTau07 / 5.0) * 1.5);
        drawSmall(92 + (timer / 5) % 2, x, y + 28.0f);
        drawSmall(90, x, y + 18.0f + wave);
        drawSmall(91, x, y + wave);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
        drawSmall(90, x, y + 25.0f + wave);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        break;
    }
    case 0x76: {
        const double bob = std::sin(static_cast<double>(timer - 2) *
                                    kPi07 / 4.0) * 2.0;
        const double radians = radians07(enemy.secondaryAngle16);
        const float centerX = x + static_cast<float>(std::cos(radians) * -60.0);
        const float centerY = y + static_cast<float>(bob) +
                              static_cast<float>(std::sin(radians) * -60.0);
        const double leftRadians = radians07(angle07(
            static_cast<int>(enemy.secondaryAngle16) - 0x32c8));
        const double rightRadians = radians07(angle07(
            static_cast<int>(enemy.secondaryAngle16) + 0x32c8));
        const float leftX = centerX +
                            static_cast<float>(std::cos(leftRadians) * 87.0);
        const float leftY = centerY +
                            static_cast<float>(std::sin(leftRadians) * 87.0);
        const float rightX = centerX +
                             static_cast<float>(std::cos(rightRadians) * 87.0);
        const float rightY = centerY +
                             static_cast<float>(std::sin(rightRadians) * 87.0);
        drawSmall(94 + (timer / 5) % 2, x + 75.0f, y + 90.0f);
        drawSmall(94 + (timer / 5) % 2, x - 75.0f, y + 90.0f, 0, true);
        drawMedium(118, x, y + 5.0f + static_cast<float>(bob));
        drawMedium(119, x + 75.0f, y + 10.0f + static_cast<float>(bob));
        drawMedium(119, x - 75.0f, y + 10.0f + static_cast<float>(bob), 0, true);
        drawMedium(120, x, y + static_cast<float>(bob),
                   angle07(static_cast<int>(enemy.secondaryAngle16) - 0x4000));
        drawMedium(121, centerX, centerY,
                   angle07(static_cast<int>(enemy.secondaryAngle16) - 0x4000));
        drawMedium(122, leftX, leftY,
                   angle07(static_cast<int>(enemy.secondaryAngle16) - 0x4000));
        drawMedium(122, rightX, rightY,
                   angle07(static_cast<int>(enemy.secondaryAngle16) - 0x4000), true);
        break;
    }
    case 0x77: {
        const float bob = static_cast<float>(
            std::sin(static_cast<double>(timer) * kPi07 / 4.0) * 2.0);
        const auto panelAngle = angle07(static_cast<int>(
            std::sin(static_cast<double>(frame_) * kTau07 / 164.0) *
            2000.0));
        drawSmall(96 + (timer / 5) % 2, x + 65.0f, y + 280.0f);
        drawSmall(96 + (timer / 5) % 2, x - 65.0f, y + 280.0f, 0, true);
        drawLarge(41, x, y + 90.0f + bob);
        drawMedium(124, x, y + bob);
        drawMedium(125, x - 65.0f, y - 100.0f + bob, panelAngle);
        SetDrawBright(0, 0x20, 0x40);
        drawLarge(41, x, y + 150.0f + bob);
        SetDrawBright(255, 255, 255);
        break;
    }
    case 0x78:
        drawMedium(123, x, y, enemy.sourceAngle16);
        break;
    default:
        break;
    }

    if (enemy.targetable && enemy.maxHp >= 1000) {
        StageEnemy gauge = enemy;
        gauge.hp = enemy.drawHp;
        int mode = 1;
        if (enemy.spawnType == 0x70 || enemy.spawnType == 0x74 ||
            enemy.spawnType == 0x75 || enemy.spawnType == 0x78) {
            mode = 2;
        }
        else if (enemy.spawnType == 0x77) {
            mode = 0;
        }
        drawEnemyGaugeExact(gauge, mode, x, y);
    }
    return true;
}

} // namespace reconstructed
