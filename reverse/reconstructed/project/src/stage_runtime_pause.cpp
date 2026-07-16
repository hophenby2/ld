#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <string_view>

namespace reconstructed {
namespace {

constexpr double kPi = 3.14159265358979323846;
constexpr int kPauseFadeFrames = 30;
constexpr int kResumeCountdownFrames = 180;
constexpr int kGameOverDelayFrames = 180;
constexpr int kGameOverPresentationFrames = 480;

constexpr std::array<int, 11> kDefaultKeyBindings{{
    0xc8, 0xd0, 0xcd, 0xcb, 0x2c, 0x2d, 0x2c, 0x2d, 0x2e, 0x2a, 0x01,
}};
constexpr std::array<int, 11> kDefaultControllerBindings{{
    0x08, 0x01, 0x04, 0x02, 0x10, 0x20, 0x10, 0x40, 0x20, 0x200, 0x800,
}};

// DirectInput scan-code order used by FUN_140102ae0 and KerboardPromot.png.
constexpr std::array<int, 100> kKeyboardPromptKeys{{
    0x0e, 0x0f, 0x1c, 0x2a, 0x36, 0x1d, 0x9d, 0x01, 0x39, 0xc9,
    0xd1, 0xcf, 0xc7, 0xcb, 0xc8, 0xcd, 0xd0, 0xd2, 0xd3, 0x0c,
    0x7d, 0x90, 0x34, 0x35, 0x38, 0xb8, 0x46, 0x27, 0x92, 0x1a,
    0x1b, 0x91, 0x2b, 0x33, 0x3a, 0xc5, 0x52, 0x4f, 0x50, 0x51,
    0x4b, 0x4c, 0x4d, 0x47, 0x48, 0x49, 0x37, 0x4e, 0x4a, 0x53,
    0xb5, 0x9c, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42,
    0x43, 0x44, 0x57, 0x58, 0x1e, 0x30, 0x2e, 0x20, 0x12, 0x21,
    0x22, 0x23, 0x17, 0x24, 0x25, 0x26, 0x32, 0x31, 0x18, 0x19,
    0x10, 0x13, 0x1f, 0x14, 0x16, 0x2f, 0x11, 0x2d, 0x15, 0x2c,
    0x0b, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
}};

std::vector<int> graphFramesOrLoad(ResourceManager& resources,
                                   std::string_view id,
                                   const char* path,
                                   int frameCount,
                                   int columns,
                                   int rows,
                                   int frameWidth,
                                   int frameHeight) {
    std::vector<int> frames;
    frames.reserve(static_cast<std::size_t>(frameCount));
    for (int frame = 0; frame < frameCount; ++frame) {
        frames.push_back(resources.graphFrameById(id, frame));
    }
    if (!frames.empty() && frames.front() != -1) {
        return frames;
    }
    return resources.loadDivGraph(path, frameCount, columns, rows, frameWidth, frameHeight);
}

int frameHandle(const std::vector<int>& frames, int frame) {
    return frame >= 0 && frame < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(frame)]
               : -1;
}

int sineFadeIn(int frame, int duration) {
    const double progress = std::clamp(static_cast<double>(frame) / duration, 0.0, 1.0);
    return static_cast<int>(std::sin(progress * kPi * 0.5) * 255.0);
}

int wrapIndex(int value, int count) {
    value %= count;
    return value < 0 ? value + count : value;
}

std::array<int, 11> defaultControllerBindings(int controlDevice) {
    auto result = kDefaultControllerBindings;
    if (controlDevice == 3) {
        result[10] = 0x2000;
    }
    else if (controlDevice == 4) {
        result[4] = 0x20;
        result[5] = 0x40;
        result[6] = 0x20;
        result[7] = 0x10;
        result[8] = 0x40;
        result[10] = 0x2000;
    }
    return result;
}

int keyboardPromptFrame(int keyCode) {
    const auto found = std::find(kKeyboardPromptKeys.begin(), kKeyboardPromptKeys.end(), keyCode);
    return found == kKeyboardPromptKeys.end()
               ? -1
               : static_cast<int>(found - kKeyboardPromptKeys.begin());
}

int controllerPromptFrame(int controlDevice, int binding) {
    if (controlDevice < 1 || controlDevice > 4) {
        return -1;
    }
    unsigned int mask = 0x10;
    for (int index = 0; index < 28; ++index) {
        if (binding == static_cast<int>(mask)) {
            const int frame = controlDevice * 15 + index + 1;
            return frame < 75 ? frame : -1;
        }
        mask <<= 1;
    }
    return -1;
}

int controllerButtonNumber(int binding) {
    unsigned int mask = 0x10;
    for (int index = 0; index < 28; ++index) {
        if (binding == static_cast<int>(mask)) {
            return index + 1;
        }
        mask <<= 1;
    }
    return 0;
}

void drawTileWipe(const std::vector<int>& effectMediumFrames, int phase) {
    // Direct transcription of FUN_1400d3fd0: frames 1/2 form a staggered
    // 12x6 checkerboard, with each tile opening over twelve frames.
    for (int column = 0; column < 12; ++column) {
        for (int row = 0; row < 6; ++row) {
            const int onset = column + row * 3;
            if (phase < onset) {
                continue;
            }
            const double progress = std::clamp(
                static_cast<double>(phase - onset) / 12.0, 0.0, 1.0);
            const double scaleX = std::sin(progress * kPi * 0.5);
            const float x = static_cast<float>(column * 120);
            const float y = static_cast<float>(
                row * 120 + 60 + 180 - static_cast<int>(scaleX * 180.0));
            const int handle = frameHandle(effectMediumFrames,
                                           ((column + row) & 1) == 0 ? 1 : 2);
            if (handle != -1) {
                DrawRotaGraph3F(x, y, 100.0f, 100.0f,
                                scaleX, 1.0, 0.0, handle, TRUE);
            }
        }
    }
}

} // namespace

