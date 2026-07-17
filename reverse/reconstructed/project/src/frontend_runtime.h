#pragma once

#include "resource_manager.h"
#include "save_config.h"

#include <array>
#include <cstdint>
#include <vector>

namespace reconstructed {

class FrontendRuntime {
public:
    enum class MainState {
        TitleMenu = 0x02,
        StageSetup = 0x03,
        StageSelect = 0x04,
        AlternateSetup = 0x05,
        Gallery = 0x06,
        Achievement = 0x07,
        EnemyEncyclopedia = 0x08,
        Manual = 0x09,
        Options = 0x0a,
        OptionAssist = 0x0b,
        ConfigMenu = 0x0c,
        KeyConfig = 0x0d,
        ReplayList = 0x0e,
        ReplayStageSelect = 0x0f,
        ResultSubmit = 0x10,
        Ranking = 0x11,
        RankingNotice = 0x12,
        Gameplay = 0x14,
        ResultSummary = 0x20,
        TrialContinue = 0x22,
        ReplayPrompt = 0x23,
        ReplaySave = 0x24,
    };

    struct GameplayRequest {
        bool requested = false;
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
        bool dataWindowUnlocked = false;
        int language = 0;
        int bgmVolume = 10;
        int soundEffectVolume = 10;
        std::array<int, 7> systemConfig{{0, 0, 1, 0, 1, 0, 0}};
        int itemVisibility = 0;
        int likeStyle = 0;
        std::array<int, 4> optionSlots{{0, 0, 0, 0}};
        std::array<int, 11> keyboardBindings{};
        std::array<int, 11> controllerBindings{};
        int controlDevice = 5;
        int controlModeEnabled = 1;
        int helpMode = 6;
        int helpAutoProgress = 0;
        int rawStartFrame = 0;
        int firstDispatchFrame = 0;
        int initialStock = -1;
        int initialStockProgressSteps = -1;
        int initialSpecialGauge = -1;
        std::int64_t initialBestScore = 0;
        int initialBestTimeFrames = 0;
        bool continueRun = false;
        bool replayPlayback = false;
    };

    struct GameplaySettings {
        int bgmVolume = 10;
        int soundEffectVolume = 10;
        int language = 0;
        int dataWindowEnabled = 1;
        std::array<int, 7> systemConfig{{0, 0, 1, 0, 1, 0, 0}};
        std::array<int, 11> keyboardBindings{};
        std::array<int, 11> controllerBindings{};
        int controlDevice = 5;
        bool saveData = false;
        bool saveSystemConfig = false;
    };

    void initialize(ResourceManager& resources, const SaveConfigState& saveConfigState);
    void update(ResourceManager& resources);
    void draw(const ResourceManager& resources) const;
    void completeGameplay(ResourceManager& resources, std::int64_t score = 0,
                          int elapsedFrames = 0);
    void returnToTitle(ResourceManager& resources);
    void abortGameplay(ResourceManager& resources);
    void skipTutorial(ResourceManager& resources);
    void finishGameOver(ResourceManager& resources, bool replayPrompt,
                        std::int64_t score, int elapsedFrames);
    void applyGameplaySettings(ResourceManager& resources,
                               const GameplaySettings& settings);

    GameplayRequest consumeGameplayRequest();
    MainState state() const { return state_; }
    int cursor() const { return cursor_; }
    int selectedStage() const { return selectedStage_; }
    int frameRateMode() const { return systemConfig_[1]; }

private:
    struct InputSnapshot {
        bool up = false;
        bool down = false;
        bool confirm = false;
        bool cancel = false;
        bool upRepeat = false;
        bool downRepeat = false;
        bool leftRepeat = false;
        bool rightRepeat = false;
        bool anyAction = false;
    };

    struct TransitionSpec {
        int commitFrames = 0x3c;
        int wipeDelay = 0x14;
    };

    struct ReplaySlot {
        bool valid = false;
        std::array<char, 4> tag{{'-', '-', '-', '\0'}};
        int timestamp = 0;
        int mode = 0;
        int submode = 0;
        int checkpoint = 1;
        int maximumStage = 1;
        long long score = 0;
    };

    InputSnapshot readInput();
    void resetInputCounters();
    static void updateHeldCounter(bool down, int& heldFrames);
    static bool repeatSlow(int heldFrames);
    static bool pressed(int heldFrames);
    TransitionSpec currentTransitionSpec() const;
    void setState(MainState state, int cursor = 0);

