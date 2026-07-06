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
        int projectileId = 0;
        int visualSelector = 0;
        int age = 0;
        float x = 0.0f;
        float y = 0.0f;
        float vx = 0.0f;
        float vy = 0.0f;
        int radius = 5;
        bool active = true;
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
    void spawnEnemy(const StageSpawnEvent& event);
    void updatePlayer();
    void updateEnemies();
    void updateProjectiles();
    void updatePlayerShots();
    void handleCollisions();
    void spawnProjectileNode(int projectileId, int visualSelector, float x, float y, float angle, float speed, int radius);
    void spawnProjectileSpread(int projectileId, int visualSelector, float x, float y, float centerAngle, float speed, int radius, int count, float spreadRadians);
    void drawBackground() const;
    void drawPlayer() const;
    void drawEnemies() const;
    void drawProjectiles() const;
    void drawPlayerShots() const;
    void drawOverlay() const;

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
    std::vector<StageEnemy> enemies_;
    std::vector<StageProjectile> enemyProjectiles_;
    std::vector<PlayerShot> playerShots_;
};

} // namespace reconstructed
