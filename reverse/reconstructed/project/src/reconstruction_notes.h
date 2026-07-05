#pragma once

namespace reconstructed::notes {

inline constexpr const char* kDxArchiveKey = "VanillaFever11";
inline constexpr int kScreenWidth = 0x500;   // 1280, from startup decompile SetGraphMode path.
inline constexpr int kScreenHeight = 0x2d0;  // 720.

// Primary evidence files:
// - reverse/README.md: DxLib + DXArchive, extracted assets, DXA key.
// - reverse/ghidra-or-ida/exports/renamed-decompiled/1400f4f70_game_startup_init_candidate.c
// - reverse/ghidra-or-ida/exports/renamed-decompiled/1400ced90_load_primary_resources_candidate.c
// - reverse/reconstructed/data-structures/resource-handle-map.md

} // namespace reconstructed::notes
