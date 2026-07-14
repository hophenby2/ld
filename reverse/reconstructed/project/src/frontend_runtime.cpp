#include "frontend_runtime.h"

#include "reconstruction_notes.h"

#include <DxLib.h>
#include <Windows.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

namespace reconstructed {
namespace {

constexpr int kTitleMenuCount = 9;
constexpr int kStageSetupRows = 7;
constexpr int kPracticeRows = 10;
constexpr int kOptionsRows = 9;
constexpr int kGalleryPictureCount = 20;
constexpr int kAchievementCount = 50;
constexpr int kEnemyEncyclopediaCount = 104;
constexpr int kOptionAssistRows = 4;
constexpr int kConfigMenuRows = 9;
constexpr int kKeyConfigRows = 13;
constexpr int kManualPageCount = 11;
constexpr int kReplaySlotCount = 24;
constexpr float kPi = 3.14159265358979323846f;
constexpr int kTitleInputEnableFrame = 0x40;
constexpr int kSetupInputEnableFrame = 0x32;
constexpr int kSecondaryMenuInputEnableFrame = 0x20;
constexpr int kAchievementInputEnableFrame = 0x3c;
constexpr int kEnemyEncyclopediaInputEnableFrame = 0x3c;
constexpr const char* kPracticeMenuPath = "media\\system\\PracticeMenu.png";
constexpr const char* kConfigNumberPath = "media\\system\\ConfigNumber.png";
constexpr const char* kEffectMediumPath = "media\\effect\\Effect_m.png";
constexpr const char* kGalleryFramePath = "media\\gallery\\GalleryFrame.png";
constexpr const char* kAchievementPath = "media\\gallery\\Achievement.png";
constexpr const char* kNoticeFramePath = "media\\gallery\\NoticeFrame.png";
constexpr const char* kEnemyListWindowPath = "media\\gallery\\EnemyListWindow.png";
constexpr const char* kEnemyListPath = "media\\gallery\\EnemyList.png";
constexpr const char* kEnemyListPicturePath = "media\\gallery\\EnemyListPic.png";
constexpr const char* kBossPath = "media\\stage\\Boss.png";
constexpr const char* kKeyboardPromptPath = "media\\system\\KerboardPromot.png";
constexpr const char* kControllerPromptPath = "media\\system\\KerPromotButton.png";
constexpr const char* kRankingNoticePath = "media\\system\\RankingNotice.png";
constexpr const char* kResultMenuPath = "media\\player\\Result.png";

constexpr std::array<int, 11> kDefaultKeyBindings{{
    KEY_INPUT_UP, KEY_INPUT_DOWN, KEY_INPUT_RIGHT, KEY_INPUT_LEFT,
    KEY_INPUT_Z, KEY_INPUT_X, KEY_INPUT_Z, KEY_INPUT_X,
    KEY_INPUT_C, KEY_INPUT_LSHIFT, KEY_INPUT_ESCAPE,
}};
constexpr std::array<int, 11> kDefaultControllerBindings{{
    0x08, 0x01, 0x04, 0x02,
    0x10, 0x20, 0x10, 0x40, 0x20, 0x200, 0x800,
}};

// FUN_1400b5c70 indexes Achievement.png through this 50-entry .rdata table.
constexpr std::array<int, kAchievementCount> kAchievementIconFrames{{
    0, 0, 0, 0, 0, 0, 0, 0, 1, 2,
    1, 1, 1, 2, 2, 1, 2, 2, 1, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    1, 2, 2, 0, 1, 2, 0, 1, 2, 3,
}};

// FUN_1400dacb0 maps these DirectInput scan codes to KerboardPromot frames.
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

constexpr std::array<const char*, 4> kManualPaths{{
    "media\\system\\Manual.png",
    "media\\system\\Manual_eng.png",
    "media\\system\\Manual_ch1.png",
    "media\\system\\Manual_ch2.png",
}};
constexpr std::array<const char*, 4> kManualMenuPaths{{
    "media\\system\\ManualMenu.png",
    "media\\system\\ManualMenu_eng.png",
    "media\\system\\ManualMenu_ch1.png",
    "media\\system\\ManualMenu_ch2.png",
}};
constexpr std::array<const char*, 4> kGalleryPicturePaths{{
    "media\\gallery\\GalleryPic.png",
    "media\\gallery\\GalleryPic_eng.png",
    "media\\gallery\\GalleryPic_ch1.png",
    "media\\gallery\\GalleryPic_ch2.png",
}};
constexpr std::array<const char*, 4> kGalleryNoticePaths{{
    "media\\gallery\\NoticeText2.png",
    "media\\gallery\\NoticeText2_eng.png",
    "media\\gallery\\NoticeText2_ch1.png",
    "media\\gallery\\NoticeText2_ch2.png",
}};
constexpr std::array<const char*, 4> kAchievementNoticePaths{{
    "media\\gallery\\NoticeText3.png",
    "media\\gallery\\NoticeText3_eng.png",
    "media\\gallery\\NoticeText3_ch1.png",
    "media\\gallery\\NoticeText3_ch2.png",
}};

struct StageNode {
    float x = 0.0f;
    float y = 0.0f;
};

// local_218 and its contiguous stack aliases in state_04 form this world map.
// Entries 1..13 come from _DAT_14053c0b0/_DAT_14053c1e0/
// _DAT_14053c290/_DAT_14053bd50/_DAT_14053b5d0/_DAT_14053c1f0.
constexpr std::array<StageNode, 15> kStageNodes{{
    {0.0f, 0.0f},
    {0.0f, 0.0f},
    {750.0f, -320.0f},
    {1500.0f, -320.0f},
    {2250.0f, -640.0f},
    {3000.0f, -640.0f},
    {3750.0f, -960.0f},
    {4500.0f, -960.0f},
    {5250.0f, -1280.0f},
    {6000.0f, 320.0f},
    {6750.0f, -320.0f},
    {7500.0f, 0.0f},
    {8250.0f, -320.0f},
    {9000.0f, -640.0f},
    {9750.0f, -640.0f},
}};

int wrapIndex(int value, int count) {
    if (count <= 0) {
        return 0;
    }
    value %= count;
    return value < 0 ? value + count : value;
}

StageNode stageNode(int stage) {
    if (stage < 0 || stage >= static_cast<int>(kStageNodes.size())) {
        return {};
    }
    return kStageNodes[static_cast<std::size_t>(stage)];
}

int minimumStageForRoute(int routeMode, bool trialExtraUnlocked) {
    return routeMode == 1 ? (trialExtraUnlocked ? 10 : 11) : 1;
}

int equipMenuFrameForSetupItem(int item, int setupGroup, const std::array<int, 4>& optionSlots, int feverMode) {
    // Exact state_03 loop at 0x1400d4610: items 0..2 use paired frames
    // per player group, item 3 is the four-way style, then auto-fever/start.
    if (item >= 0 && item <= 2) {
        return optionSlots[static_cast<std::size_t>(item)] + (item + setupGroup * 3) * 2;
    }
    if (item == 3) {
        return 0x12 + optionSlots[3];
    }
    if (item == 4) {
        return feverMode == 0 ? 0x17 : 0x1d;
    }
    return 0x16;
}

int statusEquipMenuFrameForGroup(int setupGroup) {
    return wrapIndex(0x18 + setupGroup, notes::ui_resource_evidence::kEquipMenuFrames);
}

int standFrameForSetup(int cursor, int setupGroup, const std::array<int, 4>& optionSlots) {
    // state_03 copies twelve four-entry rows from .rdata before indexing
    // [group][cursor-1][choice]. Cursor 0 and the final two rows use group*10.
    constexpr std::array<std::array<int, 4>, 12> frames{{
        {{1, 1, 0, 0}}, {{4, 4, 0, 0}}, {{2, 2, 0, 0}}, {{1, -1, -1, 2}},
        {{11, 11, 10, 10}}, {{12, 12, 10, 10}}, {{15, 15, 10, 10}}, {{14, 14, 14, 14}},
        {{22, 22, 20, 20}}, {{24, 24, 20, 20}}, {{21, 21, 20, 20}}, {{26, 26, 26, 26}},
    }};
    if (cursor < 1 || cursor > 4) {
        return setupGroup * 10;
    }
    const int tableRow = setupGroup * 4 + cursor - 1;
    const int choice = std::clamp(optionSlots[static_cast<std::size_t>(cursor - 1)], 0, 3);
    return frames[static_cast<std::size_t>(tableRow)][static_cast<std::size_t>(choice)];
}

int stageFrame2ForStage(int stage) {
    return stage >= 1 && stage <= notes::ui_resource_evidence::kStageFrame2Frames ? stage - 1 : -1;
}

int mapMenuFrameForStage(int stage) {
    return stage >= 1 && stage <= notes::ui_resource_evidence::kMapMenuFrames ? stage - 1 : -1;
}

int practicePhaseMax(int stage) {
    constexpr std::array<int, 12> maxima{{3, 3, 3, 3, 4, 4, 4, 4, 5, 6, 4, 5}};
    return stage >= 0 && stage < static_cast<int>(maxima.size())
        ? maxima[static_cast<std::size_t>(stage)]
        : 5;
}

template <std::size_t N>
int maxDifficultyForStage(const std::array<int, N>& unlocked, int stage) {
    if (stage >= 0 && stage < static_cast<int>(unlocked.size())) {
        return unlocked[static_cast<std::size_t>(stage)];
    }
    return notes::difficulty_overlay_evidence::kDefaultDifficulty;
}

void drawFrameScaledAlpha(const ResourceManager& resources, const char* id, int frame, float cx, float cy, double scale, int alpha) {
    const int handle = resources.graphFrameById(id, frame);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    if (handle != -1) {
        DrawRotaGraphF(cx, cy, scale, 0.0, handle, TRUE);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void drawPathFrameScaledAlpha(const ResourceManager& resources, const char* path, int frame,
                              float cx, float cy, double scale, int alpha) {
    const int handle = resources.graphFrame(path, frame);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    if (handle != -1) {
        DrawRotaGraphF(cx, cy, scale, 0.0, handle, TRUE);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void drawConfigNumber(const ResourceManager& resources, float rightX, float y, int value, bool percent, int alpha) {
    value = std::max(0, value);
    float x = rightX;
    if (percent) {
        drawPathFrameScaledAlpha(resources, kConfigNumberPath, 10, x, y, 1.0, alpha);
        x -= 25.0f;
    }
    do {
        drawPathFrameScaledAlpha(resources, kConfigNumberPath, value % 10, x, y, 1.0, alpha);
        value /= 10;
        x -= 25.0f;
    } while (value > 0);
}

const char* localizedPath(const std::array<const char*, 4>& paths, int language) {
    return paths[static_cast<std::size_t>(std::clamp(language, 0, 3))];
}

void drawFrontendBackdrop(const ResourceManager& resources, int menuTitleFrame, int language) {
    const int titleBack = resources.graphHandleById("GFX_system_TitleBack");
    if (titleBack != -1) {
        DrawGraph(0, 0, titleBack, TRUE);
    }
    else {
        DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(18, 22, 42), TRUE);
    }
    const char* menuTitleId = language == 2 ? "GFX_system_MenuTitle_ch1"
                            : language == 3 ? "GFX_system_MenuTitle_ch2"
                                            : "GFX_system_MenuTitle";
    const int title = resources.graphFrameById(menuTitleId, menuTitleFrame);
    if (title != -1) {
        DrawGraph(0, 0, title, TRUE);
    }
}

std::string replayTimestampText(int timestamp) {
    if (timestamp <= 0) {
        return "----/--/-- --:--";
    }
    const std::time_t raw = static_cast<std::time_t>(timestamp);
    std::tm local{};
    if (localtime_s(&local, &raw) != 0) {
        return "----/--/-- --:--";
    }
    char text[32]{};
    if (std::strftime(text, sizeof(text), "%Y/%m/%d %H:%M", &local) == 0) {
        return "----/--/-- --:--";
    }
    return text;
}

float galleryCellX(int index) {
    const int row = index / 4;
    return 260.0f + static_cast<float>(index % 4) * 240.0f + (row % 2 == 1 ? 40.0f : 0.0f);
}

bool titleRowUnlocked(int index, bool trialUnlocked, int maxGameStage) {
    if (index == 1) {
        return trialUnlocked;
    }
    if (index == 2) {
        return maxGameStage >= 2;
    }
    return true;
}

void drawBossFrame(const ResourceManager& resources, int frame, float x, float y,
                   int fixedAngle = 0, double scaleX = 1.0, double scaleY = 1.0,
                   bool mirror = false) {
    const int handle = resources.graphFrame(kBossPath, frame);
    if (handle == -1) {
        return;
    }
    const double angle = static_cast<double>(fixedAngle) * static_cast<double>(kPi) / 32768.0;
    DrawRotaGraph3F(x, y, 100.0f, 100.0f, scaleX, scaleY, angle,
                    handle, TRUE, mirror ? TRUE : FALSE, FALSE);
}

template <class... Frames>
void drawBossAnimation(const ResourceManager& resources, int timer, int step,
                       float x, float y, Frames... frames) {
    const std::array<int, sizeof...(Frames)> sequence{{static_cast<int>(frames)...}};
    const int period = step * static_cast<int>(sequence.size());
    const int index = (timer % period) / step;
    drawBossFrame(resources, sequence[static_cast<std::size_t>(index)], x, y);
}

void drawEnemyEncyclopediaComposite(const ResourceManager& resources, int enemyId,
                                    int timer, float xOffset) {
    switch (enemyId) {
    case 11:
        drawBossAnimation(resources, timer, 7, xOffset + 715.0f, 240.0f, 0, 1, 2);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 240.0f, 5, 6, 7);
        drawBossAnimation(resources, timer, 5, xOffset + 815.0f, 440.0f, 8, 9);
        break;
    case 22:
        drawBossAnimation(resources, timer, 5, xOffset + 715.0f, 240.0f, 10, 11, 12);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 240.0f, 15, 16, 17);
        drawBossAnimation(resources, timer, 5, xOffset + 815.0f, 440.0f, 18, 19);
        break;
    case 32:
        drawBossAnimation(resources, timer, 7, xOffset + 715.0f, 340.0f, 20, 21, 22);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 340.0f, 23, 24);
        break;
    case 41:
        drawBossAnimation(resources, timer, 7, xOffset + 715.0f, 240.0f, 25, 26, 27);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 240.0f, 30, 31, 32);
        drawBossAnimation(resources, timer, 5, xOffset + 715.0f, 440.0f, 35, 36, 37);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 440.0f, 38, 39);
        break;
    case 50:
        drawBossAnimation(resources, timer, 7, xOffset + 715.0f, 240.0f, 40, 41, 42, 41);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 240.0f, 45, 46, 47, 46);
        drawBossAnimation(resources, timer, 5, xOffset + 815.0f, 440.0f, 48, 49);
        break;
    case 51:
        drawBossAnimation(resources, timer, 7, xOffset + 715.0f, 340.0f, 50, 51, 52);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 340.0f, 55, 56, 57);
        break;
    case 59:
        drawBossAnimation(resources, timer, 5, xOffset + 715.0f, 240.0f, 60, 61, 62);
        drawBossAnimation(resources, timer, 7, xOffset + 915.0f, 240.0f, 65, 66, 67);
        drawBossAnimation(resources, timer, 5, xOffset + 815.0f, 440.0f, 68, 69);
        break;
    case 61:
        drawBossAnimation(resources, timer, 6, xOffset + 715.0f, 240.0f, 70, 71, 72, 71);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 240.0f, 75, 76, 77);
        drawBossAnimation(resources, timer, 5, xOffset + 815.0f, 440.0f, 78, 79);
        break;
    case 72:
        drawBossAnimation(resources, timer, 5, xOffset + 715.0f, 340.0f,
                          80, 81, 82, 83, 84, 85, 87, 86,
                          87, 86, 85, 84, 83, 82, 80, 81);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 340.0f, 88, 89);
        break;
    case 73:
        drawBossAnimation(resources, timer, 5, xOffset + 715.0f, 340.0f,
                          96, 95, 94, 93, 92, 90, 91, 90,
                          91, 92, 93, 94, 95, 97, 96, 97);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 340.0f, 98, 99);
        break;
    case 82: {
        const int angle = static_cast<int>(
            std::sin(static_cast<float>(timer) * kPi / 60.0f) * 2000.0f);
        drawBossFrame(resources, 59, xOffset + 695.0f, 145.0f, angle);
        drawBossFrame(resources, 59, xOffset + 675.0f, 145.0f, -angle, 1.0, 1.0, true);
        drawBossFrame(resources, 58, xOffset + 685.0f, 160.0f);
        drawBossAnimation(resources, timer, 6, xOffset + 685.0f, 160.0f, 110, 111, 112, 111);

        drawBossFrame(resources, 59, xOffset + 955.0f, 145.0f, angle);
        drawBossFrame(resources, 59, xOffset + 935.0f, 145.0f, -angle, 1.0, 1.0, true);
        drawBossFrame(resources, 58, xOffset + 945.0f, 160.0f);
        drawBossAnimation(resources, timer, 5, xOffset + 945.0f, 160.0f, 113, 114);

        drawBossAnimation(resources, timer, 6, xOffset + 715.0f, 340.0f, 100, 101, 102, 101);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 340.0f, 105, 106, 107);
        drawBossAnimation(resources, timer, 5, xOffset + 815.0f, 520.0f, 108, 109);
        break;
    }
    case 84: {
        const float wave = std::sin(static_cast<float>(timer) * kPi / 24.0f);
        const int angle = static_cast<int>(wave * 3000.0f);
        const double scaleX = 0.7 + static_cast<double>(wave) * 0.3;

        drawBossFrame(resources, 129, xOffset + 709.0f, 220.0f, angle, scaleX);
        drawBossFrame(resources, 129, xOffset + 661.0f, 220.0f, -angle, scaleX, 1.0, true);
        drawBossAnimation(resources, timer, 5, xOffset + 685.0f, 240.0f, 115, 116, 117, 116);

        drawBossFrame(resources, 129, xOffset + 969.0f, 220.0f, angle, scaleX);
        drawBossFrame(resources, 129, xOffset + 921.0f, 220.0f, -angle, scaleX, 1.0, true);
        drawBossAnimation(resources, timer, 5, xOffset + 945.0f, 240.0f, 120, 121, 122);

        drawBossFrame(resources, 129, xOffset + 709.0f, 420.0f, angle, scaleX);
        drawBossFrame(resources, 129, xOffset + 661.0f, 420.0f, -angle, scaleX, 1.0, true);
        drawBossAnimation(resources, timer, 5, xOffset + 685.0f, 440.0f, 123, 124);

        drawBossFrame(resources, 129, xOffset + 969.0f, 420.0f, angle, scaleX);
        drawBossFrame(resources, 129, xOffset + 921.0f, 420.0f, -angle, scaleX, 1.0, true);
        drawBossAnimation(resources, timer, 5, xOffset + 945.0f, 440.0f, 127, 128);
        break;
    }
    case 103:
        drawBossAnimation(resources, timer, 5, xOffset + 715.0f, 240.0f, 145, 146, 147, 146);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 240.0f, 150, 151, 152, 153, 152, 151);
        drawBossAnimation(resources, timer, 5, xOffset + 715.0f, 440.0f, 154, 155, 156, 157);
        drawBossAnimation(resources, timer, 5, xOffset + 915.0f, 440.0f, 158, 159);
        break;
    default:
        break;
    }
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

