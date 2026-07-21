#pragma once

#include <array>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace reconstructed {

constexpr std::size_t kReplayHeaderSize = 0x0a98;
constexpr std::int32_t kReplayFormatVersion = 200;

struct ReplayInputRecord {
    std::uint32_t frame = 0;
    std::uint16_t inputMask = 0;
};

struct ReplayData {
    std::array<std::uint8_t, kReplayHeaderSize> header{};
    std::vector<ReplayInputRecord> inputRecords;
    bool recordable = false;

    void clear() {
        header.fill(0);
        inputRecords.clear();
        recordable = false;
    }
};

inline std::uint16_t readReplayU16(
    const std::array<std::uint8_t, kReplayHeaderSize>& bytes,
    std::size_t offset) {
    if (offset + sizeof(std::uint16_t) > bytes.size()) {
        return 0;
    }
    return static_cast<std::uint16_t>(bytes[offset]) |
           static_cast<std::uint16_t>(bytes[offset + 1] << 8U);
}

inline std::uint32_t readReplayU32(
    const std::array<std::uint8_t, kReplayHeaderSize>& bytes,
    std::size_t offset) {
    if (offset + sizeof(std::uint32_t) > bytes.size()) {
        return 0;
    }
    return static_cast<std::uint32_t>(bytes[offset]) |
           (static_cast<std::uint32_t>(bytes[offset + 1]) << 8U) |
           (static_cast<std::uint32_t>(bytes[offset + 2]) << 16U) |
           (static_cast<std::uint32_t>(bytes[offset + 3]) << 24U);
}

inline std::int32_t readReplayI32(
    const std::array<std::uint8_t, kReplayHeaderSize>& bytes,
    std::size_t offset) {
    return static_cast<std::int32_t>(readReplayU32(bytes, offset));
}

inline void writeReplayU16(
    std::array<std::uint8_t, kReplayHeaderSize>& bytes,
    std::size_t offset, std::uint16_t value) {
    if (offset + sizeof(value) > bytes.size()) {
        return;
    }
    bytes[offset] = static_cast<std::uint8_t>(value);
    bytes[offset + 1] = static_cast<std::uint8_t>(value >> 8U);
}

inline void writeReplayU32(
    std::array<std::uint8_t, kReplayHeaderSize>& bytes,
    std::size_t offset, std::uint32_t value) {
    if (offset + sizeof(value) > bytes.size()) {
        return;
    }
    bytes[offset] = static_cast<std::uint8_t>(value);
    bytes[offset + 1] = static_cast<std::uint8_t>(value >> 8U);
    bytes[offset + 2] = static_cast<std::uint8_t>(value >> 16U);
    bytes[offset + 3] = static_cast<std::uint8_t>(value >> 24U);
}

inline void writeReplayI32(
    std::array<std::uint8_t, kReplayHeaderSize>& bytes,
    std::size_t offset, std::int32_t value) {
    writeReplayU32(bytes, offset, static_cast<std::uint32_t>(value));
}

inline void writeReplayI64(
    std::array<std::uint8_t, kReplayHeaderSize>& bytes,
    std::size_t offset, std::int64_t value) {
    if (offset + sizeof(value) > bytes.size()) {
        return;
    }
    const auto bits = static_cast<std::uint64_t>(value);
    for (std::size_t index = 0; index < sizeof(bits); ++index) {
        bytes[offset + index] = static_cast<std::uint8_t>(bits >> (index * 8U));
    }
}

inline void writeReplayF32(
    std::array<std::uint8_t, kReplayHeaderSize>& bytes,
    std::size_t offset, float value) {
    writeReplayU32(bytes, offset, std::bit_cast<std::uint32_t>(value));
}

} // namespace reconstructed
