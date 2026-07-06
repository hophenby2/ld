#pragma once

#include "resource_manager.h"

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
    };

    InputSnapshot readInput();
    bool keyPressed(int key, bool& previous) const;
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

    MainState state_ = MainState::TitleMenu;
    MainState pendingState_ = MainState::TitleMenu;
    int cursor_ = 0;
    int frame_ = 0;
    int transitionTimer_ = 0;
    int transitionDirection_ = 0;
    int selectionDirtyTimer_ = 0;
    int routeMode_ = 0;
    int selectedStage_ = 1;
    int stageSetupRow_ = 0;
    bool titleBgmStarted_ = false;
    GameplayRequest gameplayRequest_;

    bool prevUp_ = false;
    bool prevDown_ = false;
    bool prevLeft_ = false;
    bool prevRight_ = false;
    bool prevConfirmA_ = false;
    bool prevConfirmB_ = false;
    bool prevCancelA_ = false;
    bool prevCancelB_ = false;
};

} // namespace reconstructed