int controlDeviceForPadType(int padType) {
    // main dispatcher 0x1400f5ef0 maps DxLib pad types to prompt families.
    if (padType == 1 || padType == 2) {
        return 2;
    }
    if (padType == 4 || padType == 5) {
        return 4;
    }
    if (padType == 8) {
        return 3;
    }
    return 0;
}

int keyboardPromptFrame(int keyCode) {
    const auto found = std::find(kKeyboardPromptKeys.begin(), kKeyboardPromptKeys.end(), keyCode);
    return found == kKeyboardPromptKeys.end()
        ? -1
        : static_cast<int>(found - kKeyboardPromptKeys.begin());
}

int controllerPromptFrame(int controlDevice, int action, int binding) {
    const int base = std::clamp(controlDevice, 0, 4) * 15;
    if (action < 4) {
        return base;
    }
    // FUN_1400dacb0 uses fixed action-row prompts for the generic device-0
    // family. Only the four named controller families search by button mask.
    if (controlDevice == 0) {
        return action - 3;
    }
    unsigned int mask = 0x10;
    for (int index = 0; index < 28; ++index) {
        if (binding == static_cast<int>(mask)) {
            const int frame = base + index + 1;
            return frame < 75 ? frame : -1;
        }
        mask <<= 1;
    }
    return -1;
}

} // namespace

void FrontendRuntime::initialize(ResourceManager& resources, const SaveConfigState& saveConfigState) {
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
    feverMode_ = 0;
    optionSlots_ = {{0, 0, 0, 0}};
    setupOptionsByGroup_ = {{
        {{0, 0, 0, 0}},
        {{0, 0, 0, 0}},
        {{0, 0, 0, 0}},
    }};
    setupGroup_ = 0;
    previousSetupCursor_ = 0;
    selectedStage_ = 1;
    stageOverlayState_ = 0;
    selectedDifficulty_ = notes::difficulty_overlay_evidence::kDefaultDifficulty;
    counterMode_ = 0;
    savedStageByRoute_ = {{1, 11}};
    maxUnlockedStageByRoute_ = {{1, 11}};
    maxUnlockedDifficultyByStage_.fill(notes::difficulty_overlay_evidence::kDefaultDifficulty);
    practiceOptions_ = {{1, notes::difficulty_overlay_evidence::kDefaultDifficulty, 0, 0, 0, 0, 0, 0}};
    trialUnlocked_ = false;
    trialExtraUnlocked_ = false;
    counterUnlocked_ = true;
    bgmVolume_ = 10;
    seVolume_ = 10;
    language_ = 0;
    dataWindowEnabled_ = 1;
    dataWindowUnlocked_ = false;
    shortcutUnlocked_ = false;
    galleryUnlocked_.fill(0);
    galleryViewed_.fill(0);
    achievementUnlocked_.fill(0);
    achievementViewed_.fill(0);
    enemyUnlocked_.fill(0);
    enemyStageStatus_.fill(0);
    enemySequentialProgress_ = 0;
    enemyMaximum_ = 10;
    galleryExpanded_ = false;
    galleryClosing_ = false;
    galleryExpandTimer_ = 0;
    controlModeEnabled_ = 1;
    helpMode_ = 6;
    systemConfig_ = {{0, 0, 1, 0, 1, 0, 0}};
    keyBindings_ = kDefaultKeyBindings;
    controllerBindings_ = kDefaultControllerBindings;
    controlDevice_ = 5;
    keyCaptureActive_ = false;
    keyCaptureDelay_ = 0;
    replaySlots_.fill(ReplaySlot{});
    replaySlotIndex_ = 0;
    replayStageChoice_ = 1;
    rankingCursor_ = 0;
    rankingValue_ = 0;
    loadSaveBackedState(saveConfigState);
    loadMissingFrontendGraphs(resources);
    setupGroup_ = std::clamp(setupGroup_, 0, 2);
    optionSlots_ = setupOptionsByGroup_[static_cast<std::size_t>(setupGroup_)];
    refreshOptionSlots();
    selectedStage_ = savedStageByRoute_[0];
    const auto initialNode = stageNode(selectedStage_);
    stageCameraX_ = initialNode.x;
    stageCameraY_ = initialNode.y;
    stageCameraStartX_ = stageCameraX_;
    stageCameraStartY_ = stageCameraY_;
    stageCameraTimer_ = 0;
    gameplayRequest_ = {};
    ensureTitleBgm(resources);
}

void FrontendRuntime::update(ResourceManager& resources) {
    ++frame_;
    if (selectionDirtyTimer_ > 0) {
        --selectionDirtyTimer_;
    }
    if (state_ == MainState::StageSelect && stageCameraTimer_ > 0) {
        const auto target = stageNode(selectedStage_);
        const float progress = 1.0f - static_cast<float>(stageCameraTimer_) / 30.0f;
        const float eased = std::sin(std::clamp(progress, 0.0f, 1.0f) * kPi * 0.5f);
        stageCameraX_ = stageCameraStartX_ + (target.x - stageCameraStartX_) * eased;
        stageCameraY_ = stageCameraStartY_ + (target.y - stageCameraStartY_) * eased;
        --stageCameraTimer_;
        if (stageCameraTimer_ == 0) {
            stageCameraX_ = target.x;
            stageCameraY_ = target.y;
        }
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
    case MainState::Gallery: updateGallery(resources, input); break;
    case MainState::Achievement: updateAchievement(resources, input); break;
    case MainState::EnemyEncyclopedia: updateEnemyEncyclopedia(resources, input); break;
    case MainState::Manual: updateManual(resources, input); break;
    case MainState::Options: updateOptions(resources, input); break;
    case MainState::OptionAssist: updateOptionAssist(resources, input); break;
    case MainState::ConfigMenu: updateConfigMenu(resources, input); break;
    case MainState::KeyConfig: updateKeyConfig(resources, input); break;
    case MainState::ReplayList: updateReplayList(resources, input); break;
    case MainState::ReplayStageSelect: updateReplayStageSelect(resources, input); break;
    case MainState::Ranking: updateRanking(resources, input); break;
    case MainState::RankingNotice: updateRankingNotice(resources, input); break;
    case MainState::Gameplay: break;
    }
}

void FrontendRuntime::draw(const ResourceManager& resources) const {
    switch (state_) {
    case MainState::TitleMenu: drawTitleMenu(resources); break;
    case MainState::StageSetup: drawStageSetup(resources); break;
    case MainState::StageSelect: drawStageSelect(resources); break;
    case MainState::AlternateSetup: drawAlternateSetup(resources); break;
    case MainState::Gallery: drawGallery(resources); break;
    case MainState::Achievement: drawAchievement(resources); break;
    case MainState::EnemyEncyclopedia: drawEnemyEncyclopedia(resources); break;
    case MainState::Manual: drawManual(resources); break;
    case MainState::Options: drawOptions(resources); break;
    case MainState::OptionAssist: drawOptionAssist(resources); break;
    case MainState::ConfigMenu: drawConfigMenu(resources); break;
    case MainState::KeyConfig: drawKeyConfig(resources); break;
    case MainState::ReplayList: drawReplayList(resources); break;
    case MainState::ReplayStageSelect: drawReplayStageSelect(resources); break;
    case MainState::Ranking: drawRanking(resources); break;
    case MainState::RankingNotice: drawRankingNotice(resources); break;
    case MainState::Gameplay: break;
    }
    drawTransitionOverlay(resources);
}

FrontendRuntime::GameplayRequest FrontendRuntime::consumeGameplayRequest() {
    auto request = gameplayRequest_;
    gameplayRequest_ = {};
    return request;
}

void FrontendRuntime::completeGameplay(ResourceManager& resources) {
    setState(MainState::StageSelect, 0);
    ensureTitleBgm(resources);
}

FrontendRuntime::InputSnapshot FrontendRuntime::readInput() {
    const int padState = GetJoypadInputState(DX_INPUT_PAD1);
    std::array<bool, 11> actions{};
    bool keyboardUsed = false;
    bool controllerUsed = false;
    for (std::size_t action = 0; action < actions.size(); ++action) {
        const int key = keyBindings_[action];
        const bool keyboardDown = key > 0 && key < 0x100 && CheckHitKey(key) != 0;
        const int binding = controllerBindings_[action];
        const bool controllerDown = padState != -1 && binding != 0 && (padState & binding) != 0;
        actions[action] = keyboardDown || controllerDown;
        keyboardUsed = keyboardUsed || keyboardDown;
        controllerUsed = controllerUsed || controllerDown;
    }
    if (!keyCaptureActive_) {
        if (keyboardUsed) {
            controlDevice_ = 5;
        }
        if (controllerUsed) {
            controlDevice_ = controlDeviceForPadType(GetJoypadType(DX_INPUT_PAD1));
        }
    }
    updateHeldCounter(actions[0], upHeldFrames_);
    updateHeldCounter(actions[1], downHeldFrames_);
    updateHeldCounter(actions[3], leftHeldFrames_);
    updateHeldCounter(actions[2], rightHeldFrames_);
    updateHeldCounter(actions[4], confirmHeldFrames_);
    updateHeldCounter(actions[5], cancelHeldFrames_);

    InputSnapshot input;
    input.up = pressed(upHeldFrames_);
    input.down = pressed(downHeldFrames_);
    input.confirm = pressed(confirmHeldFrames_);
    input.cancel = pressed(cancelHeldFrames_);
    input.upRepeat = repeatSlow(upHeldFrames_);
    input.downRepeat = repeatSlow(downHeldFrames_);
    input.leftRepeat = repeatSlow(leftHeldFrames_);
    input.rightRepeat = repeatSlow(rightHeldFrames_);
    input.anyAction = std::any_of(actions.begin(), actions.end(), [](bool down) { return down; });
    return input;
}

void FrontendRuntime::updateHeldCounter(bool down, int& heldFrames) {
    heldFrames = down ? heldFrames + 1 : 0;
}

bool FrontendRuntime::repeatSlow(int heldFrames) {
    return heldFrames == 1 || (heldFrames > 0x13 && (heldFrames - 0x14) % 8 == 0);
}

bool FrontendRuntime::pressed(int heldFrames) {
    return heldFrames == 1;
}

FrontendRuntime::TransitionSpec FrontendRuntime::currentTransitionSpec() const {
    switch (state_) {
    case MainState::TitleMenu:
        return cursor_ == 8 ? TransitionSpec{0x5a, 0x1e} : TransitionSpec{0x3c, 0x14};
    case MainState::StageSetup:
        return transitionDirection_ > 0 ? TransitionSpec{0x50, 0x1e} : TransitionSpec{0x32, 10};
    case MainState::StageSelect:
        return pendingState_ == MainState::Gameplay
            ? TransitionSpec{notes::difficulty_overlay_evidence::kLaunchCommitFrames, 0x3c}
            : TransitionSpec{0x32, 10};
    case MainState::AlternateSetup:
    case MainState::Options:
    case MainState::OptionAssist:
    case MainState::ConfigMenu:
    case MainState::KeyConfig:
        return {0x32, 0x14};
    case MainState::Gallery:
    case MainState::Manual:
        return {0x32, 0x14};
    case MainState::Achievement:
        return transitionDirection_ > 0 && pendingState_ == MainState::Gallery
            ? TransitionSpec{0x3c, 0x40000000}
            : TransitionSpec{0x32, 0x14};
    case MainState::EnemyEncyclopedia:
        return transitionDirection_ > 0 && pendingState_ == MainState::Gallery
            ? TransitionSpec{0x3c, 0x40000000}
            : TransitionSpec{0x32, 0x14};
    case MainState::ReplayList:
        return pendingState_ == MainState::ReplayStageSelect
            ? TransitionSpec{0x20, 0x20}
            : TransitionSpec{0x32, 10};
    case MainState::ReplayStageSelect:
        return {0x20, 0x20};
    case MainState::Ranking:
        return pendingState_ == MainState::RankingNotice
            ? TransitionSpec{10, 10}
            : TransitionSpec{0x32, 10};
    case MainState::RankingNotice:
        return {1, 1};
    case MainState::Gameplay:
        break;
    }
    return {0x3c, 0x14};
}

