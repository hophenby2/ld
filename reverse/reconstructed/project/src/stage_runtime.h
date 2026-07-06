#pragma once

#include "resource_manager.h"

#include <cstdint>
#include <cstddef>
#include <vector>

namespace reconstructed {

class StageRuntime {
public:
    struct StageSpawnEvent {
        int frame = 0;
        int spawnType = 0;
        int lifetime = 0;
        int x = 0;
        int y = 0;
        const char* sourceNote = nullptr;
    };

    bool initialize(ResourceManager& resources, int stage = 1);
    void setStage(int stage);
    void reset();
    void update();
    void draw() const;

    bool initialized() const { return initialized_; }
    int selectedStage() const { return selectedStage_; }
    int frame() const { return frame_; }
    int enemiesAlive() const;
    int enemyProjectilesAlive() const;

private:
    struct PlayerState {
        float x = 640.0f;
        float y = 620.0f;
        int shotCooldown = 0;
        int invulnerableFrames = 0;
        int lives = 3;
        bool focused = false;
    };

    struct StageEnemy {
        int spawnType = 0;
        int age = 0;
        int lifetime = 0;
        float x = 0.0f;
        float y = 0.0f;
        float vx = 0.0f;
        float vy = 0.0f;
        float angle = 0.0f;
        float speed = 0.0f;
        int hp = 8;
        int radius = 24;
        int visualFrame = 0;
        int activationDelay = 20;
        bool active = true;
    };

    struct StageProjectile {
        bool active = true;
        int age = 0;
        int visualSelector = 0;
        int projectileId = 0;
        float x = 0.0f;
        float y = 0.0f;
        float prevX = 0.0f;
        float prevY = 0.0f;
        float speedOrAccelHint = 0.0f;
        std::uint16_t angle16 = 0;
        std::uint16_t prevAngle16 = 0;
        float angle = 0.0f;
        float speed = 0.0f;
        float baseSpeed = 0.0f;
        int radius = 5;
        bool grazeOrHitProcessed = false;
        bool collisionEnabled = true;
        int arg8OrAux = 0;
        float vx = 0.0f;
        float vy = 0.0f;
    };

    struct PlayerShot {
        float x = 0.0f;
        float y = 0.0f;
        float vy = -12.0f;
        int radius = 5;
        bool active = true;
    };

    static const StageSpawnEvent* eventsForStage(int stage, std::size_t& count);
    void spawnDueEvents();
    void spawnStage04OriginalSchedule();
    void spawnEnemy(const StageSpawnEvent& event);
    void updatePlayer();
    void updateEnemies();
    void updateStage04Enemy(StageEnemy& enemy, int activeAge);
    void emitStage04Projectiles(StageEnemy& enemy, int activeAge);
    void updateGenericEnemy(StageEnemy& enemy, int activeAge);
    void emitGenericProjectiles(StageEnemy& enemy, int activeAge);
    void updateProjectiles();
    void updateProjectileCommonMotion(StageProjectile& projectile);
    void updateProjectileReflectOnBoundary(StageProjectile& projectile);
    void updateProjectileHomingSteering(StageProjectile& projectile);
    void updateProjectileScriptedEmitter(StageProjectile& projectile);
    void updateProjectileOrbitArcPair(StageProjectile& projectile);
    void updateProjectileExpandingSpiralPair(StageProjectile& projectile);
    static void updateProjectileVelocity(StageProjectile& projectile);
    void updatePlayerShots();
    void handleCollisions();
    void spawnProjectileNode(int projectileId, int visualSelector, float x, float y, float angle, float speed, int radius);
    void spawnProjectileNode(int projectileId, int visualSelector, float x, float y, std::uint16_t angle16, float speedOrAccelHint, float speed, int radius, int arg8OrAux);
    void spawnProjectileSpread(int projectileId, int visualSelector, float x, float y, float centerAngle, float speed, int radius, int count, float spreadRadians);
    void spawnProjectileSpread(int projectileId, int visualSelector, float x, float y, std::uint16_t centerAngle16, float speedOrAccelHint, float speed, int radius, int count, int spreadAngle16, int arg8OrAux);
    void drawBackground() const;
    void drawPlayer() const;
    void drawEnemies() const;
    void drawProjectiles() const;
    void drawPlayerShots() const;
    void drawOverlay() const;
    void drawHudSidebar() const;
    void drawDebugOverlay() const;
    void drawHudNumber(int rightX, int y, int value, const std::vector<int>& digitFrames, int digitWidth, int digitHeight, double scale = 1.0) const;
    void drawHudGauge(int x, int y, int value, int maxValue) const;
    void drawHudTokenPips(int x, int y, int activeCount, int maxCount) const;

    float aimAtPlayer(float x, float y) const;
    static float deterministicUnit(int frame, int salt);
    static bool offscreen(float x, float y, float margin);

    bool initialized_ = false;
    int selectedStage_ = 1;
    int frame_ = 0;
    PlayerState player_;
    std::vector<int> playerFrames_;
    std::vector<int> enemySmallFrames_;
    std::vector<int> enemyMediumFrames_;
    std::vector<int> bulletFrames_;
    std::vector<int> stageBack1Frames_;
    std::vector<int> stageBack2Frames_;
    std::vector<int> stageFrameFrames_;
    std::vector<int> numSmallFrames_;
    std::vector<int> numMediumFrames_;
    std::vector<int> numLargeFrames_;
    int dataWindowHandle_ = -1;
    int timeWindowHandle_ = -1;
    std::vector<int> playerFrameFrames_;
    std::vector<int> stateFrames_;
    std::vector<int> dreamGaugeFrames_;
    std::vector<StageEnemy> enemies_;
    std::vector<StageProjectile> enemyProjectiles_;
    std::vector<PlayerShot> playerShots_;
};

} // namespace reconstructed
