#include "frontend_runtime.h"

#include "reconstruction_notes.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>

namespace reconstructed {
namespace {

constexpr int kTransitionFrames = 60;
constexpr int kTitleMenuCount = 9;
constexpr int kStageSetupRows = 7;
constexpr int kAlternateRows = 10;
constexpr int kOptionsRows = 9;
constexpr std::array<int, 3> kSelectableStages{{1, 2, 4}};
constexpr float kPi = 3.14159265358979323846f;

const char* titleRowLabel(int index) {
    constexpr std::array<const char*, kTitleMenuCount> labels{{
        "Start route 0", "Start route 1", "Start route 2", "Replay", "Extra branch",
        "Gallery", "System branch", "Options", "Back / Exit",
    }};
    return index >= 0 && index < static_cast<int>(labels.size()) ? labels[static_cast<std::size_t>(index)] : "Unknown";
}

const char* stateName(FrontendRuntime::MainState state) {
    switch (state) {
    case FrontendRuntime::MainState::TitleMenu: return "0x02 title/main menu";
    case FrontendRuntime::MainState::StageSetup: return "0x03 stage setup";
    case FrontendRuntime::MainState::StageSelect: return "0x04 stage select";
    case FrontendRuntime::MainState::AlternateSetup: return "0x05 alternate setup";
    case FrontendRuntime::MainState::Options: return "0x0a options";
    case FrontendRuntime::MainState::Gameplay: return "0x14 gameplay handoff";
    }
    return "unknown";
}

} // namespace

void FrontendRuntime::initialize(ResourceManager& resources) {
    state_ = MainState::TitleMenu;
    pendingState_ = state_;
    cursor_ = 0;
    frame_ = 0;
    transitionTimer_ = 0;
    transitionDirection_ = 0;
    selectionDirtyTimer_ = 0;
    routeMode_ = 0;
    selectedStage_ = 1;
    stageSetupRow_ = 0;
    gameplayRequest_ = {};
    ensureTitleBgm(resources);
}

void FrontendRuntime::update(ResourceManager& resources) {
    ++frame_;
    if (selectionDirtyTimer_ > 0) {
        --selectionDirtyTimer_;
    }
    if (transitionTimer_ != 0) {
        updateTransition(resources);
        return;
    }

    auto input = readInput();
    switch (state_) {
    case MainState::TitleMenu: updateTitleMenu(resources, input); break;
    case MainState::StageSetup: updateStageSetup(resources, input); break;
    case MainState::StageSelect: updateStageSelect(resources, input); break;
    case MainState::AlternateSetup: updateAlternateSetup(resources, input); break;
    case MainState::Options: updateOptions(resources, input); break;
    case MainState::Gameplay: break;
    }
}

void FrontendRuntime::draw(const ResourceManager& resources) const {
    switch (state_) {
    case MainState::TitleMenu: drawTitleMenu(resources); break;
    case MainState::StageSetup: drawStageSetup(resources); break;
    case MainState::StageSelect: drawStageSelect(resources); break;
    case MainState::AlternateSetup: drawAlternateSetup(resources); break;
    case MainState::Options: drawOptions(resources); break;
    case MainState::Gameplay: break;
    }
    drawTransitionOverlay(resources);
}

FrontendRuntime::GameplayRequest FrontendRuntime::consumeGameplayRequest() {
    auto request = gameplayRequest_;
    gameplayRequest_ = {};
    return request;
}

FrontendRuntime::InputSnapshot FrontendRuntime::readInput() {
    InputSnapshot input;
    input.up = keyPressed(KEY_INPUT_UP, prevUp_);
    input.down = keyPressed(KEY_INPUT_DOWN, prevDown_);
    input.left = keyPressed(KEY_INPUT_LEFT, prevLeft_);
    input.right = keyPressed(KEY_INPUT_RIGHT, prevRight_);
    const bool confirmA = keyPressed(KEY_INPUT_Z, prevConfirmA_);
    const bool confirmB = keyPressed(KEY_INPUT_RETURN, prevConfirmB_);
    input.confirm = confirmA || confirmB;
    const bool cancelA = keyPressed(KEY_INPUT_X, prevCancelA_);
    const bool cancelB = keyPressed(KEY_INPUT_BACK, prevCancelB_);
    input.cancel = cancelA || cancelB;
    return input;
}

void FrontendRuntime::refreshOptionSlots() {
    optionSlots_ = {{routeMode_, playerOption_, subOption_, loadoutId_}};
}

bool FrontendRuntime::keyPressed(int key, bool& previous) const {
    const bool down = CheckHitKey(key) != 0;
    const bool pressed = down && !previous;
    previous = down;
    return pressed;
}

void FrontendRuntime::setState(MainState state, int cursor) {
    state_ = state;
    pendingState_ = state;
    cursor_ = cursor;
    frame_ = 0;
    transitionTimer_ = 0;
    transitionDirection_ = 0;
    selectionDirtyTimer_ = 0;
}

void FrontendRuntime::updateTitleMenu(ResourceManager& resources, const InputSnapshot& input) {
    ensureTitleBgm(resources);
    if (input.up) {
        moveCursor(resources, -1, kTitleMenuCount);
    }
    if (input.down) {
        moveCursor(resources, 1, kTitleMenuCount);
    }
    if (input.cancel) {
        cursor_ = 8;
        selectionDirtyTimer_ = 12;
        playSound(resources, "SE_se_Cancel");
        return;
    }
    if (!input.confirm) {
        return;
    }

    if (cursor_ >= 0 && cursor_ <= 2) {
        routeMode_ = cursor_;
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::StageSetup);
    }
    else if (cursor_ == 7) {
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::Options);
    }
    else if (cursor_ == 8) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::TitleMenu);
    }
    else {
        playSound(resources, "SE_se_Error");
    }
}