void FrontendRuntime::refreshOptionSlots() {
    setupOptionsByGroup_[static_cast<std::size_t>(std::clamp(setupGroup_, 0, 2))] = optionSlots_;
    playerOption_ = optionSlots_[0];
    subOption_ = optionSlots_[1];
    loadoutId_ = optionSlots_[2];
}

void FrontendRuntime::setState(MainState state, int cursor) {
    state_ = state;
    pendingState_ = state;
    cursor_ = cursor;
    frame_ = 0;
    transitionTimer_ = 0;
    transitionDirection_ = 0;
    selectionDirtyTimer_ = 0;
    if (state == MainState::StageSelect) {
        stageOverlayState_ = 0;
        const int routeIndex = routeMode_ == 1 ? 1 : 0;
        const int minimum = minimumStageForRoute(routeMode_, trialExtraUnlocked_);
        const int maximum = std::max(minimum, maxUnlockedStageByRoute_[static_cast<std::size_t>(routeIndex)]);
        selectedStage_ = std::clamp(savedStageByRoute_[static_cast<std::size_t>(routeIndex)], minimum, maximum);
        const auto node = stageNode(selectedStage_);
        stageCameraX_ = node.x;
        stageCameraY_ = node.y;
        stageCameraStartX_ = node.x;
        stageCameraStartY_ = node.y;
        stageCameraTimer_ = 0;
    }
    else if (state == MainState::Gallery) {
        galleryExpanded_ = false;
        galleryClosing_ = false;
        galleryExpandTimer_ = 0;
        cursor_ = std::clamp(cursor_, 0, kGalleryPictureCount - 1);
    }
    else if (state == MainState::Achievement) {
        cursor_ = std::clamp(cursor_, 0, kAchievementCount - 1);
    }
    else if (state == MainState::EnemyEncyclopedia) {
        cursor_ = std::clamp(cursor_, 1, enemyMaximum_);
    }
    else if (state == MainState::KeyConfig) {
        cursor_ = std::clamp(cursor_, 0, kKeyConfigRows - 1);
        keyCaptureActive_ = false;
        keyCaptureDelay_ = 0;
    }
    else if (state == MainState::ReplayStageSelect) {
        const auto& slot = replaySlots_[static_cast<std::size_t>(std::clamp(replaySlotIndex_, 0, kReplaySlotCount - 1))];
        const int maximum = std::clamp(slot.maximumStage, 1, 9);
        replayStageChoice_ = slot.mode == 1 ? 1 : std::clamp(slot.checkpoint, 1, maximum);
    }
    else if (state == MainState::Ranking) {
        rankingCursor_ = cursor_;
    }
}

void FrontendRuntime::updateTitleMenu(ResourceManager& resources, const InputSnapshot& input) {
    ensureTitleBgm(resources);
    if (frame_ < kTitleInputEnableFrame || frame_ >= 0xe10) {
        return;
    }
    if (input.upRepeat) {
        moveCursor(resources, -1, kTitleMenuCount);
        selectionDirtyTimer_ = 4;
    }
    if (input.downRepeat) {
        moveCursor(resources, 1, kTitleMenuCount);
        selectionDirtyTimer_ = 4;
    }
    if (!input.confirm) {
        return;
    }
    if (!titleRowUnlocked(cursor_, trialUnlocked_, maxUnlockedStageByRoute_[0])) {
        playSound(resources, "SE_se_Error");
        return;
    }

    if (cursor_ >= 0 && cursor_ <= 2) {
        routeMode_ = cursor_;
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::StageSetup);
    }
    else if (cursor_ == 3) {
        replaySlotIndex_ = 0;
        scanReplaySlots(resources);
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::ReplayList);
    }
    else if (cursor_ == 4) {
        rankingCursor_ = 0;
        rankingValue_ = 0;
        ensureRankingGraphs(resources);
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::Ranking);
    }
    else if (cursor_ == 5) {
        ensureGalleryGraphs(resources);
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::Gallery);
    }
    else if (cursor_ == 6) {
        ensureManualGraphs(resources);
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::Manual);
    }
    else if (cursor_ == 7) {
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::Options);
    }
    else if (cursor_ == 8) {
        // The original keeps state 0x02 alive through timer 0x5a, then exits.
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::TitleMenu);
    }
    else {
        playSound(resources, "SE_se_Error");
    }
}

void FrontendRuntime::updateStageSetup(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < kSetupInputEnableFrame || selectionDirtyTimer_ > 0) {
        return;
    }

    // DAT_140e467bc/7b8 are the configured Down/Up actions. In state_03
    // they jump to the Ready row and restore the previous row, respectively.
    if (cursor_ < kStageSetupRows - 1 && input.down) {
        previousSetupCursor_ = cursor_;
        cursor_ = kStageSetupRows - 1;
        selectionDirtyTimer_ = 8;
        playSound(resources, "SE_se_Enter");
        return;
    }
    if (cursor_ == kStageSetupRows - 1 && input.up) {
        cursor_ = std::clamp(previousSetupCursor_, 0, kStageSetupRows - 2);
        selectionDirtyTimer_ = 8;
        playSound(resources, "SE_se_Cancel");
        return;
    }

    if ((input.leftRepeat || input.rightRepeat) && cursor_ < kStageSetupRows - 1) {
        const int delta = input.rightRepeat ? 1 : -1;
        if (cursor_ == 0) {
            refreshOptionSlots();
            setupGroup_ = wrapIndex(setupGroup_ + delta, 3);
            optionSlots_ = setupOptionsByGroup_[static_cast<std::size_t>(setupGroup_)];
            refreshOptionSlots();
            playSound(resources, "SE_se_Select");
        }
        else if (cursor_ >= 1 && cursor_ <= 4) {
            int& slot = optionSlots_[static_cast<std::size_t>(cursor_ - 1)];
            const int slotMax = cursor_ == 4 ? 3 : 1;
            slot = (slot + delta + slotMax + 1) % (slotMax + 1);
            refreshOptionSlots();
            playSound(resources, "SE_se_Select");
        }
        else if (cursor_ == 5) {
            feverMode_ = feverMode_ == 0 ? 1 : 0;
            playSound(resources, "SE_se_Select");
        }
        selectionDirtyTimer_ = 4;
    }
    if (input.cancel) {
        if (cursor_ == 0) {
            playSound(resources, "SE_se_Cancel");
            beginCancelTransition(MainState::TitleMenu);
        }
        else {
            previousSetupCursor_ = cursor_;
            --cursor_;
            selectionDirtyTimer_ = 8;
            playSound(resources, "SE_se_Cancel");
        }
        return;
    }
    if (input.confirm) {
        if (cursor_ < kStageSetupRows - 1) {
            previousSetupCursor_ = cursor_;
            ++cursor_;
            selectionDirtyTimer_ = 8;
            playSound(resources, "SE_se_Enter");
        }
        else {
            refreshOptionSlots();
            if (routeMode_ == 2) {
                selectedStage_ = practiceOptions_[0];
            }
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(routeMode_ == 2 ? MainState::AlternateSetup : MainState::StageSelect);
        }
    }
}

void FrontendRuntime::updateStageSelect(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ <= notes::difficulty_overlay_evidence::kInputEnableFrame) {
        return;
    }

    if (stageOverlayState_ == 0) {
        if ((input.leftRepeat || input.rightRepeat) && stageCameraTimer_ == 0) {
            const int routeIndex = routeMode_ == 1 ? 1 : 0;
            const int minimum = minimumStageForRoute(routeMode_, trialExtraUnlocked_);
            const int maximum = std::max(minimum, maxUnlockedStageByRoute_[static_cast<std::size_t>(routeIndex)]);
            const int next = selectedStage_ + (input.rightRepeat ? 1 : -1);
            if (next >= minimum && next <= maximum) {
                stageCameraStartX_ = stageCameraX_;
                stageCameraStartY_ = stageCameraY_;
                selectedStage_ = next;
                savedStageByRoute_[static_cast<std::size_t>(routeIndex)] = selectedStage_;
                stageCameraTimer_ = 30;
                playSound(resources, "SE_se_Select");
            }
        }
        if (input.confirm && stageCameraTimer_ == 0) {
            stageOverlayState_ = 1;
            selectionDirtyTimer_ = notes::difficulty_overlay_evidence::kLayerSwitchCommitFrames;
            playSound(resources, "SE_se_Enter");
            return;
        }
        if (input.cancel) {
            playSound(resources, "SE_se_Cancel");
            beginCancelTransition(MainState::StageSetup);
        }
        return;
    }

    if (stageOverlayState_ == 1) {
        if (input.cancel) {
            stageOverlayState_ = 0;
            selectionDirtyTimer_ = notes::difficulty_overlay_evidence::kLayerSwitchCommitFrames;
            playSound(resources, "SE_se_Cancel");
            return;
        }
        if (input.leftRepeat || input.rightRepeat) {
            const int delta = input.rightRepeat ? 1 : -1;
            const int next = selectedDifficulty_ + delta;
            if (next >= 0 && next < notes::difficulty_overlay_evidence::kDifficultyCount) {
                selectedDifficulty_ = next;
                selectionDirtyTimer_ = 4;
                playSound(resources, "SE_se_Select");
            }
            else {
                playSound(resources, "SE_se_Error");
            }
        }
        if (input.up && counterUnlocked_ && counterMode_ == 0) {
            counterMode_ = 1;
            selectionDirtyTimer_ = 4;
            playSound(resources, "SE_se_Select");
            return;
        }
        if (input.down && counterUnlocked_ && counterMode_ == 1) {
            counterMode_ = 0;
            selectionDirtyTimer_ = 4;
            playSound(resources, "SE_se_Select");
            return;
        }
        if (input.confirm) {
            const int maxUnlocked = maxDifficultyForStage(maxUnlockedDifficultyByStage_, selectedStage_);
            if (selectedDifficulty_ <= maxUnlocked) {
                stageOverlayState_ = 2;
                const int routeIndex = routeMode_ == 1 ? 1 : 0;
                savedStageByRoute_[static_cast<std::size_t>(routeIndex)] = selectedStage_;
                playSound(resources, "SE_se_Enter");
                stopTitleBgm(resources);
                beginConfirmTransition(MainState::Gameplay);
            }
            else {
                playSound(resources, "SE_se_Error");
            }
        }
    }
}

void FrontendRuntime::updateAlternateSetup(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < kSecondaryMenuInputEnableFrame || selectionDirtyTimer_ > 0) {
        return;
    }

    if (input.upRepeat) {
        moveCursor(resources, -1, kPracticeRows);
        selectionDirtyTimer_ = 1;
    }
    if (input.downRepeat) {
        moveCursor(resources, 1, kPracticeRows);
        selectionDirtyTimer_ = 1;
    }

    if ((input.leftRepeat || input.rightRepeat) && cursor_ < 8) {
        const int delta = input.rightRepeat ? 1 : -1;
        int minimum = 0;
        int maximum = 0;
        bool available = true;
        switch (cursor_) {
        case 0: {
            const int normalMaximum = std::max(1, maxUnlockedStageByRoute_[0]);
            const int current = practiceOptions_[0];
            int next = current;
            if (delta > 0) {
                if (current < normalMaximum) {
                    next = current + 1;
                }
                else if (trialExtraUnlocked_ && current < 10) {
                    next = 10;
                }
                else {
                    available = false;
                }
            }
            else if (current > 1) {
                next = current == 10 ? normalMaximum : current - 1;
            }
            else {
                available = false;
            }
            if (available) {
                practiceOptions_[0] = next;
                practiceOptions_[1] = std::min(practiceOptions_[1], maxDifficultyForStage(maxUnlockedDifficultyByStage_, next));
                practiceOptions_[4] = std::min(practiceOptions_[4], practicePhaseMax(next));
                selectionDirtyTimer_ = 1;
                playSound(resources, "SE_se_Select");
            }
            else {
                playSound(resources, "SE_se_Error");
            }
            return;
        }
        case 1:
            available = practiceOptions_[0] < 10;
            maximum = maxUnlockedDifficultyByStage_[1];
            break;
        case 2:
            available = counterUnlocked_;
            maximum = 1;
            break;
        case 3:
            available = maxUnlockedStageByRoute_[1] >= 14;
            maximum = 1;
            break;
        case 4: maximum = practicePhaseMax(practiceOptions_[0]); break;
        case 5: maximum = 3; break;
        case 6:
        case 7: maximum = 20; break;
        default: break;
        }

        const int next = practiceOptions_[static_cast<std::size_t>(cursor_)] + delta;
        if (available && next >= minimum && next <= maximum) {
            practiceOptions_[static_cast<std::size_t>(cursor_)] = next;
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Select");
        }
        else {
            playSound(resources, "SE_se_Error");
        }
    }

    if (input.cancel) {
        if (cursor_ == 9) {
            playSound(resources, "SE_se_Cancel");
            beginCancelTransition(MainState::StageSetup);
        }
        else {
            cursor_ = 9;
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Cancel");
        }
        return;
    }

    if (input.confirm) {
        if (cursor_ < 8) {
            cursor_ = 8;
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Enter");
            return;
        }
        if (cursor_ == 9) {
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(MainState::StageSetup);
            return;
        }

        const int practiceStage = practiceOptions_[0];
        const bool canStart = practiceStage == 10 ||
            practiceOptions_[1] <= maxDifficultyForStage(maxUnlockedDifficultyByStage_, practiceStage);
        if (!canStart) {
            playSound(resources, "SE_se_Error");
            return;
        }
        selectedStage_ = practiceStage;
        selectedDifficulty_ = practiceOptions_[1];
        counterMode_ = practiceOptions_[2];
        playSound(resources, "SE_se_Enter");
        stopTitleBgm(resources);
        beginConfirmTransition(MainState::Gameplay);
    }
}

void FrontendRuntime::updateGallery(ResourceManager& resources, const InputSnapshot& input) {
    if (galleryExpanded_) {
        if (galleryClosing_) {
            if (galleryExpandTimer_ > 0) {
                --galleryExpandTimer_;
            }
            if (galleryExpandTimer_ == 0) {
                galleryExpanded_ = false;
                galleryClosing_ = false;
            }
            return;
        }
        if (galleryExpandTimer_ < 0x14) {
            ++galleryExpandTimer_;
            return;
        }
        if (input.confirm || input.cancel) {
            galleryClosing_ = true;
            playSound(resources, input.cancel ? "SE_se_Cancel" : "SE_se_Enter");
        }
        return;
    }

    if (frame_ < kSecondaryMenuInputEnableFrame) {
        return;
    }
    if (input.upRepeat && cursor_ > 3) {
        cursor_ -= 4;
        selectionDirtyTimer_ = 4;
        playSound(resources, "SE_se_Select");
        return;
    }
    if (input.downRepeat && cursor_ < 16) {
        cursor_ += 4;
        selectionDirtyTimer_ = 4;
        playSound(resources, "SE_se_Select");
        return;
    }
    if (input.rightRepeat) {
        if (cursor_ % 4 != 3 && cursor_ < kGalleryPictureCount - 1) {
            ++cursor_;
            selectionDirtyTimer_ = 4;
            playSound(resources, "SE_se_Select");
        }
        else {
            ensureAchievementGraphs(resources);
            const int achievement = (cursor_ / 4) * 10;
            playSound(resources, "SE_se_Select");
            setState(MainState::Achievement, achievement);
        }
        return;
    }
    if (input.leftRepeat) {
        if (cursor_ % 4 != 0) {
            --cursor_;
            selectionDirtyTimer_ = 4;
            playSound(resources, "SE_se_Select");
        }
        else {
            ensureEnemyEncyclopediaGraphs(resources);
            playSound(resources, "SE_se_Select");
            setState(MainState::EnemyEncyclopedia, 1);
        }
        return;
    }
    if (input.cancel) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::TitleMenu);
        return;
    }
    if (!input.confirm) {
        return;
    }
    if (galleryUnlocked_[static_cast<std::size_t>(cursor_)] == 0) {
        playSound(resources, "SE_se_Error");
        return;
    }
    galleryViewed_[static_cast<std::size_t>(cursor_)] = 1;
    saveFrontendState(resources);
    galleryExpanded_ = true;
    galleryClosing_ = false;
    galleryExpandTimer_ = 1;
    playSound(resources, "SE_se_Enter");
}

