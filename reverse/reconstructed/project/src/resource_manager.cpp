#include "resource_manager.h"

#include "path_utils.h"

#include <DxLib.h>

#include <algorithm>
#include <utility>

namespace reconstructed {
namespace {

constexpr const char* kSmokeTestGraphs[] = {
    "media\\system\\WhiteBack.png",
    "media\\system\\starting.png",
    "media\\system\\NowLoading.png",
    "media\\system\\TitleBack.png",
    "media\\system\\TitleLogo.png",
};

} // namespace

ResourceManager::ResourceManager(std::filesystem::path assetRoot, ResourceMode mode)
    : assetRoot_(std::move(assetRoot)), mode_(mode) {}

ResourceManager::~ResourceManager() {
    releaseAll();
}

bool ResourceManager::loadStartupResources() {
    bool ok = true;
    for (const auto* logicalPath : kSmokeTestGraphs) {
        ok = loadGraph(logicalPath) != -1 && ok;
    }
    return ok;
}

int ResourceManager::loadGraph(const std::string& logicalPath) {
    const auto resolved = resolvePath(logicalPath);
    const int handle = LoadGraph(resolved.c_str());
    graphs_.push_back({logicalPath, resolved, handle});
    return handle;
}

std::vector<int> ResourceManager::loadDivGraph(const std::string& logicalPath, int allNum, int xNum, int yNum, int xSize, int ySize) {
    std::vector<int> handles(static_cast<std::size_t>(allNum), -1);
    const auto resolved = resolvePath(logicalPath);
    if (LoadDivGraph(resolved.c_str(), allNum, xNum, yNum, xSize, ySize, handles.data()) == -1) {
        std::fill(handles.begin(), handles.end(), -1);
    }
    for (int handle : handles) {
        graphs_.push_back({logicalPath, resolved, handle});
    }
    return handles;
}

int ResourceManager::loadSound(const std::string& logicalPath, int bufferNum) {
    const auto resolved = resolvePath(logicalPath);
    const int handle = LoadSoundMem(resolved.c_str(), bufferNum);
    if (handle != -1) {
        sounds_.push_back(handle);
    }
    return handle;
}

void ResourceManager::releaseAll() {
    for (const auto& graph : graphs_) {
        if (graph.handle != -1) {
            DeleteGraph(graph.handle);
        }
    }
    graphs_.clear();

    for (int sound : sounds_) {
        if (sound != -1) {
            DeleteSoundMem(sound);
        }
    }
    sounds_.clear();
}

int ResourceManager::graphHandle(const std::string& logicalPath) const {
    const auto it = std::find_if(graphs_.begin(), graphs_.end(), [&](const LoadedGraph& graph) {
        return graph.logicalPath == logicalPath;
    });
    return it == graphs_.end() ? -1 : it->handle;
}

std::string ResourceManager::resolvePath(const std::string& logicalPath) const {
    if (mode_ == ResourceMode::DxArchive) {
        return logicalPath;
    }
    return logicalMediaPathToExtractedPath(assetRoot_, logicalPath);
}

} // namespace reconstructed
