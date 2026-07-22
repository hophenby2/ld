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
constexpr std::size_t kStageEntityCap = 0x200;

bool isStage10EnemyType(int spawnType) {
    return spawnType >= 0xfa && spawnType <= 0x104;
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

std::uint16_t approachAngle16(std::uint16_t current,
                              std::uint16_t target, int step) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    delta = std::clamp(delta, -step, step);
    return normalizeAngle16(static_cast<int>(current) + delta);
}

std::uint32_t stage10ScriptRand(std::uint32_t seed) {
    const std::uint32_t u = ((seed >> 30) ^ seed) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

std::uint16_t stage10RandomAngle(std::uint32_t seed) {
    const std::uint32_t random = stage10ScriptRand(seed);
    return static_cast<std::uint16_t>(random - random / 0x10001u);
}

int frameHandle(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

} // namespace

void StageRuntime::updateStage10Enemy(StageEnemy& enemy) {
    if (!isStage10EnemyType(enemy.spawnType)) {
        return;
    }

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    const auto aimFrom = [this](float x, float y) {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto moveAlongHeading = [&enemy]() {
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
        enemy.speed = static_cast<float>(enemy.sourceSpeed);
        enemy.angle = static_cast<float>(radians);
    };
    const auto markerPoint = [this](float x, float y, float margin) {
        const float horizontalOrigin = player_.x / 6.0f;
        return std::array<float, 2>{{
            std::clamp(x, horizontalOrigin + margin,
                       horizontalOrigin + 600.0f - margin),
            std::clamp(y, margin, 720.0f - margin),
        }};
    };
    const auto outsideSmallBounds = [this](const StageEnemy& target) {
        const float horizontalOrigin = player_.x / 6.0f;
        return target.x < horizontalOrigin - 180.0f ||
               target.x > horizontalOrigin + 780.0f ||
               target.y < -180.0f || target.y > 900.0f;
    };
    const auto outsideLargeBounds = [this](const StageEnemy& target) {
        const float horizontalOrigin = player_.x / 6.0f;
        return target.x < horizontalOrigin - 128.0f ||
               target.x > horizontalOrigin + 728.0f ||
               target.y < -128.0f || target.y > 848.0f;
    };
    const auto finishDeath = [this](StageEnemy& target, int rewardWindow,
                                     int effectMode) {
        spawnEnemyDeathRewardBurst(target, rewardWindow, false);
        spawnEnemyDeathEffects(target, effectMode);
        target.targetable = false;
        target.targetableTimer = 0;
        target.active = false;
    };

    if (enemy.spawnType == 0xff || enemy.spawnType == 0x101) {
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr ||
            (enemy.spawnType == 0xff && parent->spawnType != 0xfe) ||
            (enemy.spawnType == 0x101 && parent->spawnType != 0x100)) {
            if (parent != nullptr && parent->liveChildCount > 0) {
                --parent->liveChildCount;
            }
            enemy.active = false;
            return;
        }

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
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        enemy.targetable = false;
        if (parent->hp < 1 || !parent->active) {
            // FUN_14008bd60 queues the owner's terminal-frame child shot and
            // body before its owner-HP/owner-active cleanup tail.
            emitStage10EnemyProjectiles(enemy);
            if (parent->hp < 1) {
                spawnEnemyDeathEffects(enemy, 0);
            }
            if (parent->liveChildCount > 0) {
                --parent->liveChildCount;
            }
            enemy.active = false;
        }
        return;
    }

    const bool pendingDeath = enemy.hp < 1;
    const auto finishPendingDeath = [&]() {
        switch (enemy.spawnType) {
        case 0xfa:
        case 0xfb:
            finishDeath(enemy, 200, 0);
            break;
        case 0xfc:
        case 0xfd:
            finishDeath(enemy, 300, 0);
            break;
        default:
            finishDeath(enemy, 500, 1);
            break;
        }
    };

    const auto spawnChild = [this, &enemy](int spawnType, float offsetX,
                                            float offsetY,
                                            std::uint16_t angle16,
                                            int childIndex) {
        if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
            return;
        }
        StageEnemy child;
        child.entityId = nextEntityId_++;
        child.spawnType = spawnType;
        child.updateCase = 0x1c;
        child.sourceHitPoints = 99999999;
        child.sourceX = static_cast<int>(std::lround(offsetX));
        child.sourceY = static_cast<int>(std::lround(offsetY));
        child.sourceNote = spawnType == 0xff
                               ? "S10 FUN_1400b14d0 satellite 0xff"
                               : "S10 FUN_1400b1db0 satellite 0x101";
        child.sourceDispatchKind = 1;
        child.sourceDispatchField = 20;
        child.parentEntityId = enemy.entityId;
        child.parentSpawnType = enemy.spawnType;
        child.childIndex = childIndex;
        child.x = enemy.x;
        child.y = enemy.y;
        child.originX = offsetX;
        child.originY = offsetY;
        child.sourceAngle16 = angle16;
        child.secondaryAngle16 = angle16;
        child.targetAngle16 = angle16;
        child.angle = static_cast<float>(fixedAngleRadians(angle16));
        child.sourceSpeed = 0.0;
        child.speed = 0.0f;
        child.hp = 99999999;
        child.maxHp = child.hp;
        child.drawHp = child.hp;
        child.radius = 20;
        child.activationDelay = 0;
        child.helperState = 1;
        child.targetable = false;
        pendingEnemies_.push_back(child);
        ++enemy.liveChildCount;
    };

    if (enemy.helperState == 0) {
        if (enemy.helperTimer == 0) {
            if (enemy.spawnType == 0xfe) {
                enemy.x = enemy.originX < 360.0f ? -100.0f : 820.0f;
                enemy.y = -100.0f;
            }
            else if (enemy.spawnType == 0x100) {
                enemy.x = enemy.originX < 360.0f ? -100.0f : 820.0f;
                enemy.y = -100.0f;
            }
            else if (enemy.spawnType == 0x103) {
                enemy.sourceAngle16 = 0x64a8;
            }
            else if (enemy.spawnType == 0x104) {
                enemy.sourceAngle16 = 7000;
            }
        }

        float markerX = enemy.x;
        float markerY = enemy.y;
        float markerMargin = -50.0f;
        if (enemy.spawnType <= 0xfd) {
            markerMargin = -20.0f;
        }
        if (enemy.spawnType == 0x103 || enemy.spawnType == 0x104) {
            const double radians = fixedAngleRadians(enemy.sourceAngle16);
            const double distance = -static_cast<double>(enemy.y) * 0.8;
            markerX += static_cast<float>(std::cos(radians) * distance);
            markerY += static_cast<float>(std::sin(radians) * distance);
        }
        const auto point = markerPoint(markerX, markerY, markerMargin);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = point[0];
        enemy.markerDrawY = point[1];

        if (enemy.helperTimer < 20) {
            if (pendingDeath) finishPendingDeath();
            return;
        }

        switch (enemy.spawnType) {
        case 0xfa:
            enemy.sourceSpeed = 7.0;
            if (enemy.originY > 0.0f) {
                if (enemy.originX <= 0.0f) enemy.sourceAngle16 = 0;
                if (enemy.originX >= 720.0f) enemy.sourceAngle16 = 0x8000;
            }
            else {
                enemy.sourceAngle16 = enemy.originX < 360.0f
                                          ? static_cast<std::uint16_t>(0x18f1)
                                          : static_cast<std::uint16_t>(0x670f);
            }
            enemy.secondaryAngle16 = aimFrom(enemy.x, enemy.y);
            break;
        case 0xfb: {
            enemy.sourceSpeed = 5.0;
            enemy.sourceAngle16 = normalizeAngle16(
                0x3a24 + static_cast<int>(stage10ScriptRand(
                                     static_cast<std::uint32_t>(frame_)) %
                                 3001u));
            const auto active = markerPoint(enemy.x, enemy.y, -20.0f);
            enemy.x = active[0];
            enemy.y = active[1];
            break;
        }
        case 0xfc: {
            enemy.sourceSpeed = 2.0;
            enemy.sourceAngle16 = 0x4000;
            const auto active = markerPoint(enemy.x, enemy.y, -60.0f);
            enemy.x = active[0];
            enemy.y = active[1];
            break;
        }
        case 0xfd: {
            enemy.sourceSpeed = 6.0;
            const auto active = markerPoint(enemy.x, enemy.y, -50.0f);
            enemy.x = active[0];
            enemy.y = active[1];
            if (enemy.x <= 0.0f) enemy.sourceAngle16 = 0;
            else if (enemy.x >= 720.0f) enemy.sourceAngle16 = 0x8000;
            break;
        }
        case 0xfe:
            spawnChild(0xff, 50.0f, -50.0f, 0, 0);
            spawnChild(0xff, -50.0f, -50.0f, 0, 1);
            spawnChild(0xff, 100.0f, -20.0f, 0x1130, 2);
            spawnChild(0xff, -100.0f, -20.0f, 0xeed0, 3);
            enemy.sourceSpeed = 11.5;
            enemy.sourceAngle16 = radiansToAngle16(std::atan2(
                static_cast<double>(enemy.originY - enemy.y),
                static_cast<double>(enemy.originX - enemy.x)));
            break;
        case 0x100:
            spawnChild(0x101, 70.0f, -40.0f, 0, 0);
            spawnChild(0x101, -70.0f, -40.0f, 0, 1);
            enemy.sourceSpeed = 11.5;
            enemy.sourceAngle16 = radiansToAngle16(std::atan2(
                static_cast<double>(enemy.originY - enemy.y),
                static_cast<double>(enemy.originX - enemy.x)));
            break;
        case 0x102:
            enemy.sourceSpeed = 7.0;
            break;
        case 0x103:
        case 0x104:
            enemy.sourceSpeed = 12.0;
            break;
        default:
            break;
        }

        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
    }

    const int timer = enemy.helperTimer;
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    switch (enemy.spawnType) {
    case 0xfa: {
        const auto aimed = aimFrom(enemy.x, enemy.y);
        int turn = 0;
        if (enemy.originY > 0.0f) {
            turn = timer > 109 ? 0x3c : 400;
            if ((enemy.originX <= 0.0f && enemy.originY >= 250.0f) ||
                (enemy.originX >= 720.0f && enemy.originY < 250.0f)) {
                turn = -turn;
            }
        }
        else {
            turn = timer > 89 ? 0x3c : 400;
            if (enemy.originX >= 360.0f) turn = -turn;
        }
        enemy.sourceAngle16 = normalizeAngle16(
            static_cast<int>(enemy.sourceAngle16) + turn);
        moveAlongHeading();
        int delta = static_cast<int>(aimed) -
                    static_cast<int>(enemy.secondaryAngle16);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        enemy.secondaryAngle16 = approachAngle16(
            enemy.secondaryAngle16, aimed, std::abs(delta) / 10 + 0x30);
        if (outsideSmallBounds(enemy)) enemy.active = false;
        break;
    }
    case 0xfb:
        if (timer < 200) {
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimFrom(enemy.x, enemy.y), 0xff);
        }
        enemy.sourceSpeed += 0.05;
        moveAlongHeading();
        if (outsideSmallBounds(enemy)) enemy.active = false;
        break;
    case 0xfc:
        if (timer < 180) {
            const double radians = fixedAngleRadians(enemy.sourceAngle16);
            enemy.originX += static_cast<float>(
                std::cos(radians) * enemy.sourceSpeed);
            enemy.originY += static_cast<float>(
                std::sin(radians) * enemy.sourceSpeed);
            const std::uint32_t random = stage10ScriptRand(
                static_cast<std::uint32_t>(frame_ - timer));
            const double amplitude = (random & 1u) == 0u ? 60.0 : -60.0;
            enemy.x = enemy.originX +
                      static_cast<float>(
                          std::sin(static_cast<double>(timer) * kPi / 120.0) *
                          amplitude);
            enemy.y = enemy.originY;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16,
                aimFrom(enemy.originX, enemy.originY), 0x40);
        }
        else {
            moveAlongHeading();
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, 0xc000, 0xa0);
            enemy.sourceSpeed += 0.1;
        }
        enemy.speed = static_cast<float>(enemy.sourceSpeed);
        enemy.angle = static_cast<float>(fixedAngleRadians(
            enemy.sourceAngle16));
        if (outsideSmallBounds(enemy)) enemy.active = false;
        break;
    case 0xfd:
        if (timer < 90) {
            if (enemy.sourceSpeed > 2.0) enemy.sourceSpeed -= 0.05;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimFrom(enemy.x, enemy.y), 0x30);
        }
        else {
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, 0xc000, 0x200);
            enemy.sourceSpeed += 0.1;
        }
        moveAlongHeading();
        if (outsideSmallBounds(enemy)) enemy.active = false;
        break;
    case 0xfe:
    case 0x100: {
        const auto target = radiansToAngle16(std::atan2(
            static_cast<double>(enemy.originY - enemy.y),
            static_cast<double>(enemy.originX - enemy.x)));
        if (timer < 240) {
            const int firstRetarget = enemy.spawnType == 0xfe ? 60 : 70;
            if (timer >= firstRetarget &&
                (timer - firstRetarget) % 50 == 0) {
                const std::uint32_t xSeed = static_cast<std::uint32_t>(
                    timer * enemy.entityId *
                    (enemy.spawnType == 0xfe ? 888 : 999));
                const std::uint32_t ySeed = static_cast<std::uint32_t>(
                    timer * enemy.entityId *
                    (enemy.spawnType == 0xfe ? 8888 : 9999));
                enemy.originX = 120.0f + static_cast<float>(
                    stage10ScriptRand(xSeed) % 481u);
                enemy.originY = static_cast<float>(timer) +
                                static_cast<float>(stage10ScriptRand(ySeed) %
                                                   101u);
            }
            const double minimum = enemy.spawnType == 0xfe ? 3.0 : 2.5;
            if (timer < 61 && enemy.sourceSpeed > minimum) {
                enemy.sourceSpeed -= 0.15;
            }
        }
        else {
            enemy.sourceSpeed += 0.1;
            enemy.originY = -500.0f;
        }
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, target, 0x200);
        moveAlongHeading();
        if ((timer & 3) == 0) {
            const int graph = frameHandle(
                enemyMediumFrames_, enemy.spawnType == 0xfe ? 204 : 206);
            spawnStageEffect(5, graph, 200, 0x21,
                             enemy.x, enemy.y, 0,
                             0.0, 1.0, 1.0, 0x18,
                             0xff, 0xff, 0xff, 0x40);
        }
        if (timer > 239 && outsideLargeBounds(enemy)) enemy.active = false;
        break;
    }
    case 0x102:
        if (timer < 121 && enemy.sourceSpeed > 1.2) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, aimFrom(enemy.x, enemy.y), 0x80);
        if (timer > 299) enemy.sourceSpeed -= 0.1;
        moveAlongHeading();
        if (outsideLargeBounds(enemy)) enemy.active = false;
        break;
    case 0x103:
    case 0x104: {
        const auto aimed = aimFrom(enemy.x, enemy.y);
        if (timer < 100) {
            if (enemy.sourceSpeed > 0.0) enemy.sourceSpeed -= 0.12;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimed, 0x20);
        }
        else if (timer < 240) {
            if (timer == 100) enemy.sourceAngle16 = aimed;
            if (timer < 130) enemy.sourceSpeed += 0.05;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimed, 0x80);
        }
        else {
            enemy.sourceSpeed -= 0.1;
        }
        moveAlongHeading();
        if (timer > 119 && outsideLargeBounds(enemy)) enemy.active = false;
        break;
    }
    default:
        break;
    }

    if (pendingDeath) {
        // The original helpers queue the lethal frame's movement, bullets,
        // body, and gauge before their shared HP/death tail unlinks the node.
        emitStage10EnemyProjectiles(enemy);
        finishPendingDeath();
    }
}