void FrontendRuntime::updateAchievement(ResourceManager& resources, const InputSnapshot& input) {
    const auto markViewed = [&]() {
        const std::size_t index = static_cast<std::size_t>(std::clamp(cursor_, 0, kAchievementCount - 1));
        if (achievementUnlocked_[index] != 0 && achievementViewed_[index] == 0) {
            achievementViewed_[index] = 1;
            saveFrontendState(resources);
        }
    };
    markViewed();
    if (frame_ < kAchievementInputEnableFrame) {
        return;
    }
    if (input.upRepeat && cursor_ >= 10) {
        cursor_ -= 10;
        playSound(resources, "SE_se_Select");
        markViewed();
        return;
    }
    if (input.downRepeat && cursor_ < 40) {
        cursor_ += 10;
        playSound(resources, "SE_se_Select");
        markViewed();
        return;
    }
    if (input.rightRepeat && cursor_ % 10 != 9) {
        ++cursor_;
        playSound(resources, "SE_se_Select");
        markViewed();
        return;
    }
    if (input.leftRepeat) {
        if (cursor_ % 10 != 0) {
            --cursor_;
        }
        else {
            const int galleryIndex = std::min(kGalleryPictureCount - 1, (cursor_ / 10) * 4 + 3);
            cursor_ = galleryIndex;
            playSound(resources, "SE_se_Select");
            beginConfirmTransition(MainState::Gallery);
            return;
        }
        playSound(resources, "SE_se_Select");
        markViewed();
        return;
    }
    if (input.cancel) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::TitleMenu);
        return;
    }

    // Confirm only has an executable branch on the hidden gated final cell,
    // which enters the still-unreconstructed state 0x30. Ordinary cells do
    // not play Enter/Error or otherwise react to Confirm.
}

void FrontendRuntime::updateEnemyEncyclopedia(ResourceManager& resources, const InputSnapshot& input) {
    refreshEnemyEncyclopediaAvailability();
    if (frame_ < kEnemyEncyclopediaInputEnableFrame) {
        return;
    }
    cursor_ = std::clamp(cursor_, 1, enemyMaximum_);
    if (input.upRepeat && downHeldFrames_ == 0) {
        cursor_ = cursor_ > 1 ? cursor_ - 1 : enemyMaximum_;
        playSound(resources, "SE_se_Select");
        return;
    }
    if (input.downRepeat && upHeldFrames_ == 0) {
        cursor_ = cursor_ < enemyMaximum_ ? cursor_ + 1 : 1;
        playSound(resources, "SE_se_Select");
        return;
    }
    if (input.rightRepeat) {
        cursor_ = 0;
        playSound(resources, "SE_se_Select");
        beginConfirmTransition(MainState::Gallery);
        return;
    }
    if (input.cancel) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::TitleMenu);
        return;
    }
}

void FrontendRuntime::updateManual(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < kSecondaryMenuInputEnableFrame) {
        return;
    }
    if (input.upRepeat) {
        moveCursor(resources, -1, kManualPageCount);
        return;
    }
    if (input.downRepeat) {
        moveCursor(resources, 1, kManualPageCount);
        return;
    }
    if (input.cancel) {
        if (cursor_ != kManualPageCount - 1) {
            cursor_ = kManualPageCount - 1;
            selectionDirtyTimer_ = 4;
            playSound(resources, "SE_se_Cancel");
        }
        else {
            playSound(resources, "SE_se_Cancel");
            beginConfirmTransition(MainState::TitleMenu);
        }
        return;
    }
    if (input.confirm && cursor_ == kManualPageCount - 1) {
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::TitleMenu);
    }
}

void FrontendRuntime::updateReplayList(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < kSecondaryMenuInputEnableFrame) {
        return;
    }
    if (input.upRepeat) {
        moveCursor(resources, -1, kReplaySlotCount);
        return;
    }
    if (input.downRepeat) {
        moveCursor(resources, 1, kReplaySlotCount);
        return;
    }
    if (input.cancel) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::TitleMenu);
        return;
    }
    if (!input.confirm) {
        return;
    }
    if (!replaySlots_[static_cast<std::size_t>(cursor_)].valid) {
        playSound(resources, "SE_se_Error");
        return;
    }
    replaySlotIndex_ = cursor_;
    playSound(resources, "SE_se_Enter");
    beginConfirmTransition(MainState::ReplayStageSelect);
}

void FrontendRuntime::updateReplayStageSelect(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < kSecondaryMenuInputEnableFrame) {
        return;
    }
    const auto& slot = replaySlots_[static_cast<std::size_t>(std::clamp(replaySlotIndex_, 0, kReplaySlotCount - 1))];
    const int maximum = std::clamp(slot.maximumStage, 1, 9);
    if (slot.mode == 1 && slot.checkpoint != 10) {
        if (input.upRepeat) {
            if (replayStageChoice_ > 1) {
                --replayStageChoice_;
                playSound(resources, "SE_se_Select");
            }
            else {
                playSound(resources, "SE_se_Error");
            }
            return;
        }
        if (input.downRepeat) {
            if (replayStageChoice_ < maximum) {
                ++replayStageChoice_;
                playSound(resources, "SE_se_Select");
            }
            else {
                playSound(resources, "SE_se_Error");
            }
            return;
        }
    }
    if (input.cancel) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::ReplayList);
        return;
    }
    if (input.confirm) {
        // State 0x0f loads recorded input and hands it to 0x14. StageRuntime does
        // not yet expose that input stream, so launching normal play would be false.
        playSound(resources, "SE_se_Error");
    }
}

void FrontendRuntime::updateRanking(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < 0x3c) {
        return;
    }
    const int categoryCount = trialExtraUnlocked_ ? 5 : 4;
    if (input.leftRepeat) {
        moveCursor(resources, -1, categoryCount);
        rankingCursor_ = cursor_;
        return;
    }
    if (input.rightRepeat) {
        moveCursor(resources, 1, categoryCount);
        rankingCursor_ = cursor_;
        return;
    }
    if (input.upRepeat || input.downRepeat) {
        if (cursor_ == 4) {
            rankingValue_ = rankingValue_ < 5 ? rankingValue_ + 5 : rankingValue_ - 5;
        }
        else {
            rankingValue_ = wrapIndex(rankingValue_ + (input.downRepeat ? 1 : -1), 10);
        }
        playSound(resources, "SE_se_Select");
        return;
    }
    if (input.cancel) {
        playSound(resources, "SE_se_Cancel");
        beginCancelTransition(MainState::TitleMenu);
        return;
    }
    if (input.confirm) {
        rankingCursor_ = cursor_;
        playSound(resources, "SE_se_Enter");
        beginConfirmTransition(MainState::RankingNotice);
    }
}

void FrontendRuntime::updateRankingNotice(ResourceManager& resources, const InputSnapshot& input) {
    // The original calls the Steam leaderboard API at frame 0x3c. The local
    // reconstruction uses a Steam stub, so frame 1 (No data) is authoritative.
    if (frame_ >= 0x3c && (input.confirm || input.cancel)) {
        playSound(resources, "SE_se_Cancel");
        setState(MainState::Ranking, rankingCursor_);
    }
}

void FrontendRuntime::updateOptions(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < kSecondaryMenuInputEnableFrame || selectionDirtyTimer_ > 0) {
        return;
    }

    const bool upCommand = input.upRepeat && downHeldFrames_ == 0;
    const bool downCommand = input.downRepeat && upHeldFrames_ == 0;
    if (upCommand || downCommand) {
        moveCursor(resources, downCommand ? 1 : -1, kOptionsRows);
        selectionDirtyTimer_ = 1;
    }

    const bool leftCommand = input.leftRepeat && rightHeldFrames_ == 0;
    const bool rightCommand = input.rightRepeat && leftHeldFrames_ == 0;
    if ((leftCommand || rightCommand) && cursor_ < 4) {
        const int delta = rightCommand ? 1 : -1;
        bool changed = true;
        if (cursor_ == 0) {
            const int next = bgmVolume_ + delta;
            if (next >= 0 && next <= 10) {
                bgmVolume_ = next;
                const int handle = resources.soundHandleById("BGM_bgm_Title");
                if (handle != -1) {
                    ChangeVolumeSoundMem(bgmVolume_ * 0x19, handle);
                }
            }
            else {
                changed = false;
            }
        }
        else if (cursor_ == 1) {
            const int next = seVolume_ + delta;
            if (next >= 0 && next <= 10) {
                seVolume_ = next;
            }
            else {
                changed = false;
            }
        }
        else if (cursor_ == 2) {
            language_ = wrapIndex(language_ + delta, 4);
        }
        else if (cursor_ == 3) {
            if (dataWindowUnlocked_) {
                dataWindowEnabled_ = dataWindowEnabled_ == 0 ? 1 : 0;
            }
            else {
                changed = false;
            }
        }
        selectionDirtyTimer_ = 1;
        playSound(resources, changed ? "SE_se_Select" : "SE_se_Error");
    }

    // DAT_140e467fc suppresses Confirm/Cancel after any directional action
    // accepted earlier in the same frame.
    if (selectionDirtyTimer_ > 0) {
        return;
    }

    // The executable tests Confirm before Cancel. This matters when both
    // actions are pressed on a command row.
    if (input.confirm && cursor_ >= 4) {
        if (cursor_ == 4) {
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(MainState::OptionAssist);
        }
        else if (cursor_ == 5) {
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(MainState::ConfigMenu);
        }
        else if (cursor_ == 6) {
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(MainState::KeyConfig);
        }
        else if (cursor_ == 7) {
            if (!shortcutUnlocked_) {
                playSound(resources, "SE_se_Error");
                return;
            }
            routeMode_ = -1;
            selectedStage_ = 1;
            playSound(resources, "SE_se_Enter");
            stopTitleBgm(resources);
            beginConfirmTransition(MainState::Gameplay);
        }
        else {
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(MainState::TitleMenu);
        }
        return;
    }

    if (input.cancel) {
        if (cursor_ == 8) {
            playSound(resources, "SE_se_Cancel");
            beginCancelTransition(MainState::TitleMenu);
        }
        else {
            cursor_ = 8;
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Cancel");
        }
    }
}

void FrontendRuntime::updateOptionAssist(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < kSecondaryMenuInputEnableFrame || selectionDirtyTimer_ > 0) {
        return;
    }
    const bool upCommand = input.upRepeat && downHeldFrames_ == 0;
    const bool downCommand = input.downRepeat && upHeldFrames_ == 0;
    if (upCommand || downCommand) {
        moveCursor(resources, downCommand ? 1 : -1, kOptionAssistRows);
        selectionDirtyTimer_ = 1;
    }
    const bool leftCommand = input.leftRepeat && rightHeldFrames_ == 0;
    const bool rightCommand = input.rightRepeat && leftHeldFrames_ == 0;
    if ((leftCommand || rightCommand) && cursor_ < 2) {
        if (cursor_ == 0) {
            controlModeEnabled_ = controlModeEnabled_ == 0 ? 1 : 0;
        }
        else {
            const int delta = rightCommand ? 1 : -1;
            helpMode_ = wrapIndex(helpMode_ + delta, 7);
        }
        selectionDirtyTimer_ = 1;
        playSound(resources, "SE_se_Select");
    }
    if (selectionDirtyTimer_ > 0) {
        return;
    }

    if (input.confirm && cursor_ >= 2) {
        if (cursor_ == 2) {
            controlModeEnabled_ = 1;
            helpMode_ = 6;
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Enter");
        }
        else {
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(MainState::Options);
        }
        return;
    }

    if (input.cancel) {
        if (cursor_ == 3) {
            playSound(resources, "SE_se_Cancel");
            beginCancelTransition(MainState::Options);
        }
        else {
            cursor_ = 3;
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Cancel");
        }
    }
}

void FrontendRuntime::updateConfigMenu(ResourceManager& resources, const InputSnapshot& input) {
    if (frame_ < kSecondaryMenuInputEnableFrame || selectionDirtyTimer_ > 0) {
        return;
    }
    const bool upCommand = input.upRepeat && downHeldFrames_ == 0;
    const bool downCommand = input.downRepeat && upHeldFrames_ == 0;
    if (upCommand || downCommand) {
        moveCursor(resources, downCommand ? 1 : -1, kConfigMenuRows);
        selectionDirtyTimer_ = 1;
    }
    const bool leftCommand = input.leftRepeat && rightHeldFrames_ == 0;
    const bool rightCommand = input.rightRepeat && leftHeldFrames_ == 0;
    if ((leftCommand || rightCommand) && cursor_ < 7) {
        const int delta = rightCommand ? 1 : -1;
        if (cursor_ == 0) {
            systemConfig_[0] = systemConfig_[0] == 0 ? 1 : 0;
        }
        else if (cursor_ == 1) {
            systemConfig_[1] = wrapIndex(systemConfig_[1] + delta, 3);
        }
        else if (cursor_ == 6) {
            systemConfig_[6] = wrapIndex(systemConfig_[6] + delta, 4);
        }
        else {
            systemConfig_[static_cast<std::size_t>(cursor_)] =
                systemConfig_[static_cast<std::size_t>(cursor_)] == 0 ? 1 : 0;
        }
        selectionDirtyTimer_ = 1;
        playSound(resources, "SE_se_Select");
    }
    if (selectionDirtyTimer_ > 0) {
        return;
    }

    if (input.confirm && cursor_ >= 7) {
        if (cursor_ == 7) {
            const int fullScreen = systemConfig_[0];
            const int soundType = systemConfig_[6];
            systemConfig_ = {{fullScreen, 0, 1, 0, 1, 0, soundType}};
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Enter");
        }
        else {
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(MainState::Options);
        }
        return;
    }

    if (input.cancel) {
        if (cursor_ == 8) {
            playSound(resources, "SE_se_Cancel");
            beginCancelTransition(MainState::Options);
        }
        else {
            cursor_ = 8;
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Cancel");
        }
    }
}

