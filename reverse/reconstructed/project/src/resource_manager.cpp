#include "resource_manager.h"

#include "path_utils.h"

#include <DxLib.h>

#include <algorithm>
#include <string_view>
#include <utility>
#include <vector>

namespace reconstructed {
namespace {

int countValidHandles(const std::vector<int>& handles) {
    return static_cast<int>(std::count_if(handles.begin(), handles.end(), [](int value) { return value != -1; }));
}

int firstValidHandle(const std::vector<int>& handles) {
    const auto it = std::find_if(handles.begin(), handles.end(), [](int value) { return value != -1; });
    return it == handles.end() ? -1 : *it;
}

} // namespace

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
        std::vector<int> handles;
        int handleCount = 0;
        const auto resolved = resolvePath(spec.logicalPath);

        if (spec.loadKind == GraphLoadKind::Div) {
            if (spec.allNum > 0 && spec.xNum > 0 && spec.yNum > 0 &&
                spec.xSize > 0 && spec.ySize > 0) {
                handles.assign(static_cast<std::size_t>(spec.allNum), -1);
                if (LoadDivGraph(resolved.c_str(), spec.allNum, spec.xNum, spec.yNum,
                                 spec.xSize, spec.ySize, handles.data()) != -1) {
                    handle = firstValidHandle(handles);
                    handleCount = countValidHandles(handles);
                }
            }
        }
        else {
            handle = LoadGraph(resolved.c_str());
            if (handle != -1) {
                handles.push_back(handle);
            }
            handleCount = handle == -1 ? 0 : 1;
        }

        if (handle != -1) {
            ++summary_.graphSuccesses;
        }
        else {
            ok = false;
        }
        graphs_.push_back({spec.id, spec.logicalPath, resolved, spec.source, spec.loadKind, handle, handleCount, std::move(handles)});
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
    std::vector<int> handles;
    if (handle != -1) {
        handles.push_back(handle);
    }
    graphs_.push_back({logicalPath, logicalPath, resolved, ResourceSource::Startup, GraphLoadKind::Single, handle, handle == -1 ? 0 : 1, std::move(handles)});
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
    const int handleCount = countValidHandles(handles);
    graphs_.push_back({logicalPath, logicalPath, resolved, ResourceSource::Primary, GraphLoadKind::Div,
                       firstValidHandle(handles), handleCount, handles});
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
    std::vector<int> deletedGraphs;
    for (const auto& graph : graphs_) {
        for (const int handle : graph.handles) {
            if (handle != -1 && std::find(deletedGraphs.begin(), deletedGraphs.end(), handle) == deletedGraphs.end()) {
                DeleteGraph(handle);
                deletedGraphs.push_back(handle);
            }
        }
        if (graph.handles.empty() && graph.handle != -1 &&
            std::find(deletedGraphs.begin(), deletedGraphs.end(), graph.handle) == deletedGraphs.end()) {
            DeleteGraph(graph.handle);
            deletedGraphs.push_back(graph.handle);
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
    return graphFrame(logicalPath, 0);
}

int ResourceManager::graphFrame(std::string_view logicalPath, int frame) const {
    const auto it = std::find_if(graphs_.begin(), graphs_.end(), [&](const LoadedGraph& graph) {
        return graph.logicalPath == logicalPath;
    });
    if (it == graphs_.end()) {
        return -1;
    }
    if (frame >= 0 && frame < static_cast<int>(it->handles.size())) {
        return it->handles[static_cast<std::size_t>(frame)];
    }
    return frame == 0 ? it->handle : -1;
}

int ResourceManager::graphHandleById(std::string_view id) const {
    return graphFrameById(id, 0);
}

int ResourceManager::graphFrameById(std::string_view id, int frame) const {
    const auto it = std::find_if(graphs_.begin(), graphs_.end(), [&](const LoadedGraph& graph) {
        return graph.id == id;
    });
    if (it == graphs_.end()) {
        return -1;
    }
    if (frame >= 0 && frame < static_cast<int>(it->handles.size())) {
        return it->handles[static_cast<std::size_t>(frame)];
    }
    return frame == 0 ? it->handle : -1;
}

int ResourceManager::soundHandle(std::string_view logicalPath) const {
    const auto it = std::find_if(sounds_.begin(), sounds_.end(), [&](const LoadedSound& sound) {
        return sound.logicalPath == logicalPath;
    });
    return it == sounds_.end() ? -1 : it->handle;
}

int ResourceManager::soundHandleById(std::string_view id) const {
    const auto it = std::find_if(sounds_.begin(), sounds_.end(), [&](const LoadedSound& sound) {
        return sound.id == id;
    });
    return it == sounds_.end() ? -1 : it->handle;
}

std::string ResourceManager::resolvePath(const std::string& logicalPath) const {
    if (mode_ == ResourceMode::DxArchive) {
        return logicalPath;
    }
    return logicalMediaPathToExtractedPath(assetRoot_, logicalPath);
}

} // namespace reconstructed
