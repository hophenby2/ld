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
constexpr std::size_t kEntityCap = 0x200;

std::uint16_t angle16(int value) {
    return static_cast<std::uint16_t>(value & 0xffff);
}

double radians16(std::uint16_t value) {
    return static_cast<double>(value) * kTau / 65536.0;
}

std::uint16_t angleTo(float x0, float y0, float x1, float y1) {
    return angle16(static_cast<int>(
        std::atan2(static_cast<double>(y1 - y0),
                   static_cast<double>(x1 - x0)) *
        65536.0 / kTau));
}

std::uint32_t scriptRand(std::uint32_t seed) {
    const std::uint32_t u = ((seed >> 30) ^ seed) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

std::uint16_t scriptAngle(std::uint32_t seed) {
    const std::uint32_t value = scriptRand(seed);
    return angle16(static_cast<int>(static_cast<std::int16_t>(value)) -
                   static_cast<int>(static_cast<std::int16_t>(
                       value / 0x10001u)));
}

double scriptRandomHundredth(std::uint32_t seed, int minimum100,
                             int maximum100) {
    return static_cast<double>(
               minimum100 +
               static_cast<int>(scriptRand(seed) %
                                static_cast<std::uint32_t>(
                                    maximum100 - minimum100 + 1))) /
           100.0;
}

const std::array<int, 3>& paletteColor(int index) {
    static constexpr std::array<std::array<int, 3>, 7> kColors{{
        {{0xff, 0x78, 0x78}}, {{0xff, 0xc8, 0x6e}},
        {{0xff, 0xff, 0x78}}, {{0x78, 0xff, 0x78}},
        {{0x78, 0xff, 0xff}}, {{0x78, 0x78, 0xff}},
        {{0xdc, 0x78, 0xff}},
    }};
    return kColors[static_cast<std::size_t>(index % 7)];
}

int frameHandle(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

bool isMaterializingEmitter(int spawnType) {
    return (spawnType >= 0x105 && spawnType <= 0x10b) ||
           spawnType == 0x10f || spawnType == 0x110;
}

bool isPhase151Emitter(int spawnType) {
    return spawnType >= 0x12e && spawnType <= 0x135;
}

} // namespace

bool StageRuntime::isStage10FinalBossEmitterType(int spawnType) const {
    return (spawnType >= 0x105 && spawnType <= 0x110) ||
           spawnType == 0x123 || spawnType == 0x124 ||
           (spawnType >= 0x128 && spawnType <= 0x12c) ||
           isPhase151Emitter(spawnType);
}

bool StageRuntime::spawnStage10FinalBossEmitter(
    StageEnemy& parent, int spawnType, float targetX, float targetY,
    std::uint16_t angle, double speed, int childIndex) {
    if (!isStage10FinalBossEmitterType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kEntityCap) {
        return false;
    }

    int updateCase = -1;
    if (spawnType <= 0x10b) updateCase = 0x8a;
    else if (spawnType <= 0x10e) updateCase = 0x8b;
    else if (spawnType <= 0x110) updateCase = 0x8c;
    else if (spawnType <= 0x124) updateCase = 0x97;
    else if (spawnType <= 0x12a) updateCase = 0x9a;
    else if (spawnType <= 0x12c) updateCase = 0x9b;
    else updateCase = 0x9d;

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = updateCase;
    node.sourceHitPoints = spawnType >= 0x12e ? 10 : 99999999;
    node.sourceX = static_cast<int>(std::lround(targetX));
    node.sourceY = static_cast<int>(std::lround(targetY));
    node.sourceNote = "S10 recovered final-root transient emitter";
    node.sourceDispatchKind = 0;
    node.sourceDispatchField = spawnType == 0x123
                                   ? 0x32
                                   : (spawnType == 0x124
                                          ? 0x1e
                                          : (spawnType >= 0x123 ? 40 : 20));
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = parent.spawnType;
    node.childIndex = childIndex;
    node.originX = targetX;
    node.originY = targetY;
    node.markerDrawX = parent.x;
    node.markerDrawY = parent.y;
    if (isMaterializingEmitter(spawnType)) {
        node.x = parent.x;
        node.y = parent.y;
        node.helperState = 0;
    }
    else {
        node.x = targetX;
        node.y = targetY;
        node.helperState = spawnType == 0x10e ? 0 : 1;
    }
    node.sourceAngle16 = angle;
    node.secondaryAngle16 = angle;
    node.targetAngle16 = angle;
    node.angle = static_cast<float>(radians16(angle));
    node.sourceSpeed = speed;
    node.speed = static_cast<float>(speed);
    node.hp = 99999999;
    node.maxHp = node.hp;
    node.drawHp = node.hp;
    node.radius = spawnType == 0x123
                      ? 0x32
                      : (spawnType == 0x124
                             ? 0x1e
                             : (spawnType >= 0x123 ? 20 : 8));
    node.activationDelay = 0;
    node.rewardWeight = 0;
    node.targetable = false;
    pendingEnemies_.push_back(node);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage10FinalBossEmitter(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawMarkerThisFrame = false;
    enemy.drawBodyThisFrame = true;
    enemy.targetable = false;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    const auto release = [&enemy, parent]() {
        if (!enemy.active) {
            return;
        }
        if (parent != nullptr && parent->liveChildCount > 0) {
            --parent->liveChildCount;
        }
        enemy.active = false;
    };
    if (parent == nullptr || !parent->active) {
        release();
        return;
    }

    const int type = enemy.spawnType;
    int timer = enemy.helperTimer;
    if (isMaterializingEmitter(type) && enemy.helperState == 0) {
        if (timer == 0) {
            enemy.markerDrawX = parent->x;
            enemy.markerDrawY = parent->y;
        }
        if (type == 0x10f || type == 0x110) {
            enemy.originX = player_.x / 6.0f +
                            (type == 0x10f ? 10.0f : 590.0f);
        }
        if (timer < 60) {
            const double p = std::clamp(static_cast<double>(timer) / 60.0,
                                        0.0, 1.0);
            const double eased = std::sin(p * kPi * 0.5);
            const double wobble = std::sin(p * kPi) * 100.0;
            const double direction = radians16(angle16(
                (config_.difficulty * 2 - timer) * 0x168));
            enemy.x = enemy.markerDrawX +
                      static_cast<float>(
                          (enemy.originX - enemy.markerDrawX) * eased +
                          std::cos(direction) * wobble);
            enemy.y = enemy.markerDrawY +
                      static_cast<float>(
                          (enemy.originY - enemy.markerDrawY) * eased +
                          std::sin(direction) * wobble);
            return;
        }
        // FUN_140057f90/FUN_140059000 continue into the active branch on
        // the same dispatch after resetting +0x0c to zero.
        enemy.x = enemy.originX;
        enemy.y = enemy.originY;
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        timer = 0;
    }

    const auto move = [&enemy]() {
        const double heading = radians16(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(heading) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(heading) * enemy.sourceSpeed);
        enemy.speed = static_cast<float>(enemy.sourceSpeed);
        enemy.angle = static_cast<float>(heading);
    };
    const auto aim = [this](float x, float y) {
        return angleTo(x, y, player_.x, player_.y);
    };
    const float horizontalOrigin = player_.x / 6.0f;
    const auto outside = [horizontalOrigin](const StageEnemy& node) {
        return node.x < horizontalOrigin - 180.0f ||
               node.x > horizontalOrigin + 780.0f ||
               node.y < -180.0f || node.y > 900.0f;
    };
    const auto outsideMargin = [horizontalOrigin, &enemy](float margin) {
        return enemy.x < horizontalOrigin + margin ||
               enemy.x > horizontalOrigin + 600.0f - margin ||
               enemy.y < margin || enemy.y > 720.0f - margin;
    };
    const auto clampToMargin = [horizontalOrigin, &enemy](float margin) {
        enemy.x = std::clamp(enemy.x, horizontalOrigin + margin,
                             horizontalOrigin + 600.0f - margin);
        enemy.y = std::clamp(enemy.y, margin, 720.0f - margin);
    };
    bool fired = false;
    int shotSoundHandle = -1;
    int shotSoundPriority = 0;

    if (timer == 0 &&
        ((type >= 0x105 && type <= 0x107) ||
         (type >= 0x10c && type <= 0x10e))) {
        playPlayerSound(bossSe7SoundHandle_, 0x13);
    }

    switch (type) {
    case 0x105:
        enemy.sourceSpeed += 0.15;
        move();
        if (timer == 0x10) {
            spawnProjectileNode(3, 2, enemy.x, enemy.y,
                                aim(enemy.x, enemy.y), 0.0f, 7.0, 1, 0);
            fired = true;
        }
        spawnProjectileNode(4, 0x0f, enemy.x, enemy.y,
                            enemy.sourceAngle16, 0.0f, 0.0, 1, 0);
        break;
    case 0x106: {
        if (timer == 0) {
            clampToMargin(-10.0f);
        }
        const int sign = enemy.originX < 360.0f ? -1 : 1;
        enemy.sourceAngle16 = angle16(
            static_cast<int>(enemy.sourceAngle16) +
            static_cast<int>(std::sin(timer * kPi / 60.0) * sign * 360.0));
        move();
        spawnProjectileNode(4, 0x10, enemy.x, enemy.y,
                            enemy.sourceAngle16, 0.0f, 0.0, 1, 0);
        break;
    }
    case 0x107:
        enemy.sourceSpeed += 0.07;
        move();
        if (enemy.helperState == 1 && enemy.y >= 1.0f &&
            outsideMargin(0.0f)) {
            if (enemy.x < horizontalOrigin ||
                enemy.x > horizontalOrigin + 600.0f) {
                enemy.sourceAngle16 = angle16(
                    0x8000 - static_cast<int>(enemy.sourceAngle16));
            }
            clampToMargin(0.0f);
            ++enemy.helperState;
        }
        spawnProjectileNode(4, 0x10, enemy.x, enemy.y,
                            enemy.sourceAngle16, 0.0f, 0.0, 1, 0);
        break;
    case 0x108:
    case 0x109: {
        const std::uint16_t oldAngle = enemy.sourceAngle16;
        move();
        const int direction = type == 0x108 ? 0x400 : -0x400;
        enemy.sourceAngle16 = angle16(static_cast<int>(oldAngle) + direction);
        if ((timer & 1) == 0) {
            const int base = type == 0x108
                                 ? static_cast<int>(oldAngle) + 0x4400
                                 : static_cast<int>(oldAngle) - 0x4400;
            for (int i = 0; i < 2; ++i) {
                spawnProjectileNode(0x0d, 3, enemy.x, enemy.y,
                                    angle16(base + 0x4000 - i * 0x8000),
                                    0.0f, 5.0, 1, 0);
                spawnProjectileNode(0x0d, 3, enemy.x, enemy.y,
                                    angle16(base + 0x6000 + i * 0x4000),
                                    0.0f, 6.4, 1, 0);
            }
            spawnProjectileNode(0x0d, 3, enemy.x, enemy.y,
                                angle16(base), 0.0f, 5.0, 1, 0);
            fired = true;
            shotSoundHandle = bullet1SoundHandle_;
            shotSoundPriority = 0x10;
        }
        spawnProjectileNode(4, 0x10, enemy.x, enemy.y,
                            enemy.sourceAngle16, 0.0f, 0.0, 1, 0);
        if (timer == 0x40) release();
        break;
    }
    case 0x10a:
    case 0x10b:
        break;
    case 0x10c:
    case 0x10d: {
        move();
        const int sign = type == 0x10c ? -1 : 1;
        enemy.sourceAngle16 = angle16(
            static_cast<int>(enemy.sourceAngle16) +
            static_cast<int>(std::sin(timer * kPi / 38.5) * sign * 550.0));
        if (timer == 0x19) {
            spawnProjectileNode(3, 2, enemy.x, enemy.y,
                                aim(enemy.x, enemy.y), 0.0f, 6.0, 1, 0);
            fired = true;
            shotSoundHandle = bullet2SoundHandle_;
            shotSoundPriority = 0x0c;
        }
        spawnProjectileNode(4, 0x10, enemy.x, enemy.y,
                            enemy.sourceAngle16, 0.0f, 0.0, 1, 0);
        break;
    }
    case 0x10e:
        move();
        enemy.sourceSpeed += 0.07;
        if (enemy.helperState == 0 && outsideMargin(0.0f)) {
            const std::uint16_t oldAngle = enemy.sourceAngle16;
            if (enemy.x < horizontalOrigin ||
                enemy.x > horizontalOrigin + 600.0f) {
                enemy.sourceAngle16 = angle16(
                    0x8000 - static_cast<int>(oldAngle));
            }
            if (enemy.y < 0.0f || enemy.y > 720.0f) {
                enemy.sourceAngle16 = angle16(-static_cast<int>(oldAngle));
            }
            clampToMargin(0.0f);
            ++enemy.helperState;
        }
        spawnProjectileNode(4, 0x0f, enemy.x, enemy.y,
                            enemy.sourceAngle16, 0.0f, 0.0, 1, 0);
        break;
    case 0x10f:
    case 0x110: {
        move();
        if (enemy.helperState == 1 || enemy.helperState == 3) {
            enemy.x = horizontalOrigin +
                      (type == 0x10f ? 10.0f : 590.0f);
        }
        if (outsideMargin(-10.0f)) {
            if (enemy.helperState >= 4) {
                release();
                break;
            }
            enemy.sourceAngle16 = angle16(
                static_cast<int>(enemy.sourceAngle16) +
                (type == 0x10f ? 0xc000 : 0x4000));
            clampToMargin(10.0f);
            ++enemy.helperState;
        }
        if ((timer & 1) == 0) {
            const double speed =
                5.0 + static_cast<double>(parent->helperTimer - 90) * 0.005;
            const int visual = type == 0x10f ? 0x0d : 0x0c;
            const auto aimed = aim(enemy.x, enemy.y);
            spawnProjectileNode(visual, 0, enemy.x, enemy.y,
                                aimed, 0.0f, speed, 1, 0);
            spawnProjectileNode(visual, 0, enemy.x, enemy.y,
                                aimed, 0.0f, speed + 1.0, 1, 0);
            fired = true;
            shotSoundHandle = bullet1SoundHandle_;
            shotSoundPriority = 0x10;
        }
        break;
    }
    case 0x123:
    case 0x124: {
        move();
        const int warmup = type == 0x123 ? 0x32 : 0x1e;
        if (timer < 10) enemy.sourceSpeed = 0.0;
        else if (timer < warmup) {
            enemy.sourceSpeed = 2.0 *
                std::sin((timer - 10) * kPi /
                         static_cast<double>(warmup - 10) * 0.5);
        }
        else {
            enemy.sourceSpeed = 2.0;
        }
        const int lifetime = type == 0x123 ? 0x46 : 0x32;
        if (timer == lifetime) {
            const int layers = type == 0x123 ? 5 : 3;
            const int projectileId = type == 0x123 ? 0x3a : 0x3b;
            for (int layer = layers; layer > 0; --layer) {
                const auto randomAngle = scriptAngle(
                    static_cast<std::uint32_t>(parent->helperTimer +
                                               layer * 0x42));
                const int visual = layer < (type == 0x123 ? 4 : 3) ? 3 : 2;
                const int count = std::max(1, static_cast<int>(layer * kTau));
                spawnProjectileSpread(visual, projectileId, enemy.x, enemy.y,
                                      randomAngle, layer * 32.0f, 0.0, 1,
                                      count, 0x10000, 0);
            }
            spawnProjectileNode(3, projectileId, enemy.x, enemy.y,
                                0, 0.0f, 0.0, 1, 0);
            fired = true;
            release();
        }
        break;
    }
    case 0x128: {
        const double radius = timer < 60
                                  ? 600.0 -
                                        std::sin(timer * kPi / 120.0) * 600.0
                                  : 0.0;
        const double heading = radians16(enemy.sourceAngle16);
        enemy.x = parent->x + static_cast<float>(std::cos(heading) * radius);
        enemy.y = parent->y + static_cast<float>(std::sin(heading) * radius);
        if (timer == 60) release();
        break;
    }
    case 0x129:
        move();
        enemy.y -= static_cast<float>(timer) * 0.2f;
        if (enemy.x < horizontalOrigin - 50.0f ||
            enemy.x > horizontalOrigin + 650.0f ||
            enemy.y < -50.0f || enemy.y > 770.0f) {
            release();
        }
        break;
    case 0x12a:
        move();
        enemy.sourceSpeed += 0.3;
        if (enemy.x < horizontalOrigin - 50.0f ||
            enemy.x > horizontalOrigin + 650.0f ||
            enemy.y < -50.0f || enemy.y > 770.0f) {
            release();
        }
        break;
    case 0x12b:
    case 0x12c: {
        move();
        enemy.sourceAngle16 = angle16(static_cast<int>(enemy.sourceAngle16) + 0x51e);
        enemy.secondaryAngle16 = angle16(
            static_cast<int>(enemy.secondaryAngle16) + 0x834);
        if (type == 0x12c && timer < 0x32 && (timer & 1) == 0) {
            const float offset = static_cast<float>(
                std::sin(timer * kTau / 100.0) * 40.0);
            const double heading = radians16(enemy.sourceAngle16);
            const float sourceX = enemy.x +
                static_cast<float>(std::cos(heading) * offset);
            const float sourceY = enemy.y +
                static_cast<float>(std::sin(heading) * offset);
            spawnProjectileNode(8, 3, sourceX, sourceY,
                                angle16(static_cast<int>(enemy.sourceAngle16) -
                                        timer * 200 - 9000),
                                0.0f, 6.0, 1, 0);
            spawnProjectileNode(8, 3, sourceX, sourceY,
                                angle16(static_cast<int>(enemy.sourceAngle16) -
                                        timer * 200 - 0x1623),
                                0.0f, 7.2, 1, 0);
            fired = true;
            shotSoundHandle = bullet1SoundHandle_;
            shotSoundPriority = 0x0c;
        }
        const float offset = static_cast<float>(
            std::sin(timer * kTau / 100.0) * 50.0);
        for (int i = 0; i < 3; ++i) {
            const double heading = radians16(angle16(
                static_cast<int>(enemy.secondaryAngle16) +
                (i + 3) * 0x4000));
            spawnProjectileNode(5, 0x11,
                                enemy.x + static_cast<float>(std::cos(heading) * offset),
                                enemy.y + static_cast<float>(std::sin(heading) * offset),
                                enemy.sourceAngle16, 0.0f, 0.0, 1, 0);
        }
        if (timer == 0x32) release();
        break;
    }
    default:
        if (isPhase151Emitter(type)) {
            const bool reverse = type == 0x12f || type == 0x131 ||
                                 type == 0x133 || type == 0x135;
            const float radius = static_cast<float>(timer) * 0.48f;
            const double heading = radians16(enemy.sourceAngle16);
            enemy.x = parent->x + enemy.originX +
                      static_cast<float>(std::cos(heading) * radius);
            enemy.y = parent->y + enemy.originY +
                      static_cast<float>(std::sin(heading) * radius);
            enemy.sourceAngle16 = angle16(
                static_cast<int>(enemy.sourceAngle16) +
                (reverse ? -0x168 : 0x168));

            if (timer >= 0x1e && timer < 0x186) {
                const int local = timer - 0x1e;
                const int base = static_cast<int>(enemy.secondaryAngle16);
                if ((type == 0x12e || type == 0x12f) && local % 5 == 0) {
                    const int spin = timer * (type == 0x12e ? 0x1a4 : -0x1a4);
                    const int visual = type == 0x12e ? 4 : 5;
                    const double speed = 6.0 + local * 0.01;
                    for (int i = 0; i < 3; ++i) {
                        spawnProjectileNode(visual, 0, enemy.x, enemy.y,
                                            angle16(base + spin - 0x1d4c +
                                                    i * 0x1d4c),
                                            0.0f, speed, 1, 0);
                        spawnProjectileNode(visual, 0, enemy.x, enemy.y,
                                            angle16(base + spin + 0x62b4 +
                                                    i * 0x1d4c),
                                            0.0f, speed, 1, 0);
                    }
                    fired = true;
                    shotSoundHandle = bullet1SoundHandle_;
                    shotSoundPriority = 0x10;
                }
                else if ((type == 0x130 || type == 0x131) && local % 10 < 5) {
                    const int spin = timer * (type == 0x130 ? 0x1e0 : -0x1e0);
                    const int visual = type == 0x130 ? 0x0c : 0x0d;
                    const double speed = 5.5 + local * 0.008;
                    for (int i = 0; i < 4; ++i) {
                        spawnProjectileNode(visual, 0, enemy.x, enemy.y,
                                            angle16(base + spin + i * 0x4000),
                                            0.0f, speed, 1, 0);
                    }
                    fired = true;
                    shotSoundHandle = bullet1SoundHandle_;
                    shotSoundPriority = 0x0c;
                }
                else if ((type == 0x132 || type == 0x133) && local % 6 == 0) {
                    const int sweep = timer * (type == 0x132 ? 700 : -700);
                    const int visual = type == 0x132 ? 10 : 0x0b;
                    const double speed = 7.2 + local * 0.006;
                    for (int layer = 0; layer < 4; ++layer) {
                        const int offset = 1500 - layer * 500;
                        spawnProjectileSpread(visual, 0, enemy.x, enemy.y,
                                              angle16(base + sweep), 0.0f,
                                              speed + layer * 0.5, 1, 2,
                                              offset, 0);
                        spawnProjectileSpread(visual, 0, enemy.x, enemy.y,
                                              angle16(base + sweep - 0x8000),
                                              0.0f, speed + layer * 0.5, 1,
                                              2, offset, 0);
                    }
                    fired = true;
                    shotSoundHandle = bullet1SoundHandle_;
                    shotSoundPriority = 0x10;
                }
                else if ((type == 0x134 || type == 0x135) && local % 7 == 0) {
                    const int sweep = timer * (type == 0x134 ? 250 : -250);
                    const int visual = type == 0x134 ? 0x0c : 0x0d;
                    const int secondVisual = type == 0x134 ? 2 : 3;
                    const double speed = 5.5 + local * 0.009;
                    spawnProjectileSpread(visual, 0, enemy.x, enemy.y,
                                          angle16(base + sweep), 0.0f,
                                          speed, 1, 4, 0x10000, 0);
                    spawnProjectileSpread(secondVisual, 0, enemy.x, enemy.y,
                                          angle16(base + sweep + 0x2000),
                                          0.0f, speed + 1.0, 1, 4,
                                          0x10000, 0);
                    fired = true;
                    shotSoundHandle = bullet1SoundHandle_;
                    shotSoundPriority = 0x10;
                }
            }
            const bool phaseEnded = type <= 0x12f
                                        ? parent->helperState > 1
                                        : (type <= 0x131
                                               ? parent->helperState > 2
                                               : (type <= 0x133
                                                      ? parent->helperState == 99
                                                      : (parent->helperState == 200 ||
                                                         lateStageBossCountdown_ < 1)));
            if (phaseEnded || timer == 0x19a) release();
        }
        break;
    }

    if (type >= 0x128 && type <= 0x12a) {
        const int radius = static_cast<int>(
            scriptRand(static_cast<std::uint32_t>(timer * 0x22b8 +
                                                  enemy.entityId)) %
            0x11u);
        const auto offsetAngle = scriptAngle(
            static_cast<std::uint32_t>(timer * 0x378 + enemy.entityId));
        const double offsetRadians = radians16(offsetAngle);
        const float effectX = enemy.x + static_cast<float>(
            std::cos(offsetRadians) * static_cast<double>(radius));
        const float effectY = enemy.y + static_cast<float>(
            std::sin(offsetRadians) * static_cast<double>(radius));
        const double scale = scriptRandomHundredth(
            static_cast<std::uint32_t>(timer * 0x15b38 + enemy.entityId),
            50, 100);
        const auto& color = paletteColor((timer / 3) % 7);
        const int graph = frameHandle(effectSmallFrames_, 17);
        spawnStageEffect(
            4, graph, 100, 0x22, effectX, effectY,
            scriptAngle(static_cast<std::uint32_t>(timer * 0x58 +
                                                   enemy.entityId)),
            0.0, scale, scale, 0x10,
            color[0], color[1], color[2], 0xc0);
    }
    if (type == 0x12b || type == 0x12c) {
        const double scale = std::sin(timer * kPi / 50.0);
        spawnStageEffect(5, frameHandle(enemyMediumFrames_, 225), 200, 0x23,
                         enemy.x, enemy.y, 0, 0.0, scale, scale, 0x0c,
                         0xff, 0xff, 0xff, 0x60);
    }
    if (isPhase151Emitter(type) && (timer & 1) == 0) {
        const double scale = timer < 30
                                 ? std::sin(timer * kPi / 60.0)
                                 : (timer < 0x186
                                        ? 1.0
                                        : (timer < 0x19a
                                               ? std::cos((timer - 0x186) *
                                                          kPi / 40.0)
                                               : 0.0));
        const auto drawAngle = angle16(static_cast<int>(
            std::sin(timer * kPi / 44.0) * 1280.0));
        spawnStageEffect(5, frameHandle(enemyMediumFrames_, 226), 200, 0x23,
                         enemy.x, enemy.y, drawAngle, 0.0, scale, scale, 0x10,
                         0xff, 0xff, 0xff, 0x60);
    }

    if (outside(enemy) && type >= 0x105 && type <= 0x110) {
        release();
    }
    if ((type == 0x123 || type == 0x124) && parent->helperState == 99) {
        release();
    }
    if (type <= 0x110 &&
        (parent->spawnType != 0x141 || parent->hp < 1 ||
         lateStageBossCountdown_ < 1)) {
        release();
    }
    if (fired && shotSoundHandle != -1) {
        playPlayerSound(shotSoundHandle, shotSoundPriority);
    }
}

bool StageRuntime::drawStage10FinalBossEmitter(const StageEnemy& enemy,
                                                float x, float y) const {
    if (!isStage10FinalBossEmitterType(enemy.spawnType)) {
        return false;
    }

    if (enemy.spawnType >= 0x128 && enemy.spawnType <= 0x12a) {
        // FUN_14006a2e0 is invisible; it leaves one Effect_s[17] particle
        // every update instead of drawing the entity itself.
        return true;
    }

    int graph = -1;
    if (enemy.spawnType >= 0x105 && enemy.spawnType <= 0x110) {
        graph = frameHandle(enemySmallFrames_, 169);
    }
    else if (enemy.spawnType == 0x123) {
        graph = frameHandle(enemyMediumFrames_, 219);
    }
    else if (enemy.spawnType == 0x124) {
        graph = frameHandle(enemyMediumFrames_, 220);
    }
    else if (enemy.spawnType == 0x12b || enemy.spawnType == 0x12c) {
        graph = frameHandle(enemyMediumFrames_, 225);
    }
    else {
        graph = frameHandle(enemyMediumFrames_, 226);
    }
    if (graph == -1) {
        return true;
    }

    double scale = 1.0;
    int alpha = 0xff;
    std::uint16_t drawAngle = 0;
    if (isMaterializingEmitter(enemy.spawnType) && enemy.drawHelperState == 0) {
        scale = std::sin(std::clamp(enemy.drawHelperTimer, 0, 60) *
                         kPi / 120.0);
    }
    else if (enemy.spawnType == 0x123 || enemy.spawnType == 0x124) {
        scale = std::sin(std::min(enemy.drawHelperTimer, 10) * kPi / 20.0);
        const double period = enemy.spawnType == 0x123 ? 32.0 : 24.0;
        drawAngle = angle16(static_cast<int>(
            std::sin(enemy.drawHelperTimer * kPi / period) * 3000.0));
    }
    else if (enemy.spawnType == 0x12b || enemy.spawnType == 0x12c) {
        scale = std::sin(enemy.drawHelperTimer * kPi / 50.0);
        drawAngle = enemy.secondaryAngle16;
    }
    else if (isPhase151Emitter(enemy.spawnType)) {
        const int timer = enemy.drawHelperTimer;
        scale = timer < 30
                    ? std::sin(timer * kPi / 60.0)
                    : (timer < 0x186
                           ? 1.0
                           : std::max(0.0, std::cos((timer - 0x186) *
                                                   kPi / 40.0)));
        drawAngle = angle16(static_cast<int>(
            std::sin(timer * kPi / 44.0) * 1280.0));
    }

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    drawOriginalMode7Node(graph, x, y, drawAngle,
                          scale, scale, false);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    return true;
}

} // namespace reconstructed