void FrontendRuntime::updateKeyConfig(ResourceManager& resources, const InputSnapshot& input) {
    if (keyCaptureActive_) {
        // DAT_140e467fc keeps capture dormant until the menu action used to
        // enter it has been released. Unbound physical inputs do not delay it.
        if (keyCaptureDelay_ < 0) {
            if (!input.anyAction) {
                keyCaptureDelay_ = 0;
            }
            return;
        }

        bool captured = false;
        if (controlDevice_ < 5) {
            const int padState = GetJoypadInputState(DX_INPUT_PAD1);
            const auto unsignedPadState = static_cast<std::uint32_t>(padState);
            if (padState == -1 || (unsignedPadState & 0x0fU) != 0) {
                return;
            }

            const int first = cursor_ < 6 ? 4 : 6;
            const int last = cursor_ < 6 ? 6 : 11;
            std::uint32_t mask = 0x10U;
            for (int index = 0; index < 28; ++index) {
                if ((unsignedPadState & mask) != 0) {
                    const int binding = static_cast<int>(mask);
                    const int previous = controllerBindings_[static_cast<std::size_t>(cursor_)];
                    for (int action = first; action < last; ++action) {
                        if (action != cursor_ && controllerBindings_[static_cast<std::size_t>(action)] == binding) {
                            controllerBindings_[static_cast<std::size_t>(action)] = previous;
                        }
                    }
                    controllerBindings_[static_cast<std::size_t>(cursor_)] = binding;
                    captured = true;
                    playSound(resources, "SE_se_Enter");
                }
                mask <<= 1;
            }
        }
        else {
            std::array<char, 256> keyState{};
            if (GetHitKeyStateAll(keyState.data()) == -1) {
                return;
            }

            const int first = cursor_ < 4 ? 0 : (cursor_ < 6 ? 4 : 6);
            const int last = cursor_ < 4 ? 4 : (cursor_ < 6 ? 6 : 11);
            for (const int key : kKeyboardPromptKeys) {
                if (key > 0 && key < static_cast<int>(keyState.size()) &&
                    keyState[static_cast<std::size_t>(key)] != 0) {
                    const int previous = keyBindings_[static_cast<std::size_t>(cursor_)];
                    for (int action = first; action < last; ++action) {
                        if (action != cursor_ && keyBindings_[static_cast<std::size_t>(action)] == key) {
                            keyBindings_[static_cast<std::size_t>(action)] = previous;
                        }
                    }
                    keyBindings_[static_cast<std::size_t>(cursor_)] = key;
                    captured = true;
                    playSound(resources, "SE_se_Enter");
                }
            }
        }
        if (!captured) {
            return;
        }
        keyCaptureActive_ = false;
        keyCaptureDelay_ = 0;
        // Only the keyboard path writes DAT_140e46014 = 8.
        selectionDirtyTimer_ = controlDevice_ == 5 ? 8 : 0;
        return;
    }

    if (frame_ < kSecondaryMenuInputEnableFrame || selectionDirtyTimer_ > 0) {
        return;
    }
    const bool upCommand = input.upRepeat && downHeldFrames_ == 0;
    const bool downCommand = input.downRepeat && upHeldFrames_ == 0;
    if (upCommand || downCommand) {
        moveCursor(resources, downCommand ? 1 : -1, kKeyConfigRows);
        selectionDirtyTimer_ = 1;
    }
    if (selectionDirtyTimer_ > 0) {
        return;
    }

    if (input.confirm) {
        if (cursor_ < 11) {
            if (controlDevice_ < 5 && cursor_ < 4) {
                playSound(resources, "SE_se_Error");
                return;
            }
            keyCaptureActive_ = true;
            keyCaptureDelay_ = -1;
            playSound(resources, "SE_se_Enter");
        }
        else if (cursor_ == 11) {
            if (controlDevice_ < 5) {
                controllerBindings_ = defaultControllerBindings(controlDevice_);
            }
            else {
                keyBindings_ = kDefaultKeyBindings;
            }
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Enter");
        }
        else {
            playSound(resources, "SE_se_Enter");
            beginConfirmTransition(MainState::Options);
        }
        return;
    }

    if (input.cancel) {
        if (cursor_ == 12) {
            // State 0x0d uses the same positive wipe for Confirm and Cancel.
            playSound(resources, "SE_se_Cancel");
            beginConfirmTransition(MainState::Options);
        }
        else {
            cursor_ = 12;
            selectionDirtyTimer_ = 1;
            playSound(resources, "SE_se_Cancel");
        }
    }
}