void FrontendRuntime::updateStageSetup(ResourceManager& resources, const InputSnapshot& input) {
    if (input.up) {
        moveCursor(resources, -1, kStageSetupRows);
        stageSetupRow_ = cursor_;
    }
    if (input.down) {
        moveCursor(resources, 1, kStageSetupRows);
        stageSetupRow_ = cursor_;
    }
    if (input.left || input.right) {
        const int delta = input.right ? 1 : -1;
        if (cursor_ == 0) {
            routeMode_ = (routeMode_ + (input.right ? 1 : 2)) % 3;
            refreshOptionSlots();
            playSound(resources, "SE_se_Switch");
        }
        else if (cursor_ == 1) {
            playerOption_ = playerOption_ == 0 ? 1 : 0;
            refreshOptionSlots();
            playSound(resources, "SE_se_Switch");
        }
        else if (cursor_ == 2) {
            subOption_ = subOption_ == 0 ? 1 : 0;
            refreshOptionSlots();
            playSound(resources, "SE_se_Switch");
        }
        else if (cursor_ == 3) {
            loadoutId_ = (loadoutId_ + delta + 7) % 7;
            refreshOptionSlots();
            playSound(resources, "SE_se_Switch");
        }
        else if (cursor_ == 4) {
            auto it = std::find(kSelectableStages.begin(), kSelectableStages.end(), selectedStage_);
            int index = it == kSelectableStages.end() ? 0 : static_cast<int>(it - kSelectableStages.begin());
            index = (index + (input.right ? 1 : static_cast<int>(kSelectableStages.size()) - 1)) % static_cast<int>(kSelectableStages.size());
            selectedStage_ = kSelectableStages[static_cast<std::size_t>(index)];
            playSound(resources, "SE_se_Switch");
        }
    }
    if (input.cancel) {
        if (cursor_ == 0) {
            playSound(resources, "SE_se_Cancel");
            beginCancelTransition(MainState::TitleMenu);
        }
        else {
            --cursor_;
            stageSetupRow_ = cursor_;
            playSound(resources, "SE_se_Cancel");
        }
        return;
    }
    if (input.confirm) {
        if (cursor_ < kStageSetupRows - 1) {
            ++cursor_;
            stageSetupRow_ = cursor_;
            selectionDirtyTimer_ = 10;
            playSound(resources, "SE_se_Enter");
        }
        else {
            refreshOptionSlots();
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(routeMode_ == 2 ? MainState::AlternateSetup : MainState::StageSelect);
        }
    }
}

