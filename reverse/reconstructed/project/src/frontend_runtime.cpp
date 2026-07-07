#include "frontend_runtime.h"

#include "reconstruction_notes.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>

namespace reconstructed {
namespace {

constexpr int kTitleMenuCount = 9;
constexpr int kStageSetupRows = 7;
constexpr int kAlternateRows = 10;
constexpr int kOptionsRows = 9;
constexpr std::array<int, 3> kSelectableStages{{1, 2, 4}};
constexpr float kPi = 3.14159265358979323846f;

struct StageSelectApproxNode {
    int stage = 1;
    notes::PointI center{};
};

int wrapIndex(int value, int count) {
    if (count <= 0) {
        return 0;
    }
    value %= count;
    return value < 0 ? value + count : value;
}

int selectableStageIndex(int stage) {
    auto it = std::find(kSelectableStages.begin(), kSelectableStages.end(), stage);
    return it == kSelectableStages.end() ? 0 : static_cast<int>(it - kSelectableStages.begin());
}

int equipMenuFrameForSetupRow(int row, int routeMode, const std::array<int, 4>& optionSlots, int setupToggle) {
    // State 0x03 indexes DAT_140e46a40 from route and four setup globals.
    // The status frame and toggle/start rows are evidence-backed; option-slot
    // rows remain isolated here until DAT_14053 table semantics are fully decoded.
    switch (row) {
    case 0: return wrapIndex(routeMode, notes::ui_resource_evidence::kEquipMenuFrames);
    case 1: return wrapIndex(4 + routeMode * 4 + optionSlots[0], notes::ui_resource_evidence::kEquipMenuFrames);
    case 2: return wrapIndex(8 + routeMode * 4 + optionSlots[1], notes::ui_resource_evidence::kEquipMenuFrames);
    case 3: return wrapIndex(0x12 + optionSlots[2], notes::ui_resource_evidence::kEquipMenuFrames);
    case 4: return wrapIndex(0x14 + optionSlots[3], notes::ui_resource_evidence::kEquipMenuFrames);
    case 5: return setupToggle == 0 ? 0x17 : 0x1d;
    default: return 0x16;
    }
}

int statusEquipMenuFrameForRoute(int routeMode) {
    // state_03 uses DAT_140e445c0 + 0x18 for the right/status EquipMenu handle.
    return wrapIndex(0x18 + routeMode, notes::ui_resource_evidence::kEquipMenuFrames);
}

int standFrameForSetup(int routeMode, const std::array<int, 4>& optionSlots) {
    // Provisional visual selection. Evidence confirms Stand.png and y positions,
    // but local_1ec/frame table semantics still require DAT_14053 decoding.
    return wrapIndex(routeMode * 10 + optionSlots[0] * 4 + optionSlots[1] * 2 + optionSlots[2], notes::ui_resource_evidence::kStandFrames);
}

int textIconFrameForSetup(int row, int routeMode) {
    return wrapIndex(routeMode * 4 + row, notes::ui_resource_evidence::kTextIconFrames);
}

int approxStageFrame2ForStage(int stage) {
    return wrapIndex(stage - 1, notes::ui_resource_evidence::kStageFrame2Frames);
}

int approxMapMenuFrameForStage(int stage) {
    return wrapIndex(stage - 1, notes::ui_resource_evidence::kMapMenuFrames);
}

int approxMapMenu2FrameForStage(int stage, int routeMode) {
    return wrapIndex((stage - 1) + routeMode * 3, notes::ui_resource_evidence::kMapMenu2Frames);
}

void drawFrameAlpha(const ResourceManager& resources, const char* id, int frame, int x, int y, int alpha) {
    const int handle = resources.graphFrameById(id, frame);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    if (handle != -1) {
        DrawGraph(x, y, handle, TRUE);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void drawFrameScaledAlpha(const ResourceManager& resources, const char* id, int frame, float cx, float cy, double scale, int alpha) {
    const int handle = resources.graphFrameById(id, frame);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    if (handle != -1) {
        DrawRotaGraphF(cx, cy, scale, 0.0, handle, TRUE);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void drawNumSmall(const ResourceManager& resources, int x, int y, int value, double scale = 1.0) {
    value = std::max(0, value);
    const int tens = value / 10;
    const int ones = value % 10;
    if (value >= 10) {
        drawFrameScaledAlpha(resources, "GFX_system_Num_s", tens, static_cast<float>(x), static_cast<float>(y), scale, 255);
    }
    drawFrameScaledAlpha(resources, "GFX_system_Num_s", ones, static_cast<float>(x + (value >= 10 ? 18 : 0)), static_cast<float>(y), scale, 255);
}

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
    playerOption_ = 0;
    subOption_ = 0;
    loadoutId_ = 0;
    setupToggle_ = 0;
    optionSlots_ = {{0, 0, 0, 0}};
    selectedStage_ = 1;
    stageSetupRow_ = 0;
    stageRouteIndex_ = 0;
    stageSubIndex_ = 0;
    stageBranchToggle_ = 0;
    stageOverlayState_ = 0;
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
    updateHeldCounter(CheckHitKey(KEY_INPUT_UP) != 0, upHeldFrames_);
    updateHeldCounter(CheckHitKey(KEY_INPUT_DOWN) != 0, downHeldFrames_);
    updateHeldCounter(CheckHitKey(KEY_INPUT_LEFT) != 0, leftHeldFrames_);
    updateHeldCounter(CheckHitKey(KEY_INPUT_RIGHT) != 0, rightHeldFrames_);
    updateHeldCounter(CheckHitKey(KEY_INPUT_Z) != 0 || CheckHitKey(KEY_INPUT_RETURN) != 0, confirmHeldFrames_);
    updateHeldCounter(CheckHitKey(KEY_INPUT_X) != 0 || CheckHitKey(KEY_INPUT_BACK) != 0, cancelHeldFrames_);

    InputSnapshot input;
    input.up = pressed(upHeldFrames_);
    input.down = pressed(downHeldFrames_);
    input.left = pressed(leftHeldFrames_);
    input.right = pressed(rightHeldFrames_);
    input.confirm = pressed(confirmHeldFrames_);
    input.cancel = pressed(cancelHeldFrames_);
    input.upRepeat = repeatSlow(upHeldFrames_);
    input.downRepeat = repeatSlow(downHeldFrames_);
    input.leftRepeat = repeatSlow(leftHeldFrames_);
    input.rightRepeat = repeatSlow(rightHeldFrames_);
    input.leftRepeatFast = repeatFast(leftHeldFrames_);
    input.rightRepeatFast = repeatFast(rightHeldFrames_);
    return input;
}

void FrontendRuntime::updateHeldCounter(bool down, int& heldFrames) {
    heldFrames = down ? heldFrames + 1 : 0;
}

bool FrontendRuntime::repeatSlow(int heldFrames) {
    return heldFrames == 1 || (heldFrames > 0x13 && (heldFrames - 0x14) % 8 == 0);
}

bool FrontendRuntime::repeatFast(int heldFrames) {
    return heldFrames == 1 || (heldFrames > 0x13 && (heldFrames - 0x14) % 3 == 0);
}

bool FrontendRuntime::pressed(int heldFrames) {
    return heldFrames == 1;
}

FrontendRuntime::TransitionSpec FrontendRuntime::currentTransitionSpec() const {
    if (state_ == MainState::StageSetup && transitionDirection_ > 0) {
        return {0x50, 0x14};
    }
    if (state_ == MainState::StageSetup && transitionDirection_ < 0) {
        return {0x32, 0x14};
    }
    if (pendingState_ == MainState::Gameplay) {
        return {0x50, 0x14};
    }
    return {0x3c, 0x14};
}

void FrontendRuntime::refreshOptionSlots() {
    optionSlots_ = {{playerOption_, subOption_, loadoutId_, setupToggle_}};
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
    if (input.upRepeat) {
        moveCursor(resources, -1, kTitleMenuCount);
    }
    if (input.downRepeat) {
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
    if (input.upRepeat) {
        moveCursor(resources, -1, kStageSetupRows);
        stageSetupRow_ = cursor_;
    }
    if (input.downRepeat) {
        moveCursor(resources, 1, kStageSetupRows);
        stageSetupRow_ = cursor_;
    }
    if (input.leftRepeatFast || input.rightRepeatFast) {
        const int delta = input.rightRepeatFast ? 1 : -1;
        if (cursor_ == 0) {
            routeMode_ = (routeMode_ + delta + 3) % 3;
            refreshOptionSlots();
            playSound(resources, "SE_se_Switch");
        }
        else if (cursor_ >= 1 && cursor_ <= 4) {
            int& slot = optionSlots_[static_cast<std::size_t>(cursor_ - 1)];
            const int slotMax = routeMode_ == 2 ? 3 : 1;
            slot = (slot + delta + slotMax + 1) % (slotMax + 1);
            playerOption_ = optionSlots_[0];
            subOption_ = optionSlots_[1];
            loadoutId_ = optionSlots_[2];
            playSound(resources, "SE_se_Switch");
        }
        else if (cursor_ == 5) {
            setupToggle_ = setupToggle_ == 0 ? 1 : 0;
            refreshOptionSlots();
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
            selectedStage_ = kSelectableStages[static_cast<std::size_t>(std::min(routeMode_, static_cast<int>(kSelectableStages.size()) - 1))];
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(routeMode_ == 2 ? MainState::AlternateSetup : MainState::StageSelect);
        }
    }
}

void FrontendRuntime::updateStageSelect(ResourceManager& resources, const InputSnapshot& input) {
    if (input.leftRepeat || input.rightRepeat) {
        auto it = std::find(kSelectableStages.begin(), kSelectableStages.end(), selectedStage_);
        int index = it == kSelectableStages.end() ? 0 : static_cast<int>(it - kSelectableStages.begin());
        index = (index + (input.rightRepeat ? 1 : static_cast<int>(kSelectableStages.size()) - 1)) % static_cast<int>(kSelectableStages.size());
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
    const auto spec = currentTransitionSpec();
    transitionTimer_ += transitionDirection_;
    if (transitionDirection_ > 0 && transitionTimer_ >= spec.commitFrames) {
        const auto target = pendingState_;
        setState(target, 0);
        if (target == MainState::Gameplay) {
            gameplayRequest_ = {true, selectedStage_, routeMode_, playerOption_, subOption_, loadoutId_, optionSlots_};
        }
    }
    else if (transitionDirection_ < 0 && transitionTimer_ <= -spec.commitFrames) {
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
            DrawBox(x, y, x + notes::title_layout::kMenuFrameWidth, y + notes::title_layout::kMenuFrameHeight, GetColor(255, 255, 255), FALSE);
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
    const int titleBack = resources.graphHandleById("GFX_system_TitleBack");
    if (titleBack != -1) {
        DrawGraph(notes::stage_setup_evidence::kTitleBackOrigin.x, notes::stage_setup_evidence::kTitleBackOrigin.y, titleBack, TRUE);
    }
    else {
        DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(18, 22, 42), TRUE);
    }

    const int menuTitle = resources.graphFrameById("GFX_system_MenuTitle", routeMode_);
    if (menuTitle != -1) {
        DrawGraph(notes::stage_setup_evidence::kMenuTitleOrigin.x, notes::stage_setup_evidence::kMenuTitleOrigin.y, menuTitle, TRUE);
    }

    const int standFrame = standFrameForSetup(routeMode_, optionSlots_);
    drawFrameScaledAlpha(resources, "GFX_system_Stand", standFrame,
                         static_cast<float>(notes::stage_setup_evidence::kStandBaseX + notes::stage_setup_evidence::kStandShadowOffsetX),
                         static_cast<float>(notes::stage_setup_evidence::kStandShadowY),
                         1.0, 48);
    drawFrameScaledAlpha(resources, "GFX_system_Stand", standFrame,
                         static_cast<float>(notes::stage_setup_evidence::kStandBaseX),
                         static_cast<float>(notes::stage_setup_evidence::kStandY),
                         1.0, 255);

    drawFrameScaledAlpha(resources, "GFX_system_EquipMenu", statusEquipMenuFrameForRoute(routeMode_),
                         static_cast<float>(notes::stage_setup_evidence::kStatusEquipMenuX),
                         static_cast<float>(notes::stage_setup_evidence::kStatusEquipMenuY),
                         1.0, 230);

    constexpr std::array<notes::PointI, 6> rowOrigins{{
        notes::stage_setup_evidence::kEquipMenuRow0,
        notes::stage_setup_evidence::kEquipMenuRow1,
        notes::stage_setup_evidence::kEquipMenuRow2,
        notes::stage_setup_evidence::kEquipMenuRow3,
        notes::stage_setup_evidence::kEquipMenuRow4,
        notes::stage_setup_evidence::kEquipMenuRow5,
    }};
    for (int i = 0; i < static_cast<int>(rowOrigins.size()); ++i) {
        const int x = rowOrigins[static_cast<std::size_t>(i)].x;
        const int y = rowOrigins[static_cast<std::size_t>(i)].y;
        const bool selected = i == cursor_;
        const int alpha = selected ? 255 : (i < cursor_ ? 180 : 128);
        const int frame = equipMenuFrameForSetupRow(i, routeMode_, optionSlots_, setupToggle_);
        drawFrameScaledAlpha(resources, "GFX_system_EquipMenu", frame, static_cast<float>(x), static_cast<float>(y), 1.0, alpha);
        if (selected) {
            const int halfW = notes::ui_resource_evidence::kEquipMenuFrameWidth / 2;
            const int halfH = notes::ui_resource_evidence::kEquipMenuFrameHeight / 2;
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 110);
            DrawBox(x - halfW - 7, y - halfH - 7, x + halfW + 7, y + halfH + 7, GetColor(255, 232, 96), FALSE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
    }


    const int textBox = resources.graphFrameById("GFX_system_TextBox", 0);
    if (textBox != -1) {
        DrawGraph(notes::stage_setup_evidence::kTextBoxOrigin.x, notes::stage_setup_evidence::kTextBoxOrigin.y, textBox, TRUE);
    }
    else {
        DrawBox(notes::stage_setup_evidence::kTextBoxOrigin.x, notes::stage_setup_evidence::kTextBoxOrigin.y,
                notes::stage_setup_evidence::kTextBoxOrigin.x + notes::ui_resource_evidence::kTextBoxFrameWidth,
                notes::stage_setup_evidence::kTextBoxOrigin.y + notes::ui_resource_evidence::kTextBoxFrameHeight,
                GetColor(24, 28, 48), TRUE);
    }
    drawFrameScaledAlpha(resources, "GFX_system_TextIcon", textIconFrameForSetup(cursor_, routeMode_),
                         static_cast<float>(notes::stage_setup_evidence::kTextIconOrigin.x + 40),
                         static_cast<float>(notes::stage_setup_evidence::kTextIconOrigin.y + 40), 1.0, 255);
}

void FrontendRuntime::drawStageSelect(const ResourceManager& resources) const {
    const int titleBack = resources.graphHandleById("GFX_system_TitleBack");
    if (titleBack != -1) {
        DrawGraph(0, 0, titleBack, TRUE);
    }
    else {
        DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(12, 16, 34), TRUE);
    }

    const int stageFrame = resources.graphFrameById("GFX_system_StageFrame", routeMode_ == 2 ? 1 : 0);
    if (stageFrame != -1) {
        DrawGraph(notes::gameplay_layout::kStageFrameRect.x, notes::gameplay_layout::kStageFrameRect.y, stageFrame, TRUE);
    }
    else {
        DrawBox(notes::gameplay_layout::kStageFrameRect.x, notes::gameplay_layout::kStageFrameRect.y,
                notes::gameplay_layout::kStageFrameRect.right(), notes::gameplay_layout::kStageFrameRect.bottom(),
                GetColor(16, 18, 34), TRUE);
    }

    constexpr std::array<StageSelectApproxNode, 3> nodes{{
        {1, {notes::gameplay_layout::kStageFrameRect.x + notes::stage_select_evidence::kMapFocusOffset.x + notes::stage_select_evidence::kStageNode1.x,
             notes::gameplay_layout::kStageFrameRect.y + notes::stage_select_evidence::kMapFocusOffset.y + notes::stage_select_evidence::kStageNode1.y}},
        {2, {notes::gameplay_layout::kStageFrameRect.x + notes::stage_select_evidence::kMapFocusOffset.x + notes::stage_select_evidence::kStageNode2.x,
             notes::gameplay_layout::kStageFrameRect.y + notes::stage_select_evidence::kMapFocusOffset.y + notes::stage_select_evidence::kStageNode2.y}},
        {4, {notes::gameplay_layout::kStageFrameRect.x + notes::stage_select_evidence::kMapFocusOffset.x + notes::stage_select_evidence::kStageNode4.x,
             notes::gameplay_layout::kStageFrameRect.y + notes::stage_select_evidence::kMapFocusOffset.y + notes::stage_select_evidence::kStageNode4.y}},
    }};
    const int pathColor = GetColor(120, 170, 230);
    for (std::size_t i = 1; i < nodes.size(); ++i) {
        DrawLine(nodes[i - 1].center.x, nodes[i - 1].center.y, nodes[i].center.x, nodes[i].center.y, pathColor, 3);
    }
    for (const auto& node : nodes) {
        const bool selected = node.stage == selectedStage_;
        const int pulse = selected ? selectionDirtyTimer_ * 4 : 0;
        const int radius = selected ? 26 + pulse / 3 : 18;
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, selected ? 230 : 130);
        DrawCircle(node.center.x, node.center.y, radius, selected ? GetColor(255, 220, 90) : GetColor(80, 140, 220), TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        DrawCircle(node.center.x, node.center.y, radius, GetColor(255, 255, 255), FALSE);
        drawNumSmall(resources, node.center.x - 8, node.center.y - 4, node.stage, selected ? 0.75 : 0.58);
    }

    const int selectedPreview = resources.graphFrameById("GFX_system_StageFrame2", approxStageFrame2ForStage(selectedStage_));
    if (selectedPreview != -1) {
        DrawRotaGraphF(static_cast<float>(notes::stage_select_provisional_layout::kSelectedPreviewCenter.x),
                       static_cast<float>(notes::stage_select_provisional_layout::kSelectedPreviewCenter.y),
                       notes::stage_select_provisional_layout::kSelectedPreviewScale, 0.0, selectedPreview, TRUE);
    }
    for (const int stage : kSelectableStages) {
        if (stage == selectedStage_) {
            continue;
        }
        const int index = selectableStageIndex(stage);
        drawFrameScaledAlpha(resources, "GFX_system_StageFrame2", approxStageFrame2ForStage(stage),
                             735.0f + static_cast<float>(index) * 132.0f, 520.0f, 0.32, 120);
    }

    drawFrameAlpha(resources, "GFX_system_MapMenu", approxMapMenuFrameForStage(selectedStage_),
                   notes::stage_select_provisional_layout::kMapMenuOrigin.x,
                   notes::stage_select_provisional_layout::kMapMenuOrigin.y, 255);
    drawFrameAlpha(resources, "GFX_system_MapMenu2", approxMapMenu2FrameForStage(selectedStage_, routeMode_),
                   notes::stage_select_provisional_layout::kMapMenu2Origin.x,
                   notes::stage_select_provisional_layout::kMapMenu2Origin.y, 235);
    drawNumSmall(resources, 908, 474, selectedStage_, 1.0);

    drawFrameScaledAlpha(resources, "GFX_system_Stand", standFrameForSetup(routeMode_, optionSlots_),
                         static_cast<float>(notes::stage_select_provisional_layout::kStandCenter.x),
                         static_cast<float>(notes::stage_select_provisional_layout::kStandCenter.y),
                         notes::stage_select_provisional_layout::kStandScale, 210);
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
    const auto spec = currentTransitionSpec();
    const int raw = std::abs(transitionTimer_);
    const int delayed = std::max(0, raw - spec.wipeDelay);
    if (delayed == 0) {
        return;
    }
    const int denom = std::max(1, spec.commitFrames - spec.wipeDelay);
    const int alpha = std::min(220, delayed * 220 / denom);
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
