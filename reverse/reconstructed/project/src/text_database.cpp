#include "text_database.h"

#include "path_utils.h"

#include <Windows.h>

#include <fstream>
#include <sstream>

namespace reconstructed {
namespace {

std::string readBinaryFile(const std::filesystem::path& path, std::string& error) {
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        error = "open failed";
        return {};
    }
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

std::string convertToUtf8(const std::string& bytes, unsigned int codePage, bool stripBom, std::string& error) {
    std::string input = bytes;
    if (stripBom && input.size() >= 3 &&
        static_cast<unsigned char>(input[0]) == 0xef &&
        static_cast<unsigned char>(input[1]) == 0xbb &&
        static_cast<unsigned char>(input[2]) == 0xbf) {
        input.erase(0, 3);
    }

    if (codePage == CP_UTF8) {
        return input;
    }

    const int wideCount = MultiByteToWideChar(codePage, 0, input.data(), static_cast<int>(input.size()), nullptr, 0);
    if (wideCount <= 0) {
        error = "MultiByteToWideChar failed";
        return {};
    }

    std::wstring wide(static_cast<std::size_t>(wideCount), L'\0');
    MultiByteToWideChar(codePage, 0, input.data(), static_cast<int>(input.size()), wide.data(), wideCount);

    const int utf8Count = WideCharToMultiByte(CP_UTF8, 0, wide.data(), wideCount, nullptr, 0, nullptr, nullptr);
    if (utf8Count <= 0) {
        error = "WideCharToMultiByte failed";
        return {};
    }

    std::string result(static_cast<std::size_t>(utf8Count), '\0');
    WideCharToMultiByte(CP_UTF8, 0, wide.data(), wideCount, result.data(), utf8Count, nullptr, nullptr);
    return result;
}

std::vector<std::string> splitCsvSimple(const std::string& line) {
    std::vector<std::string> fields;
    std::string current;
    bool quoted = false;
    for (char ch : line) {
        if (ch == '"') {
            quoted = !quoted;
        }
        else if (ch == ',' && !quoted) {
            fields.push_back(current);
            current.clear();
        }
        else if (ch != '\r') {
            current.push_back(ch);
        }
    }
    fields.push_back(current);
    return fields;
}

int toInt(const std::string& value) {
    try {
        return std::stoi(value);
    }
    catch (...) {
        return 0;
    }
}

} // namespace

bool TextDatabase::load(std::span<const TextResourceSpec> specs, const std::filesystem::path& assetRoot, ResourceMode mode) {
    files_.clear();
    attempted_ = 0;
    succeeded_ = 0;

    for (const auto& spec : specs) {
        ++attempted_;
        auto loaded = loadOne(spec, assetRoot, mode);
        if (loaded.loaded) {
            ++succeeded_;
        }
        files_.push_back(std::move(loaded));
    }

    return failed() == 0;
}

const TextRecord* TextDatabase::find(int language, int id) const {
    if (language < 0 || language > 3 ||
        static_cast<std::size_t>(language) >= files_.size()) {
        return nullptr;
    }

    const auto& records = files_[static_cast<std::size_t>(language)].records;
    for (const auto& record : records) {
        if (record.id == id) {
            return &record;
        }
    }
    return nullptr;
}

LoadedTextFile TextDatabase::loadOne(const TextResourceSpec& spec, const std::filesystem::path& assetRoot, ResourceMode mode) const {
    LoadedTextFile result;
    result.id = spec.id;
    result.logicalPath = spec.logicalPath;
    result.codePage = spec.codePage;
    result.resolvedPath = mode == ResourceMode::DxArchive ? spec.logicalPath : logicalMediaPathToExtractedPath(assetRoot, spec.logicalPath);

    if (mode == ResourceMode::DxArchive) {
        result.error = "text diagnostics currently require extracted files";
        return result;
    }

    std::string error;
    const auto bytes = readBinaryFile(std::filesystem::path(result.resolvedPath), error);
    if (!error.empty()) {
        result.error = error;
        return result;
    }

    const auto utf8 = convertToUtf8(bytes, spec.codePage, spec.utf8Bom, error);
    if (!error.empty()) {
        result.error = error;
        return result;
    }

    std::istringstream input(utf8);
    std::string line;
    while (std::getline(input, line)) {
        if (line.empty()) {
            continue;
        }
        const auto fields = splitCsvSimple(line);
        if (fields.size() != 4) {
            continue;
        }
        TextRecord record{toInt(fields[0]), fields[1], fields[2], toInt(fields[3])};
        ++result.rowCount;
        if (result.sampleRecords.size() < 4) {
            result.sampleRecords.push_back(record);
        }
        result.records.push_back(std::move(record));
    }

    result.loaded = result.rowCount > 0;
    if (!result.loaded) {
        result.error = "no parseable rows";
    }
    return result;
}

} // namespace reconstructed