    void updateTitleMenu(ResourceManager& resources, const InputSnapshot& input);
    void updateStageSetup(ResourceManager& resources, const InputSnapshot& input);
    void updateStageSelect(ResourceManager& resources, const InputSnapshot& input);
    void updateAlternateSetup(ResourceManager& resources, const InputSnapshot& input);
    void updateGallery(ResourceManager& resources, const InputSnapshot& input);
    void updateAchievement(ResourceManager& resources, const InputSnapshot& input);
    void updateEnemyEncyclopedia(ResourceManager& resources, const InputSnapshot& input);
    void updateManual(ResourceManager& resources, const InputSnapshot& input);
    void updateOptions(ResourceManager& resources, const InputSnapshot& input);
    void updateOptionAssist(ResourceManager& resources, const InputSnapshot& input);
    void updateConfigMenu(ResourceManager& resources, const InputSnapshot& input);
    void updateKeyConfig(ResourceManager& resources, const InputSnapshot& input);
    void updateReplayList(ResourceManager& resources, const InputSnapshot& input);
    void updateReplayStageSelect(ResourceManager& resources, const InputSnapshot& input);
    void updateResultSubmit(ResourceManager& resources, const InputSnapshot& input);
    void updateRanking(ResourceManager& resources, const InputSnapshot& input);
    void updateRankingNotice(ResourceManager& resources, const InputSnapshot& input);
    void updateResultSummary(ResourceManager& resources, const InputSnapshot& input);
    void updateTrialContinue(ResourceManager& resources, const InputSnapshot& input);
    void updateReplayPrompt(ResourceManager& resources, const InputSnapshot& input);
    void updateReplaySave(ResourceManager& resources, const InputSnapshot& input);
    void updateTransition(ResourceManager& resources);

    void drawTitleMenu(const ResourceManager& resources) const;
    void drawStageSetup(const ResourceManager& resources) const;
    void drawStageSelect(const ResourceManager& resources) const;
    void drawAlternateSetup(const ResourceManager& resources) const;
    void drawGallery(const ResourceManager& resources) const;
    void drawAchievement(const ResourceManager& resources) const;
    void drawEnemyEncyclopedia(const ResourceManager& resources) const;
    void drawManual(const ResourceManager& resources) const;
    void drawOptions(const ResourceManager& resources) const;
    void drawOptionAssist(const ResourceManager& resources) const;
    void drawConfigMenu(const ResourceManager& resources) const;
    void drawKeyConfig(const ResourceManager& resources) const;
    void drawReplayList(const ResourceManager& resources) const;
    void drawReplayStageSelect(const ResourceManager& resources) const;
    void drawResultSubmit(const ResourceManager& resources) const;
    void drawRanking(const ResourceManager& resources) const;
    void drawRankingNotice(const ResourceManager& resources) const;
    void drawResultSummary(const ResourceManager& resources) const;
    void drawTrialContinue(const ResourceManager& resources) const;
    void drawReplayPrompt(const ResourceManager& resources) const;
    void drawReplaySave(const ResourceManager& resources) const;
    void drawTransitionOverlay(const ResourceManager& resources) const;

    void loadSaveBackedState(const SaveConfigState& saveConfigState);
    void saveFrontendState(const ResourceManager& resources) const;
    void saveSystemConfig(const ResourceManager& resources) const;
    void refreshEnemyEncyclopediaAvailability();
    void loadMissingFrontendGraphs(ResourceManager& resources);
    void ensureGalleryGraphs(ResourceManager& resources) const;
    void ensureAchievementGraphs(ResourceManager& resources) const;
    void ensureEnemyEncyclopediaGraphs(ResourceManager& resources) const;
    void ensureManualGraphs(ResourceManager& resources) const;
    void ensureRankingGraphs(ResourceManager& resources) const;
    void ensureResultGraphs(ResourceManager& resources) const;
    void scanReplaySlots(const ResourceManager& resources);
    void playSound(ResourceManager& resources, const char* id) const;
    void ensureTitleBgm(ResourceManager& resources);
    void restartTitleBgm(ResourceManager& resources);
    void stopTitleBgm(ResourceManager& resources);
    void stopAllBgm(ResourceManager& resources);
    void startResultBgm(ResourceManager& resources);
    void stopResultBgm(ResourceManager& resources);
    void beginConfirmTransition(MainState target);
    void beginCancelTransition(MainState target);
    void moveCursor(ResourceManager& resources, int delta, int count);
    void refreshOptionSlots();
    void queueGameplayRequest(bool continueRun = false,
                              bool manualTrialContinue = false,
                              bool replayPlayback = false);
    int resultHelpLevel() const;
    bool shouldPromptResultSubmit() const;

