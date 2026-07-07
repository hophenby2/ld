#pragma once

#include "resource_manager.h"

#include <array>

namespace reconstructed {

class FrontendRuntime {
public:
    enum class MainState {
        TitleMenu = 0x02,
        StageSetup = 0x03,
        StageSelect = 0x04,
        AlternateSetup = 0x05,
        Options = 0x0a,
        Gameplay = 0x14,
    };

    struct GameplayRequest {
        bool requested = false;
        int stage = 1;
        int routeMode = 0;
        int playerOption = 0;
        int subOption = 0;
        int loadoutId = 0;
        int difficulty = 0;
        int counterMode = 0;
        std::array<int, 4> optionSlots{{0, 0, 0, 0}};
    };

    void initialize(ResourceManager& resources);
    void update(ResourceManager& resources);
    void draw(const ResourceManager& resources) const;

    GameplayRequest consumeGameplayRequest();
    MainState state() const { return state_; }
    int cursor() const { return cursor_; }
    int selectedStage() const { return selectedStage_; }

private:
    struct InputSnapshot {
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
        bool confirm = false;
        bool cancel = false;
        bool upRepeat = false;
        bool downRepeat = false;
        bool leftRepeat = false;
        bool rightRepeat = false;
        bool leftRepeatFast = false;
        bool rightRepeatFast = false;
    };

    struct TransitionSpec {
        int commitFrames = 0x3c;
        int wipeDelay = 0x14;
    };

    InputSnapshot readInput();
    static void updateHeldCounter(bool down, int& heldFrames);
    static bool repeatSlow(int heldFrames);
    static bool repeatFast(int heldFrames);
    static bool pressed(int heldFrames);
    TransitionSpec currentTransitionSpec() const;
    void setState(MainState state, int cursor = 0);

    void updateTitleMenu(ResourceManager& resources, const InputSnapshot& input);
    void updateStageSetup(ResourceManager& resources, const InputSnapshot& input);
    void updateStageSelect(ResourceManager& resources, const InputSnapshot& input);
    void updateAlternateSetup(ResourceManager& resources, const InputSnapshot& input);
    void updateOptions(ResourceManager& resources, const InputSnapshot& input);
    void updateTransition(ResourceManager& resources);

    void drawTitleMenu(const ResourceManager& resources) const;
    void drawStageSetup(const ResourceManager& resources) const;
    void drawStageSelect(const ResourceManager& resources) const;
    void drawAlternateSetup(const ResourceManager& resources) const;
    void drawOptions(const ResourceManager& resources) const;
    void drawPlaceholderPanel(const char* title, const char* body) const;
    void drawTransitionOverlay(const ResourceManager& resources) const;

    void playSound(ResourceManager& resources, const char* id) const;
    void ensureTitleBgm(ResourceManager& resources);
    void stopTitleBgm(ResourceManager& resources);
    void beginConfirmTransition(MainState target);
    void beginCancelTransition(MainState target);
    void moveCursor(ResourceManager& resources, int delta, int count);
    void refreshOptionSlots();

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
    int setupToggle_ = 0;
    std::array<int, 4> optionSlots_{{0, 0, 0, 0}};
    int selectedStage_ = 1;
    int stageSetupRow_ = 0;
    int stageRouteIndex_ = 0;
    int stageSubIndex_ = 0;
    int stageBranchToggle_ = 0;
    int stageOverlayState_ = 0;
    int selectedDifficulty_ = 2;
    int counterMode_ = 0;
    std::array<int, 11> maxUnlockedDifficultyByStage_{{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}};
    bool counterUnlocked_ = true;
    bool titleBgmStarted_ = false;
    GameplayRequest gameplayRequest_;

    int upHeldFrames_ = 0;
    int downHeldFrames_ = 0;
    int leftHeldFrames_ = 0;
    int rightHeldFrames_ = 0;
    int confirmHeldFrames_ = 0;
    int cancelHeldFrames_ = 0;
};

} // namespace reconstructed
