#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kBoss09Pi = 3.14159265358979323846;
constexpr double kBoss09Tau = kBoss09Pi * 2.0;

std::uint16_t boss09Angle(int value) {
    return static_cast<std::uint16_t>(value & 0xffff);
}

double boss09Radians(std::uint16_t angle) {
    return static_cast<double>(angle) * kBoss09Tau / 65536.0;
}

std::uint16_t boss09AngleTo(float x0, float y0, float x1, float y1) {
    return boss09Angle(static_cast<int>(
        std::atan2(static_cast<double>(y1 - y0),
                   static_cast<double>(x1 - x0)) *
        65536.0 / kBoss09Tau));
}

std::uint16_t boss09Approach(std::uint16_t current, std::uint16_t target,
                             int step) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    return boss09Angle(static_cast<int>(current) +
                       std::clamp(delta, -step, step));
}

std::uint32_t boss09Rand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

double boss09Smooth(double value) {
    value = std::clamp(value, 0.0, 1.0);
    return value * value * (3.0 - 2.0 * value);
}

double boss09SineEase(double value) {
    value = std::clamp(value, 0.0, 1.0);
    return std::sin(value * kBoss09Pi * 0.5);
}

double boss09EaseBetween(int timer, int start, int end,
                         double from, double to) {
    if (timer <= start) return from;
    if (timer >= end) return to;
    const double t = static_cast<double>(timer - start) /
                     static_cast<double>(end - start);
    return from + (to - from) * boss09SineEase(t);
}

double boss09ReverseEaseBetween(int timer, int start, int end,
                                double from, double to) {
    if (timer <= start) return from;
    if (timer >= end) return to;
    const double t = static_cast<double>(timer - start) /
                     static_cast<double>(end - start);
    return from + (to - from) * (1.0 - std::cos(t * kBoss09Pi * 0.5));
}

bool boss09Periodic(int timer, int start, int end, int interval) {
    return timer >= start && (end == 0 || timer < end) &&
           (timer - start) % interval == 0;
}

bool boss09BurstPeriodic(int timer, int start, int end, int period,
                         int activeLength, int interval) {
    if (timer < start || (end != 0 && timer >= end)) return false;
    const int phase = (timer - start) % period;
    return phase < activeLength && phase % interval == 0;
}

int boss09NodeUpdateCase(int spawnType) {
    if (spawnType == 0xc3) return 0x75;
    if (spawnType == 0xcd) return 0x7c;
    if (spawnType >= 0xce && spawnType <= 0xd9) return 0x7d;
    if (spawnType >= 0xda && spawnType <= 0xdd) return 0x7e;
    return -1;
}

bool boss09NormalMoveState(int state) {
    return (state >= 0x0c && state <= 0x10) ||
           (state >= 0x12 && state <= 0x16);
}

std::pair<float, float> boss09NormalMoveTarget(int state) {
    switch (state) {
    case 0x0c:
    case 0x15: return {500.0f, 370.0f};
    case 0x0d:
    case 0x14: return {200.0f, 200.0f};
    case 0x0e:
    case 0x13: return {520.0f, 200.0f};
    case 0x0f:
    case 0x12: return {255.0f, 370.0f};
    case 0x10:
    case 0x16: return {360.0f, 100.0f};
    default: return {360.0f, 190.0f};
    }
}

int boss09NormalMoveDuration(int state) {
    return state >= 0x12 ? 20 : 30;
}

bool boss09CombatState(int state) {
    return state == 1 || state == 6 ||
           (state >= 0x0b && state <= 0x1b) ||
           state == 0x3d || state == 0x3e ||
           (state >= 0x6f && state <= 0x75) || state == 0xa1;
}

} // namespace

bool StageRuntime::isStage09BossNodeType(int spawnType) const {
    return spawnType == 0xc3 ||
           (spawnType >= 0xcd && spawnType <= 0xdd);
}

