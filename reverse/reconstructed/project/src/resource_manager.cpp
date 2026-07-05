#include "resource_manager.h"

#include "path_utils.h"

#include <DxLib.h>

#include <algorithm>
#include <utility>

namespace reconstructed {

ResourceManager::ResourceManager(std::filesystem::path assetRoot, ResourceMode mode)
    : assetRoot_(std::move(assetRoot)), mode_(mode) {}

ResourceManager::~ResourceManager() {
    releaseAll();
}

bool ResourceManager::loadStartupResources() {
    return loadGraphs(startupGraphResources());
}

bool ResourceManager::loadGraphs(std::span<const GraphResourceSpec> specs) {
    bool ok = true;
    for (const auto& spec : specs) {
        ++summary_.graphAttempts;
        int handle = -1;
        int handleCount = 0;
        const auto resolved = resolvePath(spec.logicalPath);

        if (spec.loadKind == GraphLoadKind::Div) {
            const int xSize = spec.xSize == 0 ? 1 : spec.xSize;
            const int ySize = spec.ySize == 0 ? 1 : spec.ySize;
            std::vector<int> handles(static_cast<std::size_t>(spec.allNum), -1);
            if (LoadDivGraph(resolved.c_str(), spec.allNum, spec.xNum, spec.yNum, xSize, ySize, handles.data()) != -1) {
                handle = handles.empty() ? -1 : handles.front();
                handleCount = static_cast<int>(std::count_if(handles.begin(), handles.end(), [](int value) { return value != -1; }));
            }
        }
        else {
            handle = LoadGraph(resolved.c_str());
            handleCount = handle == -1 ? 0 : 1;
        }

        if (handle != -1) {
            ++summary_.graphSuccesses;
        }
        else {
            ok = false;
        }
        graphs_.push_back({spec.id, spec.logicalPath, resolved, spec.source, spec.loadKind, handle, handleCount});
    }
    return ok;
}

bool ResourceManager::loadSounds(std::span<const SoundResourceSpec> specs) {
    bool ok = true;
    for (const auto& spec : specs) {
        ++summary_.soundAttempts;
        const auto resolved = resolvePath(spec.logicalPath);
        const int handle = LoadSoundMem(resolved.c_str(), spec.bufferNum);
        if (handle != -1) {
            ++summary_.soundSuccesses;
        }
        else {
            ok = false;
        }
        sounds_.push_back({spec.id, spec.logicalPath, resolved, spec.kind, handle});
    }
    return ok;
}

int ResourceManager::loadGraph(const std::string& logicalPath) {
    const auto resolved = resolvePath(logicalPath);
    const int handle = LoadGraph(resolved.c_str());
    graphs_.push_back({logicalPath, logicalPath, resolved, ResourceSource::Startup, GraphLoadKind::Single, handle, handle == -1 ? 0 : 1});
    ++summary_.graphAttempts;
    if (handle != -1) {
        ++summary_.graphSuccesses;
    }
    return handle;
}

std::vector<int> ResourceManager::loadDivGraph(const std::string& logicalPath, int allNum, int xNum, int yNum, int xSize, int ySize) {
    std::vector<int> handles(static_cast<std::size_t>(allNum), -1);
    const auto resolved = resolvePath(logicalPath);
    if (LoadDivGraph(resolved.c_str(), allNum, xNum, yNum, xSize, ySize, handles.data()) == -1) {
        std::fill(handles.begin(), handles.end(), -1);
    }
    const int handleCount = static_cast<int>(std::count_if(handles.begin(), handles.end(), [](int value) { return value != -1; }));
    graphs_.push_back({logicalPath, logicalPath, resolved, ResourceSource::Primary, GraphLoadKind::Div,
                       handles.empty() ? -1 : handles.front(), handleCount});
    ++summary_.graphAttempts;
    if (handleCount > 0) {
        ++summary_.graphSuccesses;
    }
    return handles;
}

int ResourceManager::loadSound(const std::string& logicalPath, int bufferNum) {
    const auto resolved = resolvePath(logicalPath);
    const int handle = LoadSoundMem(resolved.c_str(), bufferNum);
    sounds_.push_back({logicalPath, logicalPath, resolved, SoundKind::Se, handle});
    ++summary_.soundAttempts;
    if (handle != -1) {
        ++summary_.soundSuccesses;
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

    for (const auto& sound : sounds_) {
        if (sound.handle != -1) {
            DeleteSoundMem(sound.handle);
        }
    }
    sounds_.clear();
    summary_ = {};
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
