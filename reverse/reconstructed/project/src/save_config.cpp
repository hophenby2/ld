#include "save_config.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <fstream>
#include <utility>

namespace reconstructed {
namespace {

void writeI32(std::vector<std::uint8_t>& bytes, std::size_t offset, std::int32_t value) {
    if (offset + sizeof(value) <= bytes.size()) {
        std::memcpy(bytes.data() + offset, &value, sizeof(value));
    }
}

std::int32_t readI32(const std::vector<std::uint8_t>& bytes, std::size_t offset) {
    std::int32_t value = 0;
    if (offset + sizeof(value) <= bytes.size()) {
        std::memcpy(&value, bytes.data() + offset, sizeof(value));
    }
    return value;
}

std::vector<std::uint8_t> originalSaveDefaults() {
    std::vector<std::uint8_t> bytes(SaveConfigState::kSaveDatSize, 0);

    // FUN_1400d0aa0 initializes this complete 0x2730-byte block before the
    // executable creates a missing save file.
    writeI32(bytes, 0x0000, 200);
    writeI32(bytes, 0x0048, 1);
    writeI32(bytes, 0x004c, 11);
    writeI32(bytes, 0x0058, 1);
    writeI32(bytes, 0x005c, 11);

    for (int character = 0; character < 3; ++character) {
        for (int stage = 0; stage < 15; ++stage) {
            const std::size_t record = 0x00c8 + static_cast<std::size_t>(character) * 0x00c8 +
                                       static_cast<std::size_t>(stage) * 0x0258;
            for (int slot = 0; slot < 5; ++slot) {
                const std::size_t timer = record + 0x0048 + static_cast<std::size_t>(slot) * 8;
                writeI32(bytes, timer, 0x57030);
                writeI32(bytes, timer + 4, 0x57030);
            }
        }
    }

    for (int stage = 0; stage < 15; ++stage) {
        writeI32(bytes, 0x2398 + static_cast<std::size_t>(stage) * 4, 2);
    }
    writeI32(bytes, 0x23e8, 1);

    // Scalar menu defaults copied by FUN_1400d0aa0 from the original .rdata.
    writeI32(bytes, 0x267c, 10);
    writeI32(bytes, 0x2680, 10);
    writeI32(bytes, 0x2684, 1);
    writeI32(bytes, 0x2688, 6);
    writeI32(bytes, 0x2694, 1);
    writeI32(bytes, 0x269c, 1);
    writeI32(bytes, 0x26a4, 1);
    writeI32(bytes, 0x26bc, 5);

    constexpr std::array<std::int32_t, 11> keyboard{{
        0xc8, 0xd0, 0xcd, 0xcb, 0x2c, 0x2d, 0x2c, 0x2d, 0x2e, 0x2a, 0x01,
    }};
    constexpr std::array<std::int32_t, 11> controller{{
        0x08, 0x01, 0x04, 0x02, 0x10, 0x20, 0x10, 0x40, 0x20, 0x200, 0x800,
    }};
    for (std::size_t index = 0; index < keyboard.size(); ++index) {
        writeI32(bytes, 0x26c0 + index * 4, keyboard[index]);
        writeI32(bytes, 0x26f0 + index * 4, controller[index]);
    }

    return bytes;
}

std::vector<std::uint8_t> originalConfigDefaults() {
    // game_startup_init_candidate copies the first four values from
    // 0x14053b4e0, then sets entry 4 to one and entries 5..6 to zero.
    constexpr std::array<std::int32_t, 7> values{{0, 0, 1, 0, 1, 0, 0}};
    std::vector<std::uint8_t> bytes(SaveConfigState::kConfigDatSize, 0);
    for (std::size_t index = 0; index < values.size(); ++index) {
        writeI32(bytes, index * 4, values[index]);
    }
    return bytes;
}

void migrateSaveToVersion200(std::vector<std::uint8_t>& bytes) {
    writeI32(bytes, 0x2448, readI32(bytes, 0x2464));
    writeI32(bytes, 0x244c, readI32(bytes, 0x2468));
    writeI32(bytes, 0x2458, readI32(bytes, 0x246c));
    writeI32(bytes, 0x2444, 0);
    writeI32(bytes, 0x2450, 0);
    writeI32(bytes, 0x2454, 0);
    std::fill(bytes.begin() + 0x24a8, bytes.begin() + 0x24c0, 0);
    writeI32(bytes, 0, 200);
}

} // namespace

SaveConfigStore::SaveConfigStore(std::filesystem::path assetRoot) : assetRoot_(std::move(assetRoot)) {}

bool SaveConfigStore::loadOrCreate() {
    const auto saveDir = assetRoot_ / "save";
    std::error_code ec;
    std::filesystem::create_directories(saveDir, ec);
    if (ec) {
        return false;
    }

    const auto saveDefaults = originalSaveDefaults();
    const auto configDefaults = originalConfigDefaults();
    const bool saveOk = loadOrCreateFile(saveDir / "save.dat", state_.saveDat, saveDefaults, true,
                                         state_.saveExisted, state_.diagnostics.saveCreated,
                                         state_.diagnostics.saveActualSize);
    const bool configOk = loadOrCreateFile(saveDir / "config.dat", state_.configDat, configDefaults, false,
                                           state_.configExisted, state_.diagnostics.configCreated,
                                           state_.diagnostics.configActualSize);
    state_.diagnostics.saveExisted = state_.saveExisted;
    state_.diagnostics.configExisted = state_.configExisted;
    return saveOk && configOk;
}

bool SaveConfigStore::loadOrCreateFile(const std::filesystem::path& path,
                                       std::vector<std::uint8_t>& bytes,
                                       const std::vector<std::uint8_t>& defaults,
                                       bool requireSaveVersion,
                                       bool& existed,
                                       bool& created,
                                       std::uintmax_t& actualSize) {
    std::error_code ec;
    existed = std::filesystem::exists(path, ec);
    if (ec) {
        return false;
    }
    created = !existed;
    actualSize = existed ? std::filesystem::file_size(path, ec) : defaults.size();
    if (ec) {
        return false;
    }

    if (existed) {
        bytes.assign(defaults.size(), 0);
        std::ifstream in(path, std::ios::binary);
        if (!in) {
            return false;
        }
        in.read(reinterpret_cast<char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
        if (!requireSaveVersion) {
            return true;
        }
        const std::int32_t version = readI32(bytes, 0);
        if (version >= 100 && version < 200) {
            migrateSaveToVersion200(bytes);
        }
        else if (version != 200) {
            bytes = defaults;
        }
        return true;
    }

    bytes = defaults;
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) {
        return false;
    }
    out.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
    return static_cast<bool>(out);
}

} // namespace reconstructed