bool StageRuntime::spawnStage09BossNode(StageEnemy& parent, int spawnType,
                                        int childIndex, float offsetX,
                                        float offsetY,
                                        std::uint16_t angle16, double speed,
                                        int radius, bool attached) {
    if (!isStage09BossNodeType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= 0x200) {
        return false;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = boss09NodeUpdateCase(spawnType);
    node.sourceHitPoints = 99999999;
    node.hp = 99999999;
    node.maxHp = 99999999;
    node.drawHp = 99999999;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = 0x140;
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
    node.angle = static_cast<float>(boss09Radians(angle16));
    node.sourceSpeed = speed;
    node.speed = static_cast<float>(speed);
    node.radius = radius;
    node.sourceDispatchKind = 1;
    node.sourceDispatchField = attached ? 1 : 0;
    node.activationDelay = 0;
    node.targetable = false;
    node.drawBodyThisFrame = true;
    node.sourceNote = "S09 FUN_14004a970 internal boss node";
    pendingEnemies_.push_back(node);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage09Boss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHp = enemy.hp;

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int state = enemy.helperState;
    const int timer = enemy.helperTimer;
    // FUN_14004a970's +0x3c draw anchor advances only in the two long
    // travelling patterns.  The articulated pieces below use this value
    // independently of the root's collision position.
    if (state == 0x0b || state == 0x6f) {
        enemy.angle += static_cast<float>(timer) * 0.01f;
    }
    const auto aimed = [&]() {
        return boss09AngleTo(enemy.x, enemy.y, player_.x, player_.y);
    };
    const auto playBoss4 = [&]() {
        if (bossBgmHandles_[2] != -1) StopSoundMem(bossBgmHandles_[2]);
        activeBossBgmIndex_ = 3;
        if (bossBgmHandles_[3] != -1) {
            ChangeVolumeSoundMem(static_cast<int>(config_.bgmVolume * 25.5),
                                 bossBgmHandles_[3]);
            PlaySoundMem(bossBgmHandles_[3], DX_PLAYTYPE_LOOP, TRUE);
        }
    };
    const auto openPhase = [&](int nextState, int hp, int countdown,
                               int phaseIndex) {
        enemy.helperState = nextState;
        enemy.helperTimer = 0;
        enemy.hp = hp;
        enemy.maxHp = hp;
        enemy.drawHp = hp;
        enemy.sourceHitPoints = hp;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        lateStageBossMaxHp_ = hp;
        lateStageBossCountdown_ = countdown;
        lateStageBossCountdownDraw_ = countdown;
        lateStageBossPhaseMode_ = 1;
        lateStageBossPhaseIndex_ = phaseIndex;
    };
    const auto spawnPolarNode = [&](int spawnType, int index,
                                    std::uint16_t offsetAngle,
                                    float distance,
                                    std::uint16_t sourceAngle) {
        const double radians = boss09Radians(offsetAngle);
        return spawnStage09BossNode(
            enemy, spawnType, index,
            static_cast<float>(std::cos(radians) * distance),
            static_cast<float>(std::sin(radians) * distance),
            sourceAngle, 0.0, 30, true);
    };

    const bool shieldEligible = boss09CombatState(state) &&
                                lateStageBossPhaseMode_ == 1;
    if (shieldEligible) {
        const bool specialActive = player_.bombLock > 0 ||
                                   player_.bombLock < -100;
        if (!enemy.guardSpawnLatched && specialActive) {
            spawnStage09BossNode(enemy, 0xc3, 0, 0.0f, 0.0f, 0,
                                 0.0, 120, true);
            enemy.guardSpawnLatched = true;
        }
        if (enemy.guardSpawnLatched) {
            enemy.targetable = false;
            if (player_.invulnerableFrames < 61) {
                enemy.guardSpawnLatched = false;
                enemy.targetable = true;
            }
        }
    }

    if (lateStageBossPhaseMode_ == 1 && boss09CombatState(state) &&
        (enemy.hp < 1 || lateStageBossCountdown_ < 1)) {
        enemy.targetable = false;
        enemy.targetableTimer = 0;
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

        const int remaining = lateStageBossBreaksRemaining_;
        if (remaining >= 4) {
            enemy.helperState = 5;
            lateStageBossPhaseMode_ = 2;
        }
        else if (remaining == 3) {
            enemy.helperState = 10;
            lateStageBossPhaseMode_ = 2;
        }
        else if (remaining == 2) {
            enemy.helperState = difficulty < 4 ? 0x3c : 0xa0;
            lateStageBossPhaseMode_ = 2;
        }
        else {
            enemy.helperState = difficulty < 4 ? 99 : 199;
            lateStageBossPhaseMode_ = -1;
            lateStageClearStarted_ = true;
            // FUN_140003e60 raises the stage-clear flag at final timer 600.
            // The shared clear timeline needs a 120-frame offset so its
            // 480-frame endpoint lands on that recovered tick.
            lateStageClearTimer_ = -120;
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 360);
        }
        enemy.helperTimer = 0;
        enemy.helperState = std::max(0, enemy.helperState);
        enemy.guardSpawnLatched = false;
        lateStageBossBreaksRemaining_ = std::max(0, remaining - 1);
        lateStageBossPhaseIndex_ = std::min(3, lateStageBossPhaseIndex_ + 1);
        return;
    }

    switch (state) {
    case 0:
        enemy.targetable = false;
        if (timer == 0) playPlayerSound(bossSe8SoundHandle_, 0x19);
        if (timer >= 240) openPhase(1, 100000, 0x960, 0);
        break;
    case 1: {
        enemy.x = enemy.originX + static_cast<float>(
            std::sin(static_cast<double>(timer) * kBoss09Tau / 151.0) * 10.0);
        enemy.y = enemy.originY + static_cast<float>(
            std::sin(static_cast<double>(timer) * kBoss09Tau / 127.0) * 10.0);
        if (timer > 9) {
            const int cycle = (timer - 10) % 0x640;
            static constexpr std::array<int, 5> kCeInterval{{90, 70, 60, 48, 40}};
            if (cycle < 0x30c &&
                cycle % kCeInterval[static_cast<std::size_t>(difficulty)] == 0) {
                const std::uint32_t random = boss09Rand(timer);
                const auto offsetAngle = boss09Angle(
                    static_cast<int>(random % 0x10001u));
                const float distance = 30.0f +
                    static_cast<float>(random % 51u);
                const double radians = boss09Radians(offsetAngle);
                const float ox = static_cast<float>(std::cos(radians) * distance);
                const float oy = static_cast<float>(std::sin(radians) * distance);
                const auto sourceAngle = boss09Angle(
                    boss09AngleTo(enemy.x + ox, enemy.y + oy,
                                  player_.x, player_.y) - 0x8000);
                spawnPolarNode(0xce, cycle, offsetAngle, distance, sourceAngle);
            }
            if (cycle >= 0x5a && cycle < 0x14a &&
                (cycle - 0x5a) % 0x1e == 0) {
                spawnPolarNode(
                    0xcf, cycle,
                    boss09Angle(cycle * 0x96 - 0x74bc), 120.0f,
                    boss09Angle(-0x16fc - cycle * 0x32));
            }
            if (cycle >= 0x168 && cycle < 600 &&
                (cycle - 0x168) % 0x1e == 0) {
                spawnPolarNode(
                    0xd0, cycle,
                    boss09Angle(0x92f0 - cycle * 0x96), 120.0f,
                    boss09Angle(0x6240 + cycle * 0x32));
            }
            if (cycle == 0x32a) {
                spawnStage09BossNode(enemy, 0xd3, cycle,
                                     0.0f, -100.0f, 0x4000,
                                     0.0, 30, true);
            }
            const auto fixedAim = boss09AngleTo(
                360.0f, -100.0f, player_.x, player_.y);
            const auto satelliteOffset = boss09Angle(
                cycle * 0x3c + 0x7b20);
            const int phase = cycle * 0x37 + 0x4b88;
            if (cycle >= 0x348 && cycle < 0x456 &&
                (cycle - 0x348) % 0x28 == 0) {
                spawnPolarNode(
                    0xd1, cycle, satelliteOffset, 120.0f,
                    boss09Angle(fixedAim + phase - 24000));
            }
            if (cycle >= 0x352 && cycle < 0x456 &&
                (cycle - 0x352) % 0x28 == 0) {
                spawnPolarNode(
                    0xd2, cycle, satelliteOffset, 120.0f,
                    boss09Angle(fixedAim - phase + 24000));
            }
            if (cycle == 0x4d8) {
                spawnStage09BossNode(enemy, 0xd4, cycle,
                                     60.0f, 20.0f, 0xc000,
                                     0.0, 30, true);
                spawnStage09BossNode(enemy, 0xd5, cycle,
                                     -60.0f, -20.0f, 0xc000,
                                     0.0, 30, true);
            }
        }
        break;
    }
    case 5: {
        enemy.targetable = false;
        if (timer == 1) spawnStage02DeathExplosionChain(enemy);
        if (timer < 120) {
            const double t = boss09Smooth(static_cast<double>(timer) / 120.0);
            enemy.x += (360.0f - enemy.x) * static_cast<float>(0.04 + t * 0.06);
            enemy.y += (190.0f - enemy.y) * static_cast<float>(0.04 + t * 0.06);
        }
        if (timer >= 150) openPhase(6, 100000, 0x960, 1);
        break;
    }
    case 6: {
        enemy.x = enemy.originX + static_cast<float>(
            std::sin(static_cast<double>(frame_) * kBoss09Tau / 151.0) * 10.0);
        enemy.y = enemy.originY + static_cast<float>(
            std::sin(static_cast<double>(frame_) * kBoss09Tau / 127.0) * 10.0);
        if (timer > 9) {
            const int cycle = (timer - 10) % 0x640;
            if (cycle == 0) {
                static constexpr std::array<int, 6> kSourceOffsets{{
                    0, -26768, -6000, 29768, 3000, -32768
                }};
                for (int i = 0; i < 6; ++i) {
                    const int type = (i & 1) == 0 ? 0xd6 : 0xd7;
                    const auto offsetAngle = boss09Angle(i * 0x2aaa);
                    const auto sourceAngle = boss09Angle(
                        i * 0x2aaa +
                        kSourceOffsets[static_cast<std::size_t>(i)]);
                    spawnPolarNode(type, i, offsetAngle, 110.0f,
                                   sourceAngle);
                }
                playPlayerSound(bullet2SoundHandle_, 0x13);
            }
            if (cycle == 0x78) {
                for (int i = 0; i < 6; ++i) {
                    const auto offsetAngle = boss09Angle(
                        i * 0x2aaa + 0x1555);
                    const double radians = boss09Radians(offsetAngle);
                    const float ox = static_cast<float>(std::cos(radians) * 80.0);
                    const float oy = static_cast<float>(std::sin(radians) * 80.0);
                    const auto angle = boss09AngleTo(enemy.x + ox, enemy.y + oy,
                                                     player_.x, player_.y);
                    spawnStage09BossNode(enemy, 0xd8, i, ox, oy,
                                         boss09Angle(angle - 0x8000), 0.0,
                                         30, true);
                }
                playPlayerSound(bullet2SoundHandle_, 0x13);
            }
            const int ceInterval = difficulty == 0 ? 0x3c : 0x28;
            if (cycle >= 0x30c && cycle < 0x370 &&
                (cycle - 0x30c) % ceInterval == 0) {
                const std::uint32_t random = boss09Rand(timer);
                const auto offsetAngle = boss09Angle(
                    static_cast<int>(random % 0x10001u));
                const float distance = 30.0f +
                    static_cast<float>(random % 81u);
                const double radians = boss09Radians(offsetAngle);
                const float ox = static_cast<float>(std::cos(radians) * distance);
                const float oy = static_cast<float>(std::sin(radians) * distance);
                const auto sourceAngle = boss09Angle(
                    boss09AngleTo(enemy.x + ox, enemy.y + oy,
                                  player_.x, player_.y) - 0x8000);
                spawnPolarNode(0xce, cycle, offsetAngle, distance, sourceAngle);
            }
            const std::array<int, 5> d9Interval{{10, 8, 7, 8, 7}};
            if (cycle >= 0x398 && cycle < 0x604 &&
                (cycle - 0x398) %
                    d9Interval[static_cast<std::size_t>(difficulty)] == 0) {
                const std::uint32_t random = boss09Rand(timer);
                const auto offsetAngle = boss09Angle(
                    static_cast<int>(random % 0x10001u));
                const float distance = 30.0f +
                    static_cast<float>(random % 81u);
                const double radians = boss09Radians(offsetAngle);
                const float ox = static_cast<float>(std::cos(radians) * distance);
                const float oy = static_cast<float>(std::sin(radians) * distance);
                const auto sourceAngle = boss09Angle(
                    boss09AngleTo(enemy.x + ox, enemy.y + oy,
                                  player_.x, player_.y) +
                    static_cast<int>(random % 0x4651u) - 9000);
                spawnPolarNode(0xd9, cycle, offsetAngle, distance, sourceAngle);
            }
        }
        break;
    }
    case 10:
        enemy.targetable = false;
        if (timer == 1 || timer == 0x3c || timer == 0x78 ||
            timer == 0xf0) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 0x140) playBoss4();
        if (timer >= 0x21c) {
            if (difficulty < 4) openPhase(0x0b, 200000, 0x1518, 2);
            else openPhase(0x6f, 180000, 0x1518, 2);
        }
        break;
    case 0x3c:
    case 0xa0:
        enemy.targetable = false;
        if (timer == 0) {
            playPlayerSound(bossSe6SoundHandle_, 0x19);
            enemy.sourceSpeed = 0.3;
        }
        if (timer < 50) {
            const double angle = static_cast<double>(timer) * kBoss09Tau / 50.0;
            enemy.x = 360.0f + static_cast<float>(std::cos(angle) * (50 - timer) * 2.0);
            enemy.y = 190.0f + static_cast<float>(std::sin(angle) * (50 - timer) * 2.0);
        }
        else {
            enemy.sourceAngle16 = boss09Approach(enemy.sourceAngle16, aimed(), 0x300);
            const double radians = boss09Radians(enemy.sourceAngle16);
            enemy.x += static_cast<float>(std::cos(radians) * 0.3);
            enemy.y += static_cast<float>(std::sin(radians) * 0.3);
        }
        if (timer >= 0x96) {
            if (state == 0x3c) openPhase(0x3d, 150000, 6000, 3);
            else openPhase(0xa1, 180000, 0x1e00, 3);
        }
        break;
    case 99:
    case 199:
        enemy.targetable = false;
        if (timer < 240 && timer % 3 == 0) {
            spawnStage02DeathExplosionChain(enemy);
        }
        enemy.y += 0.2f;
        if (timer == 240) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnEnemyDeathEffects(enemy, 2);
        }
        if (timer >= 600) {
            clearLateStageGate(9);
            enemy.active = false;
        }
        break;
    default:
        if (boss09NormalMoveState(state)) {
            const auto [targetX, targetY] = boss09NormalMoveTarget(state);
            const int duration = boss09NormalMoveDuration(state);
            if (timer == 0) {
                enemy.originX = enemy.x;
                enemy.originY = enemy.y;
            }
            if (timer == 8) {
                enemy.secondaryAngle16 = boss09AngleTo(
                    enemy.x, enemy.y, targetX, targetY);
                playPlayerSound(bossSe1SoundHandle_, 0x13);
            }
            const double moveT = boss09SineEase(
                static_cast<double>(std::clamp(timer - 8, 0, 8)) / 8.0);
            enemy.x = enemy.originX +
                      (targetX - enemy.originX) * static_cast<float>(moveT);
            enemy.y = enemy.originY +
                      (targetY - enemy.originY) * static_cast<float>(moveT);
            if (timer == 20) {
                static constexpr std::array<int, 5> kCount{{21, 27, 31, 31, 31}};
                static constexpr std::array<double, 5> kSpeed{{6.0, 7.0, 8.0, 8.0, 8.0}};
                const int count = kCount[static_cast<std::size_t>(difficulty)];
                if (difficulty >= 3) {
                    spawnProjectileSpread(
                        5, 0, enemy.x, enemy.y,
                        boss09Angle(0x10000 / (count * 2)), -30.0f,
                        4.0, 1, count, 0x10000, 0);
                }
                spawnProjectileSpread(
                    3, 0, enemy.x, enemy.y, 0, -30.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)], 1,
                    count, 0x10000, 0);
                playPlayerSound(bullet1SoundHandle_, 0x13);
            }
            if (timer >= duration) {
                enemy.helperState += 1;
                enemy.helperTimer = 0;
                enemy.originX = enemy.x;
                enemy.originY = enemy.y;
                enemy.sourceSpeed = 0.5;
            }
        }
        else if (boss09CombatState(state)) {
            if (state == 0x0b) {
                enemy.sourceSpeed = boss09EaseBetween(
                    timer, 0x3c, 0xf0, 0.1, 3.0);
            }
            else if (state == 0x18) {
                enemy.sourceSpeed = boss09EaseBetween(
                    timer, 0, 0x78, 0.5, 3.0);
            }
            else if (state == 0x19) {
                enemy.sourceSpeed = boss09EaseBetween(
                    timer, 0, 0x3c, 3.0, 0.5);
            }
            else if (state == 0x1a) {
                enemy.sourceSpeed = boss09ReverseEaseBetween(
                    timer, 0, 0x47e, 0.5, 3.0);
            }
            else if (state == 0x6f || state == 0x75) {
                enemy.sourceSpeed = boss09EaseBetween(
                    timer, 0x3c, 0x1e0, 0.1, 2.0);
            }
            else if (state == 0x70) {
                enemy.sourceSpeed = boss09ReverseEaseBetween(
                    timer, 0, 0x3c, 2.0, 0.5);
            }
            else if (state == 0x71) {
                enemy.sourceSpeed = boss09EaseBetween(
                    timer, 0, 0xb4, 0.5, 2.4);
            }
            else if (state == 0x74) {
                enemy.sourceSpeed = boss09EaseBetween(
                    timer, 600, 0x47e, 2.4, 0.1);
            }
            else if (state == 0xa1) {
                enemy.sourceSpeed = boss09EaseBetween(
                    timer, 0, 300, 0.3, 2.4);
            }
            if (frame_ % 50 == 0) {
                lateStageBossTargetX_ = 210.0f + static_cast<float>(
                    boss09Rand(frame_) % 301u);
                const float targetYBase =
                    (state == 0x19 || state == 0x70) ? 200.0f : 150.0f;
                lateStageBossTargetY_ = targetYBase + static_cast<float>(
                    boss09Rand(frame_ + selectedStage_ * 999) % 101u);
            }
            const auto target = boss09AngleTo(enemy.x, enemy.y,
                                              lateStageBossTargetX_,
                                              lateStageBossTargetY_);
            enemy.sourceAngle16 = boss09Approach(enemy.sourceAngle16,
                                                 target, 0x300);
            // The original helper snapshots +0x28/+0x2c before applying its
            // polar movement and passes that snapshot to every bullet call.
            emitStage09BossProjectiles(enemy);
            const double radians = boss09Radians(enemy.sourceAngle16);
            enemy.x += static_cast<float>(
                std::cos(radians) * enemy.sourceSpeed);
            enemy.y += static_cast<float>(
                std::sin(radians) * enemy.sourceSpeed);

            int nextState = -1;
            switch (state) {
            case 0x0b:
            case 0x1b: if (timer >= 900) nextState = 0x0c; break;
            case 0x11: if (timer >= 0x8c) nextState = 0x12; break;
            case 0x17: if (timer >= 0x1b8) nextState = 0x18; break;
            case 0x18: if (timer >= 0x15e) nextState = 0x19; break;
            case 0x19: if (timer >= 0x460) nextState = 0x1a; break;
            case 0x1a: if (timer >= 0x47e) nextState = 0x1b; break;
            case 0x6f:
            case 0x75: if (timer >= 900) nextState = 0x70; break;
            case 0x70: if (timer >= 0x244) nextState = 0x71; break;
            case 0x71: if (timer >= 600) nextState = 0x72; break;
            case 0x72: if (timer >= 0x230) nextState = 0x73; break;
            case 0x73: if (timer >= 600) nextState = 0x74; break;
            case 0x74: if (timer >= 0x47e) nextState = 0x75; break;
            default: break;
            }
            if (state == 0x3d && enemy.hp < enemy.maxHp / 2 &&
                timer > 100 && (timer - 100) % 0x168 == 0xaa) {
                // FUN_14004a970 changes only +0x14 here; +0x0c keeps
                // advancing so the 0xdc/0xdd group follows ten frames later.
                enemy.helperState = 0x3e;
            }
            if (nextState >= 0) {
                enemy.helperState = nextState;
                enemy.helperTimer = 0;
                enemy.originX = enemy.x;
                enemy.originY = enemy.y;
            }
        }
        break;
    }

    const int currentState = enemy.helperState;
    const bool trailState = currentState < 0x3c ||
                            (currentState >= 0x6f && currentState < 0xa0);
    const bool trailReady = currentState != 5 &&
                            (currentState != 0 || enemy.helperTimer >= 190);
    if (trailState && trailReady &&
        player_.invulnerableFrames < 61) {
        const int interval = currentState < 5 ? 50 : 25;
        if (enemy.helperTimer >= 0 && enemy.helperTimer % interval == 0) {
            const std::uint32_t random = boss09Rand(frame_);
            const int distance = 150 + static_cast<int>(random % 0x83u);
            const auto offsetAngle = boss09Angle(
                static_cast<int>(random % 0x8001u) - 0x8000);
            const double radians = boss09Radians(offsetAngle);
            const float spawnX = enemy.x + static_cast<float>(
                std::cos(radians) * distance);
            const float spawnY = enemy.y + 70.0f + static_cast<float>(
                std::sin(radians) * distance);
            const auto angle = boss09Angle(
                static_cast<int>(random % 0x10001u));
            spawnStage09BossNode(enemy, 0xcd, enemy.helperTimer,
                                 spawnX, spawnY,
                                 angle, 0.2, 40, false);
        }
    }

    enemy.drawHp = enemy.hp;
    lateStageBossCountdownDraw_ = lateStageBossCountdown_;
    if (lateStageBossPhaseMode_ == 1 &&
        boss09CombatState(enemy.helperState)) {
        updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
        if (lateStageBossCountdown_ > 0) --lateStageBossCountdown_;
    }
}