void FrontendRuntime::updateStageSelect(ResourceManager& resources, const InputSnapshot& input) {
    if (input.left || input.right) {
        auto it = std::find(kSelectableStages.begin(), kSelectableStages.end(), selectedStage_);
        int index = it == kSelectableStages.end() ? 0 : static_cast<int>(it - kSelectableStages.begin());
        index = (index + (input.right ? 1 : static_cast<int>(kSelectableStages.size()) - 1)) % static_cast<int>(kSelectableStages.size());
        selectedStage_ = kSelectableStages[static_cast<std::size_t>(index)];
        selectionDirtyTimer_ = 10;
        playSound(resources, "SE_se_Select");
    }
    if (input.cancel) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::StageSetup);
    }
    if (input.confirm) {
        playSound(resources, "SE_se_Enter");
        stopTitleBgm(resources);
        beginConfirmTransition(MainState::Gameplay);
    }
}

void FrontendRuntime::updateAlternateSetup(ResourceManager& resources, const InputSnapshot& input) {
    if (input.up) moveCursor(resources, -1, kAlternateRows);
    if (input.down) moveCursor(resources, 1, kAlternateRows);
    if (input.cancel || (input.confirm && cursor_ == 9)) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::StageSetup);
        return;
    }
    if (input.confirm && cursor_ == 8) {
        selectedStage_ = 4;
        playSound(resources, "SE_se_Enter");
        stopTitleBgm(resources);
        beginConfirmTransition(MainState::Gameplay);
        return;
    }
    if (input.confirm) {
        playSound(resources, "SE_se_Switch");
    }
}

void FrontendRuntime::updateOptions(ResourceManager& resources, const InputSnapshot& input) {
    if (input.up) moveCursor(resources, -1, kOptionsRows);
    if (input.down) moveCursor(resources, 1, kOptionsRows);
    if (input.cancel || (input.confirm && cursor_ == 8)) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::TitleMenu);
        return;
    }
    if (input.confirm) {
        playSound(resources, cursor_ >= 4 && cursor_ <= 6 ? "SE_se_Enter" : "SE_se_Error");
    }
}

void FrontendRuntime::updateTransition(ResourceManager&) {
    transitionTimer_ += transitionDirection_;
    if (transitionDirection_ > 0 && transitionTimer_ >= kTransitionFrames) {
        const auto target = pendingState_;
        setState(target, 0);
        if (target == MainState::Gameplay) {
            gameplayRequest_ = {true, selectedStage_, routeMode_, playerOption_, subOption_, loadoutId_, optionSlots_};
        }
    }
    else if (transitionDirection_ < 0 && transitionTimer_ <= -kTransitionFrames) {
        setState(pendingState_, 0);
    }
}

