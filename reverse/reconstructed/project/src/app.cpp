#include "app.h"

#include "reconstruction_notes.h"
#include "resource_tables.h"
#include "steam_stub.h"

#include <DxLib.h>
#include <Windows.h>

#include <string>
#include <utility>


namespace reconstructed {
namespace {

constexpr unsigned int kWhite = 0xffffff;
constexpr unsigned int kRed = 0xff6060;

std::filesystem::path fontPath(const std::filesystem::path& assetRoot, const char* name) {
    return assetRoot / name;
}

} // namespace

App::App(AppOptions options) : options_(std::move(options)) {}

App::~App() {
    shutdown();
}

int App::run() {
    if (!initialize()) {
        shutdown();
        return 1;
    }
    return runSmokeTestLoop();
}

bool App::initialize() {
    if (!initializeSteamStub()) {
        return false;
    }

    SaveConfigStore saveConfig(options_.assetRoot);
    if (!saveConfig.loadOrCreate()) {
        MessageBoxA(nullptr, "Failed to load or create save/config stubs.", "LikeDreamerRe", MB_OK | MB_ICONERROR);
        return false;
    }
    saveConfigState_ = saveConfig.state();

    SetOutApplicationLogValidFlag(TRUE);
    SetMainWindowText("LikeDreamerRe reconstruction scaffold");
    ChangeWindowMode(TRUE);
    SetGraphMode(notes::kScreenWidth, notes::kScreenHeight, 32);
    SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);

    if (DxLib_Init() == -1) {
        MessageBoxA(nullptr, "DxLib_Init failed.", "LikeDreamerRe", MB_OK | MB_ICONERROR);
        return false;
    }
    dxInitialized_ = true;

    SetDrawScreen(DX_SCREEN_BACK);
    SetDXArchiveKeyString(notes::kDxArchiveKey);
    loadFonts();

    resources_ = std::make_unique<ResourceManager>(options_.assetRoot, options_.resourceMode);
    if (!resources_->loadStartupResources()) {
        // Continue into the diagnostic window if DxLib itself is alive; the first
        // scaffold is useful even when it reports missing path/library setup.
        OutputDebugString("[LikeDreamerRe] One or more smoke-test resources failed to load.\n");
    }
    if (options_.loadAllGraphics) {
        resources_->loadGraphs(expandedGraphResources());
    }
    if (options_.loadAudio) {
        resources_->loadSounds(soundResources());
    }
    textDatabase_.load(textResources(), options_.assetRoot, options_.resourceMode);

    return true;
}

void App::shutdown() {
    resources_.reset();

    if (fontsLoaded_) {
        RemoveFontResourceExA(fontPath(options_.assetRoot, "Nyashi.ttf").string().c_str(), FR_PRIVATE, nullptr);
        RemoveFontResourceExA(fontPath(options_.assetRoot, "ChillRoundM.ttf").string().c_str(), FR_PRIVATE, nullptr);
        fontsLoaded_ = false;
    }

    if (dxInitialized_) {
        DxLib_End();
        dxInitialized_ = false;
    }

    shutdownSteamStub();
}

void App::loadFonts() {
    const auto nyashi = fontPath(options_.assetRoot, "Nyashi.ttf").string();
    const auto chill = fontPath(options_.assetRoot, "ChillRoundM.ttf").string();
    const int addedNyashi = AddFontResourceExA(nyashi.c_str(), FR_PRIVATE, nullptr);
    const int addedChill = AddFontResourceExA(chill.c_str(), FR_PRIVATE, nullptr);
    fontsLoaded_ = addedNyashi > 0 || addedChill > 0;
}

int App::runSmokeTestLoop() {
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
        if (CheckHitKey(KEY_INPUT_F1) != 0) {
            diagnosticsPage_ = 1;
        }
        else if (CheckHitKey(KEY_INPUT_F2) != 0) {
            diagnosticsPage_ = 2;
        }
        else if (CheckHitKey(KEY_INPUT_F3) != 0) {
            diagnosticsPage_ = 3;
        }
        else if (CheckHitKey(KEY_INPUT_F4) != 0) {
            diagnosticsPage_ = 4;
        }
        drawSmokeTestFrame();
        ScreenFlip();
    }
    return 0;
}

void App::drawSmokeTestFrame() const {
    ClearDrawScreen();

    const int titleBack = resources_ ? resources_->graphHandle("media\\system\\TitleBack.png") : -1;
    const int titleLogo = resources_ ? resources_->graphHandle("media\\system\\TitleLogo.png") : -1;
    const int nowLoading = resources_ ? resources_->graphHandle("media\\system\\NowLoading.png") : -1;

    if (titleBack != -1) {
        DrawGraph(0, 0, titleBack, TRUE);
    }
    else {
        DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(20, 24, 48), TRUE);
    }

    if (titleLogo != -1) {
        DrawGraph(260, 80, titleLogo, TRUE);
    }

    if (nowLoading != -1) {
        DrawGraph(24, notes::kScreenHeight - 96, nowLoading, TRUE);
    }

    DrawString(24, 24, "LikeDreamerRe reconstruction scaffold", GetColor(255, 240, 128));
    DrawString(24, 48, "F1 title  F2 resources  F3 text CSV  F4 save/config  ESC exit", GetColor(255, 255, 255));
    if (diagnosticsPage_ == 1) {
        DrawString(24, 72, "Smoke test: startup/title resource loading only", GetColor(255, 255, 255));
        drawDiagnostics(24, 120);
    }
    else if (diagnosticsPage_ == 2) {
        drawResourceDiagnostics(24, 84);
    }
    else if (diagnosticsPage_ == 3) {
        drawTextDiagnostics(24, 84);
    }
    else {
        drawSaveDiagnostics(24, 84);
    }
}

