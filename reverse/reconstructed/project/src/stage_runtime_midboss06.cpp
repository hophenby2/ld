#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kMidboss06Pi = 3.14159265358979323846;
constexpr double kMidboss06Tau = kMidboss06Pi * 2.0;
constexpr std::size_t kMidboss06EntityCap = 0x200;

std::uint16_t midboss06Angle(int value) {
    return static_cast<std::uint16_t>(value & 0xffff);
}

double midboss06Radians(std::uint16_t angle) {
    return static_cast<double>(angle) * kMidboss06Tau / 65536.0;
}

std::uint16_t midboss06AngleTo(float x0, float y0, float x1, float y1) {
    return midboss06Angle(static_cast<int>(
        std::atan2(static_cast<double>(y1 - y0),
                   static_cast<double>(x1 - x0)) *
        65536.0 / kMidboss06Tau));
}

std::uint16_t midboss06Approach(std::uint16_t current,
                                std::uint16_t target, int step) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return midboss06Angle(static_cast<int>(current) +
                          std::clamp(delta, -step, step));
}

std::uint32_t midboss06Rand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

double midboss06Unit(int seed) {
    return static_cast<double>(midboss06Rand(seed) >> 8) /
           static_cast<double>(1u << 24);
}

int midboss06Frame(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

} // namespace

bool StageRuntime::isStage06MidbossNodeType(int spawnType) const {
    return spawnType >= 0x61 && spawnType <= 0x63;
}

