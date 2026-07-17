#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kPi = 3.14159265358979323846;
constexpr double kTau = kPi * 2.0;
constexpr std::size_t kEntityCap = 0x200;

std::uint16_t sceneAngle(int angle) {
    return static_cast<std::uint16_t>(angle & 0xffff);
}

double sceneRadians(std::uint16_t angle) {
    return static_cast<double>(angle) * kTau / 65536.0;
}

std::uint16_t approachSceneAngle(std::uint16_t current,
                                 std::uint16_t target, int step) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return sceneAngle(static_cast<int>(current) +
                      std::clamp(delta, -step, step));
}

std::uint32_t sceneScriptRand(std::uint32_t seed) {
    const std::uint32_t u = ((seed >> 30) ^ seed) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return ((c >> 11) ^ mixed) >> 8 ^ c ^ mixed;
}

std::uint16_t sceneRandomAngle(std::uint32_t seed) {
    const std::uint32_t random = sceneScriptRand(seed);
    return static_cast<std::uint16_t>(random - random / 0x10001u);
}

double sceneRandomHundredth(std::uint32_t seed, double minimum,
                            double maximum) {
    const int minimum100 = static_cast<int>(minimum * 100.0);
    const int maximum100 = static_cast<int>(maximum * 100.0);
    const std::uint32_t width = static_cast<std::uint32_t>(
        maximum100 - minimum100 + 1);
    return static_cast<double>(minimum100 +
                               static_cast<int>(sceneScriptRand(seed) % width)) /
           100.0;
}

struct SceneCombatWindow {
    int startFrame;
    int endFrame;
};

SceneCombatWindow sceneCombatWindow(int spawnType) {
    if ((spawnType >= 0xe4 && spawnType <= 0xe7) ||
        spawnType == 0xf2 || spawnType == 0xf3) {
        return {1300, 3000};
    }
    if ((spawnType >= 0xe8 && spawnType <= 0xec) ||
        (spawnType >= 0xf4 && spawnType <= 0xf7)) {
        return {2000, 5500};
    }
    if (spawnType == 0xed) return {5700, 6600};
    if (spawnType == 0xf8) return {5700, 8500};
    if (spawnType == 0xee) return {7900, 8800};
    if (spawnType == 0xf9) return {7900, 9100};
    if (spawnType == 0xef || spawnType == 0xf0) return {9300, 10600};
    if (spawnType == 0xf1) return {10600, 11500};
    return {0, 0};
}

bool isStructuralSceneNode(int spawnType) {
    return spawnType >= 0xde && spawnType <= 0xe3;
}

int sceneUpdateCase(int spawnType) {
    if (spawnType <= 0xe3) return 0x7f;
    if (spawnType <= 0xf1) return 0x80;
    return 0x81;
}

int frameAt(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

} // namespace

bool StageRuntime::isStage10SceneNodeType(int spawnType) const {
    return spawnType >= 0xde && spawnType <= 0xf9;
}

bool StageRuntime::isSharedHitboxProxyType(int spawnType) const {
    return spawnType == 0x151 || spawnType == 0x152;
}

bool StageRuntime::isStage10GuardNodeType(int spawnType) const {
    return spawnType == 0x136;
}

void StageRuntime::maybeSpawnStage10GuardNode(StageEnemy& owner) {
    switch (owner.spawnType) {
    case 0x111:
    case 0x112:
    case 0x113:
    case 0x115:
    case 0x11a:
    case 0x11d:
    case 0x125:
    case 0x126:
    case 0x12d:
        break;
    default:
        return;
    }

    if (player_.invulnerableFrames < 61) {
        owner.guardSpawnLatched = false;
    }
    const bool playerInBlockingState = player_.playerStateTimer > 0 ||
                                       player_.playerStateTimer < -100;
    if (!owner.targetable || !playerInBlockingState ||
        owner.guardSpawnLatched ||
        enemies_.size() + pendingEnemies_.size() >= kEntityCap) {
        return;
    }

    StageEnemy guard;
    guard.entityId = nextEntityId_++;
    guard.spawnType = 0x136;
    guard.updateCase = 0x75;
    guard.sourceHitPoints = 99999999;
    guard.sourceDispatchKind = 1;
    guard.sourceDispatchField = 20;
    guard.rewardWeight = 1;
    guard.parentEntityId = owner.entityId;
    guard.parentSpawnType = owner.spawnType;
    guard.sourceNote = "S10 FUN_14004a4a0 player-state guard";
    guard.x = owner.x;
    guard.y = owner.y;
    guard.hp = 99999999;
    guard.maxHp = guard.hp;
    guard.drawHp = guard.hp;
    guard.radius = 20;
    guard.activationDelay = 0;
    guard.targetable = true;
    pendingEnemies_.push_back(guard);
    owner.guardSpawnLatched = true;
}