void StageRuntime::emitStage10EnemyProjectiles(StageEnemy& enemy) {
    if (!enemy.active || !isStage10EnemyType(enemy.spawnType) ||
        enemy.helperState != 1) {
        return;
    }

    const int timer = enemy.helperTimer;
    const float horizontalOrigin = player_.x / 6.0f;
    const auto aimFrom = [this](float x, float y) {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto onScreen = [horizontalOrigin](float x, float y) {
        return x >= horizontalOrigin && x <= horizontalOrigin + 600.0f &&
               y >= 0.0f && y <= 720.0f;
    };

    switch (enemy.spawnType) {
    case 0xfa: {
        if (timer >= 200 || frame_ % 10 != 0) break;
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        const float x = enemy.x +
                        static_cast<float>(std::cos(radians) * 45.0);
        const float y = enemy.y +
                        static_cast<float>(std::sin(radians) * 45.0);
        const float dx = player_.x - x;
        const float dy = player_.y - y;
        if (x >= horizontalOrigin + 20.0f &&
            x <= horizontalOrigin + 580.0f && y >= 20.0f && y <= 700.0f &&
            y < 520.0f && dx * dx + dy * dy >= 90.0f * 90.0f) {
            const auto snapped = normalizeAngle16(
                (static_cast<int>(enemy.secondaryAngle16) + 0x400) &
                ~0x7ff);
            spawnProjectileNode(9, 0, x, y, snapped, 0.0f, 7.7, 1, 0);
        }
        break;
    }
    case 0xfb: {
        if (timer >= 200 || timer % 18 != 0 ||
            enemy.x < horizontalOrigin + 20.0f ||
            enemy.x > horizontalOrigin + 580.0f || enemy.y < 20.0f ||
            enemy.y > 700.0f || enemy.y >= 420.0f) {
            break;
        }
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        const float x = enemy.x +
                        static_cast<float>(std::cos(radians) * 45.0);
        const float y = enemy.y +
                        static_cast<float>(std::sin(radians) * 45.0);
        const float dx = player_.x - x;
        const float dy = player_.y - y;
        if (dx * dx + dy * dy >= 90.0f * 90.0f) {
            spawnProjectileNode(8, 0, x, y, enemy.sourceAngle16,
                                0.0f, 7.7, 1, 0);
        }
        break;
    }
    case 0xfc: {
        if (timer < 40 || timer >= 180) break;
        const int local = (timer - 40) % 50;
        if (local >= 20 || local % 5 != 0) break;
        const float front = static_cast<float>(
            std::sin(static_cast<double>(timer) * kPi / 25.0) - 20.0);
        const float sourceY = enemy.y + front;
        if (local == 0) {
            enemy.secondaryAngle16 = aimFrom(enemy.x, sourceY);
        }
        if (!onScreen(enemy.x, sourceY)) break;
        const double speed = 8.8 + local * 0.1;
        spawnProjectileNode(0x0c, 0, enemy.x, sourceY,
                            enemy.secondaryAngle16, 0.0f, speed, 1, 0);
        spawnProjectileNode(4, 0, enemy.x + 25.0f, sourceY - 30.0f,
                            enemy.secondaryAngle16, 0.0f, speed, 1, 0);
        spawnProjectileNode(4, 0, enemy.x - 25.0f, sourceY - 30.0f,
                            enemy.secondaryAngle16, 0.0f, speed, 1, 0);
        break;
    }
    case 0xfd: {
        if (timer < 10 || timer >= 90) break;
        const int local = (timer - 10) % 60;
        if (local >= 24 || local % 4 != 0) break;
        if (local == 0) {
            enemy.secondaryAngle16 = aimFrom(enemy.x, enemy.y + 40.0f);
        }
        const int count = local / 4 + 1;
        spawnProjectileSpread(0x0d, 0, enemy.x, enemy.y + 40.0f,
                              enemy.secondaryAngle16, 10.0f, 9.0, 1,
                              count, (count - 1) * 400, 0);
        break;
    }
    case 0xff: {
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->helperTimer >= 240 || timer < 75) {
            break;
        }
        const int local = (timer - 75) % 60;
        if (local >= 40 || local % 5 != 0) break;
        if (local == 0) {
            enemy.secondaryAngle16 = aimFrom(parent->x, parent->y);
        }
        spawnProjectileNode(
            7, 0, enemy.x, enemy.y,
            normalizeAngle16(static_cast<int>(enemy.sourceAngle16) +
                             static_cast<int>(enemy.secondaryAngle16)),
            10.0f, 7.5 + local * 0.08, 1, 0);
        break;
    }
    case 0x100: {
        if (timer < 70 || timer >= 240) break;
        const int local = (timer - 70) % 60;
        if (local >= 40 || local % 5 != 0) break;
        if (local == 0) {
            enemy.secondaryAngle16 = aimFrom(enemy.x, enemy.y);
        }
        const double speed = 7.2 + local * 0.08;
        spawnProjectileNode(7, 0, enemy.x + 16.0f, enemy.y + 16.0f,
                            enemy.secondaryAngle16, 10.0f, speed, 1, 0);
        spawnProjectileNode(7, 0, enemy.x - 16.0f, enemy.y + 16.0f,
                            enemy.secondaryAngle16, 10.0f, speed, 1, 0);
        break;
    }
    case 0x101: {
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->helperTimer >= 240 || timer < 70 ||
            (timer - 70) % 14 != 0) {
            break;
        }
        const auto aimed = aimFrom(parent->x, parent->y);
        const int local = (timer - 70) % 120;
        int center = 0;
        if (enemy.originX < 0.0f) {
            center = local < 60 ? -local * 400 + 12000
                                : local * 400 + 0x7360;
        }
        else {
            center = local < 60 ? local * 400 - 12000
                                : -local * 400 - 0x7360;
        }
        center += static_cast<int>(aimed);
        for (int i = 0; i < 5; ++i) {
            spawnProjectileNode(4, 0, enemy.x, enemy.y,
                                normalizeAngle16(center - 900 + i * 450),
                                0.0f, 6.0, 1, 0);
        }
        break;
    }
    case 0x102: {
        if (timer < 24 || timer >= 300) break;
        const float bodyWave = static_cast<float>(
            2.0 * std::sin(static_cast<double>(timer - 36) * kTau / 70.0));
        const float leftX = enemy.x - 68.0f;
        const float leftY = enemy.y + bodyWave - 50.0f;
        const float rightX = enemy.x + 65.0f;
        const float rightY = enemy.y + bodyWave + 27.0f;
        const int local = (timer - 24) % 50;
        const auto leftAim = aimFrom(leftX, leftY);
        if (local == 0) enemy.secondaryAngle16 = leftAim;
        if (local < 40 && onScreen(leftX, leftY)) {
            // FUN_1400b2760 derives every scatter component from this
            // frame/timer key with a separate original multiplier.
            const std::uint32_t baseSeed = static_cast<std::uint32_t>(
                frame_ * 0x115c - timer * 0x115b);
            const double radius = static_cast<double>(
                stage10ScriptRand(baseSeed * 4u) % 11u);
            const auto scatter = stage10RandomAngle(baseSeed);
            const double scatterRadians = fixedAngleRadians(scatter);
            const float shotX = leftX +
                static_cast<float>(std::cos(scatterRadians) * radius);
            const float shotY = leftY +
                static_cast<float>(std::sin(scatterRadians) * radius);
            const int angleJitter = static_cast<int>(
                stage10ScriptRand(baseSeed * 44u) % 1601u) - 800;
            spawnProjectileNode(
                0x0d, 0, shotX, shotY,
                normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) +
                                 angleJitter),
                0.0f, 6.0 + local * 0.2, 1, 0);
            enemy.secondaryAngle16 = approachAngle16(
                enemy.secondaryAngle16, leftAim, 0x48);
        }

        if (timer >= 64 && (timer - 64) % 100 == 0) {
            const auto rightAim = aimFrom(rightX, rightY);
            const std::uint32_t baseSeed = static_cast<std::uint32_t>(
                frame_ * 0x115c - timer * 0x115b);
            for (int i = 0; i < 15; ++i) {
                const auto ordinal = static_cast<std::uint32_t>(i);
                const double radius = static_cast<double>(
                    stage10ScriptRand(baseSeed * 444u + ordinal) % 33u);
                const auto scatter = stage10RandomAngle(
                    baseSeed * 4444u + ordinal);
                const double scatterRadians = fixedAngleRadians(scatter);
                const int angleJitter = static_cast<int>(
                    stage10ScriptRand(baseSeed * 66u + ordinal) % 24001u) -
                    12000;
                const double speed = 3.0 +
                    static_cast<double>(
                        stage10ScriptRand(baseSeed * 666u + ordinal) % 401u) /
                        100.0;
                spawnProjectileNode(
                    0, 0,
                    rightX + static_cast<float>(
                                 std::cos(scatterRadians) * radius),
                    rightY + static_cast<float>(
                                 std::sin(scatterRadians) * radius),
                    normalizeAngle16(static_cast<int>(rightAim) + angleJitter),
                    0.0f, speed, 1, 0);
            }
        }
        break;
    }
    case 0x103:
    case 0x104: {
        if (timer < 50 || timer >= 240) break;
        const int local = (timer - 50) % 100;
        if (local == 0) {
            enemy.secondaryAngle16 = aimFrom(enemy.x, enemy.y - 64.0f);
        }
        if (local >= 30 || local % 5 != 0) break;
        constexpr std::array<float, 4> kOffsetX{{24.0f, -24.0f,
                                                  49.0f, -49.0f}};
        constexpr std::array<float, 4> kOffsetY{{-36.0f, -36.0f,
                                                  -64.0f, -64.0f}};
        constexpr std::array<int, 4> kAngleOffset{{-1500, 1500,
                                                    -3600, 3600}};
        for (std::size_t i = 0; i < kOffsetX.size(); ++i) {
            const float x = enemy.x + kOffsetX[i];
            const float y = enemy.y + kOffsetY[i];
            if (!onScreen(x, y)) continue;
            spawnProjectileNode(
                4, 0x34, x, y,
                normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) +
                                 kAngleOffset[i]),
                0.0f, 7.0, 1, 0);
        }
        break;
    }
    default:
        break;
    }
}

