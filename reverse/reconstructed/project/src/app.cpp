#include "app.h"

#include "reconstruction_notes.h"
#include "resource_tables.h"
#include "steam_stub.h"

#include <DxLib.h>
#include <Windows.h>

#include <cmath>
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
        OutputDebugString("[LikeDreamerRe] One or more startup resources failed to load.\n");
    }

    drawLoadingFrame(0);
    ScreenFlip();

    resources_->loadGraphs(frontendGraphResources());
    resources_->loadSounds(soundResources());

    for (int frame = 1; frame < 60 && ProcessMessage() == 0; ++frame) {
        drawLoadingFrame(frame);
        ScreenFlip();
    }

    if (options_.loadAllGraphics) {
        resources_->loadGraphs(expandedGraphResources());
    }
    if (options_.loadAudio) {
        // Frontend/menu sounds are loaded by default above; this option is kept
        // for compatibility with older smoke-test command lines.
    }
    textDatabase_.load(textResources(), options_.assetRoot, options_.resourceMode);
    stageProbe_.loadDemoSummaries(options_.assetRoot);
    frontendRuntime_.initialize(*resources_);

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

void App::drawLoadingFrame(int frame) const {
    ClearDrawScreen();
    const int starting = resources_ ? resources_->graphHandleById("GFX_system_starting") : -1;
    const int whiteBack = resources_ ? resources_->graphHandleById("GFX_system_WhiteBack") : -1;
    const int nowLoading = resources_ ? resources_->graphHandleById("GFX_system_NowLoading") : -1;

    if (starting != -1) {
        DrawGraph(0, 0, starting, FALSE);
    }
    else if (whiteBack != -1) {
        DrawGraph(0, 0, whiteBack, TRUE);
    }
    else {
        DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(245, 245, 245), TRUE);
    }

    if (nowLoading != -1) {
        const int phase60 = frame % 60;
        const double wave = std::sin(static_cast<double>(phase60) * 3.14159265358979323846 / 120.0);
        const int x = (frame % 240 < 120) ? (480 + frame) : (720 - (frame % 120));
        const int y = 640 - static_cast<int>(wave * 32.0);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 160 - static_cast<int>(wave * 64.0));
        DrawGraph(x, y, nowLoading, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    DrawString(24, notes::kScreenHeight - 28, "Loading reconstructed frontend resources...", GetColor(80, 80, 80));
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
        else if (CheckHitKey(KEY_INPUT_F5) != 0) {
            diagnosticsPage_ = 5;
        }
        else if (CheckHitKey(KEY_INPUT_F6) != 0) {
            diagnosticsPage_ = 6;
            if (resources_ && !stageRuntime_.initialized()) {
                stageRuntime_.initialize(*resources_);
            }
        }
        else if (diagnosticsPage_ == 6 && CheckHitKey(KEY_INPUT_1) != 0) {
            stageRuntime_.setStage(1);
        }
        else if (diagnosticsPage_ == 6 && CheckHitKey(KEY_INPUT_2) != 0) {
            stageRuntime_.setStage(2);
        }
        else if (diagnosticsPage_ == 6 && CheckHitKey(KEY_INPUT_4) != 0) {
            stageRuntime_.setStage(4);
        }

        if (diagnosticsPage_ == 0 && resources_) {
            frontendRuntime_.update(*resources_);
            const auto request = frontendRuntime_.consumeGameplayRequest();
            if (request.requested) {
                StageRuntime::StageRuntimeConfig config;
                config.stage = request.stage;
                config.routeMode = request.routeMode;
                config.playerOption = request.playerOption;
                config.subOption = request.subOption;
                config.loadoutId = request.loadoutId;
                config.optionSlots = request.optionSlots;
                if (!stageRuntime_.initialized()) {
                    stageRuntime_.initialize(*resources_, config);
                }
                else {
                    stageRuntime_.setConfig(config);
                }
                diagnosticsPage_ = 6;
            }
        }
        drawSmokeTestFrame();
        ScreenFlip();
    }
    return 0;
}

