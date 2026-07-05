#pragma once

#include <filesystem>
#include <string>

namespace reconstructed {

std::filesystem::path findDefaultAssetRoot();
std::string logicalMediaPathToExtractedPath(const std::filesystem::path& assetRoot, const std::string& logicalPath);
std::string pathToDxString(const std::filesystem::path& path);
std::string wideToUtf8(const wchar_t* value);

} // namespace reconstructed