void StageRuntime::initializePauseResources(ResourceManager& resources) {
    pauseBackFrames_ = graphFramesOrLoad(
        resources, "GFX_player_PauseBack", "media\\player\\PauseBack.png",
        10, 5, 2, 600, 720);
    pauseCountFrames_ = graphFramesOrLoad(
        resources, "GFX_player_PauseCount", "media\\player\\PauseCount.png",
        4, 4, 1, 320, 320);

    constexpr std::array<const char*, 4> kMenuIds{{
        "GFX_player_PauseMenu",
        "GFX_player_PauseMenu_eng",
        "GFX_player_PauseMenu_ch1",
        "GFX_player_PauseMenu_ch2",
    }};
    constexpr std::array<const char*, 4> kMenuPaths{{
        "media\\player\\PauseMenu.png",
        "media\\player\\PauseMenu_eng.png",
        "media\\player\\PauseMenu_ch1.png",
        "media\\player\\PauseMenu_ch2.png",
    }};
    for (std::size_t language = 0; language < pauseMenuFramesByLanguage_.size(); ++language) {
        pauseMenuFramesByLanguage_[language] = graphFramesOrLoad(
            resources, kMenuIds[language], kMenuPaths[language], 30, 1, 30, 480, 80);
    }
    pauseConfigMenuFrames_ = graphFramesOrLoad(
        resources, "GFX_system_ConfigMenu", "media\\system\\ConfigMenu.png",
        20, 1, 20, 240, 40);
    pauseConfigMenu2Frames_ = graphFramesOrLoad(
        resources, "GFX_system_ConfigMenu2", "media\\system\\ConfigMenu2.png",
        15, 1, 15, 240, 40);
    pauseConfigNumberFrames_ = graphFramesOrLoad(
        resources, "GFX_system_ConfigNumber", "media\\system\\ConfigNumber.png",
        11, 1, 11, 30, 40);
    pauseKeyConfigMenuFrames_ = graphFramesOrLoad(
        resources, "GFX_system_KeyConfigMenu", "media\\system\\KeyConfigMenu.png",
        21, 1, 21, 240, 40);
    pauseKeyboardPromptFrames_ = graphFramesOrLoad(
        resources, "GFX_system_KerboardPromot", "media\\system\\KerboardPromot.png",
        110, 10, 11, 40, 40);
    pauseControllerPromptFrames_ = graphFramesOrLoad(
        resources, "GFX_system_KerPromotButton", "media\\system\\KerPromotButton.png",
        75, 15, 5, 40, 40);

    pauseSelectSoundHandle_ = resources.soundHandleById("SE_se_Select");
    pauseEnterSoundHandle_ = resources.soundHandleById("SE_se_Enter");
    pauseCancelSoundHandle_ = resources.soundHandleById("SE_se_Cancel");
    pauseErrorSoundHandle_ = resources.soundHandleById("SE_se_Error");
    pausePoseSoundHandle_ = resources.soundHandleById("SE_se_Pose");
    if (pausePoseSoundHandle_ == -1) {
        pausePoseSoundHandle_ = resources.loadSound("media\\se\\Pose.wav", 3);
    }
    pauseSwitchSoundHandle_ = resources.soundHandleById("SE_se_Switch");
    gameOverBgmHandle_ = resources.soundHandleById("BGM_bgm_Gameover");
}

void StageRuntime::stopStageBgm() {
    for (const int handle : stageBgmHandles_) {
        if (handle != -1) {
            StopSoundMem(handle, FALSE);
        }
    }
    for (const int handle : bossBgmHandles_) {
        if (handle != -1) {
            StopSoundMem(handle, FALSE);
        }
    }
}

void StageRuntime::captureAndStopStageBgm() {
    pausedBgmHandles_.clear();
    const auto capture = [this](int handle) {
        if (handle != -1 && CheckSoundMem(handle) == 1) {
            pausedBgmHandles_.push_back(handle);
            StopSoundMem(handle, FALSE);
        }
    };
    for (const int handle : stageBgmHandles_) {
        capture(handle);
    }
    for (const int handle : bossBgmHandles_) {
        capture(handle);
    }
}

void StageRuntime::resumeStageBgm() {
    for (const int handle : pausedBgmHandles_) {
        if (handle == -1) {
            continue;
        }
        ChangeVolumeSoundMem(static_cast<int>(config_.bgmVolume * 25.5f), handle);
        PlaySoundMem(handle, DX_PLAYTYPE_LOOP, FALSE);
    }
    pausedBgmHandles_.clear();
}

void StageRuntime::playPauseWipeSound(int phase) const {
    if (phase >= 0 && phase < 28 && phase % 3 == 0) {
        playPlayerSound(pauseSwitchSoundHandle_, 0x0c);
    }
}

void StageRuntime::enterPauseMenu() {
    pauseFlowState_ = PauseFlowState::Menu;
    pauseCursor_ = 0;
    pauseTransitionTimer_ = 0;
    pauseStateTimer_ = 0;
    pauseSelectionPulse_ = 0;
    pauseUpHeldFrames_ = 0;
    pauseDownHeldFrames_ = 0;
    pauseLeftHeldFrames_ = 0;
    pauseRightHeldFrames_ = 0;
    pauseKeyCaptureActive_ = false;
    pauseKeyCaptureDelay_ = 0;
    pauseInputConsumed_ = true;
    captureAndStopStageBgm();
    playPlayerSound(pausePoseSoundHandle_);
}

void StageRuntime::beginGameOver() {
    if (pauseFlowState_ == PauseFlowState::GameOverDelay ||
        pauseFlowState_ == PauseFlowState::GameOverPresentation ||
        pendingExitRequest_ == GameplayExitRequest::GameOver) {
        return;
    }
    pauseFlowState_ = PauseFlowState::GameOverDelay;
    pauseTransitionTimer_ = 0;
    pauseStateTimer_ = 0;
    gameOverDelayComplete_ = false;
    pauseInputConsumed_ = true;
    player_.playerStateTimer = 259;
}