void StageRuntime::emitStage09BossProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int state = enemy.helperState;
    const int timer = enemy.helperTimer;
    const float fireY = enemy.y + 5.0f;
    const auto aimed = boss09AngleTo(enemy.x, fireY, player_.x, player_.y);
    bool fired = false;
    bool firedBullet2 = false;

    if (state == 0x0b || state == 0x1b) {
        static constexpr std::array<int, 5> kRingInterval{{19, 15, 13, 11, 11}};
        static constexpr std::array<int, 5> kFanInterval{{11, 9, 9, 7, 7}};
        static constexpr std::array<int, 5> kWaveUnit{{18, 12, 10, 10, 10}};
        static constexpr std::array<int, 5> kRingCount{{7, 9, 9, 9, 9}};
        static constexpr std::array<int, 5> kFanCount{{5, 5, 6, 7, 7}};
        static constexpr std::array<int, 5> kWaveCount{{5, 7, 7, 7, 7}};
        static constexpr std::array<double, 5> kBaseSpeed{{5.0, 5.5, 6.0, 6.0, 6.0}};
        const std::size_t index = static_cast<std::size_t>(difficulty);
        const double speed = kBaseSpeed[index] +
                             static_cast<double>(timer - 70) * 0.004;

        if (boss09Periodic(timer, 70, 860, kRingInterval[index])) {
            const int spread = 20000 + static_cast<int>(
                std::sin(static_cast<double>(timer) * kBoss09Tau / 77.0) *
                3000.0);
            const auto angle = boss09Angle(timer * 0x115);
            spawnProjectileSpread(0x0c, 0, enemy.x, fireY, angle,
                                  0.0f, speed, 1,
                                  kRingCount[index], spread, 0);
            spawnProjectileSpread(0x0c, 0, enemy.x, fireY,
                                  boss09Angle(angle + 0x8000),
                                  0.0f, speed, 1,
                                  kRingCount[index], spread, 0);
            fired = true;
        }
        if (boss09Periodic(timer, 190, 860, kFanInterval[index])) {
            spawnProjectileSpread(3, 0, enemy.x, fireY,
                                  boss09Angle(timer * 0xfe65),
                                  10.0f, speed + 1.0, 1,
                                  kFanCount[index], 0x10000, 0);
            fired = true;
        }

        const int unit = kWaveUnit[index];
        const int period = unit * 6;
        if (boss09Periodic(timer, 330, 860, period)) {
            enemy.secondaryAngle16 = aimed;
        }
        if (boss09BurstPeriodic(timer, 330, 860, period,
                                unit * 4, unit * 2)) {
            spawnProjectileSpread(9, 0, enemy.x, fireY,
                                  enemy.secondaryAngle16, 10.0f,
                                  speed + 0.5, 1,
                                  kWaveCount[index], 24000, 0);
            fired = true;
        }
        if (boss09BurstPeriodic(timer, 330 + unit, 860, period,
                                unit * 4, unit * 2)) {
            const int count = kWaveCount[index] - 1;
            const int spread = 24000 / (count + 1) * count;
            spawnProjectileSpread(9, 0, enemy.x, fireY,
                                  enemy.secondaryAngle16, 10.0f,
                                  speed + 0.5, 1,
                                  count, spread, 0);
            fired = true;
        }
    }
    else if (state == 0x11) {
        if (timer == 0x1e) {
            const int count = std::array<int, 5>{{9, 11, 13, 15, 15}}[
                static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(3, 0x2b, enemy.x, fireY, aimed,
                                  10.0f, 8.0, 1, count, 0x10000, 0);
            spawnProjectileSpread(
                3, 0x2b, enemy.x, fireY,
                boss09Angle(aimed + 0x10000 / (count * 2)),
                10.0f, 10.0, 1, count, 0x10000, 0);
            fired = true;
        }
    }
    else if (state == 0x17) {
        static constexpr std::array<int, 5> kInterval{{15, 12, 9, 7, 7}};
        static constexpr std::array<int, 5> kInitialCount{{9, 13, 13, 13, 13}};
        static constexpr std::array<int, 5> kBurstInterval{{24, 18, 16, 14, 14}};
        static constexpr std::array<int, 5> kBurstCount{{18, 20, 22, 22, 22}};
        static constexpr std::array<double, 5> kSpeed{{5.5, 6.0, 6.5, 7.0, 7.0}};
        const std::size_t index = static_cast<std::size_t>(difficulty);
        const int interval = kInterval[index];
        const int count = kInitialCount[index] +
                          (timer - 0x32) / (interval * 2);
        const double speed = kSpeed[index] +
                             static_cast<double>(timer - 0x32) * 0.04;
        if (boss09Periodic(timer, 0x32, 0xe6, interval * 2)) {
            enemy.secondaryAngle16 = aimed;
            spawnProjectileSpread(0x0c, 0, enemy.x, fireY,
                                  enemy.secondaryAngle16, 0.0f,
                                  speed, 1, count, 0x10000, 0);
            firedBullet2 = true;
        }
        if (boss09Periodic(timer, 0x32 + interval, 0xe6,
                           interval * 2)) {
            spawnProjectileSpread(
                0x0d, 0, enemy.x, fireY,
                boss09Angle(enemy.secondaryAngle16 +
                            0x10000 / (count * 2)),
                0.0f, speed, 1, count, 0x10000, 0);
            firedBullet2 = true;
        }
        if (timer == 0xf0) enemy.secondaryAngle16 = aimed;
        const int burstInterval = kBurstInterval[index];
        const int burstCount = kBurstCount[index];
        const double burstSpeed = kSpeed[index] + 5.0;
        if (boss09Periodic(timer, 0xf0, 0x1a4, burstInterval * 2)) {
            for (int offset : {-500, 0, 500}) {
                spawnProjectileSpread(
                    5, 0, enemy.x, fireY,
                    boss09Angle(enemy.secondaryAngle16 + offset),
                    0.0f, burstSpeed, 1, burstCount, 0x10000, 0);
            }
            fired = true;
        }
        if (boss09Periodic(timer, 0xf0 + burstInterval, 0x1a4,
                           burstInterval * 2)) {
            const int halfStep = 0x10000 / (burstCount * 2);
            for (int offset : {-500, 0, 500}) {
                spawnProjectileSpread(
                    4, 0, enemy.x, fireY,
                    boss09Angle(enemy.secondaryAngle16 + halfStep + offset),
                    0.0f, burstSpeed, 1, burstCount, 0x10000, 0);
            }
            fired = true;
        }
    }
    else if (state == 0x18) {
        static constexpr std::array<int, 5> kCount{{3, 5, 6, 7, 7}};
        static constexpr std::array<int, 5> kAngleStep{{0x457, 0x320, 0x294, 0x302, 0x302}};
        static constexpr std::array<double, 5> kSpeed{{6.0, 7.0, 7.5, 7.5, 7.5}};
        const std::size_t index = static_cast<std::size_t>(difficulty);
        const int interval = timer < 0xdc ? 0x32 : 0x1e;
        if (boss09Periodic(timer, 0x14, 0xdc, interval) ||
            boss09Periodic(timer, 0xdc, 0x154, interval)) {
            enemy.secondaryAngle16 = aimed;
        }
        const bool positiveBurst =
            boss09BurstPeriodic(timer, 0x14, 0xdc, interval * 2, 0x28, 3) ||
            boss09BurstPeriodic(timer, 0xdc, 0x154, interval * 2, 0x19, 3);
        if (positiveBurst) {
            spawnProjectileSpread(
                2, 0x2c, enemy.x, fireY,
                boss09Angle(enemy.secondaryAngle16 + timer * kAngleStep[index]),
                0.0f, kSpeed[index], 1, kCount[index], 0x10000, 0);
            firedBullet2 = true;
        }
        const bool negativeBurst =
            boss09BurstPeriodic(timer, 0x14 + interval, 0xdc,
                                interval * 2, 0x28, 3) ||
            boss09BurstPeriodic(timer, 0xdc + interval, 0x154,
                                interval * 2, 0x19, 3);
        if (negativeBurst) {
            spawnProjectileSpread(
                3, 0x2d, enemy.x, fireY,
                boss09Angle(enemy.secondaryAngle16 - timer * kAngleStep[index]),
                0.0f, kSpeed[index], 1, kCount[index], 0x10000, 0);
            firedBullet2 = true;
        }
    }
    else if (state == 0x19) {
        static constexpr std::array<int, 5> kInterval{{8, 7, 7, 6, 6}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        if (timer == 0x1e) {
            enemy.secondaryAngle16 = boss09AngleTo(
                enemy.x, fireY, 128.0f, 0.0f);
        }
        if (boss09Periodic(timer, 0x1e, 0x2d0, interval)) {
            spawnProjectileSpread(4, 0x2e, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  0.0f, 6.0, 1, 1, 0, 0);
            fired = true;
        }
        if (boss09Periodic(timer, 0x334, 900, 10)) {
            spawnProjectileSpread(4, 0x2e, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  0.0f, 6.0, 1, 3, 0x10000, 0);
            fired = true;
        }
        enemy.secondaryAngle16 = boss09Angle(
            enemy.secondaryAngle16 + (timer < 800 ? 0xe6 : 0x6f1));
    }
    else if (state == 0x1a) {
        static constexpr std::array<int, 5> kInterval{{10, 8, 8, 7, 7}};
        static constexpr std::array<int, 5> kCount{{6, 10, 12, 12, 12}};
        static constexpr std::array<double, 5> kSpeed{{6.4, 7.0, 7.5, 8.0, 8.0}};
        const std::size_t index = static_cast<std::size_t>(difficulty);
        const int interval = kInterval[index];
        const int count = kCount[index];
        if (timer == 1) {
            enemy.secondaryAngle16 = aimed;
            enemy.targetAngle16 = aimed;
        }
        if (boss09Periodic(timer, 1, 0x96, interval)) {
            const int targetSpread = 0x10000 / count;
            const int spread = static_cast<int>(
                65535.0 + (static_cast<double>(targetSpread) - 65535.0) *
                              boss09SineEase(static_cast<double>(timer) / 150.0));
            spawnProjectileSpread(4, 0, enemy.x, fireY,
                                  enemy.secondaryAngle16, 0.0f,
                                  kSpeed[index], 1, 2, spread, 0);
            spawnProjectileSpread(1, 0, enemy.x, fireY,
                                  enemy.targetAngle16, 0.0f,
                                  kSpeed[index] - 1.5, 1, 2, spread, 0);
            fired = true;
        }
        if (boss09Periodic(timer, 0x96, 0x460, interval)) {
            const int halfStep = 0x10000 / (count * 2);
            spawnProjectileSpread(
                4, 0, enemy.x, fireY,
                boss09Angle(enemy.secondaryAngle16 + halfStep),
                0.0f, kSpeed[index], 1, count, 0x10000, 0);
            spawnProjectileSpread(
                1, 0, enemy.x, fireY,
                boss09Angle(enemy.targetAngle16 + halfStep),
                0.0f, kSpeed[index] - 1.5, 1, count, 0x10000, 0);
            fired = true;
        }
        if (timer < 0x96) {
            const int turn = static_cast<int>(
                0x500 + (0x40 - 0x500) *
                            boss09SineEase(static_cast<double>(timer) / 150.0));
            enemy.secondaryAngle16 = boss09Approach(
                enemy.secondaryAngle16, aimed, turn);
            enemy.targetAngle16 = boss09Approach(
                enemy.targetAngle16, aimed, turn);
        }
        else {
            if (timer >= 0xb4) {
                enemy.secondaryAngle16 = boss09Angle(
                    enemy.secondaryAngle16 + (timer - 0xb4) / 2);
            }
            if (timer >= 0xdc) {
                enemy.targetAngle16 = boss09Angle(
                    enemy.targetAngle16 - (timer - 0xdc) / 2);
            }
        }
    }
    else if (state == 0x6f || state == 0x75) {
        enemy.secondaryAngle16 = boss09Angle(
            0x4000 + static_cast<int>(
                std::sin((static_cast<double>(timer) + 69.0) *
                         kBoss09Tau / 555.0) * 65536.0));
        enemy.targetAngle16 = boss09Angle(
            -0x8000 + static_cast<int>(
                std::sin((static_cast<double>(timer) - 189.0) *
                         kBoss09Tau / 666.0) * 65536.0));
        const double speed = 9.9 +
                             static_cast<double>(timer - 70) * 0.001;
        if (boss09BurstPeriodic(timer, 70, 310, 40, 20, 4)) {
            spawnProjectileSpread(0x0d, 0, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  0.0f, speed, 1, 11, 0x10000, 0);
            fired = true;
        }
        if (boss09BurstPeriodic(timer, 90, 310, 40, 20, 4)) {
            spawnProjectileSpread(0x0c, 0, enemy.x, fireY,
                                  enemy.targetAngle16,
                                  0.0f, speed, 1, 11, 0x10000, 0);
            fired = true;
        }
        if (boss09Periodic(timer, 310, 720, 8)) {
            spawnProjectileSpread(0x0d, 0, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  0.0f, speed, 1, 22, 0x10000, 0);
            fired = true;
        }
        if (boss09Periodic(timer, 314, 720, 8)) {
            spawnProjectileSpread(0x0c, 0, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  0.0f, speed, 1, 22, 0x10000, 0);
            fired = true;
        }
        if (timer == 720) {
            spawnProjectileSpread(2, 0x2f, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  0.0f, 10.0, 1, 22, 0x10000, 0);
            firedBullet2 = true;
        }
        if (timer == 800) {
            spawnProjectileSpread(3, 0x30, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  0.0f, 10.0, 1, 22, 0x10000, 0);
            firedBullet2 = true;
        }
    }
    else if (state == 0x70) {
        if (timer == 0x14) enemy.secondaryAngle16 = aimed;
        if (boss09Periodic(timer, 0x14, 500, 2)) {
            spawnProjectileSpread(0x0b, 0x31, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  10.0f, 7.7, 1, 1, 0, 0);
            fired = true;
        }
        enemy.secondaryAngle16 = boss09Angle(
            enemy.secondaryAngle16 + (timer < 0x10e ? 0x280 : -0x280));
    }
    else if (state == 0x71) {
        if (timer == 0x14) {
            enemy.secondaryAngle16 = boss09Angle(aimed - 0x4000);
        }
        if (boss09Periodic(timer, 0x14, 0x21c, 6)) {
            spawnProjectileSpread(2, 0x32, enemy.x, fireY,
                                  enemy.secondaryAngle16,
                                  10.0f, 13.0, 1, 1, 0, 0);
            fired = true;
        }
        if (timer == 0x99) {
            enemy.targetAngle16 = boss09Angle(aimed + 0x4000);
        }
        if (boss09Periodic(timer, 0x99, 0x21c, 6)) {
            spawnProjectileSpread(3, 0x32, enemy.x, fireY,
                                  enemy.targetAngle16,
                                  10.0f, 13.0, 1, 1, 0, 0);
            fired = true;
        }
        enemy.secondaryAngle16 = boss09Angle(
            enemy.secondaryAngle16 + 0x29a);
        enemy.targetAngle16 = boss09Angle(
            enemy.targetAngle16 - 0x29a);
    }
    else if (state == 0x72) {
        const int interval = timer < 0xbe ? 0x20 : 0x10;
        if (boss09Periodic(timer, 10, 500, interval)) {
            const auto angle = boss09Angle(static_cast<int>(
                boss09Rand(timer) % 0x10001u));
            spawnProjectileSpread(3, 0x2c, enemy.x, fireY, angle,
                                  0.0f, 6.0, 1, 21, 0x10000, 0);
            spawnProjectileSpread(2, 0x2d, enemy.x, fireY, angle,
                                  0.0f, 6.0, 1, 21, 0x10000, 0);
            fired = true;
        }
    }
    else if (state == 0x73) {
        const double speed = 9.6 + static_cast<double>(timer) * 0.01;
        if (boss09Periodic(timer, 10, 0x226, 0x1e)) {
            enemy.secondaryAngle16 = aimed;
        }
        const int phase = (timer - 10) % 0x1e;
        const int angleOffset = phase * 0x3c;
        if (boss09BurstPeriodic(timer, 10, 0x226, 0x3c, 0x18, 3)) {
            spawnProjectileSpread(
                0x0b, 0, enemy.x, fireY,
                boss09Angle(enemy.secondaryAngle16 + angleOffset),
                0.0f, speed, 1, 6, 0x8000, 0);
            spawnProjectileSpread(
                0x0b, 0, enemy.x, fireY,
                boss09Angle(enemy.secondaryAngle16 - angleOffset),
                0.0f, speed, 1, 6, 0x8000, 0);
            fired = true;
        }
        if (boss09BurstPeriodic(timer, 0x28, 0x226,
                                0x3c, 0x18, 3)) {
            constexpr int kInsetSpread = (0x8000 / 5) * 4;
            spawnProjectileSpread(
                0x0b, 0, enemy.x, fireY,
                boss09Angle(enemy.secondaryAngle16 + angleOffset),
                0.0f, speed, 1, 5, kInsetSpread, 0);
            spawnProjectileSpread(
                0x0b, 0, enemy.x, fireY,
                boss09Angle(enemy.secondaryAngle16 - angleOffset),
                0.0f, speed, 1, 5, kInsetSpread, 0);
            fired = true;
        }
        if (boss09Periodic(timer, 0x46, 0x226, 0x3c)) {
            spawnProjectileSpread(
                0x0c, 0x33, enemy.x, fireY,
                boss09Angle(aimed - 0x8000),
                0.0f, 6.4, 1, 13, 20000, 0);
            fired = true;
        }
        if (boss09Periodic(timer, 0x82, 0x226, 0x1e)) {
            spawnProjectileSpread(5, 0, enemy.x, fireY, aimed,
                                  0.0f, 5.5, 1, 17, 30000, 0);
            spawnProjectileSpread(5, 0, enemy.x, fireY, aimed,
                                  0.0f, 8.5, 1, 17, 30000, 0);
            firedBullet2 = true;
        }
    }
    else if (state == 0x74) {
        if (timer == 10) enemy.secondaryAngle16 = 0;
        if (boss09Periodic(timer, 10, 0x460, 2)) {
            const int count = timer < 180 ? 3 : (timer < 360 ? 4 :
                              (timer < 600 ? 5 : (timer < 840 ? 6 : 7)));
            const double baseSpeed = 3.0 +
                                     static_cast<double>(timer) * 0.0015;
            for (int i = 0; i < count; ++i) {
                const double speed = baseSpeed + i * 2.0;
                spawnProjectileSpread(
                    5, 0, enemy.x, fireY,
                    boss09Angle(enemy.secondaryAngle16 - i * 0xc8d - 0x4000),
                    0.0f, speed, 1, 1, 0, 0);
                spawnProjectileSpread(
                    4, 0, enemy.x, fireY,
                    boss09Angle(i * 0xc8d - enemy.secondaryAngle16 - 0x4000),
                    0.0f, speed, 1, 1, 0, 0);
            }
            fired = true;
        }
        enemy.secondaryAngle16 = boss09Angle(
            enemy.secondaryAngle16 + timer + 999);
    }
    else if (state == 0x3d || state == 0x3e) {
        if (timer >= 100) {
            const int cycle = (timer - 100) % 0x168;
            const auto spawnOrbitGroup = [&](int clockwiseType,
                                             int counterclockwiseType) {
                const std::uint32_t random = boss09Rand(timer);
                const int type = (random & 1u) == 0
                                     ? clockwiseType
                                     : counterclockwiseType;
                const double angularSpeed =
                    type == clockwiseType ? 200.0 : -200.0;
                const int radius = 150 + static_cast<int>(random % 31u);
                for (int i = 0; i < 4; ++i) {
                    spawnStage09BossNode(
                        enemy, type, i, 0.0f, 0.0f,
                        boss09Angle(i * 0x4000), angularSpeed,
                        radius, true);
                }
                playPlayerSound(bullet2SoundHandle_, 0x13);
            };
            if (cycle == 0) {
                spawnOrbitGroup(0xda, 0xdb);
            }
            if (state == 0x3e && cycle == 0xb4) {
                spawnOrbitGroup(0xdc, 0xdd);
            }

            if (state == 0x3d && timer >= 0x154) {
                static constexpr std::array<int, 5> kInterval{{16, 10, 8, 6, 6}};
                static constexpr std::array<double, 5> kSpeed{{5.5, 5.5, 6.5, 7.0, 7.0}};
                static constexpr std::array<int, 5> kCount{{30, 30, 32, 32, 32}};
                const int shotCycle = (timer - 0x154) % 0x168;
                const int interval = kInterval[static_cast<std::size_t>(difficulty)];
                if (shotCycle == 0x1e) {
                    enemy.secondaryAngle16 = aimed;
                }
                if (shotCycle >= 0x1e && shotCycle < 0x82 &&
                    (shotCycle - 0x1e) % interval == 0) {
                    const int halfRange = (shotCycle - 0x1e) * 10;
                    int randomOffset = 0;
                    if (halfRange > 0) {
                        randomOffset = static_cast<int>(
                            boss09Rand(timer) %
                            static_cast<std::uint32_t>(halfRange * 2 + 1)) -
                            halfRange;
                    }
                    spawnProjectileSpread(
                        2, 1, enemy.x, fireY,
                        boss09Angle(enemy.secondaryAngle16 + randomOffset),
                        0.0f, kSpeed[static_cast<std::size_t>(difficulty)],
                        1, kCount[static_cast<std::size_t>(difficulty)],
                        0x10000, 0);
                    fired = true;
                }
            }
        }
    }
    else if (state == 0xa1 && timer >= 100) {
        const int cycle = (timer - 100) % 600;
        const auto spawnOrbitGroup = [&](int clockwiseType,
                                         int counterclockwiseType) {
            const int type = (boss09Rand(frame_) & 1u) == 0
                                 ? clockwiseType
                                 : counterclockwiseType;
            const double angularSpeed =
                type == clockwiseType ? 200.0 : -200.0;
            const int radius = 150 + static_cast<int>(boss09Rand(timer) % 31u);
            for (int i = 0; i < 7; ++i) {
                spawnStage09BossNode(
                    enemy, type, i, 0.0f, 0.0f,
                    boss09Angle(i * 0x2492), angularSpeed,
                    radius, true);
            }
            playPlayerSound(bullet2SoundHandle_, 0x13);
        };
        if (cycle == 0 || cycle == 300) {
            spawnOrbitGroup(0xda, 0xdb);
        }
        if (cycle == 0x96) {
            spawnOrbitGroup(0xdc, 0xdd);
        }

        if (timer >= 300) {
            const int shotCycle = (timer - 600) % 600;
            if (shotCycle == 0x1e) {
                enemy.secondaryAngle16 = aimed;
            }
            if (shotCycle >= 0x1e && shotCycle < 0x96 &&
                (shotCycle - 0x1e) % 8 == 0) {
                const int halfRange = shotCycle * 0x1b;
                int randomOffset = 0;
                if (halfRange > 0) {
                    randomOffset = static_cast<int>(
                        boss09Rand(timer) %
                        static_cast<std::uint32_t>(halfRange * 2 + 1)) -
                        halfRange;
                }
                spawnProjectileSpread(
                    4, 1, enemy.x, fireY,
                    boss09Angle(enemy.secondaryAngle16 + randomOffset),
                    0.0f, 8.8, 1, 40, 0x10000, 0);
                fired = true;
            }
        }
    }

    if (fired) playPlayerSound(bullet1SoundHandle_, 0x13);
    if (firedBullet2) playPlayerSound(bullet2SoundHandle_, 0x13);
}

void StageRuntime::updateStage09BossNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.targetable = false;

    StageEnemy* root = findEnemyById(enemy.parentEntityId);
    if (root == nullptr || root->spawnType != 0x140 || !root->active) {
        enemy.active = false;
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    const auto aimed = [&]() {
        return boss09AngleTo(enemy.x, enemy.y, player_.x, player_.y);
    };

    if (enemy.spawnType == 0xc3) {
        enemy.x = root->x;
        enemy.y = root->y;
        enemy.sourceAngle16 = boss09Angle(frame_ * 0x400);
        if (enemy.helperState == 0 && timer == 0) {
            const auto randomHundredth = [](int seed, double minimum,
                                            int steps) {
                return minimum +
                       static_cast<double>(boss09Rand(seed) %
                                           static_cast<std::uint32_t>(steps)) /
                           100.0;
            };
            const int particle = playerFrames_.size() > 14
                                     ? playerFrames_[14]
                                     : -1;
            for (int index = 0; index < 32; ++index) {
                const auto angle = boss09Angle(static_cast<int>(
                    boss09Rand(frame_ + index * 0x58) % 0x10001u));
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
        if (player_.invulnerableFrames < 61 ||
            lateStageBossPhaseMode_ != 1) {
            if (enemy.helperState == 0) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
            }
            else if (timer >= 16) {
                enemy.active = false;
            }
        }
        return;
    }

    if (enemy.spawnType == 0xcd) {
        const bool shieldAlive = std::any_of(
            enemies_.begin(), enemies_.end(), [root](const StageEnemy& node) {
                return node.active && node.spawnType == 0xc3 &&
                       node.parentEntityId == root->entityId &&
                       node.parentSpawnType == 0x140;
            });
        if (shieldAlive && enemy.helperTimer < 0xa4) {
            // FUN_140051030 observes the root's +0x54 shield flag and jumps
            // directly to the beginning of its 16-frame fade window.
            enemy.helperTimer = 0xa4;
        }
        const double radians = boss09Radians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
        if (timer >= 0xb4) enemy.active = false;
        return;
    }

    if (enemy.spawnType >= 0xda && enemy.spawnType <= 0xdd) {
        if (!root->targetable || lateStageBossPhaseMode_ != 1 ||
            root->hp < 1 || lateStageBossCountdown_ < 1) {
            enemy.active = false;
            return;
        }

        const int type = enemy.spawnType;
        const int angularVelocity = static_cast<int>(enemy.sourceSpeed);
        enemy.sourceAngle16 = boss09Angle(
            static_cast<int>(enemy.sourceAngle16) + angularVelocity);

        const double radiusPhase = std::clamp(
            static_cast<double>(timer) / 300.0, 0.0, 1.0);
        const double orbitRadius =
            static_cast<double>(enemy.radius) *
            std::sin(radiusPhase * kBoss09Pi);
        const double orbitRadians = boss09Radians(enemy.sourceAngle16);
        enemy.x = root->x + static_cast<float>(
            std::cos(orbitRadians) * orbitRadius);
        enemy.y = root->y + static_cast<float>(
            std::sin(orbitRadians) * orbitRadius);

        static constexpr std::array<int, 5> kInterval{{6, 5, 4, 3, 3}};
        static constexpr std::array<int, 5> kTurn{{200, 230, 270, 340, 470}};
        static constexpr std::array<double, 5> kBaseSpeed{{5.0, 5.5, 6.5, 7.0, 7.0}};
        if (timer == 0x1e) {
            const std::uint32_t random = boss09Rand(root->helperTimer);
            enemy.secondaryAngle16 = boss09Angle(
                static_cast<int>(enemy.sourceAngle16) -
                static_cast<int>(random / 0x10001u) +
                static_cast<int>(static_cast<std::uint16_t>(random)));
        }

        bool fired = false;
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        if (timer >= 0x1e && timer < 0x10e &&
            (timer - 0x1e) % interval == 0) {
            const double speed =
                kBaseSpeed[static_cast<std::size_t>(difficulty)] +
                static_cast<double>(timer - 0x1e) *
                    (difficulty == 4 ? 0.02 : 0.012);
            if (difficulty < 4) {
                const int selector = type < 0xdc ? 3 : 2;
                spawnProjectileSpread(
                    selector, 0, enemy.x, enemy.y,
                    enemy.secondaryAngle16, 0.0f, speed, 1,
                    2, 0x10000, 0);
            }
            else {
                const int selector = type < 0xdc ? 0x0d : 0x0c;
                const int projectileId = (type == 0xda || type == 0xdc)
                                             ? 0x2c
                                             : 0x2d;
                spawnProjectileSpread(
                    selector, projectileId, enemy.x, enemy.y,
                    enemy.secondaryAngle16, 0.0f, speed, 1,
                    1, 0, 0);
            }
            fired = true;
        }

        const int turn = kTurn[static_cast<std::size_t>(difficulty)];
        enemy.secondaryAngle16 = boss09Angle(
            static_cast<int>(enemy.secondaryAngle16) + angularVelocity +
            ((type == 0xda || type == 0xdc) ? turn : -turn));
        if (fired) playPlayerSound(bullet1SoundHandle_, 0x13);
        if (timer >= 300) enemy.active = false;
        return;
    }

    if (enemy.sourceDispatchField != 0) {
        enemy.x = root->x + enemy.originX;
        enemy.y = root->y + enemy.originY;
    }

    if (enemy.helperState == 0) {
        const int type = enemy.spawnType;
        const bool aimsDuringEntry = type == 0xce || type == 0xd3 ||
                                     type == 0xd4 || type == 0xd5 ||
                                     type == 0xd8;
        if (aimsDuringEntry) {
            const auto target = aimed();
            int delta = static_cast<int>(target) -
                        static_cast<int>(enemy.sourceAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            enemy.sourceAngle16 = boss09Approach(
                enemy.sourceAngle16, target, std::abs(delta) / 5 + 0x40);
        }
        else {
            const int entryRotation = timer < 0x14
                ? static_cast<int>(std::sin(
                      static_cast<double>(timer) * kBoss09Pi / 40.0) *
                  65536.0)
                : 0;
            enemy.sourceAngle16 = boss09Angle(
                static_cast<int>(enemy.secondaryAngle16) + entryRotation);
        }
        if (timer >= 0x14) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        return;
    }
    if (enemy.helperState == 2) {
        if (timer >= 0x14) enemy.active = false;
        return;
    }
    if (!root->targetable || lateStageBossPhaseMode_ != 1 || root->hp < 1 ||
        lateStageBossCountdown_ < 1) {
        enemy.helperState = 2;
        enemy.helperTimer = 0;
        return;
    }

    const int type = enemy.spawnType;
    int lifetime = 0x32;
    if (type == 0xd9) lifetime = 0x24;
    else if (type == 0xcf || type == 0xd0) lifetime = 0xf0;
    else if (type == 0xd1 || type == 0xd2) lifetime = 0x5a;
    else if (type == 0xd3) lifetime = 0x14a;
    else if (type == 0xd4 || type == 0xd5) lifetime = 0x140;
    else if (type == 0xd6 || type == 0xd7) lifetime = 0x2d0;
    else if (type == 0xd8) lifetime = 600;

    enemy.targetAngle16 = aimed();
    const auto muzzleAngle = enemy.sourceAngle16;
    const double muzzleRadians = boss09Radians(muzzleAngle);
    const float shotX = enemy.x +
        static_cast<float>(std::cos(muzzleRadians) * 10.0);
    const float shotY = enemy.y +
        static_cast<float>(std::sin(muzzleRadians) * 10.0);

    bool fired = false;
    if (type == 0xce || type == 0xd9) {
        static constexpr std::array<double, 5> kSpeed{{6.0, 7.0, 8.0, 9.0, 11.0}};
        const int end = type == 0xce ? 0x32 : 0x24;
        if (timer >= 10 && timer < end && (timer - 10) % 4 == 0) {
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)] +
                                 static_cast<double>(timer) * 0.1;
            spawnProjectileSpread(10, 0, shotX, shotY,
                                  enemy.sourceAngle16, 10.0f, speed, 1,
                                  1, 0, 0);
            spawnProjectileSpread(10, 0, shotX, shotY,
                                  enemy.sourceAngle16, 10.0f,
                                  speed - 0.5, 1, 2, 0x4b0, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(10, 0, shotX, shotY,
                                      enemy.sourceAngle16, 10.0f,
                                      speed - 1.2, 1, 2, 2000, 0);
            }
            if (type == 0xd9) {
                spawnProjectileSpread(
                    11, 0, shotX, shotY,
                    boss09Angle(enemy.sourceAngle16 + 0x8000),
                    10.0f, speed, 1, 2, 0x5555, 0);
            }
            fired = true;
        }
    }
    else if (type == 0xcf || type == 0xd0) {
        static constexpr std::array<int, 5> kInterval{{11, 7, 6, 7, 6}};
        static constexpr std::array<int, 5> kCount{{1, 1, 1, 2, 2}};
        static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 6.5, 7.0, 8.5}};
        const std::size_t index = static_cast<std::size_t>(difficulty);
        if (timer >= 10 && timer < 0xf0 &&
            (timer - 10) % kInterval[index] == 0) {
            spawnProjectileSpread(0x0d, 0, shotX, shotY,
                                  enemy.sourceAngle16, 10.0f,
                                  kSpeed[index], 1, kCount[index],
                                  0x8ae, 0);
            fired = true;
        }
        enemy.sourceAngle16 = boss09Angle(
            static_cast<int>(enemy.sourceAngle16) +
            (type == 0xcf ? 0xde : -0xde));
    }
    else if (type == 0xd1 || type == 0xd2) {
        static constexpr std::array<int, 5> kTurn{{100, 110, 120, 128, 128}};
        if (timer >= 10 && timer < 0x5a && (timer - 10) % 5 == 0) {
            const auto center = boss09Angle(
                static_cast<int>(enemy.sourceAngle16) +
                (player_.y <= enemy.y ? 0x8000 : 0));
            spawnProjectileSpread(3, 0, shotX, shotY, center,
                                  10.0f, 6.0 + timer * 0.02, 1,
                                  2, 0x2000, 0);
            fired = true;
        }
        enemy.sourceAngle16 = boss09Angle(
            static_cast<int>(enemy.sourceAngle16) +
            (type == 0xd1
                 ? kTurn[static_cast<std::size_t>(difficulty)]
                 : -kTurn[static_cast<std::size_t>(difficulty)]));
    }
    else if (type == 0xd3) {
        static constexpr std::array<int, 5> kInterval{{40, 30, 24, 24, 20}};
        static constexpr std::array<int, 5> kCount{{5, 7, 9, 7, 9}};
        static constexpr std::array<double, 5> kBaseSpeed{{5.0, 5.5, 6.0, 6.0, 7.0}};
        const auto target = aimed();
        int delta = static_cast<int>(target) -
                    static_cast<int>(enemy.secondaryAngle16);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        enemy.secondaryAngle16 = boss09Approach(
            enemy.secondaryAngle16, target, std::abs(delta) / 20 + 0x30);
        enemy.sourceAngle16 = boss09Angle(
            static_cast<int>(enemy.secondaryAngle16) +
            static_cast<int>(std::sin(
                static_cast<double>(timer) * kBoss09Tau / 71.0) * 1234.0));

        const std::size_t index = static_cast<std::size_t>(difficulty);
        if (timer >= 10 && timer < 0x14a &&
            (timer - 10) % kInterval[index] == 0) {
            const double speed = kBaseSpeed[index] - timer * 0.008;
            spawnProjectileSpread(8, 0, shotX, shotY,
                                  enemy.sourceAngle16, 10.0f, speed, 1,
                                  kCount[index], 12000, 0);
            if (difficulty > 2) {
                const int insetCount = kCount[index] - 1;
                const int insetSpread =
                    (12000 / insetCount) * (insetCount - 1);
                spawnProjectileSpread(8, 0, shotX, shotY,
                                      enemy.sourceAngle16, 10.0f,
                                      speed + 1.0, 1, insetCount,
                                      insetSpread, 0);
            }
            fired = true;
        }
    }
    else if (type == 0xd4 || type == 0xd5) {
        static constexpr std::array<int, 5> kGrowthInterval{{32, 24, 20, 16, 16}};
        static constexpr std::array<int, 5> kBaseCount{{9, 13, 15, 15, 17}};
        static constexpr std::array<double, 5> kBaseSpeed{{4.0, 4.5, 5.0, 5.0, 6.4}};
        enemy.sourceAngle16 = boss09Approach(
            enemy.sourceAngle16, aimed(), 0x18);
        const std::size_t index = static_cast<std::size_t>(difficulty);
        if (timer >= 10 && timer < 0x140 && (timer - 10) % 4 == 0) {
            const int count = kBaseCount[index] +
                              (timer - 10) / kGrowthInterval[index];
            spawnProjectileSpread(type == 0xd4 ? 0x0d : 0x0c, 0,
                                  shotX, shotY, enemy.sourceAngle16,
                                  10.0f, kBaseSpeed[index] + timer * 0.01,
                                  1, count, 0x10000, 0);
            fired = true;
        }
    }
    else if (type == 0xd6 || type == 0xd7) {
        static constexpr std::array<int, 5> kInterval{{14, 10, 8, 8, 7}};
        static constexpr std::array<int, 5> kCount{{2, 3, 3, 4, 5}};
        static constexpr std::array<int, 5> kTurn{{120, 160, 200, 200, 250}};
        const std::size_t index = static_cast<std::size_t>(difficulty);
        if (timer >= 10 && timer < 0x2d0 &&
            (timer - 10) % kInterval[index] == 0) {
            const double baseSpeed = difficulty == 4 ? 6.0 : 5.0;
            for (int i = 0; i < kCount[index]; ++i) {
                const int offset = i * 0x140 * (type == 0xd6 ? -1 : 1);
                spawnProjectileSpread(
                    9, 0, shotX, shotY,
                    boss09Angle(enemy.sourceAngle16 + offset),
                    10.0f, baseSpeed + i * 1.5, 1, 1, 0, 0);
            }
            fired = true;
        }
        enemy.sourceAngle16 = boss09Angle(
            static_cast<int>(enemy.sourceAngle16) +
            (type == 0xd6 ? kTurn[index] : -kTurn[index]));
    }
    else if (type == 0xd8) {
        static constexpr std::array<int, 5> kInterval{{120, 100, 80, 80, 60}};
        static constexpr std::array<double, 5> kSpeed{{6.0, 7.0, 7.5, 6.0, 7.5}};
        const auto target = aimed();
        int delta = static_cast<int>(target) -
                    static_cast<int>(enemy.sourceAngle16);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        enemy.sourceAngle16 = boss09Approach(
            enemy.sourceAngle16, target, std::abs(delta) / 20 + 0x30);
        const std::size_t index = static_cast<std::size_t>(difficulty);
        if (timer >= 0x1e && timer < 600 &&
            (timer - 0x1e) % kInterval[index] == 0) {
            spawnProjectileSpread(0x0c, 0, shotX, shotY,
                                  enemy.sourceAngle16, 10.0f,
                                  kSpeed[index], 1, 1, 0, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(0x0c, 0, shotX, shotY,
                                      enemy.sourceAngle16, 10.0f,
                                      kSpeed[index] + 3.0, 1, 1, 0, 0);
            }
            fired = true;
        }
    }

    if (fired) playPlayerSound(bullet1SoundHandle_, 0x13);
    if (timer >= lifetime) {
        enemy.helperState = 2;
        enemy.helperTimer = 0;
    }
}