bool StageRuntime::spawnStage06MidbossNode(StageEnemy& parent, int spawnType,
                                            int childIndex,
                                            float initialRadius,
                                            std::uint16_t angle16,
                                            double spinAmplitude) {
    if (!isStage06MidbossNodeType(spawnType) ||
        parent.spawnType != 0x143 ||
        enemies_.size() + pendingEnemies_.size() >= kMidboss06EntityCap) {
        return false;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = 0x49;
    node.sourceHitPoints = 99999999;
    node.hp = 99999999;
    node.maxHp = 99999999;
    node.drawHp = 99999999;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = parent.spawnType;
    node.childIndex = childIndex;
    node.sourceX = static_cast<int>(std::lround(initialRadius));
    node.sourceY = 0;
    node.x = initialRadius;
    node.y = 0.0f;
    node.originX = parent.x;
    node.originY = parent.y;
    node.markerDrawX = initialRadius;
    node.markerDrawY = 0.0f;
    node.sourceAngle16 = angle16;
    node.secondaryAngle16 = angle16;
    node.targetAngle16 = angle16;
    node.sourceSpeed = spinAmplitude;
    node.speed = static_cast<float>(spinAmplitude);
    node.angle = static_cast<float>(midboss06Radians(angle16));
    node.radius = 20;
    node.sourceDispatchKind = 10;
    node.sourceDispatchField = 20;
    node.rewardWeight = 0;
    node.activationDelay = 0;
    node.targetable = false;
    node.sourceNote = "S06 FUN_1400db1f0 internal orbit node";

    ++parent.liveChildCount;
    pendingEnemies_.push_back(node);
    return true;
}

void StageRuntime::updateStage06Midboss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHp = enemy.hp;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);

    const auto oldTargetAngle = midboss06AngleTo(
        enemy.x, enemy.y, lateStageBossTargetX_, lateStageBossTargetY_);
    if (frame_ % 50 == 0) {
        lateStageBossTargetX_ = 210.0f + static_cast<float>(
            midboss06Rand(frame_) % 301u);
        lateStageBossTargetY_ = 150.0f + static_cast<float>(
            midboss06Rand(selectedStage_ * 111 + frame_) % 101u);
    }

    if (lateStageBossPhaseMode_ == 1 &&
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
        enemy.helperState = 5;
        enemy.helperTimer = 0;
        enemy.liveChildCount = 0;
        lateStageBossBreaksRemaining_ = 0;
        lateStageBossPhaseMode_ = -1;
    }

    // FUN_1400db1f0 queues the current state's body before its transition tail.
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;

    const auto steerAndMove = [&enemy, oldTargetAngle]() {
        enemy.sourceAngle16 = midboss06Approach(
            enemy.sourceAngle16, oldTargetAngle, 0x200);
        const double radians = midboss06Radians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
    };

    const int timer = enemy.helperTimer;
    switch (enemy.helperState) {
    case 0:
        if (timer == 0) {
            playPlayerSound(bossSe1SoundHandle_, 0x19);
            lateStageBossPhaseMode_ = 0;
            lateStageBossPhaseIndex_ = 0;
            lateStageBossBreaksRemaining_ = 1;
            lateStageBossCountdown_ = 0;
            lateStageBossMaxHp_ = 50000;
            lateStageBossTargetX_ = 400.0f;
            lateStageBossTargetY_ = 240.0f;
            enemy.targetable = false;
        }
        if (timer <= 110) {
            enemy.x = enemy.originX - 500.0f + static_cast<float>(
                std::sin(static_cast<double>(timer) * kMidboss06Pi / 220.0) *
                500.0);
            enemy.y = enemy.originY + static_cast<float>(
                std::sin(static_cast<double>(timer) * kMidboss06Pi / 110.0) *
                100.0);
        }
        if (timer == 120) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.hp = 50000;
            enemy.maxHp = 50000;
            enemy.drawHp = 50000;
            enemy.sourceSpeed = 0.3;
            enemy.speed = 0.3f;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
            lateStageBossMaxHp_ = 50000;
            lateStageBossCountdown_ = 0x690;
            lateStageBossCountdownDraw_ = 0x690;
            lateStageBossPhaseMode_ = 1;
        }
        break;

    case 1:
    case 3: {
        steerAndMove();
        if (timer == 1) {
            spawnStage06MidbossNode(enemy, 0x61, 0, 100.0f, 0xc000, 330.0);
            spawnStage06MidbossNode(enemy, 0x61, 1, 100.0f, 0x4000, 330.0);
            playPlayerSound(bossSe1SoundHandle_, 0x19);
        }
        if (timer == 10) {
            const int primaryCount = difficulty == 0 ? 4 : 8;
            const int secondaryCount = difficulty < 2
                                           ? 0
                                           : (difficulty == 2 ? 4 : 8);
            const int primaryType = enemy.helperState == 1 ? 0x62 : 0x63;
            const int secondaryType = enemy.helperState == 1 ? 0x63 : 0x62;
            for (int i = 0; i < primaryCount; ++i) {
                spawnStage06MidbossNode(
                    enemy, primaryType, i + 2, 150.0f,
                    midboss06Angle(i * (0x10000 / primaryCount) - 0x4000),
                    -260.0);
            }
            for (int i = 0; i < secondaryCount; ++i) {
                spawnStage06MidbossNode(
                    enemy, secondaryType, i + 2 + primaryCount, 200.0f,
                    midboss06Angle(i * (0x10000 / secondaryCount) + 0x1000),
                    220.0);
            }
            playPlayerSound(bossSe1SoundHandle_, 0x19);
        }
        if (timer == 0x28a) {
            ++enemy.helperState;
            enemy.helperTimer = 0;
            enemy.targetable = false;
            enemy.targetableTimer = 0;
        }
        break;
    }

    case 2:
    case 4: {
        if (timer == 1) {
            enemy.originX = enemy.x;
            enemy.originY = enemy.y;
            if (enemy.helperState == 2) {
                enemy.markerDrawX = 220.0f;
                enemy.markerDrawY = 150.0f;
            }
            else {
                enemy.markerDrawX = 450.0f;
                enemy.markerDrawY = 210.0f;
            }
            playPlayerSound(bossSe1SoundHandle_, 0x19);
        }
        const double progress = std::sin(
            static_cast<double>(timer) * kMidboss06Pi / 160.0);
        enemy.x = enemy.originX + static_cast<float>(
            (enemy.markerDrawX - enemy.originX) * progress);
        enemy.y = enemy.originY + static_cast<float>(
            (enemy.markerDrawY - enemy.originY) * progress);

        const auto randomAngle = midboss06Angle(
            static_cast<int>(midboss06Rand(frame_) & 0xffffu));
        const double randomRadians = midboss06Radians(randomAngle);
        const double signedLimit = std::sin(randomRadians) * 300.0;
        const double drawRadius = midboss06Unit(frame_ + enemy.entityId * 111) *
                                  signedLimit;
        enemy.vx = static_cast<float>(std::cos(randomRadians) * drawRadius);
        enemy.vy = static_cast<float>(std::sin(randomRadians) * drawRadius);

        if (timer == 0x50) {
            enemy.helperTimer = 0;
            enemy.helperState = enemy.helperState == 4 ? 1
                                                       : enemy.helperState + 1;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }
        break;
    }

    case 5:
        enemy.targetable = false;
        if (timer < 0x78) {
            enemy.y += 0.1f;
            spawnStage02DeathExplosionChain(enemy);
        }
        else {
            enemy.drawBodyThisFrame = false;
        }
        if (timer == 0x78) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnEnemyDeathEffects(enemy, 2, false);
            clearLateStageGate(6);
            enemy.active = false;
        }
        break;

    default:
        break;
    }

    enemy.drawHp = enemy.hp;
    lateStageBossCountdownDraw_ = lateStageBossCountdown_;
    if (lateStageBossPhaseMode_ == 1 && lateStageBossCountdown_ > 0) {
        updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
        --lateStageBossCountdown_;
    }
}

