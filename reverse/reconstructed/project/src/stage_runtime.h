#pragma once

#include "resource_manager.h"
#include "text_database.h"

#include <array>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace reconstructed {

class StageRuntime {
public:
    struct StageRuntimeConfig {
        int stage = 1;
        int routeMode = 0;
        int setupGroup = 0;
        int playerOption = 0;
        int subOption = 0;
        int loadoutId = 0;
        int difficulty = 0;
        int counterMode = 0;
        int specialMode = 0;
        int specialStageFlag = 0;
        int dataWindowEnabled = 1;
        int language = 0;
        int bgmVolume = 10;
        int soundEffectVolume = 10;
        int itemVisibility = 0;
        int likeStyle = 0;
        std::array<int, 4> optionSlots{{0, 0, 0, 0}};
        std::array<int, 11> keyboardBindings{{
            0xc8, 0xd0, 0xcd, 0xcb, 0x2c, 0x2d, 0x2c, 0x2d, 0x2e, 0x2a, 0x01,
        }};
        std::array<int, 11> controllerBindings{{
            0x08, 0x01, 0x04, 0x02, 0x10, 0x20, 0x10, 0x40, 0x20, 0x200, 0x800,
        }};
        int controlDevice = 5;
        int controlModeEnabled = 1;
        int helpMode = 6;
        int helpAutoProgress = 0;
        int rawStartFrame = 0;
        int firstDispatchFrame = 0;
        int initialStock = -1;
        int initialStockProgressSteps = -1;
        int initialSpecialGauge = -1;
        bool continueRun = false;
        const TextDatabase* textDatabase = nullptr;
    };

    struct StageSpawnEvent {
        int frame = 0;
        int spawnType = 0;
        int hitPoints = 0;
        int x = 0;
        int y = 0;
        const char* sourceNote = nullptr;
    };

    bool initialize(ResourceManager& resources, int stage = 1);
    bool initialize(ResourceManager& resources, const StageRuntimeConfig& config);
    void setStage(int stage);
    bool setConfig(const StageRuntimeConfig& config);
    void reset();
    void update();
    void draw() const;

    bool initialized() const { return initialized_; }
    int selectedStage() const { return selectedStage_; }
    int frame() const { return frame_; }
    int score() const { return player_.score; }
    int enemiesAlive() const;
    int enemyProjectilesAlive() const;
    bool stageComplete() const {
        if (selectedStage_ == 1) return stage01ClearComplete_;
        if (selectedStage_ == 2) return stage02ClearComplete_;
        if (selectedStage_ == 3) return stage03ClearComplete_;
        if (selectedStage_ == 4) return stage04ClearComplete_;
        if (selectedStage_ >= 5 && selectedStage_ <= 10) {
            return lateStageClearComplete_[static_cast<std::size_t>(selectedStage_)];
        }
        return false;
    }

private:
    enum class InputAction : int {
        Up = 0,
        Down = 1,
        Right = 2,
        Left = 3,
        Confirm = 4,
        Cancel = 5,
        Shoot = 6,
        Bomb = 7,
        RapidFire = 8,
        Slow = 9,
        Pause = 10,
    };

    struct PlayerState {
        float x = 360.0f;
        float y = 620.0f;
        int playerStateTimer = 0;
        int shotTimer = 0;
        int focusTransition = 0x20;
        int focusHoldTimer = 0;
        int shotVariant = 0;
        int score = 0;
        int scoreItemBaseValue = 100;
        int specialGauge = 0;
        int tokenStock = 2;
        int graze = 0;
        int keyStateCount = 0;
        int stockProgress = 0;
        int invulnerableFrames = 0;
        int lives = 3;
        int bombLock = 0;
        std::array<float, 4> optionX{};
        std::array<float, 4> optionY{};
        std::array<std::uint16_t, 4> optionAngle16{{0xc000, 0xc000, 0xc000, 0xc000}};
        std::uint16_t optionFormationAngle16 = 0xc000;
        std::uint16_t movementAngle16 = 0xc000;
        bool focused = false;
    };

    struct StageEnemy {
        int spawnType = 0;
        int age = 0;
        int maxHp = 8;
        float x = 0.0f;
        float y = 0.0f;
        float vx = 0.0f;
        float vy = 0.0f;
        float angle = 0.0f;
        float speed = 0.0f;
        int hp = 8;
        int drawHp = 8;
        int radius = 24;
        int visualFrame = 0;
        int activationDelay = 20;
        int sourceHitPoints = 0;
        int sourceX = 0;
        int sourceY = 0;
        int updateCase = -1;
        int sourceDispatchKind = -1;
        int sourceDispatchField = 0;
        int entityId = 0;
        int parentEntityId = 0;
        int parentSpawnType = 0;
        int childIndex = 0;
        int liveChildCount = 0;
        const char* sourceNote = nullptr;
        float originX = 0.0f;
        float originY = 0.0f;
        std::uint16_t sourceAngle16 = 0;
        std::uint16_t secondaryAngle16 = 0;
        std::uint16_t targetAngle16 = 0;
        double sourceSpeed = 0.0;
        int helperState = 0;
        int helperTimer = 0;
        int drawHelperState = 0;
        int drawHelperTimer = 0;
        int targetableTimer = 0;
        int rewardWeight = 1;
        bool drawBodyThisFrame = false;
        bool drawMarkerThisFrame = false;
        bool guardSpawnLatched = false;
        int markerDrawTimer = 0;
        float markerDrawX = 0.0f;
        float markerDrawY = 0.0f;
        bool targetable = true;
        bool active = true;
    };