void FrontendRuntime::updateTransition(ResourceManager& resources) {
    const auto spec = currentTransitionSpec();
    transitionTimer_ += transitionDirection_;
    const bool commitForward = transitionDirection_ > 0 && transitionTimer_ >= spec.commitFrames;
    const bool commitBackward = transitionDirection_ < 0 && transitionTimer_ <= -spec.commitFrames;
    if (!commitForward && !commitBackward) {
        return;
    }

    const auto source = state_;
    const int sourceCursor = cursor_;
    const auto target = pendingState_;
    if (source == MainState::TitleMenu && sourceCursor == 8 && commitForward && target == MainState::TitleMenu) {
        transitionTimer_ = 0;
        transitionDirection_ = 0;
        PostQuitMessage(0);
        return;
    }

    if (source == MainState::ConfigMenu) {
        saveSystemConfig(resources);
    }
    else if (source != MainState::TitleMenu && source != MainState::Gameplay) {
        saveFrontendState(resources);
    }

    int targetCursor = 0;
    if (target == MainState::TitleMenu) {
        if (source == MainState::StageSetup) {
            targetCursor = std::clamp(routeMode_, 0, 2);
        }
        else if (source == MainState::Options || source == MainState::OptionAssist ||
                 source == MainState::ConfigMenu || source == MainState::KeyConfig) {
            targetCursor = 7;
        }
        else if (source == MainState::ReplayList || source == MainState::ReplayStageSelect) {
            targetCursor = 3;
        }
        else if (source == MainState::Ranking || source == MainState::RankingNotice) {
            targetCursor = 4;
        }
        else if (source == MainState::Gallery || source == MainState::Achievement ||
                 source == MainState::EnemyEncyclopedia) {
            targetCursor = 5;
        }
        else if (source == MainState::Manual) {
            targetCursor = 6;
        }
    }
    else if (target == MainState::ReplayList) {
        targetCursor = std::clamp(replaySlotIndex_, 0, kReplaySlotCount - 1);
    }
    else if (target == MainState::Ranking) {
        targetCursor = rankingCursor_;
    }
    else if (target == MainState::Gallery && source == MainState::Achievement) {
        targetCursor = std::clamp(sourceCursor, 0, kGalleryPictureCount - 1);
    }
    else if (target == MainState::Options) {
        if (source == MainState::OptionAssist) {
            targetCursor = 4;
        }
        else if (source == MainState::ConfigMenu) {
            targetCursor = 5;
        }
        else if (source == MainState::KeyConfig) {
            targetCursor = 6;
        }
    }
    setState(target, targetCursor);
    if ((source == MainState::Achievement || source == MainState::EnemyEncyclopedia) &&
        target == MainState::Gallery) {
        frame_ = 0x3c;
    }
    if (source == MainState::ReplayStageSelect && target == MainState::ReplayList) {
        // state_0f restores state_0e at frame 0x3d after its -0x20 cancel timer.
        frame_ = 0x3d;
    }
    if (target == MainState::Gameplay) {
        refreshOptionSlots();
        gameplayRequest_ = {};
        gameplayRequest_.requested = true;
        gameplayRequest_.stage = selectedStage_;
        gameplayRequest_.routeMode = routeMode_;
        gameplayRequest_.setupGroup = setupGroup_;
        gameplayRequest_.playerOption = playerOption_;
        gameplayRequest_.subOption = subOption_;
        gameplayRequest_.loadoutId = loadoutId_;
        gameplayRequest_.difficulty = selectedDifficulty_;
        gameplayRequest_.counterMode = counterMode_;
        gameplayRequest_.specialMode = feverMode_;
        gameplayRequest_.dataWindowEnabled = dataWindowEnabled_;
        gameplayRequest_.soundEffectVolume = seVolume_;
        gameplayRequest_.itemVisibility = systemConfig_[3];
        gameplayRequest_.likeStyle = systemConfig_[5];
        gameplayRequest_.optionSlots = optionSlots_;
        gameplayRequest_.keyboardBindings = keyBindings_;
        gameplayRequest_.controllerBindings = controllerBindings_;
        gameplayRequest_.controlDevice = controlDevice_;
        gameplayRequest_.controlModeEnabled = controlModeEnabled_;
        gameplayRequest_.helpMode = helpMode_;
        const std::size_t helpProgressOffset = 0xac +
            static_cast<std::size_t>((selectedStage_ * 3 + setupGroup_) * 50 + selectedDifficulty_) * 4;
        std::int32_t helpProgress = 0;
        if (helpProgressOffset + sizeof(helpProgress) <= saveBackingBytes_.size()) {
            std::memcpy(&helpProgress, saveBackingBytes_.data() + helpProgressOffset,
                        sizeof(helpProgress));
        }
        gameplayRequest_.helpAutoProgress = static_cast<int>(helpProgress);
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

    // state_02: DAT_14053ae48=400, DAT_14053adb4=200 and the logo wave is
    // -5*sin(frame*pi/120). The queued graph coordinates are image centers.
    if (titleLogo != -1) {
        const float logoY = 200.0f - 5.0f * std::sin(static_cast<float>(frame_) * kPi / 120.0f);
        DrawRotaGraphF(400.0f, logoY, 1.0, 0.0, titleLogo, TRUE);
    }

    // The two neighbours use the exact state_02 constants: x step 80, y step
    // 40 with one extra step away from the selected row, and scales 0.7/0.6.
    constexpr float centerX = 400.0f;
    constexpr float centerY = 520.0f;
    for (int distance = 2; distance >= -2; --distance) {
        const int index = (cursor_ + distance + kTitleMenuCount) % kTitleMenuCount;
        const int handle = resources.graphFrameById("GFX_system_TitleMenu", index);
        const bool selected = distance == 0;
        int alpha = selected ? 255 : (3 - std::abs(distance)) * 0x40;
        if (selected && !titleRowUnlocked(index, trialUnlocked_, maxUnlockedStageByRoute_[0])) {
            alpha = 0x80;
        }
        if (transitionTimer_ != 0 && selected && wrapIndex(transitionTimer_ + 10000, 4) < 2) {
            alpha = 0x60;
        }
        const float x = centerX + static_cast<float>(distance) * 80.0f;
        const int sign = distance < 0 ? -1 : 1;
        const float y = selected ? centerY : centerY + static_cast<float>(sign * (std::abs(distance) + 1) * 40);
        const double scale = selected
            ? 1.0 + std::sin(static_cast<double>(selectionDirtyTimer_) * kPi / 8.0) * 0.1
            : 0.8 - static_cast<double>(std::abs(distance)) * 0.1;
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        if (handle != -1) {
            DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
        }
        else {
            const int halfW = static_cast<int>(notes::title_layout::kMenuFrameWidth * scale * 0.5);
            const int halfH = static_cast<int>(notes::title_layout::kMenuFrameHeight * scale * 0.5);
            DrawBox(static_cast<int>(x) - halfW, static_cast<int>(y) - halfH,
                    static_cast<int>(x) + halfW, static_cast<int>(y) + halfH,
                    GetColor(255, 255, 255), FALSE);
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

        if (selected) {
            const int sub = resources.graphFrameById("GFX_system_TitleMenu2", index);
            if (sub != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
                DrawRotaGraphF(centerX, centerY + 32.0f, scale, 0.0, sub, TRUE);
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

    const int menuTitle = resources.graphFrameById("GFX_system_MenuTitle", 0);
    if (menuTitle != -1) {
        DrawGraph(notes::stage_setup_evidence::kMenuTitleOrigin.x, notes::stage_setup_evidence::kMenuTitleOrigin.y, menuTitle, TRUE);
    }

    const int standFrame = standFrameForSetup(cursor_, setupGroup_, optionSlots_);
    drawFrameScaledAlpha(resources, "GFX_system_Stand", standFrame,
                         320.0f, 495.0f, 1.0, 0x20);
    drawFrameScaledAlpha(resources, "GFX_system_Stand", standFrame,
                         300.0f, 480.0f, 1.0, 255);

    drawFrameScaledAlpha(resources, "GFX_system_EquipMenu", statusEquipMenuFrameForGroup(setupGroup_),
                         160.0f, 600.0f, 1.0, 255);

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
        const bool selected = cursor_ == i + 1;
        const int alpha = cursor_ > i ? 255 : 0x80;
        const int frame = equipMenuFrameForSetupItem(i, setupGroup_, optionSlots_, feverMode_);
        drawFrameScaledAlpha(resources, "GFX_system_EquipMenu", frame, static_cast<float>(x), static_cast<float>(y), 1.0, alpha);
        if (selected) {
            const int arrow = resources.graphFrameById("GFX_effect_Effect_s", 1);
            if (arrow != -1) {
                DrawRotaGraphF(static_cast<float>(x - 180), static_cast<float>(y), 1.2, 0.0, arrow, TRUE);
                DrawRotaGraphF(static_cast<float>(x + 180), static_cast<float>(y), 1.2, kPi, arrow, TRUE);
            }
        }
    }

    const int textBox = resources.graphFrameById("GFX_system_TextBox", 0);
    if (textBox != -1) {
        DrawRotaGraphF(640.0f, 650.0f, 1.0, 0.0, textBox, TRUE);
    }
    else {
        DrawBox(340, 600, 940, 700,
                GetColor(24, 28, 48), TRUE);
    }
    if (cursor_ == 0 || cursor_ == 6) {
        drawFrameScaledAlpha(resources, "GFX_system_TextIcon", setupGroup_, 390.0f, 650.0f, 1.0, 255);
    }
}

void FrontendRuntime::drawStageSelect(const ResourceManager& resources) const {
    const int titleBack = resources.graphHandleById("GFX_system_TitleBack");
    if (titleBack != -1) {
        DrawGraph(0, 0, titleBack, TRUE);
    }
    else {
        DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(12, 16, 34), TRUE);
    }

    const int menuTitle = resources.graphFrameById("GFX_system_MenuTitle", 1);
    if (menuTitle != -1) {
        DrawGraph(0, 0, menuTitle, TRUE);
    }

    drawFrameScaledAlpha(resources, "GFX_system_Stand", setupGroup_ * 10, 200.0f, 480.0f, 1.0, 0x80);

    const int routeIndex = routeMode_ == 1 ? 1 : 0;
    const int firstStage = minimumStageForRoute(routeMode_, trialExtraUnlocked_);
    const int lastStage = std::max(firstStage, maxUnlockedStageByRoute_[static_cast<std::size_t>(routeIndex)]);
    for (int stage = firstStage; stage <= lastStage; ++stage) {
        const auto node = stageNode(stage);
        const float x = 640.0f + node.x - stageCameraX_;
        const float y = 320.0f + node.y - stageCameraY_;
        if (x < -700.0f || x > 1980.0f || y < -800.0f || y > 1520.0f) {
            continue;
        }

        const bool selected = stage == selectedStage_;
        drawFrameScaledAlpha(resources, "GFX_system_StageFrame", 0, x, y, 1.0, 0x80);
        drawFrameScaledAlpha(resources, "GFX_system_StageFrame", 1, x, y, 1.0, selected ? 0xff : 0x80);
        drawFrameScaledAlpha(resources, "GFX_system_StageFrame2", stageFrame2ForStage(stage),
                             x, y - 50.0f, 1.0, selected ? 0xff : 0x80);
        drawFrameScaledAlpha(resources, "GFX_system_MapMenu", mapMenuFrameForStage(stage),
                             x, y - 240.0f, 1.0, selected ? 0xff : 0x80);
    }

    const int maxUnlocked = maxDifficultyForStage(maxUnlockedDifficultyByStage_, selectedStage_);
    if (stageOverlayState_ >= 1) {
        const bool locked = selectedDifficulty_ > maxUnlocked;
        const double difficultyBump = 1.0 + static_cast<double>(std::abs(selectionDirtyTimer_)) * 0.012;
        drawFrameScaledAlpha(resources, "GFX_system_MapMenu2", notes::difficulty_overlay_evidence::kMapMenu2BaseFrame,
                             static_cast<float>(notes::difficulty_overlay_evidence::kBaseMapMenu2.x),
                             static_cast<float>(notes::difficulty_overlay_evidence::kBaseMapMenu2.y), 1.0, 255);
        drawFrameScaledAlpha(resources, "GFX_system_MapMenu2",
                             notes::difficulty_overlay_evidence::kMapMenu2DifficultyBaseFrame + selectedDifficulty_,
                             static_cast<float>(notes::difficulty_overlay_evidence::kDifficultyMapMenu2.x),
                             static_cast<float>(notes::difficulty_overlay_evidence::kDifficultyMapMenu2.y),
                             difficultyBump, locked ? 0x80 : 0xff);
        if (locked) {
            const int handle = resources.graphFrameById("GFX_system_MapMenu2", notes::difficulty_overlay_evidence::kMapMenu2LockedFrame);
            if (handle != -1) {
                DrawRotaGraphF(static_cast<float>(notes::difficulty_overlay_evidence::kDifficultyMapMenu2.x),
                               static_cast<float>(notes::difficulty_overlay_evidence::kDifficultyMapMenu2.y),
                               difficultyBump, 0.0, handle, TRUE);
            }
        }
        if (!locked) {
            drawFrameScaledAlpha(resources, "GFX_system_DifficultyTips", selectedDifficulty_,
                                 static_cast<float>(notes::difficulty_overlay_evidence::kDifficultyTips.x),
                                 static_cast<float>(notes::difficulty_overlay_evidence::kDifficultyTips.y), 1.0, 255);
        }
        drawFrameScaledAlpha(resources, "GFX_system_MapMenu2", notes::difficulty_overlay_evidence::kMapMenu2CounterFrame,
                             static_cast<float>(notes::difficulty_overlay_evidence::kCounterMapMenu2.x),
                             static_cast<float>(notes::difficulty_overlay_evidence::kCounterMapMenu2.y),
                             1.0, counterMode_ ? 0xff : 0x80);
        const int arrow = resources.graphFrameById("GFX_effect_Effect_s", notes::difficulty_overlay_evidence::kArrowEffectFrame);
        if (arrow != -1) {
            const double angle = counterMode_ ? kPi * 0.5 : kPi * 1.5;
            DrawRotaGraphF(static_cast<float>(notes::difficulty_overlay_evidence::kCounterArrow.x),
                           static_cast<float>(notes::difficulty_overlay_evidence::kCounterArrow.y),
                           0.58, angle, arrow, TRUE);
            if (selectedDifficulty_ < notes::difficulty_overlay_evidence::kDifficultyCount - 1) {
                DrawRotaGraphF(760.0f, static_cast<float>(notes::difficulty_overlay_evidence::kDifficultyMapMenu2.y),
                               0.50, 0.0, arrow, TRUE);
            }
            if (selectedDifficulty_ > 0) {
                DrawRotaGraphF(520.0f, static_cast<float>(notes::difficulty_overlay_evidence::kDifficultyMapMenu2.y),
                               0.50, kPi, arrow, TRUE);
            }
        }
    }
}

void FrontendRuntime::drawAlternateSetup(const ResourceManager& resources) const {
    const int titleBack = resources.graphHandleById("GFX_system_TitleBack");
    if (titleBack != -1) {
        DrawGraph(0, 0, titleBack, TRUE);
    }
    const int menuTitle = resources.graphFrameById("GFX_system_MenuTitle", 2);
    if (menuTitle != -1) {
        DrawGraph(0, 0, menuTitle, TRUE);
    }

    drawFrameScaledAlpha(resources, "GFX_system_Stand", setupGroup_ * 10, 900.0f, 480.0f, 1.0, 0x80);

    const int practiceStage = practiceOptions_[0];
    const int maximumDifficulty = maxDifficultyForStage(maxUnlockedDifficultyByStage_, practiceStage);
    const bool validDifficulty = practiceStage == 10 || practiceOptions_[1] <= maximumDifficulty;
    for (int i = 0; i < kPracticeRows; ++i) {
        bool available = true;
        if (i == 1) available = validDifficulty;
        if (i == 2) available = counterUnlocked_;
        if (i == 3) available = maxUnlockedStageByRoute_[1] >= 14;
        if (i == 8) available = validDifficulty;
        int alpha = i == cursor_ ? 0xff : 0x60;
        if (!available) alpha = std::min(alpha, 0x80);
        if (i == cursor_ && transitionTimer_ != 0 && wrapIndex(transitionTimer_ + 10000, 4) >= 2) {
            alpha = std::min(alpha, 0x60);
        }
        drawPathFrameScaledAlpha(resources, kPracticeMenuPath, i, 420.0f,
                                 static_cast<float>(i * 0x2d + 0x82), 1.0, alpha);

        const float y = static_cast<float>(i * 0x2d + 0x82);
        switch (i) {
        case 0:
            if (practiceStage > 9) {
                drawPathFrameScaledAlpha(resources, kPracticeMenuPath, 17, 575.0f, y, 1.0, alpha);
            }
            else {
                drawConfigNumber(resources, 575.0f, y, practiceStage, false, alpha);
            }
            break;
        case 1:
            drawPathFrameScaledAlpha(resources, kPracticeMenuPath,
                                     practiceStage > 9 ? 17 : 12 + practiceOptions_[1],
                                     680.0f, y, 1.0, available ? alpha : 0x80);
            break;
        case 2:
        case 3:
            drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2",
                                 practiceOptions_[static_cast<std::size_t>(i)] == 1 ? 0 : 1,
                                 680.0f, y, 1.0, alpha);
            break;
        case 4: {
            const int maximumPhase = practicePhaseMax(practiceStage);
            const int phase = practiceOptions_[4];
            drawPathFrameScaledAlpha(resources, kPracticeMenuPath, phase < maximumPhase ? 10 : 11,
                                     680.0f, y, 1.0, alpha);
            if (phase < maximumPhase) {
                drawConfigNumber(resources, 760.0f, y, phase + 1, false, alpha);
            }
            break;
        }
        case 5:
            if (practiceOptions_[5] > 2) {
                drawPathFrameScaledAlpha(resources, kPracticeMenuPath, 18, 575.0f, y, 1.0, alpha);
            }
            else {
                drawConfigNumber(resources, 575.0f, y, practiceOptions_[5], false, alpha);
            }
            break;
        case 6:
        case 7: {
            const int value = practiceOptions_[static_cast<std::size_t>(i)];
            if (value > 19) {
                drawPathFrameScaledAlpha(resources, kPracticeMenuPath, 18, 680.0f, y, 1.0, alpha);
            }
            else {
                drawConfigNumber(resources, 680.0f, y, value * 5, true, alpha);
            }
            break;
        }
        default:
            break;
        }
    }
}

void FrontendRuntime::drawGallery(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 5, language_);
    const char* picturePath = localizedPath(kGalleryPicturePaths, language_);
    const int selected = std::clamp(cursor_, 0, kGalleryPictureCount - 1);

    for (int index = 0; index < kGalleryPictureCount; ++index) {
        const int row = index / 4;
        const float x = galleryCellX(index);
        const float y = 130.0f + static_cast<float>(row) * 110.0f;
        const bool unlocked = galleryUnlocked_[static_cast<std::size_t>(index)] != 0;
        int alpha = unlocked ? 0xff : 0x60;
        if (unlocked && galleryViewed_[static_cast<std::size_t>(index)] == 0) {
            alpha = 0xc0 - static_cast<int>(std::sin(static_cast<float>(frame_) * kPi / 60.0f) * 0x40);
        }
        if (unlocked) {
            drawPathFrameScaledAlpha(resources, picturePath, index, x, y, 0.13, std::clamp(alpha, 0, 255));
        }
        else {
            SetDrawBright(0, 0, 0);
            drawPathFrameScaledAlpha(resources, picturePath, index, x, y, 0.13, alpha);
            SetDrawBright(255, 255, 255);
        }

        if (index == selected) {
            const int frameHandle = resources.graphHandle(kGalleryFramePath);
            if (frameHandle != -1) {
                DrawRotaGraphF(x, y, 1.0, 0.0, frameHandle, TRUE);
            }
        }
    }

    if (galleryExpanded_ && galleryUnlocked_[static_cast<std::size_t>(selected)] != 0) {
        const int row = selected / 4;
        const float sourceX = galleryCellX(selected);
        const float sourceY = 130.0f + static_cast<float>(row) * 110.0f;
        const float phase = std::clamp(static_cast<float>(galleryExpandTimer_) / 20.0f, 0.0f, 1.0f);
        const float eased = std::sin(phase * kPi * 0.5f);
        const float x = sourceX + (640.0f - sourceX) * phase;
        const float y = sourceY + (360.0f - sourceY) * phase;
        const double scale = 0.13 + 0.87 * static_cast<double>(eased);
        drawPathFrameScaledAlpha(resources, picturePath, selected, x, y, scale, 255);
    }
    else if (galleryUnlocked_[static_cast<std::size_t>(selected)] != 0) {
        const int noticeFrame = resources.graphHandle(kNoticeFramePath);
        if (noticeFrame != -1) {
            DrawRotaGraphF(640.0f, 668.0f, 1.0, 0.0, noticeFrame, TRUE);
        }
        drawPathFrameScaledAlpha(resources, localizedPath(kGalleryNoticePaths, language_), selected,
                                 640.0f, 668.0f, 1.0, 255);
    }
}

void FrontendRuntime::drawAchievement(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 5, language_);

    float xOffset = 0.0f;
    if (frame_ < kAchievementInputEnableFrame) {
        xOffset = 1280.0f - 1280.0f *
            std::sin(static_cast<float>(frame_) * kPi / 120.0f);
    }
    else if (transitionDirection_ > 0 && pendingState_ == MainState::Gallery) {
        xOffset = 1280.0f *
            std::sin(static_cast<float>(transitionTimer_) * kPi / 120.0f);
    }

    const int selected = std::clamp(cursor_, 0, kAchievementCount - 1);
    for (int index = 0; index < kAchievementCount; ++index) {
        const int row = index / 10;
        const int column = index % 10;
        const float x = xOffset + (row % 2 == 0 ? 190.0f : 150.0f) +
            static_cast<float>(column) * 110.0f;
        const float y = 130.0f + static_cast<float>(row) * 110.0f;
        const bool unlocked = achievementUnlocked_[static_cast<std::size_t>(index)] != 0;
        int alpha = unlocked ? 0xff : 0x60;
        if (unlocked && achievementViewed_[static_cast<std::size_t>(index)] == 0) {
            alpha = 0xc0 - static_cast<int>(std::sin(static_cast<float>(frame_) * kPi / 60.0f) * 0x40);
        }
        const double scale = index == selected
            ? 1.0 + std::sin(static_cast<double>(frame_) * kPi / 32.0) * 0.05
            : 1.0;
        if (!unlocked) {
            SetDrawBright(0, 0, 0);
        }
        drawPathFrameScaledAlpha(resources, kAchievementPath,
                                 kAchievementIconFrames[static_cast<std::size_t>(index)],
                                 x, y, scale, std::clamp(alpha, 0, 255));
        if (!unlocked) {
            SetDrawBright(255, 255, 255);
        }
        if (index == selected) {
            const int selection = resources.graphFrame(kAchievementPath, 4);
            if (selection != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                                 0x50 + static_cast<int>(std::sin(static_cast<float>(frame_) * kPi / 32.0f) * 0x20));
                DrawRotaGraphF(x, y, scale, 0.0, selection, TRUE);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
    }

    if (achievementUnlocked_[static_cast<std::size_t>(selected)] != 0) {
        const int noticeFrame = resources.graphHandle(kNoticeFramePath);
        if (noticeFrame != -1) {
            DrawRotaGraphF(xOffset + 640.0f, 668.0f, 1.0, 0.0, noticeFrame, TRUE);
        }
        drawPathFrameScaledAlpha(resources, localizedPath(kAchievementNoticePaths, language_), selected,
                                 xOffset + 640.0f, 668.0f, 1.0, 255);
    }
}

void FrontendRuntime::drawEnemyEncyclopedia(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 5, language_);

    float xOffset = 0.0f;
    if (frame_ < kEnemyEncyclopediaInputEnableFrame) {
        xOffset = 1280.0f * std::sin(static_cast<float>(frame_) * kPi / 120.0f) - 1280.0f;
    }
    else if (transitionDirection_ > 0 && pendingState_ == MainState::Gallery) {
        xOffset = -1280.0f *
            std::sin(static_cast<float>(transitionTimer_) * kPi / 120.0f);
    }

    const int window = resources.graphHandle(kEnemyListWindowPath);
    if (window != -1) {
        DrawRotaGraph3F(xOffset, 0.0f, 0.0f, 0.0f, 1.0, 1.0, 0.0, window, TRUE);
    }

    const int selected = std::clamp(cursor_, 1, enemyMaximum_);
    const int first = selected - (selected - 1) % 10;
    for (int row = 0; row < 10; ++row) {
        const int index = first + row;
        if (index > enemyMaximum_ || index >= kEnemyEncyclopediaCount) {
            break;
        }
        const bool unlocked = enemyUnlocked_[static_cast<std::size_t>(index)] != 0;
        const int frame = unlocked
            ? index * 4 + std::clamp(language_, 0, 3)
            : std::clamp(language_, 0, 3);
        const int handle = resources.graphFrame(kEnemyListPath, frame);
        if (handle == -1) {
            continue;
        }
        const int brightness = index == selected ? 0xff : 0x80;
        SetDrawBright(brightness, brightness, brightness);
        DrawRotaGraph3F(xOffset + 200.0f, 90.0f + static_cast<float>(row * 50),
                        0.0f, 0.0f, 1.0, 1.0, 0.0, handle, TRUE);
        SetDrawBright(255, 255, 255);
    }

    const int pictureIndex = enemyUnlocked_[static_cast<std::size_t>(selected)] != 0 ? selected : 0;
    drawPathFrameScaledAlpha(resources, kEnemyListPicturePath, pictureIndex,
                             xOffset + 815.0f, 340.0f, 1.0, 255);
    if (pictureIndex != 0) {
        drawEnemyEncyclopediaComposite(resources, pictureIndex, frame_, xOffset);
    }

    if (frame_ >= kEnemyEncyclopediaInputEnableFrame && transitionTimer_ == 0) {
        const int arrow = resources.graphFrameById("GFX_effect_Effect_s", 1);
        if (arrow != -1) {
            const float arrowX = 1200.0f +
                8.0f * std::sin(static_cast<float>(frame_) * kPi / 40.0f);
            DrawRotaGraphF(arrowX, 360.0f, 1.0, 0.0, arrow, TRUE);
        }
    }
}