void StageRuntime::updateStage06MidbossNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.targetable = false;
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    const auto deactivate = [this, &enemy, &parent](bool withEffect) {
        if (!enemy.active) return;
        if (withEffect) spawnEnemyDeathEffects(enemy, 1);
        enemy.active = false;
        if (parent != nullptr && parent->liveChildCount > 0) {
            --parent->liveChildCount;
        }
    };
    if (parent == nullptr || parent->spawnType != 0x143 || !parent->active ||
        parent->hp < 1 || lateStageBossCountdown_ < 1) {
        deactivate(parent != nullptr);
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    const float parentX = parent->x;
    const float parentY = parent->y;

    if (enemy.helperState == 0) {
        enemy.originX = parentX;
        enemy.originY = parentY;
        const double unit = midboss06Unit(
            frame_ + enemy.entityId * 0x457 + timer * 3);
        const int turn = static_cast<int>((1.0 - unit) * 3000.0) *
                         (enemy.sourceSpeed > 0.0 ? 1 : -1);
        enemy.sourceAngle16 = midboss06Angle(
            static_cast<int>(enemy.sourceAngle16) + turn);
        const double radius = midboss06Unit(
            frame_ + enemy.entityId * 0x15b3 + timer * 5) *
            static_cast<double>(enemy.markerDrawX);
        const double radians = midboss06Radians(enemy.sourceAngle16);
        enemy.x = parentX + static_cast<float>(std::cos(radians) * radius);
        enemy.y = parentY + static_cast<float>(std::sin(radians) * radius);
        if (timer == 0x28) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
    }
    else if (enemy.helperState == 1) {
        enemy.originX = parentX;
        enemy.originY = parentY;
        const int turn = static_cast<int>(
            std::sin(static_cast<double>(timer) * kMidboss06Tau / 600.0) *
            static_cast<double>(static_cast<int>(enemy.sourceSpeed)));
        enemy.sourceAngle16 = midboss06Angle(
            static_cast<int>(enemy.sourceAngle16) + turn);
        const double radians = midboss06Radians(enemy.sourceAngle16);
        enemy.x = parentX + static_cast<float>(
            std::cos(radians) * static_cast<double>(enemy.markerDrawX));
        enemy.y = parentY + static_cast<float>(
            std::sin(radians) * static_cast<double>(enemy.markerDrawX));

        if (enemy.spawnType == 0x61) {
            static constexpr std::array<int, 5> kInterval{{
                180, 120, 90, 90, 60,
            }};
            static constexpr std::array<double, 5> kSpeed{{
                5.0, 6.0, 6.5, 5.0, 7.0,
            }};
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            const int local = (timer - 50) % interval;
            const auto aimed = midboss06AngleTo(
                enemy.x, enemy.y, player_.x, player_.y);
            if (timer >= 50 && timer < 560 && local == 0) {
                enemy.targetAngle16 = aimed;
            }
            if (timer >= 50 && timer < 560 && local >= 0 && local < 20 &&
                (local & 3) == 0) {
                const double speed =
                    kSpeed[static_cast<std::size_t>(difficulty)] +
                    static_cast<double>(local) * 0.1;
                spawnProjectileNode(0x0b, 0, enemy.x, enemy.y,
                                    enemy.targetAngle16, 10.0f,
                                    speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(0x0b, 0, enemy.x, enemy.y,
                                        enemy.targetAngle16, 10.0f,
                                        speed + 2.0, 1, 0);
                }
                playPlayerSound(bullet1SoundHandle_, 0x0c);
            }
            enemy.targetAngle16 = midboss06Approach(
                enemy.targetAngle16, aimed, 0x30);
        }
        else {
            static constexpr std::array<int, 5> kInterval{{9, 6, 7, 7, 6}};
            static constexpr std::array<double, 5> kSpeed{{
                3.2, 3.8, 4.2, 4.5, 5.5,
            }};
            const int interval = kInterval[static_cast<std::size_t>(difficulty)];
            const bool burstWindow = timer < interval * 3 ||
                                     timer >= interval * 35 ||
                                     (timer - interval * 3) % (interval * 5) >=
                                         interval * 2;
            if (timer < 560 && timer % interval == 0 && burstWindow) {
                const float dx = enemy.x - player_.x;
                const float dy = enemy.y - player_.y;
                if (dx * dx + dy * dy >= 80.0f * 80.0f) {
                    const int direction = enemy.spawnType == 0x63 ? -1 : 1;
                    const auto shotAngle = midboss06Angle(
                        static_cast<int>(enemy.sourceAngle16) +
                        direction * timer * 0x14 - 0x8000);
                    spawnProjectileNode(
                        enemy.spawnType == 0x63 ? 5 : 4, 0,
                        enemy.x, enemy.y, shotAngle, 0.0f,
                        kSpeed[static_cast<std::size_t>(difficulty)] +
                            static_cast<double>(timer) * 0.0042,
                        1, 0);
                    playPlayerSound(bullet1SoundHandle_, 9);
                }
            }
        }

        if (timer == 600) {
            enemy.helperTimer = 0;
            if (enemy.spawnType == 0x61) {
                enemy.helperState = 2;
            }
            else {
                enemy.helperState = 3;
                enemy.sourceSpeed = 0.0;
                enemy.speed = 0.0f;
                enemy.targetAngle16 = midboss06AngleTo(
                    parentX, parentY, player_.x, player_.y);
            }
        }
    }
    else if (enemy.helperState == 2) {
        if (timer == 0x1e) {
            deactivate(false);
        }
    }
    else if (enemy.helperState == 3) {
        enemy.markerDrawX += 1.0f;
        enemy.sourceSpeed += 0.1;
        enemy.speed = static_cast<float>(enemy.sourceSpeed);
        const int direction = enemy.spawnType == 0x63 ? -1 : 1;
        enemy.sourceAngle16 = midboss06Angle(
            static_cast<int>(enemy.sourceAngle16) + direction * timer * 2);
        const double radians = midboss06Radians(enemy.sourceAngle16);
        enemy.originX += static_cast<float>(
            std::cos(radians) * enemy.sourceSpeed);
        enemy.originY += static_cast<float>(
            std::sin(radians) * enemy.sourceSpeed);
        enemy.x = enemy.originX + static_cast<float>(
            std::cos(radians) * static_cast<double>(enemy.markerDrawX));
        enemy.y = enemy.originY + static_cast<float>(
            std::sin(radians) * static_cast<double>(enemy.markerDrawX));
        spawnProjectileNode(5, 0x0f, enemy.x, enemy.y,
                            enemy.sourceAngle16, 0.0f, 0.0, 1, 0);

        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.x < horizontalOrigin - 50.0f ||
            enemy.x > horizontalOrigin + 650.0f ||
            enemy.y < -50.0f || enemy.y > 770.0f) {
            deactivate(false);
        }
    }

    enemy.drawHp = enemy.hp;
}