void StageRuntime::updateStage10GuardNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawMarkerThisFrame = false;
    enemy.drawBodyThisFrame = true;
    StageEnemy* owner = findEnemyById(enemy.parentEntityId);
    if (owner == nullptr || !owner->active ||
        owner->spawnType != enemy.parentSpawnType) {
        enemy.targetable = false;
        enemy.active = false;
        return;
    }

    enemy.x = owner->x;
    enemy.y = owner->y;
    enemy.targetable = true;
    if (enemy.helperState == 0) {
        if (enemy.helperTimer == 0) {
            const int spark = frameAt(playerFrames_, 14);
            for (int i = 0; i < 32; ++i) {
                const std::uint32_t angleSeed =
                    static_cast<std::uint32_t>(frame_ + i * 0x58);
                const std::uint32_t scaleSeed =
                    static_cast<std::uint32_t>(frame_ + i * 0x22b8);
                const std::uint32_t speedSeed =
                    static_cast<std::uint32_t>(frame_ + i * 0x378);
                const double scale = sceneRandomHundredth(
                    scaleSeed, 1.1, 2.2);
                spawnStageEffect(
                    0x2c, spark, 0x48, 0x48, enemy.x, enemy.y,
                    sceneRandomAngle(angleSeed),
                    sceneRandomHundredth(speedSeed, 16.0, 26.0),
                    scale, scale, 0, 0xff, 0xff, 0xff, 0xc0);
            }
        }
        const int timer = std::clamp(enemy.helperTimer, 0, 32);
        const double expansion = std::sin(
            static_cast<double>(timer) * kPi / 64.0);
        enemy.radius = static_cast<int>(expansion * 360.0);
        if (player_.invulnerableFrames < 61) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
    }
    else if (enemy.helperState == 1 && enemy.helperTimer >= 16) {
        enemy.targetable = false;
        enemy.active = false;
    }
}

bool StageRuntime::drawStage10GuardNode(const StageEnemy& enemy, float x,
                                        float y) const {
    if (!isStage10GuardNodeType(enemy.spawnType)) return false;
    if (!enemy.drawBodyThisFrame) return true;
    const int handle = frameAt(effectLargeFrames_, 6);
    if (handle == -1) return true;

    double scale = 1.8;
    int alpha = 255;
    if (enemy.drawHelperState == 0) {
        const int timer = std::clamp(enemy.drawHelperTimer, 0, 32);
        scale = 0.1 + std::sin(static_cast<double>(timer) * kPi / 64.0) *
                          1.7;
    }
    else if (enemy.drawHelperState == 1) {
        if (enemy.drawHelperTimer < 16) {
            alpha = std::clamp(static_cast<int>(std::sin(
                static_cast<double>(enemy.drawHelperTimer + 16) *
                kPi / 32.0) * 255.0), 0, 255);
        }
        else {
            alpha = 0;
        }
    }
    const int sourceFrame = std::max(0, frame_ - 1);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    drawOriginalMode7Node(handle, x, y, sceneAngle(sourceFrame * 0x400),
                          scale, scale, false);
    drawOriginalMode7Node(handle, x, y, sceneAngle(-sourceFrame * 0x400),
                          scale, scale, false);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    return true;
}