void FrontendRuntime::drawManual(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 6, language_);
    const char* pagePath = localizedPath(kManualPaths, language_);
    const char* menuPath = localizedPath(kManualMenuPaths, language_);

    if (cursor_ >= 0 && cursor_ < kManualPageCount) {
        const int page = resources.graphFrame(pagePath, cursor_);
        if (page != -1) {
            DrawGraph(380, 100, page, TRUE);
        }
    }
    for (int index = 0; index < kManualPageCount; ++index) {
        int alpha = index == cursor_ ? 0xff : 0x60;
        if (index == cursor_ && transitionTimer_ != 0 && wrapIndex(transitionTimer_ + 10000, 4) >= 2) {
            alpha = 0x60;
        }
        const int handle = resources.graphFrame(menuPath, index);
        if (handle == -1) {
            continue;
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        DrawGraph(index == cursor_ ? 135 : 120, 100 + index * 50, handle, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}

void FrontendRuntime::drawReplayList(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 4, language_);
    const int selected = std::clamp(cursor_, 0, kReplaySlotCount - 1);
    constexpr int visibleRows = 11;
    constexpr int firstY = 105;
    for (int offset = -visibleRows / 2; offset <= visibleRows / 2; ++offset) {
        const int index = wrapIndex(selected + offset, kReplaySlotCount);
        const int y = firstY + (offset + visibleRows / 2) * 50;
        const auto& slot = replaySlots_[static_cast<std::size_t>(index)];
        const bool current = offset == 0;
        const unsigned int color = current
            ? GetColor(255, 240, 255)
            : GetColor(slot.valid ? 150 : 88, slot.valid ? 190 : 96, slot.valid ? 255 : 118);
        if (current) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x70);
            DrawBox(145, y - 7, 1135, y + 34, GetColor(32, 30, 68), TRUE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if (slot.valid) {
            const auto timestamp = replayTimestampText(slot.timestamp);
            DrawFormatString(175, y, color, "%02d  %.3s  %s  STAGE %d",
                             index + 1, slot.tag.data(), timestamp.c_str(), slot.maximumStage);
        }
        else {
            DrawFormatString(175, y, color, "%02d  NO DATA", index + 1);
        }
    }

    const auto& slot = replaySlots_[static_cast<std::size_t>(selected)];
    if (slot.valid) {
        DrawFormatString(855, 665, GetColor(210, 220, 255), "SCORE %lld", slot.score);
    }
}

void FrontendRuntime::drawReplayStageSelect(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 4, language_);
    const int index = std::clamp(replaySlotIndex_, 0, kReplaySlotCount - 1);
    const auto& slot = replaySlots_[static_cast<std::size_t>(index)];
    const auto timestamp = replayTimestampText(slot.timestamp);
    DrawFormatString(260, 190, GetColor(230, 235, 255), "REPLAY %02d   %.3s", index + 1, slot.tag.data());
    DrawFormatString(260, 235, GetColor(180, 205, 255), "%s", timestamp.c_str());
    DrawFormatString(260, 280, GetColor(180, 205, 255), "SCORE %lld", slot.score);
    DrawFormatString(260, 325, GetColor(180, 205, 255), "MODE %d", slot.mode);

    DrawFormatString(500, 430, GetColor(255, 245, 255), "STAGE %d", replayStageChoice_);
    if (slot.mode == 1 && slot.checkpoint != 10) {
        const int arrow = resources.graphFrameById("GFX_effect_Effect_s", 1);
        if (arrow != -1) {
            DrawRotaGraphF(450.0f, 445.0f, 0.5, kPi * 1.5, arrow, TRUE);
            DrawRotaGraphF(650.0f, 445.0f, 0.5, kPi * 0.5, arrow, TRUE);
        }
    }
}

void FrontendRuntime::drawRanking(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 11, language_);
    constexpr std::array<int, 5> categoryFrames{{2, 14, 16, 18, 9}};
    const int category = std::clamp(cursor_, 0, trialExtraUnlocked_ ? 4 : 3);
    drawPathFrameScaledAlpha(resources, kResultMenuPath, categoryFrames[static_cast<std::size_t>(category)],
                             400.0f, 360.0f, 1.0, 255);
    drawPathFrameScaledAlpha(resources, kResultMenuPath, 4 + rankingValue_ % 5,
                             550.0f, 360.0f, 1.0, 255);
    if (rankingValue_ > 4) {
        drawPathFrameScaledAlpha(resources, kResultMenuPath, 11, 710.0f, 360.0f, 1.0, 255);
    }

    const int arrow = resources.graphFrameById("GFX_effect_Effect_s", 1);
    if (arrow != -1) {
        const float wave = std::sin(static_cast<float>(frame_) * kPi / 30.0f) * 3.0f;
        DrawRotaGraphF(350.0f + wave, 360.0f, 0.6, kPi, arrow, TRUE);
        DrawRotaGraphF(930.0f - wave, 360.0f, 0.6, 0.0, arrow, TRUE);
        DrawRotaGraphF(640.0f, 300.0f + wave, 0.6, kPi * 1.5, arrow, TRUE);
        DrawRotaGraphF(640.0f, 420.0f - wave, 0.6, kPi * 0.5, arrow, TRUE);
    }
}

void FrontendRuntime::drawRankingNotice(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 11, language_);
    drawPathFrameScaledAlpha(resources, kRankingNoticePath, frame_ < 0x3c ? 0 : 1,
                             640.0f, 360.0f, 1.0, 255);
}

void FrontendRuntime::drawOptions(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 7, language_);

    for (int i = 0; i < kOptionsRows; ++i) {
        int alpha = i == cursor_ ? 0xff : 0x60;
        if ((i == 3 && !dataWindowUnlocked_) || (i == 7 && !shortcutUnlocked_)) {
            alpha = std::min(alpha, 0x80);
        }
        if (i == cursor_ && transitionTimer_ != 0 && wrapIndex(transitionTimer_ + 10000, 4) >= 2) {
            alpha = 0x60;
        }
        const float y = static_cast<float>(i * 0x32 + 0x82);
        drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu", i, 550.0f, y, 1.0, alpha);
        if (i == 0) {
            drawConfigNumber(resources, 810.0f, y, bgmVolume_ * 10, true, alpha);
        }
        else if (i == 1) {
            drawConfigNumber(resources, 810.0f, y, seVolume_ * 10, true, alpha);
        }
        else if (i == 2) {
            drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2", 11 + language_, 810.0f, y, 1.0, alpha);
        }
        else if (i == 3) {
            drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2", dataWindowEnabled_ == 1 ? 0 : 1,
                                 810.0f, y, 1.0, alpha);
        }
    }
}

void FrontendRuntime::drawOptionAssist(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 8, language_);
    constexpr std::array<int, kOptionAssistRows> frames{{10, 11, 9, 8}};
    for (int row = 0; row < kOptionAssistRows; ++row) {
        int alpha = row == cursor_ ? 0xff : 0x60;
        if (row == cursor_ && transitionTimer_ != 0 && wrapIndex(transitionTimer_ + 10000, 4) >= 2) {
            alpha = 0x60;
        }
        const float y = 180.0f + static_cast<float>(row) * 50.0f;
        drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu", frames[static_cast<std::size_t>(row)],
                             550.0f, y, 1.0, alpha);
        if (row == 0) {
            drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2", controlModeEnabled_ == 1 ? 0 : 1,
                                 810.0f, y, 1.0, alpha);
        }
        else if (row == 1) {
            if (helpMode_ == 0) {
                drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2", 2, 810.0f, y, 1.0, alpha);
            }
            else if (helpMode_ == 6) {
                drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2", 1, 810.0f, y, 1.0, alpha);
            }
            else {
                drawConfigNumber(resources, 810.0f, y, helpMode_, false, alpha);
            }
        }
    }
}

void FrontendRuntime::drawConfigMenu(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 9, language_);
    constexpr std::array<int, kConfigMenuRows> frames{{12, 13, 14, 15, 16, 17, 18, 9, 8}};
    constexpr std::array<int, 3> frameRates{{60, 30, 20}};
    constexpr std::array<int, 4> soundFrames{{2, 5, 6, 7}};
    for (int row = 0; row < kConfigMenuRows; ++row) {
        int alpha = row == cursor_ ? 0xff : 0x60;
        if (row == cursor_ && transitionTimer_ != 0 && wrapIndex(transitionTimer_ + 10000, 4) >= 2) {
            alpha = 0x60;
        }
        const float y = 150.0f + static_cast<float>(row) * 50.0f;
        drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu", frames[static_cast<std::size_t>(row)],
                             550.0f, y, 1.0, alpha);
        if (row == 1) {
            drawConfigNumber(resources, 810.0f, y,
                             frameRates[static_cast<std::size_t>(std::clamp(systemConfig_[1], 0, 2))],
                             false, alpha);
        }
        else if (row == 5) {
            drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2", systemConfig_[5] == 0 ? 8 : 9,
                                 810.0f, y, 1.0, alpha);
        }
        else if (row == 6) {
            drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2",
                                 soundFrames[static_cast<std::size_t>(std::clamp(systemConfig_[6], 0, 3))],
                                 810.0f, y, 1.0, alpha);
        }
        else if (row < 7) {
            drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu2",
                                 systemConfig_[static_cast<std::size_t>(row)] == 1 ? 0 : 1,
                                 810.0f, y, 1.0, alpha);
        }
    }
}

void FrontendRuntime::drawKeyConfig(const ResourceManager& resources) const {
    drawFrontendBackdrop(resources, 10, language_);
    drawFrameScaledAlpha(resources, "GFX_system_KeyConfigMenu", 0, 560.0f, 62.0f, 1.0, 255);
    drawFrameScaledAlpha(resources, "GFX_system_KeyConfigMenu", std::clamp(controlDevice_ + 1, 1, 6),
                         760.0f, 62.0f, 1.0, 255);

    for (int row = 0; row < kKeyConfigRows; ++row) {
        int alpha = row == cursor_ ? 0xff : 0x60;
        const bool available = controlDevice_ == 5 || row >= 4;
        if (!available && row < 11) {
            alpha = std::min(alpha, 0x80);
        }
        if (row == cursor_ && transitionTimer_ != 0 && wrapIndex(transitionTimer_ + 10000, 4) >= 2) {
            alpha = std::min(alpha, 0x60);
        }
        const float y = 102.0f + static_cast<float>(row) * 42.0f;
        if (row < 11) {
            drawFrameScaledAlpha(resources, "GFX_system_KeyConfigMenu", 7 + row,
                                 560.0f, y, 1.0, alpha);
            if (keyCaptureActive_ && row == cursor_) {
                drawFrameScaledAlpha(resources, "GFX_system_KeyConfigMenu", 20,
                                     760.0f, y, 1.0,
                                     0x80 - static_cast<int>(std::sin(static_cast<float>(frame_) * kPi / 32.0f) * 0x40));
                continue;
            }

            int promptFrame = -1;
            const char* promptPath = nullptr;
            if (controlDevice_ < 5) {
                promptPath = kControllerPromptPath;
                promptFrame = controllerPromptFrame(controlDevice_, row,
                    controllerBindings_[static_cast<std::size_t>(row)]);
            }
            else {
                promptPath = kKeyboardPromptPath;
                promptFrame = keyboardPromptFrame(keyBindings_[static_cast<std::size_t>(row)]);
            }
            if (promptPath != nullptr && promptFrame >= 0 && resources.graphFrame(promptPath, promptFrame) != -1) {
                drawPathFrameScaledAlpha(resources, promptPath, promptFrame, 760.0f, y, 1.0, alpha);
            }
        }
        else if (row == 11) {
            drawFrameScaledAlpha(resources, "GFX_system_KeyConfigMenu", 18, 560.0f, y, 1.0, alpha);
        }
        else {
            drawFrameScaledAlpha(resources, "GFX_system_ConfigMenu", 8, 560.0f, y, 1.0, alpha);
        }
    }
}

void FrontendRuntime::drawTransitionOverlay(const ResourceManager& resources) const {
    if (transitionTimer_ == 0) {
        return;
    }

    const auto spec = currentTransitionSpec();
    const int raw = std::abs(transitionTimer_);
    const int phase = raw - spec.wipeDelay;
    if (phase <= 0) {
        return;
    }

    // Direct transcription of FUN_1400d3fd0 @ 0x1400d3fd0. The helper lays
    // out Effect_m frames 1/2 as a 12x6 checkerboard, staggering each row by
    // three frames and expanding every tile horizontally over twelve frames.
    for (int column = 0; column < 12; ++column) {
        for (int row = 0; row < 6; ++row) {
            const int onset = column + row * 3;
            if (phase < onset) {
                continue;
            }
            const float progress = std::clamp(static_cast<float>(phase - onset) / 12.0f, 0.0f, 1.0f);
            const double scaleX = std::sin(static_cast<double>(progress) * kPi * 0.5);
            const float dropOffset = 180.0f * (1.0f - static_cast<float>(scaleX));
            const int frame = ((column + row) & 1) == 0 ? 1 : 2;
            const int handle = resources.graphFrame(kEffectMediumPath, frame);
            const float x = static_cast<float>(column * 120);
            const float y = static_cast<float>(row * 120 + 60) + dropOffset;
            if (handle != -1) {
                DrawRotaGraph3F(x, y, 100.0f, 100.0f, scaleX, 1.0, 0.0, handle, TRUE);
            }
            else {
                const int halfWidth = static_cast<int>(100.0 * scaleX);
                DrawBox(static_cast<int>(x) - halfWidth, static_cast<int>(y) - 100,
                        static_cast<int>(x) + halfWidth, static_cast<int>(y) + 100,
                        ((column + row) & 1) == 0 ? GetColor(255, 128, 224) : GetColor(128, 220, 255), TRUE);
            }
        }
    }
}

void FrontendRuntime::loadMissingFrontendGraphs(ResourceManager& resources) {
    // These three tables are loaded by 0x1400ced90 in the original executable,
    // but were omitted from the reconstruction's small default frontend set.
    if (resources.graphFrame(kPracticeMenuPath, 0) == -1) {
        resources.loadDivGraph(kPracticeMenuPath, 0x14, 1, 0x14, 0xf0, 0x28);
    }
    if (resources.graphFrame(kConfigNumberPath, 0) == -1) {
        resources.loadDivGraph(kConfigNumberPath, 0x0b, 1, 0x0b, 0x1e, 0x28);
    }
    if (resources.graphFrame(kEffectMediumPath, 0) == -1) {
        resources.loadDivGraph(kEffectMediumPath, 0x1e, 10, 3, 200, 200);
    }
    if (resources.graphFrame(kKeyboardPromptPath, 0) == -1) {
        resources.loadDivGraph(kKeyboardPromptPath, 0x6e, 10, 0x0b, 40, 40);
    }
    if (resources.graphFrame(kControllerPromptPath, 0) == -1) {
        resources.loadDivGraph(kControllerPromptPath, 0x4b, 0x0f, 5, 40, 40);
    }
}

void FrontendRuntime::ensureGalleryGraphs(ResourceManager& resources) const {
    const char* picturePath = localizedPath(kGalleryPicturePaths, language_);
    if (resources.graphFrame(picturePath, 0) == -1) {
        resources.loadDivGraph(picturePath, kGalleryPictureCount, 5, 4, 0x500, 0x2d0);
    }
    if (resources.graphHandle(kGalleryFramePath) == -1) {
        resources.loadGraph(kGalleryFramePath);
    }
    const char* noticePath = localizedPath(kGalleryNoticePaths, language_);
    if (resources.graphFrame(noticePath, 0) == -1) {
        resources.loadDivGraph(noticePath, kGalleryPictureCount, 1, kGalleryPictureCount, 140, 25);
    }
    if (resources.graphHandle(kNoticeFramePath) == -1) {
        resources.loadGraph(kNoticeFramePath);
    }
}

void FrontendRuntime::ensureAchievementGraphs(ResourceManager& resources) const {
    if (resources.graphFrame(kAchievementPath, 0) == -1) {
        resources.loadDivGraph(kAchievementPath, 5, 5, 1, 100, 100);
    }
    const char* noticePath = localizedPath(kAchievementNoticePaths, language_);
    if (resources.graphFrame(noticePath, 0) == -1) {
        resources.loadDivGraph(noticePath, kAchievementCount, 1, kAchievementCount, 140, 25);
    }
    if (resources.graphHandle(kNoticeFramePath) == -1) {
        resources.loadGraph(kNoticeFramePath);
    }
}