bool StageRuntime::drawStage09Boss(const StageEnemy& enemy, float x,
                                   float y, int exactLayer) const {
    if (enemy.spawnType != 0x140) return false;
    if (!enemy.drawBodyThisFrame) return true;

    const int state = enemy.drawHelperState;
    const int timer = enemy.drawHelperTimer;
    int bodyFrame = 0x73 + (timer / 5) % 3;
    if (boss09NormalMoveState(state)) {
        const int duration = boss09NormalMoveDuration(state);
        if (timer < 10 || timer >= duration - 10) {
            bodyFrame = 0x76 + (timer / 5) % 2;
        }
        else {
            bodyFrame = 0x78 + (timer / 5) % 3;
        }
    }
    else if (state == 0x3c || state == 0xa0) {
        if (timer < 0x6e) bodyFrame = 0x7f + (timer / 5) % 2;
        else if (timer < 0x78) bodyFrame = 0x7e - (timer / 5) % 2;
    }
    else if (state == 99 || state == 199) {
        if (timer >= 0xf0) return true;
        bodyFrame = 0x7f + (timer / 5) % 2;
    }

    const auto drawFrame = [this](const std::vector<int>& frames, int frame,
                                  float drawX, float drawY,
                                  std::uint16_t angle = 0,
                                  double scale = 1.0,
                                  bool reverse = false) {
        if (frame < 0 || frame >= static_cast<int>(frames.size())) {
            return false;
        }
        const int graph = frames[static_cast<std::size_t>(frame)];
        if (graph == -1) return false;
        drawOriginalMode7Node(graph, drawX, drawY, angle,
                              scale, scale, reverse);
        return true;
    };
    const auto polarPoint = [](float centerX, float centerY,
                               std::uint16_t angle, float distance) {
        const double radians = boss09Radians(angle);
        return std::pair<float, float>{
            centerX + static_cast<float>(std::cos(radians) * distance),
            centerY + static_cast<float>(std::sin(radians) * distance)};
    };

    bool drew = false;
    const float cameraX = x - enemy.x;
    const float cameraY = y - enemy.y;
    const bool earlyAssembly = state < 0x3c ||
                               (state >= 0x6f && state < 0xa0);
    if (earlyAssembly) {
        // Enemy_l[62] is the moving upper body.  Enemy_l[61] is a separate
        // fixed-axis component: its normal copy is at layer 0x12 and state 0
        // also queues a materialization copy at layer 0x19.
        if (exactLayer == 0x1e) {
            drew |= drawFrame(enemyLargeFrames_, 0x3e, x, y);
        }
        const float assemblyY = cameraY + enemy.angle + 120.0f;
        if (exactLayer == 0x12) {
            drew |= drawFrame(enemyLargeFrames_, 0x3d,
                              cameraX + 360.0f, assemblyY);
        }
        if (exactLayer == 0x19 && state == 0 && timer < 0xbe) {
            const int alpha = std::clamp(timer * 255 / 0xbe, 0, 255);
            SetDrawBlendMode(DX_BLENDMODE_ADD, alpha);
            drew |= drawFrame(enemyLargeFrames_, 0x3d,
                              cameraX + 360.0f, assemblyY);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }

        // FUN_14004a970 builds six delayed links from each side.  The two
        // upper chains retain their own descending layers (0x14..0x0f), while
        // both lower chains are explicitly fixed to 0x0f.
        if ((state != 0 || timer >= 0x3c) &&
            exactLayer >= 0x0f && exactLayer <= 0x14) {
            float spacing = 55.0f;
            if (state == 0) {
                spacing *= std::clamp((timer - 0x3c) / 20.0f, 0.0f, 1.0f);
            }
            for (int link = 0; link < 6; ++link) {
                const float distance = spacing * static_cast<float>(link);
                const int upperLayer = 0x14 - link;
                const int phase = (frame_ - link * 10) % 120;
                const double pulse = phase >= 0 && phase <= 0x20 && state < 10
                    ? 1.0 + std::sin(static_cast<double>(phase) *
                                     kBoss09Pi / 0x20) * 0.1
                    : 1.0;
                if (exactLayer == upperLayer) {
                    const auto right = polarPoint(cameraX + 730.0f,
                                                   cameraY + enemy.angle + 420.0f,
                                                   0x9770, distance);
                    const auto left = polarPoint(cameraX - 10.0f,
                                                  cameraY + enemy.angle + 420.0f,
                                                  0xe890, distance);
                    drew |= drawFrame(enemySmallFrames_, 0x8a,
                                      right.first, right.second,
                                      0x9770, pulse);
                    drew |= drawFrame(enemySmallFrames_, 0x8a,
                                      left.first, left.second,
                                      0xe890, pulse, true);
                }
                if (exactLayer == 0x0f) {
                    const auto right = polarPoint(cameraX + 730.0f,
                                                   cameraY + enemy.angle - 30.0f,
                                                   0x6890, distance);
                    const auto left = polarPoint(cameraX - 10.0f,
                                                  cameraY + enemy.angle - 30.0f,
                                                  0x1770, distance);
                    drew |= drawFrame(enemySmallFrames_, 0x8b,
                                      right.first, right.second,
                                      0x6890, pulse);
                    drew |= drawFrame(enemySmallFrames_, 0x8b,
                                      left.first, left.second,
                                      0x1770, pulse, true);
                }
            }
        }
    }

    const bool lateLayerSet = state > 10 ||
                              (state == 10 && timer >= 0xfa);
    if (lateLayerSet && exactLayer == 0x22) {
        const int sideFrame = config_.difficulty > 3 ? 0x90 : 0x81;
        const int swing = static_cast<int>(
            std::sin(frame_ * kBoss09Tau / 120.0) * 3000.0);
        const double scale = 0.7 +
            std::sin(frame_ * kBoss09Tau / 120.0) * 0.3;
        drew |= drawFrame(bossFrames_, sideFrame,
                          x + 24.0f, y - 20.0f,
                          boss09Angle(swing), scale);
        drew |= drawFrame(bossFrames_, sideFrame,
                          x - 24.0f, y - 20.0f,
                          boss09Angle(-swing), scale, true);
    }

    const int bodyLayer = lateLayerSet ? 0x23 : 0x1e;
    if (lateLayerSet && exactLayer == bodyLayer) {
        drew |= drawFrame(bossFrames_, bodyFrame, x, y);
    }
    if (!drew && exactLayer == bodyLayer && !earlyAssembly) {
        DrawCircle(static_cast<int>(x), static_cast<int>(y), 46,
                   GetColor(120, 220, 255), TRUE);
    }
    return true;
}