    MainState state_ = MainState::TitleMenu;
    MainState pendingState_ = MainState::TitleMenu;
    int cursor_ = 0;
    int frame_ = 0;
    int transitionTimer_ = 0;
    int transitionDirection_ = 0;
    int selectionDirtyTimer_ = 0;
    int routeMode_ = 0;
    int playerOption_ = 0;
    int subOption_ = 0;
    int loadoutId_ = 0;
    int feverMode_ = 0;
    std::array<int, 4> optionSlots_{{0, 0, 0, 0}};
    std::array<std::array<int, 4>, 3> setupOptionsByGroup_{{
        {{0, 0, 0, 0}},
        {{0, 0, 0, 0}},
        {{0, 0, 0, 0}},
    }};
    int setupGroup_ = 0;
    int previousSetupCursor_ = 0;
    int selectedStage_ = 1;
    int stageOverlayState_ = 0;
    int stageLayerTransitionTimer_ = 0;
    int stageDifficultyAnimationTimer_ = 0;
    int stageCounterAnimationTimer_ = 0;
    int selectedDifficulty_ = 2;
    int counterMode_ = 0;
    std::array<int, 15> maxUnlockedDifficultyByStage_{{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};
    std::array<int, 2> savedStageByRoute_{{1, 11}};
    std::array<int, 2> maxUnlockedStageByRoute_{{1, 11}};
    std::array<int, 8> practiceOptions_{{1, 2, 0, 0, 0, 0, 0, 0}};
    float stageCameraX_ = 0.0f;
    float stageCameraY_ = 0.0f;
    float stageCameraStartX_ = 0.0f;
    float stageCameraStartY_ = 0.0f;
    int stageCameraTimer_ = 0;
    int bgmVolume_ = 10;
    int seVolume_ = 10;
    int language_ = 0;
    int dataWindowEnabled_ = 1;
    bool counterUnlocked_ = true;
    bool dataWindowUnlocked_ = false;
    bool shortcutUnlocked_ = false;
    bool trialUnlocked_ = false;
    bool trialExtraUnlocked_ = false;
    bool titleBgmStarted_ = false;
    std::array<int, 20> galleryUnlocked_{};
    std::array<int, 20> galleryViewed_{};
    std::array<int, 50> achievementUnlocked_{};
    std::array<int, 50> achievementViewed_{};
    std::array<int, 104> enemyUnlocked_{};
    std::array<int, 11> enemyStageStatus_{};
    int enemySequentialProgress_ = 0;
    int enemyMaximum_ = 10;
    bool galleryExpanded_ = false;
    bool galleryClosing_ = false;
    int galleryExpandTimer_ = 0;
    int controlModeEnabled_ = 1;
    int helpMode_ = 6;
    std::array<int, 7> systemConfig_{{0, 0, 1, 0, 1, 0, 0}};
    std::array<int, 11> keyBindings_{};
    std::array<int, 11> controllerBindings_{};
    int controlDevice_ = 5;
    bool keyCaptureActive_ = false;
    int keyCaptureDelay_ = 0;
    std::array<ReplaySlot, 24> replaySlots_{};
    int replaySlotIndex_ = 0;
    int replayStageChoice_ = 1;
    int rankingCursor_ = 0;
    int rankingValue_ = 0;
    std::int64_t resultScore_ = 0;
    int resultElapsedFrames_ = 0;
    int resultNextStage_ = 1;
    int resultPhase_ = 0;
    int resultPhaseTransitionTimer_ = 0;
    int resultRouteCompletion_ = 0;
    bool resultBgmStarted_ = false;
    std::vector<std::uint8_t> saveBackingBytes_;
    GameplayRequest gameplayRequest_;

    int upHeldFrames_ = 0;
    int downHeldFrames_ = 0;
    int leftHeldFrames_ = 0;
    int rightHeldFrames_ = 0;
    int confirmHeldFrames_ = 0;
    int cancelHeldFrames_ = 0;
};

} // namespace reconstructed