void StageRuntime::completeGameOverDelayFrame() {
    if (pauseFlowState_ != PauseFlowState::GameOverDelay ||
        gameOverDelayComplete_ || pauseStateTimer_ != kGameOverDelayFrames) {
        return;
    }
    gameOverDelayComplete_ = true;
    stopStageBgm();
    if (config_.routeMode == 2) {
        pendingExitRequest_ = GameplayExitRequest::GameOver;
        return;
    }
    if (gameOverBgmHandle_ != -1) {
        ChangeVolumeSoundMem(static_cast<int>(config_.bgmVolume * 25.5f),
                             gameOverBgmHandle_);
        PlaySoundMem(gameOverBgmHandle_, DX_PLAYTYPE_BACK, TRUE);
    }
}

bool StageRuntime::consumeSettingsChange(SettingsChange& change) {
    if (!pauseSettingsDirty_ && !pauseSaveDataRequested_ &&
        !pauseSaveSystemConfigRequested_) {
        return false;
    }
    change.bgmVolume = config_.bgmVolume;
    change.soundEffectVolume = config_.soundEffectVolume;
    change.language = config_.language;
    change.dataWindowEnabled = config_.dataWindowEnabled;
    change.systemConfig = config_.systemConfig;
    change.keyboardBindings = config_.keyboardBindings;
    change.controllerBindings = config_.controllerBindings;
    change.controlDevice = config_.controlDevice;
    change.saveData = pauseSaveDataRequested_;
    change.saveSystemConfig = pauseSaveSystemConfigRequested_;
    pauseSettingsDirty_ = false;
    pauseSaveDataRequested_ = false;
    pauseSaveSystemConfigRequested_ = false;
    return true;
}

void StageRuntime::updatePauseHeldCounters() {
    const auto advance = [](bool down, int& heldFrames) {
        heldFrames = down ? heldFrames + 1 : 0;
    };
    advance(actionDown(InputAction::Up), pauseUpHeldFrames_);
    advance(actionDown(InputAction::Down), pauseDownHeldFrames_);
    advance(actionDown(InputAction::Left), pauseLeftHeldFrames_);
    advance(actionDown(InputAction::Right), pauseRightHeldFrames_);
}

bool StageRuntime::anyInputActionDown() const {
    return std::any_of(inputActions_.begin(), inputActions_.end(), [](bool down) { return down; });
}

bool StageRuntime::pauseRepeat(int heldFrames) {
    return heldFrames == 1 || (heldFrames > 20 && (heldFrames - 20) % 8 == 0);
}