bool StageRuntime::drawStage09BossNode(const StageEnemy& enemy, float x,
                                       float y, int exactLayer) const {
    if (enemy.parentSpawnType != 0x140 ||
        !isStage09BossNodeType(enemy.spawnType)) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) return true;

    const int timer = enemy.drawHelperTimer;
    if (enemy.spawnType == 0xc3) {
        if (exactLayer != 0x3c) return true;
        if (effectLargeFrames_.size() <= 6 || effectLargeFrames_[6] == -1) {
            return true;
        }
        int alpha = 255;
        double scale = 1.2;
        if (enemy.drawHelperState == 0 && timer < 32) {
            scale = 0.1 + std::sin(static_cast<double>(timer) *
                                   kBoss09Pi / 64.0) * 1.1;
        }
        else if (enemy.drawHelperState == 1) {
            alpha = timer < 16
                        ? static_cast<int>(
                              std::sin(static_cast<double>(timer + 16) *
                                       kBoss09Pi / 32.0) * 255.0)
                        : 0;
        }
        SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(alpha, 0, 255));
        DrawRotaGraphF(x, y, scale, boss09Radians(enemy.sourceAngle16),
                       effectLargeFrames_[6], TRUE);
        DrawRotaGraphF(x, y, scale,
                       -boss09Radians(enemy.sourceAngle16),
                       effectLargeFrames_[6], TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        return true;
    }

    if (enemy.spawnType == 0xcd) {
        if (exactLayer != 0x1d) return true;
        const int frame = 0xab + (timer / 5) % 3;
        if (frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size()) &&
            enemyMediumFrames_[static_cast<std::size_t>(frame)] != -1) {
            double scale = 1.0;
            if (timer < 0x10) {
                scale = std::sin(static_cast<double>(timer) *
                                 kBoss09Pi / 32.0);
            }
            else if (timer >= 0xa4) {
                scale = timer < 0xb4
                            ? std::sin(static_cast<double>(timer - 0x94) *
                                       kBoss09Pi / 32.0)
                            : 0.0;
            }
            const int alpha = std::clamp(
                0xc0 + static_cast<int>(
                           std::sin(static_cast<double>(timer) *
                                    kBoss09Pi / 2.0) * 32.0),
                0, 0xff);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            drawOriginalMode7Node(
                enemyMediumFrames_[static_cast<std::size_t>(frame)],
                x, y, 0, scale, scale, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        return true;
    }

    if (enemy.spawnType >= 0xda && enemy.spawnType <= 0xdd) {
        if (exactLayer != 0x23) return true;
        double scale = 1.0;
        if (timer < 0x1e) {
            scale = std::sin(static_cast<double>(timer) * kBoss09Pi / 60.0);
        }
        else if (timer >= 0x10e) {
            scale = std::max(
                0.0, std::sin(static_cast<double>(timer - 0xf0) *
                              kBoss09Pi / 60.0));
        }
        if (enemySmallFrames_.size() > 140 &&
            enemySmallFrames_[140] != -1) {
            drawOriginalMode7Node(enemySmallFrames_[140], x, y,
                                  enemy.sourceAngle16, scale, scale, false);
        }
        if (enemySmallFrames_.size() > 141 &&
            enemySmallFrames_[141] != -1) {
            drawOriginalMode7Node(enemySmallFrames_[141], x, y,
                                  enemy.secondaryAngle16, scale, scale, false);
        }
        return true;
    }

    int alpha = 255;
    double scale = 1.0;
    if (enemy.drawHelperState == 0) {
        scale = boss09Smooth(static_cast<double>(timer) / 20.0);
    }
    else if (enemy.drawHelperState == 2) {
        scale = 1.0 - boss09Smooth(static_cast<double>(timer) / 20.0);
        alpha = std::clamp(255 - timer * 13, 0, 255);
    }
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    if (exactLayer == 0x1f && enemySmallFrames_.size() > 140 &&
        enemySmallFrames_[140] != -1) {
        drawOriginalMode7Node(enemySmallFrames_[140], x, y,
                              enemy.secondaryAngle16, scale, scale, false);
    }
    if (exactLayer == 0x20 && enemySmallFrames_.size() > 141 &&
        enemySmallFrames_[141] != -1) {
        drawOriginalMode7Node(enemySmallFrames_[141], x, y,
                              enemy.sourceAngle16, scale, scale, false);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    return true;
}

} // namespace reconstructed
