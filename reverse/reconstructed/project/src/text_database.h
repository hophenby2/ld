#pragma once

#include "resource_tables.h"

#include <filesystem>
#include <span>
#include <string>
#include <vector>

namespace reconstructed {

struct TextRecord {
    int id = 0;
    std::string line1;
    std::string line2;
    int flag = 0;
};

struct LoadedTextFile {
    std::string id;
    std::string logicalPath;
    std::string resolvedPath;
    unsigned int codePage = 0;
    bool loaded = false;
    std::size_t rowCount = 0;
    std::string error;
    std::vector<TextRecord> records;
    std::vector<TextRecord> sampleRecords;
};

class TextDatabase {
public:
    bool load(std::span<const TextResourceSpec> specs, const std::filesystem::path& assetRoot, ResourceMode mode);

    const std::vector<LoadedTextFile>& files() const { return files_; }
    const TextRecord* find(int language, int id) const;
    int attempted() const { return attempted_; }
    int succeeded() const { return succeeded_; }
    int failed() const { return attempted_ - succeeded_; }

private:
    LoadedTextFile loadOne(const TextResourceSpec& spec, const std::filesystem::path& assetRoot, ResourceMode mode) const;

    std::vector<LoadedTextFile> files_;
    int attempted_ = 0;
    int succeeded_ = 0;
};

} // namespace reconstructed