void App::drawSmokeTestFrame() {
    ClearDrawScreen();

    if (diagnosticsPage_ == 0 && resources_) {
        frontendRuntime_.draw(*resources_);
        return;
    }

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
    DrawString(24, 48, "F1 title  F2 resources  F3 text CSV  F4 save/config  F5 stage probe  F6 playable stage (1/2/4 slice)  ESC exit", GetColor(255, 255, 255));
    if (diagnosticsPage_ == 6) {
        if (stageRuntime_.initialized()) {
            stageRuntime_.update();
            stageRuntime_.draw();
        }
        else {
            drawStageRuntimeUnavailable();
        }
    }
    else if (diagnosticsPage_ == 1) {
        DrawString(24, 72, "Smoke test: startup/title resource loading only", GetColor(255, 255, 255));
        drawDiagnostics(24, 120);
    }
    else if (diagnosticsPage_ == 2) {
        drawResourceDiagnostics(24, 84);
    }
    else if (diagnosticsPage_ == 3) {
        drawTextDiagnostics(24, 84);
    }
    else if (diagnosticsPage_ == 4) {
        drawSaveDiagnostics(24, 84);
    }
    else {
        drawStageProbe(24, 84);
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

void App::drawStageRuntimeUnavailable() const {
    DrawString(24, 84, "Playable Stage 01 runtime is unavailable", GetColor(255, 96, 96));
    DrawString(24, 112, "Required local resources: Player.png, Enemy_s.png, Bullet.png, StageBack1/2.png", GetColor(255, 255, 255));
    DrawString(24, 140, "Check --asset-root and extracted re/ asset layout, then press F6 again.", GetColor(210, 210, 210));
}

void App::drawStageProbe(int x, int y) const {
    DrawString(x, y, "Stage reconstruction probe (evidence only)", GetColor(255, 240, 128));
    int line = y + 28;

    DrawString(x, line, "Stage resource hints:", GetColor(255, 255, 255));
    line += 20;
    int shown = 0;
    for (const auto& hint : stageResourceHints()) {
        DrawFormatString(x + 20, line, GetColor(210, 210, 210), "S%d %s bg=%s bgm=%s boss=%s",
                         hint.stage, hint.label, hint.backgrounds, hint.stageBgm, hint.bossBgm);
        line += 18;
        if (++shown >= 4) {
            break;
        }
    }

    line += 8;
    DrawString(x, line, "Projectile visual annotations:", GetColor(255, 255, 255));
    line += 20;
    shown = 0;
    for (const auto& annotation : projectileVisualAnnotations()) {
        const auto color = annotation.confidence[0] == 'H' ? GetColor(210, 240, 255) : GetColor(210, 210, 210);
        DrawFormatString(x + 20, line, color, "%s %s %s",
                         annotation.spawnType, annotation.projectilePair, annotation.bulletVisual);
        line += 18;
        DrawFormatString(x + 44, line, GetColor(180, 180, 180), "%.94s", annotation.interpretation);
        line += 18;
        if (++shown >= 4) {
            break;
        }
    }

    line += 8;
    DrawString(x, line, "Demo summaries:", GetColor(255, 255, 255));
    line += 20;
    for (const auto& demo : stageProbe_.demos()) {
        const auto color = demo.loaded ? kWhite : kRed;
        DrawFormatString(x + 20, line, GetColor((color >> 16) & 0xff, (color >> 8) & 0xff, color & 0xff),
                         "%s header=%d inputRecords=%d %s", demo.id.c_str(), demo.headerFieldCount,
                         demo.inputRecordCount, demo.loaded ? "" : demo.error.c_str());
        line += 18;
    }

    line += 8;
    DrawString(x, line, "Replay stage fields:", GetColor(255, 255, 255));
    line += 20;
    shown = 0;
    for (const auto& field : replayStageFieldHints()) {
        DrawFormatString(x + 20, line, GetColor(210, 210, 210), "%s %s - %.62s", field.offset, field.name, field.note);
        line += 18;
        if (++shown >= 3) {
            break;
        }
    }

    line += 8;
    DrawString(x, line, "Entity hypotheses:", GetColor(255, 255, 255));
    line += 20;
    for (const auto& entity : entityModelHypotheses()) {
        DrawFormatString(x + 20, line, GetColor(210, 210, 210), "%s: %.84s", entity.kind, entity.resourceEvidence);
        line += 18;
    }
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
