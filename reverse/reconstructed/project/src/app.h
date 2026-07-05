#pragma once

#include "resource_manager.h"

#include <filesystem>
#include <memory>
#include <string>

namespace reconstructed {

struct AppOptions {
    std::filesystem::path assetRoot;
    ResourceMode resourceMode = ResourceMode::ExtractedFiles;
    bool smokeTest = false;
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
    void drawDiagnostics(int x, int y) const;

    AppOptions options_;
    std::unique_ptr<ResourceManager> resources_;
    bool dxInitialized_ = false;
    bool fontsLoaded_ = false;
};

} // namespace reconstructed