    struct StageProjectile {
        bool active = true;
        int age = 0;
        int drawAge = 0;
        bool drawQueuedThisFrame = false;
        int visualSelector = 0;
        int projectileId = 0;
        float x = 0.0f;
        float y = 0.0f;
        float anchorX = 0.0f;
        float anchorY = 0.0f;
        float prevX = 0.0f;
        float prevY = 0.0f;
        float speedOrAccelHint = 0.0f;
        std::uint16_t angle16 = 0;
        std::uint16_t prevAngle16 = 0;
        float angle = 0.0f;
        double speed = 0.0;
        double baseSpeed = 0.0;
        int radius = 5;
        bool grazeOrHitProcessed = false;
        bool collisionEnabled = true;
        int arg8OrAux = 0;
        float vx = 0.0f;
        float vy = 0.0f;
    };

    struct PlayerSideObject {
        bool active = true;
        int age = 0;
        int type = 0;
        float x = 0.0f;
        float y = 0.0f;
        float originX = 0.0f;
        float originY = 0.0f;
        std::uint16_t angle16 = 0;
        std::uint16_t drawAngle16 = 0;
        double speedOrScale = 0.0;
        int damageOrLifetime = 0;
        float collisionRadiusOrScale = 0.0f;
        float auxRadiusOrScale = 0.0f;
        int scratch = 0;
        int next = -1;
    };

    struct RewardItem {
        bool active = true;
        int age = 0;
        int drawAge = 0;
        int itemType = 0;
        float x = 0.0f;
        float y = 0.0f;
        std::uint16_t angle16 = 0;
        float speed = 0.0f;
        int radiusOrScale = 12;
        bool homing = false;
    };

    struct StageEffect {
        bool active = true;
        int age = 0;
        int type = 0;
        int graphHandle = -1;
        int graphExtent = 0;
        int drawLayer = 0;
        float x = 0.0f;
        float y = 0.0f;
        std::uint16_t angle16 = 0;
        double scale0 = 1.0;
        double scaleX = 1.0;
        double scaleY = 1.0;
        int lifetime = 0;
        int colorR = 0xff;
        int colorG = 0xff;
        int colorB = 0xff;
        int alpha = 0xff;
        int ownerEntityId = 0;
        std::uint32_t randomSeed = 0;
        bool drawQueuedThisFrame = false;
        float drawX = 0.0f;
        float drawY = 0.0f;
        std::uint16_t drawAngle16 = 0;
        double drawScaleX = 1.0;
        double drawScaleY = 1.0;
        int drawAlpha = 0xff;
    };

