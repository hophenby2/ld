#pragma once

#include "resource_tables.h"

#include <filesystem>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace reconstructed {

struct LoadedGraph {
    std::string id;
    std::string logicalPath;
    std::string resolvedPath;
    ResourceSource source = ResourceSource::Startup;
    GraphLoadKind loadKind = GraphLoadKind::Single;
    int handle = -1;
    int handleCount = 0;
    std::vector<int> handles;
};

struct LoadedSound {
    std::string id;
    std::string logicalPath;
    std::string resolvedPath;
    SoundKind kind = SoundKind::Se;
    int handle = -1;
};

struct ResourceLoadSummary {
    int graphAttempts = 0;
    int graphSuccesses = 0;
    int soundAttempts = 0;
    int soundSuccesses = 0;
};

class ResourceManager {
public:
    ResourceManager(std::filesystem::path assetRoot, ResourceMode mode);
    ~ResourceManager();

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    bool loadStartupResources();
    bool loadGraphs(std::span<const GraphResourceSpec> specs);
    bool loadSounds(std::span<const SoundResourceSpec> specs);
    int loadGraph(const std::string& logicalPath);
    std::vector<int> loadDivGraph(const std::string& logicalPath, int allNum, int xNum, int yNum, int xSize, int ySize);
    int loadSound(const std::string& logicalPath, int bufferNum = 3);
    void releaseAll();

    const std::vector<LoadedGraph>& graphs() const { return graphs_; }
    const std::vector<LoadedSound>& sounds() const { return sounds_; }
    const ResourceLoadSummary& summary() const { return summary_; }
    int graphHandle(const std::string& logicalPath) const;
    int graphFrame(std::string_view logicalPath, int frame) const;
    int graphHandleById(std::string_view id) const;
    int graphFrameById(std::string_view id, int frame) const;
    int soundHandle(std::string_view logicalPath) const;
    int soundHandleById(std::string_view id) const;
    std::string resolvePath(const std::string& logicalPath) const;

private:
    std::filesystem::path assetRoot_;
    ResourceMode mode_ = ResourceMode::ExtractedFiles;
    std::vector<LoadedGraph> graphs_;
    std::vector<LoadedSound> sounds_;
    ResourceLoadSummary summary_;
};

} // namespace reconstructed
