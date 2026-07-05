#pragma once

#include "resource_manager.h"
#include "save_config.h"
#include "text_database.h"

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
    void drawSmokeTestFrame() const;
    void drawResourceDiagnostics(int x, int y) const;
    void drawTextDiagnostics(int x, int y) const;
    void drawSaveDiagnostics(int x, int y) const;
    void drawDiagnostics(int x, int y) const;

    AppOptions options_;
    std::unique_ptr<ResourceManager> resources_;
    SaveConfigState saveConfigState_;
    TextDatabase textDatabase_;
    int diagnosticsPage_ = 1;
    bool dxInitialized_ = false;
    bool fontsLoaded_ = false;
};

} // namespace reconstructed
