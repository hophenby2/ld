#pragma once

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <vector>

namespace reconstructed {

struct SaveConfigState {
    static constexpr std::size_t kSaveDatSize = 0x2730;
    static constexpr std::size_t kConfigDatSize = 0x1c;

    std::vector<std::uint8_t> saveDat;
    std::vector<std::uint8_t> configDat;
    bool saveExisted = false;
    bool configExisted = false;
};

class SaveConfigStore {
public:
    explicit SaveConfigStore(std::filesystem::path assetRoot);

    bool loadOrCreate();
    const SaveConfigState& state() const { return state_; }

private:
    bool loadOrCreateFile(const std::filesystem::path& path, std::vector<std::uint8_t>& bytes, std::size_t size, bool& existed);

    std::filesystem::path assetRoot_;
    SaveConfigState state_;
};

} // namespace reconstructed