void App::drawResourceDiagnostics(int x, int y) const {
    if (!resources_) {
        DrawString(x, y, "ResourceManager is not initialized", GetColor(255, 96, 96));
        return;
    }
    const auto& summary = resources_->summary();
    DrawFormatString(x, y, GetColor(255, 240, 128), "Resource diagnostics: graphs %d/%d, sounds %d/%d",
                     summary.graphSuccesses, summary.graphAttempts, summary.soundSuccesses, summary.soundAttempts);
    int line = y + 28;
    int shown = 0;
    for (const auto& graph : resources_->graphs()) {
        const auto color = graph.handle == -1 ? kRed : kWhite;
        DrawFormatString(x, line, GetColor((color >> 16) & 0xff, (color >> 8) & 0xff, color & 0xff),
                         "%s [%s/%s] count %d -> %s", graph.id.c_str(), toString(graph.source), toString(graph.loadKind),
                         graph.handleCount, graph.logicalPath.c_str());
        line += 20;
        if (++shown >= 26) {
            DrawString(x, line, "... more resources omitted from overlay", GetColor(200, 200, 200));
            break;
        }
    }
    if (summary.soundAttempts > 0) {
        line += 28;
        shown = 0;
        for (const auto& sound : resources_->sounds()) {
            const auto color = sound.handle == -1 ? kRed : kWhite;
            DrawFormatString(x, line, GetColor((color >> 16) & 0xff, (color >> 8) & 0xff, color & 0xff),
                             "%s [%s] -> handle %d", sound.id.c_str(), toString(sound.kind), sound.handle);
            line += 20;
            if (++shown >= 8) {
                DrawString(x, line, "... more sounds omitted from overlay", GetColor(200, 200, 200));
                break;
            }
        }
    }
}

void App::drawTextDiagnostics(int x, int y) const {
    DrawFormatString(x, y, GetColor(255, 240, 128), "Text CSV diagnostics: %d/%d loaded",
                     textDatabase_.succeeded(), textDatabase_.attempted());
    int line = y + 28;
    for (const auto& file : textDatabase_.files()) {
        const auto color = file.loaded ? kWhite : kRed;
        DrawFormatString(x, line, GetColor((color >> 16) & 0xff, (color >> 8) & 0xff, color & 0xff),
                         "%s cp%u rows %u %s", file.id.c_str(), file.codePage, static_cast<unsigned int>(file.rowCount),
                         file.loaded ? "" : file.error.c_str());
        line += 20;
        for (const auto& record : file.sampleRecords) {
            DrawFormatString(x + 24, line, GetColor(210, 210, 210), "%d: %.42s / %.42s", record.id, record.line1.c_str(), record.line2.c_str());
            line += 18;
        }
        line += 8;
    }
}

void App::drawSaveDiagnostics(int x, int y) const {
    const auto& diag = saveConfigState_.diagnostics;
    DrawString(x, y, "Save/config diagnostics", GetColor(255, 240, 128));
    DrawFormatString(x, y + 28, GetColor(255, 255, 255), "save.dat: existed=%d created=%d size=%u expected=%u",
                     diag.saveExisted ? 1 : 0, diag.saveCreated ? 1 : 0,
                     static_cast<unsigned int>(diag.saveActualSize), static_cast<unsigned int>(diag.saveExpectedSize));
    DrawFormatString(x, y + 52, GetColor(255, 255, 255), "config.dat: existed=%d created=%d size=%u expected=%u",
                     diag.configExisted ? 1 : 0, diag.configCreated ? 1 : 0,
                     static_cast<unsigned int>(diag.configActualSize), static_cast<unsigned int>(diag.configExpectedSize));
    DrawString(x, y + 88, "Evidence: startup candidate reads 0x2730 save bytes and 0x1c config bytes.", GetColor(210, 210, 210));
}

void App::drawDiagnostics(int x, int y) const {
    if (!resources_) {
        DrawString(x, y, "ResourceManager is not initialized", GetColor(255, 96, 96));
        return;
    }

    const auto modeText = options_.resourceMode == ResourceMode::DxArchive ? "DXA logical path mode" : "extracted re/ file mode";
    DrawFormatString(x, y, GetColor(255, 255, 255), "asset root: %s", options_.assetRoot.u8string().c_str());
    DrawFormatString(x, y + 22, GetColor(255, 255, 255), "resource mode: %s", modeText);

    int line = y + 56;
    for (const auto& graph : resources_->graphs()) {
        const auto color = graph.handle == -1 ? kRed : kWhite;
        DrawFormatString(x, line, GetColor((color >> 16) & 0xff, (color >> 8) & 0xff, color & 0xff),
                         "%s -> handle %d", graph.logicalPath.c_str(), graph.handle);
        line += 20;
    }

    DrawString(x, line + 12, "Evidence: startup candidate 1400f4f70 and resource map notes", GetColor(255, 240, 128));
}

} // namespace reconstructed
