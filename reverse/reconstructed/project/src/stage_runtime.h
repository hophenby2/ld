#pragma once

#include "resource_manager.h"

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
        int dataWindowEnabled = 1;
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
    int enemiesAlive() const;
    int enemyProjectilesAlive() const;
    bool stageComplete() const { return stage01ClearComplete_; }

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
    void spawnEnemy(const StageSpawnEvent& event);
    void spawnStage01Child(StageEnemy& parent, int childIndex, float offsetX, float offsetY, int hitPoints, const char* note);
    bool spawnStage01BossChild(StageEnemy& parent, int spawnType, int childIndex,
                               float offsetX, float offsetY, int hitPoints, const char* note);
    void spawnStage01MarkerSatellite(StageEnemy& parent, int childIndex, float offsetX, float offsetY, int hitPoints, const char* note);
    void spawnStage02Type21Child(const StageEnemy& parent, int childIndex, float x, float yOffset);
    void spawnStage03Satellite(const StageEnemy& parent, int spawnType, int childIndex,
                               float offsetX, float offsetY, int angle16);
    void spawnStage03Type2FChild(const StageEnemy& parent);
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
    void updateStage01SmallChaser(StageEnemy& enemy, int activeAge, int enterFrames, int trackFrames, int turnStep, int exitTurnStep, double initialSpeed, double floorSpeed = 1.0);
    void updateStage01Setpiece(StageEnemy& enemy, int activeAge);
    void updateStage01Marker(StageEnemy& enemy, int activeAge);
    void updateStage01MarkerSatellite(StageEnemy& enemy, int activeAge);
    void updateStage01Child(StageEnemy& enemy, int activeAge);
    void updateStage01Boss(StageEnemy& enemy);
    void updateStage01BossChild(StageEnemy& enemy);
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
    void spawnStage02DeathExplosionChain(const StageEnemy& enemy);
    void spawnStageEffect(int type, int graphHandle, int graphExtent, int drawLayer,
                          float x, float y, std::uint16_t angle16,
                          double scale0, double scaleX, double scaleY,
                          int lifetime, int colorR, int colorG, int colorB, int alpha);
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
    void updateStage04Enemy(StageEnemy& enemy, int activeAge);
    void emitStage04Projectiles(StageEnemy& enemy, int activeAge);
    void finishStage04CarrierSharedHp(StageEnemy& enemy);
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
    void updateRewardItems();
    int effectiveHelpLevel() const;
    int stockThresholdForCurrentConfig() const;
    void addRunScore(int amount);
    void addSpecialGauge(int amount);
    void collectRewardItem(const RewardItem& item);
    void processStockProgressAfterGain(int progressGain);
    void spawnEnemyDeathRewardBurst(const StageEnemy& enemy, int payoutWindow = 0);
    void updateSpecialGaugeAction();
    void updateSpecialGaugeState();
    bool settlePendingPlayerHit();
    void startEquippedBomb();
    void startFever(bool manualActivation);
    void armManualFever();
    void playPlayerSound(int handle, int volumeMultiplier = 0x19) const;
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
    bool drawType0AExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage01SmallEnemyExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type19Exact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1AExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1BExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1CExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1DOr1EExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type1FExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type20Exact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage02Type21Exact(const StageEnemy& enemy, float x, float y) const;
    void drawEnemyGaugeExact(const StageEnemy& enemy, int mode, float x, float y) const;
    bool drawStage03EnemyExact(const StageEnemy& enemy, float x, float y) const;
    bool drawStage04EnemyExact(const StageEnemy& enemy, float x, float y) const;
    void drawOriginalMode7Node(int handle, float x, float y, std::uint16_t angle16, double scaleX, double scaleY, bool reverseX) const;
    void drawStageEffects(bool foreground) const;
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
    std::vector<int> effectSmallFrames_;
    std::vector<int> effectMediumFrames_;
    std::vector<int> effectLargeFrames_;
    int whiteBackHandle_ = -1;
    std::array<int, 8> bombSoundHandles_{{-1, -1, -1, -1, -1, -1, -1, -1}};
    std::array<int, 4> feverSoundHandles_{{-1, -1, -1, -1}};
    int normalShotSoundHandle_ = -1;
    int shotHitSoundHandle_ = -1;
    int shotHit2SoundHandle_ = -1;
    int item1SoundHandle_ = -1;
    int item3SoundHandle_ = -1;
    int extendSoundHandle_ = -1;
    int blast1SoundHandle_ = -1;
    std::vector<int> enemyGaugeFrames_;
    int enemyGaugeFillHandle_ = -1;
    std::vector<int> bossFrames_;
    std::vector<int> bulletFrames_;
    std::vector<int> stageBack1Frames_;
    std::vector<int> stageBack1bFrames_;
    std::vector<int> stageBack1cFrames_;
    std::vector<int> stageBack1dFrames_;
    std::vector<int> stageBack2Frames_;
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
    bool stage01EndVisualQueued_ = false;
    bool stage01EndFlushed_ = false;
    bool stage01BossSpawned_ = false;
    int stage01BossPhaseMode_ = 0;
    int stage01BossMaxHp_ = 100000;
    int stage01BossCountdown_ = 0;
    int stage01BossBreaksRemaining_ = 3;
    int stage01BossPhaseIndex_ = 0;
    float stage01BossTargetX_ = 360.0f;
    float stage01BossTargetY_ = 200.0f;
    bool stage01ClearStarted_ = false;
    bool stage01ClearTransition_ = false;
    bool stage01ClearComplete_ = false;
    int stage01EndFrame_ = 5700;
    int nextEntityId_ = 1;
};

} // namespace reconstructed