bool StageRuntime::updatePauseFlow() {
    const bool pauseDown = actionDown(InputAction::Pause);

    if (pauseFlowState_ == PauseFlowState::Gameplay) {
        if (pauseDown && !pauseInputHeld_ && !stageComplete() &&
            pendingExitRequest_ == GameplayExitRequest::None) {
            enterPauseMenu();
            pauseInputHeld_ = true;
            return true;
        }
        pauseInputHeld_ = pauseDown;
        return false;
    }

    pauseInputHeld_ = pauseDown;

    if (pauseFlowState_ == PauseFlowState::GameOverDelay) {
        if (gameOverDelayComplete_) {
            if (config_.routeMode != 2) {
                pauseFlowState_ = PauseFlowState::GameOverPresentation;
                pauseStateTimer_ = 0;
            }
            return true;
        }
        ++pauseStateTimer_;
        if (config_.routeMode == 2) {
            playPauseWipeSound(pauseStateTimer_ - 120);
        }
        const double volumeScale = std::clamp(
            1.0 - std::sin(static_cast<double>(pauseStateTimer_) * kPi / 360.0),
            0.0, 1.0);
        const int volume = static_cast<int>(config_.bgmVolume * 25.5 * volumeScale);
        for (const int handle : stageBgmHandles_) {
            if (handle != -1) {
                ChangeVolumeSoundMem(volume, handle);
            }
        }
        for (const int handle : bossBgmHandles_) {
            if (handle != -1) {
                ChangeVolumeSoundMem(volume, handle);
            }
        }
        // The dispatcher runs counters 1..180. The counter-180 tail is
        // committed after that same gameplay update in StageRuntime::update().
        return false;
    }

    if (pauseFlowState_ == PauseFlowState::GameOverPresentation) {
        if (pauseStateTimer_ < kGameOverPresentationFrames) {
            ++pauseStateTimer_;
            playPauseWipeSound(pauseStateTimer_ - 440);
        }
        if (pauseStateTimer_ >= kGameOverPresentationFrames &&
            pendingExitRequest_ == GameplayExitRequest::None) {
            if (gameOverBgmHandle_ != -1) {
                StopSoundMem(gameOverBgmHandle_, FALSE);
            }
            pendingExitRequest_ = GameplayExitRequest::GameOver;
        }
        return true;
    }

    updatePauseHeldCounters();
    if (!anyInputActionDown()) {
        pauseInputConsumed_ = false;
    }
    if (pauseSelectionPulse_ > 0) {
        --pauseSelectionPulse_;
    }
    ++pauseStateTimer_;

    if (pauseFlowState_ == PauseFlowState::ControlConfig &&
        pauseLastControlDevice_ != config_.controlDevice) {
        pauseLastControlDevice_ = config_.controlDevice;
        pauseSettingsDirty_ = true;
    }

    if (pauseFlowState_ == PauseFlowState::ControlConfig && pauseKeyCaptureActive_) {
        if (pauseKeyCaptureDelay_ < 0) {
            if (!anyInputActionDown()) {
                pauseKeyCaptureDelay_ = 0;
            }
            return true;
        }

        bool captured = false;
        if (config_.controlDevice < 5) {
            const int padState = GetJoypadInputState(DX_INPUT_PAD1);
            const auto unsignedPadState = static_cast<std::uint32_t>(padState);
            if (padState == -1 || (unsignedPadState & 0x0fU) != 0) {
                return true;
            }
            const int first = pauseCursor_ < 6 ? 4 : 6;
            const int last = pauseCursor_ < 6 ? 6 : 11;
            std::uint32_t mask = 0x10U;
            for (int index = 0; index < 28; ++index) {
                if ((unsignedPadState & mask) != 0) {
                    const int binding = static_cast<int>(mask);
                    const int previous = config_.controllerBindings[
                        static_cast<std::size_t>(pauseCursor_)];
                    for (int action = first; action < last; ++action) {
                        if (action != pauseCursor_ &&
                            config_.controllerBindings[static_cast<std::size_t>(action)] == binding) {
                            config_.controllerBindings[static_cast<std::size_t>(action)] = previous;
                        }
                    }
                    config_.controllerBindings[static_cast<std::size_t>(pauseCursor_)] = binding;
                    captured = true;
                    playPlayerSound(pauseEnterSoundHandle_);
                }
                mask <<= 1;
            }
        }
        else {
            std::array<char, 256> keyState{};
            if (GetHitKeyStateAll(keyState.data()) == -1) {
                return true;
            }
            const int first = pauseCursor_ < 4 ? 0 : (pauseCursor_ < 6 ? 4 : 6);
            const int last = pauseCursor_ < 4 ? 4 : (pauseCursor_ < 6 ? 6 : 11);
            for (const int key : kKeyboardPromptKeys) {
                if (key <= 0 || key >= static_cast<int>(keyState.size()) ||
                    keyState[static_cast<std::size_t>(key)] == 0) {
                    continue;
                }
                const int previous = config_.keyboardBindings[
                    static_cast<std::size_t>(pauseCursor_)];
                for (int action = first; action < last; ++action) {
                    if (action != pauseCursor_ &&
                        config_.keyboardBindings[static_cast<std::size_t>(action)] == key) {
                        config_.keyboardBindings[static_cast<std::size_t>(action)] = previous;
                    }
                }
                config_.keyboardBindings[static_cast<std::size_t>(pauseCursor_)] = key;
                captured = true;
                playPlayerSound(pauseEnterSoundHandle_);
            }
        }
        if (!captured) {
            return true;
        }
        pauseKeyCaptureActive_ = false;
        pauseKeyCaptureDelay_ = config_.controlDevice == 5 ? 8 : 0;
        pauseSettingsDirty_ = true;
        pauseInputConsumed_ = true;
        return true;
    }

    if (pauseFlowState_ == PauseFlowState::ResumeCountdown) {
        if (pauseStateTimer_ == 60 || pauseStateTimer_ == 120) {
            playPlayerSound(timerSoundHandle_, 0x10);
        }
        if (pauseStateTimer_ >= kResumeCountdownFrames) {
            resumeStageBgm();
            pauseFlowState_ = PauseFlowState::Gameplay;
            pauseTransitionTimer_ = 0;
            pauseStateTimer_ = 0;
            pauseUpHeldFrames_ = 0;
            pauseDownHeldFrames_ = 0;
            pauseLeftHeldFrames_ = 0;
            pauseRightHeldFrames_ = 0;
            pauseInputConsumed_ = true;
        }
        return true;
    }

    if (pauseTransitionTimer_ != 0) {
        pauseTransitionTimer_ += pauseTransitionTimer_ > 0 ? 1 : -1;
        if (pauseFlowState_ == PauseFlowState::Menu &&
            pauseTransitionTimer_ >= kPauseFadeFrames) {
            pauseTransitionTimer_ = 0;
            pauseStateTimer_ = 0;
            if (pauseCursor_ == 0) {
                if (config_.routeMode < 0) {
                    resumeStageBgm();
                    pauseFlowState_ = PauseFlowState::Gameplay;
                    pauseInputConsumed_ = true;
                }
                else {
                    pauseFlowState_ = PauseFlowState::ResumeCountdown;
                    playPlayerSound(timerSoundHandle_, 0x10);
                }
            }
            else if (pauseCursor_ == 1) {
                pauseFlowState_ = config_.routeMode < 0
                                      ? PauseFlowState::ConfirmSkipTutorial
                                      : PauseFlowState::ConfirmRetry;
                pauseCursor_ = 1;
            }
            else if (pauseCursor_ == 2) {
                pauseFlowState_ = PauseFlowState::Settings;
                pauseCursor_ = 0;
            }
            else if (pauseCursor_ == 3) {
                pauseFlowState_ = PauseFlowState::ConfirmAbort;
                pauseCursor_ = 1;
            }
        }
        else if (pauseFlowState_ == PauseFlowState::ConfirmRetry ||
                 pauseFlowState_ == PauseFlowState::ConfirmAbort ||
                 pauseFlowState_ == PauseFlowState::ConfirmSkipTutorial) {
            if (pauseCursor_ == 0) {
                playPauseWipeSound(pauseTransitionTimer_ - 20);
            }
            if (pauseCursor_ == 1 && pauseTransitionTimer_ >= 30) {
                pauseCursor_ = pauseFlowState_ == PauseFlowState::ConfirmAbort ? 3 : 1;
                pauseFlowState_ = PauseFlowState::Menu;
                pauseTransitionTimer_ = 0;
                pauseStateTimer_ = 30;
                pauseInputConsumed_ = true;
            }
            else if (pauseCursor_ == 0 && pauseTransitionTimer_ >= 60 &&
                     pendingExitRequest_ == GameplayExitRequest::None) {
                if (pauseFlowState_ == PauseFlowState::ConfirmRetry) {
                    pendingExitRequest_ = GameplayExitRequest::Retry;
                }
                else if (pauseFlowState_ == PauseFlowState::ConfirmSkipTutorial) {
                    pendingExitRequest_ = GameplayExitRequest::SkipTutorial;
                }
                else {
                    pendingExitRequest_ = GameplayExitRequest::AbortGameplay;
                }
            }
        }
        else if (pauseFlowState_ == PauseFlowState::Settings &&
                 (pauseTransitionTimer_ >= 50 || pauseTransitionTimer_ <= -50)) {
            const int target = pauseCursor_;
            pauseTransitionTimer_ = 0;
            pauseStateTimer_ = 0;
            pauseInputConsumed_ = true;
            if (target == 4) {
                pauseFlowState_ = PauseFlowState::VideoConfig;
                pauseCursor_ = 0;
            }
            else if (target == 5) {
                pauseFlowState_ = PauseFlowState::ControlConfig;
                pauseCursor_ = 0;
                pauseKeyCaptureActive_ = false;
                pauseKeyCaptureDelay_ = 0;
                pauseLastControlDevice_ = config_.controlDevice;
            }
            else {
                pauseFlowState_ = PauseFlowState::Menu;
                pauseCursor_ = 2;
                pauseStateTimer_ = 30;
                pauseSaveDataRequested_ = true;
            }
        }
        else if (pauseFlowState_ == PauseFlowState::VideoConfig &&
                 (pauseTransitionTimer_ >= 50 || pauseTransitionTimer_ <= -50)) {
            pauseFlowState_ = PauseFlowState::Settings;
            pauseCursor_ = 4;
            pauseTransitionTimer_ = 0;
            pauseStateTimer_ = 30;
            pauseInputConsumed_ = true;
            pauseSaveSystemConfigRequested_ = true;
        }
        else if (pauseFlowState_ == PauseFlowState::ControlConfig &&
                 pauseTransitionTimer_ >= 50) {
            pauseFlowState_ = PauseFlowState::Settings;
            pauseCursor_ = 5;
            pauseTransitionTimer_ = 0;
            pauseStateTimer_ = 30;
            pauseInputConsumed_ = true;
            pauseKeyCaptureActive_ = false;
            pauseKeyCaptureDelay_ = 0;
            pauseSaveDataRequested_ = true;
        }
        return true;
    }

    const bool upCommand = pauseRepeat(pauseUpHeldFrames_) && pauseDownHeldFrames_ == 0;
    const bool downCommand = pauseRepeat(pauseDownHeldFrames_) && pauseUpHeldFrames_ == 0;
    const bool leftCommand = pauseRepeat(pauseLeftHeldFrames_) && pauseRightHeldFrames_ == 0;
    const bool rightCommand = pauseRepeat(pauseRightHeldFrames_) && pauseLeftHeldFrames_ == 0;
    const bool confirmCommand = actionDown(InputAction::Confirm) || pauseDown;

    if (pauseFlowState_ == PauseFlowState::Settings) {
        if (upCommand) {
            pauseCursor_ = (pauseCursor_ + 6) % 7;
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }
        else if (downCommand) {
            pauseCursor_ = (pauseCursor_ + 1) % 7;
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }

        if ((leftCommand || rightCommand) && pauseCursor_ < 4) {
            const int delta = rightCommand ? 1 : -1;
            bool changed = true;
            if (pauseCursor_ == 0) {
                const int next = config_.bgmVolume + delta;
                if (next >= 0 && next <= 10) {
                    config_.bgmVolume = next;
                }
                else {
                    changed = false;
                }
            }
            else if (pauseCursor_ == 1) {
                const int next = config_.soundEffectVolume + delta;
                if (next >= 0 && next <= 10) {
                    config_.soundEffectVolume = next;
                }
                else {
                    changed = false;
                }
            }
            else if (pauseCursor_ == 2) {
                config_.language = (config_.language + delta + 4) % 4;
            }
            else {
                if (config_.dataWindowUnlocked) {
                    config_.dataWindowEnabled = config_.dataWindowEnabled == 0 ? 1 : 0;
                }
                else {
                    changed = false;
                }
            }
            pauseSettingsDirty_ = pauseSettingsDirty_ || changed;
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(changed ? pauseSelectSoundHandle_ : pauseErrorSoundHandle_,
                            changed ? 0x19 : 0x14);
        }

        if (actionDown(InputAction::Cancel) && !pauseInputConsumed_) {
            pauseInputConsumed_ = true;
            playPlayerSound(pauseCancelSoundHandle_);
            if (pauseCursor_ == 6) {
                pauseTransitionTimer_ = -1;
            }
            else {
                pauseCursor_ = 6;
                pauseSelectionPulse_ = 4;
            }
        }
        else if (confirmCommand && !pauseInputConsumed_) {
            pauseInputConsumed_ = true;
            if (pauseCursor_ == 6) {
                playPlayerSound(pauseEnterSoundHandle_);
                pauseTransitionTimer_ = 1;
            }
            else if (pauseCursor_ == 4 || pauseCursor_ == 5) {
                playPlayerSound(pauseEnterSoundHandle_);
                pauseTransitionTimer_ = 1;
            }
        }
        return true;
    }

    if (pauseFlowState_ == PauseFlowState::VideoConfig) {
        if (upCommand) {
            pauseCursor_ = wrapIndex(pauseCursor_ - 1, 9);
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }
        else if (downCommand) {
            pauseCursor_ = wrapIndex(pauseCursor_ + 1, 9);
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }
        if ((leftCommand || rightCommand) && pauseCursor_ < 7) {
            const int delta = rightCommand ? 1 : -1;
            if (pauseCursor_ == 1) {
                config_.systemConfig[1] = wrapIndex(config_.systemConfig[1] + delta, 3);
            }
            else if (pauseCursor_ == 6) {
                config_.systemConfig[6] = wrapIndex(config_.systemConfig[6] + delta, 4);
            }
            else {
                auto& value = config_.systemConfig[static_cast<std::size_t>(pauseCursor_)];
                value = value == 0 ? 1 : 0;
            }
            config_.itemVisibility = config_.systemConfig[3];
            config_.likeStyle = config_.systemConfig[5];
            pauseSettingsDirty_ = true;
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }
        if (actionDown(InputAction::Cancel) && !pauseInputConsumed_) {
            pauseInputConsumed_ = true;
            playPlayerSound(pauseCancelSoundHandle_);
            if (pauseCursor_ == 8) {
                pauseTransitionTimer_ = -1;
            }
            else {
                pauseCursor_ = 8;
                pauseSelectionPulse_ = 4;
            }
        }
        else if (confirmCommand && !pauseInputConsumed_) {
            pauseInputConsumed_ = true;
            if (pauseCursor_ == 7) {
                const int fullScreen = config_.systemConfig[0];
                const int soundType = config_.systemConfig[6];
                config_.systemConfig = {{fullScreen, 0, 1, 0, 1, 0, soundType}};
                config_.itemVisibility = 0;
                config_.likeStyle = 0;
                pauseSettingsDirty_ = true;
                pauseSelectionPulse_ = 4;
                playPlayerSound(pauseEnterSoundHandle_);
            }
            else if (pauseCursor_ == 8) {
                pauseTransitionTimer_ = 1;
                playPlayerSound(pauseEnterSoundHandle_);
            }
        }
        return true;
    }

    if (pauseFlowState_ == PauseFlowState::ControlConfig) {
        if (pauseKeyCaptureDelay_ > 0) {
            --pauseKeyCaptureDelay_;
            return true;
        }
        if (upCommand) {
            pauseCursor_ = wrapIndex(pauseCursor_ - 1, 13);
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }
        else if (downCommand) {
            pauseCursor_ = wrapIndex(pauseCursor_ + 1, 13);
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }
        if (actionDown(InputAction::Cancel) && !pauseInputConsumed_) {
            pauseInputConsumed_ = true;
            playPlayerSound(pauseCancelSoundHandle_);
            if (pauseCursor_ == 12) {
                pauseTransitionTimer_ = 1;
            }
            else {
                pauseCursor_ = 12;
                pauseSelectionPulse_ = 4;
            }
        }
        else if (confirmCommand && !pauseInputConsumed_) {
            pauseInputConsumed_ = true;
            if (pauseCursor_ < 11) {
                if (config_.controlDevice < 5 && pauseCursor_ < 4) {
                    playPlayerSound(pauseErrorSoundHandle_, 0x14);
                }
                else {
                    pauseKeyCaptureActive_ = true;
                    pauseKeyCaptureDelay_ = -1;
                    playPlayerSound(pauseEnterSoundHandle_);
                }
            }
            else if (pauseCursor_ == 11) {
                if (config_.controlDevice < 5) {
                    config_.controllerBindings = defaultControllerBindings(config_.controlDevice);
                }
                else {
                    config_.keyboardBindings = kDefaultKeyBindings;
                }
                pauseSettingsDirty_ = true;
                pauseSelectionPulse_ = 4;
                playPlayerSound(pauseEnterSoundHandle_);
            }
            else {
                pauseTransitionTimer_ = 1;
                playPlayerSound(pauseEnterSoundHandle_);
            }
        }
        return true;
    }

    if (pauseFlowState_ == PauseFlowState::Menu) {
        if (upCommand) {
            pauseCursor_ = (pauseCursor_ + 3) % 4;
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }
        else if (downCommand) {
            pauseCursor_ = (pauseCursor_ + 1) % 4;
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }

        if (confirmCommand && !pauseInputConsumed_) {
            pauseInputConsumed_ = true;
            playPlayerSound(pauseEnterSoundHandle_);
            pauseTransitionTimer_ = 1;
        }
        return true;
    }

    if (pauseFlowState_ == PauseFlowState::ConfirmRetry ||
        pauseFlowState_ == PauseFlowState::ConfirmAbort ||
        pauseFlowState_ == PauseFlowState::ConfirmSkipTutorial) {
        if (upCommand || downCommand) {
            pauseCursor_ = pauseCursor_ == 0 ? 1 : 0;
            pauseSelectionPulse_ = 4;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseSelectSoundHandle_);
        }
        if (actionDown(InputAction::Cancel) && !pauseInputConsumed_) {
            pauseCursor_ = 1;
            pauseTransitionTimer_ = 1;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseCancelSoundHandle_);
        }
        else if (confirmCommand && !pauseInputConsumed_) {
            pauseTransitionTimer_ = 1;
            pauseInputConsumed_ = true;
            playPlayerSound(pauseEnterSoundHandle_);
        }
    }
    return true;
}

