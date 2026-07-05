#include "stage_runtime.h"

#include "reconstruction_notes.h"

#include <DxLib.h>

#include <algorithm>
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
constexpr StageRuntime::StageSpawnEvent kStage01Events[] = {
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
    {2780, 0x10, 40000, 0x168, 0x50, "S01 row 17: type 0x10 long setpiece"},
    {3600, 0x0c, 400, 0x180, -20, "S01 row 18: later type 0x0c top entry"},
    {3600, 0x0e, 7000, 0x1cc, 0, "S01 row 19: later type 0x0e setpiece"},
    {3820, 0x0b, 500, 740, 240, "S01 row 20: later type 0x0b side entry"},
    {4200, 0x0d, 500, -20, 300, "S01 row 21: later type 0x0d left/top entry"},
    {4200, 0x0e, 7000, 0x1cc, 0, "S01 row 22: later type 0x0e setpiece"},
    {4360, 0x0f, 8000, -120, 100, "S01 row 23: later type 0x0f side setpiece"},
    {5100, 0x08, 5000, 0x104, 0, "S01 row 27: common marker/emitter"},
};

float clampFloat(float value, float low, float high) {
    return std::max(low, std::min(value, high));
}

float distanceSquared(float ax, float ay, float bx, float by) {
    const float dx = ax - bx;
    const float dy = ay - by;
    return dx * dx + dy * dy;
}

} // namespace

bool StageRuntime::initialize(ResourceManager& resources) {
    playerFrames_ = resources.loadDivGraph("media\\player\\Player.png", 0x78, 0xf, 8, 0x50, 0x50);
    enemySmallFrames_ = resources.loadDivGraph("media\\stage\\Enemy_s.png", 0xaa, 10, 0x11, 100, 100);
    enemyMediumFrames_ = resources.loadDivGraph("media\\stage\\Enemy_m.png", 0xe6, 10, 0x17, 200, 200);
    bulletFrames_ = resources.loadDivGraph("media\\stage\\Bullet.png", 0x28, 10, 4, 0x3c, 0x3c);
    stageBack1Frames_ = resources.loadDivGraph("media\\stage\\StageBack1.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack2Frames_ = resources.loadDivGraph("media\\stage\\StageBack2.png", 10, 10, 1, 0x2d0, 0x2d0);

    initialized_ = !playerFrames_.empty() && playerFrames_.front() != -1 &&
                   !enemySmallFrames_.empty() && enemySmallFrames_.front() != -1 &&
                   !bulletFrames_.empty() && bulletFrames_.front() != -1;
    reset();
    return initialized_;
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
    for (const auto& event : kStage01Events) {
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
        if ((enemy.spawnType == 0x0b || enemy.spawnType == 0x0c || enemy.spawnType == 0x0d) && enemy.age < 220) {
            const float desired = aimAtPlayer(enemy.x, enemy.y);
            enemy.angle = enemy.angle * 0.94f + desired * 0.06f;
            enemy.vx = std::cos(enemy.angle) * enemy.speed;
            enemy.vy = std::sin(enemy.angle) * enemy.speed;
        }
        else if (enemy.spawnType == 0x0e || enemy.spawnType == 0x0f || enemy.spawnType == 0x10) {
            enemy.vx = std::sin((enemy.age + enemy.spawnType * 17) * 0.025f) * 1.1f;
        }

        enemy.x += enemy.vx;
        enemy.y += enemy.vy;

        if (enemy.age > 30 && enemy.age % 70 == 0) {
            spawnProjectileNode(0, 0, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 3.0f, 6);
        }
        if ((enemy.spawnType == 0x0c || enemy.spawnType == 0x0d) && enemy.age > 80 && enemy.age % 120 == 0) {
            spawnProjectileSpread(enemy.spawnType == 0x0c ? 3 : 5, 0, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.6f, 6, 5, kPi / 5.0f);
        }
        if ((enemy.spawnType == 0x0e || enemy.spawnType == 0x0f || enemy.spawnType == 0x10) && enemy.age > 120 && enemy.age % 180 == 0) {
            spawnProjectileSpread(2, 2, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.2f, 8, 12, kTau);
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
        const auto& frames = enemy.spawnType >= 0x0e ? enemyMediumFrames_ : enemySmallFrames_;
        const int index = frames.empty() ? -1 : std::min(enemy.visualFrame, static_cast<int>(frames.size()) - 1);
        const int handle = index < 0 ? -1 : frames[static_cast<std::size_t>(index)];
        if (handle != -1) {
            const double scale = enemy.spawnType >= 0x0e ? 0.42 : 0.55;
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
    DrawFormatString(24, 24, GetColor(255, 240, 128), "Playable reconstruction Stage 01  frame=%d", frame_);
    DrawFormatString(24, 48, GetColor(255, 255, 255), "Arrows move  Shift focus  Z shot  R reset  F1-F5 diagnostics  ESC exit");
    DrawFormatString(24, 72, GetColor(210, 210, 210), "enemies=%d enemyBullets=%d shots=%d lives=%d",
                     static_cast<int>(enemies_.size()), static_cast<int>(enemyProjectiles_.size()),
                     static_cast<int>(playerShots_.size()), player_.lives);
    DrawString(24, notes::kScreenHeight - 44,
               "Evidence slice: Stage 01 schedule + common projectile/spread semantics; behavior is simplified pending helper-by-helper reconstruction.",
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
