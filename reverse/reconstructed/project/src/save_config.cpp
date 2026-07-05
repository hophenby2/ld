#include "save_config.h"

#include <fstream>
#include <utility>

namespace reconstructed {

SaveConfigStore::SaveConfigStore(std::filesystem::path assetRoot) : assetRoot_(std::move(assetRoot)) {}

bool SaveConfigStore::loadOrCreate() {
    const auto saveDir = assetRoot_ / "save";
    std::error_code ec;
    std::filesystem::create_directories(saveDir, ec);
    if (ec) {
        return false;
    }

    return loadOrCreateFile(saveDir / "save.dat", state_.saveDat, SaveConfigState::kSaveDatSize, state_.saveExisted) &&
           loadOrCreateFile(saveDir / "config.dat", state_.configDat, SaveConfigState::kConfigDatSize, state_.configExisted);
}

bool SaveConfigStore::loadOrCreateFile(const std::filesystem::path& path, std::vector<std::uint8_t>& bytes, std::size_t size, bool& existed) {
    bytes.assign(size, 0);
    existed = std::filesystem::exists(path);

    if (existed) {
        std::ifstream in(path, std::ios::binary);
        if (!in) {
            return false;
        }
        in.read(reinterpret_cast<char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
        return true;
    }

    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) {
        return false;
    }
    out.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
    return static_cast<bool>(out);
}

} // namespace reconstructed
