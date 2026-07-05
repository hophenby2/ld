#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace reconstructed {

enum class ResourceMode {
    ExtractedFiles,
    DxArchive,
};

struct LoadedGraph {
    std::string logicalPath;
    std::string resolvedPath;
    int handle = -1;
};

class ResourceManager {
public:
    ResourceManager(std::filesystem::path assetRoot, ResourceMode mode);
    ~ResourceManager();

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    bool loadStartupResources();
    int loadGraph(const std::string& logicalPath);
    std::vector<int> loadDivGraph(const std::string& logicalPath, int allNum, int xNum, int yNum, int xSize, int ySize);
    int loadSound(const std::string& logicalPath, int bufferNum = 3);
    void releaseAll();

    const std::vector<LoadedGraph>& graphs() const { return graphs_; }
    int graphHandle(const std::string& logicalPath) const;
    std::string resolvePath(const std::string& logicalPath) const;

private:
    std::filesystem::path assetRoot_;
    ResourceMode mode_ = ResourceMode::ExtractedFiles;
    std::vector<LoadedGraph> graphs_;
    std::vector<int> sounds_;
};

} // namespace reconstructed