void FrontendRuntime::drawTitleMenu(const ResourceManager& resources) const {
    const int titleBack = resources.graphHandleById("GFX_system_TitleBack");
    const int titleLogo = resources.graphHandleById("GFX_system_TitleLogo");
    if (titleBack != -1) {
        DrawGraph(0, 0, titleBack, TRUE);
    }
    else {
        DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(18, 22, 42), TRUE);
    }

    // Original state 0x02 queues TitleLogo through FUN_1400c8410 with an x
    // anchor at the screen center constant. DrawGraph uses top-left coords, so
    // this centers the 500x320 logo while keeping the decompiled y intro motion
    // approximated by a short sine settle during the first 60 frames.
    if (titleLogo != -1) {
        const double intro = frame_ < 60 ? std::sin(static_cast<double>(frame_) * kPi / 120.0) : 1.0;
        const int logoY = notes::title_layout::kLogoBaseY + static_cast<int>((1.0 - intro) * 36.0);
        DrawGraph(notes::title_layout::kLogoX, logoY, titleLogo, TRUE);
    }

    // Original title menu draws the selected TitleMenu frame plus two wrapped
    // neighbours in each direction. Neighbour alpha follows (3-distance)*0x40;
    // the selected frame uses the unlock/transition-dependent alpha.
    constexpr int centerX = notes::title_layout::kMenuSelectedX;
    constexpr int centerY = notes::title_layout::kMenuSelectedY;
    for (int distance = 2; distance >= -2; --distance) {
        const int index = (cursor_ + distance + kTitleMenuCount) % kTitleMenuCount;
        const int handle = resources.graphFrameById("GFX_system_TitleMenu", index);
        const bool selected = distance == 0;
        int alpha = selected ? 255 : (3 - std::abs(distance)) * 0x40;
        if (transitionTimer_ != 0 && selected) {
            alpha = 0x60;
        }
        const int x = centerX + distance * notes::title_layout::kMenuNeighborStepX;
        const int y = centerY + distance * notes::title_layout::kMenuNeighborStepY;
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        if (handle != -1) {
            DrawGraph(x, y, handle, TRUE);
        }
        else {
            DrawFormatString(x, y + 18, GetColor(255, 255, 255), "%s", titleRowLabel(index));
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

        if (selected) {
            const int sub = resources.graphFrameById("GFX_system_TitleMenu2", index);
            if (sub != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
                DrawGraph(notes::title_layout::kMenu2X, y + notes::title_layout::kMenu2YOffset, sub, TRUE);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
    }
}

void FrontendRuntime::drawStageSetup(const ResourceManager& resources) const {
    drawTitleMenu(resources);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
    DrawBox(120, 128, 1160, 620, GetColor(0, 0, 0), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    DrawString(148, 150, "Stage setup/loadout candidate (state 0x03)", GetColor(255, 240, 128));
    constexpr std::array<const char*, kStageSetupRows> rows{{
        "Route / player group", "Player option/type", "Suboption", "Loadout / shot id", "Stage", "Option slots preview", "Start",
    }};
    for (int i = 0; i < static_cast<int>(rows.size()); ++i) {
        const int color = i == cursor_ ? GetColor(255, 240, 128) : GetColor(230, 230, 230);
        DrawFormatString(180, 205 + i * 44, color, "%s%s", i == cursor_ ? "> " : "  ", rows[static_cast<std::size_t>(i)]);
    }
    DrawFormatString(560, 205, GetColor(210, 210, 210), "%d", routeMode_);
    DrawFormatString(560, 205 + 44, GetColor(210, 210, 210), "%d", playerOption_);
    DrawFormatString(560, 205 + 2 * 44, GetColor(210, 210, 210), "%d", subOption_);
    DrawFormatString(560, 205 + 3 * 44, GetColor(210, 210, 210), "%d", loadoutId_);
    DrawFormatString(560, 205 + 4 * 44, GetColor(210, 210, 210), "%02d", selectedStage_);
    DrawFormatString(560, 205 + 5 * 44, GetColor(210, 210, 210), "[%d %d %d %d]",
                     optionSlots_[0], optionSlots_[1], optionSlots_[2], optionSlots_[3]);
    DrawString(148, 560, "Evidence: route/player/sub/loadout fields mirror DAT_140e445c0, DAT_140e44194, DAT_140e41b70, DAT_140e44198.", GetColor(180, 180, 180));
}

void FrontendRuntime::drawStageSelect(const ResourceManager& resources) const {
    const int titleBack = resources.graphHandleById("GFX_system_TitleBack");
    if (titleBack != -1) {
        DrawGraph(0, 0, titleBack, TRUE);
    }
    else {
        DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(12, 16, 34), TRUE);
    }
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
    DrawBox(160, 130, 1120, 590, GetColor(0, 0, 0), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    DrawString(190, 160, "Stage select candidate (state 0x04)", GetColor(255, 240, 128));
    DrawFormatString(220, 250, GetColor(255, 255, 255), "Selected Stage: %02d", selectedStage_);
    DrawString(220, 300, "Left/Right changes currently reconstructed slices: 01 / 02 / 04", GetColor(210, 210, 210));
    DrawString(220, 340, "Z/Enter starts StageRuntime, X/Back returns to setup.", GetColor(210, 210, 210));
    DrawString(190, 535, "Evidence: state 0x04 is normal pre-gameplay/stage selection before 0x14/0x15 gameplay.", GetColor(180, 180, 180));
}

void FrontendRuntime::drawAlternateSetup(const ResourceManager& resources) const {
    drawTitleMenu(resources);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
    DrawBox(140, 120, 1140, 620, GetColor(0, 0, 0), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    DrawString(170, 145, "Alternate setup candidate (state 0x05)", GetColor(255, 240, 128));
    for (int i = 0; i < kAlternateRows; ++i) {
        const int color = i == cursor_ ? GetColor(255, 240, 128) : GetColor(230, 230, 230);
        const char* label = i == 8 ? "Start alternate route" : (i == 9 ? "Back" : "Candidate option");
        DrawFormatString(200, 200 + i * 34, color, "%s%02d  %s", i == cursor_ ? "> " : "  ", i, label);
    }
    DrawString(170, 565, "Approximation: row 8 starts Stage 04 slice, row 9 returns to state 0x03.", GetColor(180, 180, 180));
}

void FrontendRuntime::drawOptions(const ResourceManager& resources) const {
    drawTitleMenu(resources);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
    DrawBox(140, 120, 1140, 620, GetColor(0, 0, 0), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    DrawString(170, 145, "Options candidate (state 0x0a)", GetColor(255, 240, 128));
    constexpr std::array<const char*, kOptionsRows> rows{{
        "BGM volume", "SE volume", "Language", "Toggle", "Submenu A", "Config", "Key config", "Start shortcut", "Back",
    }};
    for (int i = 0; i < static_cast<int>(rows.size()); ++i) {
        const int color = i == cursor_ ? GetColor(255, 240, 128) : GetColor(230, 230, 230);
        DrawFormatString(200, 200 + i * 38, color, "%s%s", i == cursor_ ? "> " : "  ", rows[static_cast<std::size_t>(i)]);
    }
    DrawString(170, 565, "Placeholder: exact config/key-binding fields need further Ghidra/save-offset mapping.", GetColor(180, 180, 180));
}

void FrontendRuntime::drawPlaceholderPanel(const char* title, const char* body) const {
    DrawBox(160, 160, 1120, 560, GetColor(0, 0, 0), TRUE);
    DrawString(190, 190, title, GetColor(255, 240, 128));
    DrawString(190, 240, body, GetColor(230, 230, 230));
}

void FrontendRuntime::drawTransitionOverlay(const ResourceManager&) const {
    if (transitionTimer_ == 0) {
        return;
    }

    // Title state 0x02 starts the outgoing tile wipe after transitionTimer > 0x13
    // and commits at 0x3c. Use the same timing window here; the exact tile-grid
    // helper is still represented by a fade approximation until FUN_1400d3fd0 is
    // fully transcribed.
    const int raw = std::abs(transitionTimer_);
    const int delayed = std::max(0, raw - 0x14);
    if (delayed == 0) {
        return;
    }
    const int alpha = std::min(220, delayed * 220 / (kTransitionFrames - 0x14));
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(255, 255, 255), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void FrontendRuntime::playSound(ResourceManager& resources, const char* id) const {
    const int handle = resources.soundHandleById(id);
    if (handle != -1) {
        PlaySoundMem(handle, DX_PLAYTYPE_BACK, TRUE);
    }
}

void FrontendRuntime::ensureTitleBgm(ResourceManager& resources) {
    if (titleBgmStarted_) {
        return;
    }
    const int handle = resources.soundHandleById("BGM_bgm_Title");
    if (handle != -1) {
        PlaySoundMem(handle, DX_PLAYTYPE_LOOP, FALSE);
        titleBgmStarted_ = true;
    }
}

void FrontendRuntime::stopTitleBgm(ResourceManager& resources) {
    const int handle = resources.soundHandleById("BGM_bgm_Title");
    if (handle != -1) {
        StopSoundMem(handle);
    }
    titleBgmStarted_ = false;
}

void FrontendRuntime::beginConfirmTransition(MainState target) {
    pendingState_ = target;
    transitionDirection_ = 1;
    transitionTimer_ = 1;
}

void FrontendRuntime::beginCancelTransition(MainState target) {
    pendingState_ = target;
    transitionDirection_ = -1;
    transitionTimer_ = -1;
}

void FrontendRuntime::moveCursor(ResourceManager& resources, int delta, int count) {
    cursor_ = (cursor_ + delta + count) % count;
    selectionDirtyTimer_ = 10;
    playSound(resources, "SE_se_Select");
}

} // namespace reconstructed