    static const StageSpawnEvent* eventsForStage(int stage, std::size_t& count);
    void pollInput();
    bool actionDown(InputAction action) const;
    void spawnDueEvents();
    void spawnStage01OriginalSchedule();
    void spawnStage02OriginalSchedule();
    void spawnStage03OriginalSchedule();
    void spawnStage04OriginalSchedule();
    void spawnStage05OriginalSchedule();
    void spawnStage06OriginalSchedule();
    void spawnStage07OriginalSchedule();
    void spawnStage08OriginalSchedule();
    void spawnStage09OriginalSchedule();
    void spawnStage10OriginalSchedule();
    void updateStageBannerTextSound() const;
    void updateEarlyStageApproachTimeline();
    void updateLateStageTimeline();
    void spawnBackgroundEffects();
    void flushEnemyProjectilesToEffects();
    void spawnBossPhaseBreakFeedback(const StageEnemy& enemy, int countdown);
    void flushStageForBossHandoff(int bossBgmIndex);
    void spawnEnemy(const StageSpawnEvent& event);
    bool configureLateStageEnemy(StageEnemy& enemy, const StageSpawnEvent& event);
    void spawnStage01Child(StageEnemy& parent, int childIndex, float offsetX, float offsetY, int hitPoints, const char* note);
    bool spawnStage01BossChild(StageEnemy& parent, int spawnType, int childIndex,
                               float offsetX, float offsetY, int hitPoints, const char* note);
    void spawnStage01MarkerSatellite(StageEnemy& parent, int childIndex, float offsetX, float offsetY, int hitPoints, const char* note);
    void spawnStage02Type21Child(const StageEnemy& parent, int childIndex, float x, float yOffset);
    bool spawnStage02BossChild(StageEnemy& parent, int spawnType, int childIndex,
                               float offsetOrRadiusX, float offsetY,
                               std::uint16_t orbitAngle, const char* note);
    void spawnStage03Satellite(const StageEnemy& parent, int spawnType, int childIndex,
                               float offsetX, float offsetY, int angle16);
    void spawnStage03Type2FChild(const StageEnemy& parent);
    bool spawnStage03BossChild(StageEnemy& parent, int spawnType, int childIndex,
                               float offsetOrTargetX, float offsetOrTargetY,
                               int hitPoints, int kind, double speed, int radius,
                               std::uint16_t angle16, const char* note);
    void spawnDelayedOwnerDamageNode(int hitPoints, int ownerEntityId,
                                     int ownerSpawnType, const char* note);
    void spawnStage03DeathNode(const StageEnemy& enemy, int hitPoints,
                               int ownerEntityId);
    bool spawnStage04BossChild(StageEnemy& parent, int spawnType, int childIndex,
                               float offsetX, float offsetY, int hitPoints,
                               int kind, double speed, int radius,
                               std::uint16_t angle16, const char* note);
    void spawnStage04DeathNode(const StageEnemy& enemy, int hitPoints,
                               int ownerEntityId);
    void spawnStage04CarrierChild(const StageEnemy& parent, int spawnType);
    void spawnStage04Type3DChild(const StageEnemy& parent, int childIndex, float offsetX, float offsetY);
    StageEnemy* findEnemyById(int entityId);
    void updatePlayer();
    void updatePlayerOptions();
    void updateEnemies();
    void updateStage01Enemy(StageEnemy& enemy, int activeAge);
    void updateStage01Type0A(StageEnemy& enemy, int activeAge);
    void updateStage01Type0B(StageEnemy& enemy, int activeAge);
    void updateStage01Type0C(StageEnemy& enemy, int activeAge);
    void updateStage01Type0D(StageEnemy& enemy, int activeAge);
    void updateStage01Type0E(StageEnemy& enemy);
    void updateStage01Type0F(StageEnemy& enemy);
    void updateStage01Setpiece(StageEnemy& enemy, int activeAge);
    void updateStage01Marker(StageEnemy& enemy, int activeAge);
    void updateStage01MarkerSatellite(StageEnemy& enemy, int activeAge);
    void updateStage01Child(StageEnemy& enemy, int activeAge);
    void updateStage01Boss(StageEnemy& enemy);
    void updateStage01BossDecoration(StageEnemy& enemy);
    void updateStage01BossChild(StageEnemy& enemy);
    bool spawnStage01BossDecoration(StageEnemy& parent, int spawnType,
                                    float offsetX, float offsetY,
                                    const char* note);
    void emitStage01BossProjectiles(StageEnemy& enemy);
    void emitStage01BossChildProjectiles(StageEnemy& enemy, const StageEnemy& parent);
    void emitStage01Projectiles(StageEnemy& enemy, int activeAge);
    void updateStage02Type19(StageEnemy& enemy);
    void updateStage02Type1A(StageEnemy& enemy);
    void updateStage02Type1B(StageEnemy& enemy);
    void updateStage02Type1C(StageEnemy& enemy);
    void updateStage02Type1DOr1E(StageEnemy& enemy);
    void updateStage02Type1F(StageEnemy& enemy);
    void updateStage02Type20(StageEnemy& enemy);
    void updateStage02Type21(StageEnemy& enemy);
    void updateStage02Boss(StageEnemy& enemy);
    void updateStage02BossChild(StageEnemy& enemy);
    void updatePostDeathCounterEntity(StageEnemy& enemy);
    void emitStage02BossProjectiles(StageEnemy& enemy);
    void emitStage02BossChildProjectiles(StageEnemy& enemy, const StageEnemy& parent);
    void spawnStage02DeathExplosionChain(const StageEnemy& enemy);
    void spawnStageEffect(int type, int graphHandle, int graphExtent, int drawLayer,
                          float x, float y, std::uint16_t angle16,
                          double scale0, double scaleX, double scaleY,
                          int lifetime, int colorR, int colorG, int colorB, int alpha,
                          int ownerEntityId = 0);
    void updateStageEffects();
    void updateStage03Enemy(StageEnemy& enemy);
    void updateStage03Type25(StageEnemy& enemy);
    void updateStage03Type26(StageEnemy& enemy);
    void updateStage03Type27Or29(StageEnemy& enemy);
    void updateStage03Satellite(StageEnemy& enemy);
    void updateStage03Type2B(StageEnemy& enemy);
    void updateStage03Type2C(StageEnemy& enemy);
    void updateStage03Type2D(StageEnemy& enemy);
    void updateStage03Type2E(StageEnemy& enemy);
    void updateStage03Type2F(StageEnemy& enemy);
    void updateStage03Boss(StageEnemy& enemy);
    void emitStage03BossProjectiles(StageEnemy& enemy);
    void updateStage03BossChild(StageEnemy& enemy);
    void updateStage03Type30(StageEnemy& enemy, StageEnemy& parent);
    void updateStage03Type31(StageEnemy& enemy, StageEnemy& parent);
    void updateStage03Type32Or33(StageEnemy& enemy, StageEnemy& parent);
    void updateStage03Type34(StageEnemy& enemy, StageEnemy& parent);
    void updateStage03DeathNode(StageEnemy& enemy);
    void updateStage04Enemy(StageEnemy& enemy, int activeAge);
    void emitStage04Projectiles(StageEnemy& enemy, int activeAge);
    void finishStage04CarrierSharedHp(StageEnemy& enemy);
    void updateStage04Boss(StageEnemy& enemy);
    void emitStage04BossProjectiles(StageEnemy& enemy);
    void updateStage04BossChild(StageEnemy& enemy);
    void updateStage04Type40(StageEnemy& enemy, StageEnemy& parent);
    void updateStage04Type41(StageEnemy& enemy, StageEnemy& parent);
    void updateStage04Type42Or43(StageEnemy& enemy, StageEnemy& parent);
    bool isLateStageEnemyType(int spawnType) const;
    bool isLateStageBossType(int spawnType) const;
    bool isLateStageFinalBossType(int spawnType) const;
    bool isStage06MidbossNodeType(int spawnType) const;
    bool isStage07MidbossType(int spawnType) const;
    bool isStage07MidbossNodeType(int spawnType) const;
    bool isStage07BossNodeType(int spawnType) const;
    bool isStage08BossNodeType(int spawnType) const;
    bool isStage09BossNodeType(int spawnType) const;
    bool isStage09MidbossType(int spawnType) const;
    bool isStage09MidbossNodeType(int spawnType) const;
    bool isStage08EnemyType(int spawnType) const;
    bool isStage10FinalBossNodeType(int spawnType) const;
    bool isLateStageGateOwner(const StageEnemy& enemy) const;
    void clearLateStageGate(int stage);
    void updateLateStageEnemy(StageEnemy& enemy, int activeAge);
    void emitLateStageProjectiles(StageEnemy& enemy, int activeAge);
    void updateLateStageBoss(StageEnemy& enemy);
    void updateStage05Boss(StageEnemy& enemy);
    void emitStage05BossProjectiles(StageEnemy& enemy);
    void updateStage05BossChild(StageEnemy& enemy);
    bool spawnStage05BossChild(StageEnemy& parent, int spawnType,
                               float offsetX, float offsetY,
                               std::uint16_t angle16, double speed,
                               int radius, int hitPoints, int kind,
                               const char* note);
    void updateStage06Boss(StageEnemy& enemy);
    void updateStage06BossNode(StageEnemy& enemy);
    bool spawnStage06BossNode(StageEnemy& parent, int spawnType,
                              int childIndex, float offsetX, float offsetY,
                              std::uint16_t angle16, int radius);
    void updateStage06Midboss(StageEnemy& enemy);
    void updateStage06MidbossNode(StageEnemy& enemy);
    bool spawnStage06MidbossNode(StageEnemy& parent, int spawnType,
                                 int childIndex, float initialRadius,
                                 std::uint16_t angle16, double spinAmplitude);
    bool drawStage06Midboss(const StageEnemy& enemy, float x, float y) const;
    bool drawStage06MidbossNode(const StageEnemy& enemy, float x, float y) const;
    bool isStage06EnemyType(int spawnType) const;
    void updateStage06Enemy(StageEnemy& enemy);
    void emitStage06EnemyProjectiles(StageEnemy& enemy);
    bool spawnStage06EnemyNode(StageEnemy& parent, int childIndex,
                               std::uint16_t angle16);
    bool drawStage06Enemy(const StageEnemy& enemy, float x, float y) const;
    void updateStage07Midboss(StageEnemy& enemy);
    void updateStage07MidbossNode(StageEnemy& enemy);
    bool spawnStage07MidbossNode(StageEnemy& parent, int spawnType,
                                 int childIndex, float xOrOffset,
                                 float yOrOffset, std::uint16_t angle16,
                                 double speed, int hitPoints, int radius,
                                 bool attached, int kind,
                                 bool countsForPhase);
    bool drawStage07Midboss(const StageEnemy& enemy, float x, float y) const;
    bool drawStage07MidbossNode(const StageEnemy& enemy, float x,
                                float y) const;
    void updateStage07Enemy(StageEnemy& enemy);
    void emitStage07EnemyProjectiles(StageEnemy& enemy);
    bool spawnStage07EnemyChild(StageEnemy& parent, float offsetX,
                                float offsetY, int childIndex);
    bool drawStage07Enemy(const StageEnemy& enemy, float x, float y) const;
    void updateStage08Enemy(StageEnemy& enemy);
    bool spawnStage08EnemyChild(StageEnemy& parent, int spawnType,
                                int childIndex, float offsetX, float offsetY,
                                std::uint16_t angle16, int kind, int radius,
                                bool targetable);
    bool drawStage08Enemy(const StageEnemy& enemy, float x, float y) const;
    void updateStage07Boss(StageEnemy& enemy);
    void updateStage07BossNode(StageEnemy& enemy);
    bool spawnStage07BossNode(StageEnemy& parent, int spawnType,
                              int childIndex, float offsetX, float offsetY,
                              std::uint16_t angle16, double speed,
                              int radius, int hitPoints);
    void updateStage08Boss(StageEnemy& enemy);
    void emitStage08BossProjectiles(StageEnemy& enemy);
    void updateStage08BossNode(StageEnemy& enemy);
    bool spawnStage08BossNode(StageEnemy& parent, int spawnType,
                              int childIndex, float offsetX, float offsetY,
                              std::uint16_t angle16, double speed,
                              int hitPoints, int radius, bool attached);
    bool drawStage08Boss(const StageEnemy& enemy, float x, float y) const;
    bool drawStage08BossNode(const StageEnemy& enemy, float x, float y) const;
    void updateStage09Boss(StageEnemy& enemy);
    void emitStage09BossProjectiles(StageEnemy& enemy);
    void updateStage09BossNode(StageEnemy& enemy);
    bool spawnStage09BossNode(StageEnemy& parent, int spawnType,
                              int childIndex, float offsetX, float offsetY,
                              std::uint16_t angle16, double speed,
                              int radius, bool attached);
    bool drawStage09Boss(const StageEnemy& enemy, float x, float y) const;
    bool drawStage09BossNode(const StageEnemy& enemy, float x, float y) const;
    void updateStage09Midboss(StageEnemy& enemy);
    void updateStage09MidbossNode(StageEnemy& enemy);
    void emitStage09Midboss146Projectiles(StageEnemy& enemy);
    void emitStage09Midboss148Projectiles(StageEnemy& enemy);
    void updateStage09TailMidboss(StageEnemy& enemy);
    void updateStage09TailMidbossNode(StageEnemy& enemy);
    void emitStage09Midboss149Projectiles(StageEnemy& enemy);
    void emitStage09Midboss14AProjectiles(StageEnemy& enemy);
    bool spawnStage09MidbossNode(StageEnemy& parent, int spawnType,
                                 int childIndex, float offsetX, float offsetY,
                                 std::uint16_t angle16, double speed,
                                 int hitPoints, int radius, bool attached);
    bool drawStage09Midboss(const StageEnemy& enemy, float x, float y) const;
    bool drawStage09MidbossNode(const StageEnemy& enemy, float x, float y) const;
    bool drawStage09TailMidboss(const StageEnemy& enemy, float x, float y) const;
    bool drawStage09TailMidbossNode(const StageEnemy& enemy, float x, float y) const;
    void updateStage10Enemy(StageEnemy& enemy);
    void emitStage10EnemyProjectiles(StageEnemy& enemy);
    bool drawStage10Enemy(const StageEnemy& enemy, float x, float y) const;
    bool isStage10SceneNodeType(int spawnType) const;
    bool isSharedHitboxProxyType(int spawnType) const;
    bool isStage10GuardNodeType(int spawnType) const;
    void ensureStage10SceneRootNode(StageEnemy& parent);
    bool spawnStage10SceneNode(StageEnemy& parent, int spawnType,
                               int childIndex, float offsetX, float offsetY,
                               std::uint16_t angle16, double speed,
                               int hitPoints, int kind, int radius);
    void updateStage10SceneNode(StageEnemy& enemy);
    bool drawStage10SceneNode(const StageEnemy& enemy, float x,
                              float y) const;
    bool spawnSharedHitboxProxy(StageEnemy& parent, int spawnType,
                                float offsetX, float offsetY, int radius);
    void updateSharedHitboxProxy(StageEnemy& enemy);
    void maybeSpawnStage10GuardNode(StageEnemy& owner);
    void updateStage10GuardNode(StageEnemy& enemy);
    bool drawStage10GuardNode(const StageEnemy& enemy, float x,
                              float y) const;
    bool isStage10FinalBossEmitterType(int spawnType) const;
    bool spawnStage10FinalBossEmitter(StageEnemy& parent, int spawnType,
                                      float targetX, float targetY,
                                      std::uint16_t angle16, double speed,
                                      int childIndex = 0);
    void updateStage10FinalBossEmitter(StageEnemy& enemy);
    bool drawStage10FinalBossEmitter(const StageEnemy& enemy, float x,
                                     float y) const;
    void updateStage10FinalBossNode(StageEnemy& enemy);
    bool spawnStage10FinalBossNode(StageEnemy& parent, int spawnType);
    void updateProjectiles();
    void updateProjectileCommonMotion(StageProjectile& projectile);
    void updateProjectileReflectOnBoundary(StageProjectile& projectile);
    void updateProjectileHomingSteering(StageProjectile& projectile);
    void updateProjectileScriptedEmitter(StageProjectile& projectile);
    void updateProjectileOrbitArcPair(StageProjectile& projectile);
    void updateProjectileExpandingSpiralPair(StageProjectile& projectile);
    void spawnProjectileTerminalEffect(float x, float y);
    static void updateProjectileVelocity(StageProjectile& projectile);
    void updateRewardItems();
    int effectiveHelpLevel() const;
    int stockThresholdForCurrentConfig() const;
    void addRunScore(int amount);
    void addSpecialGauge(int amount);
    void collectRewardItem(const RewardItem& item);
    void processStockProgressAfterGain(int progressGain);
    void spawnEnemyDeathRewardBurst(const StageEnemy& enemy, int payoutWindow = 0,
                                    bool spawnImmediateEffect = true);
    void spawnEnemyDeathEffects(const StageEnemy& enemy, int mode,
                                bool playSound = true);
    void spawnPostDeathCounterEntity(const StageEnemy& enemy, double lifetime);
    void updateSpecialGaugeAction();
    void updateSpecialGaugeState();
    bool settlePendingPlayerHit();
    void startEquippedBomb();
    void startFever(bool manualActivation);
    void armManualFever();
    void playPlayerSound(int handle, int volumeMultiplier = 0x19) const;
    void updateBossCountdownAudio(int hitPoints, int countdown) const;
    void updatePlayerSideObjects();
    std::uint16_t nearestTargetAngleForPlayerShot(const PlayerSideObject& object) const;
    void handleCollisions();
    void handlePlayerSideObjectEnemyCollisions();
    void handlePlayerSideObjectProjectileCancels();
    void handleEnemyProjectilePlayerHitAndGraze();
    void emitPlayerNormalShot();
    void spawnPlayerSideObject(int type, float x, float y, double speedOrScale, std::uint16_t angle16, int damageOrLifetime, float collisionRadiusOrScale);
    int enemyVisualFrameForSpawnType(const StageEnemy& enemy) const;
    bool enemyUsesMediumFrame(const StageEnemy& enemy) const;
    int playerSideObjectVisualFrame(const PlayerSideObject& object) const;
    bool playerSideObjectCanHitEnemy(const PlayerSideObject& object) const;
    bool playerSideObjectCanCancelProjectile(const PlayerSideObject& object) const;
    int playerSideObjectDamage(const PlayerSideObject& object) const;
    void spawnProjectileNode(int visualSelector, int projectileId, float x, float y, float angle, double speed, int radius);
    void spawnProjectileNode(int visualSelector, int projectileId, float x, float y, std::uint16_t angle16, float initialTravel, double speed, int radius, int arg8OrAux);
    void spawnProjectileSpread(int visualSelector, int projectileId, float x, float y, float centerAngle, double speed, int radius, int count, float spreadRadians);
    void spawnProjectileSpread(int visualSelector, int projectileId, float x, float y, std::uint16_t centerAngle16, float initialTravel, double speed, int radius, int count, int spreadAngle16, int arg8OrAux);
    void spawnRewardItem(int itemType, float x, float y, std::uint16_t angle16, float speed, int radiusOrScale);
    void drawBackground() const;
    void drawPlayerSideObjects() const;
    void drawPlayer() const;
    void drawEnemies() const;
    bool drawStage01BossExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage01MarkerExact(const StageEnemy& enemy, float x, float y) const;
    bool drawType0AExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage01Type0EExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage01Type0FExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage01Type10Or11Exact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage01SmallEnemyExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type19Exact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1AExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1BExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1CExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1DOr1EExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1FExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type20Exact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type21Exact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02BossExact(const StageEnemy& enemy, float x, float y) const;
    void drawStage01BossHud() const;
    void drawStage02BossHud() const;
    void drawEnemyGaugeExact(const StageEnemy& enemy, int mode, float x, float y) const;
    bool drawStage03EnemyExact(const StageEnemy& enemy, float x, float y) const;
    void drawStage03BossHud() const;
    bool drawStage04BossExact(const StageEnemy& enemy, float x, float y) const;
    void drawStage04BossHud() const;
    void drawLateStageBossHud() const;
    void drawSharedBossHud(const StageEnemy& boss, int phaseMode, int maxHp,
                           int countdown, int breaksRemaining,
                           int bossNameIndex) const;
    void drawStageApproach() const;
    void drawStageBannerPanels() const;
    void drawStageBannerText() const;
    const std::vector<int>& localizedBossApproach1Frames() const;
    bool drawStage04EnemyExact(const StageEnemy& enemy, float x, float y) const;
    bool drawLateStageBoss(const StageEnemy& enemy, float x, float y) const;
    bool drawStage07BossNode(const StageEnemy& enemy, float x, float y) const;
    bool drawStage10FinalBossNode(const StageEnemy& enemy, float x, float y) const;
    bool drawLateStageEnemy(const StageEnemy& enemy, float x, float y) const;
    void drawOriginalMode7Node(int handle, float x, float y, std::uint16_t angle16, double scaleX, double scaleY, bool reverseX) const;
    void drawStageEffects(bool foreground, int exactLayer = -1) const;
    void drawProjectiles() const;
    void drawRewardItems() const;
    void drawOverlay() const;
    void drawHudSidebar() const;
    void drawLeftHudPanel() const;
    void drawRightHudPanel() const;
    void drawStateRows() const;
    void drawDreamGauge(int x, int y, int value, int maxValue) const;
    void drawDataWindow2Tokens(int x, int y, int activeCount, int maxCount) const;
    void drawHudStatusIconGroup() const;
    void drawLayoutGuides() const;
    void drawDebugOverlay() const;
    void drawHudNumber(int rightX, int y, int value, const std::vector<int>& digitFrames, int digitWidth, int digitHeight, double scale = 1.0) const;
    void drawNumberWithSeparators(int rightX, int y, int value, const std::vector<int>& digitFrames, int digitWidth, int digitHeight, double scale = 1.0) const;