bool StageRuntime::drawStage06Midboss(const StageEnemy& enemy, float x,
                                       float y) const {
    if (enemy.spawnType != 0x143) return false;
    if (!enemy.drawBodyThisFrame) return true;

    const int state = enemy.drawHelperState;
    const int timer = enemy.drawHelperTimer;
    int frame = 65;
    if (state == 0) {
        frame = timer < 0x6e
                    ? 60 + (timer / 5) % 3
                    : 63 + ((timer - 0x6e) / 5) % 3;
    }
    else if (state >= 1 && state <= 4) {
        frame = 65 + (timer / 7) % 3;
    }
    else if (state == 5) {
        frame = 68 + (timer / 5) % 2;
    }

    const int graph = midboss06Frame(bossFrames_, frame);
    const float drawX = x + ((state == 2 || state == 4) ? enemy.vx : 0.0f);
    const float drawY = y + ((state == 2 || state == 4) ? enemy.vy : 0.0f);
    if (state == 2 || state == 4) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xc0);
    }
    if (graph != -1) {
        drawOriginalMode7Node(graph, drawX, drawY, 0,
                              1.0, 1.0, false);
    }
    else {
        DrawCircle(static_cast<int>(drawX), static_cast<int>(drawY),
                   40, GetColor(255, 96, 160), TRUE);
    }
    if (state == 2 || state == 4) {
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    return true;
}

bool StageRuntime::drawStage06MidbossNode(const StageEnemy& enemy, float x,
                                           float y) const {
    if (!isStage06MidbossNodeType(enemy.spawnType)) return false;
    if (!enemy.drawBodyThisFrame) return true;

    double scale = 1.0;
    if (enemy.drawHelperState == 0) {
        scale = std::sin(static_cast<double>(std::clamp(
                             enemy.drawHelperTimer, 0, 40)) *
                         kMidboss06Pi / 80.0);
    }
    else if (enemy.drawHelperState == 2) {
        scale = std::sin(static_cast<double>(std::clamp(
                             enemy.drawHelperTimer + 30, 30, 60)) *
                         kMidboss06Pi / 60.0);
    }

    const int graph = midboss06Frame(enemySmallFrames_, 71);
    const auto drawAngle = midboss06Angle(
        static_cast<int>(enemy.sourceAngle16) + frame_ * 0x29a);
    if (graph != -1) {
        drawOriginalMode7Node(graph, x, y, drawAngle,
                              scale, scale, false);
    }
    else if (scale > 0.0) {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(1, static_cast<int>(10.0 * scale)),
                   GetColor(255, 160, 220), TRUE);
    }
    return true;
}

} // namespace reconstructed