void StageRuntime::drawPauseFlow() const {
    if (pauseFlowState_ == PauseFlowState::Gameplay) {
        return;
    }

    if (pauseFlowState_ == PauseFlowState::GameOverDelay) {
        if (config_.routeMode == 2 && pauseStateTimer_ >= 120) {
            drawTileWipe(effectMediumFrames_, pauseStateTimer_ - 120);
        }
        return;
    }

    if (pauseFlowState_ == PauseFlowState::GameOverPresentation) {
        const int timer = pauseStateTimer_;
        const int alpha = timer < 64 ? sineFadeIn(timer, 64) : 255;
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

        const int spotlight = frameHandle(pauseBackFrames_, 5);
        if (spotlight != -1) {
            DrawGraph(340, 0, spotlight, TRUE);
        }

        float characterOffset = 0.0f;
        if (timer < 64) {
            const float entryBase = static_cast<float>(
                static_cast<int>(std::sin(timer * kPi / 128.0) * 640.0) - 640);
            characterOffset = static_cast<float>(
                std::sin((timer % 16) * kPi / 16.0) * entryBase);
        }
        else if (timer % 180 > 169) {
            characterOffset = static_cast<float>(
                -10.0 * std::sin((timer % 10) * kPi / 10.0));
        }
        const int character = frameHandle(
            pauseBackFrames_, 7 + std::clamp(config_.setupGroup, 0, 2));
        if (character != -1) {
            DrawRotaGraphF(640.0f, 360.0f + characterOffset,
                           1.0, 0.0, character, TRUE);
        }

        double titleScale = 0.0;
        if (timer >= 140) {
            titleScale = 1.0;
        }
        else if (timer >= 120) {
            titleScale = std::sin((timer - 120) * kPi / 40.0);
        }
        const int title = frameHandle(pauseBackFrames_, 6);
        if (title != -1) {
            DrawRotaGraphF(640.0f, 210.0f, titleScale, 0.0, title, TRUE);
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        if (timer >= 440) {
            drawTileWipe(effectMediumFrames_, timer - 440);
        }
        return;
    }

    if (pauseFlowState_ == PauseFlowState::ResumeCountdown) {
        const int numeralFrame = std::clamp(pauseStateTimer_ / 60, 0, 2);
        const int phase = pauseStateTimer_ % 60;
        const double numeralScale = phase < 8
                                        ? 1.0 + std::sin(phase * kPi / 16.0) * 0.2
                                        : 1.0;
        const int numeral = frameHandle(pauseCountFrames_, numeralFrame);
        if (numeral != -1) {
            DrawRotaGraphF(640.0f, 250.0f, numeralScale, 0.0, numeral, TRUE);
        }
        const int ring = frameHandle(pauseCountFrames_, 3);
        if (ring != -1) {
            const float halfWidth = static_cast<float>(160.0 * (60 - phase) / 60.0);
            DrawModiGraphF(640.0f - halfWidth, 90.0f,
                           640.0f + halfWidth, 90.0f,
                           640.0f + halfWidth, 410.0f,
                           640.0f - halfWidth, 410.0f,
                           ring, TRUE);
        }
        return;
    }

    int alpha = pauseFlowState_ == PauseFlowState::Menu &&
                        pauseStateTimer_ < kPauseFadeFrames
                    ? sineFadeIn(pauseStateTimer_, kPauseFadeFrames)
                    : 255;
    if (pauseFlowState_ == PauseFlowState::Menu && pauseCursor_ == 0 &&
        pauseTransitionTimer_ > 0) {
        alpha = 255 - sineFadeIn(pauseTransitionTimer_, kPauseFadeFrames);
    }
    alpha = std::clamp(alpha, 0, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

    const int pauseBack = frameHandle(pauseBackFrames_, 0);
    if (pauseBack != -1) {
        DrawGraph(340, 0, pauseBack, TRUE);
    }
    const int clouds = frameHandle(pauseBackFrames_, 1);
    if (clouds != -1) {
        const int bob = static_cast<int>(std::sin(pauseStateTimer_ * kPi / 180.0) * 10.0);
        DrawGraph(340, bob, clouds, TRUE);
    }
    const int character = frameHandle(
        pauseBackFrames_, 2 + std::clamp(config_.setupGroup, 0, 2));
    if (character != -1) {
        DrawGraph(340, 0, character, TRUE);
    }

    const auto& pauseMenuFrames = pauseMenuFramesByLanguage_[
        static_cast<std::size_t>(std::clamp(config_.language, 0, 3))];
    const auto drawMenuFrame = [&](int frame, float x, float y, bool selected) {
        const int handle = frameHandle(pauseMenuFrames, frame);
        if (handle == -1) {
            return;
        }
        const int brightness = selected ? 255 : 128;
        SetDrawBright(brightness, brightness, brightness);
        const double scale = selected ? 1.0 + pauseSelectionPulse_ * 0.025 : 1.0;
        DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
        SetDrawBright(255, 255, 255);
    };
    const auto drawAlphaFrame = [&](const std::vector<int>& frames, int frame,
                                    float x, float y, int elementAlpha,
                                    double scale = 1.0, int brightness = 255) {
        const int handle = frameHandle(frames, frame);
        if (handle == -1) {
            return;
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                         std::clamp(alpha * elementAlpha / 255, 0, 255));
        SetDrawBright(brightness, brightness, brightness);
        DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
        SetDrawBright(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    };
    const auto drawNumber = [&](int value, float rightX, float y,
                                int elementAlpha, bool percent,
                                int brightness = 255) {
        int remaining = std::max(value, 0);
        float x = rightX;
        do {
            drawAlphaFrame(pauseConfigNumberFrames_, remaining % 10,
                           x, y, elementAlpha, 1.0, brightness);
            remaining /= 10;
            x -= 25.0f;
        } while (remaining > 0);
        if (percent) {
            drawAlphaFrame(pauseConfigNumberFrames_, 10,
                           rightX + 35.0f, y, elementAlpha, 1.0, brightness);
        }
    };

    if (pauseFlowState_ == PauseFlowState::Menu) {
        drawMenuFrame(std::clamp(config_.setupGroup, 0, 2), 640.0f, 100.0f, true);
        for (int row = 0; row < 4; ++row) {
            bool selected = pauseCursor_ == row;
            if (selected && pauseTransitionTimer_ > 0 && pauseTransitionTimer_ % 4 >= 2) {
                selected = false;
            }
            const int frame = config_.routeMode < 0 && row == 1 ? 14 : 3 + row;
            drawMenuFrame(frame, 640.0f, 200.0f + row * 90.0f, selected);
        }
    }
    else if (pauseFlowState_ == PauseFlowState::Settings) {
        constexpr std::array<int, 7> kSettingsFrames{{0, 1, 2, 3, 5, 6, 8}};
        for (int row = 0; row < static_cast<int>(kSettingsFrames.size()); ++row) {
            const float y = 150.0f + row * 50.0f;
            const bool selected = pauseCursor_ == row;
            const int rowAlpha = selected ? 255 : 96;
            const double scale = selected ? 1.0 + pauseSelectionPulse_ * 0.025 : 1.0;
            const int brightness = row == 3 && !config_.dataWindowUnlocked ? 128 : 255;
            drawAlphaFrame(pauseConfigMenuFrames_,
                           kSettingsFrames[static_cast<std::size_t>(row)],
                           520.0f, y, rowAlpha, scale, brightness);
            if (row == 0) {
                drawNumber(config_.bgmVolume * 10, 730.0f, y, rowAlpha, true);
            }
            else if (row == 1) {
                drawNumber(config_.soundEffectVolume * 10, 730.0f, y, rowAlpha, true);
            }
            else if (row == 2) {
                drawAlphaFrame(pauseConfigMenu2Frames_,
                               11 + std::clamp(config_.language, 0, 3),
                               780.0f, y, rowAlpha, scale);
            }
            else if (row == 3) {
                drawAlphaFrame(pauseConfigMenu2Frames_,
                               config_.dataWindowEnabled == 1 ? 0 : 1,
                               780.0f, y, rowAlpha, scale, brightness);
            }
        }
    }
    else if (pauseFlowState_ == PauseFlowState::VideoConfig) {
        constexpr std::array<int, 9> kVideoFrames{{12, 13, 14, 15, 16, 17, 18, 9, 8}};
        constexpr std::array<int, 3> kFrameRates{{60, 30, 20}};
        constexpr std::array<int, 4> kSoundFrames{{2, 5, 6, 7}};
        for (int row = 0; row < static_cast<int>(kVideoFrames.size()); ++row) {
            const float y = 150.0f + row * 50.0f;
            const bool selected = pauseCursor_ == row;
            int rowAlpha = selected ? 255 : 96;
            if (selected && pauseTransitionTimer_ != 0 &&
                wrapIndex(pauseTransitionTimer_, 4) >= 2) {
                rowAlpha = 96;
            }
            const double scale = selected ? 1.0 + pauseSelectionPulse_ * 0.025 : 1.0;
            drawAlphaFrame(pauseConfigMenuFrames_,
                           kVideoFrames[static_cast<std::size_t>(row)],
                           550.0f, y, rowAlpha, scale);
            if (row == 1) {
                drawNumber(kFrameRates[static_cast<std::size_t>(
                               std::clamp(config_.systemConfig[1], 0, 2))],
                           810.0f, y, rowAlpha, false);
            }
            else if (row == 5) {
                drawAlphaFrame(pauseConfigMenu2Frames_,
                               config_.systemConfig[5] == 0 ? 8 : 9,
                               810.0f, y, rowAlpha, scale);
            }
            else if (row == 6) {
                drawAlphaFrame(pauseConfigMenu2Frames_,
                               kSoundFrames[static_cast<std::size_t>(
                                   std::clamp(config_.systemConfig[6], 0, 3))],
                               810.0f, y, rowAlpha, scale);
            }
            else if (row < 7) {
                drawAlphaFrame(pauseConfigMenu2Frames_,
                               config_.systemConfig[static_cast<std::size_t>(row)] == 1 ? 0 : 1,
                               810.0f, y, rowAlpha, scale);
            }
        }
    }
    else if (pauseFlowState_ == PauseFlowState::ControlConfig) {
        drawAlphaFrame(pauseKeyConfigMenuFrames_, 0, 560.0f, 62.0f, 255);
        drawAlphaFrame(pauseKeyConfigMenuFrames_,
                       std::clamp(config_.controlDevice + 1, 1, 6),
                       760.0f, 62.0f, 255);
        for (int row = 0; row < 13; ++row) {
            const float y = 102.0f + row * 42.0f;
            const bool selected = pauseCursor_ == row;
            const int rowAlpha = selected ? 255 : 96;
            const int brightness = config_.controlDevice < 5 && row < 4 ? 128 : 255;
            const double scale = selected ? 1.0 + pauseSelectionPulse_ * 0.025 : 1.0;
            if (row < 11) {
                drawAlphaFrame(pauseKeyConfigMenuFrames_, 7 + row,
                               560.0f, y, rowAlpha, scale, brightness);
                if (pauseKeyCaptureActive_ && row == pauseCursor_) {
                    const int promptAlpha = 128 - static_cast<int>(
                        std::sin(pauseStateTimer_ * kPi / 32.0) * 64.0);
                    drawAlphaFrame(pauseKeyConfigMenuFrames_, 20,
                                   760.0f, y, promptAlpha, 1.0, brightness);
                    continue;
                }
                if (config_.controlDevice == 5) {
                    drawAlphaFrame(pauseKeyboardPromptFrames_,
                                   keyboardPromptFrame(config_.keyboardBindings[
                                       static_cast<std::size_t>(row)]),
                                   760.0f, y, 255, 1.0, brightness);
                }
                else if (config_.controlDevice == 0) {
                    drawAlphaFrame(pauseKeyConfigMenuFrames_, 19,
                                   760.0f, y, 255, 1.0, brightness);
                    drawNumber(controllerButtonNumber(config_.controllerBindings[
                                   static_cast<std::size_t>(row)]),
                               845.0f, y, 255, false, brightness);
                }
                else {
                    drawAlphaFrame(pauseControllerPromptFrames_,
                                   controllerPromptFrame(config_.controlDevice,
                                       config_.controllerBindings[static_cast<std::size_t>(row)]),
                                   760.0f, y, 255, 1.0, brightness);
                }
            }
            else if (row == 11) {
                drawAlphaFrame(pauseKeyConfigMenuFrames_, 18,
                               560.0f, y, rowAlpha, scale);
            }
            else {
                drawAlphaFrame(pauseConfigMenuFrames_, 8,
                               560.0f, y, rowAlpha, scale);
            }
        }
    }
    else {
        int titleFrame = 20;
        if (pauseFlowState_ == PauseFlowState::ConfirmRetry) {
            titleFrame = 19;
        }
        else if (pauseFlowState_ == PauseFlowState::ConfirmSkipTutorial) {
            titleFrame = 21;
        }
        drawMenuFrame(titleFrame, 640.0f, 200.0f, true);
        drawMenuFrame(23, 640.0f, 300.0f, pauseCursor_ == 0);
        drawMenuFrame(24, 640.0f, 390.0f, pauseCursor_ == 1);
    }

    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    if (pauseTransitionTimer_ >= 20 && pauseCursor_ == 0 &&
        (pauseFlowState_ == PauseFlowState::ConfirmRetry ||
         pauseFlowState_ == PauseFlowState::ConfirmAbort ||
         pauseFlowState_ == PauseFlowState::ConfirmSkipTutorial)) {
        drawTileWipe(effectMediumFrames_, pauseTransitionTimer_ - 20);
    }
}

} // namespace reconstructed