bool StageRuntime::drawStage10Enemy(const StageEnemy& enemy, float x,
                                    float y, int exactLayer) const {
    if (!isStage10EnemyType(enemy.spawnType)) {
        return false;
    }

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = frameHandle(effectMediumFrames_, 4);
        if (marker != -1) {
            const double startScale = enemy.spawnType <= 0xfd ? 2.0 : 3.0;
            const double step = enemy.spawnType <= 0xfd ? 0.1 : 0.15;
            const double scale = std::max(
                0.0, startScale - enemy.markerDrawTimer * step);
            DrawRotaGraphF(x + enemy.markerDrawX - enemy.x,
                           y + enemy.markerDrawY - enemy.y,
                           scale, 0.0, marker, TRUE);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    if (exactLayer == 0x64 && enemy.targetable &&
        enemy.spawnType != 0xff && enemy.spawnType != 0x101) {
        StageEnemy gauge = enemy;
        gauge.hp = enemy.drawHp;
        const int gaugeMode = enemy.spawnType <= 0xfd ? 2 : 1;
        drawEnemyGaugeExact(gauge, gaugeMode, x, y, exactLayer);
    }

    int bodyLayer = 0x23;
    if (enemy.spawnType >= 0xfc && enemy.spawnType <= 0x101) {
        bodyLayer = 0x22;
    }
    else if (enemy.spawnType == 0x102 ||
             enemy.spawnType == 0x103 || enemy.spawnType == 0x104) {
        bodyLayer = 0x20;
    }
    if (exactLayer != bodyLayer) {
        return true;
    }

    bool drew = false;
    const auto drawSmall = [this, &drew](int frame, float drawX,
                                          float drawY,
                                          std::uint16_t angle = 0,
                                          double scaleX = 1.0,
                                          double scaleY = 1.0,
                                          bool reverse = false) {
        const int graph = frameHandle(enemySmallFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  scaleX, scaleY, reverse);
            drew = true;
        }
    };
    const auto drawMedium = [this, &drew](int frame, float drawX,
                                           float drawY,
                                           std::uint16_t angle = 0,
                                           double scaleX = 1.0,
                                           double scaleY = 1.0,
                                           bool reverse = false) {
        const int graph = frameHandle(enemyMediumFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  scaleX, scaleY, reverse);
            drew = true;
        }
    };

    const int timer = enemy.drawHelperTimer;
    switch (enemy.spawnType) {
    case 0xfa:
    case 0xfb: {
        const bool first = enemy.spawnType == 0xfa;
        const int bodyFrame = first ? 152 : 154;
        const int wingFrame = first ? 153 : 155;
        const int spin = static_cast<int>(
            std::sin(static_cast<double>(timer) * kTau / 25.0) * 3333.0);
        const std::uint16_t visualAngle =
            first ? enemy.secondaryAngle16 : enemy.sourceAngle16;
        const double heading = fixedAngleRadians(visualAngle);
        const double perpendicular = heading + kPi * 0.5;
        const float centerX = x + static_cast<float>(std::cos(heading) * 5.0);
        const float centerY = y + static_cast<float>(std::sin(heading) * 5.0);
        const float dx = static_cast<float>(std::cos(perpendicular) * 35.0);
        const float dy = static_cast<float>(std::sin(perpendicular) * 35.0);
        drawSmall(wingFrame, centerX + dx, centerY + dy,
                  normalizeAngle16(static_cast<int>(visualAngle) +
                                   spin - 0x4000));
        drawSmall(wingFrame, centerX - dx, centerY - dy,
                  normalizeAngle16(static_cast<int>(visualAngle) -
                                   spin - 0x4000),
                  1.0, 1.0, true);
        drawSmall(bodyFrame, x, y,
                  first ? enemy.secondaryAngle16 : enemy.sourceAngle16);
        break;
    }
    case 0xfc: {
        const float frontY = static_cast<float>(
            std::sin(static_cast<double>(timer) * kPi / 25.0) - 45.0);
        const float middleY = static_cast<float>(
            std::sin(static_cast<double>(timer - 12) * kPi / 25.0) - 5.0);
        const int frontSpin = static_cast<int>(
            -900.0 * std::sin(static_cast<double>(timer - 24) *
                              kPi / 25.0));
        const int middleSpin = static_cast<int>(
            900.0 * std::sin(static_cast<double>(timer - 12) *
                             kPi / 25.0));
        drawSmall(159, x + 12.0f, y + middleY + 36.0f,
                  normalizeAngle16(frontSpin));
        drawSmall(159, x - 12.0f, y + middleY + 36.0f,
                  normalizeAngle16(-frontSpin), 1.0, 1.0, true);
        drawSmall(158, x + 14.0f, y + middleY,
                  normalizeAngle16(middleSpin));
        drawSmall(158, x - 14.0f, y + middleY,
                  normalizeAngle16(-middleSpin), 1.0, 1.0, true);
        drawSmall(157, x, y + middleY);
        drawSmall(156, x, y + frontY);
        break;
    }
    case 0xfd:
        drawMedium(202, x, y);
        for (int i = 0; i < 4; ++i) {
            drawMedium(203, x, y - 80.0f,
                       normalizeAngle16(timer * 1000 + i * 0x4000));
        }
        break;
    case 0xfe: {
        const float sway = static_cast<float>(
            std::sin(static_cast<double>(timer) * kTau / 48.0) * 5.0);
        if ((timer & 1) == 0) {
            drawMedium(205, x + 70.0f, y + sway);
            drawMedium(205, x - 70.0f, y + sway, 0,
                       1.0, 1.0, true);
        }
        drawMedium(204, x, y);
        break;
    }
    case 0xff: {
        const int frame = 160 + (timer / 15) % 2;
        const double scaleX =
            std::sin(static_cast<double>(timer) * kTau / 30.0);
        drawSmall(frame, x, y, 0, scaleX, 1.0);
        break;
    }
    case 0x100: {
        const float sway = static_cast<float>(
            std::sin(static_cast<double>(timer) * kTau / 48.0) * 5.0);
        if ((timer & 1) == 0) {
            drawMedium(207, x + 70.0f, y + sway - 10.0f);
            drawMedium(207, x - 70.0f, y + sway - 10.0f, 0,
                       1.0, 1.0, true);
        }
        drawMedium(206, x, y);
        break;
    }
    case 0x101: {
        double scaleY = 1.0;
        if (timer % 50 < 11) {
            scaleY -= std::sin(static_cast<double>(timer % 50) *
                               kPi / 10.0);
        }
        drawSmall(162, x, y, 0, 1.0, scaleY);
        break;
    }
    case 0x102: {
        const float frontY = static_cast<float>(
            2.0 * std::sin(static_cast<double>(timer) * kTau / 70.0) -
            62.0);
        const float middleY = static_cast<float>(
            2.0 * std::sin(static_cast<double>(timer - 12) * kTau / 70.0) -
            10.0);
        const float rearY = static_cast<float>(
            2.0 * std::sin(static_cast<double>(timer - 24) * kTau / 70.0) +
            50.0);
        const float coreY = static_cast<float>(
            2.0 * std::sin(static_cast<double>(timer - 36) * kTau / 70.0));
        const int mountAngle = static_cast<int>(
            std::sin(static_cast<double>(timer) * kTau / 70.0) * 4400.0);
        const double mountRadians = fixedAngleRadians(
            normalizeAngle16(mountAngle));
        const float mountX = static_cast<float>(
            std::cos(mountRadians) * 80.0 + 10.0);
        const float mountY = static_cast<float>(
            std::sin(mountRadians) * 80.0);
        drawMedium(209, x + mountX, y + middleY + mountY,
                   normalizeAngle16(mountAngle));
        drawMedium(209, x - mountX, y + middleY + mountY,
                   normalizeAngle16(-mountAngle), 1.0, 1.0, true);
        drawSmall(164, x, y + rearY);
        drawMedium(208, x, y + middleY);
        drawSmall(163, x, y + frontY);
        drawMedium(210, x, y + coreY);
        break;
    }
    case 0x103:
    case 0x104: {
        for (int i = 0; i < 4; ++i) {
            drawMedium(213, x, y + 50.0f,
                       normalizeAngle16(timer * 600 + i * 0x4000));
        }
        drawMedium(212, x, y);
        const int sourceFrame = std::max(0, frame_ - 1);
        const auto drawOrbitHalf = [&](bool rear) {
            for (int i = 0; i < 13; ++i) {
                const auto orbitAngle = normalizeAngle16(
                    sourceFrame * 0xde + i * 0x13b1);
                if ((orbitAngle > 0x8000) != rear) continue;
                const double radians = fixedAngleRadians(orbitAngle);
                drawSmall(165,
                          x + static_cast<float>(std::cos(radians) * 72.0),
                          y - 8.0f + static_cast<float>(
                                           std::sin(radians) * 40.0));
            }
        };
        drawOrbitHalf(true);
        drawMedium(211, x, y);
        drawOrbitHalf(false);
        break;
    }
    default:
        break;
    }

    if (!drew) {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(8, enemy.radius / 3),
                   GetColor(255, 120, 180), TRUE);
    }

    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    return true;
}

} // namespace reconstructed