    void updateLayoutGuideToggle();
    float aimAtPlayer(float x, float y) const;
    static float deterministicUnit(int frame, int salt);
    static bool offscreen(float x, float y, float margin);

    bool initialized_ = false;
    int selectedStage_ = 1;
    StageRuntimeConfig config_;
    int frame_ = 0;
    PlayerState player_;
    std::vector<int> playerFrames_;
    std::vector<int> itemFrames_;
    std::vector<int> enemySmallFrames_;
    std::vector<int> enemyMediumFrames_;
    std::vector<int> enemyLargeFrames_;
    std::vector<int> enemyExtraLargeFrames_;
    std::vector<int> effectSmallFrames_;
    std::vector<int> effectMediumFrames_;
    std::vector<int> effectLargeFrames_;
    int whiteBackHandle_ = -1;
    std::array<int, 8> bombSoundHandles_{{-1, -1, -1, -1, -1, -1, -1, -1}};
    std::array<int, 4> feverSoundHandles_{{-1, -1, -1, -1}};
    int normalShotSoundHandle_ = -1;
    int miss2SoundHandle_ = -1;
    int shotHitSoundHandle_ = -1;
    int shotHit2SoundHandle_ = -1;
    int item1SoundHandle_ = -1;
    int item2SoundHandle_ = -1;
    int item3SoundHandle_ = -1;
    int extendSoundHandle_ = -1;
    int blast1SoundHandle_ = -1;
    int enemyDown1SoundHandle_ = -1;
    int enemyDown2SoundHandle_ = -1;
    int enemyDown3SoundHandle_ = -1;
    int alertSoundHandle_ = -1;
    int blast2SoundHandle_ = -1;
    int bullet1SoundHandle_ = -1;
    int bullet2SoundHandle_ = -1;
    int bossLifeSoundHandle_ = -1;
    int bonusSoundHandle_ = -1;
    int bossApproachSoundHandle_ = -1;
    int bossWeakenSoundHandle_ = -1;
    int timerSoundHandle_ = -1;
    int bossSe1SoundHandle_ = -1;
    int bossSe2SecondSoundHandle_ = -1;
    int bossSe3SoundHandle_ = -1;
    int bossSe4SecondSoundHandle_ = -1;
    int bossSe5SoundHandle_ = -1;
    int bossSe6SoundHandle_ = -1;
    int bossSe7SoundHandle_ = -1;
    int bossSe8SoundHandle_ = -1;
    int bossSe9SoundHandle_ = -1;
    int bossSe14SoundHandle_ = -1;
    int bossSe15SoundHandle_ = -1;
    std::array<int, 10> stageBgmHandles_{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    std::array<int, 5> bossBgmHandles_{{-1, -1, -1, -1, -1}};
    int stage04BgmHandle_ = -1;
    int stage04BossBgmHandle_ = -1;
    int textSoundHandle_ = -1;
    int text2SoundHandle_ = -1;
    std::array<int, 2> bannerFontHandles_{{-1, -1}};
    std::vector<int> enemyGaugeFrames_;
    int enemyGaugeFillHandle_ = -1;
    std::vector<int> bossFrames_;
    std::vector<int> bossApproach1Frames_;
    std::vector<int> bossApproach1Ch1Frames_;
    std::vector<int> bossApproach1Ch2Frames_;
    int bossApproach2Handle_ = -1;
    int stage04PhaseTitleStandHandle_ = -1;
    std::vector<int> bossGaugeFrames_;
    std::vector<int> bossNameFrames_;
    std::vector<int> textBoxFrames_;
    std::vector<int> textIconFrames_;
    std::vector<int> bulletFrames_;
    std::vector<int> stageBack1Frames_;
    std::vector<int> stageBack1bFrames_;
    std::vector<int> stageBack1cFrames_;
    std::vector<int> stageBack1dFrames_;
    std::vector<int> stageBack2Frames_;
    int stage2BackHandle_ = -1;
    int stage3BackHandle_ = -1;
    int stage6BackHandle_ = -1;
    int stage8Back1Handle_ = -1;
    int stage8Back2Handle_ = -1;
    mutable std::array<float, 4> lateBackgroundScroll_{};
    mutable int lateBackgroundScrollFrame_ = -0x3fffffff;
    std::array<int, 6> stage09BossDefeatFrames_{{-1, -1, -1, -1, -1, -1}};
    std::vector<int> stageFrameFrames_;
    std::vector<int> numSmallFrames_;
    std::vector<int> numMediumFrames_;
    std::vector<int> numLargeFrames_;
    int dataWindowHandle_ = -1;
    int timeWindowHandle_ = -1;
    std::vector<int> dataWindow2Frames_;
    std::vector<int> playerFrameFrames_;
    std::vector<int> stateFrames_;
    std::vector<int> dreamGaugeFrames_;
    std::vector<StageEnemy> enemies_;
    std::vector<StageEnemy> pendingEnemies_;
    std::vector<StageProjectile> enemyProjectiles_;
    std::vector<PlayerSideObject> playerSideObjects_;
    std::vector<RewardItem> rewardItems_;
    std::vector<StageEffect> stageEffects_;
    std::array<bool, 11> inputActions_{};
    bool showLayoutGuides_ = false;
    bool prevLayoutGuideToggle_ = false;
    bool paused_ = false;
    bool pauseInputHeld_ = false;
    bool stage01GateFlag_ = false;
    bool stage02GateFlag_ = false;
    bool stage03GateFlag_ = false;
    bool stage04GateFlag_ = false;
    bool stage05GateFlag_ = false;
    bool stage06GateFlag_ = false;
    bool stage07GateFlag_ = false;
    bool stage08GateFlag_ = false;
    bool stage09GateFlag_ = false;
    bool stage10GateFlag_ = false;
    bool stage01EndVisualQueued_ = false;
    bool stage01EndFlushed_ = false;
    bool stage01BossSpawned_ = false;
    int stage01BossPhaseMode_ = 0;
    int stage01BossMaxHp_ = 100000;
    int stage01BossCountdown_ = 0;
    int stage01BossCountdownDraw_ = 0;
    int stage01BossBreaksRemaining_ = 3;
    int stage01BossPhaseIndex_ = 0;
    float stage01BossTargetX_ = 360.0f;
    float stage01BossTargetY_ = 200.0f;
    bool stage01ClearStarted_ = false;
    bool stage01ClearTransition_ = false;
    bool stage01ClearComplete_ = false;
    int stage02BossPhaseMode_ = 0;
    int stage02BossMaxHp_ = 100000;
    int stage02BossCountdown_ = 0;
    int stage02BossCountdownDraw_ = 0;
    int stage02BossBreaksRemaining_ = 4;
    int stage02BossPhaseIndex_ = 0;
    float stage02BossTargetX_ = 360.0f;
    float stage02BossTargetY_ = 180.0f;
    bool stage02ClearStarted_ = false;
    bool stage02ClearTransition_ = false;
    bool stage02ClearComplete_ = false;
    int stage03BossPhaseMode_ = 0;
    int stage03BossMaxHp_ = 100000;
    int stage03BossCountdown_ = 0;
    int stage03BossCountdownDraw_ = 0;
    int stage03BossBreaksRemaining_ = 4;
    int stage03BossPhaseIndex_ = 0;
    float stage03BossTargetX_ = 360.0f;
    float stage03BossTargetY_ = 200.0f;
    bool stage03ClearStarted_ = false;
    bool stage03ClearTransition_ = false;
    bool stage03ClearComplete_ = false;
    int stage04BossPhaseMode_ = 0;
    int stage04BossMaxHp_ = 100000;
    int stage04BossCountdown_ = 0;
    int stage04BossCountdownDraw_ = 0;
    int stage04BossBreaksRemaining_ = 4;
    int stage04BossPhaseIndex_ = 0;
    float stage04BossTargetX_ = 360.0f;
    float stage04BossTargetY_ = 200.0f;
    bool stage04ClearStarted_ = false;
    bool stage04ClearTransition_ = false;
    bool stage04ClearComplete_ = false;
    int earlyStageApproachAgeDraw_ = -1;
    std::array<bool, 11> lateStageClearComplete_{};
    int lateStageApproachAgeDraw_ = -1;
    int lateStageClearTimer_ = 0;
    int lateStageBossPhaseMode_ = 0;
    int lateStageBossPhaseIndex_ = 0;
    int lateStageBossBreaksRemaining_ = 0;
    int lateStageBossCountdown_ = 0;
    int lateStageBossCountdownDraw_ = 0;
    int lateStageBossMaxHp_ = 100000;
    float lateStageBossTargetX_ = 360.0f;
    float lateStageBossTargetY_ = 200.0f;
    int bossPhaseRewardIndex_ = 0;
    int observedBossPhaseMode_ = 0;
    bool lateStageBossSpawned_ = false;
    bool lateStageClearStarted_ = false;
    int activeBossBgmIndex_ = -1;
    bool stage10TransitionStarted_ = false;
    bool stage10FinalBossSpawned_ = false;
    int stage01EndFrame_ = 5700;
    int nextEntityId_ = 1;
};

} // namespace reconstructed