void FrontendRuntime::ensureEnemyEncyclopediaGraphs(ResourceManager& resources) const {
    if (resources.graphHandle(kEnemyListWindowPath) == -1) {
        resources.loadGraph(kEnemyListWindowPath);
    }
    if (resources.graphFrame(kEnemyListPath, 0) == -1) {
        resources.loadDivGraph(kEnemyListPath, 0x1a0, 4, 0x68, 0x140, 0x28);
    }
    if (resources.graphFrame(kEnemyListPicturePath, 0) == -1) {
        resources.loadDivGraph(kEnemyListPicturePath, 0x6e, 10, 0x0b, 600, 600);
    }
    if (resources.graphFrame(kBossPath, 0) == -1) {
        resources.loadDivGraph(kBossPath, 0xa0, 10, 0x10, 200, 200);
    }
}

void FrontendRuntime::ensureManualGraphs(ResourceManager& resources) const {
    const char* pagePath = localizedPath(kManualPaths, language_);
    const char* menuPath = localizedPath(kManualMenuPaths, language_);
    if (resources.graphFrame(pagePath, 0) == -1) {
        resources.loadDivGraph(pagePath, 0x0b, 1, 0x0b, 800, 0x230);
    }
    if (resources.graphFrame(menuPath, 0) == -1) {
        resources.loadDivGraph(menuPath, 0x0c, 1, 0x0c, 0xb4, 0x1e);
    }
}

void FrontendRuntime::ensureRankingGraphs(ResourceManager& resources) const {
    if (resources.graphFrame(kResultMenuPath, 0) == -1) {
        resources.loadDivGraph(kResultMenuPath, 0x14, 1, 0x14, 0xf0, 0x3c);
    }
    if (resources.graphFrame(kRankingNoticePath, 0) == -1) {
        resources.loadDivGraph(kRankingNoticePath, 0x0e, 1, 0x0e, 0x280, 0x3c);
    }
}

void FrontendRuntime::scanReplaySlots(const ResourceManager& resources) {
    replaySlots_.fill(ReplaySlot{});
    for (int index = 0; index < kReplaySlotCount; ++index) {
        char logicalPath[64]{};
        std::snprintf(logicalPath, sizeof(logicalPath), "replay\\LD_replay%02d.dat", index + 1);
        std::ifstream input(resources.resolvePath(logicalPath), std::ios::binary);
        if (!input) {
            continue;
        }

        std::array<std::uint8_t, 0xa98> header{};
        input.read(reinterpret_cast<char*>(header.data()), static_cast<std::streamsize>(header.size()));
        if (input.gcount() != static_cast<std::streamsize>(header.size())) {
            continue;
        }
        const auto readI32 = [&](std::size_t offset) {
            std::int32_t value = 0;
            std::memcpy(&value, header.data() + offset, sizeof(value));
            return static_cast<int>(value);
        };
        const auto readI64 = [&](std::size_t offset) {
            std::int64_t value = 0;
            std::memcpy(&value, header.data() + offset, sizeof(value));
            return static_cast<long long>(value);
        };
        if (readI32(0) != 200) {
            continue;
        }

        auto& slot = replaySlots_[static_cast<std::size_t>(index)];
        slot.valid = true;
        for (int character = 0; character < 3; ++character) {
            const char value = static_cast<char>(header[static_cast<std::size_t>(8 + character)]);
            slot.tag[static_cast<std::size_t>(character)] = value >= 0x20 && value <= 0x7e ? value : '-';
        }
        slot.tag[3] = '\0';
        slot.timestamp = readI32(0x10);
        slot.mode = readI32(0x18);
        slot.submode = readI32(0x1c);
        slot.checkpoint = readI32(0x40);
        slot.maximumStage = std::clamp(readI32(0x44), 1, 10);
        slot.score = readI64(0x58);
    }
}

void FrontendRuntime::refreshEnemyEncyclopediaAvailability() {
    constexpr std::array<int, 11> caps{{
        10, 11, 22, 32, 41, 51, 61, 73, 82, 84, 103,
    }};

    enemyMaximum_ = 10;
    for (int stage = 1; stage <= 10; ++stage) {
        if (enemyStageStatus_[static_cast<std::size_t>(stage)] > 0) {
            enemyMaximum_ = caps[static_cast<std::size_t>(stage)];
        }
    }

    const bool firstStageGate = enemyStageStatus_[1] > 0;
    enemyUnlocked_.fill(0);
    for (int index = 0; index < kEnemyEncyclopediaCount; ++index) {
        enemyUnlocked_[static_cast<std::size_t>(index)] =
            firstStageGate && index <= enemyMaximum_ ? 1 : 0;
    }
    if (enemySequentialProgress_ >= 9) {
        enemyUnlocked_[83] = 1;
        enemyUnlocked_[84] = 1;
        enemyMaximum_ = std::max(enemyMaximum_, 84);
    }
}

void FrontendRuntime::loadSaveBackedState(const SaveConfigState& saveConfigState) {
    // config.dat is loaded independently by the original startup path and must
    // remain usable even when save.dat needs to fall back to defaults.
    if (saveConfigState.configDat.size() == SaveConfigState::kConfigDatSize) {
        std::array<std::int32_t, 7> stored{};
        std::memcpy(stored.data(), saveConfigState.configDat.data(), sizeof(stored));
        systemConfig_[0] = stored[0] != 0 ? 1 : 0;
        systemConfig_[1] = std::clamp(static_cast<int>(stored[1]), 0, 2);
        systemConfig_[2] = stored[2] != 0 ? 1 : 0;
        systemConfig_[3] = stored[3] != 0 ? 1 : 0;
        systemConfig_[4] = stored[4] != 0 ? 1 : 0;
        systemConfig_[5] = stored[5] != 0 ? 1 : 0;
        systemConfig_[6] = std::clamp(static_cast<int>(stored[6]), 0, 3);
    }

    std::vector<std::uint8_t> bytes = saveConfigState.saveDat;
    if (bytes.size() != SaveConfigState::kSaveDatSize) {
        return;
    }

    const auto readI32 = [&](std::size_t offset) {
        std::int32_t value = 0;
        if (offset + sizeof(value) <= bytes.size()) {
            std::memcpy(&value, bytes.data() + offset, sizeof(value));
        }
        return static_cast<int>(value);
    };
    if (readI32(0) != 200) {
        return;
    }
    saveBackingBytes_ = bytes;

    trialUnlocked_ = readI32(0x0c) != 0;
    setupGroup_ = std::clamp(readI32(0x14), 0, 2);
    for (int group = 0; group < 3; ++group) {
        for (int option = 0; option < 4; ++option) {
            const int maximum = option == 3 ? 3 : 1;
            setupOptionsByGroup_[static_cast<std::size_t>(group)][static_cast<std::size_t>(option)] =
                std::clamp(readI32(0x18 + static_cast<std::size_t>(group * 0x10 + option * 4)), 0, maximum);
        }
    }

    savedStageByRoute_[0] = std::clamp(readI32(0x48), 1, 9);
    savedStageByRoute_[1] = std::clamp(readI32(0x4c), 10, 14);
    selectedDifficulty_ = std::clamp(readI32(0x50), 0, notes::difficulty_overlay_evidence::kDifficultyCount - 1);
    counterMode_ = readI32(0x54) != 0 ? 1 : 0;
    maxUnlockedStageByRoute_[0] = std::clamp(readI32(0x58), 1, 9);
    maxUnlockedStageByRoute_[1] = std::clamp(readI32(0x5c), 11, 14);
    feverMode_ = readI32(0x60) != 0 ? 1 : 0;
    counterUnlocked_ = readI32(0x64) != 0;
    trialExtraUnlocked_ = readI32(0x68) != 0;
    for (int stage = 0; stage < static_cast<int>(maxUnlockedDifficultyByStage_.size()); ++stage) {
        maxUnlockedDifficultyByStage_[static_cast<std::size_t>(stage)] =
            std::clamp(readI32(0x2398 + static_cast<std::size_t>(stage) * 4), 0, 4);
    }
    dataWindowUnlocked_ = readI32(0x2408) != 0;
    for (int index = 0; index < kGalleryPictureCount; ++index) {
        galleryUnlocked_[static_cast<std::size_t>(index)] =
            readI32(0x240c + static_cast<std::size_t>(index) * 4) != 0 ? 1 : 0;
        galleryViewed_[static_cast<std::size_t>(index)] =
            readI32(0x2470 + static_cast<std::size_t>(index) * 4) != 0 ? 1 : 0;
    }
    for (int index = 0; index < kAchievementCount; ++index) {
        achievementUnlocked_[static_cast<std::size_t>(index)] =
            readI32(0x24d4 + static_cast<std::size_t>(index) * 4) != 0 ? 1 : 0;
        achievementViewed_[static_cast<std::size_t>(index)] =
            readI32(0x259c + static_cast<std::size_t>(index) * 4) != 0 ? 1 : 0;
    }
    practiceOptions_[0] = std::clamp(readI32(0x23e8), 1, 10);
    practiceOptions_[1] = std::clamp(readI32(0x23ec), 0, notes::difficulty_overlay_evidence::kDifficultyCount - 1);
    practiceOptions_[2] = readI32(0x23f0) != 0 ? 1 : 0;
    practiceOptions_[3] = readI32(0x23f4) != 0 ? 1 : 0;
    practiceOptions_[4] = std::clamp(readI32(0x23f8), 0, practicePhaseMax(practiceOptions_[0]));
    practiceOptions_[5] = std::clamp(readI32(0x23fc), 0, 3);
    practiceOptions_[6] = std::clamp(readI32(0x2400), 0, 20);
    practiceOptions_[7] = std::clamp(readI32(0x2404), 0, 20);
    bgmVolume_ = std::clamp(readI32(0x267c), 0, 10);
    seVolume_ = std::clamp(readI32(0x2680), 0, 10);
    controlModeEnabled_ = readI32(0x2684) != 0 ? 1 : 0;
    helpMode_ = std::clamp(readI32(0x2688), 0, 6);
    language_ = std::clamp(readI32(0x26a4), 0, 3);
    dataWindowEnabled_ = readI32(0x26a8) != 0 ? 1 : 0;
    shortcutUnlocked_ = readI32(0x26ac) != 0;
    controlDevice_ = std::clamp(readI32(0x26bc), 0, 5);
    for (int action = 0; action < 11; ++action) {
        const int key = readI32(0x26c0 + static_cast<std::size_t>(action) * 4);
        keyBindings_[static_cast<std::size_t>(action)] =
            key > 0 && key < 0x100 ? key : kDefaultKeyBindings[static_cast<std::size_t>(action)];
        const int button = readI32(0x26f0 + static_cast<std::size_t>(action) * 4);
        controllerBindings_[static_cast<std::size_t>(action)] =
            button != 0 ? button : kDefaultControllerBindings[static_cast<std::size_t>(action)];
    }

    const auto stageStatus = [&](int stage) {
        int result = 0;
        if (stage <= 0) {
            return result;
        }
        for (int character = 0; character < 3; ++character) {
            const std::size_t record = 0x84 + static_cast<std::size_t>(stage) * 0x258 +
                static_cast<std::size_t>(character) * 0xc8;
            for (int difficulty = 0; difficulty < 4; ++difficulty) {
                const std::size_t difficultyOffset = static_cast<std::size_t>(difficulty) * 4;
                if (readI32(record + 0x14 + difficultyOffset) > 0 && result == 0) {
                    result = 1;
                }
                if (readI32(record + difficultyOffset) > 0) {
                    result = 2;
                }
            }
        }
        return result;
    };

    enemyStageStatus_.fill(0);
    for (int stage = 1; stage <= 10; ++stage) {
        enemyStageStatus_[static_cast<std::size_t>(stage)] = stageStatus(stage);
    }
    enemySequentialProgress_ = readI32(0x58);
    refreshEnemyEncyclopediaAvailability();

}

void FrontendRuntime::saveFrontendState(const ResourceManager& resources) const {
    auto bytes = saveBackingBytes_;
    if (bytes.size() != SaveConfigState::kSaveDatSize) {
        return;
    }

    const auto writeI32 = [&](std::size_t offset, int value) {
        const std::int32_t stored = static_cast<std::int32_t>(value);
        if (offset + sizeof(stored) <= bytes.size()) {
            std::memcpy(bytes.data() + offset, &stored, sizeof(stored));
        }
    };

    writeI32(0x14, setupGroup_);
    for (int group = 0; group < 3; ++group) {
        for (int option = 0; option < 4; ++option) {
            writeI32(0x18 + static_cast<std::size_t>(group * 0x10 + option * 4),
                     setupOptionsByGroup_[static_cast<std::size_t>(group)][static_cast<std::size_t>(option)]);
        }
    }
    writeI32(0x48, savedStageByRoute_[0]);
    writeI32(0x4c, savedStageByRoute_[1]);
    writeI32(0x50, selectedDifficulty_);
    writeI32(0x54, counterMode_);
    writeI32(0x60, feverMode_);
    for (int index = 0; index < kGalleryPictureCount; ++index) {
        writeI32(0x2470 + static_cast<std::size_t>(index) * 4,
                 galleryViewed_[static_cast<std::size_t>(index)]);
    }
    for (int index = 0; index < kAchievementCount; ++index) {
        writeI32(0x259c + static_cast<std::size_t>(index) * 4,
                 achievementViewed_[static_cast<std::size_t>(index)]);
    }
    for (int option = 0; option < static_cast<int>(practiceOptions_.size()); ++option) {
        writeI32(0x23e8 + static_cast<std::size_t>(option) * 4,
                 practiceOptions_[static_cast<std::size_t>(option)]);
    }
    writeI32(0x267c, bgmVolume_);
    writeI32(0x2680, seVolume_);
    writeI32(0x2684, controlModeEnabled_);
    writeI32(0x2688, helpMode_);
    writeI32(0x26a4, language_);
    writeI32(0x26a8, dataWindowEnabled_);
    writeI32(0x26bc, controlDevice_);
    for (int action = 0; action < 11; ++action) {
        writeI32(0x26c0 + static_cast<std::size_t>(action) * 4,
                 keyBindings_[static_cast<std::size_t>(action)]);
        writeI32(0x26f0 + static_cast<std::size_t>(action) * 4,
                 controllerBindings_[static_cast<std::size_t>(action)]);
    }
    std::ofstream output(resources.assetRoot() / "save" / "save.dat", std::ios::binary | std::ios::trunc);
    if (output) {
        output.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
    }
}

void FrontendRuntime::saveSystemConfig(const ResourceManager& resources) const {
    std::ofstream configOutput(resources.assetRoot() / "save" / "config.dat", std::ios::binary | std::ios::trunc);
    if (configOutput) {
        std::array<std::int32_t, 7> stored{};
        for (int index = 0; index < 7; ++index) {
            stored[static_cast<std::size_t>(index)] =
                static_cast<std::int32_t>(systemConfig_[static_cast<std::size_t>(index)]);
        }
        configOutput.write(reinterpret_cast<const char*>(stored.data()), static_cast<std::streamsize>(sizeof(stored)));
    }
}

void FrontendRuntime::playSound(ResourceManager& resources, const char* id) const {
    const int handle = resources.soundHandleById(id);
    if (handle != -1) {
        const int scale = std::strcmp(id, "SE_se_Error") == 0 ? 0x14 : 0x19;
        ChangeVolumeSoundMem(seVolume_ * scale, handle);
        PlaySoundMem(handle, DX_PLAYTYPE_BACK, TRUE);
    }
}

void FrontendRuntime::ensureTitleBgm(ResourceManager& resources) {
    if (titleBgmStarted_) {
        return;
    }
    const int handle = resources.soundHandleById("BGM_bgm_Title");
    if (handle != -1) {
        ChangeVolumeSoundMem(bgmVolume_ * 0x19, handle);
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
