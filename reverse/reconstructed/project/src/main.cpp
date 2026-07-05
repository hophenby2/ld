#include "app.h"
#include "path_utils.h"

#include <Windows.h>
#include <shellapi.h>

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace {

std::vector<std::string> commandLineArgs() {
    int argc = 0;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    std::vector<std::string> args;
    if (argv != nullptr) {
        args.reserve(static_cast<std::size_t>(argc));
        for (int i = 0; i < argc; ++i) {
            args.push_back(reconstructed::wideToUtf8(argv[i]));
        }
        LocalFree(argv);
    }
    return args;
}

reconstructed::AppOptions parseOptions(const std::vector<std::string>& args) {
    reconstructed::AppOptions options;
    options.assetRoot = reconstructed::findDefaultAssetRoot();

    for (std::size_t i = 1; i < args.size(); ++i) {
        if (args[i] == "--asset-root" && i + 1 < args.size()) {
            options.assetRoot = args[++i];
        }
        else if (args[i] == "--use-dxa") {
            options.resourceMode = reconstructed::ResourceMode::DxArchive;
        }
        else if (args[i] == "--smoke-test") {
            options.smokeTest = true;
        }
        else if (args[i] == "--load-all-graphics") {
            options.loadAllGraphics = true;
        }
        else if (args[i] == "--load-audio") {
            options.loadAudio = true;
        }
    }

    return options;
}

} // namespace

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    const auto args = commandLineArgs();
    auto options = parseOptions(args);
    reconstructed::App app(std::move(options));
    return app.run();
}
