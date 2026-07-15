#pragma once

#include "frontend_runtime.h"
#include "resource_manager.h"
#include "save_config.h"
#include "stage_probe.h"
#include "stage_runtime.h"
#include "text_database.h"

#include <cstdint>
#include <filesystem>
#include <memory>
#include <string>

namespace reconstructed {

struct AppOptions {
    std::filesystem::path assetRoot;
    ResourceMode resourceMode = ResourceMode::ExtractedFiles;
    bool smokeTest = false;
    bool loadAllGraphics = false;
    bool loadAudio = false;
};

class App {
public:
    explicit App(AppOptions options);
    ~App();

    int run();

private:
    bool initialize();
    void shutdown();
    void loadFonts();
    int runSmokeTestLoop();
    void drawLoadingFrame(int frame) const;
    void drawSmokeTestFrame();
    void drawResourceDiagnostics(int x, int y) const;
    void drawTextDiagnostics(int x, int y) const;
    void drawSaveDiagnostics(int x, int y) const;
    void drawStageProbe(int x, int y) const;
    void drawStageRuntimeUnavailable() const;
    void drawDiagnostics(int x, int y) const;

    AppOptions options_;
    std::unique_ptr<ResourceManager> resources_;
    SaveConfigState saveConfigState_;
    TextDatabase textDatabase_;
    StageProbe stageProbe_;
    StageRuntime stageRuntime_;
    FrontendRuntime frontendRuntime_;
    int diagnosticsPage_ = 0;
    int presentationScreen_ = -1;
    std::uint64_t displayFrame_ = 0;
    bool dxInitialized_ = false;
    bool fontsLoaded_ = false;
};

} // namespace reconstructed