bool StageRuntime::spawnStage10SceneNode(StageEnemy& parent, int spawnType,
                                         int childIndex, float offsetX,
                                         float offsetY,
                                         std::uint16_t angle16, double speed,
                                         int hitPoints, int kind, int radius) {
    if (!isStage10SceneNodeType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kEntityCap) {
        return false;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = sceneUpdateCase(spawnType);
    node.sourceHitPoints = hitPoints;
    node.sourceDispatchKind = kind;
    node.sourceDispatchField = radius;
    node.rewardWeight = kind;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = parent.spawnType;
    node.childIndex = childIndex;
    node.sourceNote = "S10 recovered 0x14c scene apparatus";
    node.originX = offsetX;
    node.originY = offsetY;
    node.sourceX = static_cast<int>(std::lround(offsetX));
    node.sourceY = static_cast<int>(std::lround(offsetY));
    // FUN_140078a00 stores the supplied coordinates verbatim. The update
    // helpers resolve them against the linked parent on their first tick.
    node.x = offsetX;
    node.y = offsetY;
    node.markerDrawX = node.x;
    node.markerDrawY = node.y;
    node.sourceAngle16 = angle16;
    node.secondaryAngle16 = angle16;
    node.targetAngle16 = angle16;
    node.angle = static_cast<float>(sceneRadians(angle16));
    node.sourceSpeed = speed;
    node.speed = static_cast<float>(speed);
    node.hp = std::max(1, hitPoints);
    node.maxHp = node.hp;
    node.drawHp = node.hp;
    node.radius = radius;
    node.activationDelay = 0;
    node.targetable = false;
    pendingEnemies_.push_back(node);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::ensureStage10SceneRootNode(StageEnemy& parent) {
    if (parent.spawnType != 0x14c || parent.helperState != 0) return;
    const auto exists = [&parent](const StageEnemy& node) {
        return node.active && node.spawnType == 0xde &&
               node.parentEntityId == parent.entityId;
    };
    if (std::any_of(enemies_.begin(), enemies_.end(), exists) ||
        std::any_of(pendingEnemies_.begin(), pendingEnemies_.end(), exists)) {
        return;
    }
    spawnStage10SceneNode(parent, 0xde, 0, 0.0f, 500.0f, 0x4000,
                          1.0, 99999999, 0, 300);
}

bool StageRuntime::spawnSharedHitboxProxy(StageEnemy& parent, int spawnType,
                                          float offsetX, float offsetY,
                                          int radius) {
    if (!isSharedHitboxProxyType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kEntityCap) {
        return false;
    }

    StageEnemy proxy;
    proxy.entityId = nextEntityId_++;
    proxy.spawnType = spawnType;
    proxy.updateCase = 0xb4;
    proxy.sourceHitPoints = 99999999;
    proxy.sourceDispatchKind = 1;
    proxy.sourceDispatchField = radius;
    proxy.rewardWeight = 1;
    proxy.parentEntityId = parent.entityId;
    proxy.parentSpawnType = parent.spawnType;
    proxy.sourceNote = spawnType == 0x151
                           ? "S08 FUN_1400ab110 shared-HP hitbox"
                           : "S08 FUN_1400465d0 shared-HP hitbox";
    proxy.originX = offsetX;
    proxy.originY = offsetY;
    proxy.sourceX = static_cast<int>(std::lround(offsetX));
    proxy.sourceY = static_cast<int>(std::lround(offsetY));
    proxy.x = parent.x + offsetX;
    proxy.y = parent.y + offsetY;
    proxy.hp = 99999999;
    proxy.maxHp = proxy.hp;
    proxy.drawHp = proxy.hp;
    proxy.radius = radius;
    proxy.activationDelay = 0;
    proxy.targetable = parent.targetable;
    pendingEnemies_.push_back(proxy);
    return true;
}

void StageRuntime::updateSharedHitboxProxy(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    StageEnemy* owner = findEnemyById(enemy.parentEntityId);
    if (owner == nullptr || !owner->active ||
        owner->spawnType != enemy.parentSpawnType) {
        enemy.targetable = false;
        enemy.active = false;
        return;
    }

    enemy.x = owner->x + enemy.originX;
    enemy.y = owner->y + enemy.originY;
    enemy.targetable = owner->targetable;
    if (enemy.hp < owner->hp) {
        owner->hp -= owner->hp - enemy.hp;
    }
    else if (owner->hp < enemy.hp) {
        enemy.hp = owner->hp;
    }
    if (enemy.hp < 1) {
        owner->hp -= owner->hp;
    }
    enemy.hp = std::min(enemy.hp, owner->hp);
    enemy.maxHp = owner->maxHp;
    enemy.drawHp = owner->drawHp;
}

void StageRuntime::updateStage10SceneNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || parent->spawnType != enemy.parentSpawnType) {
        enemy.targetable = false;
        enemy.active = false;
        return;
    }

    StageEnemy* root = parent;
    for (int depth = 0; depth < 4 && root != nullptr &&
                        root->spawnType != 0x14c; ++depth) {
        root = findEnemyById(root->parentEntityId);
    }
    if (root == nullptr || root->spawnType != 0x14c) {
        enemy.targetable = false;
        enemy.active = false;
        return;
    }
    const bool rootCleanupFrame = root->helperState == 7 &&
                                  root->helperTimer == 160;
    const auto finishRootFrame = [&enemy, rootCleanupFrame]() {
        if (rootCleanupFrame) {
            enemy.targetable = false;
            enemy.active = false;
        }
    };

    if (enemy.helperTimer == 0) {
        switch (enemy.spawnType) {
        case 0xde:
            spawnStage10SceneNode(enemy, 0xdf, 0, 0.0f, 440.0f,
                                  0x4000, 1.0, 99999999, 0, 300);
            spawnStage10SceneNode(enemy, 0xe0, 0, 170.0f, -240.0f,
                                  0x4000, 1.0, 99999999, 0, 100);
            spawnStage10SceneNode(enemy, 0xe0, 1, -170.0f, -240.0f,
                                  0x4000, 1.0, 99999999, 0, 100);
            spawnStage10SceneNode(enemy, 0xef, 0, 210.0f, 140.0f,
                                  0x4000, 1.0, 7000, 50, 60);
            spawnStage10SceneNode(enemy, 0xf0, 1, -180.0f, 0.0f,
                                  0x4000, 1.0, 7000, 50, 60);
            spawnStage10SceneNode(enemy, 0xf1, 2, 0.0f, 0.0f,
                                  0x4000, 1.0, 20000, 80, 60);
            break;
        case 0xdf:
            spawnStage10SceneNode(enemy, 0xe2, 0, 175.0f, 35.0f,
                                  0x43e8, 1.0, 99999999, 0, 100);
            spawnStage10SceneNode(enemy, 0xe2, 1, -175.0f, 35.0f,
                                  0x3830, 1.0, 99999999, 0, 100);
            spawnStage10SceneNode(enemy, 0xe8, 0, -55.0f, 195.0f,
                                  0x4000, 1.0, 7000, 50, 60);
            spawnStage10SceneNode(enemy, 0xe9, 1, -250.0f, 100.0f,
                                  0x4000, 1.0, 7000, 50, 60);
            spawnStage10SceneNode(enemy, 0xea, 2, 225.0f, 70.0f,
                                  0x4000, 1.0, 7000, 50, 60);
            spawnStage10SceneNode(enemy, 0xeb, 3, 25.0f, -20.0f,
                                  0x4000, 1.0, 7000, 50, 60);
            spawnStage10SceneNode(enemy, 0xec, 4, -195.0f, -35.0f,
                                  0x4000, 1.0, 7000, 50, 60);
            spawnStage10SceneNode(enemy, 0xf4, 0, 75.0f, 185.0f,
                                  0x4000, 1.0, 3000, 20, 40);
            spawnStage10SceneNode(enemy, 0xf5, 1, 15.0f, 95.0f,
                                  0x4000, 1.0, 3000, 20, 40);
            spawnStage10SceneNode(enemy, 0xf6, 2, -90.0f, 70.0f,
                                  0x4000, 1.0, 3000, 20, 40);
            spawnStage10SceneNode(enemy, 0xf7, 3, 160.0f, -50.0f,
                                  0x4000, 1.0, 3000, 20, 40);
            break;
        case 0xe0:
            spawnStage10SceneNode(enemy, 0xe1, enemy.childIndex,
                                  enemy.childIndex == 0 ? 10.0f : -10.0f,
                                  -3000.0f, 0x4000, 1.0,
                                  99999999, 0, 100);
            break;
        case 0xe1:
            if (enemy.childIndex == 0) {
                spawnStage10SceneNode(enemy, 0xed, 0, 0.0f, 0.0f,
                                      0x4000, 1.0, 20000, 100, 60);
                spawnStage10SceneNode(enemy, 0xf8, 0, 0.0f, 0.0f,
                                      0x4000, 1.0, 4000, 30, 40);
            }
            else {
                spawnStage10SceneNode(enemy, 0xee, 1, 0.0f, 0.0f,
                                      0x4000, 1.0, 20000, 100, 60);
                spawnStage10SceneNode(enemy, 0xf9, 1, 0.0f, 0.0f,
                                      0x4000, 1.0, 4000, 30, 40);
            }
            break;
        case 0xe2:
            spawnStage10SceneNode(enemy, 0xe3, enemy.childIndex,
                                  enemy.childIndex == 0 ? 10.0f : -10.0f,
                                  -3000.0f,
                                  enemy.childIndex == 0 ? 0x3830 : 0x4fa0,
                                  1.0, 99999999, 0, 100);
            break;
        case 0xe3:
            if (enemy.childIndex == 0) {
                spawnStage10SceneNode(enemy, 0xe4, 0, 0.0f, 0.0f,
                                      0x4000, 1.0, 7000, 50, 60);
                spawnStage10SceneNode(enemy, 0xe5, 1, 0.0f, 0.0f,
                                      0x4000, 1.0, 7000, 50, 60);
                spawnStage10SceneNode(enemy, 0xf2, 0, 0.0f, 0.0f,
                                      0x4000, 1.0, 3000, 30, 40);
            }
            else {
                spawnStage10SceneNode(enemy, 0xe6, 0, 0.0f, 0.0f,
                                      0x4000, 1.0, 7000, 50, 60);
                spawnStage10SceneNode(enemy, 0xe7, 1, 0.0f, 0.0f,
                                      0x4000, 1.0, 7000, 50, 60);
                spawnStage10SceneNode(enemy, 0xf3, 0, 0.0f, 0.0f,
                                      0x4000, 1.0, 3000, 30, 40);
            }
            break;
        default:
            break;
        }
    }

    if (isStructuralSceneNode(enemy.spawnType)) {
        const auto wave = [this](int offset) {
            return std::sin(static_cast<double>(frame_ + offset) *
                            kTau / 100.0);
        };
        const auto waveAngle = [&wave](int offset, double amplitude,
                                      int base = 0) {
            return sceneAngle(static_cast<int>(wave(offset) * amplitude) + base);
        };
        const auto orbitPoint = [](float centerX, float centerY,
                                   std::uint16_t angle, double radius) {
            const double radians = sceneRadians(angle);
            return std::array<float, 2>{
                centerX + static_cast<float>(std::cos(radians) * radius),
                centerY + static_cast<float>(std::sin(radians) * radius),
            };
        };

        switch (enemy.spawnType) {
        case 0xde:
            enemy.x = parent->x + enemy.originX;
            enemy.y = parent->y + enemy.originY +
                      static_cast<float>(wave(20) * 3.0);
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y - 100.0f +
                                static_cast<float>(wave(30) * 3.0);
            enemy.sourceAngle16 = 0;
            break;
        case 0xdf:
            enemy.x = parent->x + enemy.originX;
            enemy.y = parent->y + enemy.originY +
                      static_cast<float>(wave(40) * 3.0);
            enemy.sourceAngle16 = 0;
            break;
        case 0xe0: {
            enemy.x = parent->x + enemy.originX;
            enemy.y = parent->y + enemy.originY;
            const bool right = enemy.originX >= 0.0f;
            const auto drawAngle = right
                                       ? waveAngle(20, 400.0, 0x3060)
                                       : waveAngle(0, -400.0, -0x3060);
            const auto orbitAngle = right
                                        ? drawAngle
                                        : sceneAngle(drawAngle + 0x8000);
            const auto body = orbitPoint(enemy.x, enemy.y, orbitAngle, 200.0);
            const auto marker = orbitPoint(enemy.x, enemy.y, orbitAngle, 390.0);
            enemy.angle = body[0];
            enemy.speed = body[1];
            enemy.markerDrawX = marker[0];
            enemy.markerDrawY = marker[1];
            enemy.sourceAngle16 = drawAngle;
            enemy.secondaryAngle16 = orbitAngle;
            break;
        }
        case 0xe1: {
            const float previousX = enemy.x;
            const float previousY = enemy.y;
            enemy.x = parent->markerDrawX;
            enemy.y = parent->markerDrawY;
            const bool right = enemy.originX >= 0.0f;
            const auto drawAngle = right
                                       ? waveAngle(30, 700.0, 0x24a8)
                                       : waveAngle(30, -400.0, -0x24a8);
            const auto orbitAngle = right
                                        ? drawAngle
                                        : sceneAngle(drawAngle + 0x8000);
            const auto markerAngle = waveAngle(40, right ? 800.0 : -800.0);
            // FUN_1400f1250 deliberately uses the pre-assignment coordinates
            // for the right body's first frame, but the new parent coordinates
            // for the left body.  This preserves the original off-screen
            // (10,-3000) first-frame queue on the right branch.
            const float bodyCenterX = right ? previousX : enemy.x;
            const float bodyCenterY = right ? previousY : enemy.y;
            const auto body = orbitPoint(bodyCenterX, bodyCenterY,
                                         orbitAngle, 200.0);
            const auto marker = orbitPoint(enemy.x, enemy.y,
                                           orbitAngle, 313.0);
            enemy.angle = body[0];
            enemy.speed = body[1];
            enemy.markerDrawX = marker[0];
            enemy.markerDrawY = marker[1];
            enemy.sourceAngle16 = drawAngle;
            enemy.secondaryAngle16 = orbitAngle;
            enemy.targetAngle16 = markerAngle;
            break;
        }
        case 0xe2: {
            enemy.x = parent->x + enemy.originX;
            enemy.y = parent->y + enemy.originY;
            const bool right = enemy.originX >= 0.0f;
            const auto bodyAngle = sceneAngle(
                static_cast<int>(enemy.sourceAngle16) +
                static_cast<int>(wave(70) * (right ? 200.0 : -200.0)));
            const auto body = orbitPoint(enemy.x, enemy.y, bodyAngle, 300.0);
            const auto marker = orbitPoint(enemy.x, enemy.y, bodyAngle,
                                           right ? 560.0 : 490.0);
            enemy.angle = body[0];
            enemy.speed = body[1];
            enemy.markerDrawX = marker[0];
            enemy.markerDrawY = marker[1];
            enemy.secondaryAngle16 = bodyAngle;
            break;
        }
        case 0xe3: {
            const float previousX = enemy.x;
            const float previousY = enemy.y;
            // The timer-zero frame keeps the constructor's (+/-10,-3000)
            // coordinates.  Later frames assign the parent marker only after
            // saving the coordinates used by the body draw call.
            if (enemy.helperTimer > 0) {
                enemy.x = parent->markerDrawX;
                enemy.y = parent->markerDrawY;
            }
            const bool right = enemy.originX >= 0.0f;
            const auto bodyAngle = sceneAngle(
                static_cast<int>(enemy.sourceAngle16) +
                static_cast<int>(wave(80) * (right ? 400.0 : -300.0)));
            const auto satelliteAngle = waveAngle(
                88, right ? 800.0 : -600.0, right ? 1000 : 0);
            const auto body = orbitPoint(previousX, previousY,
                                         bodyAngle, 300.0);
            const auto marker = orbitPoint(enemy.x, enemy.y, bodyAngle,
                                           right ? 490.0 : 420.0);
            enemy.angle = body[0];
            enemy.speed = body[1];
            enemy.markerDrawX = marker[0];
            enemy.markerDrawY = marker[1];
            // Original fields +0x42/+0x44 feed FUN_1400f3060's children.
            enemy.secondaryAngle16 = bodyAngle;
            enemy.targetAngle16 = satelliteAngle;
            break;
        }
        default:
            break;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        finishRootFrame();
        return;
    }

    const SceneCombatWindow window = sceneCombatWindow(enemy.spawnType);
    const bool mediumNode = enemy.spawnType <= 0xf1;

    float targetX = parent->x + enemy.originX;
    float targetY = parent->y + enemy.originY;
    const auto waveAngle = [this](int offset, double amplitude,
                                  int base = 0) {
        return sceneAngle(static_cast<int>(
                              std::sin(static_cast<double>(frame_ + offset) *
                                       kTau / 100.0) * amplitude) +
                          base);
    };
    const auto setOrbitTarget = [&targetX, &targetY](float centerX,
                                                     float centerY,
                                                     std::uint16_t angle,
                                                     double radius) {
        const double radians = sceneRadians(angle);
        targetX = centerX + static_cast<float>(std::cos(radians) * radius);
        targetY = centerY + static_cast<float>(std::sin(radians) * radius);
    };
    // FUN_1400f3060/FUN_1400f4430 keep the queued body angle separate
    // from +0x40, which combat states reuse for aimed fire.
    enemy.secondaryAngle16 = 0;
    switch (enemy.spawnType) {
    case 0xe4:
        enemy.secondaryAngle16 = waveAngle(88, 800.0);
        setOrbitTarget(parent->markerDrawX, parent->markerDrawY,
                       sceneAngle(parent->targetAngle16 + 0x5770), 70.0);
        break;
    case 0xe5:
        enemy.secondaryAngle16 = waveAngle(80, 400.0);
        setOrbitTarget(parent->x, parent->y,
                       sceneAngle(parent->secondaryAngle16 + 1000), 270.0);
        break;
    case 0xe6:
        enemy.secondaryAngle16 = waveAngle(88, -800.0);
        setOrbitTarget(parent->markerDrawX, parent->markerDrawY,
                       sceneAngle(parent->targetAngle16 + 0x3060), 60.0);
        break;
    case 0xe7:
        enemy.secondaryAngle16 = waveAngle(80, -400.0);
        setOrbitTarget(parent->x, parent->y,
                       sceneAngle(parent->secondaryAngle16 - 1000), 260.0);
        break;
    case 0xed:
        enemy.secondaryAngle16 = waveAngle(30, 700.0);
        setOrbitTarget(parent->x, parent->y,
                       waveAngle(30, 700.0, 0x20c0), 300.0);
        break;
    case 0xee:
        enemy.secondaryAngle16 = waveAngle(30, -700.0);
        setOrbitTarget(parent->x, parent->y,
                       waveAngle(30, -400.0, 0x5f40), 300.0);
        break;
    case 0xf1:
        targetX = parent->markerDrawX + enemy.originX;
        targetY = parent->markerDrawY + enemy.originY;
        break;
    case 0xf2:
        enemy.secondaryAngle16 = waveAngle(80, 400.0);
        setOrbitTarget(parent->x, parent->y,
                       sceneAngle(parent->sourceAngle16 +
                                  static_cast<int>(
                                      std::sin(static_cast<double>(frame_ + 80) *
                                               kTau / 100.0) * 400.0)),
                       400.0);
        break;
    case 0xf3:
        enemy.secondaryAngle16 = waveAngle(80, 400.0);
        setOrbitTarget(parent->x, parent->y,
                       sceneAngle(parent->sourceAngle16 +
                                  static_cast<int>(
                                      std::sin(static_cast<double>(frame_ + 80) *
                                               kTau / 100.0) * -400.0)),
                       370.0);
        break;
    case 0xf8:
        enemy.secondaryAngle16 = waveAngle(30, 700.0);
        setOrbitTarget(parent->x, parent->y,
                       waveAngle(30, 700.0, 0x1cd8), 190.0);
        break;
    case 0xf9:
        enemy.secondaryAngle16 = waveAngle(30, -700.0);
        setOrbitTarget(parent->x, parent->y,
                       waveAngle(30, -400.0, 0x6328), 190.0);
        break;
    default:
        break;
    }

    const float dx = targetX - enemy.x;
    const float dy = targetY - enemy.y;
    const float distance = std::sqrt(dx * dx + dy * dy);
    const auto heading = sceneAngle(static_cast<int>(
        std::atan2(static_cast<double>(dy), static_cast<double>(dx)) *
        65536.0 / kTau));
    const double headingRadians = sceneRadians(heading);
    enemy.x += static_cast<float>(std::cos(headingRadians) *
                                  (static_cast<double>(distance) / 3.0));
    enemy.y += static_cast<float>(std::sin(headingRadians) *
                                  (static_cast<double>(distance) / 3.0));

    if (enemy.helperState == 0) {
        bool missedEntryWindow = false;
        if (enemy.helperTimer == 0 && frame_ >= window.startFrame) {
            enemy.targetable = false;
            missedEntryWindow = true;
            if (mediumNode) {
                // FUN_1400f3060 keeps missed medium nodes alive in the
                // alternate state-2 frame family.
                enemy.helperState = 2;
            }
            else {
                // FUN_1400f4430 removes small nodes that miss their entry.
                enemy.active = false;
                return;
            }
        }
        const float activationMin = enemy.spawnType <= 0xf1 ? 90.0f : 60.0f;
        const float activationMax = enemy.spawnType <= 0xf1 ? 630.0f : 660.0f;
        if (!missedEntryWindow && frame_ >= window.startFrame &&
            enemy.x >= activationMin &&
            enemy.x <= activationMax && enemy.y >= activationMin &&
            enemy.y <= activationMax) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            enemy.sourceAngle16 = 0x4000;
        }
        if (!missedEntryWindow && root->helperState > 0) {
            enemy.targetable = false;
            enemy.helperState = mediumNode ? 3 : 2;
        }
    }
    const float horizontalOrigin = player_.x / 6.0f;
    const auto queueCombatBody = [&enemy, horizontalOrigin]() {
        enemy.drawBodyThisFrame = enemy.active &&
            enemy.x >= horizontalOrigin - 80.0f &&
            enemy.x <= horizontalOrigin + 680.0f &&
            enemy.y >= -80.0f && enemy.y <= 800.0f;
    };
    enemy.drawHp = enemy.hp;
    if (enemy.helperState != 1) {
        queueCombatBody();
        finishRootFrame();
        return;
    }

    const auto aim = [this, &enemy]() {
        return sceneAngle(static_cast<int>(std::atan2(
            static_cast<double>(player_.y - enemy.y),
            static_cast<double>(player_.x - enemy.x)) * 65536.0 / kTau));
    };
    const int timer = enemy.helperTimer;
    const bool firingEnabled = frame_ < window.endFrame && enemy.targetable;

    if (enemy.spawnType >= 0xf2) {
        const int local = timer >= 20 ? (timer - 20) % 50 : -1;
        if (firingEnabled && local >= 0 && local < 24 && local % 4 == 0) {
            if (local == 0) enemy.sourceAngle16 = aim();
            const double speed = 6.4 + local * 0.2;
            spawnProjectileNode(0x0d, 0, enemy.x, enemy.y,
                                enemy.sourceAngle16, 0.0f, speed, 1, 0);
            spawnProjectileNode(0x0d, 0, enemy.x, enemy.y,
                                enemy.sourceAngle16, 0.0f, speed + 2.0,
                                1, 0);
            enemy.sourceAngle16 = approachSceneAngle(
                enemy.sourceAngle16, aim(), 0x100);
        }
    }
    else if (enemy.spawnType == 0xed || enemy.spawnType == 0xee) {
        if (firingEnabled && timer >= 20 && (timer - 20) % 7 == 0) {
            const bool firstFamily = (enemy.spawnType == 0xed) == (timer < 420);
            const int selector = firstFamily ? 3 : 2;
            for (int layer = 0; layer < 4; ++layer) {
                const double speed = 6.4 + layer * 0.9;
                const int base = timer * (firstFamily ? 500 : -500) +
                                 layer * (firstFamily ? 900 : -900) +
                                 (firstFamily ? -10000 : 10000);
                spawnProjectileNode(selector, 0, enemy.x, enemy.y,
                                    sceneAngle(base), 0.0f, speed, 1, 0);
                spawnProjectileNode(selector, 0, enemy.x, enemy.y,
                                    sceneAngle(base + 0x8000), 0.0f,
                                    speed, 1, 0);
            }
        }
    }
    else if (enemy.spawnType == 0xf1) {
        if (firingEnabled && timer >= 20 && timer < 420 &&
            (timer - 20) % 5 == 0) {
            for (int layer = 0; layer < 4; ++layer) {
                const int spin = timer * 0x1e0;
                const double speed = 6.4 + layer * 0.7;
                spawnProjectileNode(3, 0, enemy.x, enemy.y,
                                    sceneAngle(spin + layer * 600 - 0x2580),
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(3, 0, enemy.x, enemy.y,
                                    sceneAngle(spin + layer * 600 + 0x5a80),
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(10, 0, enemy.x, enemy.y,
                                    sceneAngle(-spin - layer * 0xaf0 + 0x12c0),
                                    0.0f, 5.2 + layer * 0.8, 1, 0);
                spawnProjectileNode(10, 0, enemy.x, enemy.y,
                                    sceneAngle(-spin - layer * 0xaf0 - 0x6d40),
                                    0.0f, 5.2 + layer * 0.8, 1, 0);
            }
        }
        if (firingEnabled && timer >= 440 && (timer - 440) % 5 == 0) {
            for (int layer = 0; layer < 4; ++layer) {
                const int spin = timer * 0x1e0;
                spawnProjectileNode(0x0b, 0, enemy.x, enemy.y,
                                    sceneAngle(spin + layer * 0xaf0 - 0x2580),
                                    0.0f, 5.2 + layer * 0.8, 1, 0);
                spawnProjectileNode(0x0b, 0, enemy.x, enemy.y,
                                    sceneAngle(spin + layer * 0xaf0 + 0x5a80),
                                    0.0f, 5.2 + layer * 0.8, 1, 0);
                spawnProjectileNode(2, 0, enemy.x, enemy.y,
                                    sceneAngle(-spin - layer * 600 + 0x12c0),
                                    0.0f, 6.4 + layer * 0.7, 1, 0);
                spawnProjectileNode(2, 0, enemy.x, enemy.y,
                                    sceneAngle(-spin - layer * 600 - 0x6d40),
                                    0.0f, 6.4 + layer * 0.7, 1, 0);
            }
        }
    }
    else {
        const int local = timer >= 20 ? (timer - 20) % 75 : -1;
        if (firingEnabled && local >= 0 && local < 32 && local % 4 == 0) {
            if (local == 0) enemy.sourceAngle16 = aim();
            const double speed = 8.0 + local * 0.07;
            spawnProjectileNode(0x0b, 0, enemy.x, enemy.y,
                                enemy.sourceAngle16, 0.0f, speed, 1, 0);
            spawnProjectileNode(0x0b, 0, enemy.x, enemy.y,
                                sceneAngle(enemy.sourceAngle16 - 1000),
                                0.0f, speed - 1.0, 1, 0);
            spawnProjectileNode(0x0b, 0, enemy.x, enemy.y,
                                sceneAngle(enemy.sourceAngle16 + 1000),
                                0.0f, speed - 1.0, 1, 0);
            enemy.sourceAngle16 = approachSceneAngle(
                enemy.sourceAngle16, aim(), 0x80);
        }
    }

    enemy.targetable = enemy.x >= horizontalOrigin &&
                       enemy.x <= horizontalOrigin + 600.0f &&
                       enemy.y >= 0.0f && enemy.y <= 720.0f;
    const bool specialMedium = enemy.spawnType == 0xed ||
                               enemy.spawnType == 0xee ||
                               enemy.spawnType == 0xf1;
    if (specialMedium && !enemy.targetable) {
        enemy.helperState = 3;
    }

    if (enemy.hp < 1) {
        // Scene nodes provide their own exact death mode.  Type 0x40 defers
        // the generic immediate effect and carries the original reward helper's
        // feedback strength 8 while the remaining fields stay scene-exact.
        StageEnemy rewardSnapshot = enemy;
        rewardSnapshot.spawnType = 0x40;
        spawnEnemyDeathRewardBurst(rewardSnapshot, 1000, false);

        if (mediumNode && specialMedium) {
            spawnEnemyDeathEffects(enemy, 2);
            spawnPlayerSideObject(0x19, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
            if (enemy.spawnType == 0xf1 && player_.bombLock == 0) {
                const std::uint32_t random = sceneScriptRand(
                    static_cast<std::uint32_t>(enemy.entityId));
                const auto rewardAngle = sceneAngle(
                    static_cast<int>(random % 0x4001u) + 0x2000);
                spawnRewardItem(6, enemy.x, enemy.y, rewardAngle,
                                4.0f, 30);
            }
        }
        else {
            spawnEnemyDeathEffects(enemy, 1);
        }

        enemy.targetable = false;
        if (mediumNode) {
            ++enemy.helperState;
        }
        else {
            enemy.active = false;
        }
    }

    queueCombatBody();
    finishRootFrame();
}

bool StageRuntime::drawStage10SceneNode(const StageEnemy& enemy, float x,
                                        float y, int exactLayer) const {
    if (!isStage10SceneNodeType(enemy.spawnType)) return false;
    if (!enemy.drawBodyThisFrame) return true;

    if (isStructuralSceneNode(enemy.spawnType)) {
        const auto drawExtraLarge = [this](int frame, float drawX, float drawY,
                                            std::uint16_t angle = 0,
                                            bool reverseX = false,
                                            double scale = 1.0) {
            const int graph = frameAt(enemyExtraLargeFrames_, frame);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      scale, scale, reverseX);
            }
        };
        const auto drawLarge = [this](int frame, float drawX, float drawY,
                                      std::uint16_t angle = 0,
                                      bool reverseX = false,
                                      double scale = 1.0) {
            const int graph = frameAt(enemyLargeFrames_, frame);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      scale, scale, reverseX);
            }
        };
        const auto orbitPoint = [](float centerX, float centerY,
                                   std::uint16_t angle, double radius) {
            const double radians = sceneRadians(angle);
            return std::array<float, 2>{
                centerX + static_cast<float>(std::cos(radians) * radius),
                centerY + static_cast<float>(std::sin(radians) * radius),
            };
        };
        const auto toScreenPoint = [x, y, &enemy](float localX,
                                                   float localY) {
            return std::array<float, 2>{
                x + localX - enemy.x,
                y + localY - enemy.y,
            };
        };

        const bool right = enemy.originX >= 0.0f;
        const int sourceFrame = std::max(0, frame_ - 1);
        switch (enemy.spawnType) {
        case 0xde: {
            if (exactLayer != 0x13) return true;
            drawExtraLarge(0, x, y);
            drawLarge(71, x, y - 240.0f);
            const double scale = 1.0 +
                std::sin(static_cast<double>(sourceFrame + 30) *
                         kTau / 100.0) * 0.1;
            const auto marker = toScreenPoint(enemy.markerDrawX,
                                              enemy.markerDrawY);
            drawLarge(72, marker[0], marker[1],
                      0, false, scale);
            break;
        }
        case 0xdf:
            if (exactLayer == 0x12) {
                drawExtraLarge(1, x, y);
            }
            break;
        case 0xe0: {
            if (exactLayer != 0x11) return true;
            const auto body = toScreenPoint(enemy.angle, enemy.speed);
            drawExtraLarge(2, body[0], body[1],
                           enemy.sourceAngle16, !right);
            break;
        }
        case 0xe1: {
            const auto body = toScreenPoint(enemy.angle, enemy.speed);
            const auto marker = toScreenPoint(enemy.markerDrawX,
                                              enemy.markerDrawY);
            if (exactLayer == 0x12) {
                drawExtraLarge(3, body[0], body[1],
                               enemy.sourceAngle16, !right);
            }
            if (exactLayer == 0x11) {
                drawLarge(73, marker[0], marker[1],
                          enemy.targetAngle16, !right);
            }
            break;
        }
        case 0xe2: {
            if (exactLayer != 0x11) return true;
            const auto body = toScreenPoint(enemy.angle, enemy.speed);
            drawExtraLarge(right ? 4 : 6, body[0], body[1],
                           enemy.secondaryAngle16);
            break;
        }
        case 0xe3: {
            if (exactLayer != 0x10) return true;
            const int markerFrame = right ? 75 : 77;
            const int bodyFrame = right ? 5 : 7;
            const int satelliteFrame = right ? 74 : 76;
            const int satelliteOffset = right ? 0x5770 : 0x3060;
            const double satelliteRadius = right ? 70.0 : 60.0;
            const auto satellite = orbitPoint(
                enemy.markerDrawX, enemy.markerDrawY,
                sceneAngle(enemy.targetAngle16 + satelliteOffset),
                satelliteRadius);
            const auto body = toScreenPoint(enemy.angle, enemy.speed);
            const auto marker = toScreenPoint(enemy.markerDrawX,
                                              enemy.markerDrawY);
            const auto satelliteScreen = toScreenPoint(satellite[0],
                                                       satellite[1]);
            const double scale = 1.0 +
                std::sin(static_cast<double>(sourceFrame + 88) *
                         kTau / 100.0) * 0.1;

            // FUN_1400f1250 queues the marker layer before the XL body.
            drawLarge(markerFrame, marker[0], marker[1],
                      enemy.targetAngle16);
            drawExtraLarge(bodyFrame, body[0], body[1],
                           enemy.secondaryAngle16);
            drawLarge(satelliteFrame, satelliteScreen[0], satelliteScreen[1],
                      enemy.targetAngle16, false, scale);
            break;
        }
        default:
            break;
        }
        return true;
    }

    int handle = -1;
    if (enemy.spawnType <= 0xf1) {
        const int frame = 174 + enemy.spawnType - 0xe4 +
                          (enemy.drawHelperState == 2 ? 14 : 0);
        handle = frameAt(enemyMediumFrames_, frame);
    }
    else {
        handle = frameAt(enemySmallFrames_, 144 + enemy.spawnType - 0xf2);
    }

    if (enemy.drawHelperState == 1 && enemy.targetable) {
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot,
                            enemy.spawnType <= 0xf1 ? 1 : 2,
                            x, y, exactLayer);
    }

    const int bodyLayer = enemy.spawnType <= 0xf1 &&
                                  enemy.drawHelperState == 2
                              ? 0x14
                              : 0x17;
    if (exactLayer != bodyLayer) {
        return true;
    }

    if (handle != -1) {
        drawOriginalMode7Node(handle, x, y, enemy.secondaryAngle16,
                              1.0, 1.0, false);
        if (enemy.drawHelperState == 1 && enemy.drawHelperTimer < 40) {
            const int alpha = std::clamp(static_cast<int>(
                std::sin(static_cast<double>(enemy.drawHelperTimer + 40) *
                         kPi / 80.0) * 255.0), 0, 255);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            drawOriginalMode7Node(handle, x, y, enemy.secondaryAngle16,
                                  1.0, 1.0, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
    }

    return true;
}

} // namespace reconstructed
