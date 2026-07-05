#include "path_utils.h"

#include <Windows.h>

#include <algorithm>

namespace reconstructed {
namespace {

bool looksLikeAssetRoot(const std::filesystem::path& candidate) {
    return std::filesystem::exists(candidate / "re" / "system" / "TitleLogo.png");
}

std::string replaceBackslashes(std::string value) {
    std::replace(value.begin(), value.end(), '\\', '/');
    return value;
}

} // namespace

std::filesystem::path findDefaultAssetRoot() {
    auto current = std::filesystem::current_path();
    for (auto probe = current; !probe.empty(); probe = probe.parent_path()) {
        if (looksLikeAssetRoot(probe)) {
            return probe;
        }
        if (probe == probe.root_path()) {
            break;
        }
    }

    // Common location when running from reverse/reconstructed/project/build/<config>.
    const auto relativeProbe = current / ".." / ".." / ".." / "..";
    if (looksLikeAssetRoot(relativeProbe)) {
        return std::filesystem::weakly_canonical(relativeProbe);
    }

    return current;
}

std::string logicalMediaPathToExtractedPath(const std::filesystem::path& assetRoot, const std::string& logicalPath) {
    std::string normalized = replaceBackslashes(logicalPath);
    constexpr const char* prefix = "media/";
    if (normalized.rfind(prefix, 0) == 0) {
        normalized.replace(0, 6, "re/");
    }
    return pathToDxString(assetRoot / std::filesystem::path(normalized));
}

std::string pathToDxString(const std::filesystem::path& path) {
    const auto wide = path.wstring();
    return wideToUtf8(wide.c_str());
}

std::string wideToUtf8(const wchar_t* value) {
    if (value == nullptr || *value == L'\0') {
        return {};
    }
    const int needed = WideCharToMultiByte(CP_UTF8, 0, value, -1, nullptr, 0, nullptr, nullptr);
    if (needed <= 1) {
        return {};
    }
    std::string result(static_cast<std::size_t>(needed - 1), '\0');
    WideCharToMultiByte(CP_UTF8, 0, value, -1, result.data(), needed, nullptr, nullptr);
    return result;
}

} // namespace reconstructed
