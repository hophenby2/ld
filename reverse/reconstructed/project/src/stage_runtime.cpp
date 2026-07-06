#include "stage_runtime.h"

#include "reconstruction_notes.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>

namespace reconstructed {
namespace {

constexpr float kPi = 3.14159265358979323846f;
constexpr float kTau = kPi * 2.0f;
constexpr float kPlayLeft = 80.0f;
constexpr float kPlayRight = 720.0f;
constexpr float kPlayTop = 20.0f;
constexpr float kPlayBottom = 700.0f;

// Hand-transcribed Stage 01 slice from stage-spawn-schedule.csv. Rows that used
// DAT_140e9fd1c modulo expressions in the decompile are represented by stable
// deterministic coordinates here; this is a runnable reconstruction probe, not
// an exact recovered script interpreter.
constexpr std::array<StageRuntime::StageSpawnEvent, 25> kStage01Events{{
    {200, 0x0a, 0x960, 0x1e0, 0x96, "S01 row 1: type 0x0a fixed early entry"},
    {260, 0x0a, 2000, 0x0f0, 200, "S01 row 2: type 0x0a fixed follow-up"},
    {350, 0x0a, 2000, 0x208, 100, "S01 row 3: type 0x0a fixed lane"},
    {365, 0x0a, 2000, 0x168, 100, "S01 row 4: type 0x0a fixed lane"},
    {380, 0x0a, 2000, 200, 100, "S01 row 5: type 0x0a fixed lane"},
    {400, 0x0b, 400, 0x140, -20, "S01 row 6: type 0x0b top random entry"},
    {420, 0x0b, 400, 0x240, -20, "S01 row 6 repeat: type 0x0b top random entry"},
    {700, 0x06, 5000, 0x1cc, 0, "S01 row 7: common marker/emitter"},
    {900, 0x0e, 10000, 0x118, 0, "S01 row 8: long-lived common setpiece"},
    {1100, 0x0e, 10000, 0x1cc, 0, "S01 row 9: long-lived common setpiece"},
    {1180, 0x0c, 400, 0x1a0, -20, "S01 row 10: type 0x0c top entry"},
    {1270, 0x0d, 700, 740, 290, "S01 row 11: type 0x0d right edge entry"},
    {1380, 0x0b, 500, -20, 180, "S01 row 12: type 0x0b left edge entry"},
    {1460, 0x0b, 500, 740, 220, "S01 row 13: type 0x0b right edge entry"},
    {2200, 0x0f, 8000, 0x348, 0x96, "S01 row 14: type 0x0f side setpiece"},
    {2500, 0x0d, 700, -20, 290, "S01 row 15: type 0x0d left entry burst"},
    {2650, 0x0b, 400, 0x260, -20, "S01 row 16: type 0x0b top burst"},
    {2780, 0x10, 40000, 0x168, 0x50, "S01 row 17: type 0x10 long setpiece"},
    {3600, 0x0c, 400, 0x180, -20, "S01 row 18: later type 0x0c top entry"},
    {3600, 0x0e, 7000, 0x1cc, 0, "S01 row 19: later type 0x0e setpiece"},
    {3820, 0x0b, 500, 740, 240, "S01 row 20: later type 0x0b side entry"},
    {4200, 0x0d, 500, -20, 300, "S01 row 21: later type 0x0d left/top entry"},
    {4200, 0x0e, 7000, 0x1cc, 0, "S01 row 22: later type 0x0e setpiece"},
    {4360, 0x0f, 8000, -120, 100, "S01 row 23: later type 0x0f side setpiece"},
    {5100, 0x08, 5000, 0x104, 0, "S01 row 27: common marker/emitter"},
}};

// First-pass Stage 02 slice: a deterministic subset of the stage 02 schedule that
// preserves the observed timing/type block (0x19..0x20 plus common 0x0b/0x0d).
// It is intentionally sparse enough to be inspectable in the current runtime.
constexpr std::array<StageRuntime::StageSpawnEvent, 30> kStage02Events{{
    {120, 0x19, 800, -0x398, -20, "S02 row 1: type 0x19 patterned top lane"},
    {150, 0x19, 800, -0x2f8, -20, "S02 row 1 repeat: type 0x19 patterned top lane"},
    {180, 0x19, 800, -0x258, -20, "S02 row 1 repeat: type 0x19 patterned top lane"},
    {260, 0x1a, 300, 0x160, -20, "S02 row 2: type 0x1a randomized top entry"},
    {280, 0x1a, 300, 0x240, -20, "S02 row 2 repeat: type 0x1a randomized top entry"},
    {700, 0x07, 5000, 0x104, 0, "S02 row 3: common marker/emitter"},
    {1020, 0x1d, 0x6a4, 0x120, 0x80, "S02 row 4: type 0x1d fixed path point"},
    {1120, 0x1d, 0x6a4, 0x240, 0x90, "S02 row 4 repeat: type 0x1d fixed path point"},
    {1240, 0x1e, 0x834, 0x180, 0x60, "S02 row 5: type 0x1e path point"},
    {1400, 0x1f, 11000, 0x1e4, -0xdbe, "S02 row 6: type 0x1f long setpiece"},
    {1700, 0x0b, 400, 740, 180, "S02 row 7: reused common side entry"},
    {1760, 0x0b, 400, 740, 260, "S02 row 7 repeat: reused common side entry"},
    {1900, 0x1b, 0x1130, 0x104, 0, "S02 row 8: type 0x1b long anchor"},
    {2000, 0x1b, 0x1130, 0x1cc, 0, "S02 row 9: type 0x1b long anchor"},
    {2250, 0x0d, 400, -20, 0x96, "S02 row 10: reused common left/top entry"},
    {2420, 0x19, 500, 0x1d0, -20, "S02 row 11: type 0x19 top random entry"},
    {2560, 0x1a, 300, 0x220, -20, "S02 row 12: type 0x1a top random entry"},
    {2670, 0x1b, 0x1130, 0xf0, 0, "S02 row 13: type 0x1b anchor"},
    {2820, 0x0b, 400, 740, 180, "S02 row 14: common right entry"},
    {3000, 0x0b, 400, -20, 180, "S02 row 15: common left entry"},
    {3200, 0x1c, 6000, 0x348, 0x32, "S02 row 16: type 0x1c side setpiece"},
    {3500, 0x1a, 300, 0x1a0, -20, "S02 row 17: type 0x1a burst"},
    {3650, 0x1c, 6000, -120, 100, "S02 row 18: type 0x1c side setpiece"},
    {3900, 0x0b, 400, 0x220, -20, "S02 row 19: common top burst"},
    {4200, 0x19, 700, 0x1b0, -20, "S02 row 20: type 0x19 burst"},
    {4500, 0x1b, 4000, 0x168, 0, "S02 row 21: type 0x1b paired anchor"},
    {4580, 0x1b, 4000, 0x1fe, 0, "S02 row 22: type 0x1b paired anchor"},
    {4900, 0x1a, 300, 0x1e0, -20, "S02 row 23: type 0x1a top burst"},
    {5200, 0x1c, 0x1068, 0x348, 0x50, "S02 row 24: type 0x1c right-side setpiece"},
    {5600, 0x20, 0x2b5c, 0x168, -500, "S02 row 25: type 0x20 long stage-end setpiece"},
}};

// First-pass Stage 04 slice: sparse anchors from the Stage 04 schedule and
// reviewed helper notes. This gives the runtime a body-after-marker type (0x35),
// drifting emitter (0x37), heavy multipart source (0x38), child-carrier pair
// (0x39/0x3a), anchor spread emitter (0x3d), and boss-like controller (0x3f).
constexpr std::array<StageRuntime::StageSpawnEvent, 24> kStage04Events{{
    {0, 0x37, 500, 0x1c0, 420, "S04 row 1: type 0x37 random drifting emitter"},
    {80, 0x35, 0xfa, 0x2e4, 0x96, "S04 row 2: type 0x35 right-entry tri-afterimage"},
    {180, 0x38, 5000, 0x1e0, 0, "S04 row 3: type 0x38 long multipart source"},
    {260, 0x35, 0xfa, -20, 0x96, "S04 row 4: type 0x35 left-entry tri-afterimage"},
    {400, 0x38, 5000, 0xf0, 0, "S04 row 5: type 0x38 long multipart source"},
    {700, 0x07, 5000, 0x1cc, 0, "S04 row 9: common marker/emitter"},
    {820, 0x3d, 9000, -200, 0x96, "S04 row 10: type 0x3d three-anchor spread emitter"},
    {980, 0x36, 400, -20, 300, "S04 row 11: type 0x36 side curving spread emitter"},
    {1100, 0x36, 400, 740, 300, "S04 row 12: type 0x36 mirrored side curving spread emitter"},
    {1280, 0x38, 4000, 500, 0, "S04 row 13: type 0x38 fixed heavy source"},
    {1380, 0x38, 4000, 0xdc, 0, "S04 row 14: type 0x38 fixed heavy source"},
    {1540, 0x3d, 7000, 0x398, 0x96, "S04 row 15: type 0x3d right anchor emitter"},
    {1780, 0x39, 8000, 0x262, -80, "S04 row 20: type 0x39 directional child carrier"},
    {1900, 0x39, 8000, 0x6e, -80, "S04 row 21: type 0x39 directional child carrier"},
    {2050, 0x3a, 8000, 800, 200, "S04 row 22: type 0x3a mirrored child carrier"},
    {2300, 0x0b, 400, 0x210, -20, "S04 row 23: reused common top burst"},
    {2500, 0x36, 400, -20, 360, "S04 row 25: type 0x36 late left burst"},
    {2600, 0x36, 400, 740, 360, "S04 row 26: type 0x36 late right burst"},
    {3600, 0x3f, 48000, 0x167, 0, "S04 row 27: boss-like multipart pattern controller"},
    {4500, 0x35, 200, 0x2e4, 0x8c, "S04 row 28: fast right tri-afterimage pair"},
    {4500, 0x35, 200, -20, 0x8c, "S04 row 29: fast left tri-afterimage pair"},
    {4700, 0x3d, 9000, -200, 0x96, "S04 row 30: type 0x3d anchor refresh"},
    {5480, 0x37, 500, 0x220, 430, "S04 row 32: late type 0x37 drifting wave"},
    {5600, 0x38, 6000, 0x1cc, 0, "S04 row 33: late heavy source"},
}};

float clampFloat(float value, float low, float high) {
    return std::max(low, std::min(value, high));
}

float distanceSquared(float ax, float ay, float bx, float by) {
    const float dx = ax - bx;
    const float dy = ay - by;
    return dx * dx + dy * dy;
}

bool stageUsesMediumFrame(int spawnType) {
    return (spawnType >= 0x0e && spawnType <= 0x10) ||
           (spawnType >= 0x1b && spawnType <= 0x20) ||
           spawnType == 0x38 || spawnType == 0x3d || spawnType == 0x3f;
}

} // namespace

const StageRuntime::StageSpawnEvent* StageRuntime::eventsForStage(int stage, std::size_t& count) {
    if (stage == 2) {
        count = kStage02Events.size();
        return kStage02Events.data();
    }
    if (stage == 4) {
        count = kStage04Events.size();
        return kStage04Events.data();
    }
    count = kStage01Events.size();
    return kStage01Events.data();
}

bool StageRuntime::initialize(ResourceManager& resources, int stage) {
    playerFrames_ = resources.loadDivGraph("media\\player\\Player.png", 0x78, 0xf, 8, 0x50, 0x50);
    enemySmallFrames_ = resources.loadDivGraph("media\\stage\\Enemy_s.png", 0xaa, 10, 0x11, 100, 100);
    enemyMediumFrames_ = resources.loadDivGraph("media\\stage\\Enemy_m.png", 0xe6, 10, 0x17, 200, 200);
    bulletFrames_ = resources.loadDivGraph("media\\stage\\Bullet.png", 0x28, 10, 4, 0x3c, 0x3c);
    stageBack1Frames_ = resources.loadDivGraph("media\\stage\\StageBack1.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack2Frames_ = resources.loadDivGraph("media\\stage\\StageBack2.png", 10, 10, 1, 0x2d0, 0x2d0);

    selectedStage_ = (stage == 2 || stage == 4) ? stage : 1;
    initialized_ = !playerFrames_.empty() && playerFrames_.front() != -1 &&
                   !enemySmallFrames_.empty() && enemySmallFrames_.front() != -1 &&
                   !bulletFrames_.empty() && bulletFrames_.front() != -1;
    reset();
    return initialized_;
}

void StageRuntime::setStage(int stage) {
    const int normalized = (stage == 2 || stage == 4) ? stage : 1;
    if (selectedStage_ != normalized) {
        selectedStage_ = normalized;
        reset();
    }
}

void StageRuntime::reset() {
    frame_ = 0;
    player_ = {};
    enemies_.clear();
    enemyProjectiles_.clear();
    playerShots_.clear();
}

void StageRuntime::update() {
    if (!initialized_) {
        return;
    }

    if (CheckHitKey(KEY_INPUT_R) != 0) {
        reset();
        return;
    }

    spawnDueEvents();
    updatePlayer();
    updatePlayerShots();
    updateEnemies();
    updateProjectiles();
    handleCollisions();

    enemies_.erase(std::remove_if(enemies_.begin(), enemies_.end(), [](const StageEnemy& enemy) {
                       return !enemy.active || offscreen(enemy.x, enemy.y, 180.0f) || enemy.age > enemy.lifetime;
                   }), enemies_.end());
    enemyProjectiles_.erase(std::remove_if(enemyProjectiles_.begin(), enemyProjectiles_.end(), [](const StageProjectile& projectile) {
                                return !projectile.active || offscreen(projectile.x, projectile.y, 80.0f);
                            }), enemyProjectiles_.end());
    playerShots_.erase(std::remove_if(playerShots_.begin(), playerShots_.end(), [](const PlayerShot& shot) {
                           return !shot.active || shot.y < -40.0f;
                       }), playerShots_.end());

    ++frame_;
}

void StageRuntime::draw() const {
    drawBackground();
    drawPlayerShots();
    drawEnemies();
    drawProjectiles();
    drawPlayer();
    drawOverlay();
}

int StageRuntime::enemiesAlive() const {
    return static_cast<int>(enemies_.size());
}

int StageRuntime::enemyProjectilesAlive() const {
    return static_cast<int>(enemyProjectiles_.size());
}

void StageRuntime::spawnDueEvents() {
    std::size_t eventCount = 0;
    const StageSpawnEvent* events = eventsForStage(selectedStage_, eventCount);
    for (std::size_t i = 0; i < eventCount; ++i) {
        const auto& event = events[i];
        if (event.frame == frame_) {
            spawnEnemy(event);
        }
    }
}

void StageRuntime::spawnEnemy(const StageSpawnEvent& event) {
    StageEnemy enemy;
    enemy.spawnType = event.spawnType;
    enemy.lifetime = event.lifetime;
    enemy.x = static_cast<float>(event.x);
    enemy.y = static_cast<float>(event.y);
    enemy.angle = aimAtPlayer(enemy.x, enemy.y);

    switch (event.spawnType) {
    case 0x06:
    case 0x07:
    case 0x08:
        enemy.hp = 28;
        enemy.radius = 40;
        enemy.visualFrame = 88;
        enemy.vy = 0.25f;
        break;
    case 0x0a:
        enemy.hp = 20;
        enemy.radius = 34;
        enemy.visualFrame = 70;
        enemy.vy = 0.65f;
        break;
    case 0x0b:
        enemy.hp = 8;
        enemy.radius = 24;
        enemy.visualFrame = 16;
        enemy.speed = 1.7f;
        break;
    case 0x0c:
    case 0x0d:
        enemy.hp = 10;
        enemy.radius = 24;
        enemy.visualFrame = 20 + (event.spawnType - 0x0c) * 2;
        enemy.speed = 1.45f;
        break;
    case 0x0e:
    case 0x0f:
    case 0x10:
        enemy.hp = 36;
        enemy.radius = 48;
        enemy.visualFrame = 96;
        enemy.vy = 0.25f;
        break;
    case 0x19:
    case 0x1a:
        enemy.hp = 12;
        enemy.radius = 26;
        enemy.visualFrame = 34 + (event.spawnType - 0x19) * 4;
        enemy.speed = event.spawnType == 0x19 ? 1.35f : 1.75f;
        break;
    case 0x1b:
    case 0x1c:
        enemy.hp = 32;
        enemy.radius = 44;
        enemy.visualFrame = 108 + (event.spawnType - 0x1b) * 3;
        enemy.vy = 0.18f;
        break;
    case 0x1d:
    case 0x1e:
        enemy.hp = 18;
        enemy.radius = 32;
        enemy.visualFrame = 46 + (event.spawnType - 0x1d) * 6;
        enemy.speed = 1.15f;
        break;
    case 0x1f:
    case 0x20:
        enemy.hp = 48;
        enemy.radius = 58;
        enemy.visualFrame = 132;
        enemy.vy = 0.35f;
        break;
    case 0x35:
        enemy.hp = 18;
        enemy.radius = 28;
        enemy.visualFrame = 34;
        enemy.speed = 5.0f;
        break;
    case 0x36:
    case 0x37:
        enemy.hp = 14;
        enemy.radius = 26;
        enemy.visualFrame = event.spawnType == 0x36 ? 36 : 40;
        enemy.speed = event.spawnType == 0x36 ? 3.2f : 1.7f;
        break;
    case 0x38:
        enemy.hp = 80;
        enemy.radius = 56;
        enemy.visualFrame = 120;
        enemy.vy = 0.2f;
        break;
    case 0x39:
    case 0x3a:
        enemy.hp = 50;
        enemy.radius = 44;
        enemy.visualFrame = event.spawnType == 0x39 ? 124 : 128;
        enemy.speed = 1.1f;
        break;
    case 0x3d:
        enemy.hp = 64;
        enemy.radius = 48;
        enemy.visualFrame = 134;
        enemy.vy = 0.16f;
        break;
    case 0x3f:
        enemy.hp = 240;
        enemy.radius = 70;
        enemy.visualFrame = 138;
        enemy.vy = 0.1f;
        break;
    default:
        enemy.hp = 12;
        enemy.radius = 28;
        enemy.visualFrame = 8;
        enemy.speed = 1.2f;
        break;
    }

    enemies_.push_back(enemy);
}

void StageRuntime::updatePlayer() {
    player_.focused = CheckHitKey(KEY_INPUT_LSHIFT) != 0 || CheckHitKey(KEY_INPUT_RSHIFT) != 0;
    const float speed = player_.focused ? 3.0f : 5.5f;
    float dx = 0.0f;
    float dy = 0.0f;
    if (CheckHitKey(KEY_INPUT_LEFT) != 0) dx -= 1.0f;
    if (CheckHitKey(KEY_INPUT_RIGHT) != 0) dx += 1.0f;
    if (CheckHitKey(KEY_INPUT_UP) != 0) dy -= 1.0f;
    if (CheckHitKey(KEY_INPUT_DOWN) != 0) dy += 1.0f;
    if (dx != 0.0f && dy != 0.0f) {
        dx *= 0.70710678f;
        dy *= 0.70710678f;
    }
    player_.x = clampFloat(player_.x + dx * speed, kPlayLeft, kPlayRight);
    player_.y = clampFloat(player_.y + dy * speed, kPlayTop, kPlayBottom);

    if (player_.shotCooldown > 0) {
        --player_.shotCooldown;
    }
    if (player_.invulnerableFrames > 0) {
        --player_.invulnerableFrames;
    }
    if (CheckHitKey(KEY_INPUT_Z) != 0 && player_.shotCooldown == 0) {
        playerShots_.push_back({player_.x - 10.0f, player_.y - 22.0f});
        playerShots_.push_back({player_.x + 10.0f, player_.y - 22.0f});
        player_.shotCooldown = player_.focused ? 5 : 4;
    }
}

void StageRuntime::updateEnemies() {
    for (auto& enemy : enemies_) {
        ++enemy.age;
        if (enemy.age <= enemy.activationDelay) {
            enemy.vx *= 0.92f;
            enemy.vy *= 0.92f;
            continue;
        }
        const int activeAge = enemy.age - enemy.activationDelay;
        if (enemy.spawnType == 0x35) {
            const float desired = aimAtPlayer(enemy.x, enemy.y + 48.0f);
            const float turn = activeAge < 100 ? 0.12f : 0.025f;
            enemy.angle = enemy.angle * (1.0f - turn) + desired * turn;
            enemy.vx = std::cos(enemy.angle) * enemy.speed;
            enemy.vy = std::sin(enemy.angle) * enemy.speed;
            if (activeAge > 100) {
                enemy.speed = std::max(1.4f, enemy.speed - 0.035f);
            }
        }
        else if (enemy.spawnType == 0x36) {
            const float desired = aimAtPlayer(enemy.x, enemy.y);
            enemy.angle = enemy.angle * 0.92f + desired * 0.08f;
            enemy.vx = std::cos(enemy.angle) * enemy.speed;
            enemy.vy = std::sin(enemy.angle) * enemy.speed;
        }
        else if (enemy.spawnType == 0x37) {
            const float wobble = std::sin((enemy.age + enemy.spawnType * 11) * 0.06f);
            enemy.angle = enemy.angle * 0.97f + aimAtPlayer(enemy.x, enemy.y) * 0.03f;
            enemy.vx = std::cos(enemy.angle) * enemy.speed + wobble * 0.9f;
            enemy.vy = std::sin(enemy.angle) * enemy.speed;
        }
        else if (enemy.spawnType == 0x38 || enemy.spawnType == 0x3d || enemy.spawnType == 0x3f) {
            enemy.vx = std::sin((enemy.age + enemy.spawnType * 17) * 0.02f) * (enemy.spawnType == 0x3f ? 1.4f : 0.9f);
            if (enemy.spawnType == 0x3f && activeAge > 180) {
                enemy.vy = std::sin(activeAge * 0.018f) * 0.45f;
            }
        }
        else if (enemy.spawnType == 0x39 || enemy.spawnType == 0x3a) {
            const float sign = enemy.spawnType == 0x39 ? 1.0f : -1.0f;
            enemy.vx = sign * std::sin(activeAge * 0.025f) * 1.8f;
            enemy.vy = 0.55f + std::cos(activeAge * 0.03f) * 0.45f;
        }
        else if ((enemy.spawnType == 0x0b || enemy.spawnType == 0x0c || enemy.spawnType == 0x0d ||
             enemy.spawnType == 0x19 || enemy.spawnType == 0x1a || enemy.spawnType == 0x1d || enemy.spawnType == 0x1e) && enemy.age < 220) {
            const float desired = aimAtPlayer(enemy.x, enemy.y);
            enemy.angle = enemy.angle * 0.94f + desired * 0.06f;
            enemy.vx = std::cos(enemy.angle) * enemy.speed;
            enemy.vy = std::sin(enemy.angle) * enemy.speed;
        }
        else if (enemy.spawnType == 0x0e || enemy.spawnType == 0x0f || enemy.spawnType == 0x10 ||
                 enemy.spawnType == 0x1b || enemy.spawnType == 0x1c || enemy.spawnType == 0x1f || enemy.spawnType == 0x20) {
            enemy.vx = std::sin((enemy.age + enemy.spawnType * 17) * 0.025f) * 1.1f;
        }

        enemy.x += enemy.vx;
        enemy.y += enemy.vy;

        if (activeAge > 30 && activeAge % 70 == 0) {
            const int selector = (enemy.spawnType >= 0x19 && enemy.spawnType <= 0x20) ? 1 : 0;
            spawnProjectileNode(0, selector, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 3.0f, 6);
        }
        if (enemy.spawnType == 0x35 && activeAge > 40 && activeAge % 42 == 0) {
            spawnProjectileSpread(6, 0, enemy.x, enemy.y + 48.0f, aimAtPlayer(enemy.x, enemy.y), 2.8f, 6, 3, kPi / 7.0f);
        }
        if (enemy.spawnType == 0x36 && activeAge > 50 && activeAge % 72 == 0) {
            spawnProjectileSpread(4, 0, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.9f, 6, 5, kPi / 5.0f);
        }
        if (enemy.spawnType == 0x37 && activeAge > 70 && activeAge % 64 == 0) {
            spawnProjectileNode(0, 0, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 3.2f, 5);
        }
        if (enemy.spawnType == 0x38 && activeAge > 100 && activeAge % 96 == 0) {
            spawnProjectileSpread(9, 2, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.3f, 8, 10, kTau);
        }
        if ((enemy.spawnType == 0x39 || enemy.spawnType == 0x3a) && activeAge > 80 && activeAge % 120 == 0) {
            spawnProjectileSpread(3, 3, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.5f, 7, 7, kPi * 0.85f);
        }
        if (enemy.spawnType == 0x3d && activeAge > 70 && activeAge % 130 == 0) {
            for (float offset : {-80.0f, 0.0f, 80.0f}) {
                spawnProjectileSpread(5, 2, enemy.x + offset, enemy.y, aimAtPlayer(enemy.x + offset, enemy.y), 2.4f, 8, 5, kPi / 3.0f);
            }
        }
        if (enemy.spawnType == 0x3f && activeAge > 90 && activeAge % 75 == 0) {
            spawnProjectileSpread(7, 0, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.6f, 7, 14, kTau);
            spawnProjectileSpread(2, 2, enemy.x, enemy.y + 32.0f, aimAtPlayer(enemy.x, enemy.y), 2.0f, 9, 8, kPi);
        }
        if ((enemy.spawnType == 0x0c || enemy.spawnType == 0x0d || enemy.spawnType == 0x19 || enemy.spawnType == 0x1a) &&
            activeAge > 80 && activeAge % 120 == 0) {
            const int count = (enemy.spawnType == 0x0c || enemy.spawnType == 0x19) ? 3 : 5;
            spawnProjectileSpread(count, 0, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.6f, 6, count, kPi / 5.0f);
        }
        if ((enemy.spawnType == 0x0e || enemy.spawnType == 0x0f || enemy.spawnType == 0x10 ||
             enemy.spawnType == 0x1b || enemy.spawnType == 0x1c || enemy.spawnType == 0x1f || enemy.spawnType == 0x20) &&
            activeAge > 120 && activeAge % 180 == 0) {
            const int selector = enemy.spawnType >= 0x19 ? 3 : 2;
            spawnProjectileSpread(2, selector, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.2f, 8, 12, kTau);
        }
    }
}

void StageRuntime::updateProjectiles() {
    for (auto& projectile : enemyProjectiles_) {
        ++projectile.age;
        if (projectile.projectileId == 9 || projectile.projectileId == 0x0b) {
            if (projectile.age == 45) {
                const float speed = std::sqrt(projectile.vx * projectile.vx + projectile.vy * projectile.vy);
                const float angle = aimAtPlayer(projectile.x, projectile.y);
                projectile.vx = std::cos(angle) * speed;
                projectile.vy = std::sin(angle) * speed;
            }
        }
        projectile.x += projectile.vx;
        projectile.y += projectile.vy;
    }
}

void StageRuntime::updatePlayerShots() {
    for (auto& shot : playerShots_) {
        shot.y += shot.vy;
    }
}

void StageRuntime::handleCollisions() {
    for (auto& shot : playerShots_) {
        if (!shot.active) {
            continue;
        }
        for (auto& enemy : enemies_) {
            if (!enemy.active) {
                continue;
            }
            const int radius = shot.radius + enemy.radius;
            if (distanceSquared(shot.x, shot.y, enemy.x, enemy.y) <= static_cast<float>(radius * radius)) {
                shot.active = false;
                enemy.hp -= 2;
                if (enemy.hp <= 0) {
                    enemy.active = false;
                }
                break;
            }
        }
    }

    if (player_.invulnerableFrames == 0) {
        for (auto& projectile : enemyProjectiles_) {
            const int radius = projectile.radius + (player_.focused ? 3 : 6);
            if (distanceSquared(projectile.x, projectile.y, player_.x, player_.y) <= static_cast<float>(radius * radius)) {
                projectile.active = false;
                --player_.lives;
                player_.invulnerableFrames = 180;
                player_.x = 640.0f;
                player_.y = 620.0f;
                if (player_.lives < 0) {
                    player_.lives = 3;
                    reset();
                }
                break;
            }
        }
    }
}

void StageRuntime::spawnProjectileNode(int projectileId, int visualSelector, float x, float y, float angle, float speed, int radius) {
    StageProjectile projectile;
    projectile.projectileId = projectileId;
    projectile.visualSelector = visualSelector;
    projectile.x = x;
    projectile.y = y;
    projectile.vx = std::cos(angle) * speed;
    projectile.vy = std::sin(angle) * speed;
    projectile.radius = radius;
    enemyProjectiles_.push_back(projectile);
}

void StageRuntime::spawnProjectileSpread(int projectileId, int visualSelector, float x, float y, float centerAngle, float speed, int radius, int count, float spreadRadians) {
    if (count <= 1) {
        spawnProjectileNode(projectileId, visualSelector, x, y, centerAngle, speed, radius);
        return;
    }
    if (spreadRadians >= kTau - 0.001f) {
        for (int i = 0; i < count; ++i) {
            spawnProjectileNode(projectileId, visualSelector, x, y, centerAngle + kTau * static_cast<float>(i) / static_cast<float>(count), speed, radius);
        }
        return;
    }
    const float start = centerAngle - spreadRadians * 0.5f;
    const float step = spreadRadians / static_cast<float>(count - 1);
    for (int i = 0; i < count; ++i) {
        spawnProjectileNode(projectileId, visualSelector, x, y, start + step * static_cast<float>(i), speed, radius);
    }
}

void StageRuntime::drawBackground() const {
    DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(10, 14, 28), TRUE);
    const int scroll = frame_ % 720;
    if (!stageBack2Frames_.empty() && stageBack2Frames_.front() != -1) {
        DrawGraph(40, scroll - 720, stageBack2Frames_.front(), TRUE);
        DrawGraph(40, scroll, stageBack2Frames_.front(), TRUE);
    }
    if (!stageBack1Frames_.empty() && stageBack1Frames_.front() != -1) {
        const int slowScroll = (frame_ / 2) % 720;
        DrawGraph(40, slowScroll - 720, stageBack1Frames_.front(), TRUE);
        DrawGraph(40, slowScroll, stageBack1Frames_.front(), TRUE);
    }
    DrawBox(static_cast<int>(kPlayLeft), 0, static_cast<int>(kPlayRight), notes::kScreenHeight, GetColor(12, 12, 28), FALSE);
}

void StageRuntime::drawPlayer() const {
    const int frame = playerFrames_.empty() ? -1 : playerFrames_[0];
    if (frame != -1 && (player_.invulnerableFrames / 6) % 2 == 0) {
        DrawRotaGraphF(player_.x, player_.y, 0.7, 0.0, frame, TRUE);
    }
    const int color = player_.focused ? GetColor(128, 220, 255) : GetColor(255, 255, 255);
    DrawCircle(static_cast<int>(player_.x), static_cast<int>(player_.y), player_.focused ? 3 : 5, color, FALSE);
}

void StageRuntime::drawEnemies() const {
    for (const auto& enemy : enemies_) {
        const auto& frames = stageUsesMediumFrame(enemy.spawnType) ? enemyMediumFrames_ : enemySmallFrames_;
        const int index = frames.empty() ? -1 : std::min(enemy.visualFrame, static_cast<int>(frames.size()) - 1);
        const int handle = index < 0 ? -1 : frames[static_cast<std::size_t>(index)];
        if (handle != -1) {
            const double scale = stageUsesMediumFrame(enemy.spawnType) ? 0.42 : 0.55;
            DrawRotaGraphF(enemy.x, enemy.y, scale, enemy.angle + kPi * 0.5f, handle, TRUE);
        }
        else {
            DrawCircle(static_cast<int>(enemy.x), static_cast<int>(enemy.y), enemy.radius, GetColor(255, 96, 160), TRUE);
        }
    }
}

void StageRuntime::drawProjectiles() const {
    for (const auto& projectile : enemyProjectiles_) {
        int frameIndex = 0;
        switch (projectile.visualSelector) {
        case 0x01: frameIndex = 1; break;
        case 0x02: frameIndex = 2; break;
        case 0x03: frameIndex = 3; break;
        case 0x04: frameIndex = 4; break;
        case 0x07: frameIndex = 7; break;
        case 0x0a: frameIndex = 20; break;
        case 0x0f: frameIndex = 25; break;
        default: frameIndex = 0; break;
        }
        const int handle = bulletFrames_.empty() || frameIndex >= static_cast<int>(bulletFrames_.size()) ? -1 : bulletFrames_[static_cast<std::size_t>(frameIndex)];
        const float angle = std::atan2(projectile.vy, projectile.vx) + kPi * 0.5f;
        if (handle != -1) {
            DrawRotaGraphF(projectile.x, projectile.y, 0.75, angle, handle, TRUE);
        }
        else {
            DrawCircle(static_cast<int>(projectile.x), static_cast<int>(projectile.y), projectile.radius, GetColor(255, 80, 180), TRUE);
        }
    }
}

void StageRuntime::drawPlayerShots() const {
    for (const auto& shot : playerShots_) {
        DrawBox(static_cast<int>(shot.x - 2), static_cast<int>(shot.y - 12),
                static_cast<int>(shot.x + 2), static_cast<int>(shot.y + 8), GetColor(120, 220, 255), TRUE);
    }
}

void StageRuntime::drawOverlay() const {
    DrawFormatString(24, 24, GetColor(255, 240, 128), "Playable reconstruction Stage %02d  frame=%d", selectedStage_, frame_);
    DrawFormatString(24, 48, GetColor(255, 255, 255), "Arrows move  Shift focus  Z shot  R reset  1/2/4 stage slice  F1-F5 diagnostics  ESC exit");
    DrawFormatString(24, 72, GetColor(210, 210, 210), "enemies=%d enemyBullets=%d shots=%d lives=%d",
                     static_cast<int>(enemies_.size()), static_cast<int>(enemyProjectiles_.size()),
                     static_cast<int>(playerShots_.size()), player_.lives);
    DrawString(24, notes::kScreenHeight - 44,
               "Evidence slice: selected stage schedule + common projectile/spread semantics; behavior is simplified pending helper-by-helper reconstruction.",
               GetColor(210, 210, 210));
}

float StageRuntime::aimAtPlayer(float x, float y) const {
    return std::atan2(player_.y - y, player_.x - x);
}

float StageRuntime::deterministicUnit(int frame, int salt) {
    std::uint32_t value = static_cast<std::uint32_t>(frame * 1103515245u + salt * 12345u + 0x314159u);
    value ^= value >> 16;
    return static_cast<float>(value & 0xffffu) / 65535.0f;
}

bool StageRuntime::offscreen(float x, float y, float margin) {
    return x < -margin || x > notes::kScreenWidth + margin || y < -margin || y > notes::kScreenHeight + margin;
}

} // namespace reconstructed
